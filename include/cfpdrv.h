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
    @defgroup grp_cfpdrv_ifc CFP Driver interface
    @ingroup grp_cfpdrv_v2

    @addtogroup grp_cfpdrv_ifc
    @{

    @file cfpdrv.h

    @brief CFP driver interface

    This file contains the interfaces for the CFP Driver
    to initialize, add/remove rules & meters to/from the CFP block.

    @version 0.1 Initial version

*/
#ifndef CFPDRV_H
#define CFPDRV_H

#include <stdint.h>
#include <ethernet_cfp_types.h>

/**
    @name CFP driver Architecture IDs
    @{
    @brief Architecture IDs for CFP driver
*/
#define BRCM_SWARCH_CFPDRV_SLICE_MACRO               (0x8200U) /**< @brief #CFPDRV_SLICE_PSFP           */
#define BRCM_SWARCH_CFPDRV_RULE_GROUP_TYPE           (0x8201U) /**< @brief #CFPDRV_RuleGroupType        */
#define BRCM_SWARCH_CFPDRV_ROW_STATUS_TYPE           (0x8202U) /**< @brief #CFPDRV_RowStatusType        */
#define BRCM_SWARCH_CFPDRV_INIT_CONFIG_TYPE          (0x8203U) /**< @brief #CFPDRV_InitConfigType       */
#define BRCM_SWARCH_CFPDRV_INIT_PROC                 (0x8204U) /**< @brief #CFPDRV_Init                 */
#define BRCM_SWARCH_CFPDRV_SET_PORT_MASK_PROC        (0x8205U) /**< @brief #CFPDRV_SetPortMask          */
#define BRCM_SWARCH_CFPDRV_GET_PORT_MASK_PROC        (0x8206U) /**< @brief #CFPDRV_GetPortMask          */
#define BRCM_SWARCH_CFPDRV_SET_STATE_ID_PROC         (0x8207U) /**< @brief #CFPDRV_SetStateId           */
#define BRCM_SWARCH_CFPDRV_GET_STATE_ID_PROC         (0x8208U) /**< @brief #CFPDRV_GetStateId           */
#define BRCM_SWARCH_CFPDRV_SET_SLICE_CFG_PROC        (0x8209U) /**< @brief #CFPDRV_SetSliceCfg          */
#define BRCM_SWARCH_CFPDRV_SET_UDF_CFG_PROC          (0x820AU) /**< @brief #CFPDRV_SetUdfCfg            */
#define BRCM_SWARCH_CFPDRV_GET_UDF_CFG_PROC          (0x820BU) /**< @brief #CFPDRV_GetUdfCfg            */
#define BRCM_SWARCH_CFPDRV_ADD_ACL_RULE_PROC         (0x820CU) /**< @brief #CFPDRV_AddAclRule           */
#define BRCM_SWARCH_CFPDRV_UPDATE_ACL_RULE_PROC      (0x820DU) /**< @brief #CFPDRV_UpdateAclRule        */
#define BRCM_SWARCH_CFPDRV_REMOVE_ACL_RULE_PROC      (0x820EU) /**< @brief #CFPDRV_RemoveAclRule        */
#define BRCM_SWARCH_CFPDRV_GET_ACL_RULE_PROC         (0x820FU) /**< @brief #CFPDRV_GetAclRule           */
#define BRCM_SWARCH_CFPDRV_GET_ACL_ROW_STATUS_PROC   (0x8210U) /**< @brief #CFPDRV_GetAclRowStatus      */
#define BRCM_SWARCH_CFPDRV_ADD_PSFP_RULE_PROC        (0x8211U) /**< @brief #CFPDRV_AddPsfpRule          */
#define BRCM_SWARCH_CFPDRV_REMOVE_PSFP_RULE_PROC     (0x8212U) /**< @brief #CFPDRV_RemovePsfpRule       */
#define BRCM_SWARCH_CFPDRV_ADD_IPMC_RULE_PROC        (0x8213U) /**< @brief #CFPDRV_AddIpmcRule          */
#define BRCM_SWARCH_CFPDRV_SET_METER_PROC            (0x8214U) /**< @brief #CFPDRV_SetMeter             */
#define BRCM_SWARCH_CFPDRV_GET_METER_PROC            (0x8215U) /**< @brief #CFPDRV_GetMeter             */
#define BRCM_SWARCH_CFPDRV_GET_METER_STATS_PROC      (0x8216U) /**< @brief #CFPDRV_GetMeterStats        */
#define BRCM_SWARCH_CFPDRV_GET_METER_STATUS_PROC     (0x8217U) /**< @brief #CFPDRV_GetMeterStatus       */
#define BRCM_SWARCH_CFPDRV_MARK_ALL_FRAMES_RED_PROC  (0x8218U) /**< @brief #CFPDRV_MarkAllFramesRed     */
#define BRCM_SWARCH_CFPDRV_DE_INIT_PROC              (0x8219U) /**< @brief #CFPDRV_DeInit               */
#define BRCM_SWARCH_CFPDRV_NOTIFICATION_TYPE         (0x821AU) /**< @brief #CFPDRV_NotificationType     */
#define BRCM_SWARCH_CFPDRV_EVENT_MSG_MACRO           (0x821BU) /**< @brief #CFPDRV_EVENT_MSG            */
#define BRCM_SWARCH_CFPDRV_NOTIFYUNION_TYPE          (0x821CU) /**< @brief #CFPDRV_NotifyUnionType      */
#define BRCM_SWARCH_CFPDRV_ACL_IRQ_HANDLER_PROC      (0x821DU) /**< @brief #CFPDRV_ACLIRQHandler        */
/** @} */

/**
    @name Special slice numbers
    @{
    @brief Special slice numbers for PSFP and IPMC.
    This value to be used for the type #CFP_SliceType

    @trace #BRCM_SWREQ_CFPDRV
*/
#define CFPDRV_SLICE_PSFP         (0xFDU) /**< @brief Slice id used for PSFP matching  */
#define CFPDRV_SLICE_IPMC         (0xFEU) /**< @brief Slice id used for IPMC matching  */
/** @} */

/**
    @name CFP Rule group
    @{
    @brief CFP Rule group

    @trace #BRCM_SWREQ_CFPDRV
*/
typedef uint8_t CFPDRV_RuleGroupType;
#define CFPDRV_RULE_GROUP_ACL           (0U)  /**< @brief ACL Rule group */
#define CFPDRV_RULE_GROUP_PSFP          (1U)  /**< @brief PSFP Rule group */
#define CFPDRV_RULE_GROUP_IPMC          (2U)  /**< @brief IPMC Rule group */
#define CFPDRV_RULE_GROUP_MAX           (2U)  /**< @brief Maximum Rule groups */
/** @} */

/**
    @name CFP Rule Row status
    @{
    @brief CFP Rule Row status

    @trace #BRCM_SWREQ_CFPDRV
*/
typedef uint8_t CFPDRV_RowStatusType;
#define CFPDRV_ROW_STATUS_FREE           (0U)  /**< @brief The row is free */
#define CFPDRV_ROW_STATUS_SHORT_RULE     (1U)  /**< @brief The row is occupied by short rule */
#define CFPDRV_ROW_STATUS_LONG_RULE      (2U)  /**< @brief The row is occupied by long rule */
#define CFPDRV_ROW_STATUS_CHAINED        (3U)  /**< @brief The row contains the second part of a long rule */
/** @} */

/**
    @brief CFP Row allocation

    @trace #BRCM_SWREQ_CFPDRV
*/
typedef struct sCFPDRV_InitConfigType {
    uint16_t           maxPsfpRows;          /**< @brief Number of rows reserved for PSFP rules */
    uint16_t           maxIpmcRows;          /**< @brief Number of rows reserved for the IPMC rules */
    CFP_PktLenCorrType pktLenCorr;           /**< @brief Packet length correction */
    BCM_BoolType       disableSlicePriority; /**< @brief Slice priority disable */
} CFPDRV_InitConfigType;

/**
    @brief CFP Notification

    @trace #BRCM_SWREQ_CFPDRV
*/
typedef struct sCFPDRV_NotificationType {
    CFP_RowType  rowNum;        /**< @brief Row number */
    uint16_t     reserved[19U]; /**< @brief Reserved   */
} CFPDRV_NotificationType;
_Static_assert(sizeof(CFPDRV_NotificationType) == sizeof(BCM_NotifyDataType),
               "Size of CFPDRV_NotificationType should be equal to BCM_NotifyDataType");

/**
    @brief CFP event notification custom data union

    CFP event notification custom data union

    @trace #BRCM_SWREQ_CFPDRV
 */
typedef union uCFPDRV_NotifyUnionType {
    BCM_NotifyDataType       custData;   /**< @brief custom data */
    CFPDRV_NotificationType  payload;    /**< @brief CFP event notification custom data */
} CFPDRV_NotifyUnionType;

/**
    @brief CFP Event message

    @trace #BRCM_SWREQ_CFPDRV
*/
#define CFPDRV_EVENT_MSG                                                         \
                    (((1UL                          << BCM_MSG_ID_SHIFT   ) & BCM_MSG_ID_MASK   ) | \
                     (((uint32_t)BCM_CFP_ID         << BCM_MSG_COMP_SHIFT ) & BCM_MSG_COMP_MASK ) | \
                     (((uint32_t)BCM_GROUPID_ETHSRV << BCM_MSG_GROUP_SHIFT) & BCM_MSG_GROUP_MASK) | \
                     (BCM_MSG_ASYNC_MASK))

/** @brief Initialize the CFP HW & Driver

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aCfg       CFP Driver configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Driver initialization successful
    @retval  #BCM_ERR_TIME_OUT       HW access timed out
    @retval  #BCM_ERR_INVAL_PARAMS   aCfg is NULL or any row value specified
                                     is out of range
    @retval  #BCM_ERR_INVAL_STATE    Driver already initialized

    @post CFP HW & Driver initialized

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None

*/
int32_t CFPDRV_Init(const CFPDRV_InitConfigType * const aCfg);

/** @brief Set Port enable mask

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aGroup        CFP rule Group
    @param[in]     aPortMask     Port enable mask

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Port mask set
    @retval  #BCM_ERR_NOSUPPORT      Port mask not supported for the
                                     group
    @retval  #BCM_ERR_INVAL_PARAMS   Port mask bits out of range
    @retval  #BCM_ERR_INVAL_PARAMS   aGroup is invalid
    @retval  #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None

*/
int32_t CFPDRV_SetPortMask(CFPDRV_RuleGroupType aGroup,
                           CFP_PortMaskType  aPortMask);

/** @brief Get CFP Global configurations

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aGroup        CFP rule Group
    @param[out]    aPortMask     Port enable mask

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Port mask retrieved
    @retval  #BCM_ERR_INVAL_PARAMS   aGroup is invalid or aPortMask is NULL
    @retval  #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None

*/
int32_t CFPDRV_GetPortMask(CFPDRV_RuleGroupType aGroup,
                           CFP_PortMaskType  *const aPortMask);

/** @brief Set State ID

    Sets the current state id for the CFP rules

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aStateId     State ID to be set for the CFP block

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Current State id is updated
    @retval  #BCM_ERR_TIME_OUT       Hardware access timed out
    @retval  #BCM_ERR_UNINIT         Driver not initialized

    @post Current state id for the CFP block is updated

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None

*/
int32_t CFPDRV_SetStateId(uint8_t  aStateId);

/** @brief Get State ID

    Gets the current state id for the CFP rules

    @behavior Sync, Re-entrant

    @pre None

    @param[out]     aStateId      Current state id set for the CFP block

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             State ID retrieved successfully
    @retval  #BCM_ERR_TIME_OUT       Hardware access timed out
    @retval  #BCM_ERR_INVAL_PARAMS   aStateId is NULL
    @retval  #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None

*/
int32_t CFPDRV_GetStateId(uint8_t  *aStateId);

/** @brief Set Slice Config

    This API configures one slice

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aSliceNum         Slice number (between 0 and #CFP_MAX_SLICES-1).
    @param[in]     aEnableLongRule   Enable long rule format for this slice.
                                     If enabled, All the IPV6 rules in this slice
                                     follows long rule format.
    @param[in]     aStateIdEnable    State Id check is made available for all
                                     the rules in this slice.

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Slice config updated successfully
    @retval  #BCM_ERR_TIME_OUT       Hardware access timed out
    @retval  #BCM_ERR_INVAL_PARAMS   aSliceNum is invalid
    @retval  #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None

*/
int32_t CFPDRV_SetSliceCfg(CFP_SliceType aSliceNum,
                           BCM_BoolType  aEnableLongRule,
                           BCM_BoolType  aStateIdEnable);

/** @brief Configure UDF Info

    This API configures the UDF belonging to the given slice

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aL3Framing          L3 framing format
    @param[in]     aSliceNum           Slice number (between 0 and #CFP_MAX_SLICES-1).
                                       For PSFP, specify #CFPDRV_SLICE_PSFP.
                                       For IPMC, specify #CFPDRV_SLICE_IPMC.
    @param[in]     aUdfId              UDF index. Is a number between 0 and
                                       #CFP_MAX_SLICE_UDFS-1
    @param[in]     aBase               UDF base
    @param[in]     aOffset             UDF word (2 byte) offset from given base. This
                                       is a number between 0 and 31

    @retval  #BCM_ERR_OK               UDF configured successfully
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out
    @retval  #BCM_ERR_INVAL_PARAMS     #aL3Framing/#aSliceNum/#aUdfId/#aBase/#aOffset
                                       is invalid
    @retVal  #BCM_ERR_NOSUPPORT        #aUdfId is not valid for this slice. This
                                       could happen if we are accessing more than
                                       9 UDFs for a slice which is not enabled
                                       for long rule format.
    @retval  #BCM_ERR_UNINIT           Driver not initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV


    @limitations None

*/
int32_t CFPDRV_SetUdfCfg(CFP_L3FramingType aL3Framing,
                         CFP_SliceType     aSliceNum,
                         uint32_t          aUdfId,
                         CFP_UDFBaseType   aBase,
                         uint8_t           aOffset);

/** @brief Read UDF Info

    This API reads the UDF belonging to the given slice

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aL3Framing          L3 framing format
    @param[in]     aSliceNum           Slice number (between 0 and #CFP_MAX_SLICES-1)
                                       For PSFP, specify #CFPDRV_SLICE_PSFP.
                                       For IPMC, specify #CFPDRV_SLICE_IPMC.
    @param[in]     aUdfId              UDF index. Is a number between 0 and
                                       #CFP_MAX_SLICE_UDFS-1
    @param[out]    aBase               UDF base
    @param[out]    aOffset             UDF word (2 byte) offset from given base. This
                                       is a number between 0 and 31

    @retval  #BCM_ERR_OK               UDF config retrieved successfully
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out
    @retVal  #BCM_ERR_NOSUPPORT        #aUdfId is not valid for this slice. This
                                       could happen if we are accessing more than
                                       9 UDFs for a slice which is not enabled
                                       for long rule format.
    @retval  #BCM_ERR_INVAL_PARAMS     #aL3Framing/#aSliceNum/#aUdfId s invalid
    @retval  #BCM_ERR_INVAL_PARAMS     #aBase or #aOffset is NULL
    @retval  #BCM_ERR_UNINIT           Driver not initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV


    @limitations None

*/
int32_t CFPDRV_GetUdfCfg(CFP_L3FramingType aL3Framing,
                         CFP_SliceType     aSliceNum,
                         uint32_t          aUdfId,
                         CFP_UDFBaseType   * const aBase,
                         uint8_t           * const aOffset);

/** @brief Add ACL Rule

    Adds the given key and action to the CFP HW

    @behavior Sync, Re-entrant

    @pre None

    @param[inout]   aRow            Row number to be programmed.
                                    If #CFP_ROW_INVALID, Row number is
                                    allocated and returned by the driver.
    @param[in]      aSliceNum       Pointer to slice information
    @param[in]      aKey            Key value to be programmed.
    @param[in]      aAction         Action to be programmed.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             On success
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_NOSUPPORT      One or more parameters in the rule
                                        not supported in this platform
    @retval     #BCM_ERR_NOPERM         aRow is already programmed or
                                        aRow is in PSFP/IPMC region
    @retval     #BCM_ERR_INVAL_PARAMS   aSliceNum or aRow number is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aRow is NULL
    @retval     #BCM_ERR_INVAL_PARAMS   aKey or aAction is NULL
    @retval     #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_AddAclRule(CFP_RowType *const          aRow,
                          CFP_SliceType               aSliceNum,
                          const CFP_KeyType *const    aKey,
                          const CFP_ActionType *const aAction);

/** @brief Update ACL Rule

    Updates the given key and action to the CFP HW.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aRow            Row number to be updated.
    @param[in]      aSliceNum       Pointer to slice information
    @param[in]      aKey            Key value to be programmed.
                                    If NULL, only action will be programmed
    @param[in]      aAction         Action to be programmed.
                                    If NULL, only key will be programmed

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             On success
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_NOSUPPORT      One or more parameters in the rule
                                        not supported in this platform
    @retval     #BCM_ERR_NOPERM         aRow is in PSFP/IPMC region
    @retval     #BCM_ERR_NOT_FOUND      No rule configured at #aRow
    @retval     #BCM_ERR_INVAL_PARAMS   aSliceNum or aRow number is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aKey and aAction are NULL
    @retval     #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_UpdateAclRule(CFP_RowType                 aRow,
                             CFP_SliceType               aSliceNum,
                             const CFP_KeyType *const    aKey,
                             const CFP_ActionType *const aAction);

/** @brief Remove ACL Rule

    Removes CFP rule from given row number

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aRow          Row number. If #CFP_ROW_INVALID,
                                Row number is allocated by the driver.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             On success
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_INVAL_PARAMS   aRow number is out of range
    @retval     #BCM_ERR_NOPERM         aRow is in PSFP/IPMC region
    @retval     #BCM_ERR_NOT_FOUND      aRow is not programmed
    @retval     #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_RemoveAclRule(CFP_RowType aRow);


/** @brief Get key & Action for ACL rule

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aRow            Row number
    @param[out]     aSliceNum       Slice number
    @param[out]     aKey            Key value retrieved.
                                    If NULL only action will be fetched
    @param[out]     aAction         Action retrieved.
                                    If NULL only key will be fetched

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             On success
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_INVAL_PARAMS   aRow is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aKey and aAction are NULL
    @retval     #BCM_ERR_NOPERM         aRow is in PSFP/IPMC region
    @retval     #BCM_ERR_NOT_FOUND      aRow is not programmed
    @retval     #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_GetAclRule(CFP_RowType           aRow,
                          CFP_SliceType *const  aSliceNum,
                          CFP_KeyType *const    aKey,
                          CFP_ActionType *const aAction);

/** @brief Get ACL row status

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aRow            Row number
    @param[out]     aStatus         Status of the row

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             On success
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_NOPERM         aRow is not programmed
    @retval     #BCM_ERR_INVAL_PARAMS   aRow is out of range
    @retval     #BCM_ERR_NOPERM         aRow is in PSFP/IPMC region
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL
    @retval     #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_GetAclRowStatus(CFP_RowType                 aRow,
                               CFPDRV_RowStatusType *const aStatus);

/** @brief Program CFP rule for PSFP identification

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aPsfpId       PSFP Id
    @param[in]     aKey          Key to be programmed

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             On success
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_INVAL_PARAMS   aKey NULL
    @retval     #BCM_ERR_INVAL_PARAMS   aPsfpId is not available
    @retval     #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_AddPsfpRule(uint32_t           aPsfpId,
                           CFP_KeyType *const aKey);

/** @brief Remove CFP rule added for PSFP identification

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aPsfpId       PSFP Id

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             On success
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_INVAL_PARAMS   aPsfpId out of range
    @retval     #BCM_ERR_UNINIT         Driver not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_RemovePsfpRule(uint32_t aPsfpId);

/** @brief Program CFP rule for IPMC identification

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aIpmcId       IPMC Id
    @param[in]     aKey          Key to be programmed

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             On success
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_INVAL_PARAMS   aIpmcId is not available
    @retval     #BCM_ERR_INVAL_PARAMS   aKey NULL
    @retval     #BCM_ERR_UNINIT         CFP has not been initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_AddIpmcRule(uint32_t           aIpmcId,
                           CFP_KeyType *const aKey);

/**
    @brief Program a meter

    This API programs a meter identified by the input #aId with #aMeterCfg.
    One or more rules can be associated with this meter.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aMeterId       Meter identifier
    @param[in]     aGroup         This meter to be used with this group
                                  (ACL, PSFP, IPMC)
    @param[in]     aMeterCfg      Meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Meter programmed successfully
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out
    @retval  #BCM_ERR_NOSUPPORT        Meter config not supported for this group
    @retval  #BCM_ERR_INVAL_PARAMS     #aMeterId is an invalid meter identifier OR
                                       #aMeterCfg is NULL
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None
*/
int32_t CFPDRV_SetMeter(CFP_MeterIdType            aMeterId,
                        CFPDRV_RuleGroupType       aGroup,
                        const CFP_MeterType *const aMeterCfg);

/**
    @brief Fetch the meter configuration

    This API retrieves the meter identified by the input #aMeterId.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aMeterId       Meter identifier
    @param[in]     aGroup         This meter to be used with this group
                                  (ACL, PSFP, IPMC)
    @param[out]    aMeterCfg      Meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Meter retrieved successfully
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out
    @retval  #BCM_ERR_NOSUPPORT        Meter config not supported for this group
    @retval  #BCM_ERR_INVAL_PARAMS     #aMeterId is an invalid meter identifier OR
                                       #aMeterCfg is NULL
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None
*/
int32_t CFPDRV_GetMeter(CFP_MeterIdType      aMeterId,
                        CFPDRV_RuleGroupType aGroup,
                        CFP_MeterType *const aMeterCfg);

/**
    @brief CFP driver get statistics of a meter

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aMeterId    Meter id
    @param[in]    aGroup      This meter to be used with this group
                              (ACL, PSFP, IPMC)
    @param[in]    aClear      TRUE : Clear the stats after reading,
                              FALSE : Don't clear the stats
    @param[out]   aStats      Pointer to Statistics

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Stats read successfully
    @retval     #BCM_ERR_TIME_OUT       HW access timed out
    @retval     #BCM_ERR_NOSUPPORT      Meter config not supported for this group
    @retval     #BCM_ERR_INVAL_PARAMS   aMeterId is out of range
    @retval     #BCM_ERR_INVAL_PARAMS   aStats is NULL
    @retval     #BCM_ERR_UNINIT         CFP has not been initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV
*/
int32_t CFPDRV_GetMeterStats(CFP_MeterIdType      aMeterId,
                             CFPDRV_RuleGroupType aGroup,
                             BCM_BoolType         aClear,
                             CFP_MeterStatsType   *const aStats);

/** @brief Get Rate meter status

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aMeterId        Meter id
    @param[in]     aGroup          This meter to be used with this group
                                   (ACL, PSFP, IPMC)
    @param[out]    aFramesBlocked  All frames are blocked due to error

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Rate meter status retrieved successfully
    @retval  #BCM_ERR_TIME_OUT       HW access timed out
    @retval  #BCM_ERR_NOSUPPORT      Meter config not supported for this group
    @retval  #BCM_ERR_INVAL_PARAMS   Register is invalid
    @retval  #BCM_ERR_UNINIT         CFP has not been initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None
*/
int32_t CFPDRV_GetMeterStatus(CFP_MeterIdType      aMeterId,
                              CFPDRV_RuleGroupType aGroup,
                              BCM_BoolType * const aFramesBlocked);

/** @brief Mark all frame red for this meter

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aMeterId   Meter Id
    @param[in]     aGroup     This meter to be used with this group
                              (ACL, PSFP, IPMC)
    @param[in]     aEnable    TRUE : Set mark-all-frames-red,
                              FALSE : Clear mark-all-frames-red

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Rate Meter programmed successfully
    @retval  #BCM_ERR_TIME_OUT       HW access timed out
    @retval  #BCM_ERR_NOSUPPORT      Meter config not supported for this group
    @retval  #BCM_ERR_INVAL_PARAMS   Meter Id invalid
    @retval  #BCM_ERR_UNINIT         CFP has not been initialized

    @post None

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None
*/
int32_t CFPDRV_MarkAllFramesRed(CFP_MeterIdType      aMeterId,
                                CFPDRV_RuleGroupType aGroup,
                                BCM_BoolType         aEnable);

/** @brief CFP ACL Interrupt handler

    This API handles CFP hardware ACL interrupts.

    @behavior Sync, Non-reentrant

    @pre None

    @return     void

    @post None

    @note To be used.

    @trace  #BRCM_SWREQ_CFPDRV

    @limitations None
*/
void CFPDRV_ACLIRQHandler(void);

/** @brief Deinitialize the CFP HW & Driver

    @behavior Sync, Re-entrant

    @pre None

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Driver de-initialization successful
    @retval  #BCM_ERR_TIME_OUT       HW access timed out
    @retval  #BCM_ERR_UNINIT         Driver not initalized

    @post CFP HW & Driver de-initialized

    @trace #BRCM_SWREQ_CFPDRV

    @limitations None

*/
int32_t CFPDRV_DeInit(void);

#endif /* CFPDRV_H */
/** @} */
