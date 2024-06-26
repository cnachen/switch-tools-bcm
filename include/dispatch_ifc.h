/*****************************************************************************
 Copyright 2020-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_rpc_v2_ifc Connection Interface
    @ingroup grp_rpc_v2_mod

    @addtogroup grp_rpc_v2_ifc
    @{

    @file rpc_interface.h
    @brief DISPATCH communication interface

    @version 0.1 Initial Version
*/

#ifndef DISPATCH_IFC_H
#define DISPATCH_IFC_H

#include <bcm_err.h>
#include <rpc_msg.h>

/**
    @name DISPATCH interface Architecture IDs
    @{
    @brief Architecture IDs for DISPATCH interface

*/
#define BRCM_SWARCH_DISPATCH_IFC_MAX_MACRO           (0x8600U)   /**< @brief #DISPATCH_IFC_MAX            */
#define BRCM_SWARCH_DISPATCH_IFC_MODE_TYPE           (0x8601U)   /**< @brief #DISPATCH_IfcModeType        */
#define BRCM_SWARCH_DISPATCH_IFC_TYPE                (0x8602U)   /**< @brief #DISPATCH_IfcType            */
#define BRCM_SWARCH_DISPATCH_IFC_CONN_IDX_TYPE       (0x8603U)   /**< @brief #DISPATCH_IfcConnIdxType     */

#define BRCM_SWARCH_DISPATCH_IFC_INIT_TYPE           (0x8610U)   /**< @brief #DISPATCH_IfcInitType        */
#define BRCM_SWARCH_DISPATCH_IFC_GET_HDL_TYPE        (0x8611U)   /**< @brief #DISPATCH_IfcGetHdlType      */
#define BRCM_SWARCH_DISPATCH_IFC_GET_MSG_SZ_TYPE     (0x8612U)   /**< @brief #DISPATCH_IfcGetMsgSizeType  */
#define BRCM_SWARCH_DISPATCH_IFC_GET_EVENT_MASK_TYPE (0x8613U)   /**< @brief #DISPATCH_IfcGetEventMaskType*/
#define BRCM_SWARCH_DISPATCH_IFC_CONNECT_TYPE        (0x8614U)   /**< @brief #DISPATCH_IfcConnectType     */
#define BRCM_SWARCH_DISPATCH_IFC_GET_CONN_HDL_TYPE   (0x8615U)   /**< @brief #DISPATCH_IfcGetConnHdlType  */
#define BRCM_SWARCH_DISPATCH_IFC_SEND_TYPE           (0x8616U)   /**< @brief #DISPATCH_IfcSendType        */
#define BRCM_SWARCH_DISPATCH_IFC_RECV_TYPE           (0x8617U)   /**< @brief #DISPATCH_IfcRecvType        */
#define BRCM_SWARCH_DISPATCH_IFC_DISCONNECT_TYPE     (0x8618U)   /**< @brief #DISPATCH_IfcDisconnectType  */
#define BRCM_SWARCH_DISPATCH_IFC_DEINIT_TYPE         (0x8619U)   /**< @brief #DISPATCH_IfcDeinitType      */
#define BRCM_SWARCH_DISPATCH_IFC_INFO_TYPE           (0x861FU)   /**< @brief #DISPATCH_IfcInfoType        */

#define BRCM_SWARCH_DISPATCH_IFC_MSGQ_SLAVE_GLOBAL   (0x8640U)   /**< @brief #DISPATCH_IfcMsgQSlave       */
#define BRCM_SWARCH_DISPATCH_IFC_IPC_MASTER_GLOBAL   (0x8641U)   /**< @brief #DISPATCH_IfcIpcMaster       */
#define BRCM_SWARCH_DISPATCH_IFC_IPC_SLAVE_GLOBAL    (0x8642U)   /**< @brief #DISPATCH_IfcIpcSlave        */
#define BRCM_SWARCH_DISPATCH_IFC_SOCK_MASTER_GLOBAL  (0x8643U)   /**< @brief #DISPATCH_IfcNetMaster       */
#define BRCM_SWARCH_DISPATCH_IFC_NETSOCKSLAVE_GLOBAL (0x8644U)   /**< @brief #DISPATCH_IfcNetSlave        */
#define BRCM_SWARCH_DISPATCH_IFC_LOCALSOCKSLAVE_GLOBAL (0x8645U) /**< @brief #DISPATCH_IfcLocalSlave      */
#define BRCM_SWARCH_DISPATCH_IFC_PROXYSOCKSLAVE_GLOBAL (0x8646U) /**< @brief #DISPATCH_IfcProxySlave      */
#define BRCM_SWARCH_DISPATCH_TCPCLIENTSOCKET_GLOBAL  (0x8647U)   /**< @brief #DISPATCH_TCPClientSocket    */
#define BRCM_SWARCH_DISPATCH_TCPSERVERSOCKET_GLOBAL  (0x8648U)   /**< @brief #DISPATCH_TCPServerSocket    */
#define BRCM_SWARCH_DISPATCH_TCPPROXYSERVERSOCKET_GLOBAL  (0x8649U)   /**< @brief #DISPATCH_TCPProxyServerSocket    */
#define BRCM_SWARCH_DISPATCH_IFC_GET_PROC            (0x864AU)   /**< @brief #DISPATCH_IfcGet             */
/** @} */

/**
    @brief Maximum number of interfaces

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
#define DISPATCH_IFC_MAX      (8UL)


/**
    @name DISPATCH channel mode type
    @{

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
typedef uint8_t DISPATCH_IfcModeType;
#define DISPATCH_IFC_MODE_DIRECT_SLAVE  (0U)    /**< @brief DISPATCH Module recevies commands from
                                                remote entity, processes them with local services   */
#define DISPATCH_IFC_MODE_DIRECT_MASTER (1U)    /**< @brief DISPATCH Module sends commands to remote
                                                entity, originated or forwarded by local services   */
#define DISPATCH_IFC_MODE_PROXY_SLAVE   (2U)    /**< @brief DISPATCH Module recevies commands from
                                                remote entity, processes them with proxy services or
                                                forwards them to the terminal device                */
#define DISPATCH_IFC_MODE_PROXY_MASTER  (3U)    /**< @brief DISPATCH Module sends commands to remote
                                                entity, originated or forward by proxy services     */
/** @} */

/**
    @name DISPATCH interface type
    @{
    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
typedef uint8_t DISPATCH_IfcType;
#define DISPATCH_IFC_MSGQ      (0x1U)   /**< @brief MsgQ type    */
#define DISPATCH_IFC_SOCKET    (0x2U)   /**< @brief Socket type  */
#define DISPATCH_IFC_CUSTOM    (0x3U)   /**< @brief Custom type  */
/** @} */

/**
    @name DISPATCH interface connection index
    @{

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
typedef uint32_t DISPATCH_IfcConnIdxType;
#define DISPATCH_IFC_CONN_IDX_0      (0UL)   /**< @brief Connection index 0      */
#define DISPATCH_IFC_CONN_IDX_1      (1UL)   /**< @brief Connection index 1      */
#define DISPATCH_IFC_CONN_IDX_2      (2UL)   /**< @brief Connection index 2      */
#define DISPATCH_IFC_CONN_IDX_3      (3UL)   /**< @brief Connection index 3      */
#define DISPATCH_IFC_CONN_IDX_4      (4UL)   /**< @brief Connection index 4      */
#define DISPATCH_IFC_CONN_IDX_5      (5UL)   /**< @brief Connection index 5      */
#define DISPATCH_IFC_CONN_IDX_6      (6UL)   /**< @brief Connection index 6      */
#define DISPATCH_IFC_CONN_IDX_7      (7UL)   /**< @brief Connection index 7      */
#define DISPATCH_IFC_CONN_IDX_MAX    (8UL)   /**< @brief Max Connection index    */
/** @} */

struct sDISPATCH_IfcInfoType;

/** @brief DISPATCH interface Initialization

    @behavior Sync, Non-Reentrant

    @param[in]      aIfc         Interface Object

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Init successful
    @retval     #BCM_ERR_BUSY           Init in progress
    @retval     #BCM_ERR_UNKNOWN        Init Failed
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or invalid

    @trace  #BRCM_SWREQ_DISPATCH_IFC

    @limitations None
*/
typedef int32_t (*DISPATCH_IfcInitType)(const struct sDISPATCH_IfcInfoType *aIfc);

/** @brief Get Message size

    @behavior Sync, Non-Reentrant

    @param[in]      aIfc         Interface Object
    @param[out]     aSize        Message Size

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved handle
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or
                                        aSize is NULL

    @trace  #BRCM_SWREQ_DISPATCH_IFC

    @limitations None
*/
typedef int32_t (*DISPATCH_IfcGetMsgSizeType)(const struct sDISPATCH_IfcInfoType *aIfc,
                                                       uint32_t* const aSize);

/** @brief Get the event mask for the interface

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]      aIfc         Interface Object
    @param[out]     aMask        A 32-bit event mask for the interface

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved handle
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or
                                        aMask is NULL

    @post None

    @limitations Must return the same event mask at any point of time
    i.e. it cannot be changed dynamically.

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
typedef int32_t (*DISPATCH_IfcGetEventMaskType)(const struct sDISPATCH_IfcInfoType *aIfc,
                                                            uint32_t* const aMask);

/** @brief Get the handle for the interface

    @behavior Sync, Non-Reentrant

    @pre Interface is initialization started

    @param[in]      aIfc         Interface Object
    @param[out]     aHdl         Connection handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved handle
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or invalid
                                        aHdl is NULL or

    @post None

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
typedef int32_t (*DISPATCH_IfcGetHdlType)(const struct sDISPATCH_IfcInfoType *aIfc,
                                            BCM_HandleType* const aHdl);

/** @brief Connect

    For Master interface, this may initiate connection to remote slave.
    For Slave interface, this may accept connection.

    @behavior Sync, Non-Reentrant

    @param[in]      aIfc         Interface Object
    @param[in]      aConnIdx     Connection index to connect or accept connection
                                 (in range of 0 to max connections - 1
                                 on that interface)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Connection established
    @retval     #BCM_ERR_BUSY           Connection in progress
    @retval     #BCM_ERR_NODEV          No Connection
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or invalid

    @trace  #BRCM_SWREQ_DISPATCH_IFC

    @limitations None
*/
typedef int32_t (*DISPATCH_IfcConnectType)(const struct sDISPATCH_IfcInfoType *aIfc,
                                            DISPATCH_IfcConnIdxType aConnIdx);

/** @brief Get the handle for the connection

    @behavior Sync, Non-Reentrant

    @pre Connection is established

    @param[in]      aIfc            Interface Object
    @param[in]      aConnIdx        Connection index to connect or accept connection
                                    (in range of 0 to max connections - 1
                                    on that interface)
    @param[out]     aHdl            Connection handle (could be file descriptor
                                    on linux machines)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved handle or file descriptor(linux)
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or invalid
                                        aHdl is NULL

    @post None

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
typedef int32_t (*DISPATCH_IfcGetConnHdlType)(const struct sDISPATCH_IfcInfoType *aIfc,
                                                DISPATCH_IfcConnIdxType aConnIdx,
                                                BCM_HandleType* const aHdl);

/** @brief Send message

    Send command/response/async notification to remote entity.
    Size of payload is expected to be the value returned by DISPATCH_IfcGetMsgSizeType
    API in the corresponding interface.

    @behavior Sync, Non-Reentrant

    @param[in]      aIfc                Interface Object
    @param[in]      aConnIdx            Connection index (in range of 0 to max connections - 1
                                        on that interface)
    @param[in]      aMsg                Message to be sent

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Message sent successfully
    @retval     #BCM_ERR_NOMEM          Message not sent out due to lack of
                                        buffers. The operation should be retried.
    @retval     #BCM_ERR_NODEV          Connection lost
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or invalid
                                        aMsg is NULL

    @trace  #BRCM_SWREQ_DISPATCH_IFC

    @limitations None
*/
typedef int32_t (*DISPATCH_IfcSendType)(const struct sDISPATCH_IfcInfoType *aIfc,
                                         DISPATCH_IfcConnIdxType aConnIdx, const RPC_MsgType *aMsg);

/** @brief Receive Message

    interface function used to receive message.
    Size of payload is expected to be the value returned by DISPATCH_IfcGetMsgSizeType
    API in the corresponding interface.
    Client needs to invoke this API until #BCM_ERR_NOT_FOUND is returned.

    @behavior Sync, Non-Reentrant

    @param[in]      aIfc            Interface Object
    @param[in]      aConnIdx        Connection index (in range of 0 to max connections - 1)
    @param[out]     aMsg            Received message

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Message received successfully and copied
    @retval     #BCM_ERR_NOT_FOUND      No Message received
    @retval     #BCM_ERR_NODEV          Connection lost
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or invalid
                                        aMsg is NULL

    @trace  #BRCM_SWREQ_DISPATCH_IFC

    @limitations None
*/
typedef int32_t (*DISPATCH_IfcRecvType)(const struct sDISPATCH_IfcInfoType *aIfc,
                                         DISPATCH_IfcConnIdxType aConnIdx, RPC_MsgType* const aMsg);

/** @brief Disconnect and cleanup

    @behavior Sync, Non-Reentrant

    @param[in]      aIfc            Interface Object
    @param[in]      aConnIdx        Connection index to connect or accept connection
                                    (in range of 0 to max connections - 1
                                    on that interface)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Disconnection complete
    @retval     #BCM_ERR_BUSY           Disconnection in progress
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or invalid

    @trace  #BRCM_SWREQ_DISPATCH_IFC

    @limitations None
*/
typedef int32_t (*DISPATCH_IfcDisconnectType)(const struct sDISPATCH_IfcInfoType *aIfc,
                                               DISPATCH_IfcConnIdxType aConnIdx);

/** @brief de-initialization

    @behavior Sync, Non-Reentrant

    @param[in]      aIfc         Interface Object

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             DeInit successful
    @retval     #BCM_ERR_BUSY           DeInit in progress
    @retval     #BCM_ERR_INVAL_PARAMS   aIfc is NULL or invalid

    @trace  #BRCM_SWREQ_DISPATCH_IFC

    @limitations None
*/
typedef int32_t (*DISPATCH_IfcDeinitType)(const struct sDISPATCH_IfcInfoType *aIfc);

/**
    @brief Container structure to capture the interface specific information

    @trace #BRCM_SWREQ_DISPATCH_IFC
 */
typedef struct sDISPATCH_IfcInfoType {
    DISPATCH_IfcType             type;        /**< @brief Channel type                  */
    DISPATCH_IfcModeType         mode;        /**< @brief Channel Mode                  */
    uint32_t                     maxConn;     /**< @brief Maximum connections, must
                                                          be less than
                                                          #DISPATCH_IFC_CONN_IDX_MAX    */
    uint32_t                     *context;    /**< @brief Context of interface          */
    uint32_t                     contextSize; /**< @brief Size of the interface context */
    const SOCK_Type              *socket;     /**< @brief Socket                        */
    DISPATCH_IfcInitType         init;        /**< @brief Initialize the interface
                                                          and start listening           */
    DISPATCH_IfcGetHdlType       getHdl;      /**< @brief Get Listening handle          */
    DISPATCH_IfcGetMsgSizeType   getMsgSize;  /**< @brief Get Message Size. Currently,
                                                          this should return
                                                          sizeof(RPC_MsgType)           */
    DISPATCH_IfcGetEventMaskType getEventMask;/**< @brief Get Event Mask (for RTOS)     */
    DISPATCH_IfcConnectType      connect;     /**< @brief Connect to remote             */
    DISPATCH_IfcGetConnHdlType   getConnHdl;  /**< @brief get connection handle         */
    DISPATCH_IfcSendType         send;        /**< @brief Send Message to remote        */
    DISPATCH_IfcRecvType         recv;        /**< @brief Receive Message from remote   */
    DISPATCH_IfcDisconnectType   disconnect;  /**< @brief Disconnect from remote        */
    DISPATCH_IfcDeinitType       deinit;      /**< @brief De-Initialize                 */
} DISPATCH_IfcInfoType;

/**
    @brief DISPATCH Slave interface

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const DISPATCH_IfcInfoType DISPATCH_IfcMsgQSlave;

/**
    @brief IPC Master Interface

    This is used only in proxy mode.

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const DISPATCH_IfcInfoType DISPATCH_IfcIpcMaster;

/**
    @brief IPC Slave Interface

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const DISPATCH_IfcInfoType DISPATCH_IfcIpcSlave;

/**
    @brief Socket Master Interface

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const DISPATCH_IfcInfoType DISPATCH_IfcNetMaster;

/**
    @brief Direct slave interface with network socket

    This interface listens for commands to be processed by local services only.

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const DISPATCH_IfcInfoType DISPATCH_IfcNetSlave;

/**
    @brief Local slave Interface

    This interface is to receive requests from local applications.
    This interface uses #RPC_Socket

    @anchor DISPATCH_LOCAL_SLAVE_PROXY_MODE
    <b>DISPATCH_LOCAL_SLAVE_PROXY_MODE</b> enables proxy mode for Local slave interface

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const DISPATCH_IfcInfoType DISPATCH_IfcLocalSlave;

/**
    @brief Proxy slave Interface

    This interface is to receive requests for remote/proxy services.

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const DISPATCH_IfcInfoType DISPATCH_IfcProxySlave;

/** @brief Get list of interfaces

    This API returns the list of interfaces

    @behavior Sync, Non-reentrant

    @pre None

    Return values are documented in reverse-chronological order
    @retval     Pointer to interface list

    @post None

    @trace  #BRCM_SWREQ_DISPATCH_IFC

    @limitations None
*/
extern const DISPATCH_IfcInfoType* const * DISPATCH_IfcGet();

/**
    @brief TCP client socket for Cmd/Response

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const SOCK_Type DISPATCH_TCPClientSocket;

/**
    @brief TCP server socket for Cmd/Response

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const SOCK_Type DISPATCH_TCPServerSocket;

/**
    @brief TCP server socket for Cmd/Response

    @trace #BRCM_SWREQ_DISPATCH_IFC
*/
extern const SOCK_Type DISPATCH_TCPProxyServerSocket;

#endif /* DISPATCH_IFC_H */
/** @} */
