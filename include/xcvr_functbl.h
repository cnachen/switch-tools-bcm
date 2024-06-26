/*****************************************************************************
 Copyright 2022-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_xcvr_functbl_ifc XCVR function table Interface
    @ingroup grp_transceiver_abstract

    @addtogroup grp_xcvr_functbl_ifc
    @{

    @file ethxcvr_functbl.h
    @brief Ethernet Transceiver Driver Integration Interfaces
    This header file contains the integration interface for Ethernet Transceiver Driver

    @version 0.01 draft
*/

#ifndef XCVR_FUNCTBL_H
#define XCVR_FUNCTBL_H

#include <xcvr_common.h>

/**
    @name Ethernet Transceiver Driver Integration Interface IDs
    @{
    @brief Integration Interface IDs for Ethernet Transceiver Driver
*/
#define BRCM_SWARCH_ETHXCVR_PHYFUNCTBL_TYPE              (0x8230U)    /**< @brief #ETHXCVR_FuncTblType              */
#define BRCM_SWARCH_ETHXCVR_INIT_TYPE                    (0x8231U)    /**< @brief #ETHXCVR_InitType                 */
#define BRCM_SWARCH_ETHXCVR_RESET_TYPE                   (0x8232U)    /**< @brief #ETHXCVR_ResetType                */
#define BRCM_SWARCH_ETHXCVR_SETMODE_TYPE                 (0x8233U)    /**< @brief #ETHXCVR_SetModeType              */
#define BRCM_SWARCH_ETHXCVR_GETMODE_TYPE                 (0x8234U)    /**< @brief #ETHXCVR_GetModeType              */
#define BRCM_SWARCH_ETHXCVR_SETMASTERMODE_TYPE           (0x8235U)    /**< @brief #ETHXCVR_SetMasterModeType        */
#define BRCM_SWARCH_ETHXCVR_GETMASTERMODE_TYPE           (0x8236U)    /**< @brief #ETHXCVR_GetMasterModeType        */
#define BRCM_SWARCH_ETHXCVR_GETSPEED_TYPE                (0x8237U)    /**< @brief #ETHXCVR_GetSpeedType             */
#define BRCM_SWARCH_ETHXCVR_SETSPEED_TYPE                (0x8238U)    /**< @brief #ETHXCVR_SetSpeedType             */
#define BRCM_SWARCH_ETHXCVR_GETDUPLEXMODE_TYPE           (0x8239U)    /**< @brief #ETHXCVR_GetDuplexModeType        */
#define BRCM_SWARCH_ETHXCVR_SETDUPLEXMODE_TYPE           (0x823AU)    /**< @brief #ETHXCVR_SetDuplexModeType        */
#define BRCM_SWARCH_ETHXCVR_GETFLOWCONTROL_TYPE          (0x823BU)    /**< @brief #ETHXCVR_GetFlowControlType       */
#define BRCM_SWARCH_ETHXCVR_SETFLOWCONTROL_TYPE          (0x823CU)    /**< @brief #ETHXCVR_SetFlowControlType       */
#define BRCM_SWARCH_ETHXCVR_GETLINKSTATE_TYPE            (0x823DU)    /**< @brief #ETHXCVR_GetLinkStateType         */
#define BRCM_SWARCH_ETHXCVR_GETSQIVALUE_TYPE             (0x823EU)    /**< @brief #ETHXCVR_GetSQIValueType          */
#define BRCM_SWARCH_ETHXCVR_LINKIRQHANDLER_TYPE          (0x823FU)    /**< @brief #ETHXCVR_IRQHandlerType       */
#define BRCM_SWARCH_ETHXCVR_LINKCHANGEINDHANDLER_TYPE    (0x8240U)    /**< @brief #ETHXCVR_LinkChangeIndHandlerType */
#define BRCM_SWARCH_ETHXCVR_SETLOOPBACKMODE_TYPE         (0x8241U)    /**< @brief #ETHXCVR_SetLoopbackModeType      */
#define BRCM_SWARCH_ETHXCVR_GETLOOPBACKMODE_TYPE         (0x8242U)    /**< @brief #ETHXCVR_GetLoopbackModeType      */
#define BRCM_SWARCH_ETHXCVR_SETJUMBOMODE_TYPE            (0x8243U)    /**< @brief #ETHXCVR_SetJumboModeType         */
#define BRCM_SWARCH_ETHXCVR_GETJUMBOMODE_TYPE            (0x8244U)    /**< @brief #ETHXCVR_GetJumboModeType         */
#define BRCM_SWARCH_ETHXCVR_SETAUTONEGMODE_TYPE          (0x8246U)    /**< @brief #ETHXCVR_SetAutoNegModeType       */
#define BRCM_SWARCH_ETHXCVR_GETAUTONEGSTATUS_TYPE        (0x8247U)    /**< @brief #ETHXCVR_GetAutoNegStatusType     */
#define BRCM_SWARCH_ETHXCVR_RESTARTAUTONEG_TYPE          (0x8248U)    /**< @brief #ETHXCVR_RestartAutoNegType       */
#define BRCM_SWARCH_ETHXCVR_GETSTATS_TYPE                (0x8249U)    /**< @brief #ETHXCVR_GetStatsType             */
#define BRCM_SWARCH_ETHXCVR_STATEHANDLER_TYPE            (0x824AU)    /**< @brief #ETHXCVR_StateHandlerType         */
#define BRCM_SWARCH_ETHXCVR_UPDATEHWSTATUS_TYPE          (0x824BU)    /**< @brief #ETHXCVR_UpdateHWStatusType       */
#define BRCM_SWARCH_ETHXCVR_DEINIT_TYPE                  (0x824CU)    /**< @brief #ETHXCVR_DeInitType               */
#define BRCM_SWARCH_ETHXCVR_PHYCACHEDINFO_TYPE           (0x824DU)    /**< @brief #ETHXCVR_PhyCachedInfoType        */
#define BRCM_SWARCH_ETHXCVR_PHYCNTXT_TYPE                (0x824EU)    /**< @brief #ETHXCVR_CntxtType                */
#define BRCM_SWARCH_ETHXCVR_GETBASEADDR_TYPE             (0x824FU)    /**< @brief #ETHXCVR_GetBaseAddrType          */
/** @} */


/**
    @brief PHY cached info structure type

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_PhyCachedInfoType {
    ETHXCVR_LinkStateType       linkState;      /**< @brief PHY Link state */
    ETHXCVR_ModeType            mode;           /**< @brief PHY Mode */
    ETHXCVR_BooleanType                        connMode;       /**< @brief PHY connection mode */
    ETHXCVR_BooleanType                        loopbackMode;   /**< @brief PHY loopback mode */
    ETHXCVR_BooleanType                        jumboMode;      /**< @brief PHY jumbo mode */
    ETHXCVR_BooleanType                        autonegMode;    /**< @brief PHY AutoNeg mode */
    ETHXCVR_SpeedType           speed;          /**< @brief PHY speed */
    ETHXCVR_DuplexModeType      duplexMode;     /**< @brief PHY duplex mode */
    ETHXCVR_FlowControlType     flowControl;    /**< @brief PHY flow control */
    ETHXCVR_ModeType            localModeState; /**< @brief PHY Local Mode State */
    uint16_t                    tc10Status;     /**< @brief PHY Captured TC10 Status*/
    uint32_t                    sqiValue;       /**< @brief PHY SQI value */
    ETHXCVR_StatsType           stats;          /**< @brief PHY stats */
    ETHXCVR_AutoNegStatusType   autonegStatus;  /**< @brief PHY Autoneg status */
} ETHXCVR_PhyCachedInfoType;

/**
    @brief PHY context structure type

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_CntxtType {
    ETHXCVR_IDType              id;         /**< @brief PHY identifier */
    ETHXCVR_ModeType            mode;           /**< @brief PHY Mode */
    uint32_t                    data[16UL]; /**< @brief PHY context data */
    ETHXCVR_PhyCachedInfoType   cacheInfo;  /**< @brief PHY cached information */
    BCM_HandleType              connHdl;
} ETHXCVR_CntxtType;

/**
    @brief Function type to initialize

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_InitType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief function type to de-initialize

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_DeInitType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to reset

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ResetType)(uint8_t aId,
                                 ETHXCVR_CntxtType *const aPhyCntxt,
                                 const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to set mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_SetModeType)(uint8_t aId,
                                   ETHXCVR_CntxtType *const aPhyCntxt,
                                   const ETHXCVR_PortConfigType *const aConfig,
                                   ETHXCVR_ModeType aMode);

/**
    @brief Function type to get mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetModeType)(uint8_t aId,
                                   ETHXCVR_CntxtType *const aPhyCntxt,
                                   const ETHXCVR_PortConfigType *const aConfig,
                                   ETHXCVR_ModeType *const aMode);

/**
    @brief Function type to set master/slave mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_SetMasterModeType)(uint8_t aId,
                                     ETHXCVR_CntxtType *const aPhyCntxt,
                                     const ETHXCVR_PortConfigType *const aConfig,
                                     ETHXCVR_BooleanType aMode);

/**
    @brief Function type to get master/slave mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetMasterModeType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_BooleanType *const aMode);

/**
    @brief Function type to get speed

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetSpeedType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_SpeedType *const aSpeed);

/**
    @brief Function type to set speed

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_SetSpeedType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_SpeedType aSpeed);

/**
    @brief Function type to get duplex mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetDuplexModeType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_DuplexModeType *const aDuplexMode);

/**
    @brief Function type to set duplex mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_SetDuplexModeType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_DuplexModeType aDuplexMode);

/**
    @brief Function type to get flow control

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetFlowControlType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_FlowControlType *const aFlowControl);

/**
    @brief Function type to set flow control

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_SetFlowControlType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_FlowControlType aFlowControl);

/**
    @brief Function type to get link state

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetLinkStateType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_LinkStateType *const aLinkState);

/**
    @brief Function type to get SQI value

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetSQIValueType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    uint32_t *const aSQIValue);

/**
    @brief Function type to handle link IRQ

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_IRQHandlerType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_IrqParamsType *const aParams);

/**
    @brief Function type to handle link change indication

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_LinkChangeIndHandlerType)(uint8_t aId,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_LinkStateType *const aLinkState,
                                    uint32_t *const aIsLinkStateChanged);

/**
    @brief Function type to set loopback mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_SetLoopbackModeType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_BooleanType aMode);

/**
    @brief Function type to get loopback mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetLoopbackModeType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_BooleanType *const aMode);

/**
    @brief Function type to set jumbo mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_SetJumboModeType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_BooleanType aJumboMode);

/**
    @brief Function type to get jumbo mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetJumboModeType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_BooleanType *const aJumboMode);

/**
    @brief Function type to set auto-negotiation mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_SetAutoNegModeType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_BooleanType aAutoNegMode);

/**
    @brief Function type to get auto-negotiation status

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetAutoNegStatusType)(ETHXCVR_IDType aID,
                                ETHXCVR_CntxtType *const aPhyCntxt,
                                const ETHXCVR_PortConfigType *const aConfig,
                                ETHXCVR_AutoNegStatusType *const aAutoNegStatus);

/**
    @brief Function type to restart auto-negotiation

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_RestartAutoNegType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to retrieve statistics

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetStatsType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    ETHXCVR_StatsType *const aStats);

/**
    @brief Function type for state handler

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_StateHandlerType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig,
                                    uint32_t *const aIsModeChanged,
                                    ETHXCVR_ModeType *const aMode);

/**
    @brief Function type to update HW status parameters

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_UpdateHWStatusType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to fetch the phy/Bus base address

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_GetBaseAddrType)(ETHXCVR_IDType aID,
                                    ETHXCVR_CntxtType *const aPhyCntxt,
                                    uint32_t *const aAddr);

/**
    @brief Ethernet PHY function table type

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_FuncTblType {
    ETHXCVR_InitType                 init;                 /**< @brief Function type to initialize */
    ETHXCVR_DeInitType               deinit;               /**< @brief Function type to de-initialize */
    ETHXCVR_ResetType                reset;                /**< @brief Function type to reset */
    ETHXCVR_SetModeType              setMode;              /**< @brief Function type to set mode */
    ETHXCVR_GetModeType              getMode;              /**< @brief Function type to get mode */
    ETHXCVR_SetMasterModeType        setMasterMode;        /**< @brief Function type to set master/slave mode */
    ETHXCVR_GetMasterModeType        getMasterMode;        /**< @brief Function type to get master/slave mode */
    ETHXCVR_GetSpeedType             getSpeed;             /**< @brief Function type to get speed */
    ETHXCVR_SetSpeedType             setSpeed;             /**< @brief Function type to set speed */
    ETHXCVR_SetDuplexModeType        setDuplexMode;        /**< @brief Function type to set duplex mode */
    ETHXCVR_GetDuplexModeType        getDuplexMode;        /**< @brief Function type to get duplex mode */
    ETHXCVR_SetFlowControlType       setFlowControl;       /**< @brief Function type to set flow control */
    ETHXCVR_GetFlowControlType       getFlowControl;       /**< @brief Function type to get flow control */
    ETHXCVR_GetLinkStateType         getLinkState;         /**< @brief Function type to get link state */
    ETHXCVR_GetSQIValueType          getSQIValue;          /**< @brief Function type to get SQI value */
    ETHXCVR_SetLoopbackModeType      setLoopbackMode;      /**< @brief Function type to set loopback mode */
    ETHXCVR_GetLoopbackModeType      getLoopbackMode;      /**< @brief Function type to get loopback mode */
    ETHXCVR_SetJumboModeType         setJumboMode;         /**< @brief Function type to set jumbo mode */
    ETHXCVR_GetJumboModeType         getJumboMode;         /**< @brief Function type to get jumbo mode */
    ETHXCVR_SetAutoNegModeType       setAutoNegMode;       /**< @brief Function type to set Auto-negotiation mode */
    ETHXCVR_GetAutoNegStatusType     getAutoNegStatus;     /**< @brief Function type to get Auto-negotiation status */
    ETHXCVR_RestartAutoNegType       restartAutoNeg;       /**< @brief Function type to restart Auto-negotiation */
    ETHXCVR_GetStatsType             getStats;             /**< @brief Function type to get statistics */
    ETHXCVR_StateHandlerType         stateHandler;         /**< @brief Function type for state handler */
    ETHXCVR_UpdateHWStatusType       updateHWStatus;       /**< @brief Function type to update HW status parameters */
    ETHXCVR_IRQHandlerType           irqHandler;           /**< @brief Function type to handle IRQ */
    ETHXCVR_LinkChangeIndHandlerType linkChangeIndHandler; /**< @brief Function type to handle link change indication */
    ETHXCVR_GetBaseAddrType          getBaseAddr;          /**< @brief Function type to get the phy/bus base address */
} ETHXCVR_FuncTblType;

#endif /* XCVR_FUNCTBL_H */

/** @} */
