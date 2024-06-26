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
    @defgroup grp_system_wdg_ifc System WatchDog Interface
    @ingroup grp_system_abstract

    @addtogroup grp_system_wdg_ifc
    @{
    Safety is a responsibility of every component in the system. With the same thought process,
    Watchdog is a responsibility of every component. Logical supervision is carried out
    in corresponding component context. Deadline monitoring may happen in client context or
    System Monitor context with support from component. Frequency supervision is performed in
    System Monitor context with support from component.

    Watchdog provides mechanism to define a supervision entity (component/client to
    define it). Watchdog shall monitor these supervision entities.
    Each supervision entity has configuration of a graph defining the state transitions
    relevant for the component. Logical monitoring shall ensure that component is flowing through
    the defined graph.

    For the sake of simplicity, deadline monitoring is performing from entry to exit of the graph
    i.e., time taken by component to traverse from starting state to ending state should be
    constrained and monitored.

    Frequency of monitoring is done by system task (the highest priority task defined by architecture
    performing system initialization).

    Note that the WDGSE_CHECK_TIME_US should be designed to ensure all Supervised Entities (which need
    frequency monitoring) will have a minimum frequency of at least 1.

    @section sec_system_wdg_ifc_seq Sequence Diagram
    @startseq
    group {label = "client"; color = "#EFFFFF";  Client;};
    group {label = "server"; color = "#FFFFEF"; ServerTask; WDG;};
    ServerTask => WDG [label = "WDG_Init"];
    === Initialization Complete ===
    Client => WDG [label = "WDG_EnableSE"];
    loop {
        Client => WDG [label = "WDG_NotifyState"];
        ServerTask => WDG [label = "WDG_Monitor"];
    };
    Client => WDG [label = "WDG_DisableSE"];
    ServerTask => WDG [label = "WDG_DeInit"];
    @endseq

    @section sec_system_wdg_ifc_fsm State Machine
    @startfsm
    INIT; DEINIT;
    INIT -> DEINIT;
    DEINIT -> INIT;
    @endfsm
    The WDG shall be in DEINIT state at start. On Initialization,
    it moves to INIT state. On deinitialization, it moves back to
    DEINIT state.

    @file system_wdg.h
    @brief Interface File
    This header file contains the interface functions for watchdog service
    @version 0.1 Initial Version
*/

#ifndef SYSTEM_WDG_H
#define SYSTEM_WDG_H

#include <stddef.h>
#include <inttypes.h>
#include <bcm_err.h>
#include <bcm_utils.h>
#include <wdgse.h>

/**
    @name Watchdog Service Architecture IDs
    @{
    @brief Architecture IDs for Watchdog
*/
#define BRCM_SWARCH_WDG_MODE_MACRO                       (0x8501U)    /**< @brief #WDG_ModeType                */
#define BRCM_SWARCH_WDG_CONFIG_TYPE                      (0x8502U)    /**< @brief #WDG_ConfigType              */
#define BRCM_SWARCH_WDG_CONTEXT_TYPE                     (0x8503U)    /**< @brief #WDG_ContextType             */
#define BRCM_SWARCH_WDG_MONITOR_TYPE                     (0x8504U)    /**< @brief #WDG_MonitorType             */
#define BRCM_SWARCH_WDG_STATE_TYPE                       (0x8505U)    /**< @brief #WDG_StateType               */
#define BRCM_SWARCH_WDG_SE_TYPE                          (0x8506U)    /**< @brief #WDG_SEType                  */
#define BRCM_SWARCH_WDG_ENABLESE_PROC                    (0x8507U)    /**< @brief #WDG_EnableSE                */
#define BRCM_SWARCH_WDG_NOTIFYSTATE_PROC                 (0x8508U)    /**< @brief #WDG_NotifyState             */
#define BRCM_SWARCH_WDG_DISABLESE_PROC                   (0x8509U)    /**< @brief #WDG_DisableSE               */
#define BRCM_SWARCH_WDG_INVALID_GRAPH_BUF_ENTRY_MACRO    (0x850AU)    /**< @brief #WDG_INVALID_GRAPH_BUF_ENTRY */
#define BRCM_SWARCH_WDG_SE_MAGIC_MACRO                   (0x850BU)    /**< @brief #WDG_SE_MAGIC                */
#define BRCM_SWARCH_WDG_CALLBACK_TYPE                    (0x850CU)    /**< @brief #WDG_CbType                  */
/** @} */

/**
    @brief Invalid entry for a SE graph (legacy)

    @note This macro has been retained for legacy reasons.
    @trace #BRCM_SWREQ_WDG
 */
#define WDG_INVALID_GRAPH_BUF_ENTRY     (WDGSE_INVALID_GRAPH_BUF_ENTRY)

/**
    @brief Magic for Supervised Entity structure (legacy)

    @note This macro has been retained for legacy reasons. Refer to #WDGSE_MAGIC
    for details.
    @trace #BRCM_SWREQ_WDG
 */
#define WDG_SE_MAGIC                    (WDGSE_MAGIC)

/**
    @name Watchdog Type Masks (legacy)
    @{
    @brief Supervision Mode type masks (legacy)

    @note This type and its associated macros have been retained for legacy
          reasons.

    @trace #BRCM_SWREQ_WDG
*/
typedef WDGSE_ModeType WDG_ModeType;
#define WDG_MODE_NONE       (WDGSE_MODE_NONE)       /**< @brief Logical monitoring mask */
#define WDG_MODE_LOGICAL    (WDGSE_MODE_LOGICAL)    /**< @brief Logical monitoring mask */
#define WDG_MODE_DEADLINE   (WDGSE_MODE_DEADLINE)   /**< @brief Deadline monitoring mask */
#define WDG_MODE_FREQ       (WDGSE_MODE_FREQ)       /**< @brief Frequency monitoring mask */
/** @} */

/**
    @brief Configuration of Watchdog Supervision Entity (legacy)

    @note This type has been retained for legacy reasons.
    @trace #BRCM_SWREQ_WDG
 */
typedef WDGSE_ConfigType WDG_ConfigType;
BCM_STATIC_SIZE_ASSERT(WDG_ConfigType, 20UL, 20UL)

/**
    @brief Watchdog Supervision entity context (legacy)

    @note This type has been retained for legacy reasons.
    @trace #BRCM_SWREQ_WDG
 */
typedef WDGSE_ContextType WDG_ContextType;
BCM_STATIC_SIZE_ASSERT(WDG_ContextType, 56UL, 56UL)

/**
    @brief Watchdog Supervision entity Monitor type (legacy)

    @note This type has been retained for legacy reasons.
    @trace #BRCM_SWREQ_WDG
 */
typedef WDGSE_MonitorType WDG_MonitorType;
BCM_STATIC_SIZE_ASSERT(WDG_MonitorType, 32UL, 32UL)

/** @brief WDG Callback to be raised by WDG_Monitor

    @note This type has been retained for legacy reasons. Refer to #WDGSE_CbType
          for details
    @trace #BRCM_SWREQ_WDG
*/
typedef WDGSE_CbType WDG_CbType;

/**
    @brief Graph Buffer type (legacy)

    @note This type has been retained for legacy reasons.
    @trace #BRCM_SWREQ_WDG
*/
typedef WDGSE_StateType WDG_StateType;

/**
    @brief Structure for a supervision entity

    @note This type has been retained for legacy reasons. Refer to #WDGSE_InfoType
          for details.
    @trace #BRCM_SWREQ_WDG
*/
typedef WDGSE_InfoType WDG_SEType;

/** @brief Enable monitoring WDG Supervision entity (legacy)

    @note This API has been retained for legacy reasons. Refer to #WDGSE_Enable
          for details.

    @trace #BRCM_SWREQ_WDG
*/
int32_t WDG_EnableSE(const WDG_SEType *const aSE, const WDG_ConfigType *const aConfig);


/** @brief WDG notify checkpoint/state

    @note This API has been retained for legacy reasons. Refer to #WDG_NotifyState
          for details.

    @trace #BRCM_SWREQ_WDG
*/
int32_t WDG_NotifyState(const WDG_SEType *const aSE, WDG_StateType aState);

/** @brief Disable Supervision entity from monitoring

    @note This API has been retained for legacy reasons. Refer to #WDGSE_Disable
          for details.

    @trace #BRCM_SWREQ_WDG
*/
int32_t WDG_DisableSE(const WDG_SEType *const aSE);

#endif /* SYSTEM_WDG_H */
/** @} */
