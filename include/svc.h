/*****************************************************************************
 Copyright 2018-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_svc Supervisor Call Interface
    @ingroup grp_abstract

    @addtogroup grp_svc
    @{

    @file svc.h
    @brief This file contains Supervisor Call Interface functions


    @version 0.1 Initial Version
*/

#ifndef SVC_H
#define SVC_H

#include <inttypes.h>
#include <stdint.h>
#include <cpu.h>

/**
    @name SVC Request Architecture IDs
    @{
    @brief Architecture IDs for SVC Requests
*/
#define BRCM_SWARCH_CPU_SVC_MACRO                (0x8501U)    /**< @brief #CPU_SVC_CMD_START      */
#define BRCM_SWARCH_CPU_SVC_MAGIC_MACRO          (0x8502U)    /**< @brief #CPU_SVC_MAGIC_MCU_ID   */
#define BRCM_SWARCH_CPU_SVC_REQUEST_TYPE         (0x8503U)    /**< @brief #CPU_SvcRequestType     */
#define BRCM_SWARCH_CPU_SVC_HANDLER_TYPE         (0x8504U)    /**< @brief #CPU_SvcReqHandlerType  */
#define BRCM_SWARCH_CPU_SVC_HANDLER_PROC         (0x8505U)    /**< @brief #CPU_SvcCmdHandler      */
#define BRCM_SWARCH_CPU_SVC_TEST_SVC_PROC        (0x8506U)    /**< @brief #CPU_SvcTestSvcHandler  */
#define BRCM_SWARCH_CPU_SVC_RUN_TEST_SVC_PROC    (0x8507U)    /**< @brief #CPU_SvcRunTestSvc      */
#define BRCM_SWARCH_CPU_SVC_HANDLER_TABLE_GLOBAL (0x8508U)    /**< @brief #CPU_SvcHandlerFuncTbl  */
#define BRCM_SWARCH_CPU_SVC_PROFILE_DATA_TYPE    (0x8509U)    /**< @brief #CPU_SvcProfileDataType */
#define BRCM_SWARCH_CPU_SVC_PROFILE_DATA_GLOBAL  (0x850AU)    /**< @brief #CPU_SvcProfileData     */
/** @} */

/**
    @name SVC IDs for components
    @{
    @brief SVC number to be used by different components

    @trace #BRCM_SWREQ_CPU_ABSTRACTION
*/
#define CPU_SVC_CMD_START   (0x80UL)   /**< @brief SVC start     */
#define CPU_SVC_MCU_ID      (0x80UL)   /**< @brief MCU           */
#define CPU_SVC_SPT_ID      (0x81UL)   /**< @brief SP804         */
#define CPU_SVC_CCT_ID      (0x82UL)   /**< @brief CCT           */
#define CPU_SVC_URT_ID      (0x83UL)   /**< @brief UART          */
#define CPU_SVC_IIC_ID      (0x84UL)   /**< @brief IIC           */
#define CPU_SVC_SPI_ID      (0x85UL)   /**< @brief SPI           */
#define CPU_SVC_QSP_ID      (0x86UL)   /**< @brief QSPI          */
#define CPU_SVC_WDT_ID      (0x87UL)   /**< @brief Watchdog      */
#define CPU_SVC_GIO_ID      (0x88UL)   /**< @brief GPIO          */
#define CPU_SVC_PMX_ID      (0x89UL)   /**< @brief PinMux        */
#define CPU_SVC_SIO_ID      (0x8AUL)   /**< @brief SDIO          */
#define CPU_SVC_PWM_ID      (0x8BUL)   /**< @brief PWM           */
#define CPU_SVC_ADC_ID      (0x8CUL)   /**< @brief ADC           */
#define CPU_SVC_DMA_ID      (0x8DUL)   /**< @brief DMA330        */
#define CPU_SVC_OTP_ID      (0x8EUL)   /**< @brief OTP           */
#define CPU_SVC_VTM_ID      (0x8FUL)   /**< @brief VTMON         */
#define CPU_SVC_IPC_ID      (0x90UL)   /**< @brief IPC           */
#define CPU_SVC_PCH_ID      (0x91UL)   /**< @brief PATCH        */
#define CPU_SVC_PPR_ID      (0xA0UL)   /**< @brief PixelProcessor*/
#define CPU_SVC_IIS_ID      (0xA1UL)   /**< @brief I2S           */
#define CPU_SVC_UCM_ID      (0xA3UL)   /**< @brief UNICAM        */
#define CPU_SVC_ISP_ID      (0xA4UL)   /**< @brief ISP           */
#define CPU_SVC_VGC_ID      (0xA7UL)   /**< @brief VideoGraphicsComposer */
#define CPU_SVC_AVT_ID      (0xA9UL)   /**< @brief AVT           */
#define CPU_SVC_AMC_ID      (0xB0UL)   /**< @brief AMAC          */
#define CPU_SVC_CAN_ID      (0xB1UL)   /**< @brief CAN           */
#define CPU_SVC_LIN_ID      (0xB2UL)   /**< @brief LIN           */
#define CPU_SVC_CFP_ID      (0xB3UL)   /**< @brief CFP           */
#define CPU_SVC_SWT_ID      (0xB4UL)   /**< @brief SWITCH        */
#define CPU_SVC_XVR_ID      (0xB5UL)   /**< @brief XVR           */
#define CPU_SVC_ETT_ID      (0xB6UL)   /**< @brief Ethernet time */
#define CPU_SVC_XFI_ID      (0xB7UL)   /**< @brief XFI           */
#define CPU_SVC_MDI_ID      (0xB8UL)   /**< @brief MDIO          */
#define CPU_SVC_TCX_ID      (0xB9UL)   /**< @brief TC10          */
#define CPU_SVC_L2F_ID      (0xBAUL)   /**< @brief L2FLTRDRV     */
#define CPU_SVC_L3F_ID      (0xBBUL)   /**< @brief L3FDRV        */
#define CPU_SVC_MSG_ID      (0xC0UL)   /**< @brief MsgQ (IPC)    */
#define CPU_SVC_SHL_ID      (0xC1UL)   /**< @brief Shell         */
#define CPU_SVC_LOG_ID      (0xC2UL)   /**< @brief Log           */
#define CPU_SVC_MEM_ID      (0xC3UL)   /**< @brief MEMORY        */
#define CPU_SVC_OSI_ID      (0xC4UL)   /**< @brief OSIL          */
#define CPU_SVC_DCA_ID      (0xC5UL)   /**< @brief DCache        */
#define CPU_SVC_SOC_ID      (0xC6UL)   /**< @brief Socket        */
#define CPU_SVC_SHP_ID      (0xD0UL)   /**< @brief SecHeap       */
#define CPU_SVC_PKA_ID      (0xD1UL)   /**< @brief PKA           */
#define CPU_SVC_SPU_ID      (0xD2UL)   /**< @brief SPUM          */
#define CPU_SVC_RND_ID      (0xD3UL)   /**< @brief RAND          */
#define CPU_SVC_MSC_ID      (0xD4UL)   /**< @brief MACSEC        */
#define CPU_SVC_CBG_ID      (0xD5UL)   /**< @brief CSRBG         */
#define CPU_SVC_SKA_ID      (0xD6UL)   /**< @brief SKA           */
#define CPU_SVC_TRP_ID      (0xDEUL)   /**< @brief Test Report   */
#define CPU_SVC_TST_ID      (0xDFUL)   /**< @brief Test          */
#define CPU_SVC_CMD_END     (0xDFUL)   /**< @brief SVC end       */
/** @} */

/**
    @name Magic IDs
    @{
    @brief 32-bit magic IDs for all components

    @trace #BRCM_SWREQ_CPU_ABSTRACTION
*/
#define CPU_SVC_MAGIC_MCU_ID    (0x4D435530UL)      /**< @brief MCU            */
#define CPU_SVC_MAGIC_SPT_ID    (0x53505430UL)      /**< @brief SP804          */
#define CPU_SVC_MAGIC_CCT_ID    (0x43435430UL)      /**< @brief CCT            */
#define CPU_SVC_MAGIC_URT_ID    (0x55415254UL)      /**< @brief UART           */
#define CPU_SVC_MAGIC_IIC_ID    (0x49324330UL)      /**< @brief IIC            */
#define CPU_SVC_MAGIC_SPI_ID    (0x53504930UL)      /**< @brief SPI            */
#define CPU_SVC_MAGIC_QSP_ID    (0x51535049UL)      /**< @brief QSPI           */
#define CPU_SVC_MAGIC_WDT_ID    (0x57444F47UL)      /**< @brief Watchdog       */
#define CPU_SVC_MAGIC_GIO_ID    (0x4750494FUL)      /**< @brief GPIO           */
#define CPU_SVC_MAGIC_PMX_ID    (0x504D5558UL)      /**< @brief PinMux         */
#define CPU_SVC_MAGIC_SIO_ID    (0x5344494FUL)      /**< @brief SDIO           */
#define CPU_SVC_MAGIC_PWM_ID    (0x50574D30UL)      /**< @brief PWM            */
#define CPU_SVC_MAGIC_ADC_ID    (0x41444330UL)      /**< @brief ADC            */
#define CPU_SVC_MAGIC_DMA_ID    (0x444D4143UL)      /**< @brief DMAC           */
#define CPU_SVC_MAGIC_OTP_ID    (0x4F545030UL)      /**< @brief OTP            */
#define CPU_SVC_MAGIC_VTM_ID    (0x5626544DUL)      /**< @brief VTMON          */
#define CPU_SVC_MAGIC_PPR_ID    (0x50695072UL)      /**< @brief PixelProcessor */
#define CPU_SVC_MAGIC_IIS_ID    (0x49325330UL)      /**< @brief I2S            */
#define CPU_SVC_MAGIC_UCM_ID    (0x55434D30UL)      /**< @brief UNICAM         */
#define CPU_SVC_MAGIC_ISP_ID    (0x49535030UL)      /**< @brief ISP            */
#define CPU_SVC_MAGIC_VGC_ID    (0x5669436FUL)      /**< @brief VGC            */
#define CPU_SVC_MAGIC_AVT_ID    (0x41565430UL)      /**< @brief AVT            */
#define CPU_SVC_MAGIC_AMC_ID    (0x414D4143UL)      /**< @brief AMAC           */
#define CPU_SVC_MAGIC_CAN_ID    (0x43414E30UL)      /**< @brief CAN            */
#define CPU_SVC_MAGIC_LIN_ID    (0x4C494E30UL)      /**< @brief LIN            */
#define CPU_SVC_MAGIC_CFP_ID    (0x43465030UL)      /**< @brief CFP            */
#define CPU_SVC_MAGIC_L2F_ID    (0x4C324654UL)      /**< @brief L2FT           */
#define CPU_SVC_MAGIC_L3F_ID    (0x4C334657UL)      /**< @brief L3FW           */
#define CPU_SVC_MAGIC_SWT_ID    (0x53575448UL)      /**< @brief SWITCH         */
#define CPU_SVC_MAGIC_MSG_ID    (0x4D534751UL)      /**< @brief MsgQ (IPC)     */
#define CPU_SVC_MAGIC_SHL_ID    (0x5348454CUL)      /**< @brief Shell          */
#define CPU_SVC_MAGIC_LOG_ID    (0x554C4F47UL)      /**< @brief Log            */
#define CPU_SVC_MAGIC_PTM_ID    (0x50544D30UL)      /**< @brief PTM            */
#define CPU_SVC_MAGIC_IPC_ID    (0x49504330UL)      /**< @brief IPC            */
#define CPU_SVC_MAGIC_XVR_ID    (0x58565230UL)      /**< @brief XVR            */
#define CPU_SVC_MAGIC_ETT_ID    (0x45545430UL)      /**< @brief ETT            */
#define CPU_SVC_MAGIC_MEM_ID    (0x444D454DUL)      /**< @brief DBGMEM         */
#define CPU_SVC_MAGIC_OSI_ID    (0x4F53494CUL)      /**< @brief OSIL           */
#define CPU_SVC_MAGIC_DDR_ID    (0x44445230UL)      /**< @brief DDR            */
#define CPU_SVC_MAGIC_DCA_ID    (0x44434143UL)      /**< @brief DCache         */
#define CPU_SVC_MAGIC_SHP_ID    (0x53485030UL)      /**< @brief Secure heap    */
#define CPU_SVC_MAGIC_PKA_ID    (0x504B4130UL)      /**< @brief PKA            */
#define CPU_SVC_MAGIC_SPU_ID    (0x5350554DUL)      /**< @brief SPUM           */
#define CPU_SVC_MAGIC_RND_ID    (0x52414E44UL)      /**< @brief RAND           */
#define CPU_SVC_MAGIC_MSC_ID    (0x4D414353UL)      /**< @brief MACSEC         */
#define CPU_SVC_MAGIC_CBG_ID    (0x43524247UL)      /**< @brief CSRBG          */
#define CPU_SVC_MAGIC_SKA_ID    (0x534B4143UL)      /**< @brief SKA            */
#define CPU_SVC_MAGIC_TST_ID    (0x54455354UL)      /**< @brief Test           */
#define CPU_SVC_MAGIC_PCH_ID    (0x50434844UL)      /**< @brief Patch driver   */
#define CPU_SVC_MAGIC_SOC_ID    (0x534F434BUL)      /**< @brief Socket driver  */
#define CPU_SVC_MAGIC_XFI_ID    (0x58464944UL)      /**< @brief XFID           */
#define CPU_SVC_MAGIC_MDI_ID    (0x4D44494FUL)      /**< @brief MDIO           */
#define CPU_SVC_MAGIC_TCX_ID    (0x54433130UL)      /**< @brief TC10           */
#define CPU_SVC_MAGIC_TRP_ID    (0xFFFFFFFFUL)      /**< @brief Test Report    */
/** @} */

/**
    @brief System command request

    SVC Request parameters

    @trace #BRCM_SWREQ_CPU_ABSTRACTION
 */
typedef struct sCPU_SvcRequestType {
    uint32_t sysReqID;      /**< @brief 8-bit request ID (LSB of 32-bit)                */
    uint32_t magicID;       /**< @brief 32-bit magic number unique to each component    */
    uint32_t cmd;           /**< @brief 32-bit Command ID specific to component         */
    uint8_t *svcIO;         /**< @brief Request Info (I/O type)                         */
    int32_t response;       /**< @brief 32-bit response updated by System SVC handler   */
} CPU_SvcRequestType;


/** @brief Function pointer for component's SVC handler.

    Handles the command requested by the unpriviledged software and executes in
    the priviledged context. These functions are to be defined by each compoenent
    or driver and hooked on to the SVC.

    @behavior Sync, Non-reentrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[in]      aMagicID    Magic ID of the driver  to whom the SVC handled
                                belongs to.
    @param[in]      aCmd        Command ID specific to component.
    @param[inout]   aRequest    Request I/O type specific to the component

    @return void

    @post None

    @trace  #BRCM_SWREQ_CPU_ABSTRACTION

    @limitations None
*/
typedef void (*CPU_SvcReqHandlerType)(uint32_t aMagicID, uint32_t aCmd, uint8_t* aRequest);

/**
    @brief System handler function table

    SVC handler function table.

    @trace #BRCM_SWREQ_CPU_ABSTRACTION
 */
/*  @event         misra_c_2012_rule_5_8_violation, misra_c_2012_rule_8_3_violation
    @issue         Identifier CPU_SvcReqHandlerType is already used to represent a function with external linkage.
    @risk          None
    @justification Issue reported due to Coverity build configuration. */
/* coverity[misra_c_2012_rule_5_8_violation] */
/* coverity[misra_c_2012_rule_8_3_violation] */
extern const CPU_SvcReqHandlerType CPU_SvcHandlerFuncTbl[(CPU_SVC_CMD_END - CPU_SVC_CMD_START) + 1UL];

#ifdef ENABLE_SVC_PROFILING
/**
    @trace #BRCM_SWREQ_CPU_ABSTRACTION
*/
typedef struct sCPU_SvcProfileDataType {
    uint64_t cnt;
    uint64_t maxidx;
    uint64_t minidx;
    uint32_t max;
    uint32_t min;
    uint32_t avg;
} CPU_SvcProfileDataType;

/**
    @trace #BRCM_SWREQ_CPU_ABSTRACTION
*/
extern CPU_SvcProfileDataType CPU_SvcProfileData[(CPU_SVC_CMD_END - CPU_SVC_CMD_START) + 1UL];
#endif

/** @brief Handle requests raised by @ref CPU_SvcRequest

    This API handles SVC Request with the given sysReqID.

    @behavior Sync, Non-reentrant

    @pre CPU shall be in SVC Exception mode

    @param[inout]   aSysReqIO             SVC parameters
    @param[in]      aSysReqID             SVC Request ID

    @return     void

    @post None

    @trace  #BRCM_SWREQ_CPU_ABSTRACTION

    @limitations None
*/
extern void CPU_SvcCmdHandler(uint32_t aSysReqID, CPU_SvcRequestType *aSysReqIO);

/** @brief Test SVC handler

    This handler shall be implemented by the test application that requires test SVC
    functionality

    @behavior Sync, Non-reentrant

    @pre none

    @param[in]       aMagicID        Magic ID of CPU_SVC_MAGIC_TST_ID
    @param[in]       acmd            Command to be executed in system context
    @param[inout]    aSysIO          System IO structure to exchange information

    Return values are documented in reverse-chronological order
    @return          none

    @post none

    @trace  #BRCM_SWREQ_CPU_ABSTRACTION

    @limitations none
*/
#ifdef ENABLE_TEST_SVC
/*  @event         misra_c_2012_rule_5_8_violation, MISRA C-2012 Identifiers
    @issue         Identifier CPU_SvcTestSvcHandler is already used to represent a function with external linkage.
    @risk          None
    @justification Issue reported due to Coverity build configuration. */
/* coverity[misra_c_2012_rule_5_8_violation] */
extern void CPU_SvcTestSvcHandler(uint32_t aMagicID, uint32_t aCmd, uint8_t * aSysIO);
#endif

/** @brief Invoke Test SVC request

    This function invokes test SVC handler through system SVC request

    @behavior Sync, Non-reentrant

    @pre none

    @param[in]       acmd           Command to be executed in system context
    @param[inout]    aData          Data related to the command

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK        Success
    @retval     #BCM_ERR_UNKNOWN   Integration error

    @post none

    @trace  #BRCM_SWREQ_CPU_ABSTRACTION

    @limitations none
*/
extern int32_t CPU_SvcRunTestSvc(uint32_t aCmd, uint8_t *aData);

#endif /* SVC_H */

/** @} */
