/*****************************************************************************
 Copyright 2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ethernet_pae_types  Types
    @ingroup grp_ethernet_pae_overview

    @addtogroup grp_ethernet_pae_types
    @{

    @file ethernet_pae_types.h
    @brief 802.1X Port Authentication entity interface
    This header file contains the interface functions for KaY

    @version 1.0 Initial Version
*/

#ifndef ETHERNET_PAE_TYPES_H
#define ETHERNET_PAE_TYPES_H

#include <bcm_comp.h>
#include <stdint.h>
#include <bcm_err.h>
#include <bcm_utils.h>
#include <crypto_secy.h>

/**
    @name PAE Architecture IDs
    @{
    @brief Architecture IDs for 802.1X PAE
*/
#define BRCM_SWARCH_PAE_ID_OF_MACRO                     (0x8100U) /**< @brief #PAE_ID_OF                    */
#define BRCM_SWARCH_PAE_ID_TYPE                         (0x8101U) /**< @brief #PAE_IdType                   */
#define BRCM_SWARCH_PAE_MACRO                           (0x8102U) /**< @brief #PAE_CFG_MAX_NID              */
#define BRCM_SWARCH_PAE_ROW_STATUS_TYPE                 (0x8103U) /**< @brief #PAE_RowStatusType            */
#define BRCM_SWARCH_PAE_SYS_MSG_TYPE                    (0x8104U) /**< @brief #PAE_SysMsgType               */

#define BRCM_SWARCH_PAE_NID_USE_EAP_TYPE                (0x8110U) /**< @brief #PAE_NidUseEapType            */
#define BRCM_SWARCH_PAE_NID_UNAUTH_ALLOWED_TYPE         (0x8111U) /**< @brief #PAE_NidUnauthAllowedType     */
#define BRCM_SWARCH_PAE_NID_UNSECURED_ALLOWED_TYPE      (0x8112U) /**< @brief #PAE_NidUnsecuredAllowedType  */
#define BRCM_SWARCH_PAE_NID_UNAUTH_STATUS_TYPE          (0x8113U) /**< @brief #PAE_NidUnauthStatusType      */
#define BRCM_SWARCH_PAE_NID_CAPABILITIES_TYPE           (0x8114U) /**< @brief #PAE_NidCapabilitiesType      */
#define BRCM_SWARCH_PAE_NID_MODE_TYPE                   (0x8115U) /**< @brief #PAE_NidModeType              */
#define BRCM_SWARCH_PAE_NID_CFG_TYPE                    (0x8116U) /**< @brief #PAE_NidCfgType               */
#define BRCM_SWARCH_PAE_NID_MSG_TYPE                    (0x8117U) /**< @brief #PAE_NidMsgType               */

#define BRCM_SWARCH_PAE_PORT_NUMBER_TYPE                (0x8120U) /**< @brief #PAE_PortNumberType           */
#define BRCM_SWARCH_PAE_PORT_TYPE                       (0x8121U) /**< @brief #PAE_PortType                 */
#define BRCM_SWARCH_PAE_PORT_ENABLE_TYPE                (0x8122U) /**< @brief #PAE_PortEnableType           */
#define BRCM_SWARCH_PAE_PORT_ADMIN_PT2PT_MAC_TYPE       (0x8123U) /**< @brief #PAE_PortAdminPt2PtMACType    */
#define BRCM_SWARCH_PAE_PORT_CFG_TYPE                   (0x8124U) /**< @brief #PAE_PortCfgType              */
#define BRCM_SWARCH_PAE_PORT_CAP_TYPE                   (0x8125U) /**< @brief #PAE_PortCapType              */
#define BRCM_SWARCH_PAE_CONNECT_STATUS_TYPE             (0x8126U) /**< @brief #PAE_ConnectStatusType        */
#define BRCM_SWARCH_PAE_PORT_STATUS_TYPE                (0x8127U) /**< @brief #PAE_PortStatusType           */
#define BRCM_SWARCH_PAE_SESS_TERM_CAUSE_TYPE            (0x8128U) /**< @brief #PAE_SessTermCauseType        */
#define BRCM_SWARCH_PAE_PORT_SESSION_STATS_TYPE         (0x8129U) /**< @brief #PAE_PortSessionStatsType     */
#define BRCM_SWARCH_PAE_PORT_CFG_MSG_TYPE               (0x812AU) /**< @brief #PAE_PortCfgMsgType           */
#define BRCM_SWARCH_PAE_PORT_STATUS_MSG_TYPE            (0x812BU) /**< @brief #PAE_PortStatusMsgType        */
#define BRCM_SWARCH_PAE_PORT_SESSION_STATS_MSG_TYPE     (0x812CU) /**< @brief #PAE_PortSessionStatsMsgType  */
#define BRCM_SWARCH_PAE_PORT_INIT_MSG_TYPE              (0x812DU) /**< @brief #PAE_PortInitMsgType          */
#define BRCM_SWARCH_PAE_PN_EXHAUSTION_MSG_TYPE          (0x812EU) /**< @brief #PAE_PnExhaustionMsgType      */

#define BRCM_SWARCH_PAE_KAY_CFG_TYPE                    (0x8130U) /**< @brief #PAE_KayCfgType               */
#define BRCM_SWARCH_PAE_KAY_MKA_STATUS_TYPE             (0x8131U) /**< @brief #PAE_KayMkaStatusType         */
#define BRCM_SWARCH_PAE_KAY_MACSEC_CAP_TYPE             (0x8132U) /**< @brief #PAE_KayMacSecCapType         */
#define BRCM_SWARCH_PAE_KAY_STATUS_TYPE                 (0x8133U) /**< @brief #PAE_KayStatusType            */

#define BRCM_SWARCH_PAE_MKA_PART_ACTIVATE_TYPE          (0x8140U) /**< @brief #PAE_MkaPartActivateType      */
#define BRCM_SWARCH_PAE_MKA_PART_CFG_TYPE               (0x8141U) /**< @brief #PAE_MkaPartCfgType           */
#define BRCM_SWARCH_PAE_MKA_PEER_TYPE                   (0x8142U) /**< @brief #PAE_MkaPeerType              */
#define BRCM_SWARCH_PAE_MKA_PEER_ENTRY_TYPE             (0x8143U) /**< @brief #PAE_MkaPeerEntryType         */
#define BRCM_SWARCH_PAE_MKA_PART_STATUS_TYPE            (0x8144U) /**< @brief #PAE_MkaPartStatusType        */
#define BRCM_SWARCH_PAE_MKA_PART_STATUS_MSG_TYPE        (0x8145U) /**< @brief #PAE_MkaPartStatusMsgType     */
#define BRCM_SWARCH_PAE_MKA_PART_CFG_MSG_TYPE           (0x8146U) /**< @brief #PAE_MkaPartCfgMsgType        */

#define BRCM_SWARCH_PAE_SYS_MKA_VERSION_TYPE            (0x8150U) /**< @brief #PAE_SysMkaVersionType        */
#define BRCM_SWARCH_PAE_CFG_TYPE                        (0x8151U) /**< @brief #PAE_CfgType                  */

/** @} */

/**
    @brief Macro to Construct PAE Cmd

    @trace #BRCM_SWREQ_PAE
*/
#define PAE_ID_OF(aId)     BCM_MSG(BCM_GROUPID_ETHSRV, BCM_PAE_ID, aId)

/**
    @name PAE Message IDs
    @{
    @brief Message IDs for exchange on message queues

    @trace #BRCM_SWREQ_PAE
*/
typedef BCM_MsgType PAE_IdType;
#define PAE_ID_GLOBAL_CONTROL       PAE_ID_OF(0x00UL)   /**< @brief #PAE_SysMsgType                 #PAE_Enable/#PAE_Disable*/
#define PAE_ID_SET_NID_CFG          PAE_ID_OF(0x01UL)   /**< @brief #PAE_NidMsgType                 #PAE_SetNidCfg          */
#define PAE_ID_GET_NID_CFG          PAE_ID_OF(0x02UL)   /**< @brief #PAE_NidMsgType                 #PAE_GetNidCfg          */
#define PAE_ID_SET_MKA_PART_CFG     PAE_ID_OF(0x03UL)   /**< @brief #PAE_MkaPartCfgMsgType          #PAE_SetMkaPartCfg      */
#define PAE_ID_GET_MKA_PART_STATUS  PAE_ID_OF(0x04UL)   /**< @brief #PAE_MkaPartStatusMsgType       #PAE_GetMkaPartStatus   */
#define PAE_ID_SET_PN_EXHAUSTION    PAE_ID_OF(0x05UL)   /**< @brief #PAE_PnExhaustionMsgType        #PAE_SetPNExhaustion    */

#define PAE_ID_SET_PORT_CFG         PAE_ID_OF(0x08UL)   /**< @brief #PAE_PortCfgMsgType             #PAE_SetPortCfg         */
#define PAE_ID_GET_PORT_STATUS      PAE_ID_OF(0x09UL)   /**< @brief #PAE_PortStatusMsgType          #PAE_GetPortStatus      */
#define PAE_ID_GET_PORT_STATS       PAE_ID_OF(0x0AUL)   /**< @brief #PAE_PortSessionStatsMsgType    #PAE_GetPortStats       */
/** @} */


/**
    @name PAE Macros
    @{
    @brief PAE macros

    @trace #BRCM_SWREQ_PAE
*/
#define PAE_CFG_MAX_NID                 (2UL)   /**< @brief Maximum number of NID configs       */
#define PAE_CFG_MAX_PORT                (32UL)  /**< @brief Maximum number of Port configs      */
#define PAE_CFG_MAX_PARTICIPANT         (4UL)  /**< @brief Maximum number of Participant config*/
#define PAE_CKN_MAX_LEN                 (32UL)  /**< @brief Maximum length of the CKN           */
#define PAE_NID_MAX_LEN                 (100UL) /**< @brief Maximum length of the NID string    */
#define PAE_KMD_MAX_LEN                 (256UL) /**< @brief Maximum length of the KMD string,
                                                    limited to 253 bytes by 802.1X specification*/
#define PAE_MKA_MI_LEN                  (12UL)  /**< @brief maximum size of member identification*/
#define PAE_MAX_MKA_PEERS               (2UL)   /**< @brief Maximum number of peers per port    */
#define PAE_SESSION_ID_MAX_LEN          (256UL) /**< @brief maximum length of the PAE session ID,
                                                    limited to 253 bytes by 802.1X specification*/
#define PAE_SESSION_NAME_MAX_LEN        (256UL) /**< @brief maximum length of the PAE session name,
                                                    limited to 253 bytes by 802.1X specification*/
#define PAE_MSG_MAX_SIZE                (432UL) /**< @brief maximum message size                */
#define PAE_KAY_MKA_DEF_HELLO_TIME_MS   (2000UL)/**< @brief default MKA hello time 2s           */
#define PAE_KAY_MKA_DEF_LIFE_TIME_MS    (6000UL)/**< @brief default MKA life time 6s            */

#define PAE_KEY_CLASS_ID_SAK            (0x1U)
#define PAE_KEY_CLASS_ID_CAK            (0x2U)
/** @} */

/**
    @name PAE status
    @{
    @brief PAE status

    This parameter resembles 802.1X MIB ieee8021XNidRowStatus and ieee8021XKayMkaPartRowStatus
    which is derived from RowStatus MIB from SNMPv2.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_RowStatusType;
#define PAE_ROW_STATUS_ACTIVE           (1U)   /**< @brief active       */
#define PAE_ROW_STATUS_NOT_IN_SERVICE   (2U)   /**< @brief not in service  */
#define PAE_ROW_STATUS_NOT_READY        (3U)   /**< @brief not ready    */
#define PAE_ROW_STATUS_CREATE_AND_GO    (4U)   /**< @brief created and active */
#define PAE_ROW_STATUS_CREATE_AND_WAIT  (5U)   /**< @brief created and waiting for activation */
#define PAE_ROW_STATUS_DESTROY          (6U)   /**< @brief destroyed       */
/** @} */

/**
    @name NID Capabilities
    @{
    @brief NID Capabilities

    This parameter resembles 802.1X MIB Ieee8021XPaeNIDCapabilites.

    @limitations Only MKA, MKA_MACSEC and VENDOR_SPECIFIC are supported.
    Others are left for future enhanncements.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_NidCapabilitiesType;
#define PAE_NID_CAPABILITIES_MKA                    (1UL << 3UL)
#define PAE_NID_CAPABILITIES_MKA_MACSEC             (1UL << 4UL)
#define PAE_NID_CAPABILITIES_VENDOR_SPECIFIC        (1UL << 7UL)  /**< @brief To be used together with #PAE_NidModeType*/
/** @} */

/**
    @name Broadcom specific mode
    @{
    @brief Broadcom specific mode

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_NidModeType;
/** @} */


/**
    @name NID EAP Use
    @{
    @brief EAP Use types supported

    This parameter resembles 802.1X MIB ieee8021XNidUseEap.

    @limitations Only Never Use EAP is supported. Others are left for future
    enhanncements

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_NidUseEapType;
#define PAE_NID_USE_EAP_NEVER       (1U)   /**< @brief Never use EAP   */
/** @} */

/**
    @name NID Unauth allowed
    @{
    @brief Controls for Unauthorized connections

    This parameter resembles 802.1X MIB ieee8021XNidUnauthAllowed.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_NidUnauthAllowedType;
#define PAE_NID_UNAUTH_ALLOWED_NEVER     (1U)  /**< @brief Never allow         */
#define PAE_NID_UNAUTH_ALLOWED_IMMEDIATE (2U)  /**< @brief Immediately allow   */
#define PAE_NID_UNAUTH_ALLOWED_AUTH_FAIL (3U)  /**< @brief Allow upon Auth fail*/
/** @} */

/**
    @name NID Unsecured allowed
    @{
    @brief Controls for Unsecured connections

    This parameter resembles 802.1X MIB ieee8021XNidUnsecuredAllowed.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_NidUnsecuredAllowedType;
#define PAE_NID_UNSECURED_ALLOWED_NEVER       (1U) /**< @brief Never allow                 */
#define PAE_NID_UNSECURED_ALLOWED_IMMEDIATE   (2U) /**< @brief Immediately allow           */
#define PAE_NID_UNSECURED_ALLOWED_MKA_FAIL    (3U) /**< @brief Allow upon MKA Fail/Disable */
#define PAE_NID_UNSECURED_ALLOWED_MKA_SERVER  (4U) /**< @brief Allow upon MKA Server directs*/
/** @} */

/**
    @name NID Unauthenticated status
    @{
    @brief Controls for Unauthenticated connection status

    This parameter resembles 802.1X MIB Ieee8021XPaeNIDUnauthenticatedStatus.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_NidUnauthStatusType;
#define PAE_NID_UNAUTH_STATUS_NO_ACCESS        (0U)   /**< @brief No Access                       */
#define PAE_NID_UNAUTH_STATUS_FALLBACK_ACCESS  (1U)   /**< @brief Limited access upon Auth Failure*/
#define PAE_NID_UNAUTH_STATUS_LIMITED_ACCESS   (2U)   /**< @brief Immediate Limited access        */
#define PAE_NID_UNAUTH_STATUS_OPEN_ACCESS      (3U)   /**< @brief Open Access without Authentication */
/** @} */

/**
    @brief Network Identifier Configuration

    This parameter resembles 802.1X MIB ieee8021XNidConfigEntry.

    @trace #BRCM_SWREQ_PAE

*/
typedef struct sPAE_NidCfgType {
    PAE_NidCapabilitiesType             accessCapabilities;     /**< @brief Enabled access capabilities.
                                                                Refer 802.1X MIB ieee8021XNidAccessCapabilities  @xsd default:PAE_NID_CAPABILITIES_MKA   */
    PAE_NidModeType                     mode;                   /**< @brief This depicts Broadcom specific mode, @xsd default:0
                                                                used only when access capabilities has
                                                                #PAE_NID_CAPABILITIES_VENDOR_SPECIFIC set           */
    uint8_t                             nid[PAE_NID_MAX_LEN];   /**< @brief NID Name. @xsd str
                                                                Refer 802.1X MIB ieee8021XNidNID and Ieee8021XPaeNID*/
    PAE_NidUseEapType                   useEap;                 /**< @brief EAP Controls.
                                                                Refer 802.1X MIB ieee8021XNidUseEap                 */
    PAE_NidUnauthAllowedType            unauthAllowed;          /**< @brief Control for unauthorized connections.
                                                                Refer 802.1X MIB ieee8021XNidUnauthAllowed @xsd default:PAE_NID_UNAUTH_ALLOWED_NEVER */
    PAE_NidUnsecuredAllowedType         unsecuredAllowed;       /**< @brief Control for Unsecured connections.
                                                                Refer 802.1X MIB ieee8021XNidUnsecuredAllowed @xsd default:PAE_NID_UNSECURED_ALLOWED_NEVER */
    PAE_NidUnauthStatusType             unauthenticated;        /**< @brief Control for unauthorized connection access.
                                                                Refer 802.1X MIB ieee8021XNidUnauthenticatedAccess @xsd default:PAE_NID_UNAUTH_STATUS_NO_ACCESS */
    PAE_RowStatusType                   status;                 /**< @brief NID Status. Must be set to active for use.
                                                                Refer 802.1X MIB ieee8021XNidRowStatus, RowStatus @xsd default:PAE_ROW_STATUS_ACTIVE */
    uint8_t                             kmd[PAE_KMD_MAX_LEN];   /**< @brief Key Management Domain. @xsd hexdec
                                                                Refer 802.1X MIB ieee8021XNidKMD, Ieee8021XPaeKMD   */
    uint8_t                             reserved[15UL];         /**< @brief Reserved @xsd rsvd */
} PAE_NidCfgType;
BCM_STATIC_SIZE_ASSERT(PAE_NidCfgType, 384UL, PAE_MSG_MAX_SIZE);

/**
    @brief Port number

    This parameter resembles 802.1X MIB ieee8021XPaePortNumber.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_PortNumberType;

/**
    @name Port Feature control
    @{
    @brief Bit Mask to control individual features on each port

    This parameter resembles 802.1X MIB ieee8021XPaePortLogonEnable and
    ieee8021XPaePortKayMkaEnable.

    @note This maybe extended to ieee8021XPaePortAuthenticatorEnable,
    ieee8021XPaePortSupplicantEnable, ieee8021XPaePortAnnouncerEnable, and
    ieee8021XPaePortListenerEnable in the future.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_PortEnableType;
#define PAE_PORT_ENABLE_KAY_MKA_MASK    (0x2UL)  /**< @brief Mask to Enable KAY
                                                      @xsd name:enKay */
#define PAE_PORT_ENABLE_KAY_MKA_SHIFT   (1UL)    /**< @brief Shift to Enable KAY */
#define PAE_PORT_ENABLE_LOGON_MASK      (0x4UL)  /**< @brief Mask to Enable LOGON
                                                      @xsd name:enLogon */
#define PAE_PORT_ENABLE_LOGON_SHIFT     (2UL)    /**< @brief Shift to Enable Logon */
/** @} */

/**
    @name Port type
    @{
    @brief Port type

    This parameter resembles 802.1X MIB ieee8021XPaePortType.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_PortType;
#define PAE_PORT_TYPE_REAL      (1U)
/** @} */

/**
    @name Port Point to point mac control
    @{
    @brief Control point to point mac mode of operation for the port

    This parameter resembles 802.1X MIB ieee8021XPacPortAdminPt2PtMAC.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_PortAdminPt2PtMACType;
#define PAE_PORT_ADMIN_PT2PT_MAC_FORCE_TRUE     (1U)
/** @} */

/**
    @brief Port configuration for PAE and PAC

    This parameter resembles 802.1X MIB ieee8021XPaePortEntry and ieee8021XPacPortEntry.

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_PortCfgType {
    PAE_PortEnableType          enabled;        /**< @brief Bit Mask of Enabled Features.
                                                This parameter resembles 802.1X MIB ieee8021XPaePortLogonEnable,
                                                ieee8021XPaePortAuthenticatorEnable, ieee8021XPaePortSupplicantEnable,
                                                ieee8021XPaePortKayMkaEnable,ieee8021XPaePortAnnouncerEnable,
                                                ieee8021XPaePortListenerEnable.and ieee8021XPaePortInitialize as Bit Mask*/
    PAE_PortType                portType;       /**< @brief Port Type.
                                                This parameter resembles 802.1X MIB ieee8021XPaePortType. */
    PAE_PortAdminPt2PtMACType   adminPtToPtMAC; /**< @brief Admin Configuration of Point to Point MAC.
                                                This parameter resembles 802.1X MIB ieee8021XPacPortAdminPt2PtMAC
                                                in ieee8021XPacPortEntry.*/
    uint8_t                     selectedNidIdx; /**< @brief Selected NID. @xsd default:0
                                                This parameter resembles 802.1X MIB ieee8021XLogonNIDSelectedNID */
    uint8_t                     reserved[17UL];  /**< @brief This space is reserved for future use including below MIB elements.
                                                ieee8021XPaePortVirtualPortsEnable, ieee8021XPaePortMaxVirtualPorts
                                                ieee8021XPaePortCurrentVirtualPorts, ieee8021XPaePortVirtualPortStart,
                                                ieee8021XPaePortVirtualPortPeerMAC, ieee8021XPaeEapolGroupMAC,
                                                ieee8021XPaeControlledPortNumber, ieee8021XPaeUncontrolledPortNumber,
                                                ieee8021XPaeCommonPortNumber, ieee8021XPaePortCapabilities @xsd rsvd */
} PAE_PortCfgType;
BCM_STATIC_SIZE_ASSERT(PAE_PortCfgType, 24UL, PAE_MSG_MAX_SIZE);


/**
    @brief Kay configuration for the port

    This parameter resembles 802.1X MIB ieee8021XKayMkaEntry.

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_KayCfgType {
    BCM_BoolType        macsecDesired;          /**<  @brief Control whether MACSec is desired for the port.
                                                This parameter resembles 802.1X MIB ieee8021XKayMacSecDesired*/
    uint8_t             actorPriority;          /**<  @brief Actor priority for the port's MKA actors. @xsd hex;default:0x0
                                                This parameter resembles 802.1X MIB ieee8021XKayMkaActorsPriority */
    uint8_t             reserved0[3UL];         /**< @brief Reserved @xsd rsvd */
    SECY_ConfOffsetType macsecConfidentiality;  /**<  @brief Confidentiality offset.
                                                This parameter resembles 802.1X MIB ieee8021XKayMacSecConfidentialityOffset */
    uint32_t            retryCount;             /**< @brief Number of times an actor tries to establish the connection before
                                                giving up @xsd default:0*/
    uint32_t            retryTimeMs;            /**< @brief Actor connection establishment attempt internal in milli-seconds @xsd default:0*/
    uint32_t            helloTime;              /**< @brief Hello time in Milli-seconds. if set 0, default MKA hello time 2s @xsd default:0
                                                will be used for this KaY              */
    uint32_t            lifeTime;               /**< @brief MKA life time in milli-seconds. If set to 0, default MKA life time @xsd default:0
                                                of 6 seconds will be use             */
    uint32_t            reserved1[5UL];         /**< Reserved for ieee8021XKayMkaActive, ieee8021XKayMkaAuthenticated
                                                ieee8021XKayAllowedJoinGroup, ieee8021XKayMkaSecured,
                                                ieee8021XKayMkaFailed, ieee8021XKayMkaActorSCI, ieee8021XKayMkaKeyServerSCI,
                                                ieee8021XKayMkaKeyServerPriority, ieee8021XKayMacSecCapability,
                                                ieee8021XKayMacSecProtect, ieee8021XKayMacSecReplayProtect,
                                                ieee8021XKayMacSecValidate, ieee8021XKayMkaTxKN,
                                                ieee8021XKayMkaTxAN, ieee8021XKayMkaRxKN, ieee8021XKayMkaRxAN,
                                                ieee8021XKayAllowedFormGroup, ieee8021XKayCreateNewGroup,
                                                ieee8021XKayMkaSuspendFor, ieee8021XKayMkaSuspendOnRequest,
                                                and ieee8021XKayMkaSuspendedWhile @xsd rsvd */
} PAE_KayCfgType;
BCM_STATIC_SIZE_ASSERT(PAE_KayCfgType, 48UL, PAE_MSG_MAX_SIZE);

/**
    @name MKA Participant activation control
    @{
    @brief MKA Participant activation control

    This parameter resembles 802.1X MIB ieee8021XKayMkaPartActivateControl.

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_MkaPartActivateType;
#define PAE_MKA_PART_ACTIVATE_DEFAULT       (1U)
#define PAE_MKA_PART_ACTIVATE_DISABLED      (2U)
#define PAE_MKA_PART_ACTIVATE_ON_OPER_UP    (3U)
#define PAE_MKA_PART_ACTIVATE_ALWAYS        (4U)
/** @} */

/**
    @brief MKA Participant Config

    This parameter resembles 802.1X MIB ieee8021XKayMkaParticipantEntry.

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_MkaPartCfgType {
    uint8_t                     ckn[PAE_CKN_MAX_LEN];/**< @brief Secure connectivity association key name. @xsd hexdec
                                                This parameter resembles 802.1X MIB ieee8021XKayMkaPartCKN */
    uint8_t                     cknLen;         /**< @brief CKN Length. @xsd count:ckn
                                                This parameter resembles 802.1X MIB ieee8021XKayMkaPartNID  */
    uint8_t                     nidIdx;         /**< @brief Network Identifier. @xsd default:0
                                                This parameter resembles 802.1X MIB ieee8021XKayMkaPartNID  */
    PAE_MkaPartActivateType     activate;       /**< @brief Default activation behaviour.
                                                This parameter resembles 802.1X MIB ieee8021XKayMkaPartActivateControl
                                                @xsd default:PAE_MKA_PART_ACTIVATE_DEFAULT */
    uint8_t                     reserved[13UL]; /**< @brief ieee8021XKayMkaPartRetain, ieee8021XKayMkaPartActive,
                                                ieee8021XKayMkaPartPrincipal, ieee8021XKayMkaPartDistCKN
                                                ieee8021XKayMkaPartRowStatus @xsd rsvd */
} PAE_MkaPartCfgType;
BCM_STATIC_SIZE_ASSERT(PAE_MkaPartCfgType, 48UL, PAE_MSG_MAX_SIZE);

/**
    @name MKA Version
    @{
    @brief MKA Protocol version type

    This parameter resembles 802.1X MIB ieee8021XPaeSysMkaVersion

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_SysMkaVersionType;
#define PAE_SYS_MKA_VERSION_3     (3UL)
/** @} */


/**
    @brief PAE Static Configuration

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_CfgType {
    BCM_BoolType            systemAccessControl;/**< @brief Enable/Disable PAE at the system level for all ports.
                                                        This parameter resembles 802.1X MIB ieee8021XPaeSysAccessControl */
    uint32_t                reserved0[2UL];     /**< @brief This space is reserved for future use including
                                                        MIB elements ieee8021XPaeSysEapolVersion, ieee8021XPaeSysAnnouncements
                                                        @xsd rsvd */
    PAE_SysMkaVersionType   mkaVersion;         /**< @brief Default MKA version to be used.
                                                        This parameter resembles 802.1X MIB ieee8021XPaeSysMkaVersion   */
    PAE_NidCfgType          nid[PAE_CFG_MAX_NID];    /**< @brief Network Identifier Configuration  */
    PAE_PortCfgType         port[PAE_CFG_MAX_PORT];  /**< @brief Port configuration for PAE and PAC  */
    PAE_KayCfgType          kay[PAE_CFG_MAX_PORT];   /**< @brief Kay configuration for the port  */
    PAE_MkaPartCfgType      participant[PAE_CFG_MAX_PARTICIPANT];   /**< @brief MKA Participant  */
    uint32_t                reserved1[10UL];         /**< @brief Reserved @xsd rsvd  */
} PAE_CfgType;
BCM_STATIC_SIZE_ASSERT(PAE_CfgType, 3320UL, 3320UL);

/**
    @name Port Capabilities
    @{
    @brief Port Capabilities

    This parameter resembles 802.1X MIB ieee8021XPaePortCapabilities

    @limitations Other flags defined in the 802.1X specification will be added
    in the future

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_PortCapType;
#define PAE_PORT_CAP_MKA_IMPLEMENTED             (1UL << 2UL)
#define PAE_PORT_CAP_MACSEC_IMPLEMENTED          (1UL << 3UL)
/** @} */

/**
    @name Port Logon Connection Status
    @{
    @brief Port Logon Connection Status

    This parameter resembles 802.1X MIB ieee8021XPaePortLogonConnectStatus

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_ConnectStatusType;
#define PAE_CONNECT_STATUS_UNKNOWN           (0UL)
#define PAE_CONNECT_STATUS_PENDING           (1UL)
#define PAE_CONNECT_STATUS_UNAUTHENTICATED   (2UL)
#define PAE_CONNECT_STATUS_AUTHENTICATED     (3UL)
#define PAE_CONNECT_STATUS_SECURE            (4UL)
#define PAE_CONNECT_STATUS_FAILED            (8UL)
/** @} */


/**
    @brief Port Status

    This parameter resembles 802.1X MIB ieee8021XPaePortEntry and
    ieee8021XPaePortLogonEntry

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_PortStatusType {
    PAE_PortType                type;           /**< @brief Real or Virtual port number.
                                                This parameter resembles 802.1X MIB ieee8021XPaePortNumber
                                                and ieee8021XPaePortType. */
    PAE_PortNumberType          controlledPortNumber;/**< @brief Controlled Port Number.
                                                This parameter resembles 802.1X MIB ieee8021XPaeControlledPortNumber.*/
    PAE_PortNumberType          uncontrolledPortNumber;/**< @brief Uncontrolled Port Number.
                                                This parameter resembles 802.1X MIB ieee8021XPaeUncontrolledPortNumber.*/
    PAE_PortNumberType          commonPortNumber;/**< @brief Common Port Number.
                                                This parameter resembles 802.1X MIB ieee8021XPaeCommonPortNumber.*/
    PAE_PortCapType             implemented;    /**< @brief Implemented Features for this port.
                                                This parameter resembles 802.1X MIB ieee8021XPaePortCapabilities.*/
    PAE_PortEnableType          enabled;        /**< @brief Bit Mask of Enabled Features
                                                This parameter resembles 802.1X MIB ieee8021XPaePortLogonEnable,
                                                ieee8021XPaePortAuthenticatorEnable, ieee8021XPaePortSupplicantEnable,
                                                ieee8021XPaePortKayMkaEnable,ieee8021XPaePortAnnouncerEnable, and
                                                ieee8021XPaePortListenerEnable, ieee8021XPaePortInitialize.as Bit Mask*/
    PAE_ConnectStatusType      connect;         /**< @brief Connection Status.
                                                This parameter resembles 802.1X MIB ieee8021XPaePortLogonConnectStatus */
    BCM_BoolType               portValid;       /**< @brief Port Valid.
                                                This parameter resembles 802.1X MIB ieee8021XPaePortPortValid */
    BCM_BoolType               operPointToPointMAC;/**< @brief Operating mode of Point to Point MAC.
                                                This parameter resembles 802.1X MIB ieee8021XPacPortOperPt2PtMAC
                                                in ieee8021XPacPortEntry.*/
    uint32_t                   selectedNidIdx;  /**< @brief Selected NID.
                                                This parameter resembles 802.1X MIB ieee8021XLogonNIDSelectedNID */
    uint32_t                   reserved[6UL];   /**< @brief This space is reserved for future use including below MIB elements.
                                                ieee8021XPaePortVirtualPortsEnable, ieee8021XPaePortMaxVirtualPorts
                                                ieee8021XPaePortCurrentVirtualPorts, ieee8021XPaePortVirtualPortStart,
                                                ieee8021XPaePortVirtualPortPeerMAC, ieee8021XPaeEapolGroupMAC*/
} PAE_PortStatusType;
BCM_STATIC_SIZE_ASSERT(PAE_PortStatusType, 64UL, PAE_MSG_MAX_SIZE);


/**
    @name Kay Connection Status
    @{
    @brief Kay Connection Status

    This parameter resembles 802.1X MIB ieee8021XKayMkaAuthenticated,
    ieee8021XKayMkaSecured, and ieee8021XKayMkaFailed

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_KayMkaStatusType;
#define PAE_KAY_MKA_STATUS_AUTHENTICATED    (1UL)
#define PAE_KAY_MKA_STATUS_SECURED          (2UL)
#define PAE_KAY_MKA_STATUS_FAILED           (3UL)
/** @} */

/**
    @name Kay MACSecCapabilities
    @{
    @brief Kay MACSec Capabilities

    This parameter resembles 802.1X MIB ieee8021XKayMacSecCapability

    @trace #BRCM_SWREQ_PAE
*/
typedef SECY_CipherCapType PAE_KayMacSecCapType;
#define PAE_KAY_MACSEC_CAP_NO_MACSEC                 (0UL)
#define PAE_KAY_MACSEC_CAP_INTEGRITY                 (1UL)
#define PAE_KAY_MACSEC_CAP_CONFIDENTIALITY           (2UL)
#define PAE_KAY_MACSEC_CAP_OFFSET_CONFIDENTIALITY    (3UL)
/** @} */

/**
    @brief Kay Status

    This parameter resembles 802.1X MIB ieee8021XKayMkaEntry

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_KayStatusType {
    BCM_BoolType            active;         /**< @brief MKA status (active or inactive).
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaActive       */
    PAE_KayMkaStatusType    status;         /**< @brief MKA authentication status.                          */
    SECY_SCIType            actorSCI;       /**< @brief SCI assigned by the sytem to the port.
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaActorSCI     */
    SECY_SCIType            keyServerSCI;   /**< @brief Key Server SCI.
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaKeyServerSCI */
    uint8_t                 actorPriority;  /**< @brief MKA Actor priority.
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaActorsPriority*/
    uint8_t                 keyServerPriority;/**< @brief Elected Key server priority.
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaKeyServerPriority */
    uint16_t                reserved[3UL];
    PAE_KayMacSecCapType    macsecCapable; /**< @brief MACSec capability.
                                            This parameter resembles 802.1X MIB ieee8021XKayMacSecCapability*/
    BCM_BoolType            macsecDesired;  /**< @brief Configuration whether MACSec is desired.
                                            This parameter resembles 802.1X MIB ieee8021XKayMacSecDesired   */
    BCM_BoolType            macsecProtect;  /**< @brief MACSec protection status.
                                            This parameter resembles 802.1X MIB ieee8021XKayMacSecProtect   */
    BCM_BoolType            macsecReplayProtect;/**< @brief MACSec Replay protection status.
                                            This parameter resembles 802.1X MIB ieee8021XKayMacSecReplayProtect */
    BCM_BoolType            macsecValidate; /**< @brief MACSec Validation status.
                                            This parameter resembles 802.1X MIB ieee8021XKayMacSecValidate  */
    SECY_ConfOffsetType     macsecConfidentiality;/**< @brief Confidentiality offset selected by the Cipher suite.
                                            This parameter resembles 802.1X MIB ieee8021XKayMacSecConfidentialityOffset */
    uint32_t                txKN;           /**< @brief Transmit Key Number.
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaTxKN         */
    uint32_t                rxKN;           /**< @brief Receive Key Number.
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaRxKN         */
    SECY_HandleType         txSA;           /**< @brief Transmit SA handle.
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaTxAN         */
    SECY_HandleType         rxSA;           /**< @brief Receive SA Handle.
                                            This parameter resembles 802.1X MIB ieee8021XKayMkaRxAN */
    uint32_t                reserved1[12UL]; /**< Reserved for     ieee8021XKayAllowedJoinGroup,
                                        ieee8021XKayAllowedFormGroup, ieee8021XKayCreateNewGroup,
                                        ieee8021XKayMkaSuspendFor, ieee8021XKayMkaSuspendOnRequest,
                                        and ieee8021XKayMkaSuspendedWhile */
} PAE_KayStatusType;
BCM_STATIC_SIZE_ASSERT(PAE_KayStatusType, 128UL, PAE_MSG_MAX_SIZE);

/**
    @name MKA Peer Type
    @{
    @brief MKA Peer Type

    This parameter resembles 802.1X MIB ieee8021XKayMkaPeerListType

    @trace #BRCM_SWREQ_PAE
*/
typedef uint32_t PAE_MkaPeerType;
#define PAE_MKA_PEER_LIVE      (1UL)
#define PAE_MKA_PEER_POTENTIAL (2UL)
/** @} */

/**
    @brief MKA Peer

    This parameter resembles 802.1X MIB ieee8021XKayMkaPeerListEntry

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_MkaPeerEntryType {
    PAE_MkaPeerType     type;   /**< @brief Peer Type.
                                This resembles 802.1X MIB ieee8021XKayMkaPeerListType   */
    uint32_t            mn;     /**< @brief Member Number.
                                This resembles 802.1X MIB ieee8021XKayMkaPeerListMN     */
    uint8_t             mi[PAE_MKA_MI_LEN];/**< @brief Member Identifier.
                                This resembles 802.1X MIB ieee8021XKayMkaPeerListMI     */
    SECY_SCIType        sci;    /**< @brief Secure Channel Identifier.
                                This resembles 802.1X MIB ieee8021XKayMkaPeerListSCI    */
    uint32_t            reserved;
} PAE_MkaPeerEntryType;
BCM_STATIC_SIZE_ASSERT(PAE_MkaPeerEntryType, 32UL, PAE_MSG_MAX_SIZE);


/**
    @brief MKA Participant Status

    This parameter resembles 802.1X MIB ieee8021XKayMkaParticipantEntry

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_MkaPartStatusType {
    uint32_t        nid;        /**< @brief NID Index.                          */
    BCM_BoolType    cached;     /**< @brief Is Participant cached.
                                This resembles 802.1X MIB ieee8021XKayMkaPartCached */
    BCM_BoolType    active;     /**< @brief Is the participant active.
                                This resembles 802.1X MIB ieee8021XKayMkaPartActive */
    BCM_BoolType    principal;  /**< @brief Is the participant principal actor.
                                This resembles 802.1X MIB ieee8021XKayMkaPartPrincipal */
    PAE_RowStatusType  status;  /**< @brief Participant status.
                                This resembles 802.1X MIB ieee8021XKayMkaPartRowStatus */
    uint8_t        reserved[31UL]; /**< @brief Reserved for future use including
                                ieee8021XKayMkaPartRetain, ieee8021XKayMkaPartDistCKN
                                and ieee8021XKayMkaPartActivateControl      */
} PAE_MkaPartStatusType;
BCM_STATIC_SIZE_ASSERT(PAE_MkaPartStatusType, 48UL, PAE_MSG_MAX_SIZE);

/**
    @name PAE_SessTermCauseType
    @{
    @brief PAE session terminate causes

    This resembles 802.1X MIB ieee8021XPaePortSessionTerminate

    @trace #BRCM_SWREQ_PAE
*/
typedef uint8_t PAE_SessTermCauseType;
#define PAE_SESS_TERM_CAUSE_MAC_OPER_FAILED             (1U)   /**< @brief Common Port for this PAE
                                                                     is not operational */
#define PAE_SESS_TERM_CAUSE_SYSACC_DIS_OR_PORT_REINIT   (2U)   /**< @brief System access control
                                                                     is set to FALSE or re-init
                                                                     process for this PAE is
                                                                     invoked */
#define PAE_SESS_TERM_CAUSE_MKA_FAILURE                 (5U)   /**< @brief MKA failure or other MKA
                                                                     termination */
#define PAE_SESS_TERM_CAUSE_NOT_TERM_YET                (6U)   /**< @brief Not terminated yet */
/** @} */

/**
    @brief PAE session status and stats

    This resembles 802.1X MIB ieee8021XPaePortSessionEntry

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_PortSessionStatsType {
    uint64_t                octetsRx;   /**< @brief Session Octets Received.
                                        This resembles 802.1X MIB ieee8021XPaePortSessionOctetsRx*/
    uint64_t                octetsTx;   /**< @brief Session Octets Transmitted.
                                        This resembles 802.1X MIB ieee8021XPaePortSessionOctetsTx*/
    uint64_t                pktsRx;     /**< @brief Session Frames Received.
                                        This resembles 802.1X MIB ieee8021XPaePortSessionPktsRx*/
    uint64_t                pktsTx;     /**< @brief Session Frames Transmitted.
                                        This resembles 802.1X MIB ieee8021XPaePortSessionPktsTx*/
    uint64_t                startTime;  /**< @brief upTime when the session started in milliseconds.
                                        This resembles 802.1X MIB ieee8021XPaePortSessionStartTime*/
    uint64_t                intervalTime;/**< @brief duration of the session in milliseconds.
                                        This resembles 802.1X MIB ieee8021XPaePortSessionIntervalTime */
    PAE_SessTermCauseType   termCause;  /**< @brief cause of session termination.           */
    uint8_t                 sessionID[PAE_SESSION_ID_MAX_LEN]; /**< @brief session id.
                                        This resembles 802.1X MIB ieee8021XPaePortSessionId     */
    uint8_t                 rsvd0[15UL];/**< @brief This space is reserved for future use including
                                        MIB elements ieee8021XPaePortSessionUserName            */
} PAE_PortSessionStatsType;
BCM_STATIC_SIZE_ASSERT(PAE_PortSessionStatsType, 320UL, PAE_MSG_MAX_SIZE);

/**
    @brief System Configuration Message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_SysMsgType {
    uint32_t                enable;  /**< @brief input: Enable/Disable PAE at global level.
                                            0: Disable, 1: Enable*/
    uint32_t                reserved[7UL];
} PAE_SysMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_SysMsgType, 32UL, PAE_MSG_MAX_SIZE);

/**
    @brief NID Configuration and query message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_NidMsgType {
    uint32_t                index;  /**< @brief input: NID index                */
    uint32_t                reserved;
    PAE_NidCfgType          nid;    /**< @brief NID configuration.
                                        Input for PAE_SET_NID_CFG.
                                        Output for PAE_GET_NID_CFG              */
} PAE_NidMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_NidMsgType, 392UL, PAE_MSG_MAX_SIZE);

/**
    @brief Port configuration message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_PortCfgMsgType {
    PAE_PortNumberType      portNum;    /**< @brief Input: Port Number          */
    uint32_t                reserved;
    PAE_PortCfgType         portCfg;    /**< @brief Input: Port Config          */
    PAE_KayCfgType          kayCfg;     /**< @brief Input: Kay Config           */
} PAE_PortCfgMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_PortCfgMsgType, 80UL, PAE_MSG_MAX_SIZE);

/**
    @brief PN Exhaustion message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_PnExhaustionMsgType {
    uint64_t                pnExhaustionNum; /**< @brief Input: PN Exhaustion Number */
    PAE_PortNumberType      portNum;         /**< @brief Input: Port Number          */
    uint32_t                reserved[5UL];
} PAE_PnExhaustionMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_PnExhaustionMsgType, 32UL, PAE_MSG_MAX_SIZE);

/**
    @brief Port init message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_PortInitMsgType {
    PAE_PortNumberType      portNum;    /**< @brief Input: Port Number          */
    uint32_t                reserved[7UL];
} PAE_PortInitMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_PortInitMsgType, 32UL, PAE_MSG_MAX_SIZE);

/**
    @brief MKA Participant configuration message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_MkaPartCfgMsgType {
    uint32_t                index;  /**< @brief Input: MKA Participant Index    */
    uint32_t                reserved0;
    PAE_MkaPartCfgType      cfg;    /**< @brief Input: MKA Participant Config   */
} PAE_MkaPartCfgMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_MkaPartCfgMsgType, 56UL, PAE_MSG_MAX_SIZE);

/**
    @brief Port status message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_PortStatusMsgType {
    PAE_PortNumberType      portNum;    /**< @brief Input: Port Number          */
    uint32_t                reserved;
    PAE_PortStatusType      portStatus; /**< @brief Output: Port Status         */
    PAE_KayStatusType       kayStatus;  /**< @brief Output: Kay Status          */
} PAE_PortStatusMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_PortStatusMsgType, 200UL, PAE_MSG_MAX_SIZE);

/**
    @brief MKA Participant status message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_MkaPartStatusMsgType {
    PAE_PortNumberType      portNum;    /**< @brief Input: Port Number          */
    uint32_t                mkaPartIdx; /**< @brief Input: MKA Participant Index*/
    uint32_t                cknLen;     /**< @brief Output: CKN Length          */
    uint32_t                numPeers;   /**< @brief Output: Number of vaid peers*/
    uint8_t                 ckn[PAE_CKN_MAX_LEN];/**< @brief Output: CAK Name   */
    PAE_MkaPartStatusType   status;     /**< @brief Output: MKA Participant status*/
    PAE_MkaPeerEntryType    peers[PAE_MAX_MKA_PEERS];/**< @brief Output: Peers  */
    uint32_t                reserved[2UL];
} PAE_MkaPartStatusMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_MkaPartStatusMsgType, 168UL, PAE_MSG_MAX_SIZE);

/**
    @brief MKA Participant status message

    @trace #BRCM_SWREQ_PAE
*/
typedef struct sPAE_PortSessionStatsMsgType {
    PAE_PortNumberType          portNum;    /**< @brief Input: Port Number          */
    uint32_t                    reserved;
    PAE_PortSessionStatsType    stats;      /**< @brief Output: Statistics for current
                                            or last session */
} PAE_PortSessionStatsMsgType;
BCM_STATIC_SIZE_ASSERT(PAE_PortSessionStatsMsgType, 328UL, PAE_MSG_MAX_SIZE);

#endif /* ETHERNET_PAE_TYPES_H */

/** @} */
