/*****************************************************************************
 Copyright 2019-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_wdgse_ifc Interface
    @ingroup grp_wdgse

    @addtogroup grp_wdgse_ifc
    @{
    @section sec_system_wdg_ifc_seq Sequence Diagram

    @tagseq wdgse_seq_diagram.svg "Watchdog Supervision Entity Sequence Diagram"
    @startseq
    group {label = "client"; color = "#EFFFFF";  Client;};
    group {label = "monitor"; color = "#FFFFEF"; Monitor; WDGSE;};
    Client => WDGSE [label = "WDGSE_Enable"];
    loop {
        Client => WDGSE [label = "WDGSE_NotifyState"];
        Monitor => WDGSE [label = "WDGSE_Monitor"];
    };
    Client => WDGSE [label = "WDGSE_Disable"];
    @endseq

    @section sec_system_wdg_ifc_fsm State Machine

    @tagfsm wdgse_state_machine.svg "Watchdog Supervision Entity state machine"
    @startfsm
    INIT; DEINIT;
    begin -> DEINIT;
    DEINIT -> INIT [label="WDGSE_Enable"];
    INIT -> INIT [label="WDGSE_NotifyState"];
    INIT -> INIT [label="WDGSE_Monitor"];
    INIT -> DEINIT [label="WDGSE_Disable"];
    @endfsm

    The Watchdog Supervision Entity (WDGSE) shall be in DEINIT state at start.
    Upon initialization, WDGSE moves to the INIT state. On deinitialization, it
    moves back to the DEINIT state.

    @file wdgse.h
    @brief This header file contains the interface for Watchdog Supervision Entity

    @version 0.21 Rename WDGSE_Type to WDGSE_InfoType
    @version 0.2  Update return values for #WDGSE_Monitor and fixed typos
    @version 0.1  Initial Version
*/

#ifndef WDGSE_H
#define WDGSE_H

#include <stddef.h>
#include <inttypes.h>
#include <bcm_err.h>
#include <bcm_utils.h>

/**
    @name Watchdog Service Architecture IDs
    @{
    @brief Architecture IDs for Watchdog
*/
#define BRCM_SWARCH_WDGSE_MODE_MACRO                    (0x8501U)    /**< @brief #WDGSE_ModeType                */
#define BRCM_SWARCH_WDGSE_CONFIG_TYPE                   (0x8502U)    /**< @brief #WDGSE_ConfigType              */
#define BRCM_SWARCH_WDGSE_CONTEXT_TYPE                  (0x8503U)    /**< @brief #WDGSE_ContextType             */
#define BRCM_SWARCH_WDGSE_MONITOR_TYPE                  (0x8504U)    /**< @brief #WDGSE_MonitorType             */
#define BRCM_SWARCH_WDGSE_STATE_TYPE                    (0x8505U)    /**< @brief #WDGSE_StateType               */
#define BRCM_SWARCH_WDGSE_INFO_TYPE                     (0x8506U)    /**< @brief #WDGSE_InfoType                */
#define BRCM_SWARCH_WDGSE_ENABLE_PROC                   (0x8507U)    /**< @brief #WDGSE_Enable                  */
#define BRCM_SWARCH_WDGSE_NOTIFYSTATE_PROC              (0x8508U)    /**< @brief #WDGSE_NotifyState             */
#define BRCM_SWARCH_WDGSE_DISABLE_PROC                  (0x8509U)    /**< @brief #WDGSE_Disable                 */
#define BRCM_SWARCH_WDGSE_INVALID_GRAPH_BUF_ENTRY_MACRO (0x850AU)    /**< @brief #WDGSE_INVALID_GRAPH_BUF_ENTRY */
#define BRCM_SWARCH_WDGSE_MAGIC_MACRO                   (0x850BU)    /**< @brief #WDGSE_MAGIC                   */
#define BRCM_SWARCH_WDGSE_CALLBACK_TYPE                 (0x850CU)    /**< @brief #WDGSE_CbType                  */
#define BRCM_SWARCH_WDGSE_MONITOR_PROC                  (0x850DU)    /**< @brief #WDGSE_Monitor                 */
/** @} */

/**
    @brief Invalid entry for a SE graph

    Value to be used to indicate a empty entry for the transition
    graph within a SE.

    @trace #BRCM_SWREQ_WDGSE
 */
#define WDGSE_INVALID_GRAPH_BUF_ENTRY (0xFFU)

/**
    @brief Magic for Supervised Entity structure

    Magic value to be used within the SE structure, #WDGSE_InfoType

    @trace #BRCM_SWREQ_WDGSE
 */
#define WDGSE_MAGIC                (0x57445330UL)

/**
    @name Watchdog Supervision Entity Mode Type
    @{
    @brief Watchdog Supervision Entity Mode Type Mask

    @trace #BRCM_SWREQ_WDGSE
*/
typedef uint32_t WDGSE_ModeType;
#define WDGSE_MODE_NONE         (0x0UL) /**< @brief No monitoring */
#define WDGSE_MODE_LOGICAL      (0x1UL) /**< @brief Logical monitoring mask */
#define WDGSE_MODE_DEADLINE     (0x2UL) /**< @brief Deadline monitoring mask */
#define WDGSE_MODE_FREQ         (0x4UL) /**< @brief Frequency monitoring mask */
/** @} */

/**
    @brief Watchdog Supervision Entity configuration

    Watchdog Supervision Entity configuration to be provided by client.

    @trace #BRCM_SWREQ_WDGSE
 */
typedef struct sWDGSE_ConfigType {
    WDGSE_ModeType  mode;          /**< @brief Enabled Supervision modes(s) */
    uint32_t        deadlineInMs;  /**< @brief Deadline for state transition
                                               graph traversal from start state
                                               to end state */
    uint32_t        minFrequency;  /**< @brief Minimum number of times the graph
                                               shall execute (from start to
                                               end) in
                                                #WDGSE_CHECK_TIME_US time */
    uint32_t        maxFrequency;  /**< @brief Maximum number of times the graph
                                               shall execute (from start to
                                               end) in #WDGSE_CHECK_TIME_US time */
    uint8_t         lStart;        /**< @brief Start index in graph where client
                                               shall enter (first event in flow),
                                               typically zero */
    uint8_t         lEnd;          /**< @brief End index in graph where client
                                                shall exit (last event in flow) */
} WDGSE_ConfigType;
BCM_STATIC_SIZE_ASSERT(WDGSE_ConfigType, 20UL, 20UL)

/**
    @brief Watchdog Supervision Entity context

    This structure is typically updated in the context of the component through
    #WDGSE_Enable, #WDGSE_Disable, and #WDGSE_NotifyState

    @trace #BRCM_SWREQ_WDGSE
 */
typedef struct sWDGSE_ContextType {
    uint32_t            isActive;   /**< @brief 0UL - SE not entered start,
                                         1UL - SE entered start */
    volatile uint64_t   cTime;      /**< @brief Time at which the monitored
                                                component entered graph */
    volatile uint64_t   counter;    /**< @brief Counter to hold graph entry
                                                count */
    volatile uint32_t   lErrorCnt;  /**< @brief Detected logical error count  */
    volatile uint32_t   dErrorCnt;  /**< @brief Detected deadline error count */
    WDGSE_ConfigType    config;     /**< @brief Supervision Entity configuration */
    uint8_t             lCurrent;   /**< @brief Current logical state in graph,
                                                valid only if isActive is 1UL */
} WDGSE_ContextType;
BCM_STATIC_SIZE_ASSERT(WDGSE_ContextType, 56UL, 56UL)

/**
    @brief Watchdog Supervision Sntity Monitor type

    This structure holds previous mode and counter of the Supervision Entity
    when #WDGSE_Monitor was called previously. Content is updated only in
    #WDG_Init and #WDGSE_Monitor contexts. #WDGSE_Monitor could monitor new
    values against old snapshot and decide if new errors are detected for
    reporting.

    The Old mode is relevant during the start of frequency monitoring. It is
    possible that, the Watchdog monitoring cycle is not aligned to Supervision
    Entity execution. For the first cycle of monitoring (after WDGSE is
    enabled), it is OK to have a frequency count not in limits. To handle this
    scenario, old mode is preserved.

    @trace #BRCM_SWREQ_WDGSE
 */
typedef struct sWDGSE_MonitorType {
    WDGSE_ModeType  mode;       /**< @brief Previously enabled mode(s) */
    uint64_t        counter;    /**< @brief Previous counter to hold graph entry
                                            count */
    uint32_t        lErrorCnt;  /**< @brief Previously detected Logical error
                                            count */
    uint32_t        fErrorCnt;  /**< @brief Previously detected Frequency error
                                            count */
    uint32_t        dErrorCnt;  /**< @brief Previously detected Deadline error
                                            count */
} WDGSE_MonitorType;
BCM_STATIC_SIZE_ASSERT(WDGSE_MonitorType, 32UL, 32UL)

/** @brief WDG Callback to be raised by #WDGSE_Monitor

    This callback shall be raised by #WDGSE_Monitor function when an error
    is detected. Error value is also passed as part of the callback. This API
    shall not block the execution (no calls to WaitEvent in this context).

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aName               Name of Watchdog Supersvision Entity
                                        (for information)
    @param[in]      aError              #BCM_ERR_CUSTOM when errors are detected
                                        #BCM_ERR_MAX_ATTEMPS when errors reach
                                        max limit
    @param[in]      aMonitor            Monitor structure containing error
                                        information
    @param[in]      aMaxAllowedErrors   Maximum errors allowed by WDGSE

    @return void

    @post None

    @trace #BRCM_SWREQ_WDGSE

    @limitations This callback shall not block the execution context (No calls
    to WaitEvent allowed)
*/
typedef void (*WDGSE_CbType)(const char * aName, int32_t aError,
                             const WDGSE_MonitorType *aMonitor,
                             uint32_t aMaxAllowedErrors);

/**
    @brief Graph Buffer type

    @trace #BRCM_SWREQ_WDGSE
*/
typedef uint8_t WDGSE_StateType;

/**
    @brief Structure for a supervision entity

    @trace #BRCM_SWREQ_WDGSE
*/
typedef struct sWDGSE_InfoType {
    uint32_t            magic;      /**< @brief Magic value: #WDGSE_MAGIC */
    const char          *name;      /**< @brief Name of Supervision Entity */
    WDGSE_ContextType   *context;   /**< @brief Context pointer */
    WDGSE_MonitorType   *monitor;   /**< @brief Monitor context */
    WDGSE_StateType     *buffer;    /**< @brief State transition graph buffer:
                                         Allowed transitions for i'th state are located in
                                         buffer[i * maxTransitionsPerState] to
                                         buffer[(i+1) * maxTransitionsPerState - 1] */
    WDGSE_CbType    callback;          /**< @brief Callback to be raised when
                                                   errors are detected */
    uint32_t        maxAllowedErrors;  /**< @brief Maximum allowed number of
                                                   errors that can be
                                                   tolerated */
    uint8_t         maxState;          /**< @brief Maximum number of states
                                                   possible for component */
    uint8_t         maxTransitionsPerState; /**< @brief Maximum number of state
                                                        transitions possible
                                                        per state */
} WDGSE_InfoType;

/** @brief Enable Watchdog Supervision Entity monitoring

    This API enables the Watchdog Supervision Entity. The API also updates
    mode in #WDGSE_ContextType with that provided as part of @a aConfig

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aSE         Supervision Entity
    @param[in]      aConfig     WDGSE configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_INVAL_PARAMS   aSE is NULL or aConfig is NULL or
                                        if the configured mode is invalid or
                                        if lStart or lEnd in configuration is
                                        more than maxState
    @retval     #BCM_ERR_INVAL_MAGIC    aSE has invalid magic
    @retval     #BCM_ERR_INVAL_STATE    aSE is not in disabled state
    @retval     #BCM_ERR_OK             WDGSE monitoring enabled

    @post None

    @trace #BRCM_SWREQ_WDGSE
*/
int32_t WDGSE_Enable(const WDGSE_InfoType *const aSE, const WDGSE_ConfigType *const aConfig);

/** @brief WDGSE notify checkpoint/state

    This API notifies a state transition of the component to the WDGSE. It also
    verifies that the given state is either an entry point state or a valid
    state transition. If the entry point state is encountered while a graph is
    active or, if this state transition is invalid, logical error count is
    incremented.

    If the given state is an entry point state and deadline monitoring is
    enabled, a snapshot of current local time is preserved in nanoseconds in the
    context (for future monitoring).

    If the given state is an exit point state and deadline monitoring is
    enabled, current time is checked against snapshot of entry time for
    configured deadline monitoring.

    Any detected errors are updated in the context.

    @behavior Sync, Non-reentrant

    @pre Supervision Entity is enabled

    @param[in]      aSE         Supervision Entity
    @param[in]      aState      Checkpoint/State value that has been reached by
                                the client.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_INVAL_PARAMS   aSE is NULL or if aState is invalid
    @retval     #BCM_ERR_INVAL_MAGIC    aSE has invalid magic
    @retval     #BCM_ERR_INVAL_STATE    WDGSE is not initialized or if mode in
                                        context (#WDGSE_ContextType) is zero
    @retval     #BCM_ERR_OK             On success

    @post Context is updated with errors, states and other monitoring status

    @trace #BRCM_SWREQ_WDGSE
*/
int32_t WDGSE_NotifyState(const WDGSE_InfoType *const aSE, WDGSE_StateType aState);

/** @brief Disable Supervision entity from monitoring

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aSE     Supervision Entity

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_INVAL_PARAMS   aSE is NULL
    @retval     #BCM_ERR_INVAL_MAGIC    aSE has invalid magic
    @retval     #BCM_ERR_OK             WDGSE monitoring disabled

    @post Supervision entity is disabled

    @trace #BRCM_SWREQ_WDGSE
*/
int32_t WDGSE_Disable(const WDGSE_InfoType *const aSE);

/** @brief Monitor Supervision entity

    @behavior Sync, Non-reentrant

    @pre Supervision entity is enabled using #WDGSE_Enable

    @param[in]      aSE     Supervision Entity

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_MAX_ATTEMPS    Monitored component reached or crossed
                                        the maximum error limit
    @retval     #BCM_ERR_CUSTOM         Some errors are detected, but within the
                                        maximum error limit
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid Supervision Entity
    @retval     #BCM_ERR_OK             On success

    @post TODO

    @trace #BRCM_SWREQ_WDGSE
*/
int32_t WDGSE_Monitor(const WDGSE_InfoType *const aSE);

#endif /* WDGSE_H */
/** @} */
