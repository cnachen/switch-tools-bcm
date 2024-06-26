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
    @defgroup grp_eth_xcvr Ethernet PHY abstract Interface
    @ingroup grp_transceiver_abstract

    @addtogroup grp_eth_xcvr
    @{

    @file eth_xcvr.h

    @brief Ethernet Service: PHY Interface
    This file contains the interfaces for the Ethernet abstract for PHY

    @version 1.0 Initial version
*/

#ifndef XCVR_EXTPHY_H
#define XCVR_EXTPHY_H

#include <bcm_comp.h>
#include <bcm_err.h>
#include <xcvr_common.h>
#include <xcvr_tc10.h>
#include <xcvr_mdio.h>

/**
    @name Ethernet PHY abstract API IDs
    @{
    @brief API IDs for ethernet PHY abstract
*/
#define BRCM_SWARCH_ETHXCVR_EXTPHY_ID_OF_MACRO                  (0x8000U) /**< @brief #ETHXCVR_EXTPHY_ID_OF           */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_ID_MACRO                     (0x8001U) /**< @brief #ETHXCVR_EXTPHY_ID_INIT         */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_MSG_MAX_SIZE_MACRO           (0x8002U) /**< @brief #ETHXCVR_EXTPHY_MSG_MAX_SIZE    */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_FILE_NAME_MAX_LEN_MACRO      (0x8003U) /**< @brief #ETHXCVR_EXTPHY_FILE_NAME_MAX_LEN */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_FW_VERSION_MAX_LEN_MACRO     (0x8004U) /**< @brief #ETHXCVR_EXTPHY_FW_VERSION_MAX_LEN */
#define BRCM_SWARCH_ETHXCVR_EXTPHYHEALTHINFOTYPE_TYPE           (0x8006U) /**< @brief #ETHXCVR_ExtPhyHealthInfoType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHYAUTONEGSTATUSTYPE_TYPE        (0x8007U) /**< @brief #ETHXCVR_ExtPhyAutoNegStatusType */
#define BRCM_SWARCH_ETHXCVR_EXTPHYFWVERSIONTYPE_TYPE            (0x8008U) /**< @brief #ETHXCVR_ExtPhyFwVersionType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHYCONFIGMSGTYPE_TYPE            (0x8009U) /**< @brief #ETHXCVR_ExtPhyConfigMsgType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHYDEINITMSGTYPE_TYPE            (0x800AU) /**< @brief #ETHXCVR_ExtPhyDeInitMsgType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHYMODEMSGTYPE_TYPE              (0x800BU) /**< @brief #ETHXCVR_ExtPhyModeMsgType      */
#define BRCM_SWARCH_ETHXCVR_EXPHYIDMSGTYPE_TYPE                 (0x800CU) /**< @brief #ETHXCVR_ExPhyIDMsgType         */
#define BRCM_SWARCH_ETHXCVR_EXTPHYCABLEDIAGMSGTYPE_TYPE         (0x800DU) /**< @brief #ETHXCVR_ExtPhyCableDiagMsgType */
#define BRCM_SWARCH_ETHXCVR_EXTPHYLBMSGTYPE_TYPE                (0x800EU) /**< @brief #ETHXCVR_ExtPhyLbMsgType        */
#define BRCM_SWARCH_ETHXCVR_EXTPHYLINKSTATEMSGTYPE_TYPE         (0x800FU) /**< @brief #ETHXCVR_ExtPhyLinkStateMsgType */
#define BRCM_SWARCH_ETHXCVR_EXTPHYAUTONEGMSGTYPE_TYPE           (0x8010U) /**< @brief #ETHXCVR_ExtPhyAutoNegMsgType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHYREGRDWRMSGTYPE_TYPE           (0x8011U) /**< @brief #ETHXCVR_ExtPhyRegRdWrMsgType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHYHEALTHMSGTYPE_TYPE            (0x8012U) /**< @brief #ETHXCVR_ExtPhyHealthMsgType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHYFWVERSIONMSGTYPE_TYPE         (0x8013U) /**< @brief #ETHXCVR_ExtPhyFwVersionMsgType */
#define BRCM_SWARCH_ETHXCVR_EXTPHYFWMSGTYPE_TYPE                (0x8014U) /**< @brief #ETHXCVR_ExtPhyFwMsgType        */
#define BRCM_SWARCH_ETHXCVRM_MSGUNION_TYPE                      (0x8015U) /**< @brief #ETHXCVRM_MsgUnionType          */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_INIT_PROC                   (0x8017U) /**< @brief #ETHXCVR_ExtPhyInit             */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_DE_INIT_PROC                (0x8018U) /**< @brief #ETHXCVR_ExtPhyDeInit           */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_CONFIG_PROC             (0x8019U) /**< @brief #ETHXCVR_ExtPhyGetConfig        */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SET_MODE_PROC               (0x801AU) /**< @brief #ETHXCVR_ExtPhySetMode          */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_MODE_PROC               (0x801BU) /**< @brief #ETHXCVR_ExtPhyGetMode          */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_ID_PROC                 (0x801CU) /**< @brief #ETHXCVR_ExtPhyGetID            */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_RUN_CABLE_DIAG_PROC         (0x801DU) /**< @brief #ETHXCVR_ExtPhyRunCableDiag     */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_SET_LOOPBACK_MODE_PROC      (0x801EU) /**< @brief #ETHXCVR_ExtPhySetLoopbackMode  */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_LOOPBACK_MODE_PROC      (0x801FU) /**< @brief #ETHXCVR_ExtPhyGetLoopbackMode  */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_RE_START_AUTO_NEG_PROC      (0x8020U) /**< @brief #ETHXCVR_ExtPhyReStartAutoNeg   */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_LINK_STATE_PROC         (0x8021U) /**< @brief #ETHXCVR_ExtPhyGetLinkState     */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_AUTO_NEG_STATUS_PROC    (0x8022U) /**< @brief #ETHXCVR_ExtPhyGetAutoNegStatus */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_REG_READ_PROC               (0x8023U) /**< @brief #ETHXCVR_ExtPhyRegRead          */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_REG_WRITE_PROC              (0x8024U) /**< @brief #ETHXCVR_ExtPhyRegWrite         */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_HEALTH_INFO_PROC        (0x8025U) /**< @brief #ETHXCVR_ExtPhyGetHealthInfo    */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_FW_VERSION_PROC         (0x8026U) /**< @brief #ETHXCVR_ExtPhyGetFwVersion     */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_EXECUTE_FW_PROC             (0x8027U) /**< @brief #ETHXCVR_ExtPhyExecuteFw        */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_EXECUTE_FW_NET_PROC         (0x8028U) /**< @brief #ETHXCVR_ExtPhyExecuteFwNet     */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_UPDATE_FW_PROC              (0x8029U) /**< @brief #ETHXCVR_ExtPhyUpdateFw         */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_UPDATE_FW_NET_PROC          (0x802AU) /**< @brief #ETHXCVR_ExtPhyUpdateFwNet      */
#define BRCM_SWARCH_ETHXCVRM_MSG_TYPE                           (0x802BU) /**< @brief #ETHXCVRM_MsgType               */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_EVENTS_TYPE                  (0x802CU) /**< @brief #ETHXCVR_ExtPhyEventsType       */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_EVENTS_PROC             (0x802DU) /**< @brief #ETHXCVR_ExtPhyGetEvents        */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_TC10_GET_STATUS_PROC        (0x802EU) /**< @brief #ETHXCVR_ExtPhyTC10GetStatus    */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TIME_STAMP_TYPE              (0x802FU) /**< @brief #ETHXCVR_ExtPhyTimeStampType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TIME_STAMP_QUAL_TYPE         (0x8030U) /**< @brief #ETHXCVR_ExtPhyTimeStampQualType*/
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TIME_STAMP_INFO_TYPE         (0x8031U) /**< @brief #ETHXCVR_ExtPhyTimeStampInfoType*/
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_TIME_STAMP_PROC         (0x8032U) /**< @brief #ETHXCVR_ExtPhyGetTimeStamp     */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TIME_MSG_DIR_TYPE            (0x8033U) /**< @brief #ETHXCVR_ExtPhyTimeMsgDirType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TIME_MSG_TYPE                (0x8034U) /**< @brief #ETHXCVR_ExtPhyTimeMsgType      */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TIME_DOMAIN_TYPE             (0x8035U) /**< @brief #ETHXCVR_ExtPhyDomainType       */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10GETWAKEUPREASON_PROC      (0x8036U) /**< @brief #ETHXCVR_ExtPhyTC10GetWakeUpReason */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10WAKEUPREQ_PROC            (0x8037U) /**< @brief #ETHXCVR_ExtPhyTC10WakeUpReq    */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10SLEEPREQ_PROC             (0x8038U) /**< @brief #ETHXCVR_ExtPhyTC10SleepReq     */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10FORCESLEEPREQ_PROC        (0x8039U) /**< @brief #ETHXCVR_ExtPhyTC10ForceSleepReq */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10SLEEPABORTREQ_PROC        (0x803AU) /**< @brief #ETHXCVR_ExtPhyTC10SleepAbortReq */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10GETWAKEUPMODE_PROC        (0x803BU) /**< @brief #ETHXCVR_ExtPhyTC10GetWakeUpMode */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10ALLOWSLEEPREQ_PROC        (0x803CU) /**< @brief #ETHXCVR_ExtPhyTC10AllowSleepReq */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_EVENTSMSGTYPE_TYPE           (0x803DU) /**< @brief #ETHXCVR_ExtPhyEventsMsgType     */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_EEE_STATS_PROC          (0x803EU) /**< @brief #ETHXCVR_ExtPhyGetEEEStats       */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_EEE_STATS_TYPE               (0x803FU) /**< @brief #ETHXCVR_ExtPhyEEEStatsType      */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_EEE_STATS_MSG_TYPE           (0x8040U) /**< @brief #ETHXCVR_ExtPhyEEEStatsMsgType   */
#define BRCM_SWARCH_ETHXCVR_FLASH_MANUFACTURER_ID_TYPE          (0x8041U) /**< @brief #ETHXCVR_FlashManufacturerIDType */
#define BRCM_SWARCH_ETHXCVR_FLASH_MEMORY_TYPE                   (0x8042U) /**< @brief #ETHXCVR_FlashMemoryType         */
#define BRCM_SWARCH_ETHXCVR_FLASH_MEMORY_DENSITY_TYPE           (0x8043U) /**< @brief #ETHXCVR_FlashMemoryDensityType  */
#define BRCM_SWARCH_ETHXCVR_FLASH_DEVICE_ID_TYPE                (0x8044U) /**< @brief #ETHXCVR_FlashDeviceIDType       */
#define BRCM_SWARCH_ETHXCVR_FLASH_ID_TYPE                       (0x8045U) /**< @brief #ETHXCVR_FlashIDType             */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_FLASH_ID_MSG_TYPE            (0x8046U) /**< @brief #ETHXCVR_ExtPhyFlashIDMsgType    */
#define BRCM_SWARCH_ETHXCVR_EXT_PHY_GET_FLASH_ID_PROC           (0x8047U) /**< @brief #ETHXCVR_ExtPhyGetFlashID        */
#define BRCM_SWARCH_ETHXCVR_EXTPHYTC10ALLOWMDIWAKE_PROC         (0x8048U) /**< @brief #ETHXCVR_ExtPhyTC10AllowMdiWake  */
#define BRCM_SWARCH_ETHXCVR_EXTPHYMODEV2MSG_TYPE                (0x8049U) /**< @brief #ETHXCVR_ExtPhyModeV2MsgType     */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TEMP_TYPE                    (0x804AU) /**< @brief #ETHXCVR_ExtPhyTempType          */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_VOLT_TYPE                    (0x804BU) /**< @brief #ETHXCVR_ExtPhyVoltType          */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TEMP_CFG_TYPE                (0x804CU) /**< @brief #ETHXCVR_ExtPhyTempCfgType       */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_VOLT_CFG_TYPE                (0x804DU) /**< @brief #ETHXCVR_ExtPhyVoltCfgType       */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_SAFETY_CFG_TYPE              (0x804EU) /**< @brief #ETHXCVR_ExtPhySafetyCfgType     */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_SAFETY_CFG_MSG_TYPE          (0x804FU) /**< @brief #ETHXCVR_ExtPhySafetyCfgMsgType  */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_SET_SAFETY_CFG_PROC          (0x8050U) /**< @brief #ETHXCVR_ExtPhySetSafetyCfg      */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_GET_SAFETY_CFG_PROC          (0x8051U) /**< @brief #ETHXCVR_ExtPhyGetSafetyCfg      */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_GET_PHYCAPS_PROC             (0x8052U) /**< @brief #ETHXCVR_ExtPhyGetPhyCaps        */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_PHYCAPS_TYPE                 (0x8053U) /**< @brief #ETHXCVR_ExtPhyPhyCapsType       */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_PHYCAPS_MSG_TYPE             (0x8054U) /**< @brief #ETHXCVR_ExtPhyPhyCapsMsgType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_EVENT_TEMP_TYPE              (0x8055U) /**< @brief #ETHXCVR_ExtPhyEventTempType     */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_EVENT_VOLT_TYPE              (0x8056U) /**< @brief #ETHXCVR_ExtPhyEventVoltType     */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_VOLT_STATUS_TYPE             (0x8057U) /**< @brief #ETHXCVR_ExtPhyVoltStatusType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_VOLT_CAPS_TYPE               (0x8058U) /**< @brief #ETHXCVR_ExtPhyVoltCapsType      */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_VOLT_CAPABLE_TYPE            (0x8059U) /**< @brief #ETHXCVR_ExtPhyVoltCapableType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TEMP_CAPABLE_TYPE            (0x805AU) /**< @brief #ETHXCVR_ExtPhyTempCapableType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_PHY_CAPABLE_TYPE             (0x805BU) /**< @brief #ETHXCVR_ExtPhyPhyCapableType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_SAFETYCAPS_TYPE              (0x805CU) /**< @brief #ETHXCVR_ExtPhySafetyCapsType    */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_TEMP_CAPS_TYPE               (0x805DU) /**< @brief #ETHXCVR_ExtPhyTempCapsType      */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_NOTIFY_EVENT_TYPE            (0x805EU) /**< @brief #ETHXCVR_ExtPhyNotifyEventType   */
#define BRCM_SWARCH_ETHXCVR_EXTPHY_NOTIFY_EVENT_UNION_TYPE      (0x805FU) /**< @brief #ETHXCVR_ExtPhyNotifyEventUnionType   */
#define BRCM_SWARCH_ETHXCVR_CABLEDIAG_RESULT_TYPE               (0x8060U) /**< @brief #ETHXCVR_CableDiagResultType     */
/** @} */

/**
    @brief Macro to Construct Ethernet ETHXCVR Commands

    @trace #BRCM_SWREQ_ETHXCVR
*/
#define ETHXCVR_EXTPHY_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_XCVR, BCM_XCVRMOD_ID, aId)

/**
    @name ETHXCVR External PHY command IDs
    @{
    @brief ETHXCVR command IDs group

    @trace #BRCM_SWREQ_ETHXCVR
*/
#define ETHXCVR_EXTPHY_ID_INIT                  ETHXCVR_EXTPHY_ID_OF(0x00U)  /**< @brief #ETHXCVR_ExtPhyConfigMsgType     */
#define ETHXCVR_EXTPHY_ID_DEINIT                ETHXCVR_EXTPHY_ID_OF(0x01U)  /**< @brief #ETHXCVR_ExtPhyDeInitMsgType     */
#define ETHXCVR_EXTPHY_ID_GET_CONFIG            ETHXCVR_EXTPHY_ID_OF(0x02U)  /**< @brief #ETHXCVR_ExtPhyConfigMsgType     */
#define ETHXCVR_EXTPHY_ID_SET_MODE              ETHXCVR_EXTPHY_ID_OF(0x03U)  /**< @brief #ETHXCVR_ExtPhyModeMsgType       */
#define ETHXCVR_EXTPHY_ID_GET_MODE              ETHXCVR_EXTPHY_ID_OF(0x04U)  /**< @brief #ETHXCVR_ExtPhyModeMsgType       */
#define ETHXCVR_EXTPHY_ID_GET_PHY_ID            ETHXCVR_EXTPHY_ID_OF(0x05U)  /**< @brief #ETHXCVR_ExPhyIDMsgType          */
#define ETHXCVR_EXTPHY_ID_CABLE_DIAG            ETHXCVR_EXTPHY_ID_OF(0x06U)  /**< @brief #ETHXCVR_ExtPhyCableDiagMsgType  */
#define ETHXCVR_EXTPHY_ID_SET_LB                ETHXCVR_EXTPHY_ID_OF(0x07U)  /**< @brief #ETHXCVR_ExtPhyLbMsgType         */
#define ETHXCVR_EXTPHY_ID_GET_LB                ETHXCVR_EXTPHY_ID_OF(0x08U)  /**< @brief #ETHXCVR_ExtPhyLbMsgType         */
#define ETHXCVR_EXTPHY_ID_RESTART_AUTONEG       ETHXCVR_EXTPHY_ID_OF(0x09U)  /**< @brief #ETHXCVR_ExtPhyAutoNegMsgType    */
#define ETHXCVR_EXTPHY_ID_GET_AUTONEG_STATUS    ETHXCVR_EXTPHY_ID_OF(0x0AU)  /**< @brief #ETHXCVR_ExtPhyAutoNegMsgType    */
#define ETHXCVR_EXTPHY_ID_SET_AUTONEG_STATUS    ETHXCVR_EXTPHY_ID_OF(0x12U)  /**< @brief #ETHXCVR_ExtPhyAutoNegMsgType    */
#define ETHXCVR_EXTPHY_ID_GET_LINK_STATE        ETHXCVR_EXTPHY_ID_OF(0x0BU)  /**< @brief #ETHXCVR_ExtPhyLinkStateMsgType  */
#define ETHXCVR_EXTPHY_ID_REG_READ              ETHXCVR_EXTPHY_ID_OF(0x0CU)  /**< @brief #ETHXCVR_ExtPhyRegRdWrMsgType    */
#define ETHXCVR_EXTPHY_ID_REG_WRITE             ETHXCVR_EXTPHY_ID_OF(0x0DU)  /**< @brief #ETHXCVR_ExtPhyRegRdWrMsgType    */
#define ETHXCVR_EXTPHY_ID_GET_HEALTH            ETHXCVR_EXTPHY_ID_OF(0x0EU)  /**< @brief #ETHXCVR_ExtPhyHealthMsgType     */
#define ETHXCVR_EXTPHY_ID_FW_VERSION            ETHXCVR_EXTPHY_ID_OF(0x0FU)  /**< @brief #ETHXCVR_ExtPhyFwVersionMsgType  */
#define ETHXCVR_EXTPHY_ID_FW_EXECUTE            ETHXCVR_EXTPHY_ID_OF(0x10U)  /**< @brief #ETHXCVR_ExtPhyFwMsgType         */
#define ETHXCVR_EXTPHY_ID_FW_UPDATE             ETHXCVR_EXTPHY_ID_OF(0x11U)  /**< @brief #ETHXCVR_ExtPhyFwMsgType         */
#define ETHXCVR_EXTPHY_ID_NOTIFY_LINKSTATUS     ETHXCVR_EXTPHY_ID_OF(0x13U)  /**< @brief #ETHXCVR_NotifyLinkStatusType    */
#define ETHXCVR_EXTPHY_ID_NOTIFY_LINKSTATUSCHNG ETHXCVR_EXTPHY_ID_OF(0x14U)  /**< @brief #ETHXCVR_NotifyLinkStatusType    */
#define ETHXCVR_EXTPHY_ID_GET_TC10WAKEMODE      ETHXCVR_EXTPHY_ID_OF(0x15U)  /**< @brief #ETHXCVRM_TC10WakeUpType         */
#define ETHXCVR_EXTPHY_ID_GET_TC10WAKEREASON    ETHXCVR_EXTPHY_ID_OF(0x16U)  /**< @brief #ETHXCVRM_TC10WakeUpType         */
#define ETHXCVR_EXTPHY_ID_SET_JUMBOMODE         ETHXCVR_EXTPHY_ID_OF(0x17U)  /**< @brief #ETHXCVR_ExtPhyConfigMsgType     */
#define ETHXCVR_EXTPHY_ID_NOTIFY_TC10_EVENT     ETHXCVR_EXTPHY_ID_OF(0x18U)  /**< @brief #ETHXCVR_NotifyTC10InfoType      */
#define ETHXCVR_EXTPHY_ID_GET_EVENTS            ETHXCVR_EXTPHY_ID_OF(0x19U)  /**< @brief #ETHXCVR_ExtPhyEventsMsgType     */
#define ETHXCVR_EXTPHY_ID_GET_TC10_STATUS       ETHXCVR_EXTPHY_ID_OF(0x20U)  /**< @brief #ETHXCVRM_TC10StatusType         */
#define ETHXCVR_EXTPHY_ID_TC10_WAKE_REQ         ETHXCVR_EXTPHY_ID_OF(0x21U)  /**< @brief #ETHXCVRM_TC10PortType           */
#define ETHXCVR_EXTPHY_ID_TC10_SLEEP_REQ        ETHXCVR_EXTPHY_ID_OF(0x22U)  /**< @brief #ETHXCVRM_TC10PortType           */
#define ETHXCVR_EXTPHY_ID_TC10_FORCE_SLEEP_REQ  ETHXCVR_EXTPHY_ID_OF(0x23U)  /**< @brief #ETHXCVRM_TC10PortType           */
#define ETHXCVR_EXTPHY_ID_TC10_SLEEP_ABORT_REQ  ETHXCVR_EXTPHY_ID_OF(0x24U)  /**< @brief #ETHXCVRM_TC10PortType           */
#define ETHXCVR_EXTPHY_ID_TC10_GETWAKEUPMODE    ETHXCVR_EXTPHY_ID_OF(0x25U)  /**< @brief #ETHXCVR_ExtPhyModeMsgType       */
#define ETHXCVR_EXTPHY_ID_GET_EEE_STATS         ETHXCVR_EXTPHY_ID_OF(0x26U)  /**< @brief #ETHXCVR_ExtPhyEEEStatsMsgType   */
#define ETHXCVR_EXTPHY_ID_GET_FLASH_ID          ETHXCVR_EXTPHY_ID_OF(0x27U)  /**< @brief #ETHXCVR_ExtPhyFlashIDMsgType    */
#define ETHXCVR_EXTPHY_ID_SET_MODE_V2           ETHXCVR_EXTPHY_ID_OF(0x28U)  /**< @brief #ETHXCVR_ExtPhyModeV2MsgType     */
#define ETHXCVR_EXTPHY_ID_SET_SAFETY_CFG        ETHXCVR_EXTPHY_ID_OF(0x29U)  /**< @brief #ETHXCVR_ExtPhySafetyCfgMsgType  */
#define ETHXCVR_EXTPHY_ID_GET_SAFETY_CFG        ETHXCVR_EXTPHY_ID_OF(0x30U)  /**< @brief #ETHXCVR_ExtPhySafetyCfgMsgType  */
#define ETHXCVR_EXTPHY_ID_GET_PHY_CAPS          ETHXCVR_EXTPHY_ID_OF(0x31U)  /**< @brief #ETHXCVR_ExtPhyPhyCapsMsgType    */
#define ETHXCVR_EXTPHY_ID_NOTIFY_EXTPHY_EVENT   ETHXCVR_EXTPHY_ID_OF(0x32U)  /**< @brief #ETHXCVR_ExtPhyNotifyEventType   */
#define ETHXCVR_EXTPHY_ID_SET_DMON_SAFETY_CFG   ETHXCVR_EXTPHY_ID_OF(0x33U)  /**< @brief #ETHXCVR_ExtPhySafetyCfgMsgType  */
/** @} */

/**
    @brief Maximum size of command payload in bytes

    @trace #BRCM_SWREQ_ETHXCVR
*/
#define ETHXCVR_EXTPHY_MSG_MAX_SIZE    (416UL)

/**
    @brief Maximum size fw file name

    @trace #BRCM_SWREQ_ETHXCVR
*/
#define ETHXCVR_EXTPHY_FILE_NAME_MAX_LEN    (128UL)

/**
    @brief Maximum size of fw version string

    @trace #BRCM_SWREQ_ETHXCVR
*/
#define ETHXCVR_EXTPHY_FW_VERSION_MAX_LEN  (128UL)

/**
    @name ETHXCVR_ExtPhyAutoNegStatusType
    @{
    @brief PHY auto-negotiation status

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyAutoNegStatusType {
    ETHXCVR_LinkStateType       linkStatus;          /**< @brief link status */
    ETHXCVR_AutoNegStatusType   autoNegStatus;       /**< @brief auto-neg status */
    ETHXCVR_SpeedType           speed;               /**< @brief auto negotiated link speed (without interface suffix) */
    ETHXCVR_DuplexModeType      duplexMode;          /**< @brief link duplex mode */
    ETHXCVR_BooleanType         masterMode;          /**< @brief current mode (TRUE: master, FALSE: slave) */
    uint8_t                     reserved;            /**< @brief reserved        */
} ETHXCVR_ExtPhyAutoNegStatusType;
/** @} */

/**
    @name ETHXCVR_ExtPhyFwVersionType
    @{
    @brief PHY version information

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyFwVersionType {
    uint8_t  versionStr[ETHXCVR_EXTPHY_FW_VERSION_MAX_LEN];  /**< @brief version string             */
    uint32_t len;                                            /**< @brief length of version string   */
    uint32_t reserved;                                       /**< @brief reserved for future use    */
    uint64_t integrityVal;                                   /**< @brief integrity check value
                                                                        (CRC/checksum) of Firmware */
} ETHXCVR_ExtPhyFwVersionType;
/** @} */

/**
    @name ETHXCVR_ExtPhyEventsType
    @{
    @brief PHY Events type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint32_t ETHXCVR_ExtPhyEventsType;                                                 /**< @brief ETHXCVR_ExtPhyEvents */
#define ETHXCVR_EXTPHY_EVENTS_REMOTE_WAKEUP       (ETHXCVR_WAKEUP_EVENT_REMOTE_WAKEUP)     /**< @brief TC10 Wake-up received from remote
                                                                                                (Pin/Wake-up Pulse/Wake-up request)      */
#define ETHXCVR_EXTPHY_EVENTS_LOCAL_WAKEUP        (ETHXCVR_WAKEUP_EVENT_LOCAL_WAKEUP)      /**< @brief TC10 Wake-up initiated by self    */
#define ETHXCVR_EXTPHY_EVENTS_REMOTE_WAKEUP_FAIL  (ETHXCVR_WAKEUP_EVENT_REMOTE_WAKE_FAIL)  /**< @brief TC10 Wake-up request failed       */
#define ETHXCVR_EXTPHY_EVENTS_SLEEP               (ETHXCVR_WAKEUP_EVENT_SLEEP)             /**< @brief TC10 Sleep trigger                */
#define ETHXCVR_EXTPHY_EVENTS_SLEEP_FAIL          (ETHXCVR_WAKEUP_EVENT_SLEEP_FAIL)        /**< @brief TC10 Sleep request failed         */
#define ETHXCVR_EXTPHY_EVENTS_INHIBIT             (ETHXCVR_WAKEUP_EVENT_INHIBIT)           /**< @brief TC10 Inhibit request              */
#define ETHXCVR_EXTPHY_EVENTS_RESERVED            (0x00FF00UL)                             /**< @brief 0xFF00UL are reserved for future use   */
#define ETHXCVR_EXTPHY_EVENTS_TEMPERATURE_THRESH  (0x010000UL)                             /**< @brief Event for Temperature threshold   */
#define ETHXCVR_EXTPHY_EVENTS_VOLTAGE_THRESH      (0x020000UL)                             /**< @brief Event for volatge threshold       */
/** @} */

/**
    @name ETHXCVR_ExtPhyTimeStampType
    @{
    @brief TimeStamp information

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyTimeStampType {
    uint64_t seconds;     /**< @brief seconds component of time     */
    uint32_t nanoseconds; /**< @brief nanoseconds component of time */
    uint32_t reserved;    /**< @brief reserved for future use       */
} ETHXCVR_ExtPhyTimeStampType;
/** @} */

/**
    @name ETHXCVR_ExtPhyDomainType
    @{
    @brief ExtPhy PTP Domain number
    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint8_t ETHXCVR_ExtPhyDomainType;  /**< @brief typedef for domain number */
/** @} */

/**
    @name ETHXCVR_ExtPhyTimeMsgDirType
    @{
    @brief Ethernet PTP message direction type
    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint8_t ETHXCVR_ExtPhyTimeMsgDirType;  /**< @brief typedef for ExtPhy Time message direction type   */
#define ETHXCVR_EXTPHY_TIME_MSG_DIR_RX         (0U)  /**< @brief Message Direction type of RX */
#define ETHXCVR_EXTPHY_TIME_MSG_DIR_TX         (1U)  /**< @brief Message Direction type of TX */
/** @} */

/**
    @name ETHXCVR_ExtPhyTimeMsgType
    @{
    @brief ExtPhy PTP message type
    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint8_t ETHXCVR_ExtPhyTimeMsgType;           /**< @brief typedef for ExtPhy Time message type   */
#define ETHXCVR_EXTPHY_TIME_MSG_SYNC           (0U)  /**< @brief Message type of Sync */
#define ETHXCVR_EXTPHY_TIME_MSG_DELAY_REQ      (1U)  /**< @brief Message type of Delay Request */
#define ETHXCVR_EXTPHY_TIME_MSG_PDELAY_REQ     (2U)  /**< @brief Message type of Peer Delay Request */
#define ETHXCVR_EXTPHY_TIME_MSG_PDELAY_RESP    (3U)  /**< @brief Message type of Peer Delay Response */
/** @} */

/**
    @name ETHXCVR_ExtPhyTimeStampQualType
    @{
    @brief Ethernet transmit result type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint32_t ETHXCVR_ExtPhyTimeStampQualType; /**< @brief ETHXCVR_ExtPhyTimeStampQual typedef */
#define ETHXCVR_EXTPHY_TIME_STAMP_QUAL_VALID      (0x0UL)   /**< @brief Valid timestamp  */
#define ETHXCVR_EXTPHY_TIME_STAMP_QUAL_INVALID    (0x1UL)   /**< @brief Invalid timestamp */
#define ETHXCVR_EXTPHY_TIME_STAMP_QUAL_UNCERTAIN  (0x2UL)   /**< @brief Uncertain timestamp */
/** @} */

/**
+    @name ETHXCVR_ExtPhyTimeInfoType
+    @{
+    @brief Time information type
+
+    @trace #BRCM_SWREQ_ETHXCVR
+ */
typedef struct sETHXCVR_ExtPhyTimeStampInfoType {
    ETHXCVR_ExtPhyTimeMsgDirType  direction;              /**< @brief TX/RX direction */
    ETHXCVR_ExtPhyTimeMsgType msgType;                    /**< @brief PTP message type */
    ETHXCVR_ExtPhyDomainType  domainNumber;               /**< @brief Domain number */
    uint16_t seqID;                                       /**< @brief Sequence ID */
    uint16_t majorSDOID;                                  /**< @brief Domain Major SDO ID */
    uint16_t minorSDOID;                                  /**< @brief Domain Minor SDO ID */
    uint8_t  rsvd[4U];                                    /**< @brief reserved */
    ETHXCVR_ExtPhyTimeStampType freeTS;                   /**< @brief TimeStamp */
    ETHXCVR_ExtPhyTimeStampQualType freeTSQual;           /**< @brief Quality of the TimeStamp */
    uint32_t reserved[7U];                                /**< @brief reserved */
} ETHXCVR_ExtPhyTimeStampInfoType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyTimeStampInfoType, 64UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */


/**
    @name ETHXCVR_ExtPhyEEEStatsType
    @{
    @brief EEE stats type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyEEEStatsType {
    ETHXCVR_EEEModeType eeeMode;        /**< @brief EEE Mode */
    uint8_t reserved[3U];               /**< @brief reserved */
    uint32_t txCount;                   /**< @brief tx Counter */
    uint32_t txDuration;                /**< @brief tx Duration */
    uint32_t rxCount;                   /**< @brief rx Counter */
    uint32_t rxDuration;                /**< @brief rx Duration */
} ETHXCVR_ExtPhyEEEStatsType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyEEEStatsType, 20UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyTempType
    @{
    @brief Temperature type (in Celsius)

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef int16_t ETHXCVR_ExtPhyTempType;
/** @} */

/**
    @name ETHXCVR_ExtPhyVoltType
    @{
    @brief Voltage in millivolts

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint16_t ETHXCVR_ExtPhyVoltType;
#define ETHXCVR_EXTPHY_VOLT_NONE            (0UL)         /* Default value */
#define ETHXCVR_EXTPHY_VOLT_0V8             (800U)        /* 800 mV        */
#define ETHXCVR_EXTPHY_VOLT_1V0             (1000U)       /* 1000 mV       */
#define ETHXCVR_EXTPHY_VOLT_1V8             (1800U)       /* 1800 mV       */
#define ETHXCVR_EXTPHY_VOLT_2V5             (2500U)       /* 2500 mV       */
#define ETHXCVR_EXTPHY_VOLT_3V3             (3300U)       /* 3300 mV       */
/** @} */

/**
    @name ETHXCVR_ExtPhyEventTempType
    @{
    @brief Temperature event type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint16_t ETHXCVR_ExtPhyEventTempType;
#define ETHXCVR_EXTPHY_EVENT_TEMP_HIGH_THRESH1  (0x0001U)     /**< @brief VTOM event for Temperature High threshold-1         */
#define ETHXCVR_EXTPHY_EVENT_TEMP_HIGH_THRESH2  (0x0002U)     /**< @brief VTOM event for Temperature High threshold-2         */
#define ETHXCVR_EXTPHY_EVENT_TEMP_LOW_THRESH1   (0x0010U)     /**< @brief VTOM event for Temperature Low threshold-1          */
#define ETHXCVR_EXTPHY_EVENT_TEMP_LOW_THRESH2   (0x0020U)     /**< @brief VTOM event for Temperature Low threshold-2          */
/** @} */

/**
    @name ETHXCVR_ExtPhyEventVoltType
    @{
    @brief Voltage event type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint16_t ETHXCVR_ExtPhyEventVoltType;
#define ETHXCVR_EXTPHY_EVENT_VOLT_HIGH_THRESH1  (0x0001U)    /**< @brief VTOM event for Voltage High threshold-1         */
#define ETHXCVR_EXTPHY_EVENT_VOLT_HIGH_THRESH2  (0x0002U)    /**< @brief VTOM event for Voltage High threshold-2         */
#define ETHXCVR_EXTPHY_EVENT_VOLT_LOW_THRESH1   (0x0010U)    /**< @brief VTOM event for Voltage Low threshold-1          */
#define ETHXCVR_EXTPHY_EVENT_VOLT_LOW_THRESH2   (0x0020U)    /**< @brief VTOM event for Voltage Low threshold-2          */
/** @} */

/**
    @name ETHXCVR_ExtPhyTempCfgType
    @{
    @brief Temperature configuration

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyTempCfgType {
    ETHXCVR_ExtPhyTempType         threshLow1;   /**< @brief Temperature low-1 threshold value (in Celsius) */
    ETHXCVR_ExtPhyTempType         threshHigh1;  /**< @brief Temperature high-1 threshold value (in Celsius) */
    ETHXCVR_ExtPhyTempType         threshLow2;   /**< @brief Temperature low-2 threshold value (in Celsius) */
    ETHXCVR_ExtPhyTempType         threshHigh2;  /**< @brief Temperature high-2 threshold value (in Celsius) */
    ETHXCVR_ExtPhyEventTempType    eventEnable;  /**< @brief Temperature Mointer Event enable(pin) */
    ETHXCVR_ExtPhyEventTempType    faultEnable;  /**< @brief Temperature Fault enable */
    uint8_t                        rsvd[8U];     /**< @brief reserved */
} ETHXCVR_ExtPhyTempCfgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyTempCfgType, 20UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyVoltCfgType
    @{
    @brief Voltage configuration

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyVoltCfgType {
    ETHXCVR_ExtPhyVoltType         nominalValue; /**< @brief Nominal voltage @xsd default:ETHXCVR_EXTPHY_VOLT_NONE */
    uint16_t                       threshLow1;   /**< @brief Voltage low-1 threshold value (in mV) */
    uint16_t                       threshHigh1;  /**< @brief Voltage high-1 threshold value (in mV) */
    uint16_t                       threshLow2;   /**< @brief Voltage low-2 threshold value (in mV) */
    uint16_t                       threshHigh2;  /**< @brief Voltage high-2 threshold value (in mV) */
    ETHXCVR_ExtPhyEventVoltType    eventEnable;  /**< @brief Voltage Mointer Event enable(pin) */
    ETHXCVR_ExtPhyEventVoltType    faultEnable;  /**< @brief Voltage Fault enable */
    uint8_t                        rsvd[10U];    /**< @brief reserved */
} ETHXCVR_ExtPhyVoltCfgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyVoltCfgType, 24UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhySafetyCfgType
    @{
    @brief SAFETY configuration

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhySafetyCfgType {
    uint32_t                     reserved;     /**< @brief reserved @xsd magic rsvd */
    ETHXCVR_ExtPhyTempCfgType    tempCfg;      /**< @brief Temperature Cofig */
    ETHXCVR_ExtPhyVoltCfgType    voltCfg[6U];  /**< @brief Voltate Cofig */
    uint8_t                      rsvd[24U];    /**< @brief reserved */
} ETHXCVR_ExtPhySafetyCfgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhySafetyCfgType, 192UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */


/**
    @name ETHXCVR_ExtPhyVoltStatusType
    @{
    @brief Voltage Status

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyVoltStatusType {
    ETHXCVR_ExtPhyVoltType        nominalValue; /**< @brief Nominal voltage @xsd default:ETHXCVR_EXTPHY_VOLT_NONE */
    ETHXCVR_ExtPhyEventVoltType   events;       /**< @brief Volt Events */
} ETHXCVR_ExtPhyVoltStatusType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyVoltStatusType, 4UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyTempCapableType
    @{
    @brief Temperature capabilities type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint16_t ETHXCVR_ExtPhyTempCapableType;
#define ETHXCVR_EXTPHY_TEMP_CAPABLE_HIGH_THRESH1  (0x0001U)     /**< @brief VTOM capable for Temperature High threshold-1   */
#define ETHXCVR_EXTPHY_TEMP_CAPABLE_HIGH_THRESH2  (0x0002U)     /**< @brief VTOM capable for Temperature High threshold-2   */
#define ETHXCVR_EXTPHY_TEMP_CAPABLE_LOW_THRESH1   (0x0010U)     /**< @brief VTOM capable for Temperature Low threshold-1    */
#define ETHXCVR_EXTPHY_TEMP_CAPABLE_LOW_THRESH2   (0x0020U)     /**< @brief VTOM capable for Temperature Low threshold-2    */
/** @} */

/**
    @name ETHXCVR_ExtPhyVoltCapableType
    @{
    @brief Voltage capabilities type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint16_t ETHXCVR_ExtPhyVoltCapableType;
#define ETHXCVR_EXTPHY_VOLT_CAPABLE_HIGH_THRESH1  (0x0001U)     /**< @brief VTOM capable for Voltage High threshold-1   */
#define ETHXCVR_EXTPHY_VOLT_CAPABLE_HIGH_THRESH2  (0x0002U)     /**< @brief VTOM capable for Voltage High threshold-2   */
#define ETHXCVR_EXTPHY_VOLT_CAPABLE_LOW_THRESH1   (0x0010U)     /**< @brief VTOM capable for Voltage Low threshold-1    */
#define ETHXCVR_EXTPHY_VOLT_CAPABLE_LOW_THRESH2   (0x0020U)     /**< @brief VTOM capable for Voltage Low threshold-2    */
/** @} */


/**
    @name ETHXCVR_ExtPhyTempCapsType
    @{
    @brief Temperature Capabilties

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyTempCapsType {
    ETHXCVR_ExtPhyTempCapableType threshCapable;    /**< @brief Temp threshold Capable */
    ETHXCVR_ExtPhyTempCapableType eventCapable;     /**< @brief Temp Event Capable */
    ETHXCVR_ExtPhyTempCapableType faultCapable;     /**< @brief Temp Fault Capable */
    uint16_t                      reserved[1U];     /**< @brief reserved */
} ETHXCVR_ExtPhyTempCapsType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyTempCapsType, 8UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyVoltCapsType
    @{
    @brief Voltage Capabilties

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyVoltCapsType {
    ETHXCVR_ExtPhyVoltType        nominalValue;   /**< @brief Nominal voltage @xsd default:ETHXCVR_EXTPHY_VOLT_NONE */
    ETHXCVR_ExtPhyVoltCapableType threshCapable;  /**< @brief Volt threshold Capable */
    ETHXCVR_ExtPhyVoltCapableType eventCapable;   /**< @brief Volt Event Capable */
    ETHXCVR_ExtPhyVoltCapableType faultCapable;   /**< @brief Volt Fault Capable */
    uint16_t                      reserved[2U];   /**< @brief reserved */
} ETHXCVR_ExtPhyVoltCapsType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyVoltCapsType, 12UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyPhyCapableType
    @{
    @brief PHY capabilities type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint32_t ETHXCVR_ExtPhyPhyCapableType;
#define ETHXCVR_EXTPHY_PHY_CAPABLE_SPEED_10MBPS     (ETHXCVR_SPEED_10MBPS)    /**< @brief PHY capable for speed 10MBPS   */
#define ETHXCVR_EXTPHY_PHY_CAPABLE_SPEED_100MBPS    (ETHXCVR_SPEED_100MBPS)   /**< @brief PHY capable for speed 100MPBS  */
#define ETHXCVR_EXTPHY_PHY_CAPABLE_SPEED_1000MBPS   (ETHXCVR_SPEED_1000MBPS)  /**< @brief PHY capable for speed 1000MBPS */
#define ETHXCVR_EXTPHY_PHY_CAPABLE_SPEED_2500MBPS   (ETHXCVR_SPEED_2500MBPS)  /**< @brief PHY capable for speed 2500MPBS */
#define ETHXCVR_EXTPHY_PHY_CAPABLE_SPEED_5000MBPS   (ETHXCVR_SPEED_5000MBPS)  /**< @brief PHY capable for speed 5000MPBS */
#define ETHXCVR_EXTPHY_PHY_CAPABLE_SPEED_10GBPS     (ETHXCVR_SPEED_10000MBPS) /**< @brief PHY capable for speed 10GBPS   */
#define ETHXCVR_EXTPHY_PHY_CAPABLE_TC10             (0x1000UL)     /**< @brief PHY capable for speed TC10  */
#define ETHXCVR_EXTPHY_PHY_CAPABLE_EEE              (0x2000UL)     /**< @brief PHY capable for speed EEE  */
/** @} */

/**
    @name ETHXCVR_ExtPhySafetyCapsType
    @{
    @brief SAFETY capability querying of the PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhySafetyCapsType {
    ETHXCVR_ExtPhyTempCapsType     tempCaps;     /**< @brief Temparature Capable */
    ETHXCVR_ExtPhyVoltCapsType     voltCaps[6];  /**< @brief Voltage Capable */
    uint16_t                       reserved[2U]; /**< @brief reserved */
} ETHXCVR_ExtPhySafetyCapsType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhySafetyCapsType, 84UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyPhyCapsType
    @{
    @brief PHY capabilitiesquerying of the PHY

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyPhyCapsType {
    ETHXCVR_ExtPhySafetyCapsType   safetyCaps;      /**< @brief SAFETY Capable */
    ETHXCVR_ExtPhyPhyCapableType   phyCapable;     /**< @brief PHY Capable */
    uint16_t                       reserved[2U];   /**< @brief reserved */
} ETHXCVR_ExtPhyPhyCapsType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyPhyCapsType, 92UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyHealthInfoType
    @{
    @brief PHY health information structure

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyHealthInfoType {
    uint32_t                       linkStatusChangeCnt; /**< @brief link status change count */
    uint32_t                       sqi;                 /**< @brief link Signal quality index */
    int32_t                        currTemp;            /**< @brief current temperature in Celsius of the PHY */
    uint32_t                       currAVolt;           /**< @brief current analog voltage of the PHY */
    uint32_t                       currDVolt;           /**< @brief current digital voltage of the PHY */
    uint16_t                       voltage_0v8;         /**< @brief current voltage 0V8 in mv of the PHY */
    uint16_t                       voltage_1v0;         /**< @brief current voltage 1V0 in mv of the PHY */
    uint16_t                       voltage_1v8;         /**< @brief current voltage 1V8 in mv of the PHY */
    uint16_t                       voltage_2v5;         /**< @brief current voltage 2V5 in mv of the PHY */
    uint16_t                       voltage_3v3;         /**< @brief current voltage 3V3 in mv of the PHY */
    ETHXCVR_ExtPhyEventTempType    tempEvents;          /**< @brief temperature events */
    ETHXCVR_ExtPhyVoltStatusType   voltStatus[6UL];     /**< @brief Voltage status events */
    uint32_t                       rsvd[12UL];          /**< @brief reserved */
} ETHXCVR_ExtPhyHealthInfoType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyHealthInfoType, 104UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyConfigMsgType
    @{
    @brief PHY Config msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyConfigMsgType {
    ETHXCVR_IDType         port;                    /**< @brief Port number */
    uint8_t                reserved[3U];            /**< @brief reserved */
    ETHXCVR_PortConfigType config;                  /**< @brief Port configuration */
} ETHXCVR_ExtPhyConfigMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyConfigMsgType, 60UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyDeInitMsgType
    @{
    @brief PHY DeInit message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyDeInitMsgType {
    ETHXCVR_IDType  port;                           /**< @brief Port number */
    uint8_t         reserved[3U];                   /**< @brief reserved */
} ETHXCVR_ExtPhyDeInitMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyDeInitMsgType, 4UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_PHYSetModeMsgType
    @{
    @brief PHY set mode message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyModeMsgType {
    ETHXCVR_IDType   port;                           /**< @brief Port number */
    ETHXCVR_ModeType mode;                          /**< @brief xcvr mode */
    uint16_t         reserved;                      /**< @brief reserved */
} ETHXCVR_ExtPhyModeMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyModeMsgType, 4UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyModeV2MsgType
    @{
    @brief PHY Mode v2 message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyModeV2MsgType {
    uint64_t requestPortMask;       /**< @brief [input]  Mask of ports to be acted upon                                */
    uint32_t timeOutMs;             /**< @brief [input]  Timeout in milli seconds                                      */
    ETHXCVR_ModeType mode;          /**< @brief [input]  Mode of operation on the ports as requestPortMask             */
    uint8_t  rsvdIn[35UL];          /**< @brief [input]  Reserved fields                                               */

    uint64_t tc10EnabledPortMask;   /**< @brief [output] Mask of ports on which tc10 is enabled                        */
    uint64_t successPortMask;       /**< @brief [output] Mask of ports on which normal operation succeeded.
                                                         When mode of operation is ETHXCVR_MODE_DOWN and tc10 is enabled
                                                         on a particular port, this mask indicates that LPS handshake
                                                         through sleep operation was successful. Similarly for a
                                                         non-tc10 port, this mask indicates that the administrative mode
                                                         DOWN was successful.                                          */
    uint64_t forcedSuccessPortMask; /**< @brief [output] Mask of ports on which forced operation succeeded.
                                                         When mode of operation is ETHXCVR_MODE_DOWN and tc10 is enabled
                                                         on a particular port, this mask indicates that forceSleep
                                                         operation was successful                                      */
    uint64_t abortPortMask;         /**< @brief [output] Mask of ports where LPS handshake was aborted by link partner */
    uint64_t timedOutPortMask;      /**< @brief [output] Mask of ports which timed-out                                 */
    uint64_t failedPortMask;        /**< @brief [output] Mask of ports which failed for unknown reasons                */
    uint8_t  rsvdOut[32UL];         /**< @brief Reserved fields                                                        */
} ETHXCVR_ExtPhyModeV2MsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyModeV2MsgType, 128UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExPhyIDMsgType
    @{
    @brief PHY get PHY ID message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExPhyIDMsgType {
    ETHXCVR_IDType      port;                           /**< @brief Port number */
    uint8_t             reserved[3U];                   /**< @brief reserved */
    ETHXCVR_PhyIDType   phyID;                          /**< @brief PHY identifier */
} ETHXCVR_ExPhyIDMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExPhyIDMsgType, 20UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_CableDiagResultType
    @{
    @brief cable diagnostic result type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_CableDiagResultType {
    ETHXCVR_CableStatusType         cableStatus;   /**< @brief cable staus */
    uint32_t                        cableLen;      /**< @brief Estimated cable length in centimeters */
    uint32_t                        reserved[6UL]; /**< @brief reserved */
} ETHXCVR_CableDiagResultType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_CableDiagResultType, 32UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyCableDiagMsgType
    @{
    @brief cable diagnostic message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyCableDiagMsgType {
    ETHXCVR_IDType                  port;           /**< @brief Port number */
    ETHXCVR_BooleanType             start;          /**< @brief TRUE: Start cable diagnostic */
    uint8_t                         reserved[2U];   /**< @brief reserved */
    ETHXCVR_CableDiagResultType     result;         /**< @brief cable diag Result */
    uint32_t                        reserved2[7UL]; /**< @brief reserved */
} ETHXCVR_ExtPhyCableDiagMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyCableDiagMsgType, 64UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyLbMsgType
    @{
    @brief Loopback mode message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyLbMsgType {
    ETHXCVR_IDType                  port;          /**< @brief Port number */
    ETHXCVR_LoopbackModeType        lb;            /**< @brief loopback mode */
    uint16_t                        reserved;      /**< @brief reserved */
} ETHXCVR_ExtPhyLbMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyLbMsgType, 4UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyLinkStateMsgType
    @{
    @brief PHY link status msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyLinkStateMsgType {
    ETHXCVR_IDType                  port;          /**< @brief Port number */
    ETHXCVR_LinkStateType           status;        /**< @brief link status */
    uint16_t                        reserved;      /**< @brief reserved */
} ETHXCVR_ExtPhyLinkStateMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyLinkStateMsgType, 4UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyAutoNegMsgType
    @{
    @brief Auto-negotiation mode message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyAutoNegMsgType {
    ETHXCVR_IDType                  port;          /**< @brief Port number */
    ETHXCVR_ExtPhyAutoNegStatusType status;        /**< @brief auto-neg status */
    uint8_t                         reserved[2U];  /**< @brief reserved */
    uint32_t                        restart;       /**< @brief restart auto-neg */
} ETHXCVR_ExtPhyAutoNegMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyAutoNegMsgType, 16UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyRegRdWrMsgType
    @{
    @brief PHY register read/write message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyRegRdWrMsgType {
    ETHXCVR_IDType  port;                           /**< @brief port number */
    uint8_t         reserved[3U];                   /**< @brief reserved */
    uint32_t        addr;                           /**< @brief address to read/write from/to */
    uint32_t        data;                           /**< @brief data to read/write from/to */
} ETHXCVR_ExtPhyRegRdWrMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyRegRdWrMsgType, 12UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyHealthMsgType
    @{
    @brief Health msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyHealthMsgType {
    ETHXCVR_IDType               port;             /**< @brief port number   */
    uint8_t                      reserved[3U];     /**< @brief reserved */
    ETHXCVR_ExtPhyHealthInfoType health;           /**< @brief PHY health information */
} ETHXCVR_ExtPhyHealthMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyHealthMsgType, 108UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyFwVersionMsgType
    @{
    @brief PHY firmware version msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct COMP_PACKED sETHXCVR_ExtPhyFwVersionMsgType {
    ETHXCVR_IDType               port;                  /**< @brief port number   */
    uint8_t                      reserved[3U];          /**< @brief reserved */
    ETHXCVR_ExtPhyFwVersionType  version;               /**< @brief FW version */
} ETHXCVR_ExtPhyFwVersionMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyFwVersionMsgType, 148UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyFwMsgType
    @{
    @brief PHY firmware version msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyFwMsgType {
    ETHXCVR_IDType port;                                        /**< @brief port number   */
    uint8_t        reserved[3U];                                /**< @brief reserved */
    uint32_t       fwSize;                                      /**< @brief data size     */
    uint32_t       serverIp;                                    /**< @brief server IP address */
    uint8_t        fileName[ETHXCVR_EXTPHY_FILE_NAME_MAX_LEN];  /**< @brief file name */
} ETHXCVR_ExtPhyFwMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyFwMsgType, 140UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyEventsMsgType
    @{
    @brief PHY Events msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyEventsMsgType {                   /**< @brief ETHXCVR_ExtPhyEventsMsgType */
    ETHXCVR_IDType              port;                           /**< @brief port number   */
    uint8_t                     reserved[3U];                   /**< @brief reserved */
    ETHXCVR_ExtPhyEventsType    events;                         /**< @brief ETHXCVR_ExtPhyEvents */
} ETHXCVR_ExtPhyEventsMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyEventsMsgType, 8UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVR_ExtPhyEEEStatsMsgType
    @{
    @brief PHY EEE Stats msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyEEEStatsMsgType {                 /**< @brief ETHXCVR_ExtPhyEEEStatsMsgType */
    ETHXCVR_IDType              port;                           /**< @brief port number   */
    uint8_t                     reserved[3U];                   /**< @brief reserved */
    ETHXCVR_ExtPhyEEEStatsType  stats;                          /**< @brief ETHXCVR_ExtPhyEEEStatstype */
} ETHXCVR_ExtPhyEEEStatsMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyEEEStatsMsgType, 24UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
  @name Flash Manufacturer ID Type
  @{
  @brief Flash Manufacturer ID Type

  @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint8_t ETHXCVR_FlashManufacturerIDType;             /**< @brief typedef for flash manufacturer ID */
#define ETHXCVR_FLASH_MANUFACTURER_ID_INVALID     (0xFFU)    /**< @brief Invalid flash manufacturer ID     */
/** @} */

/**
  @name Flash Memory Type
  @{
  @brief Flash Memory Type

  @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint8_t ETHXCVR_FlashMemoryType;                    /**< @brief typedef for flash memory type */
#define ETHXCVR_FLASH_MEMORY_TYPE_INVALID         (0xFFU)   /**< @brief Invalid flash memory type     */
/** @} */

/**
  @name Flash Memory Density Type
  @{
  @brief Flash Memory Density Type

  @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint8_t ETHXCVR_FlashMemoryDensityType;             /**< @brief typedef for flash memory density type */
#define ETHXCVR_FLASH_MEMORY_DENSITY_INVALID      (0xFFU)   /**< @brief Invalid flash memory density          */
/** @} */

/**
  @name Flash Device ID Type
  @{
  @brief Flash Device ID Type

  @trace #BRCM_SWREQ_ETHXCVR
*/
typedef uint8_t ETHXCVR_FlashDeviceIDType;                  /**< @brief typedef for flash device ID type */
#define ETHXCVR_FLASH_DEVICE_ID_INVALID           (0xFFU)   /**< @brief Invalid flash device ID          */
/** @} */

/**
    @brief PHY Flash ID structure

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_FlashIDType {
    ETHXCVR_FlashManufacturerIDType manufacturerID;      /**< @brief Flash Manufacturer ID     */
    ETHXCVR_FlashMemoryType         memoryType;          /**< @brief Flash Memory Type         */
    ETHXCVR_FlashMemoryDensityType  memoryDensity;       /**< @brief Flash Memory Density      */
    ETHXCVR_FlashDeviceIDType       deviceID;            /**< @brief Flash Device ID           */
    uint32_t                        resv[8];             /**< @brief Reserved                  */
} ETHXCVR_FlashIDType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_FlashIDType, 36UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)

/**
    @brief PHY Flash ID message type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyFlashIDMsgType {           /**< @brief PHY Flash ID message type */
    ETHXCVR_IDType       port;                           /**< @brief Port number               */
    uint8_t              resv[3U];                       /**< @brief Reserved                  */
    ETHXCVR_FlashIDType  flashID;                        /**< @brief PHY Flash ID type         */
} ETHXCVR_ExtPhyFlashIDMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyFlashIDMsgType, 40UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)

/**
    @name ETHXCVR_ExtPhySafetyCfgMsgType
    @{
    @brief PHY SAFETY config msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhySafetyCfgMsgType {                 /**< @brief ETHXCVR_ExtPhySafetyCfgMsgType */
    ETHXCVR_IDType                port;                          /**< @brief port number   */
    uint8_t                       reserved[3U];                  /**< @brief reserved */
    ETHXCVR_ExtPhySafetyCfgType   safetyCfg;                     /**< @brief ETHXCVR_ExtPhySafetyCfgType */
    uint8_t                       rsvd[4U];                      /**< @brief reserved */
} ETHXCVR_ExtPhySafetyCfgMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhySafetyCfgMsgType, 200UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */


/**
    @name ETHXCVR_ExtPhySafetyCfgMsgType
    @{
    @brief PHY SAFETY config msg type

    @trace #BRCM_SWREQ_ETHXCVR
*/
typedef struct sETHXCVR_ExtPhyPhyCapsMsgType {           /**< @brief ETHXCVR_ExtPhySafetyPhyCapsMsgType */
    ETHXCVR_IDType                     port;                  /**< @brief port number   */
    uint8_t                            reserved[3U];          /**< @brief reserved */
    ETHXCVR_ExtPhyPhyCapsType          phyCaps;               /**< @brief PHY Capabilites */
    uint8_t                            rsvd[4U];              /**< @brief reserved */
} ETHXCVR_ExtPhyPhyCapsMsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyPhyCapsMsgType, 100UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @brief Transceiver Event Notification data

    Transceiver Link notification data type

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef struct sETHXCVR_ExtPhyNotifyEventType {
    ETHXCVR_ExtPhyEventsType       events;          /**< @brief ExtPhy events */
    ETHXCVR_IDType                 xcvrID;          /**< @brief Transceiver identifier */
    uint8_t                        rsvd[3U];        /**< @brief reserved               */
    uint32_t                       reserved[3UL];   /**< @brief reserved               */
} ETHXCVR_ExtPhyNotifyEventType;
BCM_STATIC_SIZE_ASSERT(ETHXCVR_ExtPhyNotifyEventType, 20UL, ETHXCVR_EXTPHY_MSG_MAX_SIZE)

/**
    @brief Transceiver Events Notification custom data union

    Transceiver Events notification custom data union

    @trace #BRCM_SWREQ_ETHXCVR
 */
typedef union uETHXCVR_ExtPhyNotifyEventUnionType {
    BCM_NotifyDataType            custData;                    /**< @brief custom data */
    ETHXCVR_ExtPhyNotifyEventType payload;                     /**< @brief ETHXCVR event notification custom data */
} ETHXCVR_ExtPhyNotifyEventUnionType;

/**
    @name ETHXCVRM_MsgUnionType
    @{
    @brief PHY message union encapsulating all the messages

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef union uETHXCVRM_MsgUnionType {
    uint32_t                       data[ETHXCVR_EXTPHY_MSG_MAX_SIZE / 4UL]; /**< @brief payload size  */
    ETHXCVR_ExtPhyConfigMsgType    init;                                    /**< @brief Init msg      */
    ETHXCVR_ExtPhyDeInitMsgType    deinit;                                  /**< @brief deinit msg    */
    ETHXCVR_ExtPhyModeMsgType      mode;                                    /**< @brief mode msg      */
    ETHXCVR_ExPhyIDMsgType         id;                                      /**< @brief phy id msg    */
    ETHXCVR_ExtPhyCableDiagMsgType diag;                                    /**< @brief cable diag msg */
    ETHXCVR_ExtPhyLbMsgType        lb;                                      /**< @brief loopback msg   */
    ETHXCVR_ExtPhyAutoNegMsgType   autoNeg;                                 /**< @brief auto-neg msg    */
    ETHXCVR_ExtPhyLinkStateMsgType link;                                    /**< @brief link state msg */
    ETHXCVR_ExtPhyRegRdWrMsgType   memRdWr;                                 /**< @brief mem rd/wr msg  */
    ETHXCVR_ExtPhyHealthMsgType    health;                                  /**< @brief status msg     */
    ETHXCVR_ExtPhyFwVersionMsgType fwVersion;                               /**< @brief PHY fw version msg */
    ETHXCVR_ExtPhyFwMsgType        fw;                                      /**< @brief fw execute/update msg */
    ETHXCVRM_TC10StatusType        tc10Status;                              /**< @brief TC10 status payload */
    ETHXCVRM_TC10FwdMapType        tc10FwdMap;                              /**< @brief TC10 forward Map get payload */
    ETHXCVRM_TC10PortType          tc10Port;                                /**< @brief port number */
    ETHXCVRM_TC10WakeUpType        tc10Wake;                                /**< @brief TC10 wake reason */
    ETHXCVRM_TC10AllowSleepRequestType tc10AllowSleep;                      /**< @brief TC10 Allow Sleep Request */
    ETHXCVRM_TC10AllowMdiWakeType   tc10AllowMdiWake;                        /**< @brief TC10 Allow Wup Request */
    MDIO_AccessType                mdioAccess;                              /**< @brief MDIO access Payload */
    ETHXCVR_TC10ConfigType         tc10OtpCfg;                              /**< @brief TC10 OTP Config */
    ETHXCVR_ExtPhyEEEStatsMsgType  eeeStats;                                /**< @brief EEE Stats */
    ETHXCVR_ExtPhyFlashIDMsgType   flashIDMsg;                              /**< @brief PHY Flash ID message */
    ETHXCVR_ExtPhyModeV2MsgType    modeV2;                                  /**< @brief Mode v2 Msg */
    ETHXCVR_ExtPhySafetyCfgMsgType safetyCfg;                                /**< @brief Set/Get SAFETY Config */
    ETHXCVR_ExtPhyEventsMsgType    getEvents;                               /**< @brief Get Events */
    ETHXCVR_ExtPhyPhyCapsMsgType   phyCaps;                                 /**< @brief PHY Capabilities */
} ETHXCVRM_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHXCVRM_MsgUnionType, ETHXCVR_EXTPHY_MSG_MAX_SIZE, ETHXCVR_EXTPHY_MSG_MAX_SIZE)
/** @} */

/**
    @name ETHXCVRM_MsgType
    @{
    @brief Command/Response structure

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef struct sETHXCVRM_MsgType {
    uint32_t     magic;                         /**< @brief Magic                     */
    BCM_MsgType  id;                            /**< @brief Command ID                */
    int32_t      status;                        /**< @brief Status                    */
    uint32_t     len;                           /**< @brief Length of the payload     */
    ETHXCVRM_MsgUnionType payload;              /**< @brief command/ response payload */
} ETHXCVRM_MsgType;
BCM_STATIC_SIZE_ASSERT(ETHXCVRM_MsgType, 432UL, 432UL)
/** @} */

/**
    @brief PHY Init

    Initialize PHY.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aID             Index of the PHY
    @param[in]      aConfig         Configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @retval     #BCM_ERR_NOSUPPORT           Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS        aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS        aCfg is NULL or invalid
    @retval     #BCM_ERR_INVAL_PARAMS        aID is invalid
    @retval     #BCM_ERR_INVAL_STATE         PHY already initialized
    @retval     #BCM_ERR_UNKNOWN             Integration error

    @post None

    @trace #BRCM_SWREQ_ETHXCVR

    @limitations None
*/
extern int32_t ETHXCVR_ExtPhyInit(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                  const ETHXCVR_PortConfigType *const aConfig);

/** @brief De-initialize PHY

    This API de-initializes the PHY driver.

    @behavior Sync, Re-entrant across PHYs

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @retval     #BCM_ERR_NOSUPPORT           Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS        aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS        aID is invalid
    @retval     #BCM_ERR_INVAL_STATE         PHY is in de-initialized state
    @retval     #BCM_ERR_UNKNOWN             Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyDeInit(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/** @brief Get PHY Configuration

    This API obtains the current configuration of the PHY.

    @behavior Sync, Re-entrant across PHYs

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[out]     aConfig     Pointer to configuration structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @retval     #BCM_ERR_NOSUPPORT           Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS        aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS        aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS        aConfig is NULL
    @retval     #BCM_ERR_INVAL_STATE         PHY is in de-initialized state
    @retval     #BCM_ERR_UNKNOWN             Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetConfig(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                       ETHXCVR_PortConfigType *const aConfig);

/** @brief Set mode for the PHY

    This API sets mode of the PHY. If aMode is #ETHXCVR_MODE_DOWN, transceiver is disabled
    (both RX/TX disabled). If aMode is #ETHXCVR_MODE_ACTIVE, PHY is enabled by the
    (both RX/TX active). if aMode is #ETHXCVR_MODE_ACTIVE_WAKEUP, PHY is enabled and wakeup
    request is triggered on the network.

    @behavior Sync, Re-entrant across PHYs

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[in]      aMode       Mode to be set

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is invalid
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_EAGAIN         PHY mode can not be set at this
                                        moment. Try again.
    @retval     #BCM_ERR_NOSUPPORT      No Support for the PHY mode
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhySetMode(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                     ETHXCVR_ModeType aMode);

/** @brief Get current mode of the PHY

    This API gets mode of the PHY (PHY). If the PHY is active, aMode
    will be set to #ETHXCVR_MODE_ACTIVE else aMode will be set to
    #ETHXCVR_MODE_DOWN. If the PHY is active with wakeup request,
    it will set aMode to #ETHXCVR_MODE_ACTIVE.

    @behavior Sync, Re-entrant across PHYs

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[out]     aMode       Pointer to Mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is NULL
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetMode(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                     ETHXCVR_ModeType *const aMode);

/** @brief Get PHY (hardware) identifier

    This API obtains the hardware identifier.

    @behavior Sync, Re-entrant across PHYs

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[out]     aPhyID      PHY identifier

    @retval     #BCM_ERR_OK             successful
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aPhyID is NULL
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetID(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                   ETHXCVR_PhyIDType *const aPhyID);

/** @brief Run cable diagnostics

    Start cable diagnostics and obtain the result in aResult.

    @behavior Sync, Re-entrant across PHYs

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[out]     aResult     Cable diagnostic result

    @retval     #BCM_ERR_OK             success (aResult is valid).
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_INVAL_STATE    PHY is not in active state
    @retval     #BCM_ERR_BUSY           Cable diagnostic is running
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyRunCableDiag(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                          ETHXCVR_CableDiagResultType *const aCableDiagResult);

/**
    @brief Set Loopback mode

    This API sets the given loopback mode in the PHY.
    Setting loopback mode to #ETHXCVR_LOOPBACK_MODE_NONE will bring-back
    the PHY in normal mode.

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[in]      aMode       Loopback mode type

    @retval     #BCM_ERR_OK             success.
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Given loopback mode is not supported
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations Setting loopback mode while PHY is active, may disrupt the traffic.

    @trace #BRCM_SWREQ_ETHXCVR
 */
extern int32_t ETHXCVR_ExtPhySetLoopbackMode(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                             ETHXCVR_LoopbackModeType aMode);

/**
    @brief Get Loopback mode

    This API obtains the loopback mode of the PHY.

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[out]     aMode       Pointer to loopback mode

    @retval     #BCM_ERR_OK             success.
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is NULL
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
 */
extern int32_t ETHXCVR_ExtPhyGetLoopbackMode(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                             ETHXCVR_LoopbackModeType *aMode);
/**
    @brief Restart Auto-negotiation

    This API restarts the auto-negotiation of the transmission parameters (passed during
    Initialization).

    User can check the status of the auto-negotiation process by calling
    #ETHXCVR_ExtPhyGetAutoNegStatus.

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY

    @retval     #BCM_ERR_OK             success.
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      auto-neg is not supported
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None.

    @trace #BRCM_SWREQ_ETHXCVR
 */
extern int32_t ETHXCVR_ExtPhyReStartAutoNeg(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/**
    @brief Get link status

    This API retvals the current state of the link.

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[out]     aState      Pointer to Link state

    @retval     #BCM_ERR_OK             success.
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None.

    @trace #BRCM_SWREQ_ETHXCVR
 */
extern int32_t ETHXCVR_ExtPhyGetLinkState(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                          ETHXCVR_LinkStateType *const aState);
/**
    @brief Get auto-neg status

    This API obtains the auto-negotiation status of the PHY.

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[out]     aStatus     Pointer to auto-neg status structure

    @retval     #BCM_ERR_OK             success.
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None.

    @trace #BRCM_SWREQ_ETHXCVR
 */
extern int32_t ETHXCVR_ExtPhyGetAutoNegStatus(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                              ETHXCVR_ExtPhyAutoNegStatusType *const aStatus);

/** @brief Reads a PHY register/memory

    This API reads the content of the register/memory of PHY.

    If the PHY is connected on MDIO bus, aAddr packs the register and device information in
    following manner:
    aAddr[15:0] : 5-bits of the CL22 register address or 16-bits of CL45 register address
    aAddr[20:16]: 5-bits of the dev address for CL45 or reserved for CL22 mode.
    aAddr[31:21]: reserved for future use.

    if the PHY is connected on MDIO bus, aData is packed in following manner:
    aData[15:0] : 16-bit of data read from the PHY
    aData[31:16] : Reserved for future use.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY.
    @param[in]      aAddr       Memory address to be read.
    @param[out]     aData       Pointer to the data.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             read successfully
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid PHY ID
    @retval     #BCM_ERR_INVAL_PARAMS   aData is NULL
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NODEV          Bus error while reading from PHY
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyRegRead(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                     uint32_t aAddr, uint32_t *const aData);

/** @brief Writes to a PHY register

    This API writes the content to register/memory of PHY

    If the PHY is connected on MDIO bus, aAddr packs the register and device information in
    following manner:
    aAddr[15:0] : 5-bits of the CL22 register address or 16-bits of CL45 register address
    aAddr[20:16]: 5-bits of the dev address for CL45 or reserved for CL22 mode.
    aAddr[31:21]: reserved for future use.

    if the PHY is connected on MDIO bus, aData is packed in following manner:
    aData[15:0] : 16-bit of data to write to PHY
    aData[31:16] : Reserved for future use.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY.
    @param[in]      aAddr       Memory address to write.
    @param[in]      aData       value to be written.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Memory was written successfully
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid PHY ID
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NODEV          Bus error while reading from PHY
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyRegWrite(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                      uint32_t aAddr, uint32_t aData);

/** @brief Get the health information of PHY.

    This API obtains health information of the PHY.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY.
    @param[out]     aInfo       Pointer to health information structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             success
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aInfo is NULL
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetHealthInfo(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                           ETHXCVR_ExtPhyHealthInfoType *const aInfo);

/** @brief Get the firmware version running on PHY

    This API obtains firmware version running on the PHY (if PHY supports).

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY.
    @param[out]     aVersion    Pointer to version structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             success
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Not supported by PHY.
    @retval     #BCM_ERR_UNKNOWN        Integration error.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetFwVersion(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                          ETHXCVR_ExtPhyFwVersionType *const aVersion);

/** @brief Execute given firmware on PHY

    This API downloads the given firmware to PHY and executes it.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[in]      aFw         Pointer to firmware binary
    @param[in]      aFwSz       Size of the firmware binary

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             success
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid PHY ID
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Not supported by PHY
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyExecuteFw(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                          const uint8_t *const aFw, uint32_t aFwSz);

/** @brief Fetch firmware over network and execute it

    This API fetches the firmware over the network (over TFTP), downloads it to the PHY
    executes it.

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY
    @param[in]      aServerIp   IP Address of the TFTP server
    @param[in]      aFileName   File name of the firmware binary
    @param[in]      aLen        Length of the file name

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             success
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aServerIp is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aFileName is NULL
    @retval     #BCM_ERR_INVAL_PARAMS   aLen > #ETHXCVR_EXTPHY_FILE_NAME_MAX_LEN
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Not supported by PHY
    @retval     #BCM_ERR_TIME_OUT       Timeout while fetching fw from remote server
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyExecuteFwNet(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                          uint32_t aServerIp, const uint8_t *const aFileName,
                                          uint32_t aLen);

/** @brief Update the firmware on PHY

    This API updates the firmware on the PHY (if PHY supports NVM firmware update).

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY.
    @param[in]      aFw         Pointer to firmware binary to be updated on PHY NVM.
    @param[in]      aFwSz       Size of the firmware binary.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             success
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aFw is NULL
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Not supported by PHY.
    @retval     #BCM_ERR_NOMEM          Size too large
    @retval     #BCM_ERR_UNKNOWN        Integration error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyUpdateFw(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                      const uint8_t *const aFW, uint32_t aFwSz);

/** @brief Fetch firmware over network and updates it.

    This API fetches the firmware over network (over TFTP) and
    updates (if PHY supports NVM firmware update).

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Index of the PHY.
    @param[in]      aServerIp   IP Address of the TFTP server.
    @param[in]      aFileName   File name of the firmware binary
    @param[in]      aLen        Length of the file name

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             success
    @retval     #BCM_ERR_NOSUPPORT      Not Supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aServerIp is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aFileName is NULL
    @retval     #BCM_ERR_INVAL_PARAMS   aLen > #ETHXCVR_EXTPHY_FILE_NAME_MAX_LEN
    @retval     #BCM_ERR_UNINIT         PHY driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Not supported by PHY.
    @retval     #BCM_ERR_TIME_OUT       Timeout while fetching fw from remote server
    @retval     #BCM_ERR_UNKNOWN        Integration error.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyUpdateFwNet(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                        uint32_t aServerIp, const uint8_t *const aFileName,
                                        uint32_t aLen);
/** @brief PHY Get Events

    This API reads and provide PHY event status

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID             Index of the transceiver
    @param[out]     aEvents         Pointer to read Events

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully Get WakeUp Reason
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      If there is No WakeUp Mode Support
    @retval     #BCM_ERR_INVAL_STATE    Wakeup Mode Disabled
    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetEvents(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                       ETHXCVR_ExtPhyEventsType *const aEvents);

/** @brief TC10 Get Status

    This API retrieves tc10 status

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[out]     aStats              Pointer to read TC10 Stats
    @param[out]     aStatus             Pointer to read TC10 Status


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved TC10 status
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      If there is No WakeUp Mode Support
    @retval     #BCM_ERR_INVAL_STATE    Wakeup Mode Disabled
    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10GetStatus(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                           ETHXCVR_StatsType *const aStats,
                                           ETHXCVR_StatusType *const aStatus);

/** @brief TC10 Get Wakeup Mode

    This API retrieves the last wake-up mode

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[out]     aMode               Pointer to retrieve wake-up mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved WakeUp mode
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Unsupported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10GetWakeUpMode(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                               ETHXCVR_BooleanType *const aMode);

/** @brief TC10 Get Wakeup Reason

    This API retrieves the last wake-up reason

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[out]     aReason             Pointer to retrieve wake-up reason

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved WakeUp Reason
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Unsupported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10GetWakeUpReason(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                                 ETHXCVR_WakeupReasonType *const aReason);

/** @brief TC10 Wakeup Req

    This API requests a TC10 wake-up

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully requested a TC10 wake-up
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Unsupported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10WakeUpReq(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/** @brief TC10 Sleep Request

    This API requests a TC10 sleep and implicitly enables accepting further
    sleep requests from link partner

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully requested a TC10 sleep
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Unsupported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10SleepReq(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/** @brief TC10 Force Sleep Req

    This API forces a TC10 sleep and implicitly enables accepting further
    sleep requests from link partner

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully forced the phy into TC10 sleep state
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Unsupported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10ForceSleepReq(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/** @brief TC10 Sleep Abort Req

    This API aborts an ongoing TC10 sleep handshake

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully aborted an ongoing sleep handshake
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Unsupported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10SleepAbortReq(BCM_HandleType aConnHdl, ETHXCVR_IDType aID);

/** @brief Allow Sleep request

    Sleep requests from remote partner will be aborted by default during boot-up.
    This API enables/disables accepting sleep requests from remote.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[in]     aMode        Boolean to indicate if sleep requests have to be allowed or not

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Completed successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
                                       OR TC10 state machine is not in awaken state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10AllowSleepReq(BCM_HandleType aConnHdl,
                                               ETHXCVR_IDType aID,
                                               ETHXCVR_BooleanType aMode);

/** @brief Allow wakeup through MDI

    This API enables/disables wakeup of phy wake requests from link partner.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aID          Index of the transceiver
    @param[in]     aMode        TRUE = Enable wakeup on WUP, FALSE = Disable wakeup on WUP

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Completed successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
                                       OR TC10 state machine is not in awaken state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyTC10AllowMdiWake(BCM_HandleType aConnHdl,
                                              ETHXCVR_IDType aID,
                                              ETHXCVR_BooleanType aMode);

/** @brief Get Time Stamp Information

    This API reads and provide 1588 time stamp

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[out]     aTSInfo             Pointer to read Time Stamp Info

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully Get WakeUp Reason
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      If there is No WakeUp Mode Support
    @retval     #BCM_ERR_INVAL_STATE    Wakeup Mode Disabled
    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetTimeStamp(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                          ETHXCVR_ExtPhyTimeStampInfoType *const aTSInfo);

/** @brief Get EEE Stats

    This API reads and provide EEE stats

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[in]      readOnClear         Read on Clear the EEE Stats
    @param[out]     aStats              Pointer to read EEE stats

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully Get WakeUp Reason
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      If there is No WakeUp Mode Support
    @retval     #BCM_ERR_INVAL_STATE    Wakeup Mode Disabled
    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetEEEStats(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                         ETHXCVR_BooleanType readOnClear,
                                         ETHXCVR_ExtPhyEEEStatsType *const aStats);

/** @brief Get Flash ID

    This API reads flash ID from the flash of PHY

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[out]     aFlashID            Pointer to flash ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully Got Flash ID
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aFlashID is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      If there is No Flash Support

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR
*/
extern int32_t ETHXCVR_ExtPhyGetFlashID(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                        ETHXCVR_FlashIDType *const aFlashID);

/** @brief Gets the Phy capabilities

    This API Gets the Phy capabilities for event, fault and for mointoring

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[out]     aPhyCaps            Pointer to get PHY capabilities

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aPhyCaps is NULL

    @post TBD

    @trace #BRCM_SWREQ_ETHXCVR

    @limitations None
*/
extern int32_t ETHXCVR_ExtPhyGetPhyCaps(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                        ETHXCVR_ExtPhyPhyCapsType *const aPhyCaps);

/** @brief Sets the Low/High threshold temperature and voltage

    This API sets the high threshold value for temperature and voltage.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[in]      aSafetyCfg           Pointer to set SAFETY configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aSafetyCfg is NULL
    @retval     #BCM_ERR_BUSY           If power up delay is not over

    @post TBD

    @trace #BRCM_SWREQ_ETHXCVR

    @limitations None
*/
extern int32_t ETHXCVR_ExtPhySetSafetyCfg(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                         const ETHXCVR_ExtPhySafetyCfgType *const aSafetyCfg);

/** @brief Gets the Low/High threshold temperature and voltage

    This API gets the high threshold value for temperature and voltage.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect or MDIO_Open)
    @param[in]      aID                 Index of the transceiver
    @param[out]     aSafetyCfg           Pointer to get SAFETY configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aSafetyCfg is NULL
    @retval     #BCM_ERR_BUSY           If power up delay is not over

    @post TBD

    @trace #BRCM_SWREQ_ETHXCVR

    @limitations None
*/
extern int32_t ETHXCVR_ExtPhyGetSafetyCfg(BCM_HandleType aConnHdl, ETHXCVR_IDType aID,
                                         ETHXCVR_ExtPhySafetyCfgType *const aSafetyCfg);

#endif /* XCVR_EXTPHY_H */
/** @} */
