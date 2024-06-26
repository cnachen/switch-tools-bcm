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
    @defgroup grp_ethernet_l3fw_ifc L3 Forwarding abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_l3fw_ifc
    @{

    @file ethernet_swt_l3.h

    @brief L3 Forwarding Interface
    This file contains the interfaces for the L3 Forwarding feature

    @version 1.0 Initial version
*/

#ifndef ETHERNET_L3FW_H
#define ETHERNET_L3FW_H

#include <bcm_utils.h>
#include <bcm_comp.h>
#include <ethernet_common.h>

/**
    @name Ethernet L3 Forwarding API IDs
    @{
    @brief API IDs for L3 Forwarding
*/
#define BRCM_SWARCH_L3FW_CFG_MAGIC_MACRO                        (0x8D00U) /**< @brief #L3FW_CFG_MAGIC                 */
#define BRCM_SWARCH_L3FW_MAX_MSG_SIZE_MACRO                     (0x8D01U) /**< @brief #L3FW_MAX_MSG_SIZE              */
#define BRCM_SWARCH_L3FW_MAX_CFG_MACRO                          (0x8D02U) /**< @brief #L3FW_MAX_CFG_INTERFACE         */
#define BRCM_SWARCH_L3FW_MSG_ID_OF_MACRO                        (0x8D03U) /**< @brief #L3FW_MSG_ID_OF                 */
#define BRCM_SWARCH_L3FW_MSG_ID_TYPE                            (0x8D04U) /**< @brief #L3FW_MsgIdType                 */
#define BRCM_SWARCH_L3FW_UNICAST_ROUTE_ID_TYPE                  (0x8D05U) /**< @brief #L3FW_UnicastRouteIdType        */
#define BRCM_SWARCH_L3FW_INTERFACE_ID_TYPE                      (0x8D06U) /**< @brief #L3FW_InterfaceIdType           */
#define BRCM_SWARCH_L3FW_HANDLE_TYPE                            (0x8D07U) /**< @brief #L3FW_HandleType                */
#define BRCM_SWARCH_L3FW_PKT_DIR_TYPE                           (0x8D08U) /**< @brief #L3FW_PktDirType                */
#define BRCM_SWARCH_L3FW_L4PROTO_TYPE                           (0x8D09U) /**< @brief #L3FW_L4ProtoType               */
#define BRCM_SWARCH_L3FW_VLAN_PCP_TYPE                          (0x8D0AU) /**< @brief #L3FW_VlanPCPType               */
#define BRCM_SWARCH_L3FW_L4PORT_NUM_TYPE                        (0x8D0BU) /**< @brief #L3FW_L4PortNumType             */
#define BRCM_SWARCH_L3FW_NAPTMATCH_TYPE                         (0x8D0CU) /**< @brief #L3FW_NAPTMatchType             */
#define BRCM_SWARCH_L3FW_NAPTREMAP_DATA_TYPE                    (0x8D0DU) /**< @brief #L3FW_NAPTRemapDataType         */
#define BRCM_SWARCH_L3FW_NAPTROUTE_CFG_TYPE                     (0x8D0EU) /**< @brief #L3FW_NAPTRouteCfgType          */
#define BRCM_SWARCH_L3FW_NAPTROUTE_STATS_TYPE                   (0x8D0FU) /**< @brief #L3FW_NAPTRouteStatsType        */
#define BRCM_SWARCH_L3FW_NAPTROUTE_MSG_TYPE                     (0x8D10U) /**< @brief #L3FW_NAPTRouteMsgType          */
#define BRCM_SWARCH_L3FW_NAPTROUTE_STATS_MSG_TYPE               (0x8D11U) /**< @brief #L3FW_NAPTRouteStatsMsgType     */
#define BRCM_SWARCH_L3FW_INTERFACE_CFG_TYPE                     (0x8D12U) /**< @brief #L3FW_InterfaceCfgType          */
#define BRCM_SWARCH_L3FW_UNICAST_ROUTE_CFG_TYPE                 (0x8D13U) /**< @brief #L3FW_UnicastRouteCfgType       */
#define BRCM_SWARCH_L3FW_MULTICAST_CFG_TYPE                     (0x8D14U) /**< @brief #L3FW_MulticastCfgType          */
#define BRCM_SWARCH_L3FW_CFG_TYPE                               (0x8D15U) /**< @brief #L3FW_CfgType                   */
#define BRCM_SWARCH_L3FW_INTERFACE_MSG_TYPE                     (0x8D17U) /**< @brief #L3FW_InterfaceMsgType          */
#define BRCM_SWARCH_L3FW_UNICAST_ROUTE_MSG_TYPE                 (0x8D18U) /**< @brief #L3FW_UnicastRouteMsgType       */
#define BRCM_SWARCH_L3FW_MULTICAST_GRP_MSG_TYPE                 (0x8D19U) /**< @brief #L3FW_MulticastGrpMsgType       */
#define BRCM_SWARCH_L3FW_MULTICAST_IFC_MSG_TYPE                 (0x8D1AU) /**< @brief #L3FW_MulticastIfcMsgType       */
#define BRCM_SWARCH_L3FW_MULTICAST_L2MSG_TYPE                   (0x8D1BU) /**< @brief #L3FW_MulticastL2MsgType        */
#define BRCM_SWARCH_L3FW_MSG_UNION_TYPE                         (0x8D1CU) /**< @brief #L3FW_MsgUnionType              */
#define BRCM_SWARCH_L3FW_ADD_INTERFACE_PROC                     (0x8D1DU) /**< @brief #L3FW_AddInterface              */
#define BRCM_SWARCH_L3FW_REMOVE_INTERFACE_PROC                  (0x8D1EU) /**< @brief #L3FW_RemoveInterface           */
#define BRCM_SWARCH_L3FW_ADD_UNICAST_ROUTE_PROC                 (0x8D1FU) /**< @brief #L3FW_AddUnicastRoute           */
#define BRCM_SWARCH_L3FW_REMOVE_UNICAST_ROUTE_PROC              (0x8D20U) /**< @brief #L3FW_RemoveUnicastRoute        */
#define BRCM_SWARCH_L3FW_GET_UNICAST_ROUTE_HDL_PROC             (0x8D21U) /**< @brief #L3FW_GetUnicastRouteHdl        */
#define BRCM_SWARCH_L3FW_ADD_MULTICAST_GRP_PROC                 (0x8D22U) /**< @brief #L3FW_AddMulticastGrp           */
#define BRCM_SWARCH_L3FW_REMOVE_MULTICAST_GRP_PROC              (0x8D23U) /**< @brief #L3FW_RemoveMulticastGrp        */
#define BRCM_SWARCH_L3FW_ADD_MULTICAST_IFC_PROC                 (0x8D24U) /**< @brief #L3FW_AddMulticastIfc           */
#define BRCM_SWARCH_L3FW_REMOVE_MULTICAST_IFC_PROC              (0x8D25U) /**< @brief #L3FW_RemoveMulticastIfc        */
#define BRCM_SWARCH_L3FW_SET_MULTICAST_L2PORTS_PROC             (0x8D26U) /**< @brief #L3FW_SetMulticastL2Ports       */
#define BRCM_SWARCH_L3FW_ADD_NAPTROUTE_PROC                     (0x8D27U) /**< @brief #L3FW_AddNAPTRoute              */
#define BRCM_SWARCH_L3FW_REMOVE_NAPTROUTE_PROC                  (0x8D28U) /**< @brief #L3FW_RemoveNAPTRoute           */
#define BRCM_SWARCH_L3FW_GET_NAPTROUTE_STATS_PROC               (0x8D29U) /**< @brief #L3FW_GetNAPTRouteStats         */
#define BRCM_SWARCH_L3FW_GET_NAPTSTATS_PROC                     (0x8D2AU) /**< @brief #L3FW_GetNAPTStats              */
#define BRCM_SWARCH_L3FW_UNICAST_HANDLE_MSG_TYPE                (0x8D2BU) /**< @brief #L3FW_UnicastHandleMsgType      */
#define BRCM_SWARCH_L3FW_INTERFACE_TYPE_TYPE                    (0x8D2CU) /**< @brief #L3FW_InterfaceTypeType         */
#define BRCM_SWARCH_L3FW_GET_INTERFACE_PROC                     (0x8D2DU) /**< @brief #L3FW_GetInterface              */
#define BRCM_SWARCH_L3FW_GET_NAPTROUTE_PROC                     (0x8D2EU) /**< @brief #L3FW_GetNAPTRoute              */
#define BRCM_SWARCH_L3FW_GET_UNICASTROUTE_PROC                  (0x8D2FU) /**< @brief #L3FW_GetUnicastRoute           */
#define BRCM_SWARCH_L3FW_STATTICIFC_LIST_TYPE                   (0x8D30U) /**< @brief #L3FW_StaticIfcListType       */
#define BRCM_SWARCH_L3FW_STATICROUTEHANDLES_LIST_TYPE           (0x8D31U) /**< @brief #L3FW_RouteHandleListType    */
#define BRCM_SWARCH_L3FW_GET_STATIC_IFC_PROC                    (0x8D32U) /**< @brief #L3FW_GetIfcStaticIds           */
#define BRCM_SWARCH_L3FW_GET_UNICAST_ST_HDLS_PROC               (0x8D33U) /**< @brief #L3FW_GetUnicastStaticHdls      */
#define BRCM_SWARCH_L3FW_GET_NAPT_ST_HDLS_PROC                  (0x8D34U) /**< @brief #L3FW_GetNaptStaticHdls         */
/** @} */

/**
    @brief Magic number for L3Forwarding configuration

    @trace #BRCM_SWREQ_L3FW
*/
#define L3FW_CFG_MAGIC           BCM_PACK32('L', '3', 'F', '0')

/**
    @brief Maximum size of L3FW messages

    @trace #BRCM_SWREQ_L3FW
*/
#define L3FW_MAX_MSG_SIZE        (440UL)

/**
    @name Maximum static config entries

    @{
    @brief Max number of config entires

    @trace #BRCM_SWREQ_L3FW
*/
#define L3FW_MAX_CFG_INTERFACE   (24UL) /**< @brief Max number of interface configs */
#define L3FW_MAX_CFG_UNICAST     (48UL) /**< @brief Max number of unicast routes */
#define L3FW_MAX_CFG_MULTICAST   (48UL) /**< @brief Max number of multicast routes */
#define L3FW_MAX_CFG_NAPT        (96UL) /**< @brief Max number of NAPT routes */
/** @} */

/**
    @brief Macro to Construct Message ID for L3Forward

    @trace #BRCM_SWREQ_L3FW
*/
#define L3FW_MSG_ID_OF(aId)     BCM_MSG(BCM_GROUPID_ETHSRV, BCM_L3FWMOD_ID, aId)

/**
    @name CRYPTO SecY Message IDs
    @{
    @brief Message IDs for exchange on message queues

    @trace #BRCM_SWREQ_L3FW
*/
typedef uint32_t L3FW_MsgIdType;                               /**< @brief L3Forward message Type       */
#define L3FW_MSG_ID_ADD_INTERFACE       L3FW_MSG_ID_OF(0x01UL) /**< @brief #L3FW_InterfaceMsgType       */
#define L3FW_MSG_ID_REM_INTERFACE       L3FW_MSG_ID_OF(0x02UL) /**< @brief #L3FW_InterfaceIdType        */
#define L3FW_MSG_ID_ADD_UNICAST_ROUTE   L3FW_MSG_ID_OF(0x03UL) /**< @brief #L3FW_UnicastRouteMsgType    */
#define L3FW_MSG_ID_REM_UNICAST_ROUTE   L3FW_MSG_ID_OF(0x04UL) /**< @brief #L3FW_HandleType             */
#define L3FW_MSG_ID_GET_UNICAST_HDL     L3FW_MSG_ID_OF(0x05UL) /**< @brief #L3FW_UnicastHandleMsgType   */
#define L3FW_MSG_ID_ADD_MULTICAST_GRP   L3FW_MSG_ID_OF(0x06UL) /**< @brief #L3FW_MulticastGrpMsgType    */
#define L3FW_MSG_ID_REM_MULTICAST_GRP   L3FW_MSG_ID_OF(0x07UL) /**< @brief #L3FW_HandleType             */
#define L3FW_MSG_ID_ADD_MULTICAST_IFC   L3FW_MSG_ID_OF(0x08UL) /**< @brief #L3FW_MulticastIfcMsgType    */
#define L3FW_MSG_ID_REM_MULTICAST_IFC   L3FW_MSG_ID_OF(0x09UL) /**< @brief #L3FW_MulticastIfcMsgType    */
#define L3FW_MSG_ID_SET_MULTICAST_L2    L3FW_MSG_ID_OF(0x0AUL) /**< @brief #L3FW_MulticastL2MsgType     */
#define L3FW_MSG_ID_GET_UNICAST_ROUTE   L3FW_MSG_ID_OF(0x0BUL) /**< @brief #L3FW_UnicastRouteMsgType    */
#define L3FW_MSG_ID_GET_STATIC_IFC      L3FW_MSG_ID_OF(0x10UL) /**< @brief #L3FW_StaticIfcListType      */
#define L3FW_MSG_ID_GET_UC_HDL_LIST     L3FW_MSG_ID_OF(0x11UL) /**< @brief #L3FW_RouteHandleListType    */
#define L3FW_MSG_ID_GET_NAPT_HDL_LIST   L3FW_MSG_ID_OF(0x12UL) /**< @brief #L3FW_RouteHandleListType    */
#define L3FW_MSG_ID_ADD_NAPT_ROUTE      L3FW_MSG_ID_OF(0x20UL) /**< @brief #L3FW_NAPTRouteMsgType       */
#define L3FW_MSG_ID_REM_NAPT_ROUTE      L3FW_MSG_ID_OF(0x21UL) /**< @brief #L3FW_HandleType             */
#define L3FW_MSG_ID_GET_NAPT_STATS      L3FW_MSG_ID_OF(0x22UL) /**< @brief #L3FW_NAPTRouteStatsMsgType  */
#define L3FW_MSG_ID_GET_NAPT_GLOB_STATS L3FW_MSG_ID_OF(0x23UL) /**< @brief #L3FW_NAPTRouteStatsMsgType  */
#define L3FW_MSG_ID_GET_INTERFACE       L3FW_MSG_ID_OF(0x24UL) /**< @brief #L3FW_InterfaceMsgType       */
#define L3FW_MSG_ID_GET_NAPT_ROUTE      L3FW_MSG_ID_OF(0x25UL) /**< @brief #L3FW_NAPTRouteMsgType       */
/** @} */

/**
    @brief Unicast Route Id type
    A running number.
    Lower number has higher priority in matching.
    IPV4 rules, and IPV6 rules use independent indices. <BR>
    For IPV4 :
    0 to #L3FW_MAX_UNICAST_ROUTES-1-maxIpV6UnicastRoutes*4UL <BR>
    For IPV6 :
    0 to maxIpV6UnicastRoutes - 1

    @trace #BRCM_SWREQ_L3FW
*/
typedef uint16_t L3FW_UnicastRouteIdType;   /**< brief Input: Unicast route index */

/**
    @brief Interface ID Type
    A running number from 0 to #L3FW_MAX_CFG_INTERFACE-1

    @trace #BRCM_SWREQ_L3FW
*/
typedef uint16_t L3FW_InterfaceIdType;      /**< brief Input: Interface id */

/**
    @brief L3FW handle type

    @trace #BRCM_SWREQ_L3FW
*/
typedef BCM_HandleType L3FW_HandleType;     /**< brief Input/Output: Interface handle,
                                                     Multicast group handle */

/**
    @name Packet direction

    @brief Packet direction type and enum

    @trace #BRCM_SWREQ_L3FW
    @{
*/
typedef uint8_t L3FW_PktDirType;
#define L3FW_PKT_DIR_INBOUND     (0x00U)    /**< @brief Inbound Packet */
#define L3FW_PKT_DIR_OUTBOUND    (0x01U)    /**< @brief Outbound Packet */
/** @} */

/**
    @name L4 Protocol type

    @brief Flags pertaining to the packet type

    @trace #BRCM_SWREQ_L3FW
    @{
*/
typedef uint8_t L3FW_L4ProtoType;
#define L3FW_L4PROTO_NONE    (0x00U)    /**< @brief TCP */
#define L3FW_L4PROTO_TCP     (0x01U)    /**< @brief TCP */
#define L3FW_L4PROTO_UDP     (0x02U)    /**< @brief UDP */
/** @} */

/**
    @name PCP field values

    @brief PCP field value of VLAN TAG

    @trace #BRCM_SWREQ_L3FW
    @{
*/
typedef uint8_t L3FW_VlanPCPType;        /**< @brief @xsd input:int        */
#define L3FW_VLAN_PCP_MAX     (0x07U)    /**< @brief PCP value max         */
#define L3FW_VLAN_PCP_NONE    (0x80U)    /**< @brief Skip PCP value update */
/** @} */

/**
    @name L4 Port number
    @{
    @brief L4 Port number type and enums

    @trace #BRCM_SWREQ_L3FW
*/
typedef uint16_t L3FW_L4PortNumType;       /**< @brief @xsd input:int  */
#define L3FW_L4PORT_NUM_NONE    (0x00U)    /**< @brief Port number not specified */
/** @} */

/**
    @name L3 Interface type
    @{
    @brief L4 Port number type and enums

    @trace #BRCM_SWREQ_L3FW
*/
typedef uint16_t L3FW_InterfaceTypeType;            /**< @brief Interface type */
#define L3FW_INTERFACE_TYPE_IPV4        (0x0000U)   /**< @brief IPV4 interface @xsd name:IPv4 */
#define L3FW_INTERFACE_TYPE_IPV6        (0x0001U)   /**< @brief IPV6 interface @xsd name:IPv6 */
/** @} */


/** @brief NAPT Match type

    @trace #BRCM_SWREQ_L3FW
 */
typedef struct sL3FW_NAPTMatchType {
    ETHER_IpAddressType  srcIp;      /**< @brief Source IP Address */
    ETHER_IpAddressType  dstIp;      /**< @brief Destination IP Address */
    L3FW_InterfaceIdType ifcId;      /**< @brief Interface Id (for DMAC match) */
    L3FW_L4PortNumType   l4srcPort;  /**< @brief L4 Source Port (0 - to ignore) */
    L3FW_L4PortNumType   l4dstPort;  /**< @brief L4 destination Port (0 - to ignore) */
    L3FW_L4ProtoType     protocol;   /**< @brief TCP/UDP/NONE */
    uint8_t              reserved;   /**< @brief reserved @xsd rsvd   */
} L3FW_NAPTMatchType;
BCM_STATIC_SIZE_ASSERT(L3FW_NAPTMatchType, 48, L3FW_MAX_MSG_SIZE);

/** @brief NAPT Remap type

    @trace #BRCM_SWREQ_L3FW
 */
typedef struct sL3FW_NAPTRemapDataType {
    ETHER_IpAddressType  ip;          /**< @brief Remap IP Address */
    L3FW_L4PortNumType   l4port;      /**< @brief L4 Remap Port, set to 0 if overwrite is not required */
    L3FW_InterfaceIdType ifcId;       /**< @brief Interface Id (SMAC, VLAN and switch port) */
    uint8_t              dmac[6];     /**< @brief Remap Destination Address @xsd type:mac */
    L3FW_VlanPCPType     pcp;         /**< @brief PCP Filed of VLAN (to be updated) */
    L3FW_PktDirType      direction;   /**< @brief Packet direction */
} L3FW_NAPTRemapDataType;
BCM_STATIC_SIZE_ASSERT(L3FW_NAPTRemapDataType, 32, L3FW_MAX_MSG_SIZE);

/** @brief NAPT Rule Entry type

    @trace #BRCM_SWREQ_L3FW
 */
typedef struct sL3FW_NAPTRouteCfgType {
    L3FW_NAPTMatchType      match;          /**< @brief Match parameters */
    L3FW_NAPTRemapDataType  remap;          /**< @brief Remap parameters */
} L3FW_NAPTRouteCfgType;
BCM_STATIC_SIZE_ASSERT(L3FW_NAPTRouteCfgType, 80, L3FW_MAX_MSG_SIZE);

/** @brief NAPT Statistics type

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_NAPTRouteStatsType {
    uint64_t hit;               /**< @brief Count of hits                       */
    uint64_t miss;              /**< @brief Reserved. Currently not supported   */
    uint64_t noRouteErr;        /**< @brief Route entry not valid               */
    uint64_t ttlErr;            /**< @brief TTL field being 0                   */
    uint64_t vlanErr;           /**< @brief Untagged packet, remap config error */
    uint64_t protocolErr;       /**< @brief Unknown protocol                    */
    uint64_t txErr;             /**< @brief Error in sending packet             */
    uint64_t noMemErr;          /**< @brief Tx buffer full                      */
    uint64_t lastTimestamp;     /**< @brief Timestamp of the last packet hit    */
    uint64_t reserved[5];
} L3FW_NAPTRouteStatsType;
BCM_STATIC_SIZE_ASSERT(L3FW_NAPTRouteStatsType, 112, L3FW_MAX_MSG_SIZE);

/** @brief NAPT Config Message Type

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_NAPTRouteMsgType {
    L3FW_HandleType hdl;       /**< @brief Output: NAPT Route handle */
    L3FW_NAPTRouteCfgType cfg; /**< @brief Input: NAPT Config */
    uint32_t reserved[2];
} L3FW_NAPTRouteMsgType;
BCM_STATIC_SIZE_ASSERT(L3FW_NAPTRouteMsgType, 96, L3FW_MAX_MSG_SIZE);

/** @brief NAPT Stats Message Type

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_NAPTRouteStatsMsgType {
    L3FW_HandleType hdl;           /**< @brief Input: NAPT Route handle */
    L3FW_NAPTRouteStatsType stats; /**< @brief Output: NAPT Route Statistics */
} L3FW_NAPTRouteStatsMsgType;
BCM_STATIC_SIZE_ASSERT(L3FW_NAPTRouteStatsMsgType, 120, L3FW_MAX_MSG_SIZE);

/**
    @brief Interface Config structure

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_InterfaceCfgType {
    L3FW_InterfaceTypeType ifcType;     /**< @brief Interface type */
    uint16_t               port;        /**< @brief Switch port number */
    ETHER_VLANIDType       vlanId;      /**< @brief VLAN ID associated with the interface
                                                    Only used in egress path */
    uint8_t                macAddr[6];  /**< @brief MAC Address @xsd type:mac */
    uint8_t                reserved[4]; /**< @brief reserved @xsd rsvd   */
} L3FW_InterfaceCfgType;
BCM_STATIC_SIZE_ASSERT(L3FW_InterfaceCfgType, 16, L3FW_MAX_MSG_SIZE)

/**
    @brief Message structure for Remove L3 Interface

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_UnicastRouteCfgType {
    L3FW_UnicastRouteIdType routeId;       /**< @brief Unicast route id */
    L3FW_InterfaceIdType    ifcId;         /**< @brief Interface Id (based on the config order) */
    ETHER_IpAddressType     ipAddr;        /**< @brief Dest IP match for the unicast */
    uint8_t                 netMaskPrefix; /**< @brief Defines net mask prefix bits for ipAddr.
                                                       (Number of bits set in mask from MSB side) */
    uint8_t                 dstMac[6];     /**< @brief Destination MAC address for this route @xsd type:mac */
    uint8_t                 reserved2[1];  /**< @brief reserved @xsd rsvd   */
} L3FW_UnicastRouteCfgType;
BCM_STATIC_SIZE_ASSERT(L3FW_UnicastRouteCfgType, 32, L3FW_MAX_MSG_SIZE)

/**
    @brief Message structure for Remove L3 Interface

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_MulticastCfgType {
    uint64_t             l2PortMask; /**< @brief List of L2 forwarding ports (bit mask) */
                                     /**< @brief output interfaces to route  (bit mask) */
    ETHER_IpAddressType  mcGrpIp;    /**< @brief Multicast group ip address             */
    uint8_t              ifcMask[(L3FW_MAX_CFG_INTERFACE+7UL)/8UL];
    uint8_t              rsvd;       /**< @brief reserved to align @xsd rsvd            */
} L3FW_MulticastCfgType;
BCM_STATIC_SIZE_ASSERT(L3FW_MulticastCfgType, 32, L3FW_MAX_MSG_SIZE)

/**
    @brief L3 Configuration

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_CfgType {
    uint32_t                 version;     /**< @brief Config version magic L3FW_CFG_MAGIC @xsd constant:0x3046334C  */
    uint16_t                 maxIpV6UnicastRoutes;
                                          /**< @brief Maximum number of IPV6 unicast routes reserved */
    uint16_t                 numInterfaceCfg;
                                          /**< @brief Number of valid interfaces in the config */
    uint16_t                 numUnicastCfg;
                                          /**< @brief Number of unicast configs */
    uint16_t                 numMulticastCfg;
                                          /**< @brief Number of multicast configs */
    uint16_t                 numNAPTCfg;  /**< @brief Number of NAPT Configs */
                                          /**< @brief Number of multicast configs */
    L3FW_InterfaceCfgType    interfaceCfg[L3FW_MAX_CFG_INTERFACE];
                                          /**< @brief Interface List */
    L3FW_UnicastRouteCfgType unicastCfg[L3FW_MAX_CFG_UNICAST];
                                          /**< @brief Unicast route config list */
    L3FW_MulticastCfgType    multicastCfg[L3FW_MAX_CFG_MULTICAST];
                                          /**< @brief Multicast config list */
    L3FW_NAPTRouteCfgType    naptCfg[L3FW_MAX_CFG_NAPT];
                                          /**< @brief NAPT config list */
} L3FW_CfgType;
_Static_assert(sizeof(L3FW_CfgType) < (12UL*1024UL-512UL), "Config size exceeded");
BCM_STATIC_SIZE_ASSERT(L3FW_CfgType, 11152, 11152)

/**
    @brief Message structure for Add L3 Interface

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_InterfaceMsgType {
    L3FW_InterfaceIdType   ifcId;       /**< @brief Interface Id */
    ETHER_VLANIDType       vlanId;      /**< @brief VLAN ID */
    ETHER_PortIDType       port;        /**< @brief Switch port number */
    L3FW_InterfaceTypeType ifcType;     /**< @brief Interface type */
    uint8_t                macAddr[6];  /**< @brief MAC address for this interface @xsd type:mac */
    uint8_t                reserved[4];
} L3FW_InterfaceMsgType;
BCM_STATIC_SIZE_ASSERT(L3FW_InterfaceMsgType, 20, L3FW_MAX_MSG_SIZE);

/**
    @brief Message structure for Add Unicast route message
    This is also used for fetching Unicast route details where routeHdl is input
    and other paramters are output.

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_UnicastRouteMsgType {
    L3FW_HandleType         routeHdl;       /**< @brief Output: Unicast route handle */
    L3FW_InterfaceIdType    ifcId;          /**< @brief Input: Interface handle */
    L3FW_UnicastRouteIdType routeId;        /**< @brief Input: Unicast forwarding Route index */
    ETHER_IpAddressType     ipAddr;         /**< @brief Input: IP Address to be matched */
    uint8_t                 netMaskPrefix;  /**< @brief Defines net mask prefix bits for ipAddr.
                                                       (Number of bits set in mask from MSB side) */
    uint8_t                 dstMac[6];      /**< @brief Input: Destination MAC address @xsd type:mac */
    uint8_t                 reserved[1];
} L3FW_UnicastRouteMsgType;
BCM_STATIC_SIZE_ASSERT(L3FW_UnicastRouteMsgType, 40, L3FW_MAX_MSG_SIZE);

/**
    @brief Message structure for Add multicast group

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_MulticastGrpMsgType {
    L3FW_HandleType       mcGrpHdl;     /**< @brief Output: Multicast group handle */
    ETHER_IpAddressType   mcGrpIpAddr;  /**< @brief Input:  Multicast group IP address */
    uint8_t               reserved[4];
} L3FW_MulticastGrpMsgType;
BCM_STATIC_SIZE_ASSERT(L3FW_MulticastGrpMsgType, 32, L3FW_MAX_MSG_SIZE);

/**
    @brief Message structure for subscribe to multicast group

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_MulticastIfcMsgType {
    L3FW_HandleType      mcGrpHdl;    /**< @brief Input: Multicast group handle */
    L3FW_InterfaceIdType ifcId;       /**< @brief Input: Interface handle */
    uint8_t              reserved[6];
} L3FW_MulticastIfcMsgType;
BCM_STATIC_SIZE_ASSERT(L3FW_MulticastIfcMsgType, 16, L3FW_MAX_MSG_SIZE);

/**
    @brief Message structure to set L2 forwarding ports for the multicast group

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_MulticastL2MsgType {
    L3FW_HandleType  mcGrpHdl;    /**< @brief Input: Multicast group handle */
    uint64_t         l2PortMask;  /**< @brief Input: L2 forwarding port list (bit mask) */
} L3FW_MulticastL2MsgType;
BCM_STATIC_SIZE_ASSERT(L3FW_MulticastL2MsgType, 16, L3FW_MAX_MSG_SIZE);

/**
    @brief Message structure to get unicast handle

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_UnicastHandleMsgType {
    L3FW_HandleType routeHdl;        /**< @brief Output: Route handle    */
    BCM_BoolType isIpV6;             /**< @brief Input: Flag for IP verion TRUE = IPV6, FALSE = IPV4 */
    L3FW_UnicastRouteIdType routeId; /**< @brief Input: Unicast route ID */
    uint8_t reserved[2];
} L3FW_UnicastHandleMsgType;
BCM_STATIC_SIZE_ASSERT(L3FW_UnicastHandleMsgType, 16, L3FW_MAX_MSG_SIZE);


/**
    @brief Message structure to get static interface list

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_StaticIfcListType {
    L3FW_InterfaceIdType ifcId[L3FW_MAX_CFG_INTERFACE];   /**< @brief Output: List of static ifc */
    uint16_t             ifcCnt;                          /**< @brief Output: Num of static ifc  */
    uint8_t              rsvd[2U];                        /**< @brief reserved                   */
} L3FW_StaticIfcListType;
BCM_STATIC_SIZE_ASSERT(L3FW_StaticIfcListType, 52, L3FW_MAX_MSG_SIZE);

/**
    @brief Message structure to get route handles list

    @trace #BRCM_SWREQ_L3FW
*/
typedef struct sL3FW_RouteHandleListType {
    L3FW_HandleType hdlList[(L3FW_MAX_MSG_SIZE/8U) - 1U]; /**< @brief Output: List of handles in range */
    uint16_t        startIdx;                        /**< @brief Input: Start index in hdl list   */
    uint16_t        endIdx;                          /**< @brief Input: End index in hdl list     */
    uint16_t        hdlCnt;                          /**< @brief Output: Num of handles in range  */
    uint8_t         rsvd[2];                         /**< @brief reserved                         */
} L3FW_RouteHandleListType;
BCM_STATIC_SIZE_ASSERT(L3FW_RouteHandleListType, L3FW_MAX_MSG_SIZE, L3FW_MAX_MSG_SIZE);

/**
    @brief Union encapsulating all messages for PSFP

    @trace #BRCM_SWREQ_L3FW
*/
typedef union uL3FW_MsgUnionType {
    uint32_t                     data[L3FW_MAX_MSG_SIZE/4UL]; /**< @brief Raw message data */
    L3FW_HandleType              hdl;                         /**< @brief Interface, MulticastGroup handle */
    L3FW_InterfaceIdType         ifcId;                       /**< @brief Interface Id */
    L3FW_InterfaceMsgType        ifc;                         /**< @brief Interface message */
    L3FW_UnicastRouteMsgType     unicastRoute;                /**< @brief Unicast Route message */
    L3FW_MulticastGrpMsgType     multicastGrp;                /**< @brief Multicast Group message */
    L3FW_MulticastIfcMsgType     multicastIfc;                /**< @brief Multicast interface message */
    L3FW_MulticastL2MsgType      multicatL2Ports;             /**< @brief Multicast L2 port message */
    L3FW_NAPTRouteMsgType        naptRouteMsg;                /**< @brief NAPT route message */
    L3FW_NAPTRouteStatsMsgType   naptStatsMsg;                /**< @brief NAPT stats message */
    L3FW_UnicastHandleMsgType    ucHandle;                    /**< @brief Unicast handle message */
    L3FW_StaticIfcListType       staticIfcList;               /**< @brief Static interface list */
    L3FW_RouteHandleListType     hdls;                        /**< @brief Route handles list */
} L3FW_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(L3FW_MsgUnionType, L3FW_MAX_MSG_SIZE, L3FW_MAX_MSG_SIZE);

/**
    @brief Add L3 Interface

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl      Connection handle (from RPC_Connect)
    @param[in]     aIfcCfg       Interface config
    @param[out]    aIfcId        Handle to the interface

    @retval  #BCM_ERR_OK            Interface added successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aIfcCfg.port/aIfcCfg.vlanid is invalid or
                                    aIfcId is NULL or aIfcCfg is NULL or
                                    aIfcCfg.macAddr is not a unicast address
    @retval  #BCM_ERR_NOPERM        Given aIfcCfg.port, aIfcCfg.vlanid combination
                                    already present
    @retval  #BCM_ERR_NOMEM         Max interface limit reached

    @post None

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_AddInterface(BCM_HandleType aConnHdl,
                          L3FW_InterfaceCfgType const * const aIfcCfg,
                          L3FW_InterfaceIdType * const aIfcId);

/**
    @brief Get L3 Interface

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]    aConnHdl      Connection handle (from RPC_Connect)
    @param[in]    aIfcId        Handle to the interface
    @param[out]   aIfcCfg       Interface config


    @retval  #BCM_ERR_OK            Interface info fetched
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aIfcId is invalid or aIfcCfg is NULL
    @retval  #BCM_ERR_NOT_FOUND     Interface aIfcId not found

    @post None

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_GetInterface(BCM_HandleType aConnHdl,
                          L3FW_InterfaceIdType aIfcId,
                          L3FW_InterfaceCfgType * const aIfcCfg);

/**
    @brief Remove L3 Interface

    Remove an L3 interface added by L3FW_AddInterface().

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl  Connection handle (from RPC_Connect)
    @param[in]     aIfcId   Handle to the interface

    @retval  #BCM_ERR_OK               Interface removed successfully
    @retval  #BCM_ERR_TIME_OUT         HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS     aIfcId is invalid
    @retval  #BCM_ERR_NOT_FOUND        aIfcId is not added

    @post None

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_RemoveInterface(BCM_HandleType aConnHdl,
                             L3FW_InterfaceIdType aIfcId);

/**
    @brief Add L3 Unicast Route

    This API is used for creating a new unicast route

    @behavior Sync, Non-Reentrant

    @pre One or more interfaces are defined

    @param[in]     aConnHdl     Connection handle (from RPC_Connect)
    @param[in]     aRouteCfg    Unicast route config
    @param[out]    aRouteHdl    Unicast route handle

    @retval  #BCM_ERR_OK            Unicast route added successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_NOMEM         aRouteCfg.routeId is more than max unicast route limit
    @retval  #BCM_ERR_NOPERM        aRouteCfg.routeId is already configured.
                                    Need to #L3FW_RemoveUnicastRoute()
    @retval  #BCM_ERR_INVAL_PARAMS  aRouteCfg.dmac is not a unicast address
    @retval  #BCM_ERR_INVAL_PARAMS  aRouteCfg.ipAddr or aRouteCfg.netMaskPrefix is invalid
    @retval  #BCM_ERR_INVAL_PARAMS  aRouteCfg.ifcId is invalid

    @post New unicast route is added with given configuration

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_AddUnicastRoute(BCM_HandleType aConnHdl,
                             L3FW_UnicastRouteCfgType const * const aRouteCfg,
                             L3FW_HandleType *aRouteHdl);

/**
    @brief Get L3 Unicast route.

    This API is used to fetch Unicast route using handle
    @note: Fetched ipAddr is masked output of the set ip address and the net-mask,
           where net-mask is defined using netMaskPrefix.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl    Connection handle (from RPC_Connect)
    @param[in]     aRouteHdl   Unicast route handle. Returned by #L3FW_AddUnicastRoute()
    @param[out]    aRouteCfg   Unicast route config

    @retval  #BCM_ERR_OK               Unicast route fetched successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aRouteCfg is invalid
    @retval  #BCM_ERR_NOT_FOUND        Handle does not exist

    @post None

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_GetUnicastRoute(BCM_HandleType aConnHdl,
                             L3FW_HandleType aRouteHdl,
                             L3FW_UnicastRouteCfgType *const aRouteCfg);

/**
    @brief Remove L3 Unicast route.

    This API is used for removing / invalidating the already configured
    unicast route (ipv4 or ipv6)

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl    Connection handle (from RPC_Connect)
    @param[in]     aRouteHdl   Unicast route handle. Returned by #L3FW_AddUnicastRoute()

    @retval  #BCM_ERR_OK               Unicast route removed successfully
    @retval  #BCM_ERR_TIME_OUT         HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS     aRouteHdl is invalid

    @post Given unicast route is removed

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_RemoveUnicastRoute(BCM_HandleType aConnHdl,
                                L3FW_HandleType aRouteHdl);

/**
    @brief Get Unicast route handle

    Get the Unicast route handle for the given routeId
    and IPV type.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl    Connection handle (from RPC_Connect)
    @param[in]     aIsIpV6     Boolean for IPv6 type
    @param[in]     aRouteId    Unicast route id.
    @param[in]     aRouteHdl   Unicast route handle

    @retval  #BCM_ERR_OK               Unicast route removed successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aRouteHdl is NULL
    @retval  #BCM_ERR_INVAL_PARAMS     aRouteId is out of range
    @retval  #BCM_ERR_NOT_FOUND        aRouteId not configured

    @post None

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_GetUnicastRouteHdl(BCM_HandleType aConnHdl,
                                BCM_BoolType aIsIpV6,
                                L3FW_UnicastRouteIdType aRouteId,
                                L3FW_HandleType *aRouteHdl);

/**
    @brief Add L3 multicast group

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl  Connection handle (from RPC_Connect)
    @param[in]     aMcGrpIp  Multicast group IP address
    @param[out]    aMcGrpHdl Handle to the created multicast group

    @retval  #BCM_ERR_OK            Multicast group added successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_NOMEM         Max multicast group limit reached
    @retval  #BCM_ERR_NOPERM        Multicast IP already added
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpIp or aMcGrpHdl is NULL
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpIp is not a multicast address

    @post Given multicast group is created

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_AddMulticastGrp(BCM_HandleType aConnHdl,
                             ETHER_IpAddressType const * const aMcGrpIp,
                             L3FW_HandleType *const aMcGrpHdl);

/**
    @brief Remove the existing L3 multicast group

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl  Connection handle (from RPC_Connect)
    @param[in]     aMcGrpHdl Multicast group handle to be removed

    @retval  #BCM_ERR_OK            Multicast group removed successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aIPaddr or aMcGrpHdl is NULL

    @post Given multicast group is removed

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_RemoveMulticastGrp(BCM_HandleType aConnHdl,
                                L3FW_HandleType aMcGrpHdl);

/**
    @brief Add the interface to the multicast group

    @behavior Sync, Non-Reentrant

    @pre Multicast group is configured correctly

    @param[in]    aConnHdl  Connection handle (from RPC_Connect)
    @param[in]    aMcGrpHdl Multicast group handle
    @param[in]    aIfcId   Output interface to be subscribed

    @retval  #BCM_ERR_OK            Interface is subscribed to the multicast successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpHdl or aIfcId is invalid

    @post Given interface is added to the multicast group

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_AddMulticastIfc(BCM_HandleType aConnHdl,
                             L3FW_HandleType aMcGrpHdl,
                             L3FW_InterfaceIdType aIfcId);

/**
    @brief Remove the interface from the multicast group

    @behavior Sync, Non-Reentrant

    @pre Multicast group is configured correctly and the
         interface is subscribed.

    @param[in]    aConnHdl   Connection handle (from RPC_Connect)
    @param[in]    aMcGrpHdl  Multicast group handle
    @param[in]    aIfcId    Output interface to be unsubscribed

    @retval  #BCM_ERR_OK            Unsubscribed from multicast
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpHdl or aIfcId is invalid

    @post Given interface is unsubscribed from the multicast group

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_RemoveMulticastIfc(BCM_HandleType aConnHdl,
                                L3FW_HandleType aMcGrpHdl,
                                L3FW_InterfaceIdType aIfcId);

/**
    @brief Set L2 forwarding port masks to multicast group

    @behavior Sync, Non-Reentrant

    @pre Multicast group is configured correctly

    @param[in]    aConnHdl   Connection handle (from RPC_Connect)
    @param[in]    aMcGrpHdl  Multicast group handle
    @param[in]    aPortMask  Port list in bitmask format

    @retval  #BCM_ERR_OK            Ports added successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpHdl is invalid
    @retval  #BCM_ERR_INVAL_PARAMS  aPortMask is invalid (port mask bits out of range)

    @post Given port mask is setup for L2 forwarding

    @trace #BRCM_SWREQ_L3FW

    @limitations None
*/
int32_t L3FW_SetMulticastL2Ports(BCM_HandleType aConnHdl,
                                 L3FW_HandleType aMcGrpHdl,
                                 uint64_t aPortMask);

/** @brief Add an NAPT route

    This API adds a new NAPT route.
    VLAN in the processed packet is updated based on remap VID and PCP.
    This table lists the possible cases.
    ----------------------------------------------------------------------
    case    Vlan-In   Vlan-Out   Remap-VID   Remap-PCP   Action
    ----------------------------------------------------------------------
    1       Yes       Yes        0U-4094U    0U-7U       Update PCP and VID
    2       Yes       Yes        0x8001U     0U-7U       Retain VID, Update PCP
    3       Yes       Yes        0U-4094U    0x80U       Update VID, Retain PCP
    4       Yes       Yes        0x8001U     0x80U       Retain VID, Retain PCP
    5       Yes       No         0x8000U     NA          Untag packet
    6       No        Yes        0U-4094U    0U-7U       Add PCP and VID
    7       No        No         0x8000U     NA          No action
    8       No        No         0x8001U     NA          No action
    -----------------------------------------------------------------------

    ETHER_VLANID_UNTAG         (0x8000U)
    ETHER_VLANID_ALL           (0x8001U)
    L3FW_VLAN_PCP_MAX          (0x07U)
    L3FW_VLAN_PCP_NONE         (0x80U)

    @note: In order for remaped PCP to take effect, pcpRemarkEn field in port
          config must be flase.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl      Connection handle (from RPC_Connect)
    @param[in]  aRouteCfg     NAPT route config
    @param[out] aRouteHdl     Handle to the NAPT route

    @retval    #BCM_ERR_OK              NAPT route added successfully
    @retval    #BCM_ERR_NOMEM           Insufficient memory to add
    @retval    #BCM_ERR_INVAL_PARAMS    aRouteCfg or aRouteHdl is NULL
    @retval    #BCM_ERR_INVAL_PARAMS    one or more filed in aRouteCfg is invalid
    @retval    #BCM_ERR_NOPERM          Duplicate match configuration

    @post NAPT Route configured

    @limitations None

    @trace #BRCM_SWREQ_L3FW
*/
int32_t L3FW_AddNAPTRoute(BCM_HandleType aConnHdl,
                          L3FW_NAPTRouteCfgType const * const aRouteCfg,
                          L3FW_HandleType *aRouteHdl);

/** @brief Get NAPT route

    This API gets NAPT route details

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl    Connection handle (from RPC_Connect)
    @param[in]  aRouteHdl   NAPT route handle.
    @param[out] aRouteCfg   NAPT route config

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Flow deleted successfully
    @retval    #BCM_ERR_INVAL_PARAMS    aRouteHdl is invalid

    @post NAPT Route details fetched

    @limitations None

    @trace #BRCM_SWREQ_L3FW
*/
int32_t L3FW_GetNAPTRoute(BCM_HandleType aConnHdl,
                          L3FW_HandleType aRouteHdl,
                          L3FW_NAPTRouteCfgType *const aRouteCfg);

/** @brief Remove an NAPT route

    This API removes/invalidates an existing NAPT route

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl    Connection handle (from RPC_Connect)
    @param[in]  aRouteHdl   NAPT route to be deleted.

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Flow deleted successfully
    @retval    #BCM_ERR_INVAL_PARAMS    aRouteHdl is invalid

    @post NAPT Route removed

    @limitations None

    @trace #BRCM_SWREQ_L3FW
*/
int32_t L3FW_RemoveNAPTRoute(BCM_HandleType aConnHdl,
                             L3FW_HandleType aRouteHdl);

/** @brief Retrieve statistics of an NAPT route

    This API retrieves statistics of an NAPT route

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl      Connection handle (from RPC_Connect)
    @param[in]  aRouteHdl     NAPT Route handle
    @param[out] aStats        Statistics of NAPT route

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Statistics retrieved successfully
    @retval    #BCM_ERR_INVAL_PARAMS    aRouteHdl is invalid
    @retval    #BCM_ERR_INVAL_PARAMS    aStats is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_L3FW
*/
int32_t L3FW_GetNAPTRouteStats(BCM_HandleType aConnHdl,
                               L3FW_HandleType aRouteHdl,
                               L3FW_NAPTRouteStatsType *const aStats);

/** @brief Retrieve global NAPT statistics

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl      Connection handle (from RPC_Connect)
    @param[out] aStats        Statistics of NAPT route

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Statistics retrieved successfully
    @retval    #BCM_ERR_INVAL_PARAMS    aStats is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_L3FW
*/
int32_t L3FW_GetNAPTStats(BCM_HandleType aConnHdl,
                          L3FW_NAPTRouteStatsType *const aStats);

/** @brief Get list of static l3fw interface IDs

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aConnHdl    Connection handle (from RPC_Connect)
    @param[out]  aIfcList    Pointer to interface list

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Interface ID list fetched
    @retval    #BCM_ERR_INVAL_PARAMS    aIfcList is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_L3FW
*/
int32_t L3FW_GetIfcStaticIds(BCM_HandleType aConnHdl,
                             L3FW_StaticIfcListType *const aIfcList);

/** @brief Get list of static l3fw unicast route handles

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aConnHdl    Connection handle (from RPC_Connect)
    @param[out]  aHdls       Pointer to handle list structure

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Unicast Handle list fetched
    @retval    #BCM_ERR_INVAL_PARAMS    aHdls is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_L3FW
*/
int32_t L3FW_GetUnicastStaticHdls(BCM_HandleType aConnHdl,
                                  L3FW_RouteHandleListType *const aHdls);

/** @brief Get list of static l3fw NAPT route handles

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl    Connection handle (from RPC_Connect)
    @param[in]  aHdls       Pointer to handle list structure

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              NAPT Handle list fetched
    @retval    #BCM_ERR_INVAL_PARAMS    aHdls is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_L3FW
*/
int32_t L3FW_GetNaptStaticHdls(BCM_HandleType aConnHdl,
                               L3FW_RouteHandleListType *const aHdls);

#endif /* ETHERNET_L3FW_H */
/** @} */
