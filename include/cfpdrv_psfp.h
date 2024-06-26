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
    @defgroup grp_cfpdrv_psfp_ifc PerStream Filtering and Policing (PSFP) Interface
    @ingroup grp_cfpdrv

    @addtogroup grp_cfpdrv_psfp_ifc
    @{

    @file cfpdrv_psfp.h

    @brief Interface for PSFP
    This file provides the interface/APIs which can be used to initialize,
    configure and add/remove rules to/from the PSFP block.

    @version 0.1 Initial version
*/

#ifndef CFPDRV_PSFP_H
#define CFPDRV_PSFP_H

#include <stdint.h>
#include <bcm_utils.h>
#include <ethernet_swt_psfp.h>

/**
    @name PSFP Architecture IDs
    @{
    @brief Architecture IDs for PSFP
*/
#define BRCM_SWARCH_CFPDRV_PSFP_INVAL_MACRO                     (0x8000U) /**< @brief #CFPDRV_PSFP_INVAL_STREAM_IDX   */
#define BRCM_SWARCH_CFPDRV_PSFP_INIT_PROC                    (0x8002U) /**< @brief #CFPDRV_PSFPInit             */
#define BRCM_SWARCH_CFPDRV_PSFP_SET_PORT_MASK_PROC           (0x8003U) /**< @brief #CFPDRV_PSFPSetPortMask      */
#define BRCM_SWARCH_CFPDRV_PSFP_SET_STRM_FILTER_PROC         (0x8004U) /**< @brief #CFPDRV_PSFPSetStreamFilter  */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_STRM_FILTER_PROC         (0x8005U) /**< @brief #CFPDRV_PSFPGetStreamFilter  */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_STRM_FILTER_STATUS_PROC  (0x8006U) /**< @brief #CFPDRV_PSFPGetStreamFilterStatus */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_STRM_COUNTERS_PROC       (0x8007U) /**< @brief #CFPDRV_PSFPGetStreamCounters */
#define BRCM_SWARCH_CFPDRV_PSFP_CLEAR_STREAM_COUNTERS_PROC   (0x8008U) /**< @brief #CFPDRV_PSFPClearStreamCounters */
#define BRCM_SWARCH_CFPDRV_PSFP_SET_GATE_CONFIG_PROC         (0x8009U) /**< @brief #CFPDRV_PSFPSetGateConfig    */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_GATE_CONFIG_PROC         (0x800AU) /**< @brief #CFPDRV_PSFPGetGateConfig    */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_GATE_STATUS_PROC         (0x800BU) /**< @brief #CFPDRV_PSFPGetGateStatus    */
#define BRCM_SWARCH_CFPDRV_PSFP_SET_FLOW_METER_CONFIG_PROC   (0x800CU) /**< @brief #CFPDRV_PSFPSetFlowMeterConfig */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_FLOW_METER_CONFIG_PROC   (0x800DU) /**< @brief #CFPDRV_PSFPGetFlowMeterConfig */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_FLOW_METER_STATUS_PROC   (0x800EU) /**< @brief #CFPDRV_PSFPGetFlowMeterStatus */
#define BRCM_SWARCH_CFPDRV_PSFP_METER_DROP_ALL_FRAMES_PROC   (0x800FU) /**< @brief #CFPDRV_PSFPFlowMeterDropAllFrames */
#define BRCM_SWARCH_CFPDRV_PSFP_UNBLOCK_STREAM_FILTER_PROC   (0x8010U) /**< @brief #CFPDRV_PSFPUnblockStreamFilter */
#define BRCM_SWARCH_CFPDRV_PSFP_UNBLOCK_GATE_PROC            (0x8011U) /**< @brief #CFPDRV_PSFPUnblockGate      */
#define BRCM_SWARCH_CFPDRV_PSFP_UNBLOCK_FLOW_METER_PROC      (0x8012U) /**< @brief #CFPDRV_PSFPUnblockFlowMeter */
#define BRCM_SWARCH_CFPDRV_PSFP_SET_TUNING_OFFSET_PROC       (0x8013U) /**< @brief #CFPDRV_PSFPSetTuningOffset  */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_TUNING_OFFSET_PROC       (0x8014U) /**< @brief #CFPDRV_PSFPGetTuningOffset  */
#define BRCM_SWARCH_CFPDRV_PSFP_DEINIT_PROC                  (0x8015U) /**< @brief #CFPDRV_PSFPDeinit           */
#define BRCM_SWARCH_CFPDRV_PSFP_GET_TOD_PROC                 (0x8016U) /**< @brief #CFPDRV_PSFPGetTimeOfDay     */
#define BRCM_SWARCH_CFPDRV_PSFP_ENABLE_EVENT_PROC            (0x8017U) /**< @brief #CFPDRV_PSFPEnableEvent      */
#define BRCM_SWARCH_CFPDRV_PSFP_EVENT_TYPE                   (0x8018U) /**< @brief #CFPDRV_PSFPEventType           */
#define BRCM_SWARCH_CFPDRV_PSFP_NOTIFICATION_TYPE            (0x8019U) /**< @brief #CFPDRV_PSFPNotificationType    */
#define BRCM_SWARCH_CFPDRV_PSFP_EVENT_MSG_MACRO              (0x801AU) /**< @brief #CFPDRV_PSFPDRV_EVENT_MSG       */
#define BRCM_SWARCH_CFPDRV_PSFP_NOTIFYUNION_TYPE             (0x801BU) /**< @brief #CFPDRV_PSFPNotifyUnionType     */
/** @} */

/**
    @brief Macro for invalid stream index/meter index/gate index

    @{
    @brief Macro for

    @trace #BRCM_SWREQ_CFPDRV_PSFP
*/
#define CFPDRV_PSFP_INVAL_STREAM_IDX  (0xFFFFFFFFUL)
#define CFPDRV_PSFP_INVAL_GATE_IDX    (0xFFFFFFFFUL)
#define CFPDRV_PSFP_INVAL_METER_IDX   (0xFFFFFFFFUL)
/** @} */

/**
    @name PSFP Event type
    @{
    @brief PSFP Events macro

    @trace #BRCM_SWREQ_CFPDRV_PSFP
*/
typedef uint32_t CFPDRV_PSFPEventType;
#define CFPDRV_PSFP_EVENT_STREAM_FLTR       (0UL)
#define CFPDRV_PSFP_EVENT_GATE              (1UL)
#define CFPDRV_PSFP_EVENT_FLOW_METER        (2UL)
#define CFPDRV_PSFP_EVENT_GATE_CFG_ERR      (3UL)
/** @} */

/**
    @brief PSFP Notification

    @trace #BRCM_SWREQ_CFPDRV_PSFP
*/
typedef struct sCFPDRV_PSFPNotificationType {
    CFPDRV_PSFPEventType event;         /**< @brief Type of PSFP event */
    uint32_t             instanceNum;   /**< @brief Stream filter index if
                                            (event is #CFPDRV_PSFP_EVENT_STREAM_FLTR or
                                            #CFPDRV_PSFP_EVENT_GATE or
                                            #CFPDRV_PSFP_EVENT_FLOW_METER)
                                            Gate index if
                                            (event is CFPDRV_PSFP_EVENT_GATE_CFG_ERR)
                                        */
    uint32_t             reserved[8];   /**< @brief reserved fields */
} CFPDRV_PSFPNotificationType;
_Static_assert(sizeof(CFPDRV_PSFPNotificationType) == sizeof(BCM_NotifyDataType),
               "Size of CFPDRV_PSFPNotificationType should be equal to BCM_NotifyDataType");

/**
    @brief PSFP event notification custom data union

    PSFP event notification custom data union

    @trace #BRCM_SWREQ_CFPDRV_PSFP
 */
typedef union uCFPDRV_PSFPNotifyUnionType {
    BCM_NotifyDataType           custData;   /**< @brief custom data */
    CFPDRV_PSFPNotificationType  payload;    /**< @brief ETHSWT PSFP event notification custom data */
} CFPDRV_PSFPNotifyUnionType;

/**
    @brief PSFP Event message

    @trace #BRCM_SWREQ_CFPDRV_PSFP
*/
#define CFPDRV_PSFPDRV_EVENT_MSG                                                          \
                    (((1UL                          << BCM_MSG_ID_SHIFT   ) & BCM_MSG_ID_MASK   ) | \
                     (((uint32_t)BCM_PSFP_ID        << BCM_MSG_COMP_SHIFT ) & BCM_MSG_COMP_MASK ) | \
                     (((uint32_t)BCM_GROUPID_ETHSRV << BCM_MSG_GROUP_SHIFT) & BCM_MSG_GROUP_MASK) | \
                     (BCM_MSG_ASYNC_MASK))

/** @brief Initialize PSFP HW and the driver

    @behavior Sync, Re-entrant

    @pre CFI driver initialized

    @param[in]    aID             Switch HW index

    @retval  #BCM_ERR_OK            Initialization successful

    @post PSFP HW and driver initialized

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPInit(ETHSWT_HwIDType aID);

/** @brief Global Enable & Disable ports for PSFP processing

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID        Switch HW index
    @param[in]    aPortMask  Bit mask of ports to be enabled for PSFP processing

    @retval  #BCM_ERR_OK  Port enable successful

    @post PSFP port enable mask setup

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPSetPortMask(ETHSWT_HwIDType aID, ETHSWT_PortMaskType aPortMask);

/** @brief Configure a Stream filter

    @behavior Sync, Re-entrant

    @pre PSFP Driver initialized

    @param[in]    aID                 Switch HW index
    @param[in]    aStreamFilterIdx    Stream filter index. (0 to #ETHSWT_PSFP_MAX_STREAM_FILTERS-1)
    @param[in]    aMaxSduSize         Max SDU size index
                                      set this to #ETHSWT_PSFP_MAXSDU_INVALID to disable SDU size check
    @param[in]    aBlockOnOvSizeFrame Block the stream if oversize frame encountered
    @param[in]    aFlowMeterIdx       Flow meter id defined by CFPDRV_PSFPConfigFlowMeter()
                                      set this to #CFPDRV_PSFP_INVAL_METER_IDX to disable flow meter feature
                                      for this stream
    @param[in]    aGateIdx            Gate index defined by CFPDRV_PSFPSetGateConfig()
                                      set this to #CFPDRV_PSFP_INVAL_GATE_IDX to disable gate feature
                                      for this stream

    @retval  #BCM_ERR_OK           Stream filter setup successfully
    @retval  #BCM_ERR_TIME_OUT     Timeout while accessing the register
    @retval  #BCM_ERR_INVAL_PARAMS aID or aStreamFilterIdx or aFlowMeterIdx or aGateIdx is invalid

    @post    Stream filter setup & enabled

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPSetStreamFilter(ETHSWT_HwIDType aID,
                                      uint32_t aStreamFilterIdx,
                                      uint32_t aMaxSduSize,
                                      BCM_BoolType aBlockOnOvSizeFrame,
                                      uint32_t aFlowMeterIdx,
                                      uint32_t aGateIdx);

/** @brief Read the Stream filter configuration

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID                 Switch HW index
    @param[in]    aStreamFilterIdx    Stream filter index. (0 to #ETHSWT_PSFP_MAX_STREAM_FILTERS-1)
    @param[out]   aMaxSduSize         Max SDU size in bytes
                                      set this to #ETHSWT_PSFP_MAXSDU_INVALID to disable SDU size check
    @param[out]   aBlockOnOvSizeFrame Block the stream if oversize frame encountered
    @param[out]   aFlowMeterIdx       Flow meter index defined by CFPDRV_PSFPConfigFlowMeter()
                                      set to #CFPDRV_PSFP_INVAL_METER_IDX if flow meter feature is disabled
                                      for this stream
    @param[out]   aGateIdx            Gate id defined by CFPDRV_PSFPSetGateConfig()
                                      set to #CFPDRV_PSFP_INVAL_GATE_IDX if gate feature is disabled
                                      for this stream

    @retval  #BCM_ERR_OK           Initialization successful
    @retval  #BCM_ERR_INVAL_PARAMS aID or aStreamFilterIdx is invalid or
                                   aMaxSduSize, or aFlowMeterIdx or aGateIdx is NULL
    @retval  #BCM_ERR_TIME_OUT     Timeout while accessing the register

    @post    None

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetStreamFilter(ETHSWT_HwIDType aID,
                                      uint32_t aStreamFilterIdx,
                                      uint32_t * const aMaxSduSize,
                                      BCM_BoolType * const aBlockOnOvSizeFrame,
                                      uint32_t * const aFlowMeterIdx,
                                      uint32_t * const aGateIdx);

/** @brief Get Stream filter status

    This API retrieves the stream filter status

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID                      Switch HW index
    @param[in]    aStreamFilterIdx         Stream filter index. (0 to #ETHSWT_PSFP_MAX_STREAM_FILTERS-1)
    @param[out]   aStatus                  Stream filter status

    @retval  #BCM_ERR_OK             Stream filter status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS   #aID or #aStreamFilterIdx is invalid OR
                                     #aStatus is NULL
    @retval  #BCM_ERR_TIME_OUT       Timeout while accessing the register

    @post    None

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetStreamFilterStatus(ETHSWT_HwIDType aID,
                                            uint32_t aStreamFilterIdx,
                                            ETHSWT_PSFPStreamFilterStatusType * const aStatus);

/** @brief Get Frame counters for the stream

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID               Switch HW index
    @param[in]    aStreamFilterIdx  Stream filter index. (0 to #ETHSWT_PSFP_MAX_STREAM_FILTERS-1)
    @param[out]   aFrameCounter     Frame counter

    @retval  #BCM_ERR_OK             Stream counter read successfully
    @retval  #BCM_ERR_INVAL_PARAMS   #aID or #aStreamFilterIdx is invalid OR
                                     #aFrameCounter is NULL
    @retval  #BCM_ERR_TIME_OUT       Timeout while accessing the register

    @post    None

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetStreamCounters(ETHSWT_HwIDType aID,
                                        uint32_t aStreamFilterIdx,
                                        ETHSWT_PSFPFrameCountersType *const aFrameCounter);

/** @brief Clear Frame counters for the stream

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID               Switch HW index
    @param[in]    aStreamFilterIdx  Stream filter index. (0 to #ETHSWT_PSFP_MAX_STREAM_FILTERS-1)

    @retval  #BCM_ERR_OK             Stream counters cleared successfully
    @retval  #BCM_ERR_INVAL_PARAMS   #aID or #aStreamFilterIdx is invalid OR
    @retval  #BCM_ERR_TIME_OUT       Timeout while accessing the register


    @post    None

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPClearStreamCounters(ETHSWT_HwIDType aID,
                                          uint32_t aStreamFilterIdx);

/** @brief Set Gate config

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID       Switch HW index
    @param[in]    aGateIdx  Gate index (0 to #ETHSWT_PSFP_MAX_GATES-1)
    @param[in]    aGateCfg  Gate Config

    @retval  #BCM_ERR_OK             Gate Config successful
    @retval  #BCM_ERR_INVAL_PARAMS   #aID or #aGateIdx is invalid OR
                                     #aGateCfg is NULL
    @retval  #BCM_ERR_TIME_OUT       Timeout while accessing the register
    @retval  #BCM_ERR_CUSTOM         The maxOctets value provided in the gate
                                     configuration could not be supported in
                                     the hardware
    @retval  #BCM_ERR_BUSY           New config cannot be applied as the
                                     previously applied config is still pending.
                                     Gate will be in this state from a successful
                                     gate config to one cycle time past the base time.

    @post    Given gate config programmed

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPSetGateConfig(ETHSWT_HwIDType aID,
                                    uint32_t aGateIdx,
                                    const ETHSWT_PSFPGateCfgType *const aGateCfg);

/** @brief Get Gate config

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID       Switch HW index
    @param[in]    aGateIdx  Gate index (0 to #ETHSWT_PSFP_MAX_GATES-1)
    @param[out]   aGateCfg  Gate Config

    @retval  #BCM_ERR_OK             Gate config read successfully
    @retval  #BCM_ERR_INVAL_PARAMS   #aID or #aGateIdx is invalid OR
                                     #aGateCfg is NULL
    @retval  #BCM_ERR_TIME_OUT       Timeout while accessing the register

    @post    None

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetGateConfig(ETHSWT_HwIDType aID,
                                    uint32_t aGateIdx,
                                    ETHSWT_PSFPGateCfgType *const aGateCfg);

/** @brief Get gate status

    This API retrieves the gate status

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID           Switch HW index
    @param[in]    aGateIdx      Gate index (0 to #ETHSWT_PSFP_MAX_GATES-1)
    @param[out]   aStatus       Gate Status

    @retval  #BCM_ERR_OK            Gate status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS  #aID or #aGateIdx is invalid OR
                                    #aStatus is NULL
    @retval  #BCM_ERR_TIME_OUT      Timeout while accessing the register

    @post    None

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetGateStatus(ETHSWT_HwIDType aID,
                                    uint32_t aGateIdx,
                                    ETHSWT_PSFPGateStatusType *const aStatus);

/**
    @brief Configure a flowmeter

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]    aID            Switch HW index
    @param[in]    aFlowMeterIdx  Flow meter index (0 to #ETHSWT_PSFP_MAX_FLOW_METERS-1)
    @param[in]    aCfg           Flow meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter configured successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aCfg is NULL OR
                                       #aID or #aFlowMeterIdx is not valid
    @retval  #BCM_ERR_TIME_OUT         Register access timeout

    @post Given flow meter is configured in the HW

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPSetFlowMeterConfig(ETHSWT_HwIDType aID,
                                         uint32_t aFlowMeterIdx,
                                         ETHSWT_PSFPFlowMeterCfgType const *const aCfg);

/**
    @brief Retrieve a flowmeter config

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aID              Switch HW index
    @param[in]     aFlowMeterIdx    Flow meter index (0 to #ETHSWT_PSFP_MAX_FLOW_METERS-1)
    @param[out]    aCfg             Flow meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aCfg is NULL OR
                                       #aFlowMeterIdx is not valid
    @retval  #BCM_ERR_TIME_OUT         Register access timeout

    @post None

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetFlowMeterConfig(ETHSWT_HwIDType aID,
                                         uint32_t aFlowMeterIdx,
                                         ETHSWT_PSFPFlowMeterCfgType *const aCfg);

/**
    @brief Get flow meter status

    This API retrieves the flow meter status

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aID              Switch HW index
    @param[in]     aFlowMeterIdx    Flow meter index
    @param[out]    aStatus          Flow meter status

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aFlowMeterIdx is invalid OR
                                       #aStatus is NULL
    @retval  #BCM_ERR_TIME_OUT         Register access timeout

    @post None

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetFlowMeterStatus(ETHSWT_HwIDType aID,
                                         uint32_t aFlowMeterIdx,
                                         ETHSWT_PSFPFlowMeterStatusType *const aStatus);

/**
    @brief Drop all frames on flow meter

    This API configures the "mark all frames red" parameter to enable/disable
    the feature to drop all packets on the flow meter. If multiple streams
    are associated with the flow meter, packets of all those streams would be
    affected. When the feature is disabled, the color of the packets would
    be determined on the basis of the incoming rate/burst (i.e. regular
    flow meter operation).

    @behavior Sync, Non-Reentrant

    @pre None

	@param[in]     aID                 Switch HW index
    @param[in]     aFlowMeterIdx       Flow meter index
    @param[in]     aEnable             Flag indicating whether all frames are to
                                       be dropped (1) or not (0)

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter configured to drop all frames
                                       successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aFlowMeterIdx is invalid
    @retval  #BCM_ERR_TIME_OUT         Register access timeout

    @post None

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPFlowMeterDropAllFrames(ETHSWT_HwIDType aID,
                                             uint32_t aFlowMeterIdx,
                                             BCM_BoolType aEnable);

/**
    @brief Unblock a stream

    This API unblocks a blocked stream by clearing the StreamBlockedDueToOversizeFrame
    parameter

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]    aID               Switch HW index
    @param[in]    aStreamFilterIdx  Stream filter index. (0 to #ETHSWT_PSFP_MAX_STREAM_FILTERS-1)

    @retval  #BCM_ERR_OK            Stream unblocked successfully
    @retval  #BCM_ERR_INVAL_PARAMS  #aID or #aStreamFilterIdx is invalid
    @retval  #BCM_ERR_TIME_OUT      Timeout while accessing the register

    @post  Given stream is unblocked

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPUnblockStreamFilter(ETHSWT_HwIDType aID,
                                          uint32_t aStreamFilterIdx);

/**
    @brief Unblock a gate

    This API unblocks a blocked gate by clearing the reason(s) provided as input.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aID             Switch HW index
    @param[in]     aGateIdx        Gate index (0 to #ETHSWT_PSFP_MAX_GATES-1)
    @param[in]     aUnblockInvalRx Unblock invalid rx error
    @param[in]     aUnblockOctetEx Unblock octet Exceeded error

    @retval  #BCM_ERR_OK               Gate unblocked successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aID or #aGateIdx is invalid or
                                       both aUnblockInvalRx and aUnblockOctetEx
                                       are FALSE
    @retval  #BCM_ERR_TIME_OUT         Timeout while accessing the register

    @post Given gate is unblocked

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPUnblockGate(ETHSWT_HwIDType aID,
                                  uint32_t aGateIdx,
                                  BCM_BoolType aUnblockInvalRx,
                                  BCM_BoolType aUnblockOctetEx);

/**
    @brief Unblock a flow meter

    This API unblocks a blocked flow meter by clearing the "mark all frames red"
    parameter

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aID                 Switch HW index
    @param[in]     aFlowMeterIdx       Flow meter index

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter unblocked successfully
    @retval  #BCM_ERR_INVAL_PARAMS     @aID or #aFlowMeterIdx is invalid
    @retval  #BCM_ERR_TIME_OUT         Register access timedout

    @post None

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPUnblockFlowMeter(ETHSWT_HwIDType aID,
                                       uint32_t aFlowMeterIdx);

/**
    @brief Set tuning offset

    This API sets the tuning offset. This is an offset added to the current
    Time of Day (TOD) before using it for any time comparisons (e.g. for
    gating/loading new gate control lists)

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]    aID           Switch HW index
    @param[in]    aSecs         Seconds part of the tuning offset
    @param[in]    aNanosecs     Nanoseconds part of the tuning offset

    @retval  #BCM_ERR_OK            Tuning offset programmed successfully
    @retval  #BCM_ERR_INVAL_PARAMS  #aID is invalid
    @retval  #BCM_ERR_NOSUPPORT     Given offset is not supported by the
                                    platform

    @post Tuning offset updated

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPSetTuningOffset(ETHSWT_HwIDType aID,
                                      uint32_t aSecs,
                                      uint32_t aNanosecs);

/**
    @brief Get tuning offset

    This API Gets the tuning offset. This is an offset added to the current
    Time of Day (TOD) before using it for any time comparisons (e.g. for
    gating/loading new gate control lists)

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]    aID           Switch HW index
    @param[out]   aSecs         Seconds part of the tuning offset
    @param[out]   aNanosecs     Nanoseconds part of the tuning offset

    @retval  #BCM_ERR_OK            Tuning offset read successfully
    @retval  #BCM_ERR_INVAL_PARAMS  #aID is invalid or
                                    #aSecs or aNanosecs is NULL

    @post None

    @trace   #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetTuningOffset(ETHSWT_HwIDType aID,
                                      uint32_t * const aSecs,
                                      uint32_t * const aNanosecs);

/**
    @brief Enable/Disable PSFP event notification

    @behavior Sync, Non-Reentrant

    @pre

    @param[in]    aID               Switch HW index
    @param[in]    aStreamFilterIdx  Stream filter index
    @param[in]    aMaxSduIntEn      Max SDU interrupt enable
                                    0 - Disable Event notification,
                                    1 - Enable Event notification,
                                    2 - Keep the current state
    @param[in]    aGateIntEn        Gate interrupt enable
                                    0 - Disable Event notification,
                                    1 - Enable Event notification,
                                    2 - Keep the current state
    @param[in]    aFlowMeterIntEn   Flow meter interrupt enable
                                    0 - Disable Event notification,
                                    1 - Enable Event notification,
                                    2 - Keep the current state

    @retval  #BCM_ERR_OK         Event notification updated successfully
    @retval  #BCM_ERR_TIME_OUT   Register access timeout

    @post

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPEnableEvent(ETHSWT_HwIDType aID,
                                  uint32_t aStreamFilterIdx,
                                  uint32_t aMaxSduEvent,
                                  uint32_t aGateEvent,
                                  uint32_t aFlowMeterEvent);

/**
    @brief Get time of day used by PSFP

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]    aID           Switch HW index
    @param[out]   aSecs         Seconds part of the TOD
    @param[out]   aNanosecs     Nanoseconds part of the TOD

    @retval  #BCM_ERR_OK            Time of day read successfully
    @retval  #BCM_ERR_INVAL_PARAMS  #aID is invalid or
                                    #aSecs or aNanosecs is NULL

    @post None

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPGetTimeOfDay(ETHSWT_HwIDType aID,
                                   uint32_t * const aSecs,
                                   uint32_t * const aNanosecs);

/**
    @brief PSFP Deinit

    Clears all the PSFP configs and deinitializes the HW

    @behavior Sync, Non-Reentrant

    @pre PSFP driver is initialized

    @param[in]    aID           Switch HW index

    @retval  #BCM_ERR_OK            Tuning offset read successfully
    @retval  #BCM_ERR_INVAL_PARAMS  #aID is invalid
    @retval  #BCM_ERR_TIME_OUT      Timeout while accessing the register

    @post PSFP Driver deinitialized

    @trace #BRCM_SWREQ_CFPDRV_PSFP

    @limitations None
*/
int32_t CFPDRV_PSFPDeinit(ETHSWT_HwIDType aID);

#endif /* CFPDRV_PSFP_H */

/** @} */
