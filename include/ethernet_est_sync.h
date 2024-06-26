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
    @addtogroup grp_ethernet_est_ifc
    @{

    @file ethernet_est_sync.h

    @brief EST Interface
    This file contains the interfaces for the Ethernet abstract for EST

    @version 1.0 Initial version
*/

#ifndef ETHERNET_EST_SYNC_H
#define ETHERNET_EST_SYNC_H

#include <ethernet_est_types.h>

/**
    @name Ethernet Service EST API IDs
    @{
    @brief API IDs for EST in Ethernet Service
*/
#define BRCM_SWARCH_EST_GETSTATS_PROC           (0x7001U) /**< @brief #EST_GetStats           */
#define BRCM_SWARCH_EST_CLEARSTATS_PROC         (0x7002U) /**< @brief #EST_ClearStats         */
#define BRCM_SWARCH_EST_SETQUEUEMAXSDU_PROC     (0x7003U) /**< @brief #EST_SetQueueMaxSDU     */
#define BRCM_SWARCH_EST_GETQUEUEMAXSDU_PROC     (0x7004U) /**< @brief #EST_GetQueueMaxSDU     */
#define BRCM_SWARCH_EST_SETGATECONFIG_PROC      (0x7005U) /**< @brief #EST_SetGateConfig      */
#define BRCM_SWARCH_EST_GETGATESTATUS_PROC      (0x7006U) /**< @brief #EST_GetGateStatus      */
#define BRCM_SWARCH_EST_GETGATECONFIG_PROC      (0x7007U) /**< @brief #EST_GetGateConfig      */
#define BRCM_SWARCH_EST_GETLIMITS_PROC          (0x7008U) /**< @brief #EST_GetLimits          */
#define BRCM_SWARCH_EST_SETPORTENABLE_PROC      (0x7009U) /**< @brief #EST_SetPortEnable      */
/** @} */

/**
    @brief Set a queue's maximum SDU size

    This API can be used to configure the queue to drop all frames with SDU
    size greater than the input value.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Port number
    @param[in]     aQueue              Queue number
    @param[in]     aMaxSDUSz           Maximum SDU size in bytes

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Queue maxSDU size configured successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aPort/aQueue is invalid

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_SetQueueMaxSDU(BCM_HandleType    aConnHdl,
                                  ETHER_PortIDType  aPort,
                                  ETHER_TCType      aQueue,
                                  uint32_t          aMaxSDUSz);

/**
    @brief Get a queue's maximum SDU size

    This API can be used to retrieve a queue's max SDU

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Port number
    @param[in]     aQueue              Queue number
    @param[out]    aMaxSDUSz           Maximum SDU size in bytes

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Queue maxSDU size configured successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aPort/aQueue is invalid or aMaxSDUSz is NULL

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_GetQueueMaxSDU(BCM_HandleType     aConnHdl,
                                  ETHER_PortIDType   aPort,
                                  ETHER_TCType       aQueue,
                                  uint32_t    *const aMaxSDUSz);

/**
    @brief Set gate configuration

    This API can be used to set the gate configuration

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Port number
    @param[in]     aCfg                Gate configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Gate configured successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aCfg is NULL or
                                       aPort is invalid or
                                       aCfg is invalid (e.g. gate control list
                                       length exceeds system limit)
    @retval  #BCM_ERR_BUSY             A previously triggered configuration
                                       change is still pending.

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_SetGateConfig(BCM_HandleType               aConnHdl,
                                 ETHER_PortIDType             aPort,
                                 const EST_GateCfgType *const aCfg);

/**
    @brief Get gate configuration

    This API can be used to get the gate configuration

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Port number
    @param[out]    aCfg                Gate configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Gate configured retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aCfg is NULL or aPort is invalid

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_GetGateConfig(BCM_HandleType         aConnHdl,
                                 ETHER_PortIDType       aPort,
                                 EST_GateCfgType *const aCfg);

/**
    @brief Retrieve the gate status

    This API can be used to retrieve the gate status

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Port number
    @param[out]    aStatus             Gate status

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Status populated successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aStatus is NULL or aPort is invalid

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_GetGateStatus(BCM_HandleType            aConnHdl,
                                 ETHER_PortIDType          aPort,
                                 EST_GateStatusType *const aStatus);

/**
    @brief Retrieve the statistics

    This API can be used to retrieve the statistics.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Port number
    @param[out]    aStats              Statistics

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Statistics populated successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aStats is NULL or aPort is invalid

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_GetStats(BCM_HandleType       aConnHdl,
                            ETHER_PortIDType     aPort,
                            EST_StatsType *const aStats);

/**
    @brief Clear the statistics

    This API can be used to clear the statistics.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Switch port number

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Statistics cleared successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aPort is invalid

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_ClearStats(BCM_HandleType     aConnHdl,
                              ETHER_PortIDType  aPort);

/**
    @brief Retrieve the limits

    This API can be used to retrieve the limits

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Port number
    @param[out]    aLimits             Limits

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Limits retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aLimits is NULL or aPort is invalid

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_GetLimits(BCM_HandleType        aConnHdl,
                             ETHER_PortIDType      aPort,
                             EST_LimitsType *const aLimits);

/**
    @brief Enable/Disable EST functionality on a port

    This API can be used to enable/disable EST functionality on a port

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPort               Port number
    @param[in]     aEnable             Administrative mode indicating whether the EST
                                       functionality is enabled (1UL) or disabled (0UL)

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               EST enabled/disabled on the port successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aPort is invalid

    @post None

    @trace #BRCM_SWREQ_EST

    @limitations None
*/
extern int32_t EST_SetPortEnable(BCM_HandleType    aConnHdl,
                                 ETHER_PortIDType  aPort,
                                 uint32_t          aEnable);

#endif /* ETHERNET_EST_SYNC_H */
/** @} */
