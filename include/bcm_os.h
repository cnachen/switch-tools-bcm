/*****************************************************************************
 Copyright 2019-2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_abstract_os OS Function Wrappers
    @ingroup grp_abstract

    @addtogroup grp_abstract_os
    @{
    This file specifies common utility wrappers for C Standard library APIs

    file osil/bcm_osil.h
    brief C Standard library wrapper functiions

    @version 1.0 Initial Version
*/

#include <bcm_err.h>
#include <stdint.h>
#include <inttypes.h>
#include <bcm_comp.h>

#ifndef BCM_OS_H
#define BCM_OS_H

/**
    @name  OS wrapper functions Architecture IDs
    @{
    @brief Architecture IDs for OS wrapper functions
*/
#define BRCM_SWARCH_BCM_EVENTMASK_TYPE            (0x8601U)    /**< @brief #BCM_EventMaskType       */
#define BRCM_SWARCH_BCM_TASK_TYPE                 (0x8602U)    /**< @brief #BCM_TaskType            */
#define BRCM_SWARCH_BCM_APPMODE_TYPE              (0x8603U)    /**< @brief #BCM_AppModeType         */
#define BRCM_SWARCH_BCM_OS_WAITEVENT_PROC         (0x8604U)    /**< @brief #BCM_WaitEvent           */
#define BRCM_SWARCH_BCM_OS_SETEVENT_PROC          (0x8605U)    /**< @brief #BCM_SetEvent            */
#define BRCM_SWARCH_BCM_OS_GETEVENT_PROC          (0x8606U)    /**< @brief #BCM_GetEvent            */
#define BRCM_SWARCH_BCM_OS_CLEAREVENT_PROC        (0x8607U)    /**< @brief #BCM_ClearEvent          */
#define BRCM_SWARCH_BCM_OS_ACTIVATETASK_PROC      (0x8608U)    /**< @brief #BCM_ActivateTask        */
#define BRCM_SWARCH_BCM_OS_TERMINATETASK_PROC     (0x8609U)    /**< @brief #BCM_TerminateTask       */
#define BRCM_SWARCH_BCM_OS_THRNOTTERMINAT_PROC    (0x860AU)    /**< @brief #BCM_ThreadNotTerminated */
#define BRCM_SWARCH_BCM_OS_STRTOS_PROC            (0x860BU)    /**< @brief #BCM_StartOS             */
#define BRCM_SWARCH_BCM_OS_SETRELALARM_PROC       (0x860CU)    /**< @brief #BCM_SetRelAlarm         */
#define BRCM_SWARCH_BCM_ALARM_TYPE                (0x860DU)    /**< @brief #BCM_AlarmType           */
#define BRCM_SWARCH_BCM_TICK_TYPE                 (0x860EU)    /**< @brief #BCM_TickType            */
#define BRCM_SWARCH_BCM_TASK_STATE                (0x860FU)    /**< @brief #BCM_TaskStateType       */
#define BRCM_SWARCH_BCM_OS_CANCELALARM_PROC       (0x8610U)    /**< @brief #BCM_CancelAlarm         */
#define BRCM_SWARCH_BCM_ENTRY_POINT_TYPE          (0x8611U)    /**< @brief #BCM_EntryPtType         */
#define BRCM_SWARCH_BCM_EXEC_HANDOVER_PROC        (0x8612U)    /**< @brief #BCM_ExecHandover        */
#define BRCM_SWARCH_BCM_OS_INCREMENTCOUNTER_PROC  (0x8613U)    /**< @brief #BCM_IncrementCounter    */
#define BRCM_SWARCH_BCM_GET_TASK_ID_PROC          (0x8614U)    /**< @brief #BCM_GetTaskID           */
#define BRCM_SWARCH_BCM_GET_TASK_STATE_PROC       (0x8615U)    /**< @brief #BCM_GetTaskState        */
#define BRCM_SWARCH_BCM_NOTIFYEVENT_PROC          (0x8616U)    /**< @brief #BCM_NotifyEvent         */
/** @} */


/**
    @brief Data type of the event mask.

    Data type to store the event mask

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
typedef uint32_t BCM_EventMaskType;

/**
    @brief Data Type to identify a task

    This data type identifies a task.

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
typedef uint32_t BCM_TaskType;

/**
    @brief BCM_AppModeType

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
typedef uint32_t BCM_AppModeType;

/**
    @brief Data Type to store Alarm identifier.

    This data type stores Alarm identifier.

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
typedef uint32_t BCM_AlarmType;

/**
    @brief Data Type to store counter ticks.

    This data type stores counter ticks.

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
typedef uint32_t BCM_TickType;

/**
    @{
    @brief Data Type to store task state.

    This data type stores task state.

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
typedef uint32_t BCM_TaskStateType;
#define BCM_TASK_STATE_RUNNING   (0UL)
#define BCM_TASK_STATE_WAITING   (1UL)
#define BCM_TASK_STATE_READY     (2UL)
#define BCM_TASK_STATE_SUSPENDED (3UL)
/** @} */

/** @brief Wait event wrapper function

    This funtion takes event mask and waits for one of those events.

    @behavior Sync, Re-entrant

    @pre Event should be allowed for the task

    @param[in]   aEventMask           input event mask

    @retVal      BCM_ERR_OK           if BCM_WaitEvent executed successfully
    @retVal      BCM_ERR_UNKNOWN      if BCM_WaitEvent returns unknown value
    @retVal      BCM_ERR_NOPERM       if calling task is not an extended task
    @retVal      BCM_ERR_BUSY         if calling task occupies resources
    @retVal      BCM_ERR_INVAL_STATE  if being called at interrupt level

    @post successfully executed BCM_WaitEvent and one or more events are set

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_WaitEvent(BCM_EventMaskType aEventMask);

/** @brief Set event wrapper function

    This function sets an Event on a given Task with a given Mask

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aTaskID               task ID
    @param[in]   aEventMask            input event mask

    @retVal      BCM_ERR_OK            if BCM_SetEvent executed successfully
    @retVal      BCM_ERR_UNKNOWN       if BCM_SetEvent returns unknown value
    @retVal      BCM_ERR_INVAL_PARAMS  if input task is invalid
    @retVal      BCM_ERR_NOPERM        if referenced task is not an extended task
    @retVal      BCM_ERR_INVAL_STATE   if the referenced task is in suspended state

    @post successfully executed BCM_SetEvent and the events of given task are set according to the event mask.

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_SetEvent(BCM_TaskType aTaskID, BCM_EventMaskType aEventMask);

/** @brief Get event wrapper

    This function gets EventMask set on a given task

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aTaskID               task ID
    @param[in]   aEventMask            pointer to store event mask

    @retVal      BCM_ERR_OK            if BCM_GetEvent executed successfully
    @retVal      BCM_ERR_UNKNOWN       if BCM_GetEvent returns unknown value
    @retVal      BCM_ERR_INVAL_PARAMS  if input task is invalid
    @retVal      BCM_ERR_NOPERM        if referenced task is not an extended task
    @retVal      BCM_ERR_INVAL_STATE   if the referenced task is in suspended state

    @post successfully executed BCM_GetEvent and returns the current state of all event bits of the input task

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_GetEvent(BCM_TaskType aTaskID, BCM_EventMaskType *aEventMask);

/** @brief Clear event wrapper

    This function Clears an Event for given Task and Mask

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aEventMask           input event mask

    @retVal      BCM_ERR_OK           if BCM_ClearEvent executed successfully
    @retVal      BCM_ERR_UNKNOWN      if BCM_ClearEvent returns unknown value
    @retVal      BCM_ERR_NOPERM       if call is not from an extended task
    @retVal      BCM_ERR_INVAL_STATE  if being called at interrupt level

    @post successfully executed BCM_ClearEvent and the events of the task calling BCM_ClearEvent are cleared
    according to the event mask

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_ClearEvent(BCM_EventMaskType aEventMask);

/** @brief BCM_ActivateTask wrapper

    This function activates a task

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aTaskID               task ID

    @retVal      BCM_ERR_OK            if BCM_ActivateTask executed successfully
    @retVal      BCM_ERR_UNKNOWN       if BCM_ActivateTask returns unknown value
    @retVal      BCM_ERR_MAX_ATTEMPS   if too many activations of given task
    @retVal      BCM_ERR_INVAL_PARAMS  if input task is invalid

    @post successfully executed BCM_ActivateTask and the task is transferred from the suspended state into the ready state.

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_ActivateTask(BCM_TaskType aTaskID);

/** @brief BCM_TerminateTask wrapper

    This function terminates a task

    @behavior Sync, Re-entrant

    @pre None

    @retVal      Never reaches this upon succesfull termination
    @retVal      BCM_ERR_UNKNOWN         Termination failed. Unknown reason
    @retVal      BCM_ERR_BUSY            Task is still holding resources
    @retVal      BCM_ERR_INVAL_STATE     Couldn't terminate. Called at interrupt level

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_TerminateTask(void);

/** @brief ThreadNotTerminated wrapper

    @pre None

    @retVal      None

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern void BCM_ThreadNotTerminated(void);

/** @brief StartOS wrapper

    @pre None

    @retVal      None

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_StartOS(BCM_AppModeType aMode);

/** @brief BCM_SetRelAlarm wrapper

    This function to set relative alarm

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aAlarmID              Alarm identifier
    @param[in]   aIncrement            Relative value in ticks representing the
                                       offset with respect to the current
                                       time of the first alarm expiration.
    @param[in]   aCycle                Cycle value in case of cyclic alarm.
                                       In case of single alarms, this parameter
                                       must be set to 0.

    @retVal      BCM_ERR_OK            BCM_SetRelAlarm successful
    @retVal      BCM_ERR_UNKNOWN       If BCM_SetRelAlarm returns unknown value
    @retVal      BCM_ERR_INVAL_STATE   Alarm already in use
    @retVal      BCM_ERR_INVAL_PARAMS  (aAlarm is invalid) or
                                       (aIncrement is 0UL) or
                                       (aIncrement is greater than counter limit)

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_SetRelAlarm(BCM_AlarmType aAlarmID,
                                BCM_TickType aIncrement,
                                BCM_TickType aCycle);
/** @brief BCM_CancelAlarm wrapper

    This function to cancel alarm

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aAlarmID              Alarm identifier

    @retVal      BCM_ERR_OK            BCM_SetRelAlarm successful
    @retVal      BCM_ERR_UNKNOWN       If BCM_SetRelAlarm returns unknown value
    @retVal      BCM_ERR_INVAL_STATE   Alarm already in use
    @retVal      BCM_ERR_INVAL_PARAMS  (aAlarm is invalid)

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_CancelAlarm(BCM_AlarmType aAlarmID);

/** @brief Entry Point for loaded firmware image

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]    void

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_OS_WRAPPER
*/
typedef void (*BCM_EntryPtType)(void);

/** @brief Handover execution from ROM to bootloader or bootloader to firmware

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]   aEntryPt              Entry Point

    @retVal      BCM_ERR_UNKNOWN       Integration fault

    @post This function does not return unless there is an integration fault

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_ExecHandover(BCM_EntryPtType aEntryPt);

/** @brief Increment the counter

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]   aCounter              The counter to be incremented

    @retVal      BCM_ERR_OK            BCM_IncrementCounter successful
    @retVal      BCM_ERR_INVAL_PARAMS  If counter ID is invalid

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_IncrementCounter(const uint32_t aCounter);

/** @brief Get the current task ID

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]   aCurTaskID            Pointer to store the task ID

    @retVal      BCM_ERR_OK            BCM_GetTaskID successful
    @retVal      BCM_ERR_INVAL_PARAMS  If aCurTaskID is NULL

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_GetTaskID(BCM_TaskType * const aCurTaskID);

/** @brief Get the task state

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]   aTaskId               Task ID
    @param[in]   aTaskState            Pointer to store the task state

    @retVal      BCM_ERR_OK            BCM_GetTaskState successful
    @retVal      BCM_ERR_INVAL_PARAMS  If aTaskState is NULL or aTaskId is invalid task

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER
*/
extern int32_t BCM_GetTaskState(const BCM_TaskType aTaskId, BCM_TaskStateType *aTaskState);

/**
    @brief Helper function to notify a component

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aMsgId          Notification Handle
    @param[in]      aData           Custom data
    @param[in]      aCompList       List of components to be notified
    @param[in]      aCompCount      Total number of components to be notified

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Notification msg has been successfully posted to all the components
    @retval         #BCM_ERR_INVAL_PARAMS     Invalid arguments either aMsgId is 0ULL or aCompList is NULL
    @retval         #BCM_ERR_UNKNOWN          Unable to sent the msg to all the registered components

    @post None

    @trace  #BRCM_SWREQ_BCM_OS_WRAPPER

    @limitations None
*/
extern int32_t BCM_NotifyEvent(BCM_MsgType aMsgId,
                               BCM_NotifyDataType const *aData,
                               const BCM_CompIDType *const aCompList,
                               uint32_t aCompCount);
#endif /* BCM_OS_H */

/** @} */
