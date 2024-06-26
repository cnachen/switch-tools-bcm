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
    @addtogroup grp_cfp_ifc
    @{

    @file ethernet_cfp_sync.h

    @brief CFP Interface
    This file contains the CFP interface

    @version 1.0 Initial version
*/

#ifndef ETHERNET_CFP_SYNC_H
#define ETHERNET_CFP_SYNC_H

#include <ethernet_cfp_types.h>

/**
    @name CFP API IDs
    @{
    @brief API IDs for CFP
*/
#define BRCM_SWARCH_CFP_ADDRULE_PROC           (0x7201U) /**< @brief #CFP_AddRule           */
#define BRCM_SWARCH_CFP_REMOVERULE_PROC        (0x7202U) /**< @brief #CFP_RemoveRule        */
#define BRCM_SWARCH_CFP_ENABLERULE_PROC        (0x7203U) /**< @brief #CFP_EnableRule        */
#define BRCM_SWARCH_CFP_DISABLERULE_PROC       (0x7204U) /**< @brief #CFP_DisableRule       */
#define BRCM_SWARCH_CFP_UPDATEACTION_PROC      (0x7205U) /**< @brief #CFP_UpdateAction      */
#define BRCM_SWARCH_CFP_GETMETERSTATS_PROC     (0x7206U) /**< @brief #CFP_GetMeterStats     */
#define BRCM_SWARCH_CFP_GETRULE_PROC           (0x7207U) /**< @brief #CFP_GetRule           */
#define BRCM_SWARCH_CFP_SETENABLEDPORTS_PROC   (0x7208U) /**< @brief #CFP_SetEnabledPorts   */
#define BRCM_SWARCH_CFP_SETCURRENTSTATEID_PROC (0x7209U) /**< @brief #CFP_SetCurrentStateId */
#define BRCM_SWARCH_CFP_UPDATEMETER_PROC       (0x720AU) /**< @brief #CFP_UpdateMeter       */
#define BRCM_SWARCH_CFP_GETMETERCFG_PROC       (0x720BU) /**< @brief #CFP_GetMeterCfg       */
#define BRCM_SWARCH_CFP_RESETMETERSTATS_PROC   (0x720CU) /**< @brief #CFP_ResetMeterStats   */
#define BRCM_SWARCH_CFP_CONFIGUDF_PROC         (0x720DU) /**< @brief #CFP_ConfigUDF         */
#define BRCM_SWARCH_CFP_GETGLOBALSNAPSHOT_PROC (0x720EU) /**< @brief #CFP_GetGlobalSnapshot */
#define BRCM_SWARCH_CFP_GETRULESSNAPSHOT_PROC  (0x720FU) /**< @brief #CFP_GetRulesSnapshot  */
#define BRCM_SWARCH_CFP_ACKEVENT_PROC          (0x7210U) /**< @brief #CFP_AckEvent          */
/** @} */

/**
    @brief Configure UDF

    This API configures the UDF belonging to the given slice

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aL3Framing          L3 framing format
    @param[in]     aSlice              Slice number (between 0 and #CFP_MAX_SLICES-1)
    @param[in]     aID                 UDF index. Is a number between 0 and
                                       #CFP_MAX_SLICE_UDFS-1
    @param[in]     aBase               UDF base
    @param[in]     aOffset             UDF word (2 byte) offset from given base. This
                                       is a number between 0 and 31

    @retval  #BCM_ERR_OK               UDF configured successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aL3Framing/#aSlice/#aID/#aBase/#aOffset
                                       is invalid
    @retval  #BCM_ERR_NOPERM           #aSlice is disabled or
                                       #aSlice is not being managed by CFP
    @retVal  #BCM_ERR_NOSUPPORT        #aID is not valid for this slice. This
                                       could happen if we are accessing more than
                                       9 UDFs for a slice which is not enabled
                                       for chaining
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_ConfigUDF(BCM_HandleType    aConnHdl,
                             CFP_L3FramingType aL3Framing,
                             CFP_SliceType     aSlice,
                             uint32_t          aID,
                             CFP_UDFBaseType   aBase,
                             uint8_t           aOffset);

/**
    @brief Add a CFP rule

    This API adds a rule to CFP TCAM and returns #aRow and #aSlice. The lookup key
    , action and slice are mandatory to be provided. The user may ask the SDK to
    auto-allocate a row by providing CFP_ROW_INVALID in the aRow parameter. There
    are multiple options for the metering:
    -# If the user wants dedicated policing/metering for this rule, they should provide
       a valid meter configuration and #CFP_METERID_INVALID as the flow meter identifier
       in the action. The SDK will create the meter and the identifier can be retrieved
       using the #CFP_GetRule() API
    -# If the user does not want any policing, they should provide NULL in the #aMeter
       argument and #CFP_METERID_INVALID as the flow meter identifier in the action. The
       SDK will associate a disabled meter with this rule
    -# If the user wants to associate this rule with a meter which was already created
       (with a prior invocation of CFP_AddRule), they should provide NULL in the #aMeter
       argument and a valid flow meter (retrieved using CFP_GetRule()) identifier in the
       action.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[inout]  aRow                Pointer to the requested row number (set to #CFP_ROW_INVALID
                                       to auto-allocate) on input. On output it provides the
                                       configured row number. For IPv6 long rule, this needs to be
                                       an even number (and the very next row needs to be empty). An
                                       IPv6 long rule will consume 2 rows.
    @param[in]     aSlice              Slice number
    @param[in]     aKey                Rule key configuration
    @param[in]     aAction             Rule action configuration
    @param[in]     aMeter              Optional meter configuration,
                                       set to NULL when dedicated policing
                                       is not required

    @retval  #BCM_ERR_OK               Rule added successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aKey/#aAction/#aRow is NULL OR
                                       #aRow or #aSlice is invalid value OR
                                       input UDF has not been configured OR
                                       aMeter is non NULL and aAction.flowMeterId is not CFP_METERID_INVALID
    @retVal  #BCM_ERR_NOT_FOUND        Input flow meter Id is not valid
    @retVal  #BCM_ERR_NOSUPPORT        Requested feature is not supported by
                                       this platform
    @retval  #BCM_ERR_NOMEM            All rows in TCAM are occupied
    @retval  #BCM_ERR_NOPERM           #aRow is occupied or #aRow+1 is not free (only for IPv6 long rule) or
                                       #aRow is not an even number (for IPv6 long rule) or
                                       #aRow is in the region reserved for PSFP or IPMC or
                                       #aSlice is disabled or
                                       #aSlice is not being managed by CFP or
                                       #aSlice is not enabled for IPv6 chaining (for IPv6 long rule)
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_AddRule(BCM_HandleType              aConnHdl,
                           CFP_RowType *const          aRow,
                           CFP_SliceType               aSlice,
                           const CFP_KeyType *const    aKey,
                           const CFP_ActionType *const aAction,
                           const CFP_MeterType *const  aMeter);

/**
    @brief Remove a CFP rule

    This API removes a rule (if it exists). It returns an error in
    case an attempt to delete a static rule is made. In case of an
    IPv6 chain rule, it removes both the rows used for the rule.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aRow                Row number

    @retval  #BCM_ERR_OK               Rule removed successfully
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized
    @retval  #BCM_ERR_NOT_FOUND        No rule configured at #aRow
    @retval  #BCM_ERR_INVAL_PARAMS     #aRow is not valid or
                                       #aRow is not even (only for IPv6 chained rule)
    @retval  #BCM_ERR_NOPERM           #aRow is in PSFP/IPMC region
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_RemoveRule(BCM_HandleType aConnHdl,
                              CFP_RowType    aRow);

/**
    @brief Enable a CFP rule

    This API enables a rule (if it exists)

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aRow                Row number

    @retval  #BCM_ERR_OK               Rule enabled successfully
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized
    @retval  #BCM_ERR_NOT_FOUND        No rule configured at #aRow
    @retval  #BCM_ERR_INVAL_PARAMS     #aRow is not valid
    @retval  #BCM_ERR_NOPERM           #aRow is in PSFP/IPMC region
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_EnableRule(BCM_HandleType aConnHdl,
                              CFP_RowType    aRow);

/**
    @brief Disable a CFP rule

    This API disables a rule (if it exists)

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aRow                Row number

    @retval  #BCM_ERR_OK               Rule disabled successfully
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized
    @retval  #BCM_ERR_NOT_FOUND        No rule configured at #aRow
    @retval  #BCM_ERR_INVAL_PARAMS     #aRow is not valid
    @retval  #BCM_ERR_NOPERM           #aRow is in PSFP/IPMC region
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_DisableRule(BCM_HandleType aConnHdl,
                               CFP_RowType    aRow);

/**
    @brief Update an existing rule's action

    This API updates the action of an existing rule.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aRow                Row number
    @param[in]     aAction             Updated action configuration

    @retval  #BCM_ERR_OK               Rule updated successfully
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized
    @retval  #BCM_ERR_NOT_FOUND        No rule configured at #aRow or
                                       Input flow meter Id is not valid
    @retval  #BCM_ERR_INVAL_PARAMS     #aRow is not a valid row number
                                       #aAction is NULL or has invalid configuration
    @retval  #BCM_ERR_NOPERM           #aRow is in PSFP/IPMC region
    @retVal  #BCM_ERR_NOSUPPORT        Requested feature is not supported by
                                       this platform
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_UpdateAction(BCM_HandleType              aConnHdl,
                                CFP_RowType                 aRow,
                                const CFP_ActionType *const aAction);

/**
    @brief Get configuration for a rule

    This API fetches the configuration for an existing rule

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl         Connection handle (from RPC_Connect)
    @param[in]     aRow             Row number
    @param[out]    aSlice           Slice number
    @param[out]    aKey             Key configuration
    @param[out]    aAction          Action configuration
    @param[out]    aMeter           Meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK            Configuration fetched successfully
    @retval  #BCM_ERR_NOT_FOUND     No rule configured at #aRow
    @retval  #BCM_ERR_INVAL_PARAMS  #aSlice/#aKey/#aAction/#aMeter is NULL or
                                    #aRow is not a valid CFP row
    @retval  #BCM_ERR_NOPERM        #aRow is in PSFP/IPMC region
    @retval  #BCM_ERR_UNINIT        CFP has not been initialized
    @retval  #BCM_ERR_TIME_OUT      Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_GetRule(BCM_HandleType        aConnHdl,
                           CFP_RowType           aRow,
                           CFP_SliceType *const  aSlice,
                           CFP_KeyType *const    aKey,
                           CFP_ActionType *const aAction,
                           CFP_MeterType  *const aMeter);

/**
    @brief Get global snapshot

    This API fetches the global snapshot

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[out]    aSnapshot         Pointer to location to store snapshot

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Snapshot fetched successfully
    @retval  #BCM_ERR_INVAL_PARAMS   #aSnapshot is NULL
    @retval  #BCM_ERR_UNINIT         CFP has not been initialized
    @retval  #BCM_ERR_TIME_OUT       Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_GetGlobalSnapshot(BCM_HandleType                aConnHdl,
                                     CFP_GlobalSnapshotType *const aSnapshot);

/**
    @brief Get rules snapshot

    This API fetches a snippet of the rules present in a section of the CFP table

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[in]     aStartRow         Starting row index. The command fetches
                                     upto #CFP_RULELIST_MAX_RULES from this
                                     index
    @param[out]    aSnapshot         Pointer to location to store snapshot

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Snapshot fetched successfully
    @retval  #BCM_ERR_INVAL_PARAMS   #aSnapshot is NULL or aStartRow is invalid
    @retval  #BCM_ERR_UNINIT         CFP has not been initialized
    @retval  #BCM_ERR_TIME_OUT       Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_GetRulesSnapshot(BCM_HandleType               aConnHdl,
                                    CFP_RowType                  aStartRow,
                                    CFP_RulesSnapshotType *const aSnapshot);

/**
    @brief Set enabled ports

    This API sets the port(s) which are currently enabled for CFP.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPortMask           Bitmap of enabled ports

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK            Enabled ports programmed successfully
    @retval  #BCM_ERR_UNINIT        CFP has not been initialized
    @retval  #BCM_ERR_TIME_OUT      Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_SetEnabledPorts(BCM_HandleType   aConnHdl,
                                   CFP_PortMaskType aPortMask);

/**
    @brief Set current state id

    This API sets the current state id. Based on the state id, the rules
    which do not have the same state-id value programmed in the key will
    be dormant (i.e. will not get hit)

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStateId            State id

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK            State id programmed successfully
    @retval  #BCM_ERR_UNINIT        CFP has not been initialized
    @retval  #BCM_ERR_TIME_OUT      Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_SetCurrentStateId(BCM_HandleType aConnHdl,
                                     uint8_t        aStateId);

/**
    @brief Update meter configuration

    This API updates a meter identified by the input #aId with #aCfg.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aId                 Meter identifier
    @param[in]     aCfg                Meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Meter updated successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aId is an invalid meter identifier OR
                                       #aCfg is NULL
    @retval  #BCM_ERR_NOT_FOUND        No meter configured for #aId
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_UpdateMeter(BCM_HandleType             aConnHdl,
                               CFP_MeterIdType            aId,
                               const CFP_MeterType *const aCfg);

/**
    @brief Fetch the meter configuration

    This API retrieves the meter identified by the input #aId.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aId                 Meter identifier
    @param[out]    aCfg                Meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Meter retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aId is an invalid meter identifier OR
                                       #aCfg is NULL
    @retval  #BCM_ERR_NOT_FOUND        No meter configured for #aId
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_GetMeterCfg(BCM_HandleType       aConnHdl,
                               CFP_MeterIdType      aId,
                               CFP_MeterType *const aCfg);

/**
    @brief Get statistic counters for a meter

    This API fetches the red, yellow and green statistic counters for an
    existing meter

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[in]     aId               Meter identifier
    @param[out]    aStats            Statistics

    @retval  #BCM_ERR_OK             Statistics fetched successfully
    @retval  #BCM_ERR_UNINIT         CFP has not been initialized
    @retval  #BCM_ERR_INVAL_PARAMS   #aId is not a valid meter identifier or
                                     #aStats is NULL
    @retval  #BCM_ERR_NOT_FOUND      No meter configured for #aId
    @retval  #BCM_ERR_TIME_OUT       Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_GetMeterStats(BCM_HandleType            aConnHdl,
                                 CFP_MeterIdType           aId,
                                 CFP_MeterStatsType *const aStats);

/**
    @brief Reset statistic counters for a meter

    This API resets the statistic counters for an existing meter

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[in]     aId               Meter identifier

    @retval  #BCM_ERR_OK             Statistics reset successfully
    @retval  #BCM_ERR_UNINIT         CFP has not been initialized
    @retval  #BCM_ERR_INVAL_PARAMS   #aId is not a valid meter identifier
    @retval  #BCM_ERR_NOT_FOUND      No meter configured for #aId
    @retval  #BCM_ERR_TIME_OUT       Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_ResetMeterStats(BCM_HandleType  aConnHdl,
                                   CFP_MeterIdType aId);

/**
    @brief Acknowledge event on a rule

    This API acknowledges the event reported on a rule. This will re-enable
    the interrupts on the rule so that further events may be reported in the
    future.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aRow                Row number identifying the rule

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Event acknowledged
                                       successfully
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized
    @retval  #BCM_ERR_NOT_FOUND        No rule configured at #aRow
    @retval  #BCM_ERR_INVAL_PARAMS     #aRow is not a valid row number
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFP

    @limitations None
*/
extern int32_t CFP_AckEvent(BCM_HandleType aConnHdl,
                            CFP_RowType    aRow);

#endif /* ETHERNET_CFP_SYNC_H */
/** @} */
