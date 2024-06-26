/*****************************************************************************
 Copyright 2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_prog_ifc Interface
    @ingroup grp_prog

    @addtogroup grp_prog_ifc
    @{


    @version 0.1 Initial Version
*/

#ifndef PROG_H
#define PROG_H

/**
    @name Architecture IDs
    @{
    @brief Architecture IDs
*/
#define BRCM_SWARCH_PROG_MACRO                  (0x8100U)   /**< @brief #PROG_CUSTOM_INSTR_COUNT*/
#define BRCM_SWARCH_PROG_VERSION_TYPE           (0x8101U)   /**< @brief #PROG_VersionType       */
#define BRCM_SWARCH_PROG_INSTR_TYPE             (0x8102U)   /**< @brief #PROG_InstrType         */
#define BRCM_SWARCH_PROG_EXEC_FLAGS_TYPE        (0x8103U)   /**< @brief #PROG_ExecFlagsType     */
#define BRCM_SWARCH_PROG_COND_TYPE              (0x8104U)   /**< @brief #PROG_CondType          */
#define BRCM_SWARCH_PROG_OP_TYPE                (0x8105U)   /**< @brief #PROG_OpType            */

#define BRCM_SWARCH_PROG_OP_HALT_EXT_TYPE       (0x8110U)   /**< @brief #PROG_OpHaltExtType     */
#define BRCM_SWARCH_PROG_OP_NOP_EXT_TYPE        (0x8111U)   /**< @brief #PROG_OpNopExtType      */
#define BRCM_SWARCH_PROG_OP_BKPT_EXT_TYPE       (0x8112U)   /**< @brief #PROG_OpBkptExtType     */
#define BRCM_SWARCH_PROG_OP_BRANCH_EXT_TYPE     (0x8113U)   /**< @brief #PROG_OpBranchExtType   */
#define BRCM_SWARCH_PROG_OP_CUST_EXT_TYPE       (0x8114U)   /**< @brief #PROG_OpCustExtType     */
#define BRCM_SWARCH_PROG_OP_HW_EXT_TYPE         (0x8115U)   /**< @brief #PROG_OpHwExtType       */
#define BRCM_SWARCH_PROG_OP_MDIO_EXT_TYPE       (0x8116U)   /**< @brief #PROG_OpMdioExtType     */
#define BRCM_SWARCH_PROG_OP_DELAY_EXT_TYPE      (0x8117U)   /**< @brief #PROG_OpDelayExtType    */
#define BRCM_SWARCH_PROG_OP_STACK_EXT_TYPE      (0x8118U)   /**< @brief #PROG_OpStackExtType    */
#define BRCM_SWARCH_PROG_OP_MEM_EXT_TYPE        (0x8119U)   /**< @brief #PROG_OpMemExtType      */
#define BRCM_SWARCH_PROG_OP_ARITH_EXT_TYPE      (0x811AU)   /**< @brief #PROG_OpArithExtType    */
#define BRCM_SWARCH_PROG_OP_EXTEND_EXT_TYPE     (0x811BU)   /**< @brief #PROG_OpExtendExtType   */
#define BRCM_SWARCH_PROG_OP_MUL_EXT_TYPE        (0x811CU)   /**< @brief #PROG_OpMulExtType      */
#define BRCM_SWARCH_PROG_OP_MOV_EXT_TYPE        (0x811DU)   /**< @brief #PROG_OpMovExtType      */
#define BRCM_SWARCH_PROG_OP_MOV_HALF_EXT_TYPE   (0x811EU)   /**< @brief #PROG_OpMovHalfExtType  */
#define BRCM_SWARCH_PROG_OP_CARRY_EXT_TYPE      (0x811FU)   /**< @brief #PROG_OpCarryExtType    */
#define BRCM_SWARCH_PROG_OP_RSUB_EXT_TYPE       (0x8120U)   /**< @brief #PROG_OpRsubExtType     */
#define BRCM_SWARCH_PROG_OP_CMP_EXT_TYPE        (0x8122U)   /**< @brief #PROG_OpCmpExtType      */
#define BRCM_SWARCH_PROG_OP_DIV_EXT_TYPE        (0x8123U)   /**< @brief #PROG_OpDivExtType      */
#define BRCM_SWARCH_PROG_OP_BIT_SHIFT_EXT_TYPE  (0x8124U)   /**< @brief #PROG_OpBitShiftExtType */
#define BRCM_SWARCH_PROG_OP_BIT_SET_EXT_TYPE    (0x8125U)   /**< @brief #PROG_OpBitSetExtType   */
#define BRCM_SWARCH_PROG_OP_BIT_WISE_EXT_TYPE   (0x8126U)   /**< @brief #PROG_OpBitWiseExtType  */

#define BRCM_SWARCH_PROG_EXCEPTION_TYPE         (0x8130U)   /**< @brief #PROG_ExceptionType     */
#define BRCM_SWARCH_PROG_CUSTOM_INSTR_TYPE      (0x8131U)   /**< @brief #PROG_CustomInstrType   */



#define BRCM_SWARCH_PROG_CONTEXT_TYPE           (0x8140U)   /**< @brief #PROG_ContextType       */
#define BRCM_SWARCH_PROG_INFO_TYPE              (0x8141U)   /**< @brief #PROG_InfoType          */

#define BRCM_SWARCH_PROG_EXECUTE_PROC           (0x8160U)   /**< @brief #PROG_Execute           */
/** @} */

/**
    @name macros
    @{
    @brief macros

    @trace #BRCM_SWREQ_PROG
*/
#define PROG_CUSTOM_INSTR_COUNT         (8UL)
#define PROG_MEMORY_SIZE                (300UL)
/** @} */

/**
    @name version
    @{
    @brief version

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_VersionType;
#define PROG_VERSION_1          (0x1)
/** @} */

/**
    @name layout
    @{
    @brief layout

    <table>
        <tr><th width="20%">Syntax</th> <th width="10%">31:28</th>  <th width="10%">27</th> <th width="10%">26:20</th>
                <th width="10%">19:16</th>  <th width="10%">15:12</th>  <th width="10%">11:8</th>   <th width="10%">7:4</th>    <th width="10%">3:0</th>    </tr>
        <tr><td>Syntax 1</td>   <td>Condition</td>  <td>Set Flags</td>  <td>Op Code</td>
                <td>Op Code Extension</td>  <td>register A</td> <td>register B</td> <td>register C</td> <td>register D</td>                                 </tr>
        <tr><td>Syntax 2</td>   <td>Condition</td>  <td>Set Flags</td>  <td>Op Code</td>
                <td>Op Code Extension</td>  <td>register A</td> <td>register B</td> <td>constant N[7:4]</td>    <td>constant N[3:0]</td>                    </tr>
        <tr><td>Syntax 3</td>   <td>Condition</td>  <td>Set Flags</td>  <td>Op Code</td>
                <td>Op Code Extension</td>  <td>constant I[15:12]</td>  <td>constant I[11:8]</td>   <td>constant I[7:4]</td>    <td>constant I[3:0]</td>    </tr>
        <tr><td>Syntax 3</td>   <td>Condition</td>  <td>Set Flags</td>  <td>Op Code</td>
                <td>Op Code Extension</td>  <td>register A</td> <td>constant X[5:2]</td>    <td>constants X[1:0]Y[5:4]</td> <td>constant Y[3:0]</td>        </tr>
    </table>

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_InstrType;
#define PROG_INSTR_COND_SHIFT    (28U)          /**< @brief Condition shift     */
#define PROG_INSTR_COND_MASK     (0xF0000000UL) /**< @brief Condition mask      */
#define PROG_INSTR_FLAG_SHIFT    (27U)          /**< @brief Flag enable shift   */
#define PROG_INSTR_FLAG_MASK     (0x08000000UL) /**< @brief Flag enable mask    */
#define PROG_INSTR_OP_SHIFT      (20U)          /**< @brief Operation shift     */
#define PROG_INSTR_OP_MASK       (0x07F00000UL) /**< @brief Operation mask      */
#define PROG_INSTR_EXT_SHIFT     (16U)          /**< @brief Oper Extension shift*/
#define PROG_INSTR_EXT_MASK      (0x000F0000UL) /**< @brief Oper Extension mask */
#define PROG_INSTR_A_SHIFT       (12U)          /**< @brief Operand A shift     */
#define PROG_INSTR_A_MASK        (0x0000F000UL) /**< @brief Operand A mask      */
#define PROG_INSTR_B_SHIFT       (8U)           /**< @brief Operand B shift     */
#define PROG_INSTR_B_MASK        (0x00000F00UL) /**< @brief Operand B mask      */
#define PROG_INSTR_C_SHIFT       (4U)           /**< @brief Operand C shift     */
#define PROG_INSTR_C_MASK        (0x000000F0UL) /**< @brief Operand C mask      */
#define PROG_INSTR_D_SHIFT       (0U)           /**< @brief Operand D shift     */
#define PROG_INSTR_D_MASK        (0x0000000FUL) /**< @brief Operand D mask      */
#define PROG_INSTR_N_SHIFT       (0U)           /**< @brief Operand N shift     */
#define PROG_INSTR_N_MASK        (0x000000FFUL) /**< @brief Operand N mask      */
#define PROG_INSTR_I_SHIFT       (0U)           /**< @brief Operand I shift     */
#define PROG_INSTR_I_MASK        (0x0000FFFFUL) /**< @brief Operand I mask      */
#define PROG_INSTR_X_SHIFT       (8U)           /**< @brief Operand X shift     */
#define PROG_INSTR_X_MASK        (0x00000FC0UL) /**< @brief Operand X mask      */
#define PROG_INSTR_Y_SHIFT       (0U)           /**< @brief Operand Y shift     */
#define PROG_INSTR_Y_MASK        (0x0000003FUL) /**< @brief Operand Y mask      */
/** @} */


/**
    @name Execution flags
    @{
    @brief Execution flags

    Execution flags (Negative, Zero, Carry and Overflow)
    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_ExecFlagsType;
#define PROG_EXEC_FLAGS_OVERFLOW_MASK   (0x1UL)
#define PROG_EXEC_FLAGS_OVERFLOW_SHIFT  (0UL)
#define PROG_EXEC_FLAGS_CARRY_MASK      (0x2UL)
#define PROG_EXEC_FLAGS_CARRY_SHIFT     (1UL)
#define PROG_EXEC_FLAGS_ZERO_MASK       (0x4UL)
#define PROG_EXEC_FLAGS_ZERO_SHIFT      (2UL)
#define PROG_EXEC_FLAGS_NEGATIVE_MASK   (0x8UL)
#define PROG_EXEC_FLAGS_NEGATIVE_SHIFT  (3UL)
/** @} */


/**
    @name Condition execution options
    @{
    @brief Condition execution options

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_CondType;
#define PROG_COND_AL    (0x0U)          /**<@brief execute always                                   */
#define PROG_COND_EQ    (0x1U)          /**<@brief Equal. Execute if Z=1                            */
#define PROG_COND_NE    (0x2U)          /**<@brief Not equal.Execute if Z=0                         */
#define PROG_COND_CS    (0x3U)          /**<@brief Higher or same, unsigned. Execute if C=1         */
#define PROG_COND_CC    (0x4U)          /**<@brief Lower, unsigned. Execute if C=0                  */
#define PROG_COND_MI    (0x5U)          /**<@brief Negative. Execute if N=1                         */
#define PROG_COND_PL    (0x6U)          /**<@brief Positive or zero. Execute if N=0                 */
#define PROG_COND_VS    (0x7U)          /**<@brief Overflow. Execute if V=1                         */
#define PROG_COND_VC    (0x8U)          /**<@brief No overflow. Execute if V=0                      */
#define PROG_COND_HI    (0x9U)          /**<@brief Higher, unsigned. Execute if C=1 and Z=0         */
#define PROG_COND_LS    (0xAU)          /**<@brief Lower or same, unsigned. Execute if C=0 and Z=1  */
#define PROG_COND_GE    (0xBU)          /**<@brief Greater than or equal, signed. Execute if N=V    */
#define PROG_COND_LT    (0xCU)          /**<@brief Less than, signed. Execute if N!=V               */
#define PROG_COND_GT    (0xDU)          /**<@brief Greater than, signed. Execute if Z=0 and N=V     */
#define PROG_COND_LE    (0xEU)          /**<@brief Less than or equal, signed. Execute if Z=1 and N!=V */
/** @} */

/**
    @name Operations
    @{
    @brief Operations

    unused:0x04-0x07,0x13-0x1F,0x1B-0x1F,0x29-0x2F,0x30-0x7F

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpType;
#define PROG_OP_HALT            (0x00UL)    /**< @brief Halt instruction.Refer #PROG_OpHaltExtType      */
#define PROG_OP_NOP             (0x01UL)    /**< @brief Nop instruction. Refer #PROG_OpNopExtType       */
#define PROG_OP_BKPT            (0x02UL)    /**< @brief Breakpoint instruction.Refer #PROG_OpBkptExtType*/
#define PROG_OP_BRANCH          (0x03UL)    /**< @brief Branch instruction.Refer #PROG_OpBranchExtType  */
#define PROG_OP_CUST            (0x08UL)    /**< @brief Custom instruction      */
#define PROG_OP_HW_WR           (0x09UL)    /**< @brief Hardware write instruction  */
#define PROG_OP_HW_RD           (0x0AUL)    /**< @brief Hardware read instruction   */
#define PROG_OP_MDIO            (0x0BUL)    /**< @brief MDIO instruction        */
#define PROG_OP_DELAY           (0x0CUL)    /**< @brief Delay instruction       */
#define PROG_OP_STACK           (0x0DUL)    /**< @brief Stack opearation instruction*/
#define PROG_OP_MEM_LDR         (0x0EUL)    /**< @brief Memory load instruction */
#define PROG_OP_MEM_STR         (0x0FUL)    /**< @brief Memory store instruction*/

#define PROG_OP_ADD             (0x10UL)    /**< @brief Add instruction         */
#define PROG_OP_SUB             (0x11UL)    /**< @brief Subtract instruction    */
#define PROG_OP_ADC             (0x12UL)    /**< @brief Add with carry  instruction */
#define PROG_OP_SBC             (0x13UL)    /**< @brief Subtract with carry instruction */
#define PROG_OP_RSB             (0x14UL)    /**< @brief Reverse subtract instruction*/
#define PROG_OP_CMP             (0x15UL)    /**< @brief Compare and set flag instruction*/
#define PROG_OP_EXTEND          (0x16UL)    /**< @brief Sign extension instriuction */
#define PROG_OP_MUL             (0x17UL)    /**< @brief Multiplication instruction  */
#define PROG_OP_DIV             (0x18UL)    /**< @brief Division instruction    */
#define PROG_OP_MOV             (0x19UL)    /**< @brief Move instruction        */
#define PROG_OP_MOV_IMM         (0x1AUL)    /**< @brief Move immediate instruction  */

#define PROG_OP_LSL             (0x20UL)    /**< @brief Loical shift left instruction   */
#define PROG_OP_LSR             (0x21UL)    /**< @brief Logical shift right instruction */
#define PROG_OP_ASR             (0x22UL)    /**< @brief Arithmetic shift right instruction  */
#define PROG_OP_ROR             (0x23UL)    /**< @brief Rotate instruction      */
#define PROG_OP_BIC             (0x24UL)    /**< @brief Bit Clear instruction   */
#define PROG_OP_BIS             (0x25UL)    /**< @brief Bit set instruction     */
#define PROG_OP_ORR             (0x26UL)    /**< @brief Bitwise OR instruction  */
#define PROG_OP_AND             (0x27UL)    /**< @brief Bitwise AND instruction */
#define PROG_OP_XOR             (0x28UL)    /**< @brief Bitwise XOR instruction */
#define PROG_OP_MAX             (PROG_OP_XOR)    /**< @brief Max instruction supported */
/** @} */

/**
    @brief Halt operation extension

    @code{.unparsed}
    halt
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpHaltExtType;

/**
    @brief No operation extension

    @code{.unparsed}
    nop
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpNopExtType;

/**
    @brief Breakpoint operation extension

    @code{.unparsed}
    bkpt
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpBkptExtType;

/**
    @name Branch operation extension
    @{
    @brief Branch operation extension

    @code{.unparsed}
    b r0; uses #PROG_OP_BRANCH_EXT_REG
    b LABEL; uses #PROG_OP_BRANCH_EXT_IMM
    bl r0; uses #PROG_OP_BRANCH_EXT_REG_WITH_LINK
    bl LABEL; uses #PROG_OP_BRANCH_EXT_IMM_WITH_LINK
    @endcode

    When a label is used,  relative offset is preserved in words (positive or negative 16-bit number in syntax 3)

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpBranchExtType;
#define PROG_OP_BRANCH_EXT_REG              (0UL)   /**< @brief Branch to a value in register */
#define PROG_OP_BRANCH_EXT_IMM              (1UL)   /**< @brief Branch to an immediate value  */
#define PROG_OP_BRANCH_EXT_REG_WITH_LINK    (8UL)   /**< @brief Branch with link to a value in register */
#define PROG_OP_BRANCH_EXT_IMM_WITH_LINK    (9UL)   /**< @brief Branch with link to an immediate value */
/** @} */

/**
    @brief Custom operation extension

    @code{.unparsed}
    cust0 rA,rB,rC,rD; uses op code extension set to 0
    cust1 rA,rB,rC,rD; uses op code extension set to 1
    cust2 rA,rB,rC,rD; uses op code extension set to 2
    cust3 rA,rB,rC,rD; uses op code extension set to 3
    cust4 rA,rB,rC,rD; uses op code extension set to 4
    cust5 rA,rB,rC,rD; uses op code extension set to 5
    cust6 rA,rB,rC,rD; uses op code extension set to 6
    cust7 rA,rB,rC,rD; uses op code extension set to 7
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpCustExtType;

/**
    @name Hardware operation extension
    @{
    @brief Hardware operation extension

    @code{.unparsed}
    hwrb rA,[rB,rC]; uses #PROG_OP_HW_EXT_MODE_C_REG and #PROG_OP_HW_EXT_ACCESS_BYTE
    hwrh rA,[rB,rC]; uses #PROG_OP_HW_EXT_MODE_C_REG and #PROG_OP_HW_EXT_ACCESS_HALF
    hwrw rA,[rB,rC]; uses #PROG_OP_HW_EXT_MODE_C_REG and #PROG_OP_HW_EXT_ACCESS_WORD
    hwrb rA,[rB,#N]; uses #PROG_OP_HW_EXT_MODE_N_FIX and #PROG_OP_HW_EXT_ACCESS_BYTE
    hwrh rA,[rB,#N]; uses #PROG_OP_HW_EXT_MODE_N_FIX and #PROG_OP_HW_EXT_ACCESS_HALF
    hwrw rA,[rB,#N]; uses #PROG_OP_HW_EXT_MODE_N_FIX and #PROG_OP_HW_EXT_ACCESS_WORD
    hrdb rA,[rB,rC]; uses #PROG_OP_HW_EXT_MODE_C_REG and #PROG_OP_HW_EXT_ACCESS_BYTE
    hrdh rA,[rB,rC]; uses #PROG_OP_HW_EXT_MODE_C_REG and #PROG_OP_HW_EXT_ACCESS_HALF
    hrdw rA,[rB,rC]; uses #PROG_OP_HW_EXT_MODE_C_REG and #PROG_OP_HW_EXT_ACCESS_WORD
    hrdb rA,[rB,#N]; uses #PROG_OP_HW_EXT_MODE_N_FIX and #PROG_OP_HW_EXT_ACCESS_BYTE
    hrdh rA,[rB,#N]; uses #PROG_OP_HW_EXT_MODE_N_FIX and #PROG_OP_HW_EXT_ACCESS_HALF
    hrdw rA,[rB,#N]; uses #PROG_OP_HW_EXT_MODE_N_FIX and #PROG_OP_HW_EXT_ACCESS_WORD
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpHwExtType;
#define PROG_OP_HW_EXT_ACCESS_MASK     (0x3UL)  /**< @brief Access mask         */
#define PROG_OP_HW_EXT_ACCESS_SHIFT    (0x0UL)  /**< @brief Access shift        */
#define PROG_OP_HW_EXT_ACCESS_BYTE     (0x0UL)  /**< @brief Access byte         */
#define PROG_OP_HW_EXT_ACCESS_HALF     (0x1UL)  /**< @brief Access half word    */
#define PROG_OP_HW_EXT_ACCESS_WORD     (0x2UL)  /**< @brief Access word         */
#define PROG_OP_HW_EXT_MODE_MASK       (0xCUL)  /**< @brief Mode mask           */
#define PROG_OP_HW_EXT_MODE_SHIFT      (0x2UL)  /**< @brief Mode shift          */
#define PROG_OP_HW_EXT_MODE_C_REG      (0x0UL)  /**< @brief C as register index */
#define PROG_OP_HW_EXT_MODE_N_FIX      (0x1UL)  /**< @brief N as immediate const*/
/** @} */

/**
    @name MDIO operation extension
    @{
    @brief MDIO operation extension

    @code{.unparsed}
    mw22 rA,rB,rC,rD; uses #PROG_OP_MDIO_EXT_WRITE_CL22
    mw45 rA,rB,rC,rD; uses #PROG_OP_MDIO_EXT_WRITE_CL45
    mr22 rA,rB,rC,rD; uses #PROG_OP_MDIO_EXT_READ_CL22
    mr45 rA,rB,rC,rD; uses #PROG_OP_MDIO_EXT_READ_CL45
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpMdioExtType;
#define PROG_OP_MDIO_EXT_WRITE_CL22     (0x0UL) /**< @brief CL22 write          */
#define PROG_OP_MDIO_EXT_WRITE_CL45     (0x1UL) /**< @brief CL45 write          */
#define PROG_OP_MDIO_EXT_READ_CL22      (0x8UL) /**< @brief CL22 read           */
#define PROG_OP_MDIO_EXT_READ_CL45      (0x9UL) /**< @brief CL45 read           */
/** @} */

/**
    @name Delay operation extension
    @{
    @brief Delay operation extension

    @code{.unparsed}
    dlyns #I; uses #PROG_OP_DELAY_EXT_NS
    dlyus #I; uses #PROG_OP_DELAY_EXT_US
    dlyms #I; uses #PROG_OP_DELAY_EXT_MS
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpDelayExtType;
#define PROG_OP_DELAY_EXT_NS    (0x0UL) /**< @brief Delay in nano seconds   */
#define PROG_OP_DELAY_EXT_US    (0x1UL) /**< @brief Delay in micro seconds  */
#define PROG_OP_DELAY_EXT_MS    (0x2UL) /**< @brief Delay in milli seconds  */
/** @} */

/**
    @name Stack operation extension
    @{
    @brief Stack operation extension

    @code{.unparsed}
    push {rA,rB,rC,rD}; uses #PROG_OP_STACK_EXT_PUSH_FOUR_REG
    push {rA-rB};       uses #PROG_OP_STACK_EXT_PUSH_ONE_RANGE, A < B, A is even and B is odd
    push {rA-rB,rC-rD}; uses #PROG_OP_STACK_EXT_PUSH_TWO_RANGE, A < B and C < D, A,C is even and B,D is odd
    pop {rA,rB,rC,rD};  uses #PROG_OP_STACK_EXT_POP_FOUR_REG
    pop {rA-rB};        uses #PROG_OP_STACK_EXT_POP_ONE_RANGE, A < B, A is even and B is odd
    pop {rA-rB,rC-rD};  uses #PROG_OP_STACK_EXT_POP_TWO_RANGE, A < B and C < D, A,C is even and B,D is odd
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpStackExtType;
#define PROG_OP_STACK_EXT_PUSH_FOUR_REG   (0x00UL)  /**< @brief Push 4 independent registers    */
#define PROG_OP_STACK_EXT_PUSH_ONE_RANGE  (0x01UL)  /**< @brief Push one range of registers     */
#define PROG_OP_STACK_EXT_PUSH_TWO_RANGE  (0x02UL)  /**< @brief Push two ranges of registers    */
#define PROG_OP_STACK_EXT_POP_FOUR_REG    (0x08UL)  /**< @brief Pop 4 independent registers     */
#define PROG_OP_STACK_EXT_POP_ONE_RANGE   (0x09UL)  /**< @brief Pop one range of registers      */
#define PROG_OP_STACK_EXT_POP_TWO_RANGE   (0x0AUL)  /**< @brief Pop two ranges of registers     */
/** @} */


/**
    @name Memory load/store operation extension
    @{
    @brief Memory load/store operation extension

    @code{.unparsed}
    ldrb rA,[rB,rC lsl rD]; uses #PROG_OP_MEM_EXT_ACCESS_BYTE and #PROG_OP_MEM_EXT_MODE_D_REG
    ldrh rA,[rB,rC lsl rD]; uses #PROG_OP_MEM_EXT_ACCESS_HALF and #PROG_OP_MEM_EXT_MODE_D_REG
    ldr rA,[rB,rC lsl rD];  uses #PROG_OP_MEM_EXT_ACCESS_WORD and #PROG_OP_MEM_EXT_MODE_D_REG
    ldrb rA,[rB,rC lsl #D]; uses #PROG_OP_MEM_EXT_ACCESS_BYTE and #PROG_OP_MEM_EXT_MODE_D_FIX
    ldrh rA,[rB,rC lsl #D]; uses #PROG_OP_MEM_EXT_ACCESS_HALF and #PROG_OP_MEM_EXT_MODE_D_FIX
    ldr rA,[rB,rC lsl #D];  uses #PROG_OP_MEM_EXT_ACCESS_WORD and #PROG_OP_MEM_EXT_MODE_D_FIX
    ldrb rA,[rB,#N];        uses #PROG_OP_MEM_EXT_ACCESS_BYTE and #PROG_OP_MEM_EXT_MODE_N_FIX, N is between -256 to 255
    ldrh rA,[rB,#N];        uses #PROG_OP_MEM_EXT_ACCESS_HALF and #PROG_OP_MEM_EXT_MODE_N_FIX, N is between -256 to 255
    ldr rA,[rB,#N];         uses #PROG_OP_MEM_EXT_ACCESS_WORD and #PROG_OP_MEM_EXT_MODE_N_FIX, N is between -256 to 255

    strb rA,[rB,rC lsl rD]; uses #PROG_OP_MEM_EXT_ACCESS_BYTE and #PROG_OP_MEM_EXT_MODE_D_REG
    strh rA,[rB,rC lsl rD]; uses #PROG_OP_MEM_EXT_ACCESS_HALF and #PROG_OP_MEM_EXT_MODE_D_REG
    str rA,[rB,rC lsl rD];  uses #PROG_OP_MEM_EXT_ACCESS_WORD and #PROG_OP_MEM_EXT_MODE_D_REG
    strb rA,[rB,rC lsl #D]; uses #PROG_OP_MEM_EXT_ACCESS_BYTE and #PROG_OP_MEM_EXT_MODE_D_FIX
    strh rA,[rB,rC lsl #D]; uses #PROG_OP_MEM_EXT_ACCESS_HALF and #PROG_OP_MEM_EXT_MODE_D_FIX
    str rA,[rB,rC lsl #D];  uses #PROG_OP_MEM_EXT_ACCESS_WORD and #PROG_OP_MEM_EXT_MODE_D_FIX
    strb rA,[rB,#N];        uses #PROG_OP_MEM_EXT_ACCESS_BYTE and #PROG_OP_MEM_EXT_MODE_N_FIX, N is between -256 to 255
    strh rA,[rB,#N];        uses #PROG_OP_MEM_EXT_ACCESS_HALF and #PROG_OP_MEM_EXT_MODE_N_FIX, N is between -256 to 255
    str rA,[rB,#N];         uses #PROG_OP_MEM_EXT_ACCESS_WORD and #PROG_OP_MEM_EXT_MODE_N_FIX, N is between -256 to 255
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpMemExtType;
#define PROG_OP_MEM_EXT_ACCESS_MASK     (0x3UL) /**< @brief Access mask         */
#define PROG_OP_MEM_EXT_ACCESS_SHIFT    (0x0UL) /**< @brief Access shift        */
#define PROG_OP_MEM_EXT_ACCESS_BYTE     (0x0UL) /**< @brief Access byte         */
#define PROG_OP_MEM_EXT_ACCESS_HALF     (0x1UL) /**< @brief Access half word    */
#define PROG_OP_MEM_EXT_ACCESS_WORD     (0x2UL) /**< @brief Access word         */
#define PROG_OP_MEM_EXT_MODE_MASK       (0xCUL) /**< @brief C,D usage mask      */
#define PROG_OP_MEM_EXT_MODE_SHIFT      (0x2UL) /**< @brief C,D usage shift     */
#define PROG_OP_MEM_EXT_MODE_D_REG      (0x0UL) /**< @brief C,D are registers   */
#define PROG_OP_MEM_EXT_MODE_D_FIX      (0x1UL) /**< @brief C is register, D is immediate   */
#define PROG_OP_MEM_EXT_MODE_N_FIX      (0x2UL) /**< @brief N as immidiate constant */
/** @} */

/**
    @name Arithmetic operation extension
    @{
    @brief Arithmetic operation extension

    @code{.unparsed}
    add rA,rB,rC;        uses #PROG_OP_ARITH_EXT_NONE and #PROG_OP_ARITH_EXT_SHIFT_NONE
    add rA,rB,rC,lsl rD; uses #PROG_OP_ARITH_EXT_D_REG and #PROG_OP_ARITH_EXT_SHIFT_LSL
    add rA,rB,rC,lsr rD; uses #PROG_OP_ARITH_EXT_D_REG and #PROG_OP_ARITH_EXT_SHIFT_LSR
    add rA,rB,rC,asr rD; uses #PROG_OP_ARITH_EXT_D_REG and #PROG_OP_ARITH_EXT_SHIFT_ASR
    add rA,rB,#N;        uses #PROG_OP_ARITH_EXT_N_FIX and #PROG_OP_ARITH_EXT_SHIFT_NONE
    add rA,rB,rC,lsl #D; uses #PROG_OP_ARITH_EXT_D_FIX and #PROG_OP_ARITH_EXT_SHIFT_LSL, D is between 1 to 16
    add rA,rB,rC,lsr #D; uses #PROG_OP_ARITH_EXT_D_FIX and #PROG_OP_ARITH_EXT_SHIFT_LSR, D is between 1 to 16
    add rA,rB,rC,asr #D; uses #PROG_OP_ARITH_EXT_D_FIX and #PROG_OP_ARITH_EXT_SHIFT_ASR, D is between 1 to 16
    sub rA,rB,rC;        uses #PROG_OP_ARITH_EXT_NONE and #PROG_OP_ARITH_EXT_SHIFT_NONE
    sub rA,rB,rC,lsl rD; uses #PROG_OP_ARITH_EXT_D_REG and #PROG_OP_ARITH_EXT_SHIFT_LSL
    sub rA,rB,rC,lsr rD; uses #PROG_OP_ARITH_EXT_D_REG and #PROG_OP_ARITH_EXT_SHIFT_LSR
    sub rA,rB,rC,asr rD; uses #PROG_OP_ARITH_EXT_D_REG and #PROG_OP_ARITH_EXT_SHIFT_ASR
    sub rA,rB,#N;        uses #PROG_OP_ARITH_EXT_N_FIX and #PROG_OP_ARITH_EXT_SHIFT_NONE
    sub rA,rB,rC,lsl #D; uses #PROG_OP_ARITH_EXT_D_FIX and #PROG_OP_ARITH_EXT_SHIFT_LSL, D is between 1 to 16
    sub rA,rB,rC,lsr #D; uses #PROG_OP_ARITH_EXT_D_FIX and #PROG_OP_ARITH_EXT_SHIFT_LSR, D is between 1 to 16
    sub rA,rB,rC,asr #D; uses #PROG_OP_ARITH_EXT_D_FIX and #PROG_OP_ARITH_EXT_SHIFT_ASR, D is between 1 to 16
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpArithExtType;
#define PROG_OP_ARITH_EXT_MODE_MASK     (0x3UL) /**< @brief Mode mask           */
#define PROG_OP_ARITH_EXT_MODE_SHIFT    (0x0UL) /**< @brief Mode shift          */
#define PROG_OP_ARITH_EXT_NONE          (0x0UL) /**< @brief Mode: none          */
#define PROG_OP_ARITH_EXT_D_REG         (0x1UL) /**< @brief Mode: D is register */
#define PROG_OP_ARITH_EXT_D_FIX         (0x2UL) /**< @brief Mode: D is immediate*/
#define PROG_OP_ARITH_EXT_N_FIX         (0x3UL) /**< @brief Mode: N is immediate*/
#define PROG_OP_ARITH_EXT_SHIFT_MASK    (0xCUL) /**< @brief Bit shift mask      */
#define PROG_OP_ARITH_EXT_SHIFT_SHIFT   (0x2UL) /**< @brief Bit shift shift     */
#define PROG_OP_ARITH_EXT_SHIFT_NONE    (0x0UL) /**< @brief No bit shift        */
#define PROG_OP_ARITH_EXT_SHIFT_LSL     (0x1UL) /**< @brief Logical left shift with D       */
#define PROG_OP_ARITH_EXT_SHIFT_LSR     (0x2UL) /**< @brief Logical right shift with D      */
#define PROG_OP_ARITH_EXT_SHIFT_ASR     (0x3UL) /**< @brief Arithmetic right shift with D   */
/** @} */

/**
    @brief Carry operation extension

    @code{.unparsed}
    adc rA,rB,rC
    sbc rA,rB,rC
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpCarryExtType;

/**
    @brief Reverse subtract operation extension

    @code{.unparsed}
    rsb rA,rB,#N
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpRsubExtType;

/**
    @name Compare operation extension
    @{
    @brief Compare operation extension

    @code{.unparsed}
    cmp rA,rB
    cmp rA,#N
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpCmpExtType;
#define PROG_OP_CMP_EXT_REG         (0UL)
#define PROG_OP_CMP_EXT_IMM         (1UL)
/** @} */

/**
    @name Sign extend operation extension
    @{
    @brief Sign extend operation extension

    @code{.unparsed}
    uxt rA,#N; uses #PROG_OP_EXTEND_EXT_UNSIGNED, N is 8 or16
    sxt rA,#N; uses #PROG_OP_EXTEND_EXT_SIGNED, N is 8 or16
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpExtendExtType;
#define PROG_OP_EXTEND_EXT_UNSIGNED     (0UL)   /**< @brief Unsigned extend     */
#define PROG_OP_EXTEND_EXT_SIGNED       (1UL)   /**< @brief signed extend       */
/** @} */

/**
    @name Multiply operation extension
    @{
    @brief Multiply operation extension

    @code{.unparsed}
    mul rA,rB,rC;     uses #PROG_OP_MUL_EXT_NONE
    mul rA,rB,#N;     uses #PROG_OP_MUL_EXT_FIX
    mull rA,rB,rC,rD; uses #PROG_OP_MUL_EXT_LLONG
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpMulExtType;
#define PROG_OP_MUL_EXT_NONE        (0UL)   /**< @brief 32-bit multiplication           */
#define PROG_OP_MUL_EXT_FIX         (1UL)   /**< @brief multiply with immediate         */
#define PROG_OP_MUL_EXT_LLONG       (2UL)   /**< @brief 64-bit multiplication result    */
/** @} */

/**
    @brief Division operation extension

    @code{.unparsed}
    div rA,rB,rC
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpDivExtType;

/**
    @brief Move operation extension

    @code{.unparsed}
    mov rA,rB
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpMovExtType;

/**
    @name Move 16-bit immediate operation extension
    @{
    @brief Move 16-bit immediate operation extension

    This instruction extension contains 2-bits of register index, and hence can be used
    with r0-r3 only.

    @code{.unparsed}
    mov  rA,#I; uses #PROG_OP_MOV_HALF_EXT_POS_ALL
    hmov rA,#I; uses #PROG_OP_MOV_HALF_EXT_POS_HIGH
    lmov rA,#I; uses #PROG_OP_MOV_HALF_EXT_POS_LOW
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpMovHalfExtType;
#define PROG_OP_MOV_HALF_EXT_POS_MASK       (0xCUL) /**< @brief Position mask   */
#define PROG_OP_MOV_HALF_EXT_POS_SHIFT      (2UL)   /**< @brief Position shift  */
#define PROG_OP_MOV_HALF_EXT_POS_ALL        (0UL)   /**< @brief All positions   */
#define PROG_OP_MOV_HALF_EXT_POS_HIGH       (1UL)   /**< @brief High position   */
#define PROG_OP_MOV_HALF_EXT_POS_LOW        (2UL)   /**< @brief Low position    */
#define PROG_OP_MOV_HALF_EXT_REG_MASK       (0x3UL) /**< @brief Register mask   */
#define PROG_OP_MOV_HALF_EXT_REG_SHIFT      (0UL)   /**< @brief Register shift  */
/** @} */

/**
    @name Bit shift operation extension
    @{
    @brief Bit shift operation extension

    When used with immediate, the immediate must be less than 31.
    When used with register, higher bits are ignored.

    @code{.unparsed}
    lsl rA,rB,rC
    lsl rA,rB,#N
    lsr rA,rB,rC
    lsr rA,rB,#N
    asr rA,rB,rC
    asr rA,rB,#N
    ror rA,rB,rC
    ror rA,rB,#N
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpBitShiftExtType;
#define PROG_OP_BIT_SHIFT_EXT_REG       (0x0UL) /**< @brief shift by register value */
#define PROG_OP_BIT_SHIFT_EXT_IMM       (0x1UL) /**< @brief shift by immediate value*/
/** @} */

/**
    @name Bit set operation extension
    @{
    @brief Bit set operation extension

    When used with immediates, the first immediate is less than second immediate
    and both are less than 31 (set/clear from X to Y).
    When used with registers, higher bits are ignored (set/clear from rB to rC).

    @code{.unparsed}
    bic rA,rB,rC
    bic rA,#X,#Y
    bis rA,rB,rC
    bis rA,#X,#Y
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpBitSetExtType;
#define PROG_OP_BIT_SET_EXT_REG     (0x0UL) /**< @brief set/clear by register value */
#define PROG_OP_BIT_SET_EXT_IMM     (0x1UL) /**< @brief set/clear by immediate value*/
/** @} */

/**
    @brief Bit wise operation extension

    When used with immediate, the immediate must be less than 31.
    When used with register, higher bits are ignored.

    @code{.unparsed}
    orr rA,rB,rC
    orr rA,rB,#N
    and rA,rB,rC
    and rA,rB,#N
    xor rA,rB,rC
    xor rA,rB,#N
    @endcode

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_OpBitWiseExtType;
#define PROG_OP_BIT_WISE_EXT_REG        (0x0UL) /**< @brief bit wise operation by register value */
#define PROG_OP_BIT_WISE_EXT_IMM        (0x1UL) /**< @brief bit wise operation by immediate value*/
/** @} */


/**
    @name Exceptions
    @{
    @brief Exceptions

    @trace #BRCM_SWREQ_PROG
*/
typedef uint32_t PROG_ExceptionType;
#define PROG_EXCEPTION_NONE             (0UL)   /**< @brief No exception                */
#define PROG_EXCEPTION_IACC_VIOL        (1UL)   /**< @brief Instructin access violation */
#define PROG_EXCEPTION_DACC_VIOL        (2UL)   /**< @brief Data access violation       */
#define PROG_EXCEPTION_CYCLE_COUNT      (3UL)   /**< @brief Cycle count exceeded        */
#define PROG_EXCEPTION_DIV_BY_ZERO      (4UL)   /**< @brief Division by zero            */
/** @} */


/**
    @brief Program context

    @trace #BRCM_SWREQ_PROG
*/
typedef struct sPROG_ContextType {
    uint32_t            regs[16UL];
    PROG_ExecFlagsType  flags;
    PROG_ExceptionType  exception;
    int32_t             exitCode;
    uint32_t            curNumCycles;
    uint32_t            dataStart;
    uint8_t             memory[PROG_MEMORY_SIZE];
} PROG_ContextType;

/** @brief Custom instruction function

    When custom instruction is triggered, this function is invoked with appropriate
    arguments (register content is passes in order). The function return value is
    not processed for any flag updates

    @behavior Sync, Re-entrant

    @pre None

    @param[inout]   aArg1       Argument 1 as in first register of custom instruction
    @param[inout]   aArg2       Argument 2 as in second register of custom instruction
    @param[inout]   aArg3       Argument 3 as in third register of custom instruction
    @param[inout]   aArg4       Argument 4 as in fourth register of custom instruction

    @return     32-bit number (preserved into first register)

    @post None

    @trace #BRCM_SWREQ_PROG

    @limitations This function is invoked in unprivileged context.
*/
typedef uint32_t (*PROG_CustomInstrType)(uint32_t aArg1, uint32_t aArg2, uint32_t aArg3, uint32_t aArg4);

/**
    @brief Program information

    @trace #BRCM_SWREQ_PROG
 */
typedef struct sPROG_InfoType {
    PROG_VersionType            version;    /**< @brief Program version         */
    const PROG_InstrType *const program;   /**< @brief Program pointer.
                                        Instructions first until #numInstr, followed by data for #numData*/
    uint32_t                    numInstr;   /**< @brief Number of 32-bit instructions   */
    uint32_t                    numData;    /**< @brief Number of 32-bit data           */
    uint32_t                    stackSize;  /**< @brief Stack needed by the program     */
    uint32_t                    dataSize;   /**< @brief data + bss size needed by program   */
    const PROG_CustomInstrType  custom[PROG_CUSTOM_INSTR_COUNT];
                                        /**< @brief custom instruction function pointers*/
} PROG_InfoType;

/** @brief Execute a program

    Performs below operations
        -# compatibility checks with implemented version and program version
        -# memory size checks requested by program and available in context
        -# executes the instructions
        -# aborts execution in case of any exceptions

    @behavior Sync, Re-entrant

    @pre Context is initialized by caller and arguments are setup in registers

    @param[in]      aInfo           Program information
    @param[inout]   aCtx            Program context
    @param[out]     aMaxExecInstr   Maximum number of instructions to execute for the program

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Execution completed successfully
    @retval     #BCM_ERR_TIME_OUT       Total cycles exceeded aMaxExecInstr
    @retval     #BCM_ERR_CUSTOM         Exception occured
    @retval     #BCM_ERR_NOMEM          Insufficient memory to execute
    @retval     #BCM_ERR_VERSION        Version not supported
    @retval     #BCM_ERR_INVAL_PARAMS   aInfo->program is NULL
    @retval     #BCM_ERR_INVAL_PARAMS   aCtx is NULL
    @retval     #BCM_ERR_INVAL_PARAMS   aInfo is NULL

    @post describe post condition (status after execution of the function)

    @trace #BRCM_SWREQ_PROG
*/
int32_t PROG_Execute(const PROG_InfoType * const aInfo, PROG_ContextType *const aCtx, uint32_t aMaxExecInstr);

#endif /* PROG_H */

/** @} */
