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
    @defgroup grp_rpc_msg_ifc RPC Message Interface
    @ingroup grp_rpc_abstract

    @addtogroup grp_rpc_msg_ifc
    @{

    @file rpc_msg.h
    @brief RPC common interface for messages

    @version 0.1 Initial Version
*/

#ifndef RPC_MSG_H
#define RPC_MSG_H

#include <stdint.h>
#include <bcm_err.h>
#include <bcm_comp.h>
#include <bcm_utils.h>
#include <socket.h>

/**
    @name RPC Common Architecture IDs
    @{
    @brief Architecture IDs for RPC Common
*/
#define BRCM_SWARCH_RPC_MAX_CNT_MACRO                   (0x8301U)    /**< @brief #RPC_MAX_CNT_MSG      */
#define BRCM_SWARCH_RPC_MSG_VER_TYPE                    (0x8303U)    /**< @brief #RPC_MsgVerType       */
#define BRCM_SWARCH_RPC_MSG_MAGIC_MACRO                 (0x8304U)    /**< @brief #RPC_MSG_MAGIC        */
#define BRCM_SWARCH_RPC_MEM_MSG_TYPE                    (0x8305U)    /**< @brief #RPC_MsgType          */
#define BRCM_SWARCH_RPC_OPEN_PROC                       (0x8306U)    /**< @brief #RPC_Open             */
#define BRCM_SWARCH_RPC_SEND_PROC                       (0x8307U)    /**< @brief #RPC_Send             */
#define BRCM_SWARCH_RPC_RECV_PROC                       (0x8308U)    /**< @brief #RPC_Recv             */
#define BRCM_SWARCH_RPC_SENDRECV_PROC                   (0x8309U)    /**< @brief #RPC_SendRecv         */
#define BRCM_SWARCH_RPC_CLOSE_PROC                      (0x830AU)    /**< @brief #RPC_Close            */
#define BRCM_SWARCH_RPC_MSGPUSHPAPPINFO_PROC            (0x8322U)    /**< @brief #RPC_MsgPushAppInfo   */
#define BRCM_SWARCH_RPC_MSGPOPPAPPINFO_PROC             (0x8323U)    /**< @brief #RPC_MsgPopAppInfo    */
#define BRCM_SWARCH_RPC_MSGPEEKAPPINFO_PROC             (0x831DU)    /**< @brief #RPC_MsgPeekAppInfo   */
#define BRCM_SWARCH_RPC_MSGINIT_PROC                    (0x8324U)    /**< @brief #RPC_MsgInit          */
#define BRCM_SWARCH_RPC_MSG_SIZE_MACRO                  (0x8326U)    /**< @brief #RPC_MSG_HEADER_SIZE  */
#define BRCM_SWARCH_RPC_STREAM_VERSION_TYPE             (0x8327U)    /**< @brief #RPC_StreamVersionType*/
#define BRCM_SWARCH_RPC_GET_IMAGE_BUFFER_PROC           (0x8328U)    /**< @brief #RPC_GetImgBuffer     */
#define BRCM_SWARCH_RPC_MSG_INFO_V10_TYPE               (0x8329U)    /**< @brief #RPC_MsgInfoV10Type   */
#define BRCM_SWARCH_RPC_MSG_INFO_V11_TYPE               (0x832AU)    /**< @brief #RPC_MsgInfoV11Type   */
#define BRCM_SWARCH_RPC_MSG_INFO_TYPE                   (0x832BU)    /**< @brief #RPC_MsgInfoType      */
#define BRCM_SWARCH_RPC_MSG_PROCESS_TYPE                (0x832CU)    /**< @brief #RPC_MsgProcessType   */
#define BRCM_SWARCH_RPC_GETNOTIFICATION_PROC            (0x832DU)    /**< @brief #RPC_GetNotification  */
#define BRCM_SWARCH_RPC_PROCESSEVENT_PROC               (0x832EU)    /**< @brief #RPC_ProcessEvent     */
#define BRCM_SWARCH_RPC_EVENT_TYPE                      (0x832FU)    /**< @brief #RPC_EventType        */

#define BRCM_SWARCH_RPC_SOCKET_GLOBAL                   (0x8340U)   /**< @brief #RPC_Socket            */
#define BRCM_SWARCH_RPC_SOCKET_NAME_MACRO               (0x8341U)   /**< @brief #RPC_SOCKET_NAME       */
#define BRCM_SWARCH_RPC_SENDV2_PROC                     (0x8342U)   /**< @brief #RPC_SendV2            */
#define BRCM_SWARCH_RPC_SENDRECVV2_PROC                 (0x8343U)   /**< @brief #RPC_SendRecvV2        */
/** @} */

/**
    @brief Slave socket name for clients to communicate

    @trace #BRCM_SWREQ_RPC
*/
#define RPC_SOCKET_NAME            "/tmp/bcm_rpc_socket"


/**
    @brief Slave socket for clients to communicate

    @trace #BRCM_SWREQ_RPC
*/
extern const SOCK_Type RPC_Socket;

/**
    @name RPC Memory Max counts
    @{
    @brief RPC Memory Max Counts

    @trace #BRCM_SWREQ_RPC
*/
#define RPC_MAX_CNT_MSG     (32UL)        /**< @brief Max Messages         */
#define RPC_MAX_CNT_APPINFO (4UL)         /**< @brief Max Appinfo per hdl  */
/** @} */

/**
    @name RPC Message Version Type
    @{
    @brief RPC Message Version Type

    @trace #BRCM_SWREQ_RPC
*/
typedef uint32_t RPC_MsgVerType;            /**< @brief RPC Message Version Type    */
#define RPC_MSG_VER_MINOR_MASK  (0xFFUL)    /**< @brief Mask for Index in the pool  */
#define RPC_MSG_VER_MINOR_SHIFT (0UL)       /**< @brief Shift for Index in the pool */
#define RPC_MSG_VER_MAJOR_MASK  (0xFF00UL)  /**< @brief Mask for Index in the pool  */
#define RPC_MSG_VER_MAJOR_SHIFT (8UL)       /**< @brief Shift for Index in the pool */
#define RPC_MSG_VER_LEGACY      (0UL)       /**< @brief Legacy message type         */
#define RPC_MSG_VER_1_0         (0x0100UL)  /**< @brief Version 1.0                 */
#define RPC_MSG_VER_1_1         (0x0101UL)  /**< @brief Version 1.1 (This version
                                                 shall use message info struct
                                                 #RPC_MsgInfoV11Type)               */
/** @} */

/**
    @brief Magic for RPC_MsgType

    @trace #BRCM_SWREQ_RPC
*/
#define RPC_MSG_MAGIC        (0x5250434DUL)

/**
    @brief RPC Message Info for version 1.0

    @trace #BRCM_SWREQ_RPC
*/
typedef struct sRPC_MsgInfoV10Type {
    uint32_t        appInfoTop;     /**< @brief appinfo top position        */
    uint32_t        appInfo[RPC_MAX_CNT_APPINFO];
                                    /**< @brief Application Information     */
    uint32_t        rsvd;           /**< @brief Reserved field used in RPC  */
} RPC_MsgInfoV10Type;
BCM_STATIC_SIZE_ASSERT(RPC_MsgInfoV10Type, 24UL, 24UL)

/**
    @name RPC Message Recepient/Process Type
    @{

    @trace #BRCM_SWREQ_RPC
*/
typedef uint32_t RPC_MsgProcessType;            /**< @brief RPC Message Process Type    */
#define RPC_MSG_PROCESS_FORWARD    (0x0UL)      /**< @brief Message to be forwarded     */
#define RPC_MSG_PROCESS_SELF       (0x1UL)      /**< @brief Message to be handled       */
/** @} */


/**
    @brief RPC Message Info for version 1.1

    @trace #BRCM_SWREQ_RPC
*/
typedef struct sRPC_MsgInfoV11Type {
    uint64_t             handle;         /**< @brief User handle                 */
    RPC_MsgProcessType   process;        /**< @brief Intended recepient for cmd  */
    uint8_t              rsvd[12];       /**< @brief Reserved field used in RPC  */
} RPC_MsgInfoV11Type;
BCM_STATIC_SIZE_ASSERT(RPC_MsgInfoV11Type, 24UL, 24UL)

/**
    @brief RPC Message info union

    This is the union used to access a message information based on the
    version of the message

    @trace #BRCM_SWREQ_RPC
 */
typedef union uRPC_MsgInfoType {
    RPC_MsgInfoV10Type v10; /**< @brief Msg Info for v10 command */
    RPC_MsgInfoV11Type v11; /**< @brief Msg Info for v11 command */
} RPC_MsgInfoType;
BCM_STATIC_SIZE_ASSERT(RPC_MsgInfoType, 24UL, 24UL)

/**
    @brief RPC Message Type

    'appinfo' stores the received application magic
    and use the same when it send the response.

    @todo Temporary name to avoid conflict with existing code.
    To be changed to RPC_MsgType later

    @trace #BRCM_SWREQ_RPC
*/
typedef struct sRPC_MsgType {
    uint32_t        magic;          /**< @brief magic holding RPCM ASCII    */
    RPC_MsgVerType  version;        /**< @brief Version                     */
    BCM_MsgType     cmd;            /**< @brief Command ID                  */
    uint32_t        timeoutMs;      /**< @brief Timeout value in ms         */
    int32_t         response;       /**< @brief Response Code               */
    uint32_t        len;            /**< @brief Command payload length      */
    RPC_MsgInfoType u;              /**< @brief Msg info union              */
    uint8_t         payload[RPC_MSG_PAYLOAD_SZ];  /**< @brief Payload       */
} RPC_MsgType;
BCM_STATIC_SIZE_ASSERT(RPC_MsgType, 496UL, 496UL)

/**
    @brief Size of Message header

    @trace #BRCM_SWREQ_RPC
*/
#define RPC_MSG_HEADER_SIZE      (sizeof(RPC_MsgType) - RPC_MSG_PAYLOAD_SZ)

/**
    @name RPC Stream version type
    @{
    @brief RPC Stream version
    @trace #BRCM_SWREQ_RPC
*/
typedef uint32_t RPC_StreamVersionType;
#define RPC_STREAM_VERSION_INVALID        (0x0UL)  /**< @brief invalid */
#define RPC_STREAM_VERSION_1              (0x1UL)  /**< @brief Legacy  */
#define RPC_STREAM_VERSION_2              (0x2UL)  /**< @brief V2      */
/** @} */

/**
    @name RPC Event Type
    @{
    @brief RPC Event Type

    @trace #BRCM_SWREQ_RPC
*/
typedef uint32_t RPC_EventType;                                                 /**< @brief RPC event Type                    */
#define RPC_EVENT_RESPONSE_SHIFT         (0x0UL)                                /**< @brief Shift for response detected event */
#define RPC_EVENT_RESPONSE_MASK          (0x1UL << RPC_EVENT_RESPONSE_SHIFT)    /**< @brief Mask for response detected event  */
#define RPC_EVENT_NOTIFICATION_SHIFT     (0x1UL)                                /**< @brief Shift for response detected event */
#define RPC_EVENT_NOTIFICATION_MASK      (0x1UL << RPC_EVENT_RESPONSE_SHIFT)    /**< @brief Mask for response detected event  */
/** @} */

/** @brief Init RPC Message

    @behavior Sync, Non-reentrant

    @pre None

    @param[in/out]      aMsg        Message Pointer

    Return values are documented in reverse-chronological order
    @retval    void

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern void RPC_MsgInit(RPC_MsgType* aMsg);

/** @brief Push AppInfo

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aMsg        Message Pointer
    @param[in]      aAppInfo    AppInfo to add

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully pushed
    @retval     #BCM_ERR_NOMEM          No space in APP Info
    @retval     #BCM_ERR_INVAL_PARAMS   aMsg is NULL or invalid version

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_MsgPushAppInfo(RPC_MsgType* aMsg, uint32_t aAppInfo);

/** @brief Pop AppInfo

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aMsg        Message Pointer
    @param[out]     aAppInfo    Pointer to retrieve AppInfo

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved
    @retval     #BCM_ERR_INVAL_PARAMS   (aMsg is NULL) or
                                        aAppInfo is NULL or
                                        invalid version

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_MsgPopAppInfo(RPC_MsgType* aMsg, uint32_t *aAppInfo);

/** @brief Peek AppInfo

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aMsg        Message pointer
    @param[out]     aAppInfo    Pointer to retrieve AppInfo

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved
    @retval     #BCM_ERR_NOMEM          Nothing left to retrieve
    @retval     #BCM_ERR_INVAL_PARAMS   (aMsg is NULL) or
                                        aAppInfo is NULL or
                                        invalid version

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_MsgPeekAppInfo(RPC_MsgType *aMsg, uint32_t *aAppInfo);

/**
    @brief Connect to the Communication Interface

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aSockName   Socket name for local socket
                                OR IP address as string
    @param[in]      aPort       Port number (used for network socket)
    @param[in]      aTimeout    Timeout for all commands in milliseconds (for Future use)
    @param[out]     aHdl        Connection handle

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Connected
    @retval         #BCM_ERR_UNKNOWN         Unable to connect
    @retval         #BCM_ERR_INVAL_PARAMS    aSockName is NULL or aHdl is NULL

    @post Connection is Established on success

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_Open(const uint8_t *aSockName, uint16_t aPort,
                        uint32_t aTimeoutMs, BCM_HandleType *aHdl);

/**
    @brief Send Message

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aCmd            Command
    @param[in]      aMsg            Message buffer
    @param[in]      aSize           Size of the Message

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Data send successful
    @retval         #BCM_ERR_NOMEM           No memory. Retry later
    @retval         #BCM_ERR_NODEV           Connection lost
    @retval         #BCM_ERR_INVAL_PARAMS    aHdl is 0 or (aMsg is NULL and aSize is not zero)
                                             or aHdl is not pointing to a valid context

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_Send(BCM_HandleType aHdl, BCM_MsgType aCmd,
                           const uint8_t *aMsg, uint32_t aSize);

/**
    @brief Send Message V2

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aCmd            Command
    @param[in]      aVersion        RPC Message version
    @param[in]      aProcess        RPC Message Recepient/Process
    @param[in]      aMsg            Message buffer
    @param[in]      aSize           Size of the Message

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Data send successful
    @retval         #BCM_ERR_NOMEM           No memory. Retry later
    @retval         #BCM_ERR_NODEV           Connection lost
    @retval         #BCM_ERR_INVAL_PARAMS    aHdl is 0 or (aMsg is NULL and aSize is not zero)
                                             or aHdl is not pointing to a valid context
                                             or aVersion is invalid
                                             or aProcess is invalid

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_SendV2(BCM_HandleType aHdl, BCM_MsgType aCmd,
                          const RPC_MsgVerType  aVersion,
                          const RPC_MsgProcessType   aProcess,
                          const uint8_t *aMsg, uint32_t aSize);

/**
    @brief Receive Message

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[out]     aMsg            Message buffer
    @param[inout]   aSize           in  : Size of the Message expected
                                    out : Size of the Message received

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Data Received successfully
    @retval         #BCM_ERR_NOMEM           No data. Retry later
    @retval         #BCM_ERR_NODEV           Connection lost
    @retval         #BCM_ERR_INVAL_MAGIC     Data received with invalid magic
                                             (May need to close and reconnect as connection might
                                             have gone out of sync)
    @retval         #BCM_ERR_INVAL_PARAMS    aHdl is 0 or aMsg is NULL or aSize is NULL
                                             or aHdl is not pointing to a valid context

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_Recv(BCM_HandleType aHdl,
                            uint8_t * const aMsg,
                            uint32_t * const aSize);

/**
    @brief Send and Receive the Message

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aCmd            Command
    @param[in]      aInMsg          In Message
    @param[out]     aInLen          In Message Length
    @param[in]      aOutMsg         Out Message
    @param[inout]   aOutLen         in  : Size of the Message expected
                                    out : Size of the Message received

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Data send successful
    @retval         #BCM_ERR_BUSY            Busy, Retry later
    @retval         #BCM_ERR_NODEV           Connection lost
    @retval         #BCM_ERR_INVAL_MAGIC     Data received with invalid magic
                                             (May need to close and reconnect as connection might
                                             have gone out of sync)
    @retval         #BCM_ERR_INVAL_PARAMS    aHdl is 0 or (aInMsg is NULL and aInLen is not zero)
                                             or (aOutMsg is NULL or aOutLen is NULL)
                                             or aHdl is not pointing to a valid context

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_SendRecv (BCM_HandleType aHdl,
                                BCM_MsgType aCmd,
                                const uint8_t *aInMsg,
                                uint32_t aInLen,
                                uint8_t * const aOutMsg,
                                uint32_t * const aOutLen);

/**
    @brief Send and Receive the Message V2

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aCmd            Command
    @param[in]      aVersion        RPC Message version
    @param[in]      aProcess        RPC Message Recepient/Process
    @param[in]      aInMsg          In Message
    @param[out]     aInLen          In Message Length
    @param[in]      aOutMsg         Out Message
    @param[inout]   aOutLen         in  : Size of the Message expected
                                    out : Size of the Message received

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Data send successful
    @retval         #BCM_ERR_BUSY            Busy, Retry later
    @retval         #BCM_ERR_NODEV           Connection lost
    @retval         #BCM_ERR_INVAL_MAGIC     Data received with invalid magic
                                             (May need to close and reconnect as connection might
                                             have gone out of sync)
    @retval         #BCM_ERR_INVAL_PARAMS    aHdl is 0 or (aInMsg is NULL and aInLen is not zero)
                                             or (aOutMsg is NULL or aOutLen is NULL)
                                             or aHdl is not pointing to a valid context
                                             or aVersion is invalid
                                             or aProcess is invalid

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_SendRecvV2 (BCM_HandleType aHdl,
                               BCM_MsgType aCmd,
                               const RPC_MsgVerType  aVersion,
                               const RPC_MsgProcessType   aProcess,
                               const uint8_t *aInMsg,
                               uint32_t aInLen,
                               uint8_t * const aOutMsg,
                               uint32_t * const aOutLen);

/**
    @brief Get the notification got from target

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[out]     aMsg            Pointer to notification message

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Notification message fetch successful
    @retval         #BCM_ERR_NOT_FOUND       No notification message found
    @retval         #BCM_ERR_INVAL_PARAMS    aMsg is NULL or aHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_GetNotification (BCM_HandleType aHdl, RPC_MsgType *aMsg);

/**
    @brief Process an event

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)

    Return values are documented in reverse-chronological order
    @retval         #RPC_EventType  Bit mask of events detected
                                    Indicates where response and/or
                                    Notifications is available for
                                    processing

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern RPC_EventType RPC_ProcessEvent(BCM_HandleType aHdl);

/**
    @brief DisConnect From the Communication Interface

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)

    Return values are documented in reverse-chronological order
    @retval     BCM_ERR_OK              DisConnected
    @retval     BCM_ERR_INVAL_PARAMS    aHdl is NULL or
                                        aHdl is 0
    @retval     BCM_ERR_CUSTOM          Failed to DisConnect

    @post Connection is DisConnected

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_Close(BCM_HandleType aHdl);

/**
    @brief Retrive the image buffer address

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aBuff           Pointer to the buffer address to fetch
    @param[in]      aSize           Pointer to get the size of the buffer

    Return values are documented in reverse-chronological order
    @retval     BCM_ERR_OK              DisConnected
    @retval     BCM_ERR_INVAL_PARAMS    aBuff is NULL or
                                        aSize is NULL

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_GetImgBuffer(const uint8_t **aBuff,
                                uint32_t *const aSize);

#endif /* RPC_MSG_H */
/** @} */
