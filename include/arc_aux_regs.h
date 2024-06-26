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
    @defgroup grp_arc_regs_ifc ARC auxiliary registers
    @ingroup grp_arc

    @addtogroup grp_arc_regs_ifc
    @{
    Helper macros and functions to access the auxiliary registers
    defined by the ARCv2EM ISA

    @file arc_aux_regs.h
    @brief Interface File
    This header file contains helper macros and functions to access the auxiliary
    registers defined by the ARCv2EM ISA
    @version 0.1 Initial Version
*/
#ifndef ARC_AUX_REGS_H
#define ARC_AUX_REGS_H

#include <stdint.h>
#include <compiler.h>

/**
    @name ARCv2EM auxiliary registers Architecture IDs
    @{
    @brief Architecture IDs for the ARCv2EM auxiliary registers
*/
#define BRCM_SWARCH_ARC_LP_MACRO                          (0x8001U)   /**< @brief #ARC_LP_START_ADDR        */
#define BRCM_SWARCH_ARC_STATUS32_MACRO                    (0x8002U)   /**< @brief #ARC_STATUS32_ADDR        */
#define BRCM_SWARCH_ARC_STATUS32_P0_MACRO                 (0x8003U)   /**< @brief #ARC_STATUS32_P0_ADDR     */
#define BRCM_SWARCH_ARC_IRQ_MACRO                         (0x8004U)   /**< @brief #ARC_IRQ_PRIORITY_ADDR    */
#define BRCM_SWARCH_ARC_AUX_IRQ_CTRL_MACRO                (0x8005U)   /**< @brief #ARC_AUX_IRQ_CTRL_ADDR    */
#define BRCM_SWARCH_ARC_AUX_HINT_MACRO                    (0x8006U)   /**< @brief #ARC_AUX_IRQ_HINT_ADDR    */
#define BRCM_SWARCH_ARC_TIMER_MACRO                       (0x8007U)   /**< @brief #ARC_TIMER_COUNT0_ADDR    */
#define BRCM_SWARCH_ARC_AUX_RTC_MACRO                     (0x8008U)   /**< @brief #ARC_AUX_RTC_CTRL_ADDR    */
#define BRCM_SWARCH_ARC_INT_VECTOR_BASE_MACRO             (0x8009U)   /**< @brief #ARC_INT_VECTOR_BASE_ADDR */
#define BRCM_SWARCH_ARC_MPU_MACRO                         (0x800AU)   /**< @brief #ARC_MPU_EN_ADDR          */
#define BRCM_SWARCH_ARC_USTACK_MACRO                      (0x800BU)   /**< @brief #ARC_USTACK_TOP_ADDR      */
#define BRCM_SWARCH_ARC_KSTACK_MACRO                      (0x800CU)   /**< @brief #ARC_KSTACK_TOP_ADDR      */
#define BRCM_SWARCH_ARC_AUX_USER_SP_MACRO                 (0x800DU)   /**< @brief #ARC_AUX_USER_SP_ADDR     */
#define BRCM_SWARCH_ARC_ERET_MACRO                        (0x800EU)   /**< @brief #ARC_ERET_ADDR            */
#define BRCM_SWARCH_ARC_ERBTA_MACRO                       (0x800FU)   /**< @brief #ARC_ERBTA_ADDR           */
#define BRCM_SWARCH_ARC_ERSTATUS_MACRO                    (0x8010U)   /**< @brief #ARC_ERSTATUS_ADDR        */
#define BRCM_SWARCH_ARC_READ_AUX_PROC                     (0x8011U)   /**< @brief #ARC_ReadAux              */
#define BRCM_SWARCH_ARC_WRITE_AUX_PROC                    (0x8012U)   /**< @brief #ARC_WriteAux             */
/** @} */

/**
    @{
    @brief Zero overhead loop start and end register addresses

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_LP_START_ADDR                 (0x02UL)
#define ARC_LP_END_ADDR                   (0x03UL)
/** @} */

/**
    @{
    @brief STATUS32 register address and bitfields

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_STATUS32_ADDR                 (0x0AUL)
#define ARC_STATUS32_H_BIT                (1UL << 0UL)
#define ARC_STATUS32_E_MASK               (0x1EUL)
#define ARC_STATUS32_E_SHIFT              (1UL)
#define ARC_STATUS32_AE_BIT               (1UL << 5UL)
#define ARC_STATUS32_DE_BIT               (1UL << 6UL)
#define ARC_STATUS32_U_BIT                (1UL << 7UL)
#define ARC_STATUS32_V_BIT                (1UL << 8UL)
#define ARC_STATUS32_C_BIT                (1UL << 9UL)
#define ARC_STATUS32_N_BIT                (1UL << 10UL)
#define ARC_STATUS32_Z_BIT                (1UL << 11UL)
#define ARC_STATUS32_L_BIT                (1UL << 12UL)
#define ARC_STATUS32_DZ_BIT               (1UL << 13UL)
#define ARC_STATUS32_SC_BIT               (1UL << 14UL)
#define ARC_STATUS32_ES_BIT               (1UL << 15UL)
#define ARC_STATUS32_BANK_SHIFT           (16UL)
#define ARC_STATUS32_BANK_MASK            (0x70000UL)
#define ARC_STATUS32_AD_BIT               (1UL << 19UL)
#define ARC_STATUS32_US_BIT               (1UL << 20UL)
#define ARC_STATUS32_IE_BIT               (1UL << 31UL)
/** @} */

/**
    @brief STATUS32_P0 register address

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_STATUS32_P0_ADDR              (0x0BUL)

/**
    @{
    @brief IRQ management register addresses

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_IRQ_PRIORITY_ADDR             (0x206UL)
#define ARC_IRQ_SELECT_ADDR               (0x40BUL)
#define ARC_IRQ_ENABLE_ADDR               (0x40CUL)
#define ARC_IRQ_TRIGGER_ADDR              (0x40DUL)
#define ARC_IRQ_STATUS_ADDR               (0x40FUL)
#define ARC_IRQ_PULSE_CANCEL_ADDR         (0x415UL)
#define ARC_IRQ_PENDING_ADDR              (0x416UL)
/** @} */

/**
    @{
    @brief Interrupt context saving register address and bitfields

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_AUX_IRQ_CTRL_ADDR             (0x0EUL)
#define ARC_AUX_IRQ_CTRL_U_BIT            (1UL << 11UL)
#define ARC_AUX_IRQ_CTRL_L_BIT            (1UL << 10UL)
#define ARC_AUX_IRQ_CTRL_B_BIT            (1UL << 9UL)
/** @} */

/**
    @brief Software interrupt trigger register address

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_AUX_IRQ_HINT_ADDR             (0x201UL)

/**
    @{
    @brief Timer management register addresses and bitfields

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_TIMER_COUNT0_ADDR             (0x21UL)
#define ARC_TIMER_COUNT1_ADDR             (0x100UL)
#define ARC_TIMER_LIMIT0_ADDR             (0x23UL)
#define ARC_TIMER_LIMIT1_ADDR             (0x102UL)
#define ARC_TIMER_CONTROL0_ADDR           (0x22UL)
#define ARC_TIMER_CONTROL1_ADDR           (0x101UL)
#define ARC_TIMER_CONTROL_IE_BIT          (1UL)
#define ARC_TIMER_CONTROL_NH_BIT          (1UL << 1UL)
#define ARC_TIMER_CONTROL_W_BIT           (1UL << 2UL)
#define ARC_TIMER_CONTROL_IP_BIT          (1UL << 3UL)
#define ARC_TIMER_CONTROL_VALID_MASK      (0xFUL)
/** @} */

/**
    @{
    @brief RTC clock register addresses and bitfields

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_AUX_RTC_CTRL_ADDR             (0x103UL)
#define ARC_AUX_RTC_CTRL_ENABLE_BIT       (1UL)
#define ARC_AUX_RTC_CTRL_CLEAR_BIT        (1UL << 1UL)
#define ARC_AUX_RTC_CTRL_A0_BIT           (1UL << 30UL)
#define ARC_AUX_RTC_CTRL_A1_BIT           (1UL << 31UL)
#define ARC_AUX_RTC_LOW_ADDR              (0x104UL)
#define ARC_AUX_RTC_HIGH_ADDR             (0x105UL)
/** @} */

/**
    @brief Vector table base address configuration register

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_INT_VECTOR_BASE_ADDR          (0x25UL)

/**
    @{
    @brief MPU register addresses and bitfields

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_MPU_EN_ADDR                   (0x409UL)
#define ARC_MPU_EN_ENABLE_BIT             (1UL << 30UL)
#define ARC_MPU_EN_DISABLE_BIT            (0UL)
#define ARC_MPU_EN_UE_BIT                 (1UL << 3UL)
#define ARC_MPU_EN_UW_BIT                 (1UL << 4UL)
#define ARC_MPU_EN_UR_BIT                 (1UL << 5UL)
#define ARC_MPU_EN_KE_BIT                 (1UL << 6UL)
#define ARC_MPU_EN_KW_BIT                 (1UL << 7UL)
#define ARC_MPU_EN_KR_BIT                 (1UL << 8UL)
#define ARC_MPU_EN_ACCESS_BITS_MASK       (0x1F8UL)
#define ARC_MPU_RDB_ADDR(i)               (0x422UL + (2UL * (i)))
#define ARC_MPU_RDB_REGION_ENABLE_BIT     (1UL)
#define ARC_MPU_RDB_REGION_DISABLE_BIT    (0UL)
#define ARC_MPU_RDP_ADDR(i)               (0x423UL + (2UL * (i)))
#define ARC_MPU_RDP_SIZE_BOTTOM_MASK      (0x3UL)
#define ARC_MPU_RDP_SIZE_BOTTOM_SHIFT     (0x0UL)
#define ARC_MPU_RDP_SIZE_TOP_MASK         (0xE00UL)
#define ARC_MPU_RDP_SIZE_TOP_SHIFT        (9UL)
#define ARC_MPU_RDP_SIZE_TOP_SHIFT_ADJUST (2UL)
#define ARC_MPU_RDP_UE_BIT                (1UL << 3UL)
#define ARC_MPU_RDP_UW_BIT                (1UL << 4UL)
#define ARC_MPU_RDP_UR_BIT                (1UL << 5UL)
#define ARC_MPU_RDP_KE_BIT                (1UL << 6UL)
#define ARC_MPU_RDP_KW_BIT                (1UL << 7UL)
#define ARC_MPU_RDP_KR_BIT                (1UL << 8UL)
#define ARC_MPU_RDP_ACCESS_BITS_MASK      (0x1F8UL)
#define ARC_MPU_RDP_ACCESS_BITS_SHIFT     (3UL)
/** @} */

/**
    @{
    @brief User mode HW stack checking register addresses

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_USTACK_TOP_ADDR               (0x260UL)
#define ARC_USTACK_BASE_ADDR              (0x261UL)
/** @} */

/**
    @{
    @brief Kernel mode HW stack checking register addresses

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_KSTACK_TOP_ADDR               (0x264UL)
#define ARC_KSTACK_BASE_ADDR              (0x265UL)
/** @} */

/**
    @brief Saved user stack pointer register addresses

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_AUX_USER_SP_ADDR              (0x0DUL)

/**
    @brief ERET register address

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_ERET_ADDR                     (0x400UL)

/**
    @brief ERBTA register address

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_ERBTA_ADDR                    (0x401UL)

/**
    @brief ERSTATUS register address

    @trace #BRCM_SWREQ_ARC_COMMON
*/
#define ARC_ERSTATUS_ADDR                 (0x402UL)

/**
    @brief Helper function to read from an ARCv2 auxiliary register

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aAddr           Address of the register to read

    @return Value returned after performing a register read

    @post None

    @trace #BRCM_SWREQ_ARC_COMMON
*/
static inline uint32_t ARC_ReadAux(const uint32_t aAddr)
{
    return _lr(aAddr);
}

/**
    @brief Helper function to read from an ARCv2 auxiliary register

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aAddr           Address of the register to write to
    @param[in]      aVal            Value to be written

    @return void

    @post aVal is written to the auxiliary register at adress aAddr

    @trace #BRCM_SWREQ_ARC_COMMON
*/
static inline void ARC_WriteAux(const uint32_t aAddr, const uint32_t aVal)
{
    _sr(aVal, aAddr);
}

#endif
/** @} */
