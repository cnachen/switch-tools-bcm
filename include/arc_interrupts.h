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
    @defgroup grp_arc_interrupts_ifc ARC Interrupt management routines
    @ingroup grp_arc

    @addtogroup grp_arc_interrupts_ifc
    @{
    Helper macros and function prototypes to manage interrupts
    on an ARC based CPU

    @file arc_interrupts.h
    @brief Interface File
    This header file contains helper macros and function prototypes
    to manage interrupts on an ARC based CPU
    @version 0.1 Initial Version
*/
#ifndef ARC_INTERRUPTS_H
#define ARC_INTERRUPTS_H

#include <compiler.h>
#include <arc_aux_regs.h>

/**
    @name ARCv2EM interrupt management helper routines Architecture IDs
    @{
    @brief Architecture IDs for the ARCv2EM interrupt management helpers
*/
#define BRCM_SWARCH_ARC_INTERRUPT_NUM_MACRO           (0x8101U)   /**< @brief #ARC_INTERRUPT_NUM_MIN        */
#define BRCM_SWARCH_ARC_TRIGGER_INTERRUPT_PROC        (0x8102U)   /**< @brief #ARC_TriggerInterrupt         */
#define BRCM_SWARCH_ARC_ENABLE_INTERRUPT_LINE_PROC    (0x8103U)   /**< @brief #ARC_EnableInterruptLine      */
#define BRCM_SWARCH_ARC_DISABLE_INTERRUPT_LINE_PROC   (0x8104U)   /**< @brief #ARC_DisableInterruptLine     */
/** @} */

/**
    @{
    @brief Interrupt line min and max numbers

    @trace #BRCM_SWREQ_ARC_INTERRUPTS
*/
#define ARC_INTERRUPT_NUM_MIN             (16UL)
#define ARC_INTERRUPT_NUM_MAX             (255UL)
/** @} */

/**
    @brief Trigger an interrupt from SW on an ARC based CPU

    @behavior Sync, Reentrant

    @pre None

    @param[in]      aIntNum                 Interrupt line to trigger

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS   Invalid interrupt number
    @retval         #BCM_ERR_BUSY           HW resources to trigger an interrupt are busy
    @retval         #BCM_ERR_OK             Interrupt triggered

    @post None

    @trace #BRCM_SWREQ_ARC_INTERRUPTS
*/
int32_t ARC_TriggerInterrupt(const uint32_t aIntNum);

/**
    @brief Enable an interrupt line on an ARC based CPU

    @behavior Sync, Reentrant

    @pre None

    @param[in]      aIntNum                 Interrupt line to trigger

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS   Invalid interrupt number
    @retval         #BCM_ERR_OK             Interrupt line enabled

    @post On a sucessful return, the requested interrupt line is enabled
        at priotity level zero.

    @trace #BRCM_SWREQ_ARC_INTERRUPTS
*/
int32_t ARC_EnableInterruptLine(const uint32_t aIrqNum);

/**
    @brief Disable an interrupt line on an ARC based CPU

    @behavior Sync, Reentrant

    @pre None

    @param[in]      aIntNum                 Interrupt line to trigger

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS   Invalid interrupt number
    @retval         #BCM_ERR_OK             Interrupt line disabled

    @post None

    @trace #BRCM_SWREQ_ARC_INTERRUPTS
*/
int32_t ARC_DisableInterruptLine(const uint32_t aIrqNum);

#endif
/** @} */
