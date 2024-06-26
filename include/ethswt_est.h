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
    @defgroup grp_ethswt_est_ifc EST Interface
    @ingroup grp_ethswt

    @addtogroup grp_ethswt_est_ifc
    @{

    @file ethswt_est.h
    @brief Application programmer interface for Ethernet Switch Driver (EST)

    @version 0.1 Initial version
 */

#ifndef ETHSWT_EST_H
#define ETHSWT_EST_H

#include <ethernet_est_types.h>
#include <ethernet_swt_common.h>

/**
    @name Ethernet Switch driver API IDs
    @{
    @brief API IDs for  Ethernet Switch driver
*/
#define BRCM_SWARCH_ETHSWT_EST_SETQUEUEMAXSDU_PROC    (0x8A01U)    /**< @brief #ETHSWT_ESTSetQueueMaxSDU */
#define BRCM_SWARCH_ETHSWT_EST_GETQUEUEMAXSDU_PROC    (0x8A02U)    /**< @brief #ETHSWT_ESTGetQueueMaxSDU */
#define BRCM_SWARCH_ETHSWT_EST_GETSTATS_PROC          (0x8A03U)    /**< @brief #ETHSWT_ESTGetStats       */
#define BRCM_SWARCH_ETHSWT_EST_RESETSTATS_PROC        (0x8A04U)    /**< @brief #ETHSWT_ESTResetStats     */
#define BRCM_SWARCH_ETHSWT_EST_GETLIMITS_PROC         (0x8A05U)    /**< @brief #ETHSWT_ESTGetLimits      */
#define BRCM_SWARCH_ETHSWT_EST_SETGATECFG_PROC        (0x8A06U)    /**< @brief #ETHSWT_ESTSetGateCfg     */
#define BRCM_SWARCH_ETHSWT_EST_GETGATECFG_PROC        (0x8A07U)    /**< @brief #ETHSWT_ESTGetGateCfg     */
#define BRCM_SWARCH_ETHSWT_EST_GETGATESTATUS_PROC     (0x8A08U)    /**< @brief #ETHSWT_ESTGetGateStatus  */
#define BRCM_SWARCH_ETHSWT_EST_SETPORTENABLE_PROC     (0x8A09U)    /**< @brief #ETHSWT_ESTSetPortEnable  */
/** @} */

/** @brief Set queue maxSDU

    This function configures the max SDU limit on a queue of a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number
    @param[in]      aQueue                   Egress queue
    @param[in]      aMaxSDU                  Max SDU limit in bytes (value of
                                             0 disables the check)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set/unset the queue maxSDU limit
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID or aQueue is invalid) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTSetQueueMaxSDU(ETHSWT_HwIDType   aSwtID,
                                 ETHSWT_PortIDType aPortID,
                                 ETHSWT_TCType     aQueue,
                                 uint32_t          aMaxSDU);

/** @brief Get queue maxSDU

    This function retrieves the max SDU limit on a queue of a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number
    @param[in]      aQueue                   Egress queue
    @param[out]     aMaxSDU                  Max SDU limit in bytes (value of
                                             0 indicates that the check is disabled)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved the queue maxSDU limit
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID or aQueue is invalid) or
                                        (aMaxSDU is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTGetQueueMaxSDU(ETHSWT_HwIDType   aSwtID,
                                 ETHSWT_PortIDType aPortID,
                                 ETHSWT_TCType     aQueue,
                                 uint32_t *const   aMaxSDU);

/** @brief Get statistics

    This function retrieves the EST statistics of a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number
    @param[out]     aStats                   Statistics


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved the statistics
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is invalid) or
                                        (aStats is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTGetStats(ETHSWT_HwIDType      aSwtID,
                           ETHSWT_PortIDType    aPortID,
                           EST_StatsType *const aStats);

/** @brief Reset statistics

    This function resets the EST statistics of a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully reset the statistics
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is invalid) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTResetStats(ETHSWT_HwIDType   aSwtID,
                             ETHSWT_PortIDType aPortID);

/** @brief Get limits

    This function retrieves the EST limits of a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number
    @param[out]     aLimits                  Limits


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved the limits
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is invalid) or
                                        (aLimits is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTGetLimits(ETHSWT_HwIDType       aSwtID,
                            ETHSWT_PortIDType     aPortID,
                            EST_LimitsType *const aLimits);

/** @brief Set gate configuration

    This function sets the gate configuration of a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number
    @param[in]      aCfg                     Gate configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set the gate configuration
    @retval     #BCM_ERR_BUSY           Previous configuration is pending
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is invalid) or
                                        (aCfg is NULL) or
                                        (Invalid switch index) or
                                        (Invalid configuration)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTSetGateCfg(ETHSWT_HwIDType              aSwtID,
                             ETHSWT_PortIDType            aPortID,
                             const EST_GateCfgType *const aCfg);

/** @brief Get gate configuration

    This function retrieves the gate configuration of a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number
    @param[out]     aCfg                     Gate configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved the gate configuration
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is invalid) or
                                        (aCfg is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTGetGateCfg(ETHSWT_HwIDType        aSwtID,
                             ETHSWT_PortIDType      aPortID,
                             EST_GateCfgType *const aCfg);

/** @brief Get gate status

    This function retrieves the gate status of a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number
    @param[out]     aStatus                  Gate status


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved the gate status
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is invalid) or
                                        (aStatus is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTGetGateStatus(ETHSWT_HwIDType           aSwtID,
                                ETHSWT_PortIDType         aPortID,
                                EST_GateStatusType *const aStatus);

/** @brief Set port enable

    This function enables EST functionality on a given port

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aSwtID                   Switch index
    @param[in]      aPortID                  Switch port number
    @param[in]      aEnable                  Flag indicating whether EST
                                             function is to be enabled (TRUE) or
                                             disabled (FALSE) on the port

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully enabled/disabled EST
                                        functionality on the port
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is invalid) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EST

    @limitations None
*/
int32_t ETHSWT_ESTSetPortEnable(ETHSWT_HwIDType   aSwtID,
                                ETHSWT_PortIDType aPortID,
                                BCM_BoolType      aEnable);

#endif /* ETHSWT_EST_H */

/** @} */
