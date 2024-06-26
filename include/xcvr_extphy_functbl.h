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
    @defgroup grp_xcvr_extphy_functbl_ifc XCVR external PHY function table Interface
    @ingroup grp_transceiver_abstract

    @addtogroup grp_xcvr_extphy_functbl_ifc
    @{

    @file ethxcvr_extphy_functbl.h
    @brief
    This header file contains the integration interface for Transceiver Driver

    @version 0.01 draft
*/

#ifndef XCVR_EXTPHY_FUNCTBL_H
#define XCVR_EXTPHY_FUNCTBL_H

#include <bcm_comp.h>
#include <xcvr_extphy.h>
#include <xcvr_common.h>

/**
    @name Ethernet Transceiver Driver Integration Interface IDs
    @{
    @brief Integration Interface IDs for Ethernet Transceiver Driver
*/
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_IS_SUPPORTED_PROC           (0x8D00U) /**< @brief #ETHXCVR_ExtPhyIsSupportedType        */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_INIT_TYPE                   (0x8D01U) /**< @brief #ETHXCVR_ExtPhyInitType               */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_DE_INIT_TYPE                (0x8D02U) /**< @brief #ETHXCVR_ExtPhyDeInitType             */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_CONFIG_TYPE             (0x8D03U) /**< @brief #ETHXCVR_ExtPhyGetConfigType          */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SET_MODE_TYPE               (0x8D04U) /**< @brief #ETHXCVR_ExtPhySetModeType            */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_MODE_TYPE               (0x8D05U) /**< @brief #ETHXCVR_ExtPhyGetModeType            */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_IDTYPE_TYPE             (0x8D06U) /**< @brief #ETHXCVR_ExtPhyGetIDType              */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_RUN_CABLE_DIAG_TYPE         (0x8D07U) /**< @brief #ETHXCVR_ExtPhyRunCableDiagType       */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SET_LOOPBACK_MODE_TYPE      (0x8D08U) /**< @brief #ETHXCVR_ExtPhySetLoopbackModeType    */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_LOOPBACK_MODE_TYPE      (0x8D09U) /**< @brief #ETHXCVR_ExtPhyGetLoopbackModeType    */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_RE_START_AUTO_NEG_TYPE      (0x8D0AU) /**< @brief #ETHXCVR_ExtPhyReStartAutoNegType     */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_LINK_STATE_TYPE         (0x8D0BU) /**< @brief #ETHXCVR_ExtPhyGetLinkStateType       */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_AUTO_NEG_STATUS_TYPE    (0x8D0CU) /**< @brief #ETHXCVR_ExtPhyGetAutoNegStatusType   */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_REG_READ_TYPE               (0x8D0DU) /**< @brief #ETHXCVR_ExtPhyRegReadType            */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_REG_WRITE_TYPE              (0x8D0EU) /**< @brief #ETHXCVR_ExtPhyRegWriteType           */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_HEALTH_INFO_TYPE        (0x8D0FU) /**< @brief #ETHXCVR_ExtPhyGetHealthInfoType      */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_FW_VERSION_TYPE         (0x8D10U) /**< @brief #ETHXCVR_ExtPhyGetFwVersionType       */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_EXECUTE_FW_TYPE             (0x8D11U) /**< @brief #ETHXCVR_ExtPhyExecuteFwType          */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_UPDATE_FW_TYPE              (0x8D12U) /**< @brief #ETHXCVR_ExtPhyUpdateFwType           */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_IRQHANDLER_TYPE             (0x8D13U) /**< @brief #ETHXCVR_ExtPhyIRQHandlerType         */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_IRQEVENT_TYPE                (0x8D14U) /**< @brief #ETHXCVR_ExtPhyIRQEventType           */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_MACSEC_ENABLE_TYPE          (0x8D15U) /**< @brief #ETHXCVR_ExtPhyMacSecEnableType       */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_MACSEC_DISABLE_TYPE         (0x8D16U) /**< @brief #ETHXCVR_ExtPhyMacSecDisableType      */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_MACSEC_REG_READ_TYPE        (0x8D17U) /**< @brief #ETHXCVR_ExtPhyMacSecRegReadType      */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_MACSEC_REG_WRITE_TYPE       (0x8D18U) /**< @brief #ETHXCVR_ExtPhyMacSecRegWriteType     */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_FUNC_TBL_TYPE               (0x8D19U) /**< @brief #ETHXCVR_ExtPhyFuncTblType            */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_FUNCTBL_GLOBAL              (0x8D1AU) /**< @brief #ETHXCVR_ExtPhyFuncTbl                */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_MACSEC_BLK_TYPE              (0x8D1BU) /**< @brief #ETHXCVR_ExtPhyMacSecBlkType          */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10GETEVENTMASK_TYPE         (0x8D1DU) /**< @brief #ETHXCVR_ExtPhyTC10GetEventMaskType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10GETSTATUS_TYPE            (0x8D1EU) /**< @brief #ETHXCVR_ExtPhyTC10GetStatusType      */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10WAKEUPREQ_TYPE            (0x8D1FU) /**< @brief #ETHXCVR_ExtPhyTC10WakeUpReqType      */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10SLEEPREQ_TYPE             (0x8D20U) /**< @brief #ETHXCVR_ExtPhyTC10SleepReqType       */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10FORCESLEEPREQ_TYPE        (0x8D21U) /**< @brief #ETHXCVR_ExtPhyTC10ForceSleepReqType  */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10SLEEPABORTREQ_TYPE        (0x8D22U) /**< @brief #ETHXCVR_ExtPhyTC10SleepAbortReqType  */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10INIT_TYPE                 (0x8D23U) /**< @brief #ETHXCVR_ExtPhyTC10InitType           */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10FUNCTBL_TYPE              (0x8D24U) /**< @brief #ETHXCVR_ExtPhyTC10FuncTblType        */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10FUNCTBL_GLOBAL            (0x8D25U) /**< @brief #ETHXCVR_ExtPhyTC10FuncTbl            */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10GETSTATS_TYPE             (0x8D26U) /**< @brief #ETHXCVR_ExtPhyTC10GetStatsType       */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10GETWAKEUPREASON_TYPE      (0x8D27U) /**< @brief #ETHXCVR_ExtPhyTC10GetWakeUpReasonType*/
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10ISSUPPORTED_TYPE          (0x8D29U) /**< @brief #ETHXCVR_ExtPhyTC10IsSupportedType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10DISABLEEVENTS_TYPE        (0x8D2AU) /**< @brief #ETHXCVR_ExtPhyTC10DisableEventsType  */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10ENABLEEVENTS_TYPE         (0x8D2BU) /**< @brief #ETHXCVR_ExtPhyTC10EnableEventsType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTIMEFUNCTBL_TYPE              (0x8D2CU) /**< @brief #ETHXCVR_ExtPhyTimeFuncTblType        */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTIMEISSUPPORTED_TYPE          (0x8D2DU) /**< @brief #ETHXCVR_ExtPhyTimeIsSupportedType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTIMEINIT_TYPE                 (0x8D2EU) /**< @brief #ETHXCVR_ExtPhyTimeInitType           */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTIMEGETTIMESTAMP_TYPE         (0x8D2FU) /**< @brief #ETHXCVR_ExtPhyTimeGetTimeStampType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTIMEFUNCTBL_GLOBAL            (0x8D30U) /**< @brief #ETHXCVR_ExtPhyTimeFuncTbl            */
#define BRCM_SWARCH_ETHXCVR_TC10ENTRY_TYPE                      (0x8D31U) /**< @brief #ETHXCVR_TC10EntryType                */
#define BRCM_SWARCH_ETHXCVR_PHYGETTC10CONFIG_PROC               (0x8D32U) /**< @brief #ETHXCVR_PhyGetTC10Config             */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10ALLOWSLEEPREQ_TYPE        (0x8D33U) /**< @brief #ETHXCVR_ExtPhyTC10AllowSleepReqType  */
#define BRCM_SWARCH_ETHXCVR_EXTPHYGETEEESTATS_TYPE              (0x8D34U) /**< @brief #ETHXCVR_ExtPhyGetEEEStatsType        */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SET_MASTER_MODE_TYPE        (0x8D35U) /**< @brief #ETHXCVR_ExtPhySetMasterModeType      */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_MASTER_MODE_TYPE        (0x8D36U) /**< @brief #ETHXCVR_ExtPhyGetMasterModeType      */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_FLASH_ID_TYPE           (0x8D37U) /**< @brief #ETHXCVR_ExtPhyGetFlashIDType         */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10ENABLEPROGRAMSTATE_TYPE   (0x8D38U) /**< @brief #ETHXCVR_ExtPhyTC10EnableProgramStateType */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10EXITHOSTMODE_TYPE         (0x8D39U) /**< @brief #ETHXCVR_ExtPhyTC10ExitHostModeType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10ENABLE_TYPE               (0x8D3AU) /**< @brief #ETHXCVR_ExtPhyTC10EnableType         */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_TC10ALLOW_MDI_WAKE_TYPE     (0x8D3BU) /**< @brief #ETHXCVR_ExtPhyTC10AllowMdiWakeType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHYGETPHYCAPS_TYPE               (0x8D3EU) /**< @brief #ETHXCVR_ExtPhyGetPhyCapsType         */
#define BRCM_SWARCH_ETHXCVR_EXTPHYGETEVENTS_TYPE                (0x8D3FU) /**< @brief #ETHXCVR_ExtPhyGetEventsType          */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SAFETY_IS_SUPPORTED_PROC    (0x8D40U) /**< @brief #ETHXCVR_ExtPhySafetyIsSupportedType  */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SAFETY_GETEVENTS_TYPE       (0x8D41U) /**< @brief #ETHXCVR_ExtPhySafetyGetEventsType    */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SAFETY_FUNC_TBL_TYPE        (0x8D42U) /**< @brief #ETHXCVR_ExtPhySafetyFuncTblType      */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_SAFETY_FUNCTBL_GLOBAL        (0x8D43U) /**< @brief #ETHXCVR_ExtPhySafetyFuncTbl          */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SAFETY_INIT_TYPE            (0x8D44U) /**< @brief #ETHXCVR_ExtPhySafetyInitType         */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SAFETY_SETCFG_TYPE          (0x8D45U) /**< @brief #ETHXCVR_ExtPhySafetySetCfgType       */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SAFETY_GETCFG_TYPE          (0x8D46U) /**< @brief #ETHXCVR_ExtPhySafetyGetCfgType       */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_SAFETY_DISNOTIFY_EVENTS_TYPE (0x8D49U) /**< @brief #ETHXCVR_ExtPhySafetyDisNotifyEventsType */
/** @} */

/** @name ETHXCVR_ExtPhyIRQEventType
    @{
    @brief PHY IRQ event information

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint32_t ETHXCVR_ExtPhyIRQEventType;
#define ETHXCVR_EXTPHY_IRQEVENT_NONE       (0UL)
#define ETHXCVR_EXTPHY_IRQEVENT_LINK       (1UL)
#define ETHXCVR_EXTPHY_IRQEVENT_TC10       (2UL)
#define ETHXCVR_EXTPHY_IRQEVENT_MACSEC     (4UL)
#define ETHXCVR_EXTPHY_IRQEVENT_HEALTH     (8UL)
/** @} */

/**
    @name ETHXCVR_ExtPhyMacSecBlkType;
    @{
    @brief PHY MacSec Block type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint32_t ETHXCVR_ExtPhyMacSecBlkType;       /**< @brief  PHY MACsec block type */
#define ETHXCVR_EXTPHY_MACSEC_BLK_SYS_MISC      (1UL)   /**< @brief MISC Blocks */
#define ETHXCVR_EXTPHY_MACSEC_BLK_MSPU_TOP      (2UL)   /**< @brief MSPU Blocks */
#define ETHXCVR_EXTPHY_MACSEC_BLK_MSPU_MAC      (3UL)   /**< @brief MAC Blocks */
#define ETHXCVR_EXTPHY_MACSEC_BLK_CORE          (4UL)   /**< @brief Ingress/Egress EIP160 Blocks */
#define ETHXCVR_EXTPHY_MACSEC_BLK_COUNT_MAX     (4UL)   /**< @brief MAX Block Count */
/** @} */

/**
    @brief External Phy related common context entry

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_TC10EntryType {
    BCM_StateType           tc10State;
    uint32_t                tc10TableIndex;
    ETHXCVR_PhyIDType       id;
    ETHXCVR_TC10PortConfigType tc10Cfg;
    BCM_HandleType          hdl;
} ETHXCVR_TC10EntryType;

/**
    @brief Function type to check if the given PHY is supported by driver.

    This function can be called by integration layer or application to check
    if the connected PHY is supported by this driver or not.
    This function can be called without initializing the PHY (driver implementation
    shall maintain the list of PHYs supported).
    Function shall return #BCM_ERR_OK is given PHY (aPhyID) is supported by the driver,
    else it shall return #BCM_ERR_NOSUPPORT.

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyIsSupportedType)(BCM_HandleType aConnHdl,
                                                const ETHXCVR_PhyIDType *const aPhyID);
/**
    @brief Function type to initialize PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyInitType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                          const ETHXCVR_PhyIDType *const aPhyID,
                                          const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to De-initialize PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyDeInitType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/**
    @brief Function type to Get PHY Configuration

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetConfigType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                               ETHXCVR_PortConfigType *const aConfig);
/**
    @brief Function type to Set mode for the PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySetModeType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                         ETHXCVR_ModeType aMode, ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to Get current mode of the PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetModeType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                             ETHXCVR_ModeType *const aMode);

/**
    @brief Function type to Get PHY (hardware) identifier

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetIDType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                           ETHXCVR_PhyIDType *const aPhyID);

/**
    @brief Function type to start cable diagnostics

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyRunCableDiagType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                  ETHXCVR_CableDiagResultType *const aResult);

/**
    @brief Function type to set PHY loopback mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySetLoopbackModeType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                     ETHXCVR_LoopbackModeType aMode,
                                                     const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to get PHY loopback mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetLoopbackModeType)(BCM_HandleType aConnH, ETHXCVR_IDType aID,
                                                     ETHXCVR_LoopbackModeType *aMode,
                                                     const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to Restart Auto-negotiation

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyReStartAutoNegType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/**
    @brief Function type to Get link status

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetLinkStateType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                  ETHXCVR_LinkStateType *const aState);

/**
    @brief Function type to get auto-neg status

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetAutoNegStatusType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                      const ETHXCVR_PortConfigType *const aConfig,
                                                      ETHXCVR_ExtPhyAutoNegStatusType *const aStatus);

/**
    @brief Function type to Reads a PHY register/memory

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyRegReadType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                            uint32_t aAddr, uint32_t *const aData);

/**
    @brief Function type to Writes to a PHY register/memory

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyRegWriteType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                              uint32_t aAddr, uint32_t aData);

/**
    @brief Function type to Get the health information of PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetHealthInfoType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                   ETHXCVR_ExtPhyHealthInfoType *const aInfo);

/**
    @brief Function type to Get the firmware version running on PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetFwVersionType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                 ETHXCVR_ExtPhyFwVersionType *const aVersion);

/**
    @brief Function type to Execute given firmware on PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyExecuteFwType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                              const uint8_t *const aData, uint32_t aDataInSz,
                                              uint32_t *const aDataOutSz, uint32_t aFwSz,
                                              ETHXCVR_BooleanType aPartial);

/**
    @brief Function type to Update the firmware on PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyUpdateFwType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                              const uint8_t *const aData, uint32_t aInSz,
                                              uint32_t *const aOutSz, uint32_t aFwSz,
                                              ETHXCVR_BooleanType aPartial);

/**
    @brief Function type to handle link IRQ

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef void (*ETHXCVR_ExtPhyIRQHandlerType) (BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                              ETHXCVR_ExtPhyIRQEventType *const aEvents);

/**
    @brief Function type to Enable MACSEC on PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyMacSecEnableType) (BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/**
    @brief Function type to Disable MACSEC on PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef void (*ETHXCVR_ExtPhyMacSecDisableType) (BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/**
    @brief Function type to read a MACSEC PHY register/memory

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyMacSecRegReadType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                   ETHXCVR_ExtPhyMacSecBlkType aBlkType,
                                                   uint32_t aAddr, uint32_t *const aData);
/**
    @brief Function type to write to a MACSEC PHY register/memory

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyMacSecRegWriteType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                    ETHXCVR_ExtPhyMacSecBlkType aBlkType,
                                                    uint32_t aAddr, uint32_t aData);

/**
    @brief Function type to Get EEE Stats of the PHY

    This API get EEE stats

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle (from RPC_Connect)
    @param[in]     aID          Index of the transceiver
    @param[in]     readOnClear  Read On clear the EEE Stats
    @param[inOut]  aStats       Pointer to EEE Stats

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Events disabled successfully
    @retval     #BCM_ERR_NOSUPPORT     No supported function table found

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetEEEStatsType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                 ETHXCVR_BooleanType readOnClear,
                                                 ETHXCVR_ExtPhyEEEStatsType *const aStats);

/**
    @brief Function type to set master/slave mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySetMasterModeType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                   const ETHXCVR_PortConfigType *const aConfig,
                                                   ETHXCVR_BooleanType aMode);

/**
    @brief Function type to get master/slave mode

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetMasterModeType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                   const ETHXCVR_PortConfigType *const aConfig,
                                                   ETHXCVR_BooleanType *const aMode);

/**
    @brief Function type to get flash ID

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetFlashIDType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                ETHXCVR_FlashIDType *const aFlashID);

/** @brief Get PHY Capabilties

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetPhyCapsType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                const ETHXCVR_PhyIDType *const aPhyID,
                                                ETHXCVR_ExtPhyPhyCapsType *const aPhyCaps);

/** @brief PHY Event Handler

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyGetEventsType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                               ETHXCVR_ExtPhyEventsType *const aEvents);

/** @brief XCVR TC10 Event Handler

    This API handles the events arising out of TC10 block. This API is
    responsible for reading the status registers and interpreting them.

    This API acts as the interrupt handler handling the tc10 interrupts
    or as a polled API to check wake-up.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl       Connection handle from RPC_Connect in the case of external PHYs
                                  Hardware instance in case of integrated PHYs
    @param[in]     aID            Index of the transceiver
    @param[inOut]  aCntxt         Pointer to context structure
    @param[in]     aIsTC10Enabled Boolean to indicate if tc10 is enabled on that phy or not
    @param[out]    aEvents        Pointer to retrieve active events

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Events handled successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10GetEventMaskType)(BCM_HandleType aConnHdl,
                                                      ETHXCVR_IDType aID,
                                                      ETHXCVR_TC10PortContextType *const aCntxt,
                                                      ETHXCVR_BooleanType aIsTC10Enabled,
                                                      ETHXCVR_WakeupEventType *const aEvents);

/** @brief TC10 Get Status

    This API retrieves the status of TC10 driver

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure
    @param[out]    aStatus      Pointer to retrieve status information

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Status retrieved successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10GetStatusType)(BCM_HandleType aConnHdl,
                                                   ETHXCVR_IDType aID,
                                                   ETHXCVR_TC10PortContextType *const aCntxt,
                                                   ETHXCVR_StatusType *const aStatus);

/** @brief TC10 Get Statistics

    This API retrieves the statistics from TC10 driver

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure
    @param[out]    aStatus      Pointer to retrieve statistics

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Statistics retrieved successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10GetStatsType)(BCM_HandleType aConnHdl,
                                                  ETHXCVR_IDType aID,
                                                  ETHXCVR_TC10PortContextType *const aCntxt,
                                                  ETHXCVR_StatsType *const aStats);

/** @brief TC10 Get Wake-up Reason

    This API retrieves the wake-up reason

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure
    @param[out]    aReason      Pointer to retrieve wake-up reason

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Wake-up reason retrieved successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10GetWakeUpReasonType)(BCM_HandleType aConnHdl,
                                                         ETHXCVR_IDType aID,
                                                         ETHXCVR_TC10PortContextType *const aCntxt,
                                                         ETHXCVR_WakeupReasonType *const aReason);

/** @brief XCVR TC10 trigger Wake-up

    This API triggers a TC10 Wake-up request. Based on the current state of the
    phy, a Wake-Up-Pulse or a Wake-Up-Request will be sent appropriately.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Wake-up request successful
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10WakeUpReqType)(BCM_HandleType aConnHdl,
                                                   ETHXCVR_IDType aID,
                                                   ETHXCVR_TC10PortContextType *const aCntxt);

/** @brief XCVR TC10 trigger Sleep

    This API requests a TC10 sleep and implicitly enables accepting further
    sleep requests from link partner

    @behavior Sync, Re-entrant

    @pre Traffic should have been disabled

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Sleep request successful
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
                                       OR TC10 state machine is not in awaken state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10SleepReqType)(BCM_HandleType aConnHdl,
                                                  ETHXCVR_IDType aID,
                                                  ETHXCVR_TC10PortContextType *const aCntxt);

/** @brief XCVR TC10 initiate forceful Sleep

    This API forces a TC10 sleep and implicitly enables accepting further
    sleep requests from link partner

    @behavior Sync, Re-entrant

    @pre Traffic should have been disabled

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Force Sleep successful
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
                                       OR TC10 state machine is not in awaken state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10ForceSleepReqType)(BCM_HandleType aConnHdl,
                                                       ETHXCVR_IDType aID,
                                                       ETHXCVR_TC10PortContextType *const aCntxt);

/** @brief XCVR TC10 trigger Abort Sleep request

    This API abort an ongoing request for sleep issued by link partner

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Sleep abort request successful
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10SleepAbortReqType)(BCM_HandleType aConnHdl,
                                                       ETHXCVR_IDType aID,
                                                       ETHXCVR_TC10PortContextType *const aCntxt);

/** @brief Allow Sleep request

    Sleep requests from remote partner will be aborted by default during boot-up.
    This API enables/disables accepting sleep requests from remote.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure
    @param[in]     aMode        Boolean to indicate if sleep requests have to be allowed or not

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Completed successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
                                       OR TC10 state machine is not in awaken state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10AllowSleepReqType)(BCM_HandleType aConnHdl,
                                                       ETHXCVR_IDType aID,
                                                       ETHXCVR_TC10PortContextType *const aCntxt,
                                                       ETHXCVR_BooleanType aMode);

/** @brief Allow wake up through MDI

    This API enables/disables wakeup of phy based on wake up from remote.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inout]  aCntxt       Pointer to context structure
    @param[in]     aMode        TRUE = Enable wakeup on WUP, FALSE = Disable wakeup on WUP

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Completed successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
                                       OR TC10 state machine is not in awaken state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10AllowMdiWakeType)(BCM_HandleType aConnHdl,
                                                      ETHXCVR_IDType aID,
                                                      ETHXCVR_TC10PortContextType *const aCntxt,
                                                      ETHXCVR_BooleanType aMode);

/** @brief TC10 Init

    This API initialises TC10 hardware logic

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure
    @param[in]     aConfig      Port configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Initialised successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10InitType)(BCM_HandleType aConnHdl,
                                              ETHXCVR_IDType aID,
                                              ETHXCVR_TC10PortContextType *const aCntxt,
                                              const ETHXCVR_TC10PortConfigType *const aConfig);

/** @brief TC10 Enable Program State

    When the TC10 straps are set-up in host mode, TC10 state machine will be
    held in initial state. Upon removing super-isolate, it advances to one of
    program, awake or sleep states based on the flags being set. This API
    enables/disables entering programming state before removing super-isolate
    as part of #ETHXCVR_ExtPhyTC10GetEventMaskType

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure
    @param[in]     aMode        Boolean to Enable/Disable entering Program State.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Success
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10EnableProgramStateType)(BCM_HandleType aConnHdl,
                                                             ETHXCVR_IDType aID,
                                                             ETHXCVR_TC10PortContextType *const aCntxt,
                                                             ETHXCVR_BooleanType aMode);

/** @brief TC10 Exit Host Mode

    This API is meant to signal an exit out of Programming state. While the
    TC10 state machine is in Programming state, calling this API will signal
    the state machine to exit out of programming state and enter "Awake" state.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Success
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10ExitHostModeType)(BCM_HandleType aConnHdl,
                                                       ETHXCVR_IDType aID,
                                                       ETHXCVR_TC10PortContextType *const aCntxt);

/** @brief TC10 Enable

    This API is meant to override the tc10 mode straps to disable TC10
    functionality on a PHY which supports TC10 but the link partner either
    doesn't support or isn't configured to enable TC10.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure
    @param[in]     aMode        Boolean to Enable/Disable TC10 functionality.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Success
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
    @retval     #BCM_ERR_NOSUPPORT     Requested aMode is unsupported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10EnableType)(BCM_HandleType aConnHdl,
                                                ETHXCVR_IDType aID,
                                                ETHXCVR_TC10PortContextType *const aCntxt,
                                                ETHXCVR_BooleanType aMode);

/**
    @brief Function type to check if the given PHY is supported by driver.

    This function can be called by integration layer or application to check
    if the connected PHY is supported by this driver or not.
    This function can be called without initializing the PHY (driver implementation
    shall maintain the list of PHYs supported).
    Function shall return #BCM_ERR_OK is given PHY configuration is supported by the driver,
    else it shall return #BCM_ERR_NOSUPPORT.

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aConfig      Pointer to TC10 configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Driver supports the input configuration
    @retval     #BCM_ERR_NOSUPPORT     Driver doesn't support the input configuration

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10IsSupportedType)(BCM_HandleType aConnHdl,
                                                     const ETHXCVR_TC10PortConfigType *const aConfig);

/** @brief TC10 Enable Events

    This API enables events specific to TC10

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Events enabled successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10EnableEventsType)(BCM_HandleType aConnHdl,
                                                      ETHXCVR_IDType aID,
                                                      ETHXCVR_TC10PortContextType *const aCntxt);

/** @brief TC10 Disable Events

    This API disables events specific to TC10

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aCntxt       Pointer to context structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Events disabled successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTC10DisableEventsType)(BCM_HandleType aConnHdl,
                                                       ETHXCVR_IDType aID,
                                                       ETHXCVR_TC10PortContextType *const aCntxt);

/** @brief Time Init

    This API initialises TC10 hardware logic

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle (from RPC_Connect)
    @param[in]     aID          Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Initialised successfully
    @retval     #BCM_ERR_NOSUPPORT     No supported function table found

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTimeInitType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                              const ETHXCVR_PortConfigType *const aConfig);

/**
    @brief Function type to check if the given PHY is supported by driver.

    This function can be called by integration layer or application to check
    if the connected PHY is supported by this driver or not.
    This function can be called without initializing the PHY (driver implementation
    shall maintain the list of PHYs supported).
    Function shall return #BCM_ERR_OK is given PHY (aPhyID) is supported by the driver,
    else it shall return #BCM_ERR_NOSUPPORT.

    @param[in]     aConnHdl     Connection handle (from RPC_Connect)
    @param[out]    aPhyID       Pointer to retrieve table index

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Table index retrieved successfully
    @retval     #BCM_ERR_NOSUPPORT     No supported function table found

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTimeIsSupportedType)(BCM_HandleType aConnHdl,
                                                     const ETHXCVR_PhyIDType *const aPhyID);

/**
    @brief Function type to Get time 1588 of the PHY

    This API get time stamp

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle (from RPC_Connect)
    @param[in]     aID          Index of the transceiver
    @param[inOut]  aTSInfo      Pointer to time stamp info structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Events disabled successfully
    @retval     #BCM_ERR_NOSUPPORT     No supported function table found

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhyTimeGetTimeStampType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                      ETHXCVR_ExtPhyTimeStampInfoType *const aTSInfo);

/** @brief Function type initialises SAFETY hardware logic

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySafetyInitType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/**
    @brief Function type to check if the given PHY is supported by driver.

    This function can be called by integration layer or application to check
    if the connected PHY is supported by this driver or not.
    This function can be called without initializing the PHY (driver implementation
    shall maintain the list of PHYs supported).
    Function shall return #BCM_ERR_OK is given PHY (aPhyID) is supported by the driver,
    else it shall return #BCM_ERR_NOSUPPORT.

    @param[in]     aConnHdl     Connection handle (from RPC_Connect)
    @param[out]    aPhyID       Pointer to retrieve table index

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Table index retrieved successfully
    @retval     #BCM_ERR_NOSUPPORT     No supported function table found

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySafetyIsSupportedType)(BCM_HandleType aConnHdl,
                                                      const ETHXCVR_PhyIDType *const aPhyID);

/** @brief Function type to Set the temperature and voltage config

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySafetySetCfgType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                 const ETHXCVR_ExtPhySafetyCfgType *const aSafetyCfg);

/** @brief Function type to Get the temperature and voltage config

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySafetyGetCfgType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                 ETHXCVR_ExtPhySafetyCfgType *const aSafetyCfg);

/** @brief PHY SAFETY Event Handler

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySafetyGetEventsType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                    ETHXCVR_ExtPhyEventsType *const aEvents);
/** @brief PHY SAFETY Disable Notify Event Handler

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int32_t (*ETHXCVR_ExtPhySafetyDisNotifyEventsType)(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                           ETHXCVR_ExtPhyEventsType aEvents);
/**
    @brief Ethernet PHY function table type

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_ExtPhyFuncTblType {
    ETHXCVR_ExtPhyIsSupportedType          isSupported;          /**< @brief Function to check if PHY is supported */
    ETHXCVR_ExtPhyInitType                 init;                 /**< @brief Function type to initialize           */
    ETHXCVR_ExtPhyDeInitType               deinit;               /**< @brief Function type to de-initialize        */
    ETHXCVR_ExtPhyGetConfigType            getConfig;            /**< @brief Function type to get config           */
    ETHXCVR_ExtPhySetModeType              setMode;              /**< @brief Function type to set mode             */
    ETHXCVR_ExtPhyGetModeType              getMode;              /**< @brief Function type to get mode             */
    ETHXCVR_ExtPhyGetIDType                getID;                /**< @brief Function type to get ID               */
    ETHXCVR_ExtPhyRunCableDiagType         runCableDiag;         /**< @brief Function type to run cable diag       */
    ETHXCVR_ExtPhySetLoopbackModeType      setLoopbackMode;      /**< @brief Function type to set loopback mode    */
    ETHXCVR_ExtPhyGetLoopbackModeType      getLoopbackMode;      /**< @brief Function type to get loopback mode    */
    ETHXCVR_ExtPhyReStartAutoNegType       reStartAutoNeg;       /**< @brief Function type to restart autogeg      */
    ETHXCVR_ExtPhyGetLinkStateType         getLinkState;         /**< @brief Function type to get link state       */
    ETHXCVR_ExtPhyGetAutoNegStatusType     getAutoNegStatus;     /**< @brief Function type to get autoneg status   */
    ETHXCVR_ExtPhyRegReadType              regRead;              /**< @brief Function type to reg read             */
    ETHXCVR_ExtPhyRegWriteType             regWrite;             /**< @brief Function type to reg write            */
    ETHXCVR_ExtPhyGetHealthInfoType        getHealthInfo;        /**< @brief Function type to get health info      */
    ETHXCVR_ExtPhyGetFwVersionType         getFwVersion;         /**< @brief Function type to get FW version       */
    ETHXCVR_ExtPhyExecuteFwType            executeFw;            /**< @brief Function type to execute FW           */
    ETHXCVR_ExtPhyUpdateFwType             updateFw;             /**< @brief Function type to update FW            */
    ETHXCVR_ExtPhyIRQHandlerType           irqHandler;           /**< @brief Function tyep to IRQ Handler          */
    ETHXCVR_ExtPhyMacSecEnableType         enMacSec;             /**< @brief Function type to Enable MACSEC        */
    ETHXCVR_ExtPhyMacSecDisableType        disMacSec;            /**< @brief Function type to Disable MACSEC       */
    ETHXCVR_ExtPhyMacSecRegReadType        regReadMacSec;        /**< @brief Function type to reg read MACSEC      */
    ETHXCVR_ExtPhyMacSecRegWriteType       regWriteMacSec;       /**< @brief Function type to reg write MACSEC     */
    ETHXCVR_ExtPhyGetEEEStatsType          getEEEStats;          /**< @brief Function type to EEE stats            */
    ETHXCVR_ExtPhySetMasterModeType        setMasterMode;        /**< @brief Function type to set master/slave mode */
    ETHXCVR_ExtPhyGetMasterModeType        getMasterMode;        /**< @brief Function type to get master/slave mode */
    ETHXCVR_ExtPhyGetFlashIDType           getFlashID;           /**< @brief Function type to get the Flash ID      */
    ETHXCVR_ExtPhyGetPhyCapsType           getPhyCaps;           /**< @brief Function pointer to get Phy capabilities */
    ETHXCVR_ExtPhyGetEventsType            getEvents;            /**< @brief Function pointer to get the events       */
} ETHXCVR_ExtPhyFuncTblType;

/**
    @brief Ethernet PHY TC10 function table type

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_ExtPhyTC10FuncTblType {
    ETHXCVR_ExtPhyTC10IsSupportedType   isSupported;   /**< @brief Function to check if PHY is supported     */
    ETHXCVR_ExtPhyTC10InitType          init;          /**< @brief Function pointer to initialise            */
    ETHXCVR_ExtPhyTC10EnableProgramStateType enPgmState; /**< @brief Function pointer to enable entering programming state */
    ETHXCVR_ExtPhyTC10ExitHostModeType  exitHostMode;  /**< @brief Function pointer to exit Host Mode        */
    ETHXCVR_ExtPhyTC10EnableType        enable;        /**< @brief Function pointer to enable/disable TC10 configuration   */
    ETHXCVR_ExtPhyTC10WakeUpReqType     wakeUpReq;     /**< @brief Function pointer to request a wake-up     */
    ETHXCVR_ExtPhyTC10SleepReqType      sleepReq;      /**< @brief Function pointer to request a sleep       */
    ETHXCVR_ExtPhyTC10ForceSleepReqType forceSleepReq; /**< @brief Function pointer to force sleep           */
    ETHXCVR_ExtPhyTC10SleepAbortReqType sleepAbortReq; /**< @brief Function pointer to abort a sleep request */
    ETHXCVR_ExtPhyTC10AllowSleepReqType allowSleepReq; /**< @brief Function pointer to allow sleep request   */
    ETHXCVR_ExtPhyTC10AllowMdiWakeType  allowMdiWake;  /**< @brief Function pointer to allow wake up through MDI */
    ETHXCVR_ExtPhyTC10GetStatusType     getStatus;     /**< @brief Function pointer to get the status        */
    ETHXCVR_ExtPhyTC10GetEventMaskType  getEventMask;  /**< @brief Function pointer to get the events        */
    ETHXCVR_ExtPhyTC10GetStatsType      getStats;      /**< @brief Function pointer to get statistics        */
    ETHXCVR_ExtPhyTC10GetWakeUpReasonType getWakeUpReason; /**< @brief Function pointer to get wake-up reason*/
    ETHXCVR_ExtPhyTC10EnableEventsType  enableEvents;  /**< @brief Function pointer to enable events         */
    ETHXCVR_ExtPhyTC10DisableEventsType disableEvents; /**< @brief Function pointer to disable events        */
} ETHXCVR_ExtPhyTC10FuncTblType;

/**
    @brief Ethernet PHY Time function table type

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_ExtPhyTimeFuncTblType {
    ETHXCVR_ExtPhyTimeIsSupportedType       isSupported;      /**< @brief Function to check if PHY is supported */
    ETHXCVR_ExtPhyTimeInitType              init;             /**< @brief Function pointer to initialise            */
    ETHXCVR_ExtPhyTimeGetTimeStampType      getTimeStamp;     /**< @brief Function pointer to get time stamp        */
} ETHXCVR_ExtPhyTimeFuncTblType;

/**
    @brief Ethernet PHY Safety function table type

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_ExtPhySafetyFuncTblType {
    ETHXCVR_ExtPhySafetyIsSupportedType      isSupported;      /**< @brief Function to check if PHY is supported            */
    ETHXCVR_ExtPhySafetyInitType             init;             /**< @brief Function pointer to initialise                   */
    ETHXCVR_ExtPhySafetySetCfgType           setSafetyCfg;     /**< @brief Function pointer to set SAFETY Config            */
    ETHXCVR_ExtPhySafetyGetCfgType           getSafetyCfg;     /**< @brief Function pointer to set SAFETY Config            */
    ETHXCVR_ExtPhySafetyGetEventsType        getEvents;        /**< @brief Function pointer to get the events               */
    ETHXCVR_ExtPhySafetyDisNotifyEventsType  disNotifyEvents;  /**< @brief Function pointer to disable the notified events  */
} ETHXCVR_ExtPhySafetyFuncTblType;

/** @brief Get the TC10 config for the given port

    This API retrieves the TC10 config for the given port

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle (from RPC_Connect)
    @param[in]     aID          Index of the transceiver

    @retval        NULL         No matching entry found
    @return        Pointer to ETHXCVR_TC10PortContextType

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR

*/
extern const ETHXCVR_TC10PortConfigType* ETHXCVR_PhyGetTC10Config(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/**
    @brief ETHXCVR External Phy Function table instance wrapping all underlying Phy function tables

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern const ETHXCVR_ExtPhyFuncTblType ETHXCVR_ExtPhyFuncTbl;

/**
    @brief ETHXCVR External Phy Function table instance wrapping all underlying TC10 function tables

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern const ETHXCVR_ExtPhyTC10FuncTblType ETHXCVR_ExtPhyTC10FuncTbl;

/**
    @brief ETHXCVR External Phy Function table instance wrapping all underlying Time function tables

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern const ETHXCVR_ExtPhyTimeFuncTblType ETHXCVR_ExtPhyTimeFuncTbl;

/**
    @brief ETHXCVR External Phy Function table instance wrapping all underlying SAFETY function tables

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern const ETHXCVR_ExtPhySafetyFuncTblType ETHXCVR_ExtPhySafetyFuncTbl;

#endif /* XCVR_EXTPHY_FUNCTBL_H */

/** @} */
