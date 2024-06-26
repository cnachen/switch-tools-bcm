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
    @defgroup grp_socket_net_ifc Network Layer Interface
    @ingroup grp_socket

    @addtogroup grp_socket_net_ifc
    @{
    @file socket_net.h

    @brief Socket Network Layer Interface

    This file defines APIs for integrating the socket to the
    network layer

    @version 0.1 Initial revision
*/
#ifndef SOCKET_NET_H
#define SOCKET_NET_H

#include <socket.h>

/**
    @name Socket abstraction Architecture IDs
    @{
    @brief Architecture IDs for Socket abstraction
*/
#define BRCM_SWARCH_SOCK_READ_MSG_PROC            (0x8101U) /**< @brief #SOCK_ReadMsg          */
#define BRCM_SWARCH_SOCK_READ_DATA_PROC           (0x8102U) /**< @brief #SOCK_ReadData         */
#define BRCM_SWARCH_SOCK_WRITE_MSG_PROC           (0x8103U) /**< @brief #SOCK_WriteMsg         */
#define BRCM_SWARCH_SOCK_WRITE_DATA_PROC          (0x8104U) /**< @brief #SOCK_WriteData        */
#define BRCM_SWARCH_SOCK_RSRV_CONNECTION_PROC     (0x8105U) /**< @brief #SOCK_RsrvConnection   */
#define BRCM_SWARCH_SOCK_RELEASE_CONNECTION_PROC  (0x8106U) /**< @brief #SOCK_ReleaseConnection*/
#define BRCM_SWARCH_SOCK_GET_BUFF_STATUS_PROC     (0x8107U) /**< @brief #SOCK_GetBuffStatus    */
/** @} */

/** @brief Read a message from user task

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aSock    Socket structure
    @param[in]      aHdl     Connection Handle
    @param[out]     aMsgInfo Pointer to store the message details.
                             If NULL, message details is not read out.
    @param[in]      aConsume 1 = The message to be dequeued,
                             0 = The message shall stay in the queue
    @param[out]     aMoreMsg More messages are available in the queue

    @retval     #BCM_ERR_OK           Message read successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock NULL or aHdl in invalid
    @retval     #BCM_ERR_NOT_FOUND    No messages found

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_ReadMsg(SOCK_Type const * const aSock,
                     SOCK_ConnHdlType aHdl,
                     SOCK_MsgInfoType * const aMsgInfo,
                     uint32_t aConsume,
                     uint32_t *aMoreMsg);

/** @brief Write a message to the user task

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aSock    Socket structure
    @param[in]      aHdl     Connection Handle
    @param[in]      aMsgInfo Message information

    @retval     #BCM_ERR_OK           Data write successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aData or aSize is NULL
                                      or aHdl is invalid
    @retval     #BCM_ERR_NOMEM        Message queue is full. Try again
                                      on next event.

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_WriteMsg(SOCK_Type const * const aSock,
                      SOCK_ConnHdlType aHdl,
                      SOCK_MsgInfoType const * const aMsgInfo);

/** @brief Read the data from the data queue

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aSock     Socket structure
    @param[in]      aHdl      Connection Handle
    @param[in]      aOffset   Offset from top of the queue
    @param[out]     aData     Buffer to store the read data,
                              If NULL, the data content is not read out
    @param[inout]   aSize     in: Size of the buffer,
                              out: Number of bytes actually read
    @param[in]      aConsume  1 = Dequeue the data till (aOffset + aSize),
                              0 = The data shall stay in the queue
    @param[out]     aMoreData More data available in the queue. If this info
                              is not needed this can be set to NULL

    @retval     #BCM_ERR_OK           Data read successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aData or aSize is NULL
                                      or aHdl is invalid
    @retval     #BCM_ERR_NODEV        Connection closed by the other side

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_ReadData(SOCK_Type const * const aSock,
                      SOCK_ConnHdlType aHdl,
                      uint32_t aOffset,
                      uint8_t * const aData,
                      uint32_t * const aSize,
                      uint32_t aConsume,
                      uint32_t * const aMoreData);

/** @brief Write the given data to the queue

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aSock    Socket structure
    @param[in]      aHdl     Connection handle
    @param[out]     aData    Data to be written
    @param[inout]   aSize    In: Number of bytes in the data buffer,
                             Out: Actual number of bytes written

    @retval     #BCM_ERR_OK           Data write successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aData or aSize is NULL
                                      or aHdl is invalid
    @retval     #BCM_ERR_NOMEM        Socket write buffer is full

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_WriteData(SOCK_Type const * const aSock,
                       SOCK_ConnHdlType aHdl,
                       uint8_t const * const aData,
                       uint32_t * const aSize);

/** @brief Get data buffer status

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aSock           Socket structure
    @param[in]      aHdl            Connection handle
    @param[out]     aFreeWriteSize  Number of bytes free in the write buffer
    @param[inout]   aFilledReadSize Number of bytes filled in the read buffer

    @retval     #BCM_ERR_OK           Buffer size updated successfully
    @retval     #BCM_ERR_INVAL_PARAMS aSock is NULL or aHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_GetBuffStatus(SOCK_Type const * const aSock,
                           SOCK_ConnHdlType aHdl,
                           uint32_t * const aFreeWriteSize,
                           uint32_t * const aFilledReadSize);

/** @brief Reserve new connection

    Reserves a new connection from the socket and retrunes the
    handle and connection id.

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aSock    Socket structure
    @param[out]     aHdl     Connection handle
    @param[out]     aNewHdl  New connection handle reserved

    @retval     #BCM_ERR_OK           New connection reserved
    @retval     #BCM_ERR_NOMEM        No free connections available
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aHdl or aConnId is NULL

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_RsrvConnection(SOCK_Type const * const aSock,
                            SOCK_ConnHdlType aHdl,
                            SOCK_ConnHdlType *aNewHdl);

/** @brief Release connection

    Release an already reserved connection if the connect
    message is not propagated to the user task.

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aSock    Socket structure
    @param[out]     aHdl     Connection handle to be released

    @retval     #BCM_ERR_OK           Connection released successfully
    @retval     #BCM_ERR_INVAL_PARAMS aSock is NULL or aHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_ReleaseConnection(SOCK_Type const * const aSock,
                               SOCK_ConnHdlType aHdl);

#endif /* SOCKET_NET_H */

/** @} */
