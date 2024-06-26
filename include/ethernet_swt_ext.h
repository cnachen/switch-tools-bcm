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
    @defgroup grp_ethernet_swt_ext_ifc Switch EXT abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_ext_ifc
    @{

    @file ethernet_swt_ext.h

    @brief EXT Interface
    This file contains the interfaces for the switch abstract for EXT

    @version 1.0 Initial version
*/

#ifndef ETHERNET_SWT_EXT_H
#define ETHERNET_SWT_EXT_H

#include <bcm_utils.h>
#include <module_msg.h>
#include <ethernet_swt_common.h>
#include <ethernet_swt_vlan.h>
#include <ethernet_xcvr_common.h>
#include <ethernet_swt_core.h>
#include <ethernet_swt_debug.h>
#include <ethernet_pae_types.h>
#include <crypto_secy_types.h>

/**
    @name EXT API IDs
    @{
    @brief API IDs for EXT
*/
#define BRCM_SWARCH_ETHSWT_EXTCMDID_TYPE                    (0x8201U)    /**< @brief #ETHSWT_ExtCmdIdType                 */
#define BRCM_SWARCH_ETHSWT_EXTPORTINFO_TYPE                 (0x8202U)    /**< @brief #ETHSWT_ExtPortInfoType              */
#define BRCM_SWARCH_ETHSWT_EXTSWITCHINFO_TYPE               (0x8203U)    /**< @brief #ETHSWT_ExtSwitchInfoType            */
#define BRCM_SWARCH_ETHSWT_EXTTC10WAKEUP_TYPE               (0x8204U)    /**< @brief #ETHSWT_ExtTc10WakeUpType            */
#define BRCM_SWARCH_ETHSWT_EXTTOTALMACLEARNINGLIMIT_TYPE    (0x8205U)    /**< @brief #ETHSWT_ExtTotalMACLearningLimitType */
#define BRCM_SWARCH_ETHSWT_EXTSTICKYMAC_TYPE                (0x8206U)    /**< @brief #ETHSWT_ExtStickyMACType             */
#define BRCM_SWARCH_ETHSWT_EXTPORTADDRESSLIMIT_TYPE         (0x8207U)    /**< @brief #ETHSWT_ExtPortAddressLimitType      */
#define BRCM_SWARCH_ETHSWT_EXTSTATIONMOVEMENT_TYPE          (0x8208U)    /**< @brief #ETHSWT_ExtStationMovementType       */
#define BRCM_SWARCH_ETHSWT_EXTPORTLINKINFO_TYPE             (0x8209U)    /**< @brief #ETHSWT_ExtPortLinkInfoType          */
#define BRCM_SWARCH_ETHSWT_EXTASYNCEVENT_TYPE               (0x820AU)    /**< @brief #ETHSWT_ExtAsyncEventType            */
#define BRCM_SWARCH_ETHSWT_EXT_MAX_PAYLOAD_SIZE_MACRO       (0x820BU)    /**< @brief #ETHSWT_EXT_MAX_PAYLOAD_SIZE         */
#define BRCM_SWARCH_ETHSWT_EXTMSGUNION_TYPE                 (0x820CU)    /**< @brief #ETHSWT_ExtMsgUnionType              */
#define BRCM_SWARCH_ETHSWT_EXT_ID_OF_MACRO                  (0x820DU)    /**< @brief #ETHSWT_EXT_ID_OF                    */
#define BRCM_SWARCH_ETHSWT_PORT_FIFO_MAX_MACRO              (0x820EU)    /**< @brief #ETHSWT_PORT_FIFO_MAX                */
#define BRCM_SWARCH_ETHSWT_SCHED_ALGO_TYPE                  (0x820FU)    /**< @brief #ETHSWT_SchedAlgoType                */
#define BRCM_SWARCH_ETHSWT_PORT_SCH_TYPE                    (0x8210U)    /**< @brief #ETHSWT_PortSchType                  */
#define BRCM_SWARCH_ETHSWT_PORT_SHAPER_CFG_TYPE             (0x8211U)    /**< @brief #ETHSWT_ShaperCfgType                */
#define BRCM_SWARCH_ETHSWT_FIFO_CFG_TYPE                    (0x8212U)    /**< @brief #ETHSWT_FifoCfgType                  */
#define BRCM_SWARCH_ETHSWT_PORT_RATE_POLICER_TYPE           (0x8213U)    /**< @brief #ETHSWT_PortPolicerActType           */
#define BRCM_SWARCH_ETHSWT_PACKET_TYPE                      (0x8214U)    /**< @brief #ETHSWT_PolicerPacketFlgMaskType     */
#define BRCM_SWARCH_ETHSWT_PORT_POLICER_CFG_TYPE            (0x8215U)    /**< @brief #ETHSWT_PortPolicerCfgType           */
#define BRCM_SWARCH_ETHSWT_PORT_MAC_ENTRY_MAX_MACRO         (0x8216U)    /**< @brief #ETHSWT_PORT_MAC_ENTRY_MAX           */
#define BRCM_SWARCH_ETHSWT_PORT_VLAN_ENTRY_MAX_MACRO        (0x8217U)    /**< @brief #ETHSWT_PORT_VLAN_ENTRY_MAX          */
#define BRCM_SWARCH_ETHSWT_PORT_INGRESS_CFG_TYPE            (0x8218U)    /**< @brief #ETHSWT_PortIngressCfgType           */
#define BRCM_SWARCH_ETHSWT_PORT_EGRESS_CFG_TYPE             (0x8219U)    /**< @brief #ETHSWT_PortEgressCfgType            */
#define BRCM_SWARCH_ETHSWT_PORT_CFG_TYPE                    (0x821AU)    /**< @brief #ETHSWT_PortCfgType                  */
#define BRCM_SWARCH_ETHSWT_PORT_SECURITY_CFG_TYPE           (0x821BU)    /**< @brief #ETHSWT_PortSecurityCfgType          */
#define BRCM_SWARCH_ETHSWT_GLOBAL_SECURITY_CFG_TYPE         (0x821CU)    /**< @brief #ETHSWT_GlobalSecurityCfgType        */
#define BRCM_SWARCH_ETHSWT_XCVR_GETPORTINFO_PROC            (0x821DU)    /**< @brief #ETHSWT_XCVRGetPortInfo              */
#define BRCM_SWARCH_ETHSWT_XCVR_SETPORTADMINMODE_PROC       (0x821EU)    /**< @brief #ETHSWT_XCVRSetPortAdminmode         */
#define BRCM_SWARCH_ETHSWT_XCVR_GETPORTADMINMODE_PROC       (0x821FU)    /**< @brief #ETHSWT_XCVRGetPortAdminmode         */
#define BRCM_SWARCH_ETHSWT_XCVR_SETPORTMASTERSLAVE_PROC     (0x8220U)    /**< @brief #ETHSWT_XCVRSetPortMasterSlave       */
#define BRCM_SWARCH_ETHSWT_XCVR_GETPORTMASTERSLAVE_PROC     (0x8221U)    /**< @brief #ETHSWT_XCVRGetPortMasterSlave       */
#define BRCM_SWARCH_ETHSWT_XCVR_GETPORTSPEED_PROC           (0x8222U)    /**< @brief #ETHSWT_XCVRGetPortSpeed             */
#define BRCM_SWARCH_ETHSWT_XCVR_SETPORTPHYLB_PROC           (0x8223U)    /**< @brief #ETHSWT_XCVRSetPortPhyLb             */
#define BRCM_SWARCH_ETHSWT_XCVR_GETPORTPHYLB_PROC           (0x8224U)    /**< @brief #ETHSWT_XCVRGetPortPhyLb             */
#define BRCM_SWARCH_ETHSWT_XCVR_SETPORTJUMBOFRAME_PROC      (0x8225U)    /**< @brief #ETHSWT_XCVRSetPortJumboFrame        */
#define BRCM_SWARCH_ETHSWT_XCVR_GETPORTJUMBOFRAME_PROC      (0x8226U)    /**< @brief #ETHSWT_XCVRGetPortJumboFrame        */
#define BRCM_SWARCH_ETHSWT_XCVR_SETPVID_PROC                (0x8227U)    /**< @brief #ETHSWT_XCVRSetPvid                  */
#define BRCM_SWARCH_ETHSWT_XCVR_GETPORTLINKSQI_PROC         (0x8228U)    /**< @brief #ETHSWT_XCVRGetPortLinkSqi           */
#define BRCM_SWARCH_ETHSWT_XCVR_GETPORTLINKSQIALL_PROC      (0x8229U)    /**< @brief #ETHSWT_XCVRGetPortLinkSqiAll        */
#define BRCM_SWARCH_ETHSWT_XCVR_GETTC10WAKEUPMODE_PROC      (0x822AU)    /**< @brief #ETHSWT_XCVRGetTc10WakeupMode        */
#define BRCM_SWARCH_ETHSWT_XCVR_GETTC10WAKEUPREASON_PROC    (0x822BU)    /**< @brief #ETHSWT_XCVRGetTc10WakeupReason      */
#define BRCM_SWARCH_ETHSWT_EXT_SETVLANHOPDETECT_PROC        (0x822CU)    /**< @brief #ETHSWT_ExtSetVlanHopDetect          */
#define BRCM_SWARCH_ETHSWT_EXT_GETVLANHOPDETECT_PROC        (0x822DU)    /**< @brief #ETHSWT_ExtGetVlanHopDetect          */
#define BRCM_SWARCH_ETHSWT_EXT_SETARLPORTLIMIT_PROC         (0x822EU)    /**< @brief #ETHSWT_ExtSetArlPortLimit           */
#define BRCM_SWARCH_ETHSWT_EXT_GETARLPORTLIMIT_PROC         (0x822FU)    /**< @brief #ETHSWT_ExtGetArlPortLimit           */
#define BRCM_SWARCH_ETHSWT_EXT_SETARLSTICKY_PROC            (0x8230U)    /**< @brief #ETHSWT_ExtSetArlSticky              */
#define BRCM_SWARCH_ETHSWT_EXT_GETARLSTICKY_PROC            (0x8231U)    /**< @brief #ETHSWT_ExtGetArlSticky              */
#define BRCM_SWARCH_ETHSWT_EXT_SETARLMOVEDETECT_PROC        (0x8232U)    /**< @brief #ETHSWT_ExtSetArlMoveDetect          */
#define BRCM_SWARCH_ETHSWT_EXT_GETARLMOVEDETECT_PROC        (0x8233U)    /**< @brief #ETHSWT_ExtGetArlMovedetect          */
#define BRCM_SWARCH_ETHSWT_EXT_SETARLTOTALLIMIT_PROC        (0x8234U)    /**< @brief #ETHSWT_ExtSetArlTotalLimit          */
#define BRCM_SWARCH_ETHSWT_EXT_GETARLTOTALLIMIT_PROC        (0x8235U)    /**< @brief #ETHSWT_ExtGetArlTotalLimit          */
#define BRCM_SWARCH_ETHSWT_EXT_PORTCONFIG_TYPE              (0x8236U)    /**< @brief #ETHSWT_ExtPortConfigType            */
#define BRCM_SWARCH_ETHSWT_EXT_EAP_BLOCKING_MODE_TYPE       (0x8237U)    /**< @brief #ETHSWT_ExtEAPBlockingModeType       */
#define BRCM_SWARCH_ETHSWT_EXT_EAP_MODE_MSG_TYPE            (0x8238U)    /**< @brief #ETHSWT_ExtEAPModeMsgType            */
#define BRCM_SWARCH_ETHSWT_EXT_EAP_STATUS_MSG_TYPE          (0x8239U)    /**< @brief #ETHSWT_ExtEAPStatusMsgType          */
#define BRCM_SWARCH_ETHSWT_EXT_UPDATE_DLF_PORT_MAP_TYPE     (0x823AU)    /**< @brief #ETHSWT_ExtUpdateDlfPortMapType      */
#define BRCM_SWARCH_ETHSWT_EXT_GETDLFPORTMAP_PROC           (0x823BU)    /**< @brief #ETHSWT_ExtGetDlfPortMap             */
#define BRCM_SWARCH_ETHSWT_EXT_ADDDLFUCASTPORTMAP_PROC      (0x823CU)    /**< @brief #ETHSWT_ExtAddDlfUcastPortMap        */
#define BRCM_SWARCH_ETHSWT_EXT_ADDDLFMCASTPORTMAP_PROC      (0x823DU)    /**< @brief #ETHSWT_ExtAddDlfMcastPortMap        */
#define BRCM_SWARCH_ETHSWT_EXT_REMOVEDLFUCASTPORTMAP_PROC   (0x823EU)    /**< @brief #ETHSWT_ExtRemoveDlfUcastPortMap     */
#define BRCM_SWARCH_ETHSWT_EXT_REMOVEDLFMCASTPORTMAP_PROC   (0x823FU)    /**< @brief #ETHSWT_ExtRemoveDlfMcastPortMap     */
#define BRCM_SWARCH_ETHSWT_EXT_SETEAPMODE_PROC              (0x8240U)    /**< @brief #ETHSWT_ExtSetEAPMode                */
#define BRCM_SWARCH_ETHSWT_EXT_GETEAP_STATUS_PROC           (0x8241U)    /**< @brief #ETHSWT_ExtGetEAPStatus              */
#define BRCM_SWARCH_ETHSWT_EXT_PORT_TX_EN_MSG_TYPE          (0x8242U)    /**< @brief #ETHSWT_ExtPortEnableMsgType         */
#define BRCM_SWARCH_ETHSWT_EXTPORTINFO_V2_TYPE              (0x8243U)    /**< @brief #ETHSWT_ExtPortInfoV2Type            */
#define BRCM_SWARCH_ETHSWT_PORT_CAPABILITY_TYPE             (0x8244U)    /**< @brief #ETHSWT_PortCapabilityType           */
/** @} */

/**
    @brief Macro to Construct Ethernet switch Ext Commands

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_EXT_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_SWT_ID, aId)

/**
    @name Switch Ext command IDs
    @{
    @brief Switch Ext command IDs group

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_ExtCmdIdType;                        /**< @brief EXT command message Type                                                */
#define ETHSWT_EXTCMDID_PORT_INFO_GET              ETHSWT_EXT_ID_OF(0xB0U)  /**< @brief #ETHSWT_ExtPortInfoType              #ETHSWT_GetPortType
                                                                                                             #ETHSWT_GetPortMode
                                                                                                             #ETHSWT_GetPortLinkState
                                                                                                             #ETHSWT_GetPortSpeed
                                                                                                             #ETHSWT_GetPortMasterMode
                                                                                                             #ETHSWT_GetSQIValue
                                                                                                             #ETHSWT_GetPortJumboMode
                                                                                                             #ETHSWT_GetPortLoopbackMode
                                                                                                             #ETHXCVR_GetPortConfig
                                                                                                             #ETHSWT_GetPortAutoNegStatus
                                                                                                             #ETHSWT_GetPortDuplexMode
                                                                                                             #ETHSWT_GetLedState
                                                                                                             #ETHSWT_GetXcvrStats
                                                                                                             #ETHSWT_GetPortDefaultVlan          */
#define ETHSWT_EXTCMDID_PORT_INFO_SET              ETHSWT_EXT_ID_OF(0xB1U)  /**< @brief #ETHSWT_ExtPortInfoType              #ETHSWT_SetPortMode
                                                                                                             #ETHSWT_SetPortSpeed
                                                                                                             #ETHSWT_SetPortMasterMode
                                                                                                             #ETHSWT_SetPortJumboMode
                                                                                                             #ETHSWT_SetPortLoopbackMode
                                                                                                             #ETHSWT_SetPortDefaultVlan          */
#define ETHSWT_EXTCMDID_SWITCH_INFO_GET            ETHSWT_EXT_ID_OF(0xB2U)  /**< @brief #ETHSWT_ExtSwitchInfoType            #ETHSWT_GetAge
                                                                                                             #ETHSWT_GetDumbFwdMode
                                                                                                             #ETHSWT_GetMgmtMode
                                                                                                             #ETHSWT_GetBrcmHdrMode
                                                                                                             #ETHSWT_GetVLANIngressFilterMode    */
#define ETHSWT_EXTCMDID_SWITCH_INFO_SET            ETHSWT_EXT_ID_OF(0xB3U)  /**< @brief #ETHSWT_ExtSwitchInfoType            #ETHSWT_SetAge
                                                                                                             #ETHSWT_SetMgmtMode
                                                                                                             #ETHSWT_SetBrcmHdrMode
                                                                                                             #ETHSWT_SetDumbFwdMode
                                                                                                             #ETHSWT_SetVLANIngressFilterMode    */
#define ETHSWT_EXTCMDID_VLAN_HOPPING_DETECTION_SET      ETHSWT_EXT_ID_OF(0xB4U)  /**< @brief #ETHSWT_SecurityActionType               #ETHSWT_SetVlanHoppingDetection     */
#define ETHSWT_EXTCMDID_VLAN_HOPPING_DETECTION_GET      ETHSWT_EXT_ID_OF(0xB5U)  /**< @brief #ETHSWT_ExtTotalMACLearningLimitType     #ETHSWT_GetTotalAddrLimitAndCounter */
#define ETHSWT_EXTCMDID_STATION_MOVE_DETECT_SET         ETHSWT_EXT_ID_OF(0xB6U)  /**< @brief #ETHSWT_ExtStationMovementType           #ETHSWT_SetStationMovementDetection */
#define ETHSWT_EXTCMDID_STATION_MOVE_DETECT_GET         ETHSWT_EXT_ID_OF(0xB7U)  /**< @brief #ETHSWT_ExtStationMovementType           #ETHSWT_GetStationMovementDetection */
#define ETHSWT_EXTCMDID_PORT_ADDRESS_LIMITING_SET       ETHSWT_EXT_ID_OF(0xB8U)  /**< @brief #ETHSWT_ExtPortAddressLimitType          #ETHSWT_SetPortAddrLimiting         */
#define ETHSWT_EXTCMDID_PORT_ADDRESS_LIMITING_GET       ETHSWT_EXT_ID_OF(0xB9U)  /**< @brief #ETHSWT_ExtPortAddressLimitType          #ETHSWT_GetPortAddrLimitAndCounter  */
#define ETHSWT_EXTCMDID_TOTAL_ADDRESS_LIMIT_SET         ETHSWT_EXT_ID_OF(0xBAU)  /**< @brief #ETHSWT_ExtTotalMACLearningLimitType     #ETHSWT_SetTotalAddrLimit           */
#define ETHSWT_EXTCMDID_TOTAL_ADDRESS_LIMIT_GET         ETHSWT_EXT_ID_OF(0xBBU)  /**< @brief #ETHSWT_ExtTotalMACLearningLimitType     #ETHSWT_GetTotalAddrLimitAndCounter */
#define ETHSWT_EXTCMDID_STICKY_MAC_ADDRESS_SET          ETHSWT_EXT_ID_OF(0xBCU)  /**< @brief #ETHSWT_ExtStickyMACType                 #ETHSWT_SetMACAddressStickyToPort   */
#define ETHSWT_EXTCMDID_STICKY_MAC_ADDRESS_GET          ETHSWT_EXT_ID_OF(0xBDU)  /**< @brief #ETHSWT_ExtStickyMACType                 #ETHSWT_GetMACAddressStickyToPort   */
#define ETHSWT_EXTCMDID_GETWAKEUPMODE                   ETHSWT_EXT_ID_OF(0xBEU)  /**< @brief #ETHSWT_ExtTc10WakeUpType                #ETHSWT_GetPortWakeUpMode           */
#define ETHSWT_EXTCMDID_GETWAKEUPREASON                 ETHSWT_EXT_ID_OF(0xBFU)  /**< @brief #ETHSWT_ExtTc10WakeUpType                #ETHSWT_GetPortWakeUpReason         */
#define ETHSWT_EXTCMDID_GET_DLF_PORT_MAP                ETHSWT_EXT_ID_OF(0xC0U)  /**< @brief #ETHSWT_ExtUpdateDlfPortMapType          #ETHSWT_GetDLFPortMap               */
#define ETHSWT_EXTCMDID_ADD_DLF_UCAST_PORT_MAP          ETHSWT_EXT_ID_OF(0xC1U)  /**< @brief #ETHSWT_ExtUpdateDlfPortMapType          #ETHSWT_AddPortToDLFUcastMap        */
#define ETHSWT_EXTCMDID_ADD_DLF_MCAST_PORT_MAP          ETHSWT_EXT_ID_OF(0xC2U)  /**< @brief #ETHSWT_ExtUpdateDlfPortMapType          #ETHSWT_AddPortToDLFMcastMap        */
#define ETHSWT_EXTCMDID_REMOVE_DLF_UCAST_PORT_MAP       ETHSWT_EXT_ID_OF(0xC3U)  /**< @brief #ETHSWT_ExtUpdateDlfPortMapType          #ETHSWT_RemovePortFromDLFUcastMap   */
#define ETHSWT_EXTCMDID_REMOVE_DLF_MCAST_PORT_MAP       ETHSWT_EXT_ID_OF(0xC4U)  /**< @brief #ETHSWT_ExtUpdateDlfPortMapType          #ETHSWT_RemovePortFromDLFMcastMap   */
#define ETHSWT_EXTCMDID_NOTIFY_LINKSTATUS               ETHSWT_EXT_ID_OF(0xC5U)  /**< @brief #ETHXCVR_NotifyLinkStatusType            #BCM_NotifyEvent                    */
#define ETHSWT_EXTCMDID_NOTIFY_LINKSTATUSCHNG           ETHSWT_EXT_ID_OF(0xC6U)  /**< @brief #ETHXCVR_NotifyLinkStatusType            #BCM_NotifyEvent                    */
#define ETHSWT_EXTCMDID_SET_EAPMODE                     ETHSWT_EXT_ID_OF(0xC7U)  /**< @brief #ETHSWT_ExtEAPModeMsgType                #ETHSWT_SetPortEAPOL                */
#define ETHSWT_EXTCMDID_GET_EAP_STATUS                  ETHSWT_EXT_ID_OF(0xC8U)  /**< @brief #ETHSWT_ExtEAPStatusMsgType              #ETHSWT_GetPortEAPOL                */
#define ETHSWT_EXTCMDID_SET_PORT_ENABLE                 ETHSWT_EXT_ID_OF(0xC9U)  /**< @brief #ETHSWT_ExtPortEnableMsgType             #ETHSWT_ExtPortEnableMsgType        */
#define ETHSWT_EXTCMDID_GET_PORT_ENABLE                 ETHSWT_EXT_ID_OF(0xCAU)  /**< @brief #ETHSWT_ExtPortEnableMsgType             #ETHSWT_ExtPortEnableMsgType        */
#define ETHSWT_EXTCMDID_PORT_INFO_GET_V2                ETHSWT_EXT_ID_OF(0xCBU)  /**< @brief #ETHSWT_ExtPortInfoV2Type                                                    */
/** @} */

/**
    @brief Maximum size of VLAN command payload in bytes

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_EXT_MAX_PAYLOAD_SIZE   (184UL)

/**
    @name Port capability
    @{
    @brief Port capability

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PortCapabilityType;
#define ETHSWT_PORT_CAPABILITY_MACSEC_SHIFT     (0x0UL)
#define ETHSWT_PORT_CAPABILITY_MACSEC_MASK      (0x1UL << ETHSWT_PORT_CAPABILITY_MACSEC_SHIFT)
/** @} */

/**
    @brief Structure to manage the port parameters.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtPortInfoType {
    ETHSWT_PortIDType           port;               /**< @brief Port identifier */
    ETHXCVR_ModeType            adminMode;          /**< @brief Admin mode of the port - enabled/disabled */
    ETHXCVR_LinkStateType       linkStatus;         /**< @brief Link status of the port - up/down */
    ETHXCVR_SpeedType           speed;              /**< @brief Current speed of the port - 10/100/Autoneg */
    ETHXCVR_BooleanType         masterEnable;       /**< @brief BroadR-Reach mode - master/slave */
    ETHXCVR_BooleanType         jumboEnable;        /**< @brief Jumbo enable */
    ETHXCVR_BooleanType         loopbackEnable;     /**< @brief Loop back mode - enabled/disabled */
    ETHXCVR_BooleanType         autonegEnable;      /**< @brief Auto Neg - enabled/disabled */
    ETHXCVR_AutoNegStatusType   autonegComplete;    /**< @brief Auto Neg - complete/pending */
    ETHXCVR_DuplexModeType      duplex;             /**< @brief duplex - full/half */
    uint32_t                    led;                /**< @brief led - on/off */
    uint32_t                    linkStateChangeCnt; /**< @brief no. of state changes */
    ETHXCVR_BusModeType         busMode;            /**< @brief XCVR bus mode */
    ETHXCVR_PhyMediaType        phyMedia;           /**< @brief XCVR phy media */
    uint32_t                    linkSQI;            /**< @brief Link SQI */
    uint32_t                    pvid;               /**< @brief PVID */
    uint32_t                    prio;               /**< @brief Priority */
} ETHSWT_ExtPortInfoType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtPortInfoType, 40UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the Additional port parameters.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtPortInfoV2Type {
    ETHSWT_ExtPortInfoType    portInfo;            /**< @brief Port Parameters */
    ETHSWT_PortCapabilityType portCapability;      /**< @brief Port Hardware Feature Capability Ex: MACSEC, TC10 */
    PAE_ConnectStatusType     securityStatus;      /**< @brief Port Security Status
                                                               SECURED         : Port has enabled the Header Tagging / Data Encription
                                                               AUTHENTICATED   : Port in not secured but server allowed the UnTag-Traffic to flow
                                                               UNAUTHENTICATED : Port is un-authenticated : Default */

    SECY_PortStatusType       secyPortStatus;      /**< @brief Secy port related status */
    uint32_t                  rsvd[20];
} ETHSWT_ExtPortInfoV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtPortInfoV2Type, 160UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)


/**
    @brief Structure to manage the switch get/set parameters.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtSwitchInfoType {
    uint32_t                         ageTime;     /**< @brief Age Time */
    ETHSWT_DumbFwdModeType           dumbFwdMode; /**< @brief Dumb Forward Mode */
    ETHSWT_VLANIngressFilterModeType iFilter;     /**< @brief Ingress Filter */
    ETHSWT_BrcmHdrModeType           brcmHdrMode; /**< @brief Broadcom Header Mode */
    ETHSWT_MgmtModeType              mgmtMode;    /**< @brief Management Mode */
} ETHSWT_ExtSwitchInfoType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtSwitchInfoType, 20UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage tc10 sleep wake

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtTc10WakeUpType {
    ETHSWT_PortIDType           port;           /**< @brief Port identifier    */
    ETHXCVR_WakeupReasonType    reason;         /**< @brief Wakeup Reason      */
    uint8_t                     mode;           /**< @brief Sleep Wake Control */
} ETHSWT_ExtTc10WakeUpType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtTc10WakeUpType, 8UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage station movement

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtStationMovementType {
    ETHSWT_PortIDType            port;              /**< @brief Port identifier */
    ETHSWT_SecurityActionType    stationMoveAction; /**< @brief Station movement action */
} ETHSWT_ExtStationMovementType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtStationMovementType, 8UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage address limiting

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtPortAddressLimitType {
    ETHSWT_PortIDType            port;                   /**< @brief Port identifier */
    ETHSWT_AddressLimitingType   addressLimitInfo;       /**< @brief Address limiting information */
    uint16_t                     portLearnedCounter;     /**< @brief SA MAC addresses learned on the port */
    uint32_t                     portOverLimitCounter;   /**< @brief Overlimit counter */
} ETHSWT_ExtPortAddressLimitType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtPortAddressLimitType, 16UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage sticky MAC

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtStickyMACType {
    ETHSWT_PortIDType            port;               /**< @brief Port identifier */
    ETHSWT_SecurityActionType    stickyMACAction;    /**< @brief Sticky MAC address action */
} ETHSWT_ExtStickyMACType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtStickyMACType, 8UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage address limiting across all ports

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtTotalMACLearningLimitType {
    uint16_t    totalMACLearningLimit;      /**< @brief maximum number of MAC
                                                  addresses allowed to
                                                  learn across all ports */
    uint16_t    totalLearnedCounter;        /**< @brief SA MAC addresses learned across all ports */
} ETHSWT_ExtTotalMACLearningLimitType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtTotalMACLearningLimitType, 4UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the switch port link information type.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtPortLinkInfoType {
    ETHSWT_PortIDType       port;           /**< @brief Port identifier */
    ETHXCVR_LinkStateType   linkState;      /**< @brief Link status of the port - up/down */
    ETHSWT_PortStatsType    portStats;      /**< @brief Port stats */
} ETHSWT_ExtPortLinkInfoType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtPortLinkInfoType, 12UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @name ETHSWT_ExtAsyncEventType
    @{
    @brief ETHSWTM EXT Asynchronous event type

    Event generated asynchronously by target

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_ExtAsyncEventType;
#define ETHSWT_EXTASYNCEVENT_PORT_LINK_INFO  (0x00U) /**< @brief Port link event */
/** @} */
/**
    @brief DLF (Destination Lookup Failure) Drop Map Configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtUpdateDlfPortMapType {
    ETHSWT_PortIDType             portNum;            /**< @brief Switch Port Index */
    ETHSWT_PortMaskType           dlfUcastPortMap;    /**< @brief DLF Unicast Port Map */
    ETHSWT_PortMaskType           dlfMcastPortMap;    /**< @brief DLF Multicast Port Map */
} ETHSWT_ExtUpdateDlfPortMapType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtUpdateDlfPortMapType, 24UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @name Port EAP blocking mode
    @{

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_ExtEAPBlockingModeType;
#define ETHSWT_EXT_EAP_BLOCKING_MODE_NO_CHECK        (0x0U) /**< @brief Do not check EAP_BLK_MODE          */
#define ETHSWT_EXT_EAP_BLOCKING_MODE_INGRESS         (0x1U) /**< @brief Check EAP_BLK_MODE on ingress port */
#define ETHSWT_EXT_EAP_BLOCKING_MODE_INGRESS_EGRESS  (0x3U) /**< @brief Check EAP_BLK_MODE on both ingress and egress port*/
#define ETHSWT_EXT_EAP_BLOCKING_MODE_MAX             (ETHSWT_EXT_EAP_BLOCKING_MODE_INGRESS_EGRESS)
/** @} */

/**
    @brief Structure to manage the Port EAP blocking mode

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtEAPModeMsgType{
    ETHSWT_PortMaskType            portMask;       /**< @brief Port Mask                       */
    ETHSWT_ExtEAPBlockingModeType  immediate;     /**< @brief Immediate EAP Mode              */
    ETHSWT_ExtEAPBlockingModeType  linkChange;    /**< @brief EAP Mode when link state change */
    uint8_t                        rsvd8[6U];
    uint32_t                       rsvd[4UL];
} ETHSWT_ExtEAPModeMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtEAPModeMsgType, 32UL, ETHSWT_CORE_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to get the EAP blocking mode for all ports

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtEAPStatusMsgType{
    //TODO: ETHSWT_PORT_ID_MAX python utility import error
    ETHSWT_ExtEAPBlockingModeType  currentEAPMode[64U];    /**< @brief Current EAP mode status           */
    ETHSWT_ExtEAPBlockingModeType  eapLinkChangeMode[64U]; /**< @brief Link state change EAP mode config */
    uint32_t                       rsvd[4UL];
} ETHSWT_ExtEAPStatusMsgType;

/**
    @brief Port Tx Enable message structure

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ExtPortEnableMsgType{
    uint64_t                       portMask;             /**< @brief Port mask */
    uint64_t                       enableMask;           /**< @brief per port Enable, 1:Enable, 0:Disbale */
    ETHSWT_TrafficDirType          direction;            /**< @brief Traffic direction */
    uint8_t                        rsvd[7UL];
} ETHSWT_ExtPortEnableMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtPortEnableMsgType, 24UL, ETHSWT_CORE_MAX_PAYLOAD_SIZE)

/**
    @brief EXT Union encapsulating all messages

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef union uETHSWT_ExtMsgUnionType {
    uint32_t                                 data[ETHSWT_EXT_MAX_PAYLOAD_SIZE/4UL];
    ETHSWT_ExtPortInfoType                   portInfo;             /**< @brief Port information */
    ETHSWT_ExtPortInfoV2Type                    portInfoV2;           /**< @brief Port information */
    ETHSWT_ExtSwitchInfoType                 switchInfo;           /**< @brief Switch information */
    ETHSWT_ExtTc10WakeUpType                 tc10Wake;             /**< @brief TC10 wake-up */
    ETHSWT_CoreRegAccessType                 regAccess;            /**< @brief Switch reg read or write     */
    uint32_t                                 vlanHoppingAction;    /**< @brief VLAN hopping Action */
    ETHSWT_ExtStationMovementType            stationMove;          /**< @brief Station Movement */
    ETHSWT_ExtPortAddressLimitType           addrLimit;            /**< @brief Address Limit */
    ETHSWT_ExtStickyMACType                  stickyMAC;            /**< @brief Sticky MAC */
    ETHSWT_ExtTotalMACLearningLimitType      totalAddressLimit;    /**< @brief Total MAC Learning Limit */
    ETHSWT_ExtPortLinkInfoType               portLinkInfo;         /**< @brief Port link information */
    ETHSWT_ExtUpdateDlfPortMapType           dlfMapConfig;         /**< @brief Dlf Port map Config */
    ETHSWT_ExtEAPModeMsgType                 eapMode;              /**< @brief EAP mode */
    ETHSWT_ExtEAPStatusMsgType               eapStatus;            /**< @brief EAP status */
    ETHSWT_ExtPortEnableMsgType            portEnMsg;            /**< @brief Port TX Enable message */
} ETHSWT_ExtMsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ExtMsgUnionType, ETHSWT_EXT_MAX_PAYLOAD_SIZE, ETHSWT_EXT_MAX_PAYLOAD_SIZE)


/** @brief Maximum number of QoS FIFO per port

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PORT_FIFO_MAX                    (8UL)

/**
    @name Port scheduler type
    @{
    @brief Port scheduler type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_SchedAlgoType;   /**< @brief Port scheduler type */
#define ETHSWT_SCHED_ALGO_SP  (0U)      /**< @brief Strict priority scheduler */
#define ETHSWT_SCHED_ALGO_WRR (1U)      /**< @brief Weighted round robin scheduler */
#define ETHSWT_SCHED_ALGO_DRR (2U)      /**< @brief Deficit round robin scheduler */
/** @} */

/**
    @brief Port scheduler type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_PortSchType {
    ETHSWT_SchedAlgoType algo[ETHSWT_PORT_FIFO_MAX];   /**< @brief Array of
                                                        scheduler algorithm type for
                                                        all port FIFOs.
                                                        @note Not all possible
                                                        combinations of scheduler
                                                        configurations are
                                                        supported. Refer to @ref
                                                        sec_ref_trm for the list of
                                                        supported scheduler
                                                        configurations. */
} ETHSWT_PortSchType;

/**
    @brief Port shaper configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ShaperCfgType {
    uint32_t     rateBps;           /**< @brief Increase in credit in bits per
                                          second (shall be multiple of 64000) */
    uint32_t     burstBytes;        /**< @brief Bucket size in bytes (shall be a
                                              multiple of 64). */
    BCM_BoolType avbShapingModeEn;  /**< @brief Enable AVB shaping mode. */
} ETHSWT_ShaperCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ShaperCfgType, 12UL, ETHSWT_EXT_MAX_PAYLOAD_SIZE)

/**
    @brief FIFO configuration in egress port

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FifoCfgType {
    uint32_t id;                    /**< @brief Index of FIFO */
    uint32_t minLen;                /**< @brief FIFO minimum length in bytes
                                              (guaranteed size of FIFO) */
    ETHSWT_TCType tc;               /**< @brief Traffic class assigned to this
                                                  FIFO. */
    ETHSWT_ShaperCfgType shaper;    /**< @brief Shaper configuration. Queue shaper
                                          is configured by ETHSWT_ShaperCfgType::rateBps
                                          and ETHSWT_ShaperCfgType::burstBytes. A
                                          non-zero value of rateBps and burstBytes
                                          enables queue shaper.
                                          Additionally, AVB shaper is enabled/disabled
                                          by ETHSWT_ShaperCfgType::avbShapingModeEn */
} ETHSWT_FifoCfgType;

/**
    @name Port policer action type
    @{
    @brief Port policer action type

    Action to be taken by the switch when rate violation happens on the port.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PortPolicerActType;     /**< @brief Port policer action type */
#define ETHSWT_PORT_RATE_POLICER_BLOCK_SRC     (1UL) /**< @brief Block the source on rate violation
                                                         (using MAC flow control: Pause frame) */
#define ETHSWT_PORT_RATE_POLICER_DROP_PKT      (2UL) /**< @brief Drop the packet on rate violation */
/** @} */

/**
    @name Ingress port policer flags
    @{
    @brief Ingress port policer flags

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PolicerPacketFlgMaskType;   /**< @brief  Policer flags type */
#define ETHSWT_PACKET_UNICAST_LOOKUP_HIT       (0x1UL)   /**< @brief Packet unicast look-up hit */
#define ETHSWT_PACKET_MULTICAST_LOOKUP_HIT     (0x2UL)   /**< @brief Packet multicast look-up hit */
#define ETHSWT_PACKET_RES_MULTICAST_LOOKUP_HIT (0x4UL)   /**< @brief Packet reserved multicast look-up hit */
#define ETHSWT_PACKET_BROADCAST_LOOUP_HIT      (0x8UL)   /**< @brief Packet broadcast look-up hit */
#define ETHSWT_PACKET_MULTICAST_LOOKUP_FAILED  (0x10UL)  /**< @brief Packet multicast look-up failed */
#define ETHSWT_PACKET_UNICAST_LOOKUP_FAILED    (0x20UL)  /**< @brief Packet unicast look-up failed */
/** @} */

/**
    @brief Port policer configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_PortPolicerCfgType{
    ETHSWT_PolicerPacketFlgMaskType pktMask;    /**< @brief Port policer packet
                                                     flag type (bit mask value
                                                     of the packet types on
                                                     which this policer is to be
                                                     applied). */
        uint32_t rateByteCount;                     /**< @brief Amount of the data
                                                         (excluding header) which
                                                         can be received on this
                                                         port in given time
                                                         (rateTimeInterval) */
    uint32_t rateTimeInterval;                  /**< @brief Time interval in
                                                          seconds where configured
                                                          bytes can be received
                                                          without a rate limitation. */
        ETHSWT_PortPolicerActType action;         /**< @brief Action to be taken
                                                            by the switch in case of
                                                            the rate violation. */
} ETHSWT_PortPolicerCfgType;

/**
    @brief Maximum number of MAC entries per port

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PORT_MAC_ENTRY_MAX               (16UL)

/**
    @brief Maximum number of VLAN entries per port

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PORT_VLAN_ENTRY_MAX              (16UL)

/**
    @brief Port ingress configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_PortIngressCfgType {
    ETHER_VLANIDType        defaultVLAN;    /**< @brief Default VLAN for
                                                this port. For more detail
                                                refer @ref eth_switch_port_forward_config
                                                "Ingress config" */
    ETHSWT_PCPType          defaultPrio;    /**< @brief Default priority of
                                                the VLAN. For more detail
                                                refer @ref eth_switch_port_forward_config
                                                "Ingress config" */
    BCM_BoolType            dropUntagged;   /**< @brief If default VLAN is not configured
                                                and this is set to TRUE, all the
                                                untagged frames shall be dropped
                                                in this port.
                                                For more detail refer @ref
                                                eth_switch_port_forward_config
                                                "Ingress config" */
    ETHSWT_TCType           tc;             /**< @brief Port traffic class.
                                                If configured, all the ingress packet on
                                                this port shall be assinged this
                                                traffic class. If set to #ETHSWT_TC_INVALID,
                                                no traffic class based assignment
                                                shall be done on this port. */
    uint32_t                policerEn;      /**< @brief Enable/disable policer.
                                                @note This parameter is
                                                not supported by driver.*/
    ETHSWT_PortPolicerCfgType   policer;    /**< @brief Port policer configurations.
                                                @note This parameter is not supported by driver.*/
    ETHSWT_TCType           pcp2tcMap[8UL]; /**< @brief PCP to traffic class
                                                              map. */
} ETHSWT_PortIngressCfgType;

/**
    @brief Port egress configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_PortEgressCfgType {

    ETHSWT_FifoCfgType  fifoList[ETHSWT_PORT_FIFO_MAX]; /**< @brief Configuration of port FIFOs. */
    uint32_t            fifoListSz;         /**< @brief Size of fifoList. */
    ETHSWT_PortSchType  scheduler;          /**< @brief Port scheduler */
    BCM_BoolType        pcpRemarkEn;        /**< @brief Enable/disable PCP remarking */
    ETHSWT_PCPType      tc2pcpMap[8UL];     /**< @brief Traffic class to PCP map
                                                @note If pcpRemarkEn is set as false,
                                                all instances of this sub-element are ignored.
                                                However if pcpRemarkEn is set as TRUE,
                                                exactly 8 instances of tc2pcpMap field
                                                shall be provided, in the order of
                                                TC0, TC1, â€¦ TC7. */
    ETHSWT_ShaperCfgType portShaper;        /**< @brief Shaper configuration. Port shaper
                                                is configured by ETHSWT_ShaperCfgType::rateBps
                                                and ETHSWT_ShaperCfgType::burstBytes. A
                                                non-zero value of rateBps and burstBytes
                                                enables port shaper.
                                                Additionally, AVB shaper is enabled/disabled
                                                by ETHSWT_ShaperCfgType::avbShapingModeEn */
} ETHSWT_PortEgressCfgType;

/**
    @brief Port security configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_PortSecurityCfgType {
    ETHSWT_AddressLimitingType addressLimit;     /**< @brief Address limiting config */
    ETHSWT_SecurityActionType  stickyMACAction;  /**< @brief Indicates the actions
                                                    after receiving packet with
                                                    source MAC address, which is
                                                    not sticky to this port, If
                                                    this field is non-zero otherwise
                                                    sticky MAC address feature
                                                    is disabled for this port. */
    ETHSWT_SecurityActionType  stationMoveAction;
                                                /**< @brief Action after detecting
                                                    the station movement, If this
                                                    field is non-zero otherwise
                                                    station movement detection feature
                                                    is disabled for this port. */
} ETHSWT_PortSecurityCfgType;

/**
    @brief Port configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_PortCfgType {
    uint32_t                   portID;            /**< @brief Port Index */
    ETHSWT_PortType            role;              /**< @brief Port role */
    uint32_t                   xcvrID;            /**< @brief Index of transceiver connected to this port */
    BCM_BoolType               enableTimeStamp;   /**< @brief Enable or disable timestamp support*/
    BCM_BoolType               enableJumboFrm;    /**< @brief Enable jumbo frames support on this port. */
    uint8_t                    fixedMacAddrList[ETHSWT_PORT_MAC_ENTRY_MAX][6UL];  /**< @brief Fixed MAC address which can be r                                                                                       eached fom this port */
    uint32_t                   macAddrListSz;     /**< @brief Size of the MAC address list */
    ETHSWT_VLANMemberCfgType   vlanMemList[ETHSWT_PORT_VLAN_ENTRY_MAX];/**<@brief VLAN membership list of this port.*/
    uint32_t                   vlanMemListSz;     /**< @brief Size of the VLAN membership list */
    ETHSWT_PortIngressCfgType  ingressCfg;        /**< @brief Port ingress configuration */
    ETHSWT_PortEgressCfgType   egressCfg;         /**< @brief Port egress configuration */
    ETHSWT_PortSecurityCfgType securityCfg;       /**< @brief Security configuration */
} ETHSWT_PortCfgType;

/**
    @brief Global security configuration across ports
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_GlobalSecurityCfgType {
    ETHSWT_SecurityActionType     vlanHoppingAction;
                                                 /**< @brief Action after detecting
                                                        Invalid double-tagged-packet,
                                                        If this field is non-zero otherwise
                                                        Invalid double-tagged-packet
                                                        detection feature is disabled
                                                        for this port. */
    uint16_t                      totalMACLearningLimit;
                                                /**< @brief Total count of dynamically
                                                        learned unicast MAC addresses
                                                        across all the ports. The limit is
                                                        capped at the #ETHSWT_ARL_SIZE.*/
} ETHSWT_GlobalSecurityCfgType;


/**
    @brief Port configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_ExtPortConfigType {
    uint32_t                     portID;            /**< @brief Port Index */
    ETHSWT_PortType              role;              /**< @brief Port role */
    uint32_t                     enableTimeStamp;   /**< @brief Enable or disable timestamp support*/
    uint32_t                     enableJumboFrm;    /**< @brief Enable jumbo frames support on this
                                                            port */
    ETHSWT_PortIngressCfgType    ingressCfg;        /**< @brief Port ingress configuration */
    ETHSWT_PortEgressCfgType     egressCfg;         /**< @brief Port egress configuration */
    ETHSWT_PortSecurityCfgType   securityCfg;       /**< @brief Security configuration */
} ETHSWT_ExtPortConfigType;

/** @brief Get port Information

    This API retrieves the Information of #aPortID

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aPortInfo   Pointer to retrieve Port Information

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port Information
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl
    @retval     #BCM_ERR_NOT_FOUND      #aPortID is not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetPortInfo(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                  ETHSWT_ExtPortInfoType *const aPortInfo);

/** @brief Set port Admin mode

    This API sets Admin mode of #aPortID.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[in]      aMode       Port Admin mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set port mode
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl or aMode is Invalid
    @retval     #BCM_ERR_NOT_FOUND      #aPortID is not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRSetPortAdminmode(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                ETHXCVR_ModeType aMode);

/** @brief Retrieve port Admin mode

    This API retrieves Admin mode of #aPortID.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aMode       Pointer to retrieve Port mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved Port mode
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl or aMode is NULL
    @retval     #BCM_ERR_NOT_FOUND      #aPortID is not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetPortAdminmode(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                ETHXCVR_ModeType *const aMode);

/** @brief Set port master/slave mode

    This API set master/slave mode of a particular port.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[in]      aMode       Port master/slave mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully sets port master mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is invalid) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_NOT_FOUND      Port index not found
    @return     #BCM_ERR_UNKNOWN        Other Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRSetPortMasterSlave(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                                    const uint8_t aMode);

/** @brief Get port master/slave mode

    This API retrieves master/slave mode of a particular port.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aMode       Pointer to retrieve port master/slave mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port master mode
    @retval     #BCM_ERR_INVAL_PARAMS   (If aMode is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_NOT_FOUND      Port index not found
    @return     #BCM_ERR_UNKNOWN        Other Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetPortMasterSlave(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                            uint8_t *const aMode);

/** @brief Get port speed

    This API Get speed of a particular port.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[in]      aSpeed      Pointer to retrieve Port speed

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port speed
    @retval     #BCM_ERR_INVAL_PARAMS   (aSpeed is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_NOT_FOUND      Port index not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetPortSpeed(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                            ETHXCVR_SpeedType *const aSpeed);

/** @brief Set port loopback mode

    This API set loopback mode of the #aPortID

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[in]      aMode       Port loopback mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set port loopback mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is invalid) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_NOT_FOUND      Port index not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRSetPortPhyLb(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                            const uint8_t aMode);

/** @brief Get port loopback mode

    This API retrieves loopback mode of the #aPortID

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aMode       Pointer to retrieve port loopback mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port loopback mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_NOT_FOUND      Port index not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetPortPhyLb(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                uint8_t *const aMode);

/** @brief Set port jumbo mode

    This API set jumbo mode of a particular port.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[in]      aMode       Port jumbo mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set port jumbo mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is invalid) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_NOT_FOUND      Port index not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRSetPortJumboFrame(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                const uint8_t aMode);

/** @brief Get port jumbo mode

    This API retrieves jumbo mode of a particular port.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aMode       Pointer to retrieve port jumbo mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port jumbo mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_NOT_FOUND      Port index not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetPortJumboFrame(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                uint8_t *const aMode);

/** @brief Get port default VLAN and Priority

    This API retrieves default VLAN ID and priority for a #aPortID

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[in]      aPVlanID    Port's default VLAN ID
    @param[in]      aPriority   Port's default priority

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port VLAN ID and
                                        port priority
    @retval     #BCM_ERR_INVAL_PARAMS   (aPriority is Invalid) or
                                        (aPVlanID is Invalid) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRSetPvid(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                ETHER_VLANIDType aPVlanID, uint16_t aPriority);

/** @brief Retrieve Port SQI value

    This API retrieves SQI value of #aPortID

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aSQIValue   Pointer to retrieve SQI value

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port SQI value
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetPortLinkSqi(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                                uint32_t *const aSQIValue);

/** @brief Retrieve All Ports SQI value

    This API retrieves All Ports SQI value

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[out]     aLinkStatus     array of size HOST_MAX_NUM_PORTS to retrieve Port Link Status
    @param[out]     aSQIValue       array of size HOST_MAX_NUM_PORTS to retrieve SQI value.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved SQI values
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (aLinkStatus is NULL) or
                                        (aSQIValue is NULL)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetPortLinkSqiAll(BCM_HandleType aConnHdl, uint8_t *const aLinkStatus,
                                                    uint32_t *const aSQIValue);

/** @brief Gwt Ethernet Switch Port Wakeup Mode

    This API Query the Sleep Mode status on #aPortID

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[Out]     aMode       WakeUpMode Enable Status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Mode Retrieved Successfully
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (aMode is NULL)
    @retval     #BCM_ERR_NOSUPPORT      No Support
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetTc10WakeupMode(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                    ETHXCVR_BooleanType *const aMode);

/** @brief Ethernet Switch Port Wakeup Reason Report

    This API Reads the wakeup Reason on the Capable PHY
    the indexed switch port by calling #ETHXCVR_GetWakeUpReason.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index
    @param[out]     aReason     WakeUp Reason Type

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Reason Retrieved Successfully
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (aReason is NULL)
    @retval     #BCM_ERR_NOSUPPORT      No Support
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_XCVRGetTc10WakeupReason(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                    ETHXCVR_WakeupReasonType *const aReason);

/** @brief Set Vlan-Hopping detection action

    This API sets Vlan-Hopping detection.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aVlanHoppingAction       Vlan-Hopping action.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set Vlan-Hopping
                                        detection
    @retval     #BCM_ERR_INVAL_PARAMS   (invalid Vlan-Hopping action) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_NOPERM         CPU port is not available
                                        (Valid only for the action,
                                         redirect to CPU)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtSetVlanHopDetect(BCM_HandleType aConnHdl,
                                            ETHSWT_SecurityActionType aVlanHoppingAction);

/** @brief Get Vlan-Hopping detection action

    This function retreives switch Vlan-Hopping detection action.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[out]     aVlanHoppingAction       Pointer to Vlan-Hopping
                                             action.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved Vlan-Hopping
                                        status
    @retval     #BCM_ERR_INVAL_PARAMS   (aVlanHoppingAction is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtGetVlanHopDetect(BCM_HandleType aConnHdl,
                                    ETHSWT_SecurityActionType *const aVlanHoppingAction);

/** @brief Set address limiting information of the port

    This API sets the maximum number of MAC addresses that are learned on
    the port.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortID                  Port index
    @param[in]      aAddressLimitInfo        Pointer to address limiting
                                             information

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set address limiting information
                                        for the port
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (Invalid aPortID) or
                                        (Invalid address limit
                                        action or value) or (aAddressLimitInfo
                                        is NULL)
    @retval     #BCM_ERR_NOPERM         CPU port is not available
                                        (Valid only for the action,
                                        redirect to CPU and copy to CPU)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtSetArlPortLimit(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                        const ETHSWT_AddressLimitingType * const aAddressLimitInfo);

/** @brief Get address limiting information for the port

    This API retreives switch address limiting information
    of the provided port.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortID                  Port index
    @param[out]     aAddressLimitInfo        Pointer to address limiting
                                             action
    @param[out]     aPortLearnedCounter      pointer to the number
                                             of SA MAC addresses
                                             learned on this ports.
                                             This counter can't exceed
                                             the max programmed learning
                                             value of this port
    @param[out]     aPortOverLimitCounter    pointer to the overlimit
                                             counter value of this ports.
                                             This counter is the number of
                                             packets ingress to this port after
                                             port SA learn counter exceeds to
                                             SA learn limit.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved address limiting
                                        information of the provided port
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (Invalid aPortID) or
                                        (aAddressLimitInfo is NULL) or
                                        (aPortLearnedCounter is NULL) or
                                        (aPortOverLimitCounter is NULL) or
                                        (invalid PortID)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtGetArlPortLimit(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                        ETHSWT_AddressLimitingType * const aAddressLimitInfo,
                                                        uint16_t * const aPortLearnedCounter,
                                                        uint32_t * const aPortOverLimitCounter);

/** @brief Set sticky MAC Address action to the port

    This API sets the sticky MAC Address action to a port.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortID                  Port index
    @param[in]      aStickyMACAction         Sticky MAC address
                                             action

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set sticky MAC Address
                                        action to the port
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (Invalid aPortID) or
                                        (Invalid sticky MAC address
                                        action)
    @retval     #BCM_ERR_NOPERM         CPU port is not available
                                        (Valid only for the action,
                                        redirect to CPU)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtSetArlSticky(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                    ETHSWT_SecurityActionType aStickyMACAction);

/** @brief Get sticky MAC Address information to the port

    This API retreives sticky MAC Address information
    of the provided port.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortID                  Port index
    @param[out]     aStickyMACAction         Pointer to sticky MAC address
                                             action

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved sticky MAC
                                        Address information to the port
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (Invalid switch index) or
                                        (Invalid aPortID) or
                                        (aStickyMACAction is NULL)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtGetArlSticky(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                          ETHSWT_SecurityActionType *const aStickyMACAction);

/** @brief Set station movement detection

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortID                  Port index
    @param[in]      aSMDetectAction          Station movement
                                             detection action

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set station movement
                                        detection action
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (Invalid aPortID) or
                                        (Invalid aSMDetectAction)
    @retval     #BCM_ERR_NOPERM         CPU port is not available
                                        (Valid only for the action,
                                         redirect to CPU)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtSetArlMoveDetect(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                        ETHSWT_SecurityActionType aSMDetectAction);

/** @brief Get station movement detection

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortID                  Port index
    @param[out]     aSMDetectAction          Pointer to station movement
                                             detection action

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved station movement
                                        detection information information
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (aSMDetectAction is NULL) or
                                        (Invalid aPortID)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtGetArlMovedetect(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortID,
                                                ETHSWT_SecurityActionType *const aSMDetectAction);

/** @brief Set total MAC-SA limiting control

    This API sets the maximum number of MAC addresses that are learned
    accross all the port.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aTotalMACLearningLimit   maximum number of MAC
                                             addresses allowed to
                                             learn across all ports

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set address limiting information
                                        for the port
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (Invalid switch index) or
                                        (aTotalMACLearningLimit
                                        is greater than the maximum
                                        ARL table size)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtSetArlTotalLimit(BCM_HandleType aConnHdl, const uint16_t aTotalMACLearningLimit);

/** @brief Get total MAC-SA limiting control

    This API retreives total MAC-SA limit accross
    all the port.

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[out]     aTotalMACLearningLimit   pointer to maximum
                                             number of MAC
                                             addresses allowed to
                                             learn on all ports
    @param[out]     aTotalLearnedCounter     pointer to the number
                                             of SA MAC addresses
                                             learned on all ports.
                                             This counter can't exceed
                                             the max programmed learning
                                             value across all the port

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully get address limiting information
                                        for the port
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (aTotalMACLearningLimit
                                        is NULL) or (aTotalLearnedCounter
                                        is NULL)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtGetArlTotalLimit(BCM_HandleType aConnHdl, uint16_t * const aTotalMACLearningLimit,
                                                                        uint16_t * const aTotalLearnedCounter);

/** @brief Get DLF Port Map for Unicast and  MultiCast

    This API retreives the DLF (Destination Lookup Failure) Port Mask for Unicast and Multicast

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[out]     aDlfUcastPortMap         Pointer to DLF Unicast Port map
    @param[out]     adlfMcastPortMap         Pointer to DLF Multicast Port map

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved the DLF map for Unicast and Multicast
                                        for the port
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (aDlfUcastPortMap is NULL) or
                                        (adlfMcastPortMap is NULL)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtGetDlfPortMap(BCM_HandleType aConnHdl, ETHSWT_PortMaskType * const aDlfUcastPortMap,
                                       ETHSWT_PortMaskType * const adlfMcastPortMap);

/** @brief Add a Port to DLF Port Map for Unicast

    This API add a Port to  the DLF Port Map for Unicast

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortId                  Switch Port Id

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully add the port to  DLF map for Unicast
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl or Invalid aPortId
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtAddDlfUcastPortMap(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortId);

/** @brief Add a Port to DLF Port Map for Multicast

    This API add a Port to  the DLF Port Map for Multicast

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortId                  Switch Port Id

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully add the port to DLF map for Multicast
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl or Invalid aPortId
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtAddDlfMcastPortMap(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortId);

/** @brief Remove a Port to DLF Port Map for Unicast

    This API remove a Port from  the DLF Port Map for Unicast

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortId                  Switch Port Id

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully removed  the port from DLF map for Unicast
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl or Invalid aPortId
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtRemoveDlfUcastPortMap(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortId);

/** @brief Remove a Port to DLF Port Map for Multicast

    This API remove a Port from the DLF Port Map for Multicast

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPortId                  Switch Port Id

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully removed the port from DLF map for Multicast
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl or Invalid aPortId
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtRemoveDlfMcastPortMap(BCM_HandleType aConnHdl, ETHSWT_PortIDType aPortId);

/** @brief Set Port EAP blocking mode

    This API set the port immediate and link change EAP blocking mode.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aEAPMode    EAP mode message

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set EAP mode
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtSetEAPMode(BCM_HandleType aConnHdl,
                                       const ETHSWT_ExtEAPModeMsgType *const aEAPMode);

/** @brief Get EAP status

    This API fetches the current EAP status for all ports and link state change config

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl      Connection handle (from RPC_Connect)
    @param[out]     aEAPStatus    EAP status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully get EAP mode
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl or
                                        aEAPStatus is NULL
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ExtGetEAPStatus(BCM_HandleType aConnHdl,
                                       ETHSWT_ExtEAPStatusMsgType * const aEAPStatus);
#endif /* ETHERNET_SWT_EXT_H */
/** @} */
