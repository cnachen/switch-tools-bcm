/*****************************************************************************
 Copyright 2022-2023 Broadcom Limited.  All rights reserved.

 This program is the proprietary software of Broadcom Limited and/or its
 licensors, and may only be used, duplicated, modified or distributed pursuant
 to the terms and conditions of a separate, written license agreement executed
 between you and Broadcom (an "Authorized License").

 Except as set forth in an Authorized License, Broadcom grants no license
 (express or implied), right to use, or waiver of any kind with respect to the
 Software, and Broadcom expressly reserves all rights in and to the Software
 and all intellectual property rights therein.  IF YOU HAVE NO AUTHORIZED
 LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD
 IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.

  Except as expressly set forth in the Authorized License,
 1. This program, including its structure, sequence and organization,
    constitutes the valuable trade secrets of Broadcom, and you shall use all
    reasonable efforts to protect the confidentiality thereof, and to use this
    information only in connection with your use of Broadcom integrated
    circuit products.

 2. TO THE COMP_MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
    AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
    WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
    TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND ALL IMPLIED
    WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A
    PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS,
    QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION.
    YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR PERFORMANCE OF THE
    SOFTWARE.

 3. TO THE COMP_MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR ITS
    LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL, INDIRECT,
    OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY WAY RELATING TO
    YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS
    OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR U.S. $1, WHICHEVER
    IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING ANY FAILURE OF
    ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
******************************************************************************/

/**
    @defgroup grp_crypto_secy_ifc SecY Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_secy_ifc
    @{
     @section sec_secy_overview Overview
     From interface perspective, SecY operations can be clubbed into these groups:
         -# Initialization of the SecY driver and hardware (#SECY_Init).
         -# SecY Management:
             -# Creating a SecY entity(#SECY_CreateSecy).
             -# Creating a rule on the hardware to map specific traffic to specific
                SecY entity (#SECY_AddSecYLookupRule).
             -# Getting the underlying supported cipher suites and its capabilities and choosing
                 one of the them to use it for the given SecY.
             -# Creating transmit/receive secure channel for a SecY (#SECY_CreateTxSC,
                #SECY_CreateRxSC)
             -# Creating transmit/receive secure associations (#SECY_CreateTxSA,
                 #SECY_CreateRxSA).
             -# Enabling of the Transmit and receive SAs (#SECY_EnableSA).
             -# Disabling the transmit and receive SAs (#SECY_DisableSA).
             -# Get next packet number information for transmit and receive SA
                 (#SECY_GetSANextPN).
             -# Set nextPN value for the receive SA (#SECY_SetSANextPN).
             -# Get transmit and receive secure channel and secure associations statistics.
             -# Get SecY statistics counters.
             -# Delete SAs (#SECY_DeleteSA).
             -# Delete Secure channels (#SECY_DeleteTxSC, #SECY_DeleteRxSC).
             -# Delete SecY Lookup rule (#SECY_RemoveSecYLookupRule).
             -# Delete SecY entity(#SECY_DeleteSecY).
         -# APIs to add rules for the packets which need to bypass the encryption/decryption.
            These packets are classified as control packet in the driver
            (refer #SECY_AddCPRuleOpt0, #SECY_AddCPRuleOpt1).
         -# De-Initialization of the SecY driver and hardware (#SECY_Deinit)

     @section sec_secy_init SECY initialization
     Each hardware port has a SecY mode which is initialized by calling #SECY_Init API.
     After the successful initialization of the SecY, all the frames, except KaY tagged frame
     (frame with E-bit set to 1 and C-bit set to 0 and #SECY_HwCfgType.checkKaY set to TRUE) are
     dropped until:
         -# A secure association is established (Creation of SecY, followed by creation of transmit
            and receive channel and then creation of secure association).
         -# A control packet rule is added by calling #SECY_AddCPRuleOpt0 or #SECY_AddCPRuleOpt1.

     <b>Non-Matched packet flow configuration(Packets for which no SA is found or SA is disabled):</b><br>
     Table below shows the configuration of non-matching flow after the initialization of the SecY
     driver.

     The nonmatching flows are subdivided into eight frame type categories, split by whether or not
     the frame was classified as a control frame and the output of a separate SecY tag
     classification function (which outputs if frame is Sectagged or not or having bad tag).

     In the table below:<BR>
     Untagged means packets with no SecTAG.<BR>
     Tagged means packet with valid SecTAG.<BR>
     Bad Tag means packet having correct SecTAG ethType but some of the SecTAG field are not valid.<BR>
     KaY Tag means packet having valid SecTAG with E-bit set to 0 and C-bit set to 1.<BR>
     control means packets which are classified as control packet.<BR>
     Non-control means packets which are not classified as control packet.<BR>
      <table>
         <caption id=flow_config>Flow Configuration</caption>
         <tr><th>Non-matching Flow type        <th>Setting
         <tr><td>Untagged non-control        <td>Drop
         <tr><td>Tagged non-control            <td>Drop
         <tr><td>Bad tag non-control        <td>Drop
         <tr><td>KaY tag, non-control        <td>Pass (if enabled in the driver)
         <tr><td>Untagged control            <td>Pass
         <tr><td>Tagged control                <td>Drop
         <tr><td>Bad tag control            <td>Drop
         <tr><td>KaY tag control            <td> Drop
     </table>

     @section sec_secy_cp Control packets
     Control packets are defined as packets which will bypass encryption/decryption (not mapped to
     any secure channel). There are two types of control packet rules:
         -# Rule based on MAC DA and ethtype (#SECY_RuleOpt0Type): These rules matches MAC DA or
            EthType in the frame and mark them as control frame. MAC DA could be a exact match,
            range or const value. These rules are added by calling #SECY_AddCPRuleOpt0 API.
             Rules can be added separately for ingress and egress direction.
         -# Rule based on MAC DA, MAC SA and frame data (#SECY_RuleOpt1Type): These rules matches
            MAC DA, MAC SA and next 56-bits of frame data after SA. Match is based on the mask
            values which means any bits of the MAC DA, MAC SA or frame data can be selected for
            matching.These rules are added by calling #SECY_AddCPRuleOpt1 API. Rules can be
            added separately for ingress and egress direction.

     Multiple control packet rules can be added on a given port (limited by underlying
     hardware resource. Refer to TRM for the details about how many rules are allowed).

     A Rule can be deleted at time by calling #SECY_RemoveCPRule API.

     @section sec_secy_mgmt SecY Management
     As defined by IEEE Std 802.1AE-2018 Media Access Control (MAC) Security specification,
     a SecY entity provides one instance of secure service to its users.
     There may be zero, one or more SecY instances on one physical port (a physical port
     is defined in this interface specification).
     A SecY contains single transmit secure channel and may contain zero, one or more receive secure
     channels (maximum number of secure receive channels that can be created for a SecY is
     statically configured in system).

     In case where more than one SecY instances are required on the same physical port, each SecY
     will represent a virtual port (maximum number of SecY instances which can be created on a
     physical port is statically configured in system).

     <b>SecY</b>

     A SecY instance is created by calling #SECY_CreateSecy API which returns a unique handle to
     be used later for creation of secure channels and secure associations for the SecY.

     If #SECY_CfgType::includeSCI is set to FALSE during the creation of the SecY, it is
     assumed that its point-to-point connection. This SecY will not encode SCI field in the SecTAG
     while transmitting the frames. Also, this SecY will receive frames from at most one peer SecY
     entity without explicitly encoded SCI field in SecTAG.

     User needs to add a rule to map a specific traffic to a SecY instance by calling
     #SECY_AddSecYLookupRule API. Rule can be added separately for transmit traffic
     and receive traffic.

     When SecY is created:
         -# Replay protection is enabled by default with window size 0 (strict ordering).
         -# Frame protection is enabled by default.
         -# Frame validation is set to Strict mode.

     SecY can be deleted by calling #SECY_DeleteSecY API (user must ensure that transmit and
     receive channels and corresponding Secure associations are deleted by deleting SecY).

     <b>Secure channels</b>

     An SC represents a security relationship between members of a Secure Connectivity
     Association(CA).
     Each SC is supported by the sequence of secure associations (SAs), which allows refreshing the
     keys without terminating the SC. Each SC has maximum four active SAs (0, 1, 2,3).

     After the secy instance is created, a transmit secure channel can be created by calling
     #SECY_CreateTxSC API. <i>Only single transmit secure channel can be created for a SecY</i>.
     Transmit secure channel can be deleted by calling #SECY_DeleteTxSC (user must ensure that
     all the transmit SAs are deleted before deleting transmit secure channel).

     A receive secure channel for each peer in CA can be created by calling #SECY_CreateRxSC API.
     Multiple receive secure channels can be created for a SecY.
     A receive SC can be deleted by calling #SECY_DeleteRxSC API (user must ensure that all the
     receive SAs associated with this secure channels are deleted).

     <b> Secure associations (SAs)</b>

     SA is a security relationship that provides security guarantees for frames transmitted
     from one member of a Connectivity Association (CA) to the others. Each SA is has a secret
     key for frame protection and validation.

     Transmit SA is created by calling #SECY_CreateTxSA API and Receive SA is created by calling
     #SECY_CreateRxSA API. SA creation takes association number (AN) and key information as input
     and creates a cryptographic record in the hardware and returns handle.
     When SA is created, by default it is not enabled (inUse flag is set to FALSE and SA can not be
     used for frame protection or validation).SA can be activated by calling #SECY_EnableSA API.

     When a transmit SA is activated, it switches the transmission from previous transmit SA to the
     current SA (if this SA is first SA, it just becomes active for transmission) without
     interrupting the traffic and inUse flag is set to TRUE.
     when #SECY_EnableSA is called for receive SA, it becomes active (inUse flag set to TRUE) and
     frames received with this AN, can be decrypted and validated by this SA.

     An SA can be disabled at any point of time by calling #SECY_DisableSA API, which de-activates
     the SA and sets inUse flag to FALSE.
     Status of the SA can be checked by calling #SECY_GetSAStatus API.
     SA can be deleted by calling #SECY_DeleteSA API.

     @section sec_secy_vlan_in_clr VLAN in clear in SecY frame
     Driver can be configured to allow 802.1Q tagged packet (ethType = 0x8100) to be clear text
     (After MAC SA and before SecTAG) in MACSec frame. To configure VLAN in clear:
         -# Enable detection of VLAN tagged packet in frame (set #SECY_HwCfgType.enableQtagParse
            to TRUE during initialization of SecY block).
         -# SecY Configuration:
             -# Set #SECY_CfgType.preSecTagAuthStart to 0.
             -# Set #SECY_CfgType.preSecTagAuthLen to 12 (VLAN tag in not authenticated).
             -# Set #SECY_CfgType.secTagOffset to 16 (6 bytes MAC DA + 6 bytes MAC SA +
                4 bytes for 802.1Q tag).

    @section sec_secy_bypassing_eapol How to bypass EAPOL (Ethtype: 0x888E) packets
    This section describes how to bypass the EAPOL frames after the SECY is initialised on
    the given port. After the SECY is initialized, all the packets are dropped on the port till
    application creates a CP Rule to bypass a specific frames or creates SC/SAs and enables
    the controller port to allow the data frames.

    For 802.1X authentication, EAPOL packets needs to be forwarded to uncontrolled port of the SECY,
    to allow MKA session establishment. Steps to forward EAPOL frames to uncontrolled port of the SECY:
        -# Initialize SECY (#SECY_Init) on the port
        -# Add a control packet rule using #SECY_AddCPRuleOpt1:
            -# Set the frameData[0] field of the SECY_RuleOpt1Type to 0x8E88 (endian-reverse of 0x888E)
               SECY_RuleOpt1Type rule = {0}
               rule.frameData[0] = 0x8E88
            -# Set the matchFrameDataMask[0] to match 16-bits of the data:
               rule.matchFrameDataMask[0] = 0xFFFF
            -# Add the Rule for ingress/egress both direction:
                rule.dir = SECY_RULE_DIR_BOTH
                ret = SECY_AddCPRuleOpt1(port, &rule, &ruleHdl)
            -# After the rule is added, any frame having ethType as 0x888E will be forwarded to uncontrolled
               port of the SecY.

    @limitations None

    @file crypto_secy.h
    @brief Crypto MAC Security Entity (MACSEC) Interface
    This header file contains the interface functions for Crypto MAC Security Entity (MACSEC)

    @version 1.0 Initial Version
*/

#ifndef CRYPTO_SECY_H
#define CRYPTO_SECY_H

#include <crypto_secy_rpc.h>

#endif /* SECY_H */

/** @} */
