/*****************************************************************************
 Copyright 2021 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_arc_timer_ifc ARC CPU timer management routines
    @ingroup grp_arc

    @addtogroup grp_arc_timer_ifc
    @{
    Helper macros and function prototypes to manage CPU timers
    on an ARC based CPU

    @file arc_timer.h
    @brief Interface File
    This header file contains helper macros and function prototypes
    to manage CPU timers on an ARC based CPU
    @version 0.1 Initial Version
*/
#ifndef ARC_TIMER_H
#define ARC_TIMER_H

#include <stdint.h>

/**
    @name ARC CPU timer management helper routines Architecture IDs
    @{
    @brief Architecture IDs for the ARC CPU timer management helpers
*/
#define BRCM_SWARCH_ARC_TIMER_ID_TYPE               (0x8301U)   /**< @brief #ARC_TimerIdType            */
#define BRCM_SWARCH_ARC_TIMER_INIT_PROC             (0x8302U)   /**< @brief #ARC_TimerInit              */
#define BRCM_SWARCH_ARC_TIMER_GET_TICK_CNT_PROC     (0x8303U)   /**< @brief #ARC_TimerGetTickCnt        */
#define BRCM_SWARCH_ARC_TIMER_HANDLE_INTERRUPT_PROC (0x8304U)   /**< @brief #ARC_TimerHandleInterrupt   */
#define BRCM_SWARCH_ARC_TIMER_DEINIT_PROC           (0x8305U)   /**< @brief #ARC_TimerDeinit            */
#define BRCM_SWARCH_ARC_TIMER_RESET_RTC_PROC        (0x8306U)   /**< @brief #ARC_TimerResetRTC          */
#define BRCM_SWARCH_ARC_TIMER_GET_TICK_CNT_RTC_PROC (0x8307U)   /**< @brief #ARC_TimerGetTickCntRTC     */
/** @} */

/**
    @{
    @brief ARC timer ID's

    @trace #BRCM_SWREQ_ARC_TIMERS
*/
typedef uint32_t ARC_TimerIdType;
#define ARC_TIMER_ID0               (0UL)
#define ARC_TIMER_ID1               (1UL)
/** @} */

/** @brief Initialize a CPU timer

    @behavior Sync, Non-reentrant

    @pre CPU is in the kernel mode

    @param[in]      aTimerId                Timer ID
    @param[in]      aTickCnt                Tick count to program into
                                            the timer limit register

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS   Invalid timer ID
    @retval         #BCM_ERR_OK             Timer initialized


    @post The timer is configured to interrupt the CPU after
        every aTickCnt cycles

    @trace #BRCM_SWREQ_ARC_TIMERS
 */
int32_t ARC_TimerInit(const ARC_TimerIdType aTimerId, const uint32_t aTickCnt);

/** @brief Return the timer tick count

    @behavior Sync, Reentrant

    @pre CPU is in the kernel mode

    @param[in]      aTimerId                Timer ID
    @param[out]     aTickCnt                Tick count output
                                            If an interrupt is pending, the value
                                            programmed via @ref ARC_TimerInit API's
                                            aTickCnt is returned.
                                            If an interrupt is not pending, the value
                                            in the timer's count register is read and
                                            returned.

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS   Invalid timer ID or aTickCnt is NULL
    @retval         #BCM_ERR_OK             Tick count filled in


    @post None

    @trace #BRCM_SWREQ_ARC_TIMERS
 */
int32_t ARC_TimerGetTickCnt(const ARC_TimerIdType aTimerId, uint32_t *const aTickCnt);

/** @brief Handle the timer interrupt

    @behavior Sync, Non-reentrant

    @pre CPU is in the kernel mode

    @param[in]      aTimerId                Timer ID

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS   Invalid timer ID
    @retval         #BCM_ERR_OK             Timer interrupt handled

    @post Timer interrupt handled

    @trace #BRCM_SWREQ_ARC_TIMERS
 */
int32_t ARC_TimerHandleInterrupt(const ARC_TimerIdType aTimerId);

/** @brief Deinit the CPU timer

    @behavior Sync, Non-reentrant

    @pre CPU is in the kernel mode

    @param[in]      aTimerId                Timer ID

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS   Invalid timer ID
    @retval         #BCM_ERR_OK             Timer deinited

    @post The timer no longer interrupts the CPU

    @trace #BRCM_SWREQ_ARC_TIMERS
 */
int32_t ARC_TimerDeinit(const ARC_TimerIdType aTimerId);

/** @brief Reset RTC

    @behavior Sync, Non-reentrant

    @pre CPU is in the kernel mode

    @return void

    @post RTC has been reset

    @trace #BRCM_SWREQ_ARC_TIMERS
 */
void ARC_TimerResetRTC(void);

/** @brief Reset the RTC clock

    @behavior Sync, Non-reentrant

    @pre None

    @return Sampled 64-bit counter from the RTC

    @post None

    @trace #BRCM_SWREQ_ARC_TIMERS
 */
uint64_t ARC_TimerGetTickCntRTC(void);

#endif /* ARC_TIMER_H */
/** @} */

