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
    @defgroup grp_cpu_exception CPU Abstraction interface (Exceptions)
    @ingroup grp_abstract

    @addtogroup grp_cpu_exception
    @{

    @file cpu.h
    @brief This file contains CPU Abstraction API interfaces for CPU faults (exceptions)

    @version 0.1 Initial Version
*/

#ifndef CPU_EXCEPTIONS_H
#define CPU_EXCEPTIONS_H

#include <inttypes.h>
#include <stdint.h>

/**
    @name CPU abstraction Architecture IDs
    @{
    @brief Architecture IDs for CPU abstraction
*/
#define BRCM_SWARCH_CPU_EXCEPTION_TYPE               (0x8C00U)    /**< @brief #CPU_ExceptionType       */
#define BRCM_SWARCH_CPU_EXCEPTION_ACTION_TYPE        (0x8C01U)    /**< @brief #CPU_ExceptionActionType */
#define BRCM_SWARCH_CPU_EXCEPTION_STATUS_TYPE        (0x8C02U)    /**< @brief #CPU_ExceptionStatusType */

#define BRCM_SWARCH_CPU_SET_EXCEPTION_ACTION_PROC    (0x8C09U)    /**< @brief #CPU_SetExceptionAction  */
#define BRCM_SWARCH_CPU_GET_EXCEPTION_STATUS_PROC    (0x8C0AU)    /**< @brief #CPU_GetExceptionStatus  */
#define BRCM_SWARCH_CPU_EXCEPTION_HANDLER_PROC       (0x8C0BU)    /**< @brief #CPU_ExceptionHandler    */
/** @} */

/**
   @name CPU_ExceptionType
   @{
   @brief CPU exception types

   @trace  #BRCM_SWREQ_CPU_ABSTRACTION
*/
typedef uint32_t CPU_ExceptionType;
#define CPU_EXCEPTION_DBUS_ACCESS       (0x0001UL)     /**< @brief Bus error occurred  while accessing data */
#define CPU_EXCEPTION_IBUS_ACCESS       (0x0002UL)     /**< @brief Bus error occurred while fetching instruction */
#define CPU_EXCEPTION_DACCVIOL          (0x0010UL)     /**< @brief Memory management fault (data access)*/
#define CPU_EXCEPTION_IACCVIOL          (0x0020UL)     /**< @brief Memory management fault (instruction access)*/
#define CPU_EXCEPTION_UNDEFINSTR        (0x0100UL)     /**< @brief undefined instruction fault */
#define CPU_EXCEPTION_UNALIGNED         (0x0200UL)     /**< @brief unaligned access fault */
#define CPU_EXCEPTION_DIVBYZERO         (0x0300UL)     /**< @brief div by 0 fault */
#define CPU_EXCEPTION_DEBUG             (0x1000UL)     /**< @brief Debug event exception */
#define CPU_EXCEPTION_MAX               (16UL)         /**< @brief Maximum number of exceptions */
/** @} */

/**
   @name CPU_ExceptionActionType
   @{
   @brief CPU exception action types

   @trace  #BRCM_SWREQ_CPU_ABSTRACTION
*/
typedef uint32_t CPU_ExceptionActionType;
#define CPU_EXCEPTION_ACTION_NONE       (0x00UL)    /**< @brief stay in while(1) loop on exception entry (don't clear exception reason) */
#define CPU_EXCEPTION_ACTION_CONTINUE   (0x01UL)    /**< @brief Clear the exception reason and return from the exception handler to resume back the execution */
#define CPU_EXCEPTION_ACTION_CRASH_DUMP (0x02UL)    /**< @brief Enable the crash dump mode and jump to crash dump handler */
/** @} */

/**
    @brief CPU Exception status structure

    @trace #BRCM_SWREQ_CPU_ABSTRACTION
*/
typedef struct sCPU_ExceptionStatusType {
    CPU_ExceptionType occurredMask;       /**< @brief Bit mask value of the exception occurred */
    uint32_t          dbusAccessCnt;      /**< @brief Number of times bus access error occurred during data access */
    uint32_t          ibusAccessCnt;      /**< @brief Number of times bus access error occurred during instruction fetch */
    uint32_t          dataAccessViolCnt;  /**< @brief Number of times data access violation occurred */
    uint32_t          instrAccessViolCnt; /**< @brief Number of times instruction access violation occurred */
    uint32_t          undefInstrCnt;    /**< @brief Number of times undefined instruction exception occurred */
    uint32_t          unalignedCnt;     /**< @brief Number of times unaligned access exception occurred */
    uint32_t          divZeroCnt;       /**< @brief Number of times divide by zero exception occurred */
    uint32_t          debugCnt;         /**< @brief number of times debug event exception occurred */
    uint32_t          others;           /**< @brief counter for all other exception which are not list above */
    uint32_t          rsvd[3UL];        /**< @brief reserved for future */
} CPU_ExceptionStatusType;

/** @brief Set the exception action

    Sets the exception action for given exceptions (aException is bit mask value)

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aException      Exception mask value
    @param[in]  aAction         Action to be taken on exception

    @return void

    @post None

    @trace  #BRCM_SWREQ_CPU_ABSTRACTION

    @limitations None
*/
/*  @event         misra_c_2012_rule_5_8_violation, MISRA C-2012 Identifiers
    @issue         Identifier CPU_GetPrivilegeLevel is already used to represent a function\
                   with external linkage.
    @risk          None
    @justification Issue reported due to Coverity build configuration. */
/* coverity[misra_c_2012_rule_5_8_violation] */
void CPU_SetExceptionAction(CPU_ExceptionType aExceptions, CPU_ExceptionActionType aAction);

/** @brief Retrieve exception status

    Retrieve exception status and exception counters

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aStatus      Pointer to Exception status memory

    @return void

    @post None

    @trace  #BRCM_SWREQ_CPU_ABSTRACTION

    @limitations None
*/
/*  @event         misra_c_2012_rule_5_8_violation, MISRA C-2012 Identifiers
    @issue         Identifier CPU_GetPrivilegeLevel is already used to represent a function\
                   with external linkage.
    @risk          None
    @justification Issue reported due to Coverity build configuration. */
/* coverity[misra_c_2012_rule_5_8_violation] */
void CPU_GetExceptionStatus(CPU_ExceptionType aExceptions, CPU_ExceptionStatusType *const aStatus);

/** @brief Generic CPU exception handler

    CPU specific exception handler which can be called from the assembly exception handler.
    Based upon the exception action installed for the specific exception, this handler
    will either enter into while(1) loop or clear the exception reason and return back
    or jump to crash dump handler.

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aStack          Pointer to stack frame
    @param[in]  aExceptionNum   Exception number

    @return void

    @post None

    @trace  #BRCM_SWREQ_CPU_ABSTRACTION

    @limitations None
*/
/*  @event         misra_c_2012_rule_5_8_violation, MISRA C-2012 Identifiers
    @issue         Identifier CPU_GetPrivilegeLevel is already used to represent a function\
                   with external linkage.
    @risk          None
    @justification Issue reported due to Coverity build configuration. */
/* coverity[misra_c_2012_rule_5_8_violation] */
void CPU_ExceptionHandler(uint32_t *aStack, uint32_t aExceptionNum);

#endif /* CPU_EXCEPTIONS_H */

/** @} */
