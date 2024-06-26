/*****************************************************************************
 Copyright 20220-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_socket_ifc Interface
    @ingroup grp_socket

    @addtogroup grp_socket_ifc
    @{
    @file socket.h

    @brief Socket Interface

    @version 0.1 Initial revision
*/
#ifndef SOCKET_H
#define SOCKET_H

#include <stddef.h>
#include <inttypes.h>
#include <compiler.h>
#include <bcm_comp.h>
#include <bcm_err.h>

/**
    @name Socket abstraction Architecture IDs
    @{
    @brief Architecture IDs for Socket abstraction
*/
#define BRCM_SWARCH_SOCK_STATE_TYPE              (0x8000U) /**< @brief #SOCK_StateType          */
#define BRCM_SWARCH_SOCK_CONN_TYPE               (0x8001U) /**< @brief #SOCK_ConnectionType     */
#define BRCM_SWARCH_SOCK_LINGERTIME_TYPE         (0x8002U) /**< @brief #SOCK_LingerTimeType     */
#define BRCM_SWARCH_SOCK_CONN_MSG_TYPE           (0x8003U) /**< @brief #SOCK_ConnMsgType        */
#define BRCM_SWARCH_SOCK_CIRCQ_FLAG_T_TYPE       (0x8004U) /**< @brief #SOCK_CircQFlagType      */
#define BRCM_SWARCH_SOCK_CHANNEL_NUM_TYPE        (0x8005U) /**< @brief #SOCK_ChannelNumType     */
#define BRCM_SWARCH_SOCK_CONN_HDL_TYPE           (0x8006U) /**< @brief #SOCK_ConnHdlType        */
#define BRCM_SWARCH_SOCK_MAX_MSG_PKTS_MACRO      (0x8007U) /**< @brief #SOCK_MAX_MSG_PKTS       */
#define BRCM_SWARCH_SOCK_CMD_BUF_SIZE_MACRO      (0x8008U) /**< @brief #SOCK_CMD_BUF_SIZE       */
#define BRCM_SWARCH_SOCK_CMD_INFO_TYPE           (0x8009U) /**< @brief #SOCK_MsgInfoType        */
#define BRCM_SWARCH_SOCK_CIRC_QCTX_TYPE          (0x800AU) /**< @brief #SOCK_CircQContextType   */
#define BRCM_SWARCH_SOCK_CHANNEL_TYPE            (0x800BU) /**< @brief #SOCK_ChannelContextType */
#define BRCM_SWARCH_SOCK_CONNXN_INFO_TYPE        (0x800CU) /**< @brief #SOCK_ConnxnInfoType     */
#define BRCM_SWARCH_SOCK_TYPE                    (0x800DU) /**< @brief #SOCK_Type               */
#define BRCM_SWARCH_SOCK_CLIENT_DEFINE_MACRO     (0x800EU) /**< @brief #SOCK_CLIENT_DEFINE      */
#define BRCM_SWARCH_SOCK_SERVER_DEFINE_MACRO     (0x8010U) /**< @brief #SOCK_SERVER_DEFINE      */
#define BRCM_SWARCH_SOCK_LOCAL_DEFINE_MACRO      (0x8011U) /**< @brief #SOCK_LOCAL_DEFINE       */
#define BRCM_SWARCH_SOCK_OPEN_PROC               (0x8012U) /**< @brief #SOCK_Open               */
#define BRCM_SWARCH_SOCK_BIND_PROC               (0x8013U) /**< @brief #SOCK_Bind               */
#define BRCM_SWARCH_SOCK_LISTEN_PROC             (0x8014U) /**< @brief #SOCK_Listen             */
#define BRCM_SWARCH_SOCK_CONNECT_PROC            (0x8015U) /**< @brief #SOCK_Connect            */
#define BRCM_SWARCH_SOCK_ACCEPT_PROC             (0x8016U) /**< @brief #SOCK_Accept             */
#define BRCM_SWARCH_SOCK_SEND_PROC               (0x8017U) /**< @brief #SOCK_Send               */
#define BRCM_SWARCH_SOCK_RECV_PROC               (0x8018U) /**< @brief #SOCK_Recv               */
#define BRCM_SWARCH_SOCK_SENDTO_PROC             (0x8019U) /**< @brief #SOCK_SendTo             */
#define BRCM_SWARCH_SOCK_RECVFROM_PROC           (0x801AU) /**< @brief #SOCK_RecvFrom           */
#define BRCM_SWARCH_SOCK_CLOSE_PROC              (0x801BU) /**< @brief #SOCK_Close              */
#define BRCM_SWARCH_SOCK_LOCAL_DEFINE_V2_MACRO   (0x801CU) /**< @brief #SOCK_LOCAL_DEFINE_V2    */
#define BRCM_SWARCH_SOCK_LOCAL_DEFINE_V3_MACRO   (0x801DU) /**< @brief #SOCK_LOCAL_DEFINE_V3    */
#define BRCM_SWARCH_SOCK_CLIENT_DEFINE_V2_MACRO  (0x801EU) /**< @brief #SOCK_CLIENT_DEFINE_V2   */
#define BRCM_SWARCH_SOCK_SERVER_DEFINE_V2_MACRO  (0x801FU) /**< @brief #SOCK_SERVER_DEFINE_V2   */
/** @} */

/**
    @name Socket States
    @{
    @brief State of the socket

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef uint32_t SOCK_StateType;
#define SOCK_STATE_RESET           (0UL)
#define SOCK_STATE_INIT            (1UL)
#define SOCK_STATE_BIND_REQ        (2UL)
#define SOCK_STATE_BIND_ACK        (3UL)
#define SOCK_STATE_LISTEN_REQ      (4UL)
#define SOCK_STATE_LISTEN_ACK      (5UL)
#define SOCK_STATE_CONN_REQ        (6UL)
#define SOCK_STATE_CONN_ACK        (7UL)
#define SOCK_STATE_CLOSE_REQ       (8UL)
#define SOCK_STATE_CLOSE_ACK       (9UL)
/** @} */

/**
    @name Socket connection type
    @{
    @brief Socket connection type Local/TCP/UDP

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef uint32_t SOCK_ConnectionType;
#define SOCK_CONN_TYPE_DOMAIN_MASK   (0x00F0UL) /**< @brief Local/network socket type mask */
#define SOCK_CONN_TYPE_LOCAL         (0x0000UL) /**< @brief Local connection */
#define SOCK_CONN_TYPE_NET_SERVER    (0x0040UL) /**< @brief Network server connection */
#define SOCK_CONN_TYPE_NET_CLIENT    (0x0050UL) /**< @brief Network client connection */
#define SOCK_CONN_TYPE_DATA_MASK     (0x0001UL) /**< @brief Datagram/Stream mask */
#define SOCK_CONN_TYPE_STREAM        (0x0000UL) /**< @brief Stream connection */
#define SOCK_CONN_TYPE_DGRAM         (0x0001UL) /**< @brief Datagram connection */
/** @} */

/**
    @name Socket connection related messages
    @{
    @brief messages posted in the socket message queue

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef uint32_t SOCK_ConnMsgType;
#define SOCK_CONN_MSG_BIND         (1UL)
#define SOCK_CONN_MSG_LISTEN       (2UL)
#define SOCK_CONN_MSG_CONNECT      (4UL)
#define SOCK_CONN_MSG_CONNECT_ACK  (5UL)
#define SOCK_CONN_MSG_DATA         (6UL)
#define SOCK_CONN_MSG_CLOSE_INIT   (7UL)
#define SOCK_CONN_MSG_CLOSE        (8UL)
/** @} */

/**
    @name Circular Queue Flag
    @{
    @brief Circular queue configuration flags

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef uint32_t SOCK_CircQFlagType;
#define SOCK_CIRCQ_FLAG_TRUNCATE    (1UL)  /**< @brief Truncate the data on push */
/** @} */

/**
    @name Socket User Type
    @{
    @brief Socket User type

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef uint32_t SOCK_ChannelNumType;
#define SOCK_CHANNEL_NUM_OWNER   (0UL)  /**< @brief Channel used by the socket owner */
#define SOCK_CHANNEL_NUM_USER    (1UL)  /**< @brief Channel used by the socket user */
#define SOCK_CHANNEL_NUM_MAX     (1UL)  /**< @brief Max Channel number value */
/** @} */

/**
    @name Connection Handle
    @{
    @brief Connection Handle

    Connection handle used for send & receive data

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef BCM_HandleType SOCK_ConnHdlType;
#define SOCK_CONN_HDL_INDEX_MASK      (0x00000000000000FFULL)
#define SOCK_CONN_HDL_CH_NUM_MASK     (0x0000000000000100ULL)
#define SOCK_CONN_HDL_CH_NUM_SHIFT                      (8UL)
#define SOCK_CONN_HDL_COUNT_MASK      (0x00000000FFFF0000ULL)
#define SOCK_CONN_HDL_COUNT_SHIFT     (                 16UL)
#define SOCK_CONN_HDL_HASH_MASK       (0x0000FFFF00000000ULL)
#define SOCK_CONN_HDL_HASH_SHIFT      (                 32UL)
#define SOCK_CONN_HDL_MAGIC           (0x5343000000000000ULL)
#define SOCK_CONN_HDL_MAGIC_MASK      (0xFFFF000000000000ULL)
/** @} */

/**
    @name Socket lingertime Type
    @{
    @brief Socket lingertime type

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/

typedef uint64_t SOCK_LingerTimeType;
#define SOCK_LINGERTIME_IMMEDIATE_ABORT_MS         (0ULL)
#define SOCK_LINGERTIME_DEFAULT_MS                 (1000ULL)
/** @} */

/**
    @brief Maximum number of messages that can be queued

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
#define SOCK_MAX_MSG_PKTS            (8UL)

/**
    @brief Buffer size for the message queue

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
#define SOCK_CMD_BUF_SIZE            (SOCK_MAX_MSG_PKTS*sizeof(SOCK_MsgInfoType))

/**
    @brief Message Information type

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef struct sSOCK_MsgInfoType {
    SOCK_ConnMsgType     msgId;          /**< @brief Connection message id */
    uint16_t             portNum;        /**< @brief Port number */
    uint32_t             ipAddr;         /**< @brief IP Address */
    SOCK_ConnHdlType     connHdl;        /**< @brief Connection handle */
    uint32_t             dataSize;       /**< @brief Data size */
    int32_t              error;          /**< @brief Message error status */
    SOCK_LingerTimeType  lingerTimeMs;   /**< @brief Linger time in milli seconds */
} SOCK_MsgInfoType;

/**
    @brief Circular queue state variables

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef struct sSOCK_CircQContextType {
    uint32_t        readIdx;     /**< @brief Read index for the queue */
    uint32_t        writeIdx;    /**< @brief Write index for the queue */
    uint32_t        filledSize;  /**< @brief filled object count in the queue */
} SOCK_CircQContextType;

/**
    @brief Communication channel
    A channel consists of a data queue and a message queue

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef struct sSOCK_ChannelContextType {
    SOCK_StateType          state;     /**< @brief State of the connection */
    SOCK_ConnHdlType        handle;    /**< @brief Handle for the connection */
    SOCK_CircQContextType   msgQCtx;   /**< @brief Message queue context */
    SOCK_CircQContextType   dataQCtx;  /**< @brief Data queue context */
    SOCK_LingerTimeType     sockLingerTimeMs;  /**< @brief socket linger time in milliseconds */
    uint32_t                isBound;   /**< @brief Bound status */
    SOCK_MsgInfoType        msgQBuffer[SOCK_MAX_MSG_PKTS];
} SOCK_ChannelContextType;

/**
    @brief Communication connection in a socket
    A connection consists of two channels. One for each direction.

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef struct sSOCK_ConnxnInfoType {
    SOCK_ChannelContextType commCh[2UL]; /**< @brief Communication channel. 1 for each
                                              direction */
} SOCK_ConnxnInfoType;

/**
    @brief Socket data structure

    @trace #BRCM_SWREQ_SOCK_KERNEL_INTERFACE
*/
typedef struct sSOCK_Type {
    const char             *name;           /**< @brief Name for the socket instance */
    SOCK_ConnectionType     type;           /**< @brief Type of connection */
    uint32_t                task0Evnt;      /**< @brief Listener task event mask */
    uint32_t                task1Evnt;      /**< @brief Connector task event mask */
    uint32_t                task0Id;        /**< @brief Listener task ID */
    uint32_t                task1Id;        /**< @brief Connector task ID */
    SOCK_ConnxnInfoType    *connxns;        /**< @brief Connections associated with this socket */
    uint32_t                numConnxns;     /**< @brief Number of connections in the array */
    uint8_t                *buffer;         /**< @brief Pointer to the buffer used for this socket */
    uint32_t                ownerBufferSize;/**< @brief Buffer to be allocated for one owner channel */
    uint32_t                userBufferSize; /**< @brief Buffer to be allocated for one user channel */
} SOCK_Type;

/**
    @brief Define a client side network Socket object

    @param[in]     aName           Name of the Socket
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aOwnerBufferSize    Data buffer size to be used for the communication on owner side
    @param[in]     aUserBufferSize     Data buffer size to be used for the communication on user side
    @param[in]     aType           Type of connection
                                   #SOCK_CONN_TYPE_DGRAM or
                                   #SOCK_CONN_TYPE_STREAM
    @param[in]     aOwnerTask      Owner task id
    @param[in]     aUserTask       User task id
    @param[in]     aOwnerEvnt      Owner Task Event Mask
    @param[in]     aUserEvent      User Task Event Mask

    @trace #BRCM_SWREQ_SOCK_CONFIGURATION
*/
#define SOCK_CLIENT_DEFINE_V2(aName,                                           \
                             aConnectionName,                                  \
                             aBufferName,                                      \
                             aOwnerBufferSize,                                 \
                             aUserBufferSize,                                  \
                             aType,                                            \
                             aOwnerTask,                                       \
                             aUserTask,                                        \
                             aOwnerEvnt,                                       \
                             aUserEvnt)                                        \
                                                                               \
static SOCK_ConnxnInfoType aConnectionName[2]                                  \
                           COMP_SECTION(".bss.socket.socket");                 \
static uint8_t aBufferName[aOwnerBufferSize + aUserBufferSize]                 \
                           COMP_SECTION(".bss.socket.socket");                 \
const SOCK_Type aName = {                                                      \
    .name          = #aName,                                                   \
    .type          = (aType) | SOCK_CONN_TYPE_NET_CLIENT,                      \
    .task0Evnt     = aOwnerEvnt,                                               \
    .task1Evnt     = aUserEvnt,                                                \
    .task0Id       = aOwnerTask,                                               \
    .task1Id       = aUserTask,                                                \
    .connxns       = aConnectionName,                                          \
    .numConnxns    = 2UL,                                                      \
    .buffer        = (uint8_t *)aBufferName,                                   \
    .ownerBufferSize = aOwnerBufferSize,                                       \
    .userBufferSize  = aUserBufferSize,                                        \
}

/**
    @brief Define a client side network Socket object

    @param[in]     aName           Name of the Socket
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aBufferSize     Buffer size to be used for the communication
    @param[in]     aType           Type of connection
                                   #SOCK_CONN_TYPE_DGRAM or
                                   #SOCK_CONN_TYPE_STREAM
    @param[in]     aOwnerTask      Owner task id
    @param[in]     aUserTask       User task id
    @param[in]     aOwnerEvnt      Owner Task Event Mask
    @param[in]     aUserEvent      User Task Event Mask

    @trace #BRCM_SWREQ_SOCK_CONFIGURATION
*/
#define SOCK_CLIENT_DEFINE(aName,                                              \
                           aConnectionName,                                    \
                           aBufferName,                                        \
                           aBufferSize,                                        \
                           aType,                                              \
                           aOwnerTask,                                         \
                           aUserTask,                                          \
                           aOwnerEvnt,                                         \
                           aUserEvnt)                                          \
        SOCK_CLIENT_DEFINE_V2(aName,                                           \
                             aConnectionName,                                  \
                             aBufferName,                                      \
                             aBufferSize,                                      \
                             aBufferSize,                                      \
                             aType,                                            \
                             aOwnerTask,                                       \
                             aUserTask,                                        \
                             aOwnerEvnt,                                       \
                             aUserEvnt)

/**
    @brief Define a server side network Socket object

    @param[in]     aName           Name of the Socket
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aNumConnections Number of connections allowed
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aOwnerBufferSize Data buffer size to be used for the communication on owner side
    @param[in]     aUserBufferSize  Data buffer size to be used for the communication on user side
    @param[in]     aType           Type of connection
                                   #SOCK_CONN_TYPE_DGRAM or
                                   #SOCK_CONN_TYPE_STREAM
    @param[in]     aOwnerTask      Owner task id
    @param[in]     aUserTask       User task id
    @param[in]     aOwnerEvnt      Owner Task Event Mask
    @param[in]     aUserEvent      User Task Event Mask
    @param[in]     aNumConnections Number of connection allowed
    @param[in]     aBufferSize     Buffer size to be used for each connection

    @trace #BRCM_SWREQ_SOCK_CONFIGURATION
*/
#define SOCK_SERVER_DEFINE_V2(aName,                                               \
                             aConnectionName,                                      \
                             aNumConnections,                                      \
                             aBufferName,                                          \
                             aOwnerBufferSize,                                     \
                             aUserBufferSize,                                      \
                             aType,                                                \
                             aOwnerTask,                                           \
                             aUserTask,                                            \
                             aOwnerEvnt,                                           \
                             aUserEvnt)                                            \
                                                                                   \
static SOCK_ConnxnInfoType aConnectionName[(aNumConnections)+1UL]                  \
                           COMP_SECTION(".bss.socket.socket");                     \
static uint8_t aBufferName[aNumConnections][aOwnerBufferSize + aUserBufferSize]    \
                           COMP_SECTION(".bss.socket.socket");                     \
const SOCK_Type aName = {                                                          \
    .name          = #aName,                                                       \
    .type          = (aType) | SOCK_CONN_TYPE_NET_SERVER,                          \
    .task0Evnt     = aOwnerEvnt,                                                   \
    .task1Evnt     = aUserEvnt,                                                    \
    .task0Id       = aOwnerTask,                                                   \
    .task1Id       = aUserTask,                                                    \
    .connxns       = aConnectionName,                                              \
    .numConnxns    = (aNumConnections)+1UL,                                        \
    .buffer        = (uint8_t *)(aBufferName),                                     \
    .ownerBufferSize = aOwnerBufferSize,                                           \
    .userBufferSize  = aUserBufferSize,                                            \
}

/**
    @brief Define a server side network Socket object

    @param[in]     aName           Name of the Socket
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aNumConnections Number of connections allowed
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aBufferSize     Buffer size to be used for the communication
    @param[in]     aType           Type of connection
                                   #SOCK_CONN_TYPE_DGRAM or
                                   #SOCK_CONN_TYPE_STREAM
    @param[in]     aOwnerTask      Owner task id
    @param[in]     aUserTask       User task id
    @param[in]     aOwnerEvnt      Owner Task Event Mask
    @param[in]     aUserEvent      User Task Event Mask
    @param[in]     aNumConnections Number of connection allowed
    @param[in]     aBufferSize     Buffer size to be used for each connection

    @trace #BRCM_SWREQ_SOCK_CONFIGURATION
*/
#define SOCK_SERVER_DEFINE(aName,                                  \
                           aConnectionName,                        \
                           aNumConnections,                        \
                           aBufferName,                            \
                           aBufferSize,                            \
                           aType,                                  \
                           aOwnerTask,                             \
                           aUserTask,                              \
                           aOwnerEvnt,                             \
                           aUserEvnt)                              \
                                                                   \
        SOCK_SERVER_DEFINE_V2(aName,                               \
                             aConnectionName,                      \
                             aNumConnections,                      \
                             aBufferName,                          \
                             aBufferSize,                          \
                             aBufferSize,                          \
                             aType,                                \
                             aOwnerTask,                           \
                             aUserTask,                            \
                             aOwnerEvnt,                           \
                             aUserEvnt)

/**
    @brief Define a local Socket object

    @param[in]     aName           Name of the Socket
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aNumConnections Number of connections allowed
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aOwnerBufferSize Data buffer size to be used for the communication on owner side
    @param[in]     aUserBufferSize  Data buffer size to be used for the communication on user side
    @param[in]     aType           Type of connection
                                   #SOCK_CONN_TYPE_DGRAM or
                                   #SOCK_CONN_TYPE_STREAM
    @param[in]     aOwnerTask      Owner task id
    @param[in]     aUserTask       User task id
    @param[in]     aOwnerEvnt      Owner Task Event Mask
    @param[in]     aUserEvent      User Task Event Mask
    @param[in]     aNumConnections Number of connection allowed
    @param[in]     aBufferSize     Buffer size to be used for each connection

    @trace #BRCM_SWREQ_SOCK_CONFIGURATION
*/
#define SOCK_LOCAL_DEFINE_V3(aName,                                               \
                             aConnectionName,                                     \
                             aNumConnections,                                     \
                             aBufferName,                                         \
                             aOwnerBufferSize,                                    \
                             aUserBufferSize,                                     \
                             aType,                                               \
                             aOwnerTask,                                          \
                             aUserTask,                                           \
                             aOwnerEvnt,                                          \
                             aUserEvnt)                                           \
                                                                                  \
static SOCK_ConnxnInfoType aConnectionName[(aNumConnections)+1UL]                 \
                           COMP_SECTION(".bss.socket.socket");                    \
static uint8_t aBufferName[aNumConnections][aOwnerBufferSize + aUserBufferSize]   \
                           COMP_SECTION(".bss.socket.socket");                    \
const SOCK_Type aName = {                                                         \
    .name          = #aName,                                                      \
    .type          = (aType) | SOCK_CONN_TYPE_LOCAL,                              \
    .task0Evnt     = aOwnerEvnt,                                                  \
    .task1Evnt     = aUserEvnt,                                                   \
    .task0Id       = aOwnerTask,                                                  \
    .task1Id       = aUserTask,                                                   \
    .connxns       = aConnectionName,                                             \
    .numConnxns    = (aNumConnections)+1UL,                                       \
    .buffer        = (uint8_t *)(aBufferName),                                    \
    .ownerBufferSize = aOwnerBufferSize,                                          \
    .userBufferSize  = aUserBufferSize,                                           \
}

/**
    @brief Define a local Socket object

    @param[in]     aName           Name of the Socket
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aNumConnections Number of connections allowed
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aBufferSize     Buffer size to be used for the communication
    @param[in]     aType           Type of connection
                                   #SOCK_CONN_TYPE_DGRAM or
                                   #SOCK_CONN_TYPE_STREAM
    @param[in]     aOwnerTask      Owner task id
    @param[in]     aUserTask       User task id
    @param[in]     aOwnerEvnt      Owner Task Event Mask
    @param[in]     aUserEvent      User Task Event Mask
    @param[in]     aNumConnections Number of connection allowed
    @param[in]     aBufferSize     Buffer size to be used for each connection

    @trace #BRCM_SWREQ_SOCK_CONFIGURATION
*/
#define SOCK_LOCAL_DEFINE_V2(aName,                                \
                          aConnectionName,                         \
                          aNumConnections,                         \
                          aBufferName,                             \
                          aBufferSize,                             \
                          aType,                                   \
                          aOwnerTask,                              \
                          aUserTask,                               \
                          aOwnerEvnt,                              \
                          aUserEvnt)                               \
                                                                   \
        SOCK_LOCAL_DEFINE_V3(aName,                                \
                          aConnectionName,                         \
                          aNumConnections,                         \
                          aBufferName,                             \
                          aBufferSize,                             \
                          aBufferSize,                             \
                          aType,                                   \
                          aOwnerTask,                              \
                          aUserTask,                               \
                          aOwnerEvnt,                              \
                          aUserEvnt)

/**
    @brief Define a local Socket object

    @param[in]     aName           Name of the Socket
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aBufferSize     Buffer size to be used for the communication
    @param[in]     aType           Type of connection
                                   #SOCK_CONN_TYPE_DGRAM or
                                   #SOCK_CONN_TYPE_STREAM
    @param[in]     aOwnerTask      Owner task id
    @param[in]     aUserTask       User task id
    @param[in]     aOwnerEvnt      Owner Task Event Mask
    @param[in]     aUserEvent      User Task Event Mask
    @param[in]     aNumConnections Number of connection allowed
    @param[in]     aBufferSize     Buffer size to be used for each connection

    @trace #BRCM_SWREQ_SOCK_CONFIGURATION
*/
#define SOCK_LOCAL_DEFINE(aName,                                   \
                          aConnectionName,                         \
                          aBufferName,                             \
                          aBufferSize,                             \
                          aType,                                   \
                          aOwnerTask,                              \
                          aUserTask,                               \
                          aOwnerEvnt,                              \
                          aUserEvnt)                               \
                                                                   \
     SOCK_LOCAL_DEFINE_V3(aName,                                   \
                          aConnectionName,                         \
                          1UL,                                     \
                          aBufferName,                             \
                          aBufferSize,                             \
                          aBufferSize,                             \
                          aType,                                   \
                          aOwnerTask,                              \
                          aUserTask,                               \
                          aOwnerEvnt,                              \
                          aUserEvnt)

/** @brief Initialize the Socket

    This function to be called from both sides of the communication.
    The returned handle to be used for further call to the socket APIs.

    SOCK_Close() should be called using this handle for releasing the
    socket.

    @behavior Sync, reentrant

    @pre Socket should be in #SOCK_STATE_RESET

    @param[in]   aSock    Socket structure
    @param[in]   aChNum   Channel number (owner or user)
    @param[out]  aHdl     Connection handle

    @retval     #BCM_ERR_OK           Init successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aHdl is NULL
    @retval     #BCM_ERR_INVAL_STATE  Socket is not in #SOCK_STATE_RESET
    @retval     #BCM_ERR_NOMEM        Socket connections are full

    @post Socket goes to SOCK_STATE_INIT

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_Open(SOCK_Type const * const aSock,
                  SOCK_ChannelNumType aChNum,
                  SOCK_ConnHdlType *const aHdl);

/** @brief Bind socket to network port

    @Note The port is unbound on successful connection close.

    @behavior Async, reentrant

    @pre Socket should be in #SOCK_STATE_INIT

    @param[in]   aSock       Socket structure
    @param[in]   aHdl        Connection handle
    @param[in]   aPortNum    Port number to bind to

    @retval     #BCM_ERR_OK           Binding successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock is NULL
    @retval     #BCM_ERR_INVAL_STATE  Socket is not in #SOCK_STATE_INIT
                                      or #SOCK_STATE_BIND_ACK
    @retval     #BCM_ERR_NOPERM       Port is already assigned to another
                                      socket
    @retval     #BCM_ERR_BUSY         Try again, on next socket event

    @post Socket goes to SOCK_STATE_BIND_ACK state

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_Bind(SOCK_Type const * const aSock,
                  SOCK_ConnHdlType aHdl,
                  uint16_t aPortNum);

/** @brief Listen for incoming connection requests

    @behavior Async, reentrant

    @pre Socket should be in #SOCK_STATE_INIT or #SOCK_STATE_BIND_ACK

    @param[in]   aSock       Socket structure
    @param[in]   aHdl        Connection handle

    @retval     #BCM_ERR_OK           Binding successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock is NULL
    @retval     #BCM_ERR_INVAL_STATE  Socket is not in #SOCK_STATE_BIND_ACK or
                                      #SOCK_STATE_INIT
    @retval     #BCM_ERR_BUSY         Try again, on next socket event

    @post Socket goes to SOCK_STATE_LISTEN_ACK state

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_Listen(SOCK_Type const * const aSock, SOCK_ConnHdlType aHdl);

/** @brief Connect to the Listener socket

    This API to be called from the client side SW. The returned
    new connection handle is used for further communication.

    @behavior Async, reentrant

    @pre Socket is in SOCK_STATE_INIT or SOCK_STATE_BIND_ACK

    @param[in]   aSock   Socket structure
    @param[in]   aHdl    Connection handle
    @param[in]   aIpAddr Remote IP address
    @param[in]   aPort   Port number to connect to

    @retval     #BCM_ERR_OK           Connection successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aHdl is NULL or
                                      aIpAddr is not valid
                                      (e.g. broadcast/multicast for TCP socket)
    @retval     #BCM_ERR_INVAL_STATE  Socket is not in #SOCK_STATE_LISTEN
    @retval     #BCM_ERR_BUSY         Waiting for connection. Try again
                                      on the next event.
    @retval     #BCM_ERR_TIME_OUT     Connection timedout
    @retval     #BCM_ERR_NODEV        Connection rejected by server

    @post On success, the connection goes to #SOCK_STATE_CONN_ACK

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_Connect(SOCK_Type const * const aSock,
                     SOCK_ConnHdlType aHdl,
                     uint32_t aIpAddr,
                     uint16_t aPort);

/** @brief Accept a new connection request from top of the queue

    This API to be called from the Listener side SW. The returned
    Connection handle is used for further communication.

    @behavior Async, reentrant

    @pre Socket is in SOCK_STATE_LISTEN_ACK state

    @param[in]   aSock   Socket structure
    @param[in]   aHdl    Listening connection handle
    @param[out]  aIpAddr IP address of the new connection.
                         NULL for local socket.
    @param[out]  aPort   Port number of the new connection.
                         NULL for local socket.
    @param[out]  aNewHdl New connection handle

    @retval     #BCM_ERR_OK           Successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aHdl is NULL
    @retval     #BCM_ERR_INVAL_STATE  Socket is not in #SOCK_STATE_LISTEN_ACK
    @retval     #BCM_ERR_UNKNOWN      Integration error
    @retval     #BCM_ERR_BUSY         Waiting for connection. Try again
                                      on the next event.

    @post On success, the connection goes to #SOCK_STATE_CONNECT

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_Accept(SOCK_Type const * const aSock,
                    SOCK_ConnHdlType aHdl,
                    uint32_t *aIpAddr,
                    uint16_t *aPort,
                    SOCK_ConnHdlType * const aNewHdl);

/** @brief Send data through the given socket connection

    @behavior Sync, reentrant

    @pre Connection is in SOCK_STATE_CONNECT

    @param[in]      aSock   Socket structure
    @param[in]      aHdl    Connection handle (from SOCK_Connect, SOCK_Accept)
    @param[in]      aData   Data buffer
    @param[inout]   aSize   Number of bytes to send,
                            Actual number of bytes sent

    @retval     #BCM_ERR_OK           Data send successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aData or aSize is NULL
    @retval     #BCM_ERR_INVAL_PARAMS aHdl is invalid or socket is a datagram type
    @retval     #BCM_ERR_NOMEM        Socket write buffer is full
    @retval     #BCM_ERR_NODEV        Connection was aborted.
                                      User should invoke a SOCK_Close

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_Send(SOCK_Type const * const aSock,
                  SOCK_ConnHdlType aHdl,
                  uint8_t const * const aData,
                  uint32_t * const aSize);

/** @brief Receive data from given socket connection

    @behavior Sync, reentrant

    @pre Connection is in SOCK_STATE_CONNECT

    @param[in]      aSock   Socket structure
    @param[in]      aHdl    Connection handle (from SOCK_Connect, SOCK_Accept)
    @param[in]      aData   Data buffer
    @param[inout]   aSize   Data buffer size in bytes
                            Actual number of bytes received

    @retval     #BCM_ERR_OK           Receive successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aData or aSize is NULL
    @retval     #BCM_ERR_INVAL_PARAMS aHdl is invalid or socket is a datagram type
    @retval     #BCM_ERR_NODEV        Connection closed by the other side

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_Recv(SOCK_Type const * const aSock,
                  SOCK_ConnHdlType aHdl,
                  uint8_t * const aData,
                  uint32_t * const aSize);

/** @brief Send data to the given destination

    @behavior Sync, reentrant

    @pre SOCK_Bind has been performed

    @param[in]      aSock       Socket structure
    @param[in]      aHdl        Connection handle (from SOCK_Open)
    @param[in]      aData       Data buffer
    @param[in]      aSize       Data buffer size in bytes
    @param[in]      aDestIpAddr Destination IP address
    @param[in]      aDestPort   Destination port number

    @retval     #BCM_ERR_OK           Data sent to stack successfully
                                      Data gets sent successfully except when
                                      1.ARP resolution timeout
                                      2.Nif buffer timeout
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aData is NULL or aSize is ZERO
    @retval     #BCM_ERR_INVAL_PARAMS aHdl is invalid or socket type is not DATAGRAM
    @retval     #BCM_ERR_NOMEM        Socket write buffer is full
    @retval     #BCM_ERR_INVAL_STATE  Socket is in invalid state

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations This API is meant to use only for DATAGRAM sockets
*/
int32_t SOCK_SendTo(SOCK_Type const * const aSock,
                    SOCK_ConnHdlType aHdl,
                    uint8_t const * const aData,
                    uint32_t aSize,
                    const uint32_t aDstIpAddr,
                    const uint16_t aDstPort);

/** @brief Receive data from a datagram socket

    @behavior Sync, reentrant

    @pre SOCK_Bind has been performed

    @param[in]    aSock         Socket structure
    @param[in]    aHdl          Connection handle (from SOCK_Open)
    @param[in]    aData         Data buffer
    @param[inout] aSize         Data buffer size in bytes and should always
                                be either equal to or more than the datagram
                                size expected from the remote peer
                                Actual number of bytes received
    @param[out]   aSrcIPAddr    IP address of the remote end from which
                                the data was received
    @param[out]   aSrcPort      Port of the remote end from which the data
                                was received
    @param[out]   aMoreData     Boolean flag which shall be set to 1 in
                                case there is more data that is to be read
                                by the caller

    @retval     #BCM_ERR_OK           Receive successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock or aData or aSize is NULL
    @retval     #BCM_ERR_INVAL_PARAMS aHdl is invalid or socket type is not DATAGRAM
    @retval     #BCM_ERR_NOMEM        Data buffer provided cannot accommodate the Datagram
                                      received.
    @retval     #BCM_ERR_INVAL_STATE  Socket hasn't been bound successfully

    @post None

    @trace #BRCM_SWREQ_SOCK

    @limitations This API is meant to be used only for DATAGRAM sockets
*/
int32_t SOCK_RecvFrom(SOCK_Type const * const aSock,
                      SOCK_ConnHdlType aHdl,
                      uint8_t * const aData,
                      uint32_t * const aSize,
                      uint32_t * const aSrcIPAddr,
                      uint16_t * const aSrcPort,
                      uint32_t * const aMoreData);

/** @brief Close the given Datagram socket or connection of a stream socket

    @behavior Async, reentrant

    @pre None

    @param[in]      aSock   Socket structure
    @param[in]      aHdl    Connection handle (from SOCK_Open or SOCK_Connect or SOCK_Accept)
                            SOCK_Connect and SOCK_Accept applies only to stream sockets

    @retval     #BCM_ERR_OK           Close Successful
    @retval     #BCM_ERR_INVAL_PARAMS aSock is NULL or
                                      aHdl is invalid
    @retval     #BCM_ERR_BUSY         Try again, on next socket event

    @post Connection is in SOCK_STATE_RESET

    @trace #BRCM_SWREQ_SOCK

    @limitations None
*/
int32_t SOCK_Close(SOCK_Type const * const aSock, SOCK_ConnHdlType aHdl);

#endif /* SOCKET_H */

/** @} */
