/*****************************************************************************
 Copyright 2021-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_module_helper_ifc Helpers
    @ingroup grp_module

    @addtogroup grp_module_helper_ifc
    @{

    @file module_helper.h

    @brief Generic Module Handler Interface
    @version 0.1 Initial version
*/

#ifndef MODULE_HANDLER_H
#define MODULE_HANDLER_H

#include <module.h>
#include <osil/module_osil.h>

/**
    @name SYSTEM Module Handler API IDs
    @{
    @brief API IDs for Module Handler in System and underlying Subsystem
*/
#define BRCM_SWARCH_MODULE_SEND_CMD_PROC            (0x8302U)    /**< @brief #MODULE_SendCmd            */
#define BRCM_SWARCH_MODULE_GET_RESP_PROC            (0x8303U)    /**< @brief #MODULE_GetResp            */
#define BRCM_SWARCH_MODULE_MERGE_RESULT_PROC        (0x8304U)    /**< @brief #MODULE_MergeResult        */
#define BRCM_SWARCH_MODULE_PROCESS_CMD_PROC         (0x8306U)    /**< @brief #MODULE_ProcessCmd         */
#define BRCM_SWARCH_MODULE_RESET_STATE_HANDLER_PROC (0x8307U)    /**< @brief #MODULE_ResetStateHandler  */
#define BRCM_SWARCH_MODULE_INIT_STATE_HANDLER_PROC  (0x8308U)    /**< @brief #MODULE_InitStateHandler   */
#define BRCM_SWARCH_MODULE_READY_STATE_HANDLER_PROC (0x8309U)    /**< @brief #MODULE_ReadyStateHandler  */
#define BRCM_SWARCH_MODULE_RUN_STATE_HANDLER_PROC   (0x830AU)    /**< @brief #MODULE_RunStateHandler    */
#define BRCM_SWARCH_MODULE_GET_EVENT_MASK_PROC      (0x830BU)    /**< @brief #MODULE_GetEventMask       */
#define BRCM_SWARCH_MODULE_EVENT_HANDLER_PROC       (0x830CU)    /**< @brief #MODULE_EventHandler       */
#define BRCM_SWARCH_SERVICE_CLIENT_HANDLER_PROC     (0x830DU)    /**< @brief #SERVICE_ClientHandler     */
#define BRCM_SWARCH_SERVICE_SERVER_TASK_FUNC_PROC   (0x830EU)    /**< @brief #SERVICE_ServerTaskFunc    */
#define BRCM_SWARCH_MODULE_ASYNC_MSG_PROC           (0x830FU)    /**< @brief #MODULE_AsyncMsg           */
#define BRCM_SWARCH_SERVICE_LOCAL_SEND_CMD_PROC     (0x8310U)    /**< @brief #SERVICE_LocalSendCmd      */
#define BRCM_SWARCH_SERVICE_LOCAL_GET_RESP_PROC     (0x8311U)    /**< @brief #SERVICE_LocalGetResp      */
#define BRCM_SWARCH_SERVICE_LOCAL_GET_CTX_HDL_PROC  (0x8312U)    /**< @brief #SERVICE_LocalGetCtxHdl    */

#define BRCM_SWARCH_MODULE_PROF_MSG_COUNT_MACRO     (0x8320U)    /**< @brief #MODULE_PROF_MSG_COUNT     */
#define BRCM_SWARCH_MODULE_PROF_DATA_TYPE           (0x8321U)    /**< @brief #MODULE_ProfDataType       */
#define BRCM_SWARCH_MODULE_PROF_CONTEXT_TYPE        (0x8322U)    /**< @brief #MODULE_ProfContextType    */
#define BRCM_SWARCH_MODULE_PROF_CONTEXT_GLOBAL      (0x8323U)    /**< @brief #MODULE_ProfContext        */
#define BRCM_SWARCH_MODULE_PROF_ADD_MSG_PROC        (0x8324U)    /**< @brief #MODULE_AddProfMsg         */
#define BRCM_SWARCH_MODULE_STATEHANDLER_PROC        (0x8325U)    /**< @brief #MODULE_StateHandler       */
#define BRCM_SWARCH_MODULE_CUST_PROGRAM_PROC        (0x8326U)    /**< @brief #MODULE_CustProgram        */
/** @} */


/** @brief Helper function to tranisiton modules from UNINIT->INIT state

    This function transitions all the modules in the pipeline sequentially
    to the BCM_STATE_INIT state

    This function follows architecture defined at @ref MODULE_StateHandlerType
    with below deltas
    @param[in]   aModules       Modules
    @param[in]   aCnt           Count of modules

    Requested state is always assumed to be #BCM_STATE_INIT

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_ResetStateHandler(const MODULE_Type * const *aModules, uint32_t aCnt);

/**
    @brief Helper function to tranisiton modules from INIT->READY state

    This function transitions all the modules in the pipeline sequentially
    to the BCM_STATE_READY state

    This function follows architecture defined at @ref MODULE_StateHandlerType
    with below deltas
    @param[in]   aModules       Modules
    @param[in]   aCnt           Count of modules

    Requested state is always assumed to be #BCM_STATE_READY

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_InitStateHandler(const MODULE_Type * const *aModules, uint32_t aCnt);

/**
    @brief Helper function to tranisiton modules from READY->RUN
    or READY->UNINIT state

    This function transitions all the modules in the pipeline sequentially
    to the BCM_STATE_RUN/BCM_STATE_UNINIT state based on #(aReqState) value

    This function follows architecture defined at @ref MODULE_StateHandlerType
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules
    @param[in]   aRequestedState    Requested state is either #BCM_STATE_RUN
                                    or #BCM_STATE_UNINIT

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_ReadyStateHandler(const MODULE_Type * const *aModules,
                                uint32_t aCnt, BCM_StateType aReqState);

/**
    @brief Helper function to tranisiton modules from RUN->READY
    or RUN->UNINIT state

    This function transitions all the modules in the pipeline sequentially
    to the BCM_STATE_READY/BCM_STATE_UNINIT state based on #(aReqState) value

    This function follows architecture defined at @ref MODULE_StateHandlerType
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules
    @param[in]   aRequestedState    Requested state is either #BCM_STATE_RUN
                                    or #BCM_STATE_UNINIT

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_RunStateHandler(const MODULE_Type * const *aModules,
                                uint32_t aCnt, BCM_StateType aReqState);

/**
    @brief Helper function to get the unified mask

    This function fetches the event mask for each module in the list and
    returns it to caller

    This function follows architecture defined at @ref MODULE_GetEventMaskType
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules

    @trace #BRCM_SWREQ_MODULE
*/
uint32_t MODULE_GetEventMask(const MODULE_Type * const *aModules, uint32_t aCnt);

/**
    @brief Helper function to handle events

    This function passes the event to the modules

    This function follows architecture defined at @ref MODULE_EventHandlerType
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules
    @param[in]   aEventMask         Event mask

    @trace #BRCM_SWREQ_MODULE
*/
void MODULE_EventHandler(const MODULE_Type * const *aModules,
                             uint32_t aCnt, uint32_t aEventMask);

/**
    @brief Helper function to send command

    This function sends the command by passing it to the appropriate module

    This function follows architecture defined at @ref MODULE_SendCmdType
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_SendCmd(const MODULE_Type  * const*aModules, uint32_t    aCnt,
                       BCM_MsgType     aCmd,
                       uint32_t        aCmdDataLen, const uint8_t *aCmdData,
                       BCM_HandleType  *aHandle,    uint32_t      *aForwardToSlaves,
                       BCM_BoolType    aTrusted);

/**
    @brief Helper function to get response for a command

    This function gets the response for previously posted command
    by querying it from the appropriate module

    This function follows architecture defined at @ref MODULE_GetRespV2Type
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_GetResp(const MODULE_Type  * const *aModules, uint32_t    aCnt,
                       BCM_HandleType  aHandle,
                       BCM_MsgType   aReplyID, uint32_t  aInLen,
                       uint8_t     *aReplyData, uint32_t   *aOutLen,
                       int32_t     *aResponse, uint32_t  *aProgress);

/**
    @brief Helper function to process command

    This function processes the command by passing it to the appropriate module

    This function follows architecture defined at @ref MODULE_ProcessCmdType
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_ProcessCmd(const MODULE_Type  * const *aModules, uint32_t   aCnt,
                          BCM_MsgType     aCmd,
                          BCM_SubStateType    *const aCmdState, uint8_t *const aCmdData,
                          uint32_t    aLen, uint32_t   *const aReplyLen);

/**
    @brief Helper function to merge result

    This function merges the result by passing it to the appropriate module

    This function follows architecture defined at @ref MODULE_MergeResultType
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_MergeResult(const MODULE_Type  * const *aModules, uint32_t aCnt,
                           BCM_MsgType aCmd,
                           uint32_t     aLen, uint8_t  *aOutResponse, int32_t   *aOutResult,
                           const uint8_t  *aInResponse1, int32_t    aInResult1,
                           const uint8_t  *aInResponse2, int32_t     aInResult2);

/**
    @brief Helper function to send async message

    This function sends the async message got from the slave device to
    the appropriate module on the master device

    This function follows architecture defined at @ref MODULE_AsyncNotifType
    with below deltas
    @param[in]   aModules           Modules
    @param[in]   aCnt               Count of modules

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_AsyncMsg(const MODULE_Type * const *aModules,
                        uint32_t aCnt,
                        BCM_MsgType aNotfn,
                        const uint8_t *aMsg,
                        uint32_t aLen,
                        uint32_t *aForwardToHost);

/** @brief Helper function to tranisiton modules

    This function transitions all the modules in the pipeline sequentially
    to the requested state

    This function follows architecture defined at @ref MODULE_StateHandlerType
    with below deltas
    @param[in]   aModules       Modules
    @param[in]   aCurrState     Current state of the module

    @trace #BRCM_SWREQ_MODULE
*/
int32_t MODULE_StateHandler(const MODULE_Type * const aModule,
                            BCM_StateType aCurrState, BCM_StateType aReqState);

/** @brief Helper function to custom program

    This function used to do custom program on the registers defined in board
    configuration binary when the state transition of module happened.

    @pre None

    @param[in]   aCompID       Component ID
    @param[in]   aState        Module state

    @retval      void

    @post The register writes for component ID & module state happened

    @trace #BRCM_SWREQ_MODULE
*/
void MODULE_CustProgram(const BCM_CompIDType aCompID, const BCM_StateType aState);

/** @brief Service state change handler (runs in client context)

    Send state change requests to the service.

    This function follows architecture defined at @ref MODULE_StateHandlerType
    with below deltas

    @param[inout]   aService            Service which needs to be transitioned
                                        (context gets updated)
    @param[in]      aRequestedState     The next state to which service needs to transition

    @trace #BRCM_SWREQ_SERVICE
*/
int32_t SERVICE_ClientHandler(const SERVICE_Type *aService, BCM_StateType aRequestedState);

/** @brief Service handler (runs in service task context)

    Process the state change requests received from client, events set by other
    tasks, commands posted into the message queue. This API must be executed in
    a dedicated task.

    @behavior Async, Non-reentrant

    @pre None

    @param[inout]   aService    Service which needs to be transitioned
    @param[in]      aTask       Task in which Service is running

    @return     void

    @post None

    @trace #BRCM_SWREQ_SERVICE
*/
void SERVICE_ServerTaskFunc(const SERVICE_Type *aService, uint32_t aTask);

/** @brief Service helper to send commands to modules

    Process the component ID received from client and sends the message to
    corresponding module's command message queue.

    @behavior Async, Non-reentrant

    @pre None

    @param[in]   aService     Service
    @param[in]   aMsgId       Message ID
    @param[in]   aMsg         Pointer to the message
    @param[in]   aMsgLen      Message length in bytes
    @param[in]   aClientMask  Client signal mask
    @param[out]  aHandle      Pointer to #BCM_HandleType
    @param[in]   aTrusted     Boolean to indicate the trusted source
                              TRUE - Trusted; FALSE - Non Trusted

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Message is successfully queued to the
                                        message queue.
    @retval     #BCM_ERR_INVAL_PARAMS   aMsgId is not valid
    @retval     #BCM_ERR_INVAL_PARAMS   aService is NULL
    @return     As returned by @MODULE_SendCmd

    @post None

    @trace #BRCM_SWREQ_SERVICE
*/
int32_t SERVICE_LocalSendCmd(const SERVICE_Type *aService, BCM_MsgType aMsgId,
                                const uint8_t* const aMsg, const uint32_t aMsgLen,
                                const uint32_t aClientMask, BCM_HandleType* const aHandle,
                                BCM_BoolType   aTrusted);

/** @brief Service helper to receive responses from modules

    Process the component ID received from client and receives the message from
    corresponding module's command message queue.

    @behavior Async, Non-reentrant

    @pre None

    @param[in]   aService     Service
    @param[in]   aReplyId     Message ID
    @param[in]   aHandle      Message handle
    @param[in]   aInLen       Reply Payload size in bytes
    @param[out]  aReplyData   Pointer to reply payload
    @param[out]  aOutLen      Reply payload filled length in bytes
    @param[out]  aResponse    Pointer to store the message response
    @param[out]  aProgress    Pointer to store the progress

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Message is successfully retrieved from the
                                        message queue.
    @retval     #BCM_ERR_INVAL_PARAMS   aReplyId is not valid
    @retval     #BCM_ERR_INVAL_PARAMS   aService is NULL
    @return     As returned by @MODULE_GetResp

    @post None

    @trace #BRCM_SWREQ_SERVICE
*/
int32_t SERVICE_LocalGetResp(const SERVICE_Type *aService, BCM_MsgType aReplyId, BCM_HandleType aHandle,
                                uint32_t  aInLen, uint8_t *aReplyData, uint32_t *aOutLen,
                                int32_t *aResponse, uint32_t *aProgress);

/** @brief Service helper to get context handle from message handle

    Process the component ID received from client and gets the context handle using the job handle
    from command message queue.

    @behavior Async, Non-reentrant

    @pre None

    @param[in]   aService     Service
    @param[in]   aCompID      Module component ID
    @param[in]   aHandle      Job handle

    @return Context handle if valid else #MSGQ_HDL_INVALID

    @post None

    @trace #BRCM_SWREQ_SERVICE
*/
BCM_HandleType SERVICE_LocalGetCtxHdl(const SERVICE_Type *aService, BCM_CompIDType aCompID, BCM_HandleType aJobHdl);

/**
    @brief Maximum Profiling messages

    @trace #BRCM_SWREQ_MODULE
*/
#define MODULE_PROF_MSG_COUNT    (1UL)

/**
    @brief Module Profiling Message Type

    @trace #BRCM_SWREQ_MODULE
*/
typedef struct sMODULE_ProfDataType {
    BCM_CompIDType      comp;
    uint16_t            line;
    BCM_StateType       state;
    uint32_t            profTime;
    uint32_t            misc;
} MODULE_ProfDataType;

/**
    @brief Module Profiling Context Type

    @trace #BRCM_SWREQ_MODULE
*/
typedef struct sMODULE_ProfContextType {
    uint32_t                count;
    MODULE_ProfDataType      msgs[MODULE_PROF_MSG_COUNT];
} MODULE_ProfContextType;

/**
    @brief Module Profiling Context

    @trace #BRCM_SWREQ_MODULE
*/
extern MODULE_ProfContextType MODULE_ProfContext;

/** @brief Add Profiling message

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]   aComp      Component ID
    @param[in]   aLine      Line Number
    @param[in]   aState     State
    @param[in]   aTime      Time in milliseconds
    @param[in]   aMisc      Any 32-bit number

    @return     void

    @post None

    @limitations None

    @trace #BRCM_SWREQ_MODULE
*/
static inline void MODULE_AddProfMsg(BCM_CompIDType aComp, uint16_t aLine,
                            BCM_StateType aState, uint32_t aTime, uint32_t aMisc)
{
    uint32_t cnt = MODULE_ProfContext.count;
    if (cnt < MODULE_PROF_MSG_COUNT) {
        MODULE_ProfContext.msgs[cnt].comp = aComp;
        MODULE_ProfContext.msgs[cnt].line = aLine;
        MODULE_ProfContext.msgs[cnt].profTime =  aTime;
        MODULE_ProfContext.msgs[cnt].state = aState;
        MODULE_ProfContext.msgs[cnt].misc = aMisc;
        MODULE_ProfContext.count++;
    }
}


#endif /* MODULE_HANDLER_H */
/** @} */
