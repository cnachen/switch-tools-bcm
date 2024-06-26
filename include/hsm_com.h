/*****************************************************************************
 Copyright 2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_hsmcom_ifc Interface
    @ingroup grp_hsmcom

    @addtogroup grp_hsmcom_ifc
    @{
    @section sec_hsmcom_overview Overview

    @file hsmcom.h

    @brief Application Programmer Interface for HSM Communication module

    This header file contains the APIs for HSM Communication module

    @version 0.1 Initial revision
*/

#ifndef HSM_COM_H
#define HSM_COM_H

#include <module.h>
#include <bcm_err.h>
#include <rpc_msg.h>

/**
    @name HSM COM API IDs
    @{
    @brief API IDs for HSM Communication module
*/
#define BRCM_SWARCH_HSMC_CMD_POOL_SIZE_LOG2_MACRO  (0x8000U) /**< @brief #HSMC_CMD_POOL_SIZE_LOG2 */
#define BRCM_SWARCH_HSMC_CMD_POOL_SIZE_MACRO       (0x8001U) /**< @brief #HSMC_CMD_POOL_SIZE      */
#define BRCM_SWARCH_HSMC_SEND_CMD_PROC             (0x8002U) /**< @brief #HSMC_SendCmd            */
#define BRCM_SWARCH_HSMC_GET_RESPONSE_PROC         (0x8003U) /**< @brief #HSMC_GetResponse        */
#define BRCM_SWARCH_HSMC_CMD_HANDLE_TYPE           (0x8004U) /**< @brief #HSMC_CmdHandleType      */
#define BRCM_SWARCH_HSMC_TO_HSM_ADDR_PROC          (0x8005U) /**< @brief #HSMC_ToHsmAddr          */
#define BRCM_SWARCH_HSMC_FROM_HSM_ADDR_PROC        (0x8006U) /**< @brief #HSMC_FromHsmAddr        */
/** @} */

/**
    @brief Command pool size

    Number of slots to be allocated for storing the command/response.
    Can be changed using build time constant.

    @trace #BRCM_SWREQ_HSMC_MODULE_IPC
*/
#ifndef HSMC_CMD_POOL_SIZE_LOG2
#define HSMC_CMD_POOL_SIZE_LOG2         (2UL)
#endif

/**
    @brief Command pool size

    Number of slots to be allocated for storing the command/response.
    Can be changed using build time constant.

    @trace #BRCM_SWREQ_HSMC_MODULE_IPC
*/
#define HSMC_CMD_POOL_SIZE         (1UL << HSMC_CMD_POOL_SIZE_LOG2)


/**
    @name HSMC Command Handle type
    @{
    @brief HSMC Command Handle type

    @trace #BRCM_SWREQ_HSMC_MODULE_IPC
*/
typedef BCM_HandleType HSMC_CmdHandleType;
#define HSMC_CMD_HANDLE_INVALID    (0ULL)
/** @} */

/** @brief Send command to HSM processor

    Sends the given command to the HSM processor. The returned handle
    can be used for retrieving the response.

    @behavior Sync, Non-reentrant

    @param[in]      aRpcMsg             RPC Message structure
    @param[in]      aEvntMask           Event to be triggered on reception of the response
    @param[out]     aHandle             Pointer to HSMC_CmdHandleType for later query
                                        using #HSMC_GetResponse()

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNINIT         HSMC not yet initialized
    @retval     #BCM_ERR_INVAL_PARAMS   aCmdData or aHandle is NULL
    @retval     #BCM_ERR_NOMEM          No slots available to send the message
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post Command information is posted to the HSMC module

    @trace #BRCM_SWREQ_HSMC_MODULE_IPC

    @limitations None
*/
int32_t HSMC_SendCmd(RPC_MsgType const *aRpcMsg,
                     uint32_t aEvntMask,
                     HSMC_CmdHandleType *aHandle);

/** @brief Get response from HSM processor

    Get response from the HSM processor for the previously sent command.

    @behavior Sync, Non-reentrant

    @param[in]      aHandle      Command handle returned by the #HSMC_SendCmd()
    @param[out]     aMsg         Response message

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNINIT         HSMC not yet initialized
    @retval     #BCM_ERR_INVAL_PARAMS   aHandle is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aMsg is NULL
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @trace #BRCM_SWREQ_HSMC_MODULE_IPC

    @limitations None
*/
int32_t HSMC_GetResponse(HSMC_CmdHandleType aHandle,
                         RPC_MsgType *aMsg);

/** @brief Translate an APP subsystem address to a HSM subsystem address

    @behavior Sync, Reentrant

    @param[in]      aAddr        APP subsystem address
    @param[out]     aHsmAddr     HSM subsystem address

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aHsmAddr is NULL
    @retval     #BCM_ERR_INVAL_PARAMS   aAddr is not a valid APP subsystem address

    @trace #BRCM_SWREQ_HSMC_MODULE_IPC

    @limitations None
*/
int32_t HSMC_ToHsmAddr(const size_t aAddr, size_t *aHsmAddr);

/** @brief Translate a HSM subsystem address into an APP subsystem address

    @behavior Sync, Reentrant

    @param[in]      aHsmAddr     HSM subsystem address
    @param[out]     aAddr        APP subsystem address

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aHsmAddr is NULL
    @retval     #BCM_ERR_INVAL_PARAMS   aHsmAddr cannot be translated into an APP address

    @trace #BRCM_SWREQ_HSMC_MODULE_IPC

    @limitations None
*/
int32_t HSMC_FromHsmAddr(const size_t aHsmAddr, size_t *aAddr);

#endif /* HSM_COM_H */
/** @} */
