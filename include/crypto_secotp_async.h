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
    @defgroup grp_crypto_secotp_async SECOTP Asynchronous Interface
    @ingroup grp_crypto_abstract

    @defgroup grp_crypto_secotp_async_ifc Interface
    @ingroup grp_crypto_secotp_async

    @addtogroup grp_crypto_secotp_async_ifc
    @{

    @limitations None

    @file crypto_secotp_async.h
    @brief SECOTP Asynchronous Interface
    This header file contains the interface functions for SECOTP module message queue

    @version 1.0 Initial Version
*/

#ifndef CRYPTO_SECOTP_ASYNC_H
#define CRYPTO_SECOTP_ASYNC_H

#include <crypto_secotp.h>

/**
    @name Crypto SECOTP Architecture IDs
    @{
    @brief Architecture IDs for Crypto SECOTP
*/
#define BRCM_SWARCH_SECOTP_MSG_UNION_TYPE         (0x8701U) /**< @brief #SECOTP_MsgUnionType       */
#define BRCM_SWARCH_SECOTP_MSG_TYPE               (0x8702U) /**< @brief #SECOTP_MsgType            */
#define BRCM_SWARCH_SECOTP_MVK_READ_REQ_PROC      (0x8703U) /**< @brief #SECOTP_MVKReadReq         */
#define BRCM_SWARCH_SECOTP_MVK_WRITE_REQ_PROC     (0x8704U) /**< @brief #SECOTP_MVKWriteReq        */
#define BRCM_SWARCH_SECOTP_GET_REQ_STATUS_PROC    (0x8715U) /**< @brief #SECOTP_GetReqStatus       */
/** @} */

/**
    @brief SECOTP Module Message Union

    @trace #BRCM_SWREQ_SECOTP
*/
typedef union uSECOTP_MsgUnionType {
    SECOTP_MvkMsgType     mvkMsg;                           /**< @brief Public key message           */
    uint32_t              data[SECOTP_MAX_PAYLOAD_SIZE/4];  /**< @brief Data buffer                  */
} SECOTP_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(SECOTP_MsgUnionType, SECOTP_MAX_PAYLOAD_SIZE, SECOTP_MAX_PAYLOAD_SIZE)

/**
    @brief SECOTP Module Message Type

    @trace #BRCM_SWREQ_SECOTP
*/
typedef struct sSECOTP_MsgType {
    uint32_t             magic;           /**< @brief Magic                 */
    SECOTP_CmdIDType     cmd;             /**< @brief Command ID            */
    uint32_t             cmdLen;          /**< @brief Command length        */
    int32_t              status;          /**< @brief Message status        */
    SECOTP_MsgUnionType  u;               /**< @brief Message union         */
} SECOTP_MsgType;
BCM_STATIC_SIZE_ASSERT(SECOTP_MsgType, 280UL, 280UL)

/** @brief SECOTP MVK Key Read Request

    This API sends MVK Key read request to SECOTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             SECOTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #SECOTP_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into SECOTP module message queue

    @trace #BRCM_SWREQ_SECOTP

    @limitations None
*/
int32_t SECOTP_MVKReadReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief SECOTP MVK Key Write Request

    This API sends write MVK Key request to SECOTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status
    @param[in]      aMVKMsg                Pointer to the array of data to be written

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             SECOTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #SECOTP_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aMVKMsg is NULL

    @post The message is posted into SECOTP module message queue

    @trace #BRCM_SWREQ_SECOTP

    @limitations None
*/
int32_t SECOTP_MVKWriteReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl, SECOTP_MvkMsgType *aMVKMsg);

/** @brief Retreive status of SECOTP Async Request

    This API queries the status of completed SECOTP commands which were
    previously issued

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aHandle                BCM Handle to retrieve response
    @param[out]  aReplyData             Pointer to the reply data payload

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command status retrieved successfully
    @retval     #BCM_ERR_BUSY              Command is in-progress
    @retval     #BCM_ERR_INVAL_PARAMS      aHandle is invalid

    @post None

    @trace #BRCM_SWREQ_SECOTP

    @limitations None
*/
int32_t SECOTP_GetReqStatus(BCM_HandleType aHandle, SECOTP_MsgUnionType *aReplyData);

#endif /* CRYPTO_SECOTP_ASYNC_H */

/** @} */
