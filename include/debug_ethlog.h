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
    @defgroup grp_debug_ethlog_ifc Debug log over Ethernet control Interface
    @ingroup grp_debug_abstract

    @addtogroup grp_debug_ethlog_ifc
    @{

    @limitations None

    @file debug_ethlog.h
    @brief Debug Log over Ethernet control Interface
    This header file contains the interface functions for Debug Log control

    @version 1.0 Initial Version
*/

#ifndef ETHLOG_LOG_H
#define ETHLOG_LOG_H

#include <bcm_comp.h>
#include <module_msg.h>
#include <msg_queue.h>
#include <bcm_err.h>
#include <bcm_utils.h>

/**
    @name Debug log Architecture IDs
    @{
    @brief Architecture IDs for Debug log
*/
#define BRCM_SWARCH_ETHLOG_ID_MACRO                     (0x8100U) /**< @brief #ETHLOG_ID                */
#define BRCM_SWARCH_ETHLOG_ID_TYPE                      (0x8101U) /**< @brief #ETHLOG_IDType            */
#define BRCM_SWARCH_ETHLOG_MACRO                        (0x8102U) /**< @brief #ETHLOG_MAGIC             */

#define BRCM_SWARCH_ETHLOG_DEFAULT_LEVEL_MSG_TYPE       (0x8180U) /**< @brief #ETHLOG_DefaultLevelMsgType  */
#define BRCM_SWARCH_ETHLOG_COMP_STATE_MSG_TYPE          (0x8181U) /**< @brief #ETHLOG_CompStateMsgType  */
#define BRCM_SWARCH_ETHLOG_COMP_LIST_MSG_TYPE           (0x8182U) /**< @brief #ETHLOG_CompListMsgType   */
#define BRCM_SWARCH_ETHLOG_MSG_UNION_TYPE               (0x8183U) /**< @brief #ETHLOG_MsgUnionType      */
#define BRCM_SWARCH_ETHLOG_MSG_TYPE                     (0x8184U) /**< @brief #ETHLOG_MsgType           */

#define BRCM_SWARCH_ETHLOG_GET_DEFAULT_LEVEL_PROC       (0x81C0U) /**< @brief #ETHLOG_GetDefaultLogLevel    */
#define BRCM_SWARCH_ETHLOG_SET_DEFAULT_LEVEL_PROC       (0x81C1U) /**< @brief #ETHLOG_SetDefaultLogLevel    */
#define BRCM_SWARCH_ETHLOG_GET_COMP_LOG_LEVEL_PROC      (0x81C2U) /**< @brief #ETHLOG_GetCompLogLevel       */
#define BRCM_SWARCH_ETHLOG_SET_COMP_LOG_LEVEL_PROC      (0x81C3U) /**< @brief #ETHLOG_SetCompLogLevel       */
#define BRCM_SWARCH_ETHLOG_GET_COMP_LIST_LOG_LEVEL_PROC (0x81C4U) /**< @brief #ETHLOG_GetCompListLogLevel   */
#define BRCM_SWARCH_ETHLOG_SET_COMP_LIST_LOG_LEVEL_PROC (0x81C5U) /**< @brief #ETHLOG_SetCompListLogLevel   */
/** @} */

/**
    @brief Log over Ethernet Command ID

    @trace #BRCM_SWREQ_ETHLOG
 */
#define ETHLOG_ID(x)                    BCM_MSG(BCM_GROUPID_DEBUG, BCM_ELG_ID, (x)) /**< @brief Log over Ethernet ID construction macro */

/**
    @name Log over Ethernet macros
    @{
    @brief Log over Ethernet macros

    @trace #BRCM_SWREQ_ETHLOG
*/
#define ETHLOG_MAGIC                    (0x444C4F45UL)      /**< @brief ASCII "DLOE"        */
#define ETHLOG_MAX_MSG_SIZE             (448UL)             /**< @brief Max Message size    */
#define ETHLOG_COMP_LIST_MAX_SIZE       (16UL)              /**< @brief Component list maximum size    */
/** @} */

/**
    @name Log over Ethernet Message IDs
    @{
    @brief Message IDs for exchange on message queues and Host

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_ETHLOG
*/
typedef BCM_MsgType ETHLOG_IDType;     /**< @brief Log over Ethernet message ID Type */
#define ETHLOG_ID_GET_DEFAULT_LEVEL      ETHLOG_ID(0x10U) /**< @brief #ETHLOG_DefaultLevelMsgType  */
#define ETHLOG_ID_SET_DEFAULT_LEVEL      ETHLOG_ID(0x11U) /**< @brief #ETHLOG_DefaultLevelMsgType  */
#define ETHLOG_ID_GET_COMP_LEVEL         ETHLOG_ID(0x12U) /**< @brief #ETHLOG_CompStateMsgType     */
#define ETHLOG_ID_SET_COMP_LEVEL         ETHLOG_ID(0x13U) /**< @brief #ETHLOG_CompStateMsgType     */
#define ETHLOG_ID_GET_LIST_LEVEL         ETHLOG_ID(0x14U) /**< @brief #ETHLOG_CompListMsgType      */
#define ETHLOG_ID_SET_LIST_LEVEL         ETHLOG_ID(0x15U) /**< @brief #ETHLOG_CompListMsgType      */
/** @} */

/**
    @brief Default Log level

    @trace #BRCM_SWREQ_ETHLOG
 */
typedef struct sETHLOG_DefaultLevelMsgType {
    BCM_LogLevelType            level;        /**< @brief Input/Output: Log level  */
} ETHLOG_DefaultLevelMsgType;
BCM_STATIC_SIZE_ASSERT(ETHLOG_DefaultLevelMsgType, 2UL, ETHLOG_MAX_MSG_SIZE)

/**
    @brief Component state

    @trace #BRCM_SWREQ_ETHLOG
 */
typedef struct sETHLOG_CompStateMsgType {
    BCM_CompIDType              compID;       /**< @brief Input: Component ID */
    BCM_LogLevelType            level;        /**< @brief Input/Output: Log level  */
} ETHLOG_CompStateMsgType;
BCM_STATIC_SIZE_ASSERT(ETHLOG_CompStateMsgType, 4UL, ETHLOG_MAX_MSG_SIZE)

/**
    @brief List of components in the

    @trace #BRCM_SWREQ_ETHLOG
 */
typedef struct sETHLOG_CompListMsgType {
    uint16_t                    count;       /**< @brief Input/Output: Size of the valid entries */
    uint16_t                    reserved;    /**< @brief Reserved */
    ETHLOG_CompStateMsgType     comp[ETHLOG_COMP_LIST_MAX_SIZE];
                                            /**< @brief Input/Output: Version of image (image which has the maximum version that appeared first */
} ETHLOG_CompListMsgType;
BCM_STATIC_SIZE_ASSERT(ETHLOG_CompListMsgType, 68UL, ETHLOG_MAX_MSG_SIZE)

/**
    @brief Update Union encapsulating all messages

    @trace #BRCM_SWREQ_ETHLOG
*/
typedef union uETHLOG_MsgUnionType {
    uint32_t                        data[ETHLOG_MAX_MSG_SIZE/4UL];
                                                 /**< @brief Unformatted request   */
    ETHLOG_DefaultLevelMsgType      logLevel;    /**< @brief Log level             */
    ETHLOG_CompStateMsgType         compState;   /**< @brief Component state       */
    ETHLOG_CompListMsgType          compList;    /**< @brief Component list        */
} ETHLOG_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHLOG_MsgUnionType, ETHLOG_MAX_MSG_SIZE, ETHLOG_MAX_MSG_SIZE)

/**
    @brief Verity Union encapsulating all messages

    @trace #BRCM_SWREQ_ETHLOG
*/
typedef struct sETHLOG_MsgType {
    uint32_t                    magic;  /**< @brief Magic                         */
    BCM_MsgType                 id;     /**< @brief Command ID of #ETHLOG_IDType  */
    int32_t                     status; /**< @brief Status                        */
    uint32_t                    len;    /**< @brief Length of the payload         */
    ETHLOG_MsgUnionType         u;      /**< @brief Payload                       */
} ETHLOG_MsgType;
BCM_STATIC_SIZE_ASSERT(ETHLOG_MsgType, 464UL, 464UL)

/**
    @brief Get the default log level

    Get the default log level

    @behavior Async, Non-reentrant

    @pre None

    @param[in]    aConnHdl    Connection handle (from RPC_Connect)
    @param[out]   aLevel      Pointer to the store the default log level

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Log level retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   aLevel is NULL
    @retval     #BCM_ERR_UNKNOWN        Integration fault

    @post None

    @trace #BRCM_SWREQ_ETHLOG

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t ETHLOG_GetDefaultLogLevel(BCM_HandleType aConnHdl,BCM_LogLevelType*  const aLevel);

/**
    @brief Set the default log level

    Set the default log level. This overrides any custom lower levels set for components.

    @behavior Async, Non-reentrant

    @pre None

    @param[in]    aConnHdl    Connection handle (from RPC_Connect)
    @param[in]    aLevel      Log level to set as default.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Log level retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   aLevel is invalid
    @retval     #BCM_ERR_UNKNOWN        Integration fault

    @post None

    @trace #BRCM_SWREQ_ETHLOG

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t ETHLOG_SetDefaultLogLevel(BCM_HandleType aConnHdl,BCM_LogLevelType aLevel);

/**
    @brief Get the log level for given component

    Get the log level for given component

    @behavior Async, Non-reentrant

    @pre None

    @param[in]    aConnHdl    Connection handle (from RPC_Connect)
    @param[in]    aCompId     Component ID.
    @param[out]   aLevel      Pointer to the store the log level of the given component

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Log level retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   aLevel is NULL
    @retval     #BCM_ERR_UNKNOWN        Integration fault

    @post None

    @trace #BRCM_SWREQ_ETHLOG

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t ETHLOG_GetCompLogLevel(BCM_HandleType aConnHdl, BCM_CompIDType aCompId, BCM_LogLevelType* const aLevel);

/**
    @brief Set the log level for given component

    Set the log level for given component

    @behavior Async, Non-reentrant

    @pre None

    @param[in]    aConnHdl    Connection handle (from RPC_Connect)
    @param[in]    aCompId     Component ID.
    @param[in]    aLevel       Log level to set for the given component

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Log level updated successfully
    @retval     #BCM_ERR_INVAL_PARAMS   aLevel is invalid
    @retval     #BCM_ERR_NOMEM          No memory to store new entries
    @retval     #BCM_ERR_UNKNOWN        Integration fault

    @post None

    @trace #BRCM_SWREQ_ETHLOG

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t ETHLOG_SetCompLogLevel(BCM_HandleType aConnHdl, BCM_CompIDType aCompId, BCM_LogLevelType aLevel);

/**
    @brief Get the log level for given component list

    Get the log level for given component list

    @behavior Async, Non-reentrant

    @pre None

    @param[in]    aConnHdl    Connection handle (from RPC_Connect)
    @param[in]    aCount      Number of components
    @param[inout] aCompState  Pointer to the Component IDs and levels.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Log level retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   aCompState is NULL
                                        aCount is 0 or more than allowed #ETHLOG_COMP_LIST_MAX_SIZE
    @retval     #BCM_ERR_UNKNOWN        Integration fault

    @post None

    @trace #BRCM_SWREQ_ETHLOG

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t ETHLOG_GetCompListLogLevel(BCM_HandleType aConnHdl, uint16_t aCount, ETHLOG_CompStateMsgType* const aCompState);

/**
    @brief Set the log level for given component list

    Set the log level for given component list

    @behavior Async, Non-reentrant

    @pre None

    @param[in]    aConnHdl    Connection handle (from RPC_Connect)
    @param[in]    aCount      Number of components
    @param[in]    aCompState  Pointer to the Component IDs and levels.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Log level retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   aCompState is NULL
                                        aCount is 0 or more than allowed #ETHLOG_COMP_LIST_MAX_SIZE
    @retval     #BCM_ERR_NOT_FOUND      aCompState entry is  not found
    @retval     #BCM_ERR_NOMEM          No memory to store new entries
    @retval     #BCM_ERR_UNKNOWN        Integration fault

    @post None

    @trace #BRCM_SWREQ_ETHLOG

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t ETHLOG_SetCompListLogLevel(BCM_HandleType aConnHdl, uint16_t aCount, const ETHLOG_CompStateMsgType* const aCompState);
#endif /* ETHLOG_LOG_H */
/** @} */
