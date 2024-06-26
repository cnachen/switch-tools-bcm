/*****************************************************************************
 Copyright 2021-2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_inout_ipc_regs Registers
    @ingroup grp_inout_ipc_overview

    @addtogroup grp_inout_ipc_regs
    @{

    @file inout_ipc_native_types.h
    @brief IPC native types

    @version 0.1 Initial Version
*/

#ifndef INOUT_IPC_REGS_H
#define INOUT_IPC_REGS_H

#include <stdint.h>
#include <rpc_msg.h>

/**
    @name RPC IPC Common Architecture IDs
    @{
    @brief Architecture IDs for RPC IPC Common
*/
#define BRCM_SWARCH_IPC_BUFF_INFO2_TYPE                 (0x7540U)   /**< @brief #IPC_BuffInfo2Type     */
#define BRCM_SWARCH_IPC_BUFF_INFO_TYPE                  (0x7541U)   /**< @brief #IPC_BuffInfoType      */
#define BRCM_SWARCH_IPC_HOST_STAT_TYPE                  (0x7542U)   /**< @brief #IPC_HostStatType      */
#define BRCM_SWARCH_IPC_TARGET_STAT_TYPE                (0x7543U)   /**< @brief #IPC_TargetStatType    */
#define BRCM_SWARCH_IPC_MSG_BUF_MACRO                   (0x7544U)   /**< @brief #IPC_MSG_BUF_SIZE_LOG2 */
#define BRCM_SWARCH_IPC_TARGET_NOTIF_COUNTER_REG_TYPE   (0x7545U)   /**< @brief #IPC_TargetNotifCounterType */
#define BRCM_SWARCH_IPC_CHIPMISCREG_TYPE                (0x7546U)   /**< @brief #IPC_ChipMiscRegType   */
#define BRCM_SWARCH_IPC_CHIPMISCREGVAL_GLOBAL           (0x7547U)   /**< @brief #IPC_ChipMiscRegVal    */
#define BRCM_SWARCH_IPC_HDR_MACRO                       (0x7548U)   /**< @brief #IPC_HDR_MAGIC_INDEX   */
#define BRCM_SWARCH_IPC_REGBLOCK_TYPE                   (0x7549U)   /**< @brief #IPC_RegBlockType      */
/** @} */

/**
    @brief IPC Chip Misc Register address to be set based on chipset

    @trace #BRCM_SWREQ_IPC
*/
typedef struct sIPC_ChipMiscRegType {
    uint32_t    buffInfoReg;      /**< @brief spare_sw_reg7   */
    uint32_t    targetStatusReg;  /**< @brief spare_sw_reg8   */
    uint32_t    hostStatReg;      /**< @brief spare_sw_reg9   */
    uint32_t    buffInfo2Reg;     /**< @brief spare_sw_reg10  */
    uint32_t    notifCntrReg;     /**< @brief spare_sw_reg11  */
    uint32_t    interruptReg;     /**< @brief Interrupt register */
} IPC_ChipMiscRegType;

/**
   @brief Chip misc register address values

   @trace #BRCM_SWREQ_IPC
*/
extern const IPC_ChipMiscRegType IPC_ChipMiscRegVal;

/**
   @name Buffer info register
   @{
   @brief Buffer info register

   Register used for storing the buffer information

   @trace #BRCM_SWREQ_IPC
*/
typedef uint16_t IPC_BuffInfoType;
#define IPC_BUFF_INFO_REG               ((uint16_t*)(IPC_ChipMiscRegVal.buffInfoReg))
#define IPC_BUFF_INFO_BASE_SHIFT        (8UL)
#define IPC_BUFF_INFO_BASE_MASK         (0xFF00U)
#define IPC_BUFF_INFO_SZ_SHIFT          (4UL)
#define IPC_BUFF_INFO_SZ_MASK           (0x00F0U)
#define IPC_BUFF_INFO_CNT_SHIFT         (2UL)
#define IPC_BUFF_INFO_CNT_MASK          (0x000CU)
#define IPC_BUFF_INFO_RSVD_SHIFT        (1UL)
#define IPC_BUFF_INFO_RSVD_MASK         (0x0002U)
#define IPC_BUFF_INFO_PAR_SHIFT         (0UL)
#define IPC_BUFF_INFO_PAR_MASK          (0x0001U)
#define IPC_BUFF_INFO_BASE_ALIGN_SHIFT  (11UL)
/** @} */

/**
   @name Buffer info2 register
   @{
   @brief Buffer info register

   Register used for storing the buffer information

   @trace #BRCM_SWREQ_IPC
*/
typedef uint16_t IPC_BuffInfo2Type;
#define IPC_BUFF_INFO2_REG              ((uint16_t*)(IPC_ChipMiscRegVal.buffInfo2Reg))
#define IPC_BUFF_INFO2_BASE_SHIFT       (1UL)
#define IPC_BUFF_INFO2_BASE_MASK        (0x3FFEU)
#define IPC_BUFF_INFO2_RSVD_SHIFT       (14UL)
#define IPC_BUFF_INFO2_RSVD_MASK        (0xC000U)
#define IPC_BUFF_INFO2_PAR_SHIFT        (0UL)
#define IPC_BUFF_INFO2_PAR_MASK         (0x0001U)
#define IPC_BUFF_INFO2_BASE_ALIGN_SHIFT (19UL)
/** @} */

/**
   @name Target status register
   @{
   @brief Target status register

   Register used for storing the target status

   @trace #BRCM_SWREQ_IPC
*/
typedef uint16_t IPC_TargetStatType;
#define IPC_TARGET_STAT_REG             ((uint16_t*)(IPC_ChipMiscRegVal.targetStatusReg))
#define IPC_TARGET_STAT_RSVD_SHIFT      (11UL)
#define IPC_TARGET_STAT_RSVD_MASK       (0xF800U)
#define IPC_TARGET_STAT_WR_SHIFT        (4UL)
#define IPC_TARGET_STAT_WR_MASK         (0xF0UL)
#define IPC_TARGET_STAT_RD_SHIFT        (0UL)
#define IPC_TARGET_STAT_RD_MASK         (0xFUL)
#define IPC_TARGET_STAT_READY_MASK      (0x0100U)
/** @} */

/**
   @name Host status register
   @{
   @brief Host status register

   Register used for storing the host status

   @trace #BRCM_SWREQ_IPC
*/
typedef uint16_t IPC_HostStatType;
#define IPC_HOST_STAT_REG               ((uint16_t*)(IPC_ChipMiscRegVal.hostStatReg))
#define IPC_HOST_STAT_RSVD_SHIFT        (8UL)
#define IPC_HOST_STAT_RSVD_MASK         (0xFF00U)
#define IPC_HOST_STAT_WR_SHIFT          (4UL)
#define IPC_HOST_STAT_WR_MASK           (0xF0UL)
#define IPC_HOST_STAT_RD_SHIFT          (0UL)
#define IPC_HOST_STAT_RD_MASK           (0xFUL)
/** @} */

/**
   @name Target notifications counter register
   @{
   @brief Target notifications counter register

   Register used for storing notifications count

   @trace #BRCM_SWREQ_IPC
*/
typedef uint16_t IPC_TargetNotifCounterType;
#define IPC_TARGET_NOTIF_COUNTER_REG     ((uint16_t*)(IPC_ChipMiscRegVal.notifCntrReg))
/** @} */

/**
    @brief IPC Chip Misc Registers as a unified structure block

    @trace #BRCM_SWREQ_IPC
*/
typedef struct sIPC_RegBlockType {
    uint16_t           blDwnldTargetSpareReg; /**< @brief Used with ROM on target */
    uint16_t           rsv1[5];               /**< @brief Reserved                */
    IPC_BuffInfoType   buffInfoReg;           /**< @brief Buffer Info register    */
    IPC_TargetStatType targetStatReg;         /**< @brief Target status register  */
    IPC_HostStatType   hostStatReg;           /**< @brief Host status register    */
    IPC_BuffInfo2Type  buffInfo2Reg;          /**< @brief Buffer Info 2 register  */
    uint16_t           rsv2[5];               /**< @brief Reserved                */
    uint16_t           cpusysMiscReg;         /**< @brief Interrupt register      */
} IPC_RegBlockType;

/**
   @brief IPC Buffer size and count config

   @trace #BRCM_SWREQ_IPC
*/
#define IPC_MSG_BUF_SIZE_LOG2             (9U)
#define IPC_MSG_BUF_COUNT_LOG2            (3U)
#define IPC_MSG_BUF_TOTAL_SIZE            (2U*(1U << IPC_MSG_BUF_SIZE_LOG2)*(1U << IPC_MSG_BUF_COUNT_LOG2))

/**
   @name IPC Message header
   @{
   @brief IPC Message header content

   @trace #BRCM_SWREQ_IPC
*/
#define IPC_HDR_MAGIC_INDEX        (0UL)
#define IPC_HDR_CHKSUM_INDEX       (1UL)
#define IPC_HDR_COMMAND_INDEX      (2UL)
#define IPC_HDR_LENGTH_INDEX       (3UL)
#define IPC_HDR_LAST_INDEX         (4UL)
/** @} */

#endif /* INOUT_IPC_REGS_H */
/** @} */
