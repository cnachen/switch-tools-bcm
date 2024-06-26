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
    @defgroup grp_ethernet_swt_dbg_ifc Switch Debug abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_dbg_ifc
    @{

    @file ethernet_swt_debug.h

    @brief Debug Abstract Interface
    This file contains the interfaces for the Ethernet abstract for Debug

    @version 1.0 Initial version
*/

#ifndef ETHERNET_SWT_DEBUG_H
#define ETHERNET_SWT_DEBUG_H

#include <module_msg.h>
#include <ethernet_common.h>
#include <ethernet_swt_common.h>
#include <ethernet_swt_debug_types.h>

/**
    @name Switch CORE API IDs
    @{
    @brief API IDs for CORE in Switch
*/
#define BRCM_SWARCH_ETHSWT_DEBUGCMDID_TYPE                (0x8301U)    /**< @brief #ETHSWT_DebugCmdIdType          */
#define BRCM_SWARCH_ETHSWT_DEBUGMIRRORENABLE_TYPE         (0x8302U)    /**< @brief #ETHSWT_DebugMirrorEnableType   */
#define BRCM_SWARCH_ETHSWT_DEBUGMIRRORSTATUS_TYPE         (0x8303U)    /**< @brief #ETHSWT_DebugMirrorStatusType   */
#define BRCM_SWARCH_ETHSWT_DEBUGMIB_TYPE                  (0x8304U)    /**< @brief #ETHSWT_DebugMibType            */
#define BRCM_SWARCH_ETHSWT_DEBUGMIBCLEAR_TYPE             (0x8305U)    /**< @brief #ETHSWT_DebugMibClearType       */
#define BRCM_SWARCH_ETHSWT_DEBUGTXMIBSV2MSG_TYPE          (0x8306U)    /**< @brief #ETHSWT_DebugTxMibsV2MsgType    */
#define BRCM_SWARCH_ETHSWT_DEBUGRXMIBSV2MSG_TYPE          (0x8307U)    /**< @brief #ETHSWT_DebugRxMibsV2MsgType    */
#define BRCM_SWARCH_ETHSWT_TRAFFICDIR_TYPE                (0x8308U)    /**< @brief #ETHSWT_TrafficDirType          */
#define BRCM_SWARCH_ETHSWT_PORTMIRRORSTATE_TYPE           (0x8309U)    /**< @brief #ETHSWT_PortMirrorStateType     */
#define BRCM_SWARCH_ETHSWT_PORTMIRRORCFG_TYPE             (0x830AU)    /**< @brief #ETHSWT_PortMirrorCfgType       */
#define BRCM_SWARCH_ETHSWT_DEBUGMSGUNION_TYPE             (0x830BU)    /**< @brief #ETHSWT_DebugMsgUnionType       */
#define BRCM_SWARCH_ETHSWT_DEBUG_MAX_PAYLOAD_SIZE_MACRO   (0x830CU)    /**< @brief #ETHSWT_DEBUG_MAX_PAYLOAD_SIZE  */
#define BRCM_SWARCH_ETHSWT_DEBUG_ID_OF_MACRO              (0x830DU)    /**< @brief #ETHSWT_DEBUG_ID_OF             */
#define BRCM_SWARCH_ETHSWT_PORTMIRRORCFGV2_TYPE           (0x830EU)    /**< @brief #ETHSWT_PortMirrorCfgV2Type     */
#define BRCM_SWARCH_ETHSWT_DEBUGMIRRORENABLEV2_TYPE       (0x830FU)    /**< @brief #ETHSWT_DebugMirrorEnableV2Type */
#define BRCM_SWARCH_ETHSWT_DEBUGMIRRORSTATUSV2_TYPE       (0x8310U)    /**< @brief #ETHSWT_DebugMirrorStatusV2Type */
#define BRCM_SWARCH_ETHSWT_DEBUGENABLEMIRROR_PROC         (0x8311U)    /**< @brief #ETHSWT_DebugEnableMirror       */
#define BRCM_SWARCH_ETHSWT_DEBUGDISABLEMIRROR_PROC        (0x8312U)    /**< @brief #ETHSWT_DebugDisableMirror      */
#define BRCM_SWARCH_ETHSWT_DEBUGGETMIRRORSTATUS_PROC      (0x8313U)    /**< @brief #ETHSWT_DebugGetMirrorStatus    */
#define BRCM_SWARCH_ETHSWT_DEBUGGETPORTMIBS_PROC          (0x8314U)    /**< @brief #ETHSWT_DebugGetPortMibs        */
#define BRCM_SWARCH_ETHSWT_DEBUGCLEARPORTMIBS_PROC        (0x8315U)    /**< @brief #ETHSWT_DebugClearportMibs      */
#define BRCM_SWARCH_ETHSWT_DEBUGGETPORTTXMIBS_PROC        (0x8316U)    /**< @brief #ETHSWT_DebugGetPortTxMibs      */
#define BRCM_SWARCH_ETHSWT_DEBUGGETPORTRXMIBS_PROC        (0x8318U)    /**< @brief #ETHSWT_DebugGetPortRxMibs      */
#define BRCM_SWARCH_ETHSWT_DEBUGGETPORTMIBSALL_PROC       (0x8317U)    /**< @brief #ETHSWT_DebugGetPortMibsAll     */
#define BRCM_SWARCH_ETHSWT_DEBUGCLEARPORTMIBSV2_PROC      (0x8319U)    /**< @brief #ETHSWT_DebugClearportMibsV2    */
/** @} */

/**
    @brief Macro to Construct Ethernet Debug Commands

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_DEBUG_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_DBG_ID, aId)

/**
    @name Switch Debug command IDs
    @{
    @brief Switch Debug command IDs group

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_DebugCmdIdType;               /**< @brief VLAN command message Type                                                               */
#define ETHSWT_DEBUGCMDID_MIRROR_ENABLE     ETHSWT_DEBUG_ID_OF(0x70U)  /**< @brief #ETHSWT_DebugMirrorEnableType   #ETHSWT_SetPortMirrorConfig:ETHSWT_SetPortMirrorState   */
#define ETHSWT_DEBUGCMDID_MIRROR_DISABLE    ETHSWT_DEBUG_ID_OF(0x71U)  /**< @brief #NA                             #ETHSWT_GetMirrorCapturePort:ETHSWT_SetPortMirrorState  */
#define ETHSWT_DEBUGCMDID_MIRROR_STATUS     ETHSWT_DEBUG_ID_OF(0x72U)  /**< @brief #ETHSWT_DebugMirrorStatusType   #ETHSWT_GetMirrorCapturePort:ETHSWT_GetPortMirrorState:ETHSWT_GetPortMirrorConfig:ETHSWT_GetPortMirrorConfig */
#define ETHSWT_DEBUGCMDID_MIBS              ETHSWT_DEBUG_ID_OF(0x73U)  /**< @brief #ETHSWT_DebugMibType            #ETHSWT_GetRxStat:ETHSWT_GetTxStat                       */
#define ETHSWT_DEBUGCMDID_MIBS_CLEAR        ETHSWT_DEBUG_ID_OF(0x74U)  /**< @brief #ETHSWT_DebugMibType            #ETHSWT_ClearRxStat:ETHSWT_ClearTxStat                   */
#define ETHSWT_DEBUGCMDID_MIRROR_ENABLE_V2  ETHSWT_DEBUG_ID_OF(0x75U)  /**< @brief #ETHSWT_DebugMirrorEnableV2Type #ETHSWT_SetPortMirrorConfig:ETHSWT_SetPortMirrorState   */
#define ETHSWT_DEBUGCMDID_MIRROR_STATUS_V2  ETHSWT_DEBUG_ID_OF(0x76U)  /**< @brief #ETHSWT_DebugMirrorStatusV2Type #ETHSWT_GetMirrorCapturePort:ETHSWT_GetPortMirrorState:ETHSWT_GetPortMirrorConfig:ETHSWT_GetPortMirrorConfig */
#define ETHSWT_DEBUGCMDID_RX_MIBS_V2        ETHSWT_DEBUG_ID_OF(0x77U)  /**< @brief #ETHSWT_DebugRxMibsV2MsgType    #ETHSWT_GetRxStatV2                   */
#define ETHSWT_DEBUGCMDID_TX_MIBS_V2        ETHSWT_DEBUG_ID_OF(0x78U)  /**< @brief #ETHSWT_DebugTxMibsV2MsgType    #ETHSWT_GetTxStatV2                   */
#define ETHSWT_DEBUGCMDID_MIBS_CLEAR_V2     ETHSWT_DEBUG_ID_OF(0x79U)  /**< @brief #ETHSWT_DebugMibClearType       #ETHSWT_ClearRxStatV2:ETHSWT_ClearTxStatV2 */
/** @} */

/**
    @brief Maximum size of VLAN command payload in bytes

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_DEBUG_MAX_PAYLOAD_SIZE   (400UL)

/**
    @name Traffic direction
    @{
    @brief Dirrection of traffic

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_TrafficDirType;
#define ETHSWT_TRAFFICDIR_INGRESS   (0x0U) /**< @brief Ingress */
#define ETHSWT_TRAFFICDIR_EGRESS    (0x1U) /**< @brief Egress  */
#define ETHSWT_TRAFFICDIR_BIDIR     (0x2U) /**< @brief Bi-directional traffic */
/** @} */

/**
    @name Port mirror state type
    @{
    @brief Port mirror state type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PortMirrorStateType;          /**< @brief Port mirror state type */
#define ETHSWT_PORTMIRRORSTATE_DISABLED     (0x0UL) /**< @brief Port mirror state disabled */
#define ETHSWT_PORTMIRRORSTATE_ENABLED      (0x1UL) /**< @brief Port mirror state enabled */
/** @} */

/**
    @brief Port mirror configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PortMirrorCfgType {
    uint16_t portMask;              /**< @brief Mirrored port mask. This is bit
                                            mask value of the ports whose traffic
                                            shall be mirrored to the given port */
    uint16_t packetDivider;         /**< @brief Packet divider (only a subset of
                                            the received frame shall be mirrored).
                                            For example if packetDivider is set to
                                            10, then out of 10 packets passing the
                                            filtering, only 1 shall be mirrored */
    uint8_t srcMacAddrFilter[6UL];  /**< @brief Source MAC address that shall be
                                            mirrored */
    uint8_t destMacAddrFilter[6UL]; /**< @brief Destination MAC address that
                                            shall be mirrored */
} ETHSWT_PortMirrorCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PortMirrorCfgType, 16UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Port mirror V2 configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PortMirrorCfgV2Type {
    ETHSWT_PortMaskType portMask;              /**< @brief Mirrored port mask. This is bit
                                                    mask value of the ports whose traffic
                                                    shall be mirrored to the given port */
    uint16_t            packetDivider;         /**< @brief Packet divider (only a subset of
                                                    the received frame shall be mirrored).
                                                    For example if packetDivider is set to
                                                    10, then out of 10 packets passing the
                                                    filtering, only 1 shall be mirrored */
    uint8_t             srcMacAddrFilter[6UL];  /**< @brief Source MAC address that shall be
                                                     mirrored */
    uint8_t             destMacAddrFilter[6UL]; /**< @brief Destination MAC address that
                                                     shall be mirrored */
} ETHSWT_PortMirrorCfgV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PortMirrorCfgV2Type, 24UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the port Mirroring.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMirrorEnableType {
    ETHSWT_PortIDType           probePort;       /**< @brief probe port */
    ETHSWT_TrafficDirType       direction;       /**< @brief traffic direction */
    ETHSWT_PortMirrorCfgType    mirrorCfg;       /**< @brief mirror configuration */
} ETHSWT_DebugMirrorEnableType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMirrorEnableType, 24UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the port Mirroring.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMirrorEnableV2Type {
    ETHSWT_PortIDType           probePort;       /**< @brief probe port */
    ETHSWT_TrafficDirType       direction;       /**< @brief traffic direction */
    ETHSWT_PortMirrorCfgV2Type  mirrorCfg;       /**< @brief mirror configuration */
} ETHSWT_DebugMirrorEnableV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMirrorEnableV2Type, 32UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the port Mirroring status.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMirrorStatusType {
    ETHSWT_PortMirrorStateType  state;              /**< @brief enabled or disabled */
    ETHSWT_PortIDType           probePort;          /**< @brief probe port */
    ETHSWT_PortMirrorCfgType    ingressMirrorCfg;   /**< @brief mirror configuration for ingress traffic */
    ETHSWT_PortMirrorCfgType    egressMirrorCfg;    /**< @brief mirror configuration for egress traffic */
} ETHSWT_DebugMirrorStatusType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMirrorStatusType, 40UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the port Mirroring status.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMirrorStatusV2Type {
    ETHSWT_PortMirrorStateType  state;              /**< @brief enabled or disabled */
    ETHSWT_PortIDType           probePort;          /**< @brief probe port */
    ETHSWT_PortMirrorCfgV2Type  ingressMirrorCfg;   /**< @brief mirror configuration for ingress traffic */
    ETHSWT_PortMirrorCfgV2Type  egressMirrorCfg;    /**< @brief mirror configuration for egress traffic */
} ETHSWT_DebugMirrorStatusV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMirrorStatusV2Type, 56UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the Rx/Tx statistics.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMibType {
    ETHSWT_PortIDType port;      /**< @brief Port ID */
    ETHER_RxStatsType rxStats;     /**< @brief Receive stats */
    ETHER_TxStatsType txStats;     /**< @brief Transmit stats */
} ETHSWT_DebugMibType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMibType, 224UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to clear the Rx/Tx statistics.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMibClearType {
    ETHSWT_PortMaskType txPortMask;      /**< @brief Port mask to clear tx mibs */
    ETHSWT_PortMaskType rxPortMask;      /**< @brief Port mask to clear rx mibs */
} ETHSWT_DebugMibClearType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMibClearType, 16UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the Tx statistics.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugTxMibsV2MsgType {
    ETHSWT_PortIDType port;        /**< @brief Port ID       */
    uint32_t rsvd;
    ETHER_TxStatsV2Type txStats;   /**< @brief Transmit stats */
} ETHSWT_DebugTxMibsV2MsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugTxMibsV2MsgType, 400UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the Rx statistics.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugRxMibsV2MsgType {
    ETHSWT_PortIDType port;        /**< @brief Port ID       */
    uint32_t rsvd;
    ETHER_RxStatsV2Type rxStats;   /**< @brief Receive stats */
} ETHSWT_DebugRxMibsV2MsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugRxMibsV2MsgType, 384UL, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/**
    @brief Vlan Union encapsulating all messages

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef union uETHSWT_DebugMsgUnionType {
    uint32_t                        data[ETHSWT_DEBUG_MAX_PAYLOAD_SIZE/4UL];
    ETHSWT_DebugMirrorEnableType    mirrorEnable;   /**< @brief Mirror Enable struct */
    ETHSWT_DebugMirrorStatusType    mirrorStatus;   /**< @brief Mirror Status struct */
    ETHSWT_DebugMibType             mib;            /**< @brief MIB struct           */
    ETHSWT_DebugMirrorEnableV2Type  mirrorEnableV2; /**< @brief Mirror Enable struct */
    ETHSWT_DebugMirrorStatusV2Type  mirrorStatusV2; /**< @brief Mirror Status struct */
    ETHSWT_DebugTxMibsV2MsgType     txMib;          /**< @brief Transmit MIB stats   */
    ETHSWT_DebugRxMibsV2MsgType     rxMib;          /**< @brief Receive MIB stats    */
    ETHSWT_DebugMibClearType        mibClear;       /**< @brief Clear MIB stats      */
} ETHSWT_DebugMsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMsgUnionType, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE, ETHSWT_DEBUG_MAX_PAYLOAD_SIZE)

/** @brief Enable Port Mirror

    This API sets port mirror state.

    @behavior Sync, Non Re-entrant for different aPortID or aSwtID

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect)
    @param[in]      aPortMask           Port Mask
    @param[in]      aProbePort          Probe Port
    @param[in]      aDirection          Traffic direction
    @param[in]      aPacketDivider      Packet divider

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully Enabled port mirror state
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortMask is Invalid) or
                                        (aProbePort is Invalid) or
                                        (aDirection is Invalid) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugEnableMirror(BCM_HandleType aConnHdl,ETHSWT_PortMaskType aPortMask,
                                    ETHSWT_PortIDType aProbePort, ETHSWT_TrafficDirType aDirection,
                                    uint16_t aPacketDivider);

/** @brief Disable Port Mirror

    This API Disables mirror state on the previously Enabled Mirror Port.

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully Disabled port mirror state
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugDisableMirror(BCM_HandleType aConnHdl);

/** @brief Get port mirror configuration

    This API retrieves port mirror configurations on previously Enabled Mirror Port.

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl          Connection handle (from RPC_Connect)
    @param[out]     aMirrorStatus     Pointer to retrieve port mirror configurations

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port mirror
                                        configurations
    @retval     #BCM_ERR_INVAL_PARAMS   (aMirrorStatus is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugGetMirrorStatus(BCM_HandleType aConnHdl,
                                            ETHSWT_DebugMirrorStatusV2Type *const aMirrorStatus);

/** @brief Get Port Mibs

    This API retrieves Tx and Rx statistics for a #aPortID

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aTxStats    Pointer to retrieve TX statistics
    @param[out]     aRxStats    Pointer to retrieve RX statistics

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port RX and TX
                                        statistics
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid port index) or
                                        (aTxStats is NULL) or
                                        (aRxStatsaRxStats is NULL) or
                                        (Invalid aConnHdl)

    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugGetPortMibs(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                            ETHER_TxStatsType *const aTxStats,
                                            ETHER_RxStatsType *const aRxStats);

/** @brief Clear Port Mibs statistics

    This API Clear Port Mibs statistics for #aPortID

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully cleared port Mibs
                                        statistics
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid port index) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugClearportMibs(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID);

/** @brief Get Port Mibs TX stats

    This API retrieves Mib Tx statistics for a #aPortID

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aTxStats    Pointer to retrieve TX statistics

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port TX
                                        statistics
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid port index) or
                                        (aTxStats is NULL) or
                                        (Invalid aConnHdl)

    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugGetPortTxMibs(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                            ETHER_TxStatsV2Type *const aTxStats);

/** @brief Get Port Mib RX stats

    This API retrieves Rx statistics for a #aPortID

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aRxStats    Pointer to retrieve RX statistics

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port RX
                                        statistics
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid port index) or
                                        (aRxStats is NULL) or
                                        (Invalid aConnHdl)

    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugGetPortRxMibs(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                            ETHER_RxStatsV2Type *const aRxStats);

/** @brief Get Port TX and RX Mib stats

    This API retrieves Tx and Rx statistics for a #aPortID

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aTxStats    Pointer to retrieve TX statistics
    @param[out]     aRxStats    Pointer to retrieve RX statistics

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port RX
                                        statistics
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid port index) or
                                        (aTxStats is NULL) or
                                        (aRxStats is NULL) or
                                        (Invalid aConnHdl)

    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugGetPortMibsAll(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                            ETHER_TxStatsV2Type *const aTxStats,
                                            ETHER_RxStatsV2Type *const aRxStats);

/** @brief Clear Port Mibs statistics

    This API Clear Port Mibs statistics for #aPortID

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl          Connection handle (from RPC_Connect)
    @param[in]      aMibsPortMask     Port mask to clear Tx and Rx stats

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully cleared port Mibs
                                        statistics
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid port index) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_DebugClearportMibsV2(BCM_HandleType aConnHdl, ETHSWT_DebugMibClearType *const aMibsPortMask);
#endif /* ETHERNET_SWT_DEBUG_H */
/** @} */
