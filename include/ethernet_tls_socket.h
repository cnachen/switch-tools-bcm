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
  @defgroup grp_tls_socket_ifc TLS Socket Definitions
  @ingroup grp_tls_abstract_def

  @addtogroup grp_tls_socket_ifc
  @{
  @file ethernet_tls_socket.h
  @brief Inteface definitions for the TLS Socket

  This file provides the common definitions and interface for the TLS Socket

  @version 0.1 Initial version
*/
#ifndef ETHERNET_TLS_SOCKET_H
#define ETHERNET_TLS_SOCKET_H

#include <stdint.h>
#include <bcm_err.h>
#include <ethernet_tls_std.h>
#include <socket.h>

/**
    @name Architecture IDs
    @{
    @brief Architecture IDs for TLS socket interface
 */
#define BRCM_SWARCH_TLS_CONN_INFO_TYPE           (0x7701U) /**< @brief #TLS_ConnInfoType         */
#define BRCM_SWARCH_TLS_SOCK_MAX_BUF_SIZE_MACRO  (0x7702U) /**< @brief #TLS_SOCKET_MAX_BUF_SIZE  */
#define BRCM_SWARCH_TLS_SERVER_DEFINE_MACRO      (0x7703U) /**< @brief #TLS_SERVER_DEFINE        */
#define BRCM_SWARCH_TLS_CLIENT_DEFINE_MACRO      (0x7704U) /**< @brief #TLS_CLIENT_DEFINE        */
#define BRCM_SWARCH_TLS_RPC_SERVER_GLOBAL        (0x7705U) /**< @brief #TLS_RpcServer            */
#define BRCM_SWARCH_TLS_RPC_CLIENT_GLOBAL        (0x7706U) /**< @brief #TLS_RpcClient            */
#define BRCM_SWARCH_TLS_TEST_SERVER_GLOBAL       (0x7707U) /**< @brief #TLS_TestServer           */
#define BRCM_SWARCH_TLS_TEST_CLIENT0_GLOBAL      (0x7708U) /**< @brief #TLS_TestClient0          */
#define BRCM_SWARCH_TLS_TEST_CLIENT1_GLOBAL      (0x7709U) /**< @brief #TLS_TestClient1          */
/** @} */

/**
    @brief TLS connection information

    TLS connection information structure

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
typedef struct sTLS_ConnInfoType {
    TLS_ConnectionType                  connType;         /**< @brief Connection type */
    uint16_t                            numConnections;   /**< @brief Number of connections */
    SOCK_Type                           localSock;        /**< @brief Local Socket */
    SOCK_Type                           remoteSock;       /**< @brief Remote Socket */
} TLS_ConnInfoType;

/**
    @brief Macro to Construct TLS Cmd

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
#define TLS_SOCKET_MAX_BUF_SIZE                (4096UL) /**< @brief Maximum socket buffer size */

/**
    @brief Define a server type TLS object

    @param[in]     aName           Name of the Object
    @param[in]     aLocalName      Name of the local socket
    @param[in]     aRemoteName     Name of the remote Socket
    @param[in]     aNumConnections Number of connections
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aTask           Task id
    @param[in]     aEvent          Event Mask
    @param[in]     aCompID         Component ID

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
#define TLS_SERVER_DEFINE(aName, aLocalName, aRemoteName, aNumConnections,                   \
                        aConnectionName, aBufferName, aTask, aEvent, aCompID)                \
static SOCK_ConnxnInfoType (aConnectionName)[2UL][((aNumConnections)+1UL)]                   \
                           COMP_SECTION(".bss.tls.socket.#aName.#aConnectionName");          \
static uint8_t (aBufferName)[2UL][aNumConnections][TLS_SOCKET_MAX_BUF_SIZE * 2UL]            \
                           COMP_SECTION(".bss.tls.socket.#aName.#aBufferName");              \
const TLS_ConnInfoType aName = {                                                             \
    .connType = TLS_CONN_SERVER,                                                             \
    .numConnections = aNumConnections,                                                       \
    .localSock = {                                                                           \
        .name          = #aLocalName,                                                        \
        .type          = SOCK_CONN_TYPE_STREAM | SOCK_CONN_TYPE_NET_SERVER,                  \
        .task0Evnt     = TLS_EVENT,                                                          \
        .task1Evnt     = aEvent,                                                             \
        .task0Id       = TLS_PROCESS_TASK,                                                   \
        .task1Id       = aTask,                                                              \
        .connxns       = (aConnectionName)[0UL],                                             \
        .numConnxns    = (aNumConnections) + 1UL,                                            \
        .buffer        = (uint8_t *)((aBufferName)[0UL]),                                    \
        .ownerBufferSize = TLS_SOCKET_MAX_BUF_SIZE,                                          \
        .userBufferSize  = TLS_SOCKET_MAX_BUF_SIZE,                                          \
    },                                                                                       \
    .remoteSock = {                                                                          \
        .name          = #aRemoteName,                                                       \
        .type          = SOCK_CONN_TYPE_STREAM | SOCK_CONN_TYPE_NET_SERVER,                  \
        .task0Evnt     = TLS_NETWORK_EVENT,                                                    \
        .task1Evnt     = TLS_EVENT,                                                          \
        .task0Id       = TLS_NETWORK_PROCESS_TASK,                                                  \
        .task1Id       = TLS_PROCESS_TASK,                                                   \
        .connxns       = (aConnectionName)[1UL],                                             \
        .numConnxns    = (aNumConnections) + 1UL,                                            \
        .buffer        = (uint8_t *)((aBufferName)[1UL]),                                    \
        .ownerBufferSize = TLS_SOCKET_MAX_BUF_SIZE,                                          \
        .userBufferSize  = TLS_SOCKET_MAX_BUF_SIZE,                                          \
    },                                                                                       \
};

/**
    @brief Define a client type TLS object

    @param[in]     aName           Name of the Object
    @param[in]     aLocalName      Name of the local socket
    @param[in]     aRemoteName     Name of the remote Socket
    @param[in]     aConnectionName Connection related data stored
                                   under this name
    @param[in]     aBufferName     Name of the buffer variable
    @param[in]     aTask           Task id
    @param[in]     aEvent          Event Mask
    @param[in]     aCompID         Component ID

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
#define TLS_CLIENT_DEFINE(aName, aLocalName, aRemoteName, aConnectionName,                   \
                        aBufferName, aTask, aEvent, aCompID)                                 \
static SOCK_ConnxnInfoType (aConnectionName)[2UL][(2UL)]                                     \
                           COMP_SECTION(".bss.tls.socket.#aName.#aConnectionName");          \
static uint8_t (aBufferName)[2UL][2UL][TLS_SOCKET_MAX_BUF_SIZE * 2UL]                        \
                           COMP_SECTION(".bss.tls.socket.#aName.#aBufferName");              \
const TLS_ConnInfoType aName = {                                                             \
    .connType = TLS_CONN_CLIENT,                                                             \
    .numConnections = 1UL,                                                                   \
    .localSock = {                                                                           \
        .name          = #aLocalName,                                                        \
        .type          = SOCK_CONN_TYPE_STREAM | SOCK_CONN_TYPE_NET_CLIENT,                  \
        .task0Evnt     = TLS_EVENT,                                                          \
        .task1Evnt     = aEvent,                                                             \
        .task0Id       = TLS_PROCESS_TASK,                                                   \
        .task1Id       = aTask,                                                              \
        .connxns       = (aConnectionName)[0UL],                                             \
        .numConnxns    = 2UL,                                                                \
        .buffer        = (uint8_t *)((aBufferName)[0UL]),                                    \
        .ownerBufferSize = TLS_SOCKET_MAX_BUF_SIZE,                                          \
        .userBufferSize  = TLS_SOCKET_MAX_BUF_SIZE,                                          \
    },                                                                                       \
    .remoteSock = {                                                                          \
        .name          = #aRemoteName,                                                       \
        .type          = SOCK_CONN_TYPE_STREAM | SOCK_CONN_TYPE_NET_CLIENT,                  \
        .task0Evnt     = TLS_NETWORK_EVENT,                                                    \
        .task1Evnt     = TLS_EVENT,                                                          \
        .task0Id       = TLS_NETWORK_PROCESS_TASK,                                                  \
        .task1Id       = TLS_PROCESS_TASK,                                                   \
        .connxns       = (aConnectionName)[1UL],                                             \
        .numConnxns    = 2UL,                                                                \
        .buffer        = (uint8_t *)((aBufferName)[1UL]),                                    \
        .ownerBufferSize = TLS_SOCKET_MAX_BUF_SIZE,                                          \
        .userBufferSize  = TLS_SOCKET_MAX_BUF_SIZE,                                          \
    },                                                                                       \
};

/**
    @brief RPC TLS server

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
extern const TLS_ConnInfoType TLS_RpcServer;

/**
    @brief RPC TLS Client

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
extern const TLS_ConnInfoType TLS_RpcClient;

/**
    @brief Test TLS Server

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
extern const TLS_ConnInfoType TLS_TestServer;

/**
    @brief Test TLS client 0

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
extern const TLS_ConnInfoType TLS_TestClient0;

/**
    @brief Test TLS client 1

    @trace #BRCM_SWREQ_TLS_SOCKET
*/
extern const TLS_ConnInfoType TLS_TestClient1;

#endif /* TLS_H */
/** @} */
