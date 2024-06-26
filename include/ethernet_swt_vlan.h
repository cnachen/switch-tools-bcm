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

 2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
    AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
    WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
    TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND ALL IMPLIED
    WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A
    PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS,
    QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION.
    YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR PERFORMANCE OF THE
    SOFTWARE.

 3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR ITS
    LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL, INDIRECT,
    OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY WAY RELATING TO
    YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS
    OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR U.S. $1, WHICHEVER
    IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING ANY FAILURE OF
    ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
******************************************************************************/

/**
    @defgroup grp_ethernet_swt_vlan_ifc Switch VLAN abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_vlan_ifc
    @{

    @file ethswtm_abs_vlan.h

    @brief Ethernet Service: VLAN Interface
    This file contains the interfaces for the Ethernet abstract for VLAN

    @version 1.0 Initial version
*/

#ifndef ETHERNET_SWT_VLAN_H
#define ETHERNET_SWT_VLAN_H

#include <ethernet_common.h>
#include <ethernet_swt_common.h>

/**
    @name VLAN API IDs
    @{
    @brief API IDs for VLAN
*/
#define BRCM_SWARCH_ETHSWT_VLAN_MAX_PAYLOAD_SIZE_MACRO  (0x8101U) /**< @brief #ETHSWT_VLAN_MAX_PAYLOAD_SIZE  */
#define BRCM_SWARCH_ETHSWT_VLANCMDID_TYPE               (0x8102U) /**< @brief #ETHSWT_VLANCmdIdType          */
#define BRCM_SWARCH_ETHSWT_VLANPORT_TYPE                (0x8103U) /**< @brief #ETHSWT_VLANPortType           */
#define BRCM_SWARCH_ETHSWT_VLANMSGUNION_TYPE            (0x8104U) /**< @brief #ETHSWT_VLANMsgUnionType       */
#define BRCM_SWARCH_ETHSWT_VLAN_ID_OF_MACRO             (0x8105U) /**< @brief #ETHSWT_VLAN_ID_OF             */
#define BRCM_SWARCH_ETHSWT_VLANPORTV2_TYPE              (0x8106U) /**< @brief #ETHSWT_VLANPortV2Type         */
#define BRCM_SWARCH_ETHSWT_VLANGET_PROC                 (0x8107U) /**< @brief #ETHSWT_VLANGet                */
#define BRCM_SWARCH_ETHSWT_VLANADD_PROC                 (0x8108U) /**< @brief #ETHSWT_VLANAdd                */
#define BRCM_SWARCH_ETHSWT_VLANREMOVE_PROC              (0x8109U) /**< @brief #ETHSWT_VLANRemove             */
#define BRCM_SWARCH_ETHSWT_VLAN_MAX_BYTES_AS_MASK_MACRO (0x810AU) /**< @brief #ETHSWT_VLAN_MAX_BYTES_AS_MASK */
#define BRCM_SWARCH_ETHSWT_VLAN_LIST_TYPE               (0x810BU) /**< @brief #ETHSWT_VLANListType           */
#define BRCM_SWARCH_ETHSWT_VLAN_LISTMSG_TYPE            (0x810CU) /**< @brief #ETHSWT_VLANListMsgType        */
#define BRCM_SWARCH_ETHSWT_VLANGETPERPORT_PROC          (0x810DU) /**< @brief #ETHSWT_VLANGetPerPort         */

#define BRCM_SWARCH_ETHSWT_VLAN_FRWRD_TYPE              (0x8140U) /**< @brief #ETHSWT_VLANFwrdType      */
#define BRCM_SWARCH_ETHSWT_VLAN_MEM_CFG_TYPE            (0x8141U) /**< @brief #ETHSWT_VLANMemberCfgType */

#define BRCM_SWARCH_ETHSWT_VLAN_MAX_ENTRIES_MACRO       (0x8180U) /**< @brief #ETHSWT_VLAN_MAX_ENTRIES    */
#define BRCM_SWARCH_ETHSWT_VLANENTRYV1_TYPE             (0x8181U) /**< @brief #ETHSWT_VLANEntryV1Type     */
#define BRCM_SWARCH_ETHSWT_VLANCONFIGV1_TYPE            (0x8182U) /**< @brief #ETHSWT_VLANConfigV1Type    */
#define BRCM_SWARCH_ETHSWT_VLANENTRYV2_TYPE             (0x8183U) /**< @brief #ETHSWT_VLANEntryV2Type     */
#define BRCM_SWARCH_ETHSWT_VLANCONFIGV2_TYPE            (0x8184U) /**< @brief #ETHSWT_VLANConfigV2Type    */
/** @} */

/**
    @brief Maximum size of VLAN command payload in bytes

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_VLAN_MAX_PAYLOAD_SIZE   (448UL)

/**
    @brief Maximum bytes of VLAN Mask

    This Macro defines the maximum number of bytes
    that can hold VLAN Mask in one message

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_VLAN_MAX_BYTES_AS_MASK    (192U)

/**
    @brief Macro to Construct Ethernet switch Ext Commands

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_VLAN_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_VLN_ID, aId)

/**
    @name Switch VLAN command IDs
    @{
    @brief Switch VLAN command IDs group

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_VLANCmdIdType;                                     /**< @brief VLAN command message Type                          */
#define ETHSWT_VLANCMDID_GET            ETHSWT_VLAN_ID_OF(0x60U)          /**< @brief #ETHSWT_VLANPortType       #ETHSWT_GetVLANPorts    */
#define ETHSWT_VLANCMDID_PORT_ADD       ETHSWT_VLAN_ID_OF(0x61U)          /**< @brief #ETHSWT_VLANPortType       #ETHSWT_AddVLANPorts    */
#define ETHSWT_VLANCMDID_PORT_REMOVE    ETHSWT_VLAN_ID_OF(0x62U)          /**< @brief #ETHSWT_VLANPortType       #ETHSWT_RemoveVLANPorts */
#define ETHSWT_VLANCMDID_GET_V2         ETHSWT_VLAN_ID_OF(0x63U)          /**< @brief #ETHSWT_VLANPortV2Type     #ETHSWT_GetVLANPorts    */
#define ETHSWT_VLANCMDID_PORT_ADD_V2    ETHSWT_VLAN_ID_OF(0x64U)          /**< @brief #ETHSWT_VLANPortV2Type     #ETHSWT_AddVLANPorts    */
#define ETHSWT_VLANCMDID_PORT_REMOVE_V2 ETHSWT_VLAN_ID_OF(0x65U)          /**< @brief #ETHSWT_VLANPortV2Type     #ETHSWT_RemoveVLANPorts */
#define ETHSWT_VLANCMDID_GET_PORT_VLAN  ETHSWT_VLAN_ID_OF(0x66U)          /**< @brief #ETHSWT_VLANListMsgType  #ETHSWT_GetVLANPorts    */
/** @} */

/**
    @name VLAN forwarding type
    @{
    @brief VLAN forwarding type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_VLANFwrdType;    /**< @brief VLAN forwarding type */
#define ETHSWT_VLAN_FRWRD_DONT_SEND   (0U) /**< @brief Don't send on this port */
#define ETHSWT_VLAN_FRWRD_TAGGED      (1U) /**< @brief Send tagged packets at this port */
#define ETHSWT_VLAN_FRWRD_UNTAGGED    (2U) /**< @brief Send untagged packets at this port */
/** @} */

/**
    @brief VLAN membership configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_VLANMemberCfgType {
    ETHER_VLANIDType   vlanID;     /**< @brief VLAN ID. Membership of this port
                                             on this virtual network, frames with
                                             this VLAN ID shall be transmitted and
                                             received over this port. */
    uint16_t           macAddrList;/**< @brief Bit mask for participating MAC
                                              addresses in the VLAN. If the nth bit
                                              is set, then nth MAC address in
                                              ETHSWT_PortCfgType::fixedMacAddrList
                                              participates in this VLAN. */
    ETHSWT_PCPType      defaultPri; /**< @brief Default priority for outgoing
                                              packets. Range 0 â€“ 7. */
    ETHSWT_VLANFwrdType forward;    /**< @brief Packet forwarding type. */
} ETHSWT_VLANMemberCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANMemberCfgType, 6UL, ETHSWT_VLAN_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage VLAN

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_VLANPortType {
    ETHER_VLANIDType    vlan;           /**< @brief VLAN ID */
    uint16_t            rsv0;           /**< @brief Reserved */
    uint32_t            portMask;       /**< @brief Port mask */
    uint32_t            tagMask;        /**< @brief Tagged port mask */
    uint32_t            staticPortMask; /**< @brief Static port mask */
    uint32_t            rsv1[4U];       /**< @brief Reserved */
} ETHSWT_VLANPortType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANPortType, 32UL, ETHSWT_VLAN_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage VLAN

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_VLANPortV2Type {
    ETHER_VLANIDType    vlan;           /**< @brief VLAN ID */
    uint16_t            rsv0;           /**< @brief Reserved */
    ETHSWT_PortMaskType portMask;       /**< @brief Port mask */
    ETHSWT_PortMaskType tagMask;        /**< @brief Tagged port mask */
    ETHSWT_PortMaskType staticPortMask; /**< @brief Static port mask */
} ETHSWT_VLANPortV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANPortV2Type, 32UL, ETHSWT_VLAN_MAX_PAYLOAD_SIZE)

/**
    @brief Structure of vlan ID and tag Mask
    This structure hold the VLAN ID as mask and corresponding tag information
    Each bit vlanMask represents participation of VLAN for the port.
    The corresponding bit in the tag mask will say if the packets are tagged or un-tagged.
    The tagged mask 0:untagged 1: tagged

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_VLANListType {
    uint8_t             vlanMask[ETHSWT_VLAN_MAX_BYTES_AS_MASK];    /**< @brief output: VLAN ID's as Mask */
    uint8_t             tagMask[ETHSWT_VLAN_MAX_BYTES_AS_MASK];     /**< @brief output: VLAN Tag's as Mask */
} ETHSWT_VLANListType;

/**
    @brief Structure to retrieve list of VLAN's of a port

    Structure to retrieve the VLANID's and tagged information of a given Port.
    The VLAN search starts from nextVlan.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_VLANListMsgType {
    ETHSWT_PortIDType     port;           /**< @brief Input : Switch Port Index              */
    ETHSWT_VLANIDType     nextVlan;       /**< @brief Input : starting ID of VLAN            */
    uint16_t              rsvd1;
    uint32_t              rsvd[14UL];
    ETHSWT_VLANListType vlanList; /**< @brief output : VLAN ID and Tag information by Mask.*/
} ETHSWT_VLANListMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANListMsgType, ETHSWT_VLAN_MAX_PAYLOAD_SIZE, ETHSWT_VLAN_MAX_PAYLOAD_SIZE)

/**
    @brief Vlan Union encapsulating all messages

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef union uETHSWT_VLANMsgUnionType {
    uint32_t                   data[ETHSWT_VLAN_MAX_PAYLOAD_SIZE/4UL]; /**< @brief Max Payload size */
    ETHSWT_VLANPortType        vlanPort;      /**< @brief VLAN Payload */
    ETHSWT_VLANPortV2Type      vlanPortV2;    /**< @brief VLAN Payload */
    ETHSWT_VLANListMsgType   portVlanList;  /**< @brief VLAN Port list Payload */
} ETHSWT_VLANMsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANMsgUnionType, ETHSWT_VLAN_MAX_PAYLOAD_SIZE, ETHSWT_VLAN_MAX_PAYLOAD_SIZE)

/**
    @brief Maximum number of VLANS supported by Ethernet Service

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_VLAN_MAX_ENTRIES                       (512UL)

/**
    @brief VLAN entry

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_VLANEntryV1Type {
    uint16_t vlan;      /**< @brief VLAN Identifier */
    uint16_t portMask;  /**< @brief Bitmap of participating ports */
    uint16_t tagMask;   /**< @brief Bitmap of participating ports
                                      where egress packets are tagged */
} ETHSWT_VLANEntryV1Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANEntryV1Type, 6UL, ETHSWT_VLAN_MAX_PAYLOAD_SIZE)

/**
    @brief VLAN Configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_VLANConfigV1Type {
    ETHSWT_VLANEntryV1Type       vidTable[ETHSWT_VLAN_MAX_ENTRIES];
                                                               /**< @brief VLAN table */
    uint32_t                      vidTblSz;                /**< @brief Number of entries in VLAN table */
} ETHSWT_VLANConfigV1Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANConfigV1Type, 3076UL, 3076UL)

/**
    @brief VLAN V2 entry

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_VLANEntryV2Type {
    ETHSWT_VLANIDType    vlan;      /**< @brief VLAN Identifier */
    ETHSWT_PortMaskType  portMask;  /**< @brief Bitmap of participating ports */
    ETHSWT_PortMaskType  tagMask;   /**< @brief Bitmap of participating ports
                                          where egress packets are tagged */
} ETHSWT_VLANEntryV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANEntryV2Type, 18UL, ETHSWT_VLAN_MAX_PAYLOAD_SIZE)

/**
    @brief VLAN V2 Configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_VLANConfigV2Type {
    ETHSWT_VLANEntryV2Type       vidTable[ETHSWT_VLAN_MAX_ENTRIES];
                                                               /**< @brief VLAN table */
    uint32_t                      vidTblSz;                /**< @brief Number of entries in VLAN table */
} ETHSWT_VLANConfigV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_VLANConfigV2Type, 9220UL, 9220UL)


/** @brief Get ports participating in a VLAN

    This API retrieves port mask of the ports participating in a given
    VLAN.

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aVlanID         VLAN ID
    @param[out]     aVlanPortInfo   VLAN Port Information

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieving ports
                                        participating in VLAN.
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aVlanPortInfo is NULL) or
                                        (Invalid VLAN identifier)
    @retval     #BCM_ERR_NOSUPPORT      Operation is Not Supported

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_VLANGet (BCM_HandleType aHdl,
                                 ETHER_VLANIDType aVlanID,
                                 ETHSWT_VLANPortV2Type *aVlanPortInfo);


/** @brief Add ports to VLAN

    This API adds given ports to a VLAN in tagged or untagged mode.

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aPortMask       Port mask
    @param[in]      aVlanID         VLAN ID
    @param[in]      aTaggedMask     Tagged mask

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully added port to VLAN
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid VLAN identifier) or
                                        (Invalid port mask) or
                                        (Invalid Tagged mode mask)
    @retval     #BCM_ERR_NOSUPPORT      Operation is Not Supported

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_VLANAdd (BCM_HandleType aHdl,
                                 ETHER_VLANIDType aVlanID,
                                 ETHSWT_PortMaskType aPortMask,
                                 ETHSWT_PortMaskType aTaggedMask);

/** @brief Remove dynamically added ports from VLAN

    This API remove dynamically added ports from a VLAN, according to the port
    mask parameter.

    @behavior Sync, Re-entrant

    @note This API would not remove static entries(Ports/VLAN) from VLAN table.

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aPortMask       Port mask
    @param[in]      aVlanID         VLAN ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully removed port from VLAN
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_NOPERM         Deletion of port/s which is/are part of static
                                        VLAN during initialization
    @retval     #BCM_ERR_INVAL_PARAMS   (Deletion of port/s which is/are not part of VLAN) or
                                        (Invalid VLAN identifier) or
                                        (Invalid port mask (zero))
    @retval     #BCM_ERR_NOSUPPORT      Operation is Not Supported

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_VLANRemove(BCM_HandleType aHdl,
                                   ETHER_VLANIDType aVlanID,
                                   ETHSWT_PortMaskType aPortMask);

/** @brief Retrieve the list of VLAN's of a Port

    This API search and retrieves the list of all VLAN's of a given port.
    On each call it can return upto (ETHSWT_VLAN_MAX_BYTES_AS_MASK * 8) VLAN ID and
    corresponding tagged information as Mask.
    Each bit represents participation of VLAN for the port.
    The VLAN ID for the port can be computed as VLAN ID = nextVlan + ((byteindex * 8) + bitindex).
    Here for byteindex range is  [0 - (ETHSWT_VLAN_MAX_BYTES_AS_MASK-1)] bytes.
    And bit index for each byte as  bit 0 is MSB and bit 7 is LSB.
    VLAN ID is valid only when the bit is set i.e (aVlanList.vlanMask[byteindex] & (1U << bitindex)) is Not '0'.
    The corresponding bit in the tag mask will say if the packets are tagged or un-tagged.
    The tagged mask 0:untagged 1: tagged

    Example:
    if aVlanList.vlanList.vlanMask[0] is 0x54, aVlanList.vlanList.tagMask[0] is 0x10
    AND aVlanList.nextVlan is 0 then
    VLAN ID = 0 + ((0 * 8) + bitindex). Iterate through 0-7 of bitindex.
    Mask is set to bit 2, bit 4 and bit 6 in aVlanList.vlanList.vlanMask[0]
    Mask is set to bit 4 in aVlanList.vlanList.tagMask[0].
    So, the port is participating in VLANs 2,4,6 and VLAN 2,6 are Untagged and VLAN 4 is tagged.

    Multiple invocations of this API is expected till the list of ETHSWT_VLANID_MAX is received.
    While invoking, aNextVlan can be set to ( previous aVlanList.vlanList.nextVlan + (ETHSWT_VLAN_MAX_BYTES_AS_MASK * 8))

    ex1:
        If the first request is made as aVlanList.vlanList.nextVlan = 0 then it can return (ETHSWT_VLAN_MAX_BYTES_AS_MASK * 8) VLAN ID's as mask.
        the second request should be aVlanList.vlanList.nextVlan = 0 + (ETHSWT_VLAN_MAX_BYTES_AS_MASK * 8)* invocation count(1)
        the third request should be aVlanList.vlanList.nextVlan = 0 + (ETHSWT_VLAN_MAX_BYTES_AS_MASK * 8)* invocation count(2)
        till aVlanList.vlanList.nextVlan <= ETHSWT_VLANID_MAX

    ex2:
        If the first request is made as aVlanList.vlanList.nextVlan = 300 then it can return (ETHSWT_VLAN_MAX_BYTES_AS_MASK * 8) VLAN ID's as mask.
        the second request should be aVlanList.vlanList.nextVlan = (300 + (ETHSWT_VLAN_MAX_BYTES_AS_MASK * 8)* 1)
        the third request should be aVlanList.vlanList.nextVlan = (300+ (ETHSWT_VLAN_MAX_BYTES_AS_MASK * 8)* 2)
        till aVlanList.vlanList.nextVlan <= ETHSWT_VLANID_MAX

    ex3:
        If the first request is made as aVlanList.vlanList.nextVlan = 4092 then it can return 3 VLAN ID's as mask.
        As it received the ETHSWT_VLANID_MAX no more calls required.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aPort           Port number for which the VLAN's to be fetched
    @param[in]      aNextVlan       Starting ID of VLAN from where the search to be started
    @param[out]     aVlanList       List of fetched VLAN's.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully fetched list of VLAN and TagMask
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   aVlanList is NULL
                #BCM_ERR_INVAL_PARAMS   Invalid aPort
                #BCM_ERR_INVAL_PARAMS   Invalid aNextVlan
    @retval     #BCM_ERR_NOSUPPORT      Operation is Not Supported

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_VLANGetPerPort(BCM_HandleType aHdl,
                                           ETHSWT_PortIDType aPort,
                                           ETHSWT_VLANIDType  aNextVlan,
                                           ETHSWT_VLANListType *const aVlanList);
#endif /* ETHERNET_SWT_VLAN_H */

/** @} */
