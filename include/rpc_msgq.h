/*****************************************************************************
 Copyright 2021-2022 Broadcom Limited.  All rights reserved.

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

/** @defgroup grp_rpc_msg MSGQ Interface
    @ingroup grp_rpc_abstract

    @addtogroup grp_rpc_msg
    @{

    @file rpc_msgq.h
    @brief RPC Message Interface for Commands/Responses/Notificaions

    @version 1.0 Initial Version
*/

#ifndef RPC_MSGQ_H
#define RPC_MSGQ_H

#include <msg_queue.h>
#include <rpc_msg.h>

/**
    @name RPC Integration Interface IDs
    @{
    @brief Integration Interface IDs for RPC

*/
#define BRCM_SWARCH_RPC_NOTIFY_EVENT_PROC       (0x8500U)   /**< @brief #RPC_NotifyEvent    */
#define BRCM_SWARCH_RPC_SEND_CMD_PROC           (0x8501U)   /**< @brief #RPC_SendCmd        */
#define BRCM_SWARCH_RPC_GET_RESP_PROC           (0x8502U)   /**< @brief #RPC_GetResp        */
/** @} */

/** @brief Send Async Messages to Host

    This API queues the Async Messages to Host

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID                Notification ID
    @param[in]      aBuff              Pointer to the Buffer
    @param[in]      aLen               Length of the message

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Asyc Message is posted successfully
    @retval     #BCM_ERR_NOMEM          Async Queue is Full and cannot be added to queue
    @retval     #BCM_ERR_INVAL_PARAMS   (aBuff is NULL AND aLen is NOT 0) OR
                                        (aBuff is NOT NULL AND aLen is 0) OR
                                        aLen is more than available memory

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_NotifyEvent(BCM_MsgType aID, const uint8_t *const aBuff, uint32_t aLen);

/** @brief Send Command Messages to MsgQ Slave

    This API queues the local Command Messages

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aID                Command ID
    @param[in]     aBuff              Pointer to the Message
    @param[in]     aLen               Length of the message
    @param[in]     aTimeoutMs         Timeout in milliseconds
    @param[in]     aClientMask        Client mask to be set on command completion
    @param[out]    aHdr               Pointer to the message queue header used to
                                      Retrieve the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Asyc Message is posted successfully
    @retval     #BCM_ERR_NOMEM          Async Queue is Full and cannot be added to queue
    @retval     #BCM_ERR_INVAL_PARAMS   aGrpID is invalid or
                                        aCompID is invalid or
                                        aCmdID is invalid or
                                        aLen is 0 or greater than RPC_MSG_PAYLOAD_SZ or
                                        aHdr is NULL or
                                        aBuff is NULL

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_SendCmd(BCM_MsgType aID, const uint8_t *const aBuff, uint32_t aLen, uint32_t aTimeoutMs,
                           uint32_t aClientMask, const BCM_HandleType** const aHdr);

/** @brief Receive Command Message Response from MsgQ Slave

    This API provides the response of the Command

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aHdr             Pointer to the message queue header to
                                    Retrieve the status
    @param[out]    aResponse        Result of the Message Queue command
    @param[in]     aBuff            Pointer to read the message
    @param[out]    aSize            Size of the Message

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Asyc Message is posted successfully
    @retval     #BCM_ERR_NOMEM          Async Queue is Full and cannot be added to queue
    @retval     #BCM_ERR_INVAL_PARAMS   aHdr is NULL or
                                        aResponse is NULL or
                                        aBuff is NULL or
                                        aSize is NULL

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_GetResp(const BCM_HandleType *const aHdr, int32_t * const aResponse,
                           uint8_t *const aBuff, uint32_t * const aSize);

#endif /* RPC_MSGQ_H */
/** @} */
