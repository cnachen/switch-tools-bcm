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
    @defgroup grp_ethernet_swt_cfp_ifc Switch CFP abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_cfp_ifc
    @{

    @file ethernet_swt_cfp.h

    @brief CFP Interface
    This file contains the interfaces for the Ethernet abstract for CFP

    @version 1.0 Initial version
*/

#ifndef ETHSWT_ABSTRACT_CFP_H
#define ETHSWT_ABSTRACT_CFP_H

#include <ethernet_common.h>
#include <ethernet_swt_common.h>
#include <bcm_utils.h>

/**
    @name Ethernet Service CFP API IDs
    @{
    @brief API IDs for CFP in Ethernet Service
*/
#define BRCM_SWARCH_ETHSWT_CFP_MAX_PAYLOAD_SIZE_MACRO     (0x8601U) /**< @brief #ETHSWT_CFP_MAX_PAYLOAD_SIZE         */
#define BRCM_SWARCH_ETHSWT_CFPRULELIST_MAX_RULES_MACRO    (0x8602U) /**< @brief #ETHSWT_CFPRULELIST_MAX_RULES        */
#define BRCM_SWARCH_ETHSWT_CFP_CONFIG_MAGIC_ID_MACRO      (0x8603U) /**< @brief #ETHSWT_CFP_CONFIG_MAGIC_ID          */
#define BRCM_SWARCH_ETHSWT_CFP_MAX_FILESIZE_MACRO         (0x8604U) /**< @brief #ETHSWT_CFP_MAX_FILESIZE             */
#define BRCM_SWARCH_ETHSWT_CFPCMDID_TYPE                  (0x8605U) /**< @brief #ETHSWT_CFPCmdIdType                 */
#define BRCM_SWARCH_ETHSWT_CFP_ACTION_TYPE                (0x8606U) /**< @brief #ETHSWT_CFPActionDefsType            */
#define BRCM_SWARCH_ETHSWT_CFP_UDF_DEFS_TYPE              (0x8607U) /**< @brief #ETHSWT_CFPUDFDefsType               */
#define BRCM_SWARCH_ETHSWT_CFPASYNCID_TYPE                (0x8608U) /**< @brief #ETHSWT_CFPAsyncIdType               */
#define BRCM_SWARCH_ETHSWT_CFPSTREAMPOLICERACTION_TYPE    (0x8609U) /**< @brief #ETHSWT_CFPStreamPolicerActionType   */
#define BRCM_SWARCH_ETHSWT_CFPSTREAMPOLICERSTATE_TYPE     (0x860AU) /**< @brief #ETHSWT_CFPStreamPolicerStateType    */
#define BRCM_SWARCH_ETHSWT_CFP_PKTLENCORR_TYPE            (0x860BU) /**< @brief #ETHSWT_CFPPktLenCorrType            */
#define BRCM_SWARCH_ETHSWT_CFPSTREAMPOLICER_TYPE          (0x860CU) /**< @brief #ETHSWT_CFPStreamPolicerType         */
#define BRCM_SWARCH_ETHSWT_CFP_MAX_UDFS_MACRO             (0x860DU) /**< @brief #ETHSWT_CFP_MAX_UDFS                 */
#define BRCM_SWARCH_ETHSWT_CFP_MAX_SLICES_MACRO           (0x860EU) /**< @brief #ETHSWT_CFP_MAX_SLICES               */
#define BRCM_SWARCH_ETHSWT_CFP_NUM_FORMATS_MACRO          (0x860FU) /**< @brief #ETHSWT_CFP_NUM_FORMATS              */
#define BRCM_SWARCH_ETHSWT_CFP_UDF_ENTRY_TYPE             (0x8610U) /**< @brief #ETHSWT_CFPUDFEntryType              */
#define BRCM_SWARCH_ETHSWT_CFP_UDF_ALLOC_LIST_TYPE        (0x8611U) /**< @brief #ETHSWT_CFPUDFAllocListType          */
#define BRCM_SWARCH_ETHSWT_CFP_TABLESNAPSHOT_TYPE         (0x8612U) /**< @brief #ETHSWT_CFPTableSnapshotType         */
#define BRCM_SWARCH_ETHSWT_CFP_ENTRYSNAPSHOT_TYPE         (0x8613U) /**< @brief #ETHSWT_CFPEntrySnapshotType         */
#define BRCM_SWARCH_ETHSWT_CFPRULELIST_TYPE               (0x8614U) /**< @brief #ETHSWT_CFPRuleListType              */
#define BRCM_SWARCH_ETHSWT_CFPSTATS_TYPE                  (0x8615U) /**< @brief #ETHSWT_CFPStatsType                 */
#define BRCM_SWARCH_ETHSWT_CFPROWSTATS_TYPE               (0x8616U) /**< @brief #ETHSWT_CFPRowStatsType              */
#define BRCM_SWARCH_ETHSWT_CFPPORTMODE_TYPE               (0x8617U) /**< @brief #ETHSWT_CFPPortModeType              */
#define BRCM_SWARCH_ETHSWT_CFPSTREAM_TYPE                 (0x8618U) /**< @brief #ETHSWT_CFPStreamType                */
#define BRCM_SWARCH_ETHSWT_CFPSTREAMPOLICERSTATUS_TYPE    (0x8619U) /**< @brief #ETHSWT_CFPStreamPolicerStatusType   */
#define BRCM_SWARCH_ETHSWT_CFPSTREAMPOLICERSNAPSHOT_TYPE  (0x861AU) /**< @brief #ETHSWT_CFPStreamPolicerSnapshotType */
#define BRCM_SWARCH_ETHSWT_CFPSTREAMPOLICERCONFIG_TYPE    (0x861BU) /**< @brief #ETHSWT_CFPStreamPolicerConfigType   */
#define BRCM_SWARCH_ETHSWT_CFPMETER_TYPE                  (0x861CU) /**< @brief #ETHSWT_CFPMeterType                 */
#define BRCM_SWARCH_ETHSWT_CFPACTION_TYPE                 (0x861DU) /**< @brief #ETHSWT_CFPActionType                */
#define BRCM_SWARCH_ETHSWT_CFP_ROWANDSLICE_TYPE           (0x861EU) /**< @brief #ETHSWT_CFPRowAndSliceType           */
#define BRCM_SWARCH_ETHSWT_CFP_METER_TYPE                 (0x861FU) /**< @brief #ETHSWT_CFPMeterDefsType             */
#define BRCM_SWARCH_ETHSWT_CFP_POLICERMODE_TYPE           (0x8620U) /**< @brief #ETHSWT_CFPPolicerModeType           */
#define BRCM_SWARCH_ETHSWT_CFP_COLOR_TYPE                 (0x8621U) /**< @brief #ETHSWT_CFPColorType                 */
#define BRCM_SWARCH_ETHSWT_CFP_CHANGEFWDMAP_TYPE          (0x8622U) /**< @brief #ETHSWT_CFPChangeFwdMapType          */
#define BRCM_SWARCH_ETHSWT_CFP_UDF_TYPE                   (0x8623U) /**< @brief #ETHSWT_CFPUDFType                   */
#define BRCM_SWARCH_ETHSWT_CFP_L2FRAMING_TYPE             (0x8624U) /**< @brief #ETHSWT_CFPL2FramingType             */
#define BRCM_SWARCH_ETHSWT_CFP_L3FRAMING_TYPE             (0x8625U) /**< @brief #ETHSWT_CFPL3FramingType             */
#define BRCM_SWARCH_ETHSWT_CFPKEY_TYPE                    (0x8626U) /**< @brief #ETHSWT_CFPKeyType                   */
#define BRCM_SWARCH_ETHSWT_CFP_KEY_TYPE                   (0x8627U) /**< @brief #ETHSWT_CFPKeyDefsType               */
#define BRCM_SWARCH_ETHSWT_CFP_UDFBASE_TYPE               (0x8628U) /**< @brief #ETHSWT_CFPUDFBaseType               */
#define BRCM_SWARCH_ETHSWT_CFPRULE_TYPE                   (0x8629U) /**< @brief #ETHSWT_CFPRuleType                  */
#define BRCM_SWARCH_ETHSWT_CFPMSGUNION_TYPE               (0x862AU) /**< @brief #ETHSWT_CFPMsgUnionType              */
#define BRCM_SWARCH_ETHSWT_CFPCONFIG_TYPE                 (0x862BU) /**< @brief #ETHSWT_CFPConfigType                */
#define BRCM_SWARCH_ETHSWT_CFP_ID_OF_MACRO                (0x862CU) /**< @brief #ETHSWT_CFP_ID_OF                    */
#define BRCM_SWARCH_ETHSWT_CFPADD_PROC                    (0x862DU) /**< @brief #ETHSWT_CFPAdd                       */
#define BRCM_SWARCH_ETHSWT_CFPDELETE_PROC                 (0x862EU) /**< @brief #ETHSWT_CFPDelete                    */
#define BRCM_SWARCH_ETHSWT_CFPUPDATE_PROC                 (0x862FU) /**< @brief #ETHSWT_CFPUpdate                    */
#define BRCM_SWARCH_ETHSWT_CFPSTATS_PROC                  (0x8630U) /**< @brief #ETHSWT_CFPStats                     */
#define BRCM_SWARCH_ETHSWT_CFPGETROWCONFIG_PROC           (0x8631U) /**< @brief #ETHSWT_CFPGetRowConfig              */
#define BRCM_SWARCH_ETHSWT_CFPGETSNAPSHOT_PROC            (0x8632U) /**< @brief #ETHSWT_CFPGetSnapshot               */
#define BRCM_SWARCH_ETHSWT_CFPSETPORTMODE_PROC            (0x8633U) /**< @brief #ETHSWT_CFPSetPortMode               */
#define BRCM_SWARCH_ETHSWT_CFPADDPOLICER_PROC             (0x8634U) /**< @brief #ETHSWT_CFPAddPolicer                */
#define BRCM_SWARCH_ETHSWT_CFPDELETEPOLICER_PROC          (0x8635U) /**< @brief #ETHSWT_CFPDeletePolicer             */
#define BRCM_SWARCH_ETHSWT_CFPBLOCKPOLICER_PROC           (0x8636U) /**< @brief #ETHSWT_CFPBlockPolicer              */
#define BRCM_SWARCH_ETHSWT_CFPRESUMEPOLICER_PROC          (0x8637U) /**< @brief #ETHSWT_CFPResumePolicer             */
#define BRCM_SWARCH_ETHSWT_CFPGETSTRMPOLICER_PROC         (0x8638U) /**< @brief #ETHSWT_CFPGetStrmPolicer            */
#define BRCM_SWARCH_ETHSWT_CFPSNAPSHOTSTRMPOLICER_PROC    (0x8639U) /**< @brief #ETHSWT_CFPSnapshotStrmPolicer       */
#define BRCM_SWARCH_ETHSWT_CFPFINDPOLICER_PROC            (0x863AU) /**< @brief #ETHSWT_CFPFindPolicer               */
/** @} */

/**
    @brief Maximum size of CFP payload

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CFP_MAX_PAYLOAD_SIZE       (388UL)

/**
    @brief Total number of rules that is captured during
    a CFP snapshot

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CFPRULELIST_MAX_RULES   (384U)

/**
    @brief Magic number for the configuration structure, containing 'CFPC'

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CFP_CONFIG_MAGIC_ID      (0x43504643UL)

/** @brief CFP Maximum config file size

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CFP_MAX_FILESIZE       (1024 * 1024)

/**
    @brief Macro to Construct Ethernet CmdID

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CFP_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_CFP_ID, aId)

/**
    @name Switch CFP command IDs
    @{
    @brief Switch CFP command IDs group

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPCmdIdType;                    /**< @brief CFP command message Type                                    */
#define ETHSWT_CFPCMDID_ADDRULE                ETHSWT_CFP_ID_OF(0x90U)  /**< @brief #ETHSWT_CFPRuleType                  #ETHSWT_CFPAddRule     */
#define ETHSWT_CFPCMDID_REMOVERULE             ETHSWT_CFP_ID_OF(0x91U)  /**< @brief #ETHSWT_CFPRuleType                  #ETHSWT_CFPRemoveRule  */
#define ETHSWT_CFPCMDID_UPDATERULE             ETHSWT_CFP_ID_OF(0x92U)  /**< @brief #ETHSWT_CFPRuleType                  #ETHSWT_CFPUpdateRule  */
#define ETHSWT_CFPCMDID_GETSTATS               ETHSWT_CFP_ID_OF(0x93U)  /**< @brief #ETHSWT_CFPRowStatsType              #ETHSWT_CFPGetStats    */
#define ETHSWT_CFPCMDID_SETPORTMODE            ETHSWT_CFP_ID_OF(0x94U)  /**< @brief #ETHSWT_CFPPortModeType              #ETHSWT_CFPDisablePort */
#define ETHSWT_CFPCMDID_GETROWCONFIG           ETHSWT_CFP_ID_OF(0x95U)  /**< @brief #ETHSWT_CFPRuleType                  #ETHSWT_CFPGetRowConfig*/
#define ETHSWT_CFPCMDID_GETSNAPSHOT            ETHSWT_CFP_ID_OF(0x96U)  /**< @brief #ETHSWT_CFPTableSnapshotType         #ETHSWT_CFPGetSnapshot */
#define ETHSWT_CFPCMDID_GETRULELIST            ETHSWT_CFP_ID_OF(0x97U)  /**< @brief #ETHSWT_CFPRuleListType              #ETHSWT_CFPGetSnapshot */
#define ETHSWT_CFPCMDID_STREAMPOLICER_ADD      ETHSWT_CFP_ID_OF(0x98U)  /**< @brief #ETHSWT_CFPStreamType                #ETHSWT_CFPAddRule     */
#define ETHSWT_CFPCMDID_STREAMPOLICER_DEL      ETHSWT_CFP_ID_OF(0x99U)  /**< @brief #ETHSWT_CFPStreamType                #ETHSWT_CFPRemoveRule  */
#define ETHSWT_CFPCMDID_BLOCKSTREAM            ETHSWT_CFP_ID_OF(0x9AU)  /**< @brief #ETHSWT_CFPStreamType                #ETHSWT_CFPUpdateRule  */
#define ETHSWT_CFPCMDID_RESUMESTREAM           ETHSWT_CFP_ID_OF(0x9BU)  /**< @brief #ETHSWT_CFPStreamType                #ETHSWT_CFPUpdateRule  */
#define ETHSWT_CFPCMDID_STREAMPOLICER_FIND     ETHSWT_CFP_ID_OF(0x9CU)  /**< @brief #ETHSWT_CFPStreamType                #NA                    */
#define ETHSWT_CFPCMDID_STREAMPOLICER_GET      ETHSWT_CFP_ID_OF(0x9DU)  /**< @brief #ETHSWT_CFPStreamPolicerStatusType   #ETHSWT_CFPGetStats    */
#define ETHSWT_CFPCMDID_STREAMPOLICER_SNAPSHOT ETHSWT_CFP_ID_OF(0x9EU)  /**< @brief #ETHSWT_CFPStreamPolicerSnapshotType #NA                    */
/** @} */

/**
    @name CFP action definitions
    @{
    @brief Definitions for CFP action

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint16_t ETHSWT_CFPActionDefsType;                   /**< @brief typedef for CFP action definitions */
#define ETHSWT_CFP_ACTION_DSTMAP_SHIFT           (0UL)       /**< @brief Bit shift for destination map */
#define ETHSWT_CFP_ACTION_DSTMAP_MASK            (0xFFFFUL)  /**< @brief Mask for destination map */
#define ETHSWT_CFP_ACTION_P16ENABLE_SHIFT        (31UL)      /**< @brief Bit shift for enabling p16 in destination map */
#define ETHSWT_CFP_ACTION_P16ENABLE_MASK         (0x80000000UL)  /**< @brief Mask for enabling p16 in destination map */
#define ETHSWT_CFP_ACTION_CHANGE_FWDMAP_SHIFT    (16UL)      /**< @brief Bit shift for change of forward map */
#define ETHSWT_CFP_ACTION_CHANGE_FWDMAP_MASK     (0x30000UL) /**< @brief Mask for change of forward map */
#define ETHSWT_CFP_ACTION_TOS_SHIFT              (0U)        /**< @brief Bit shift for TOS */
#define ETHSWT_CFP_ACTION_TOS_MASK               (0x3FU)     /**< @brief Mask for TOS */
#define ETHSWT_CFP_ACTION_CHANGE_TOS_SHIFT       (6U)        /**< @brief Bit shift for changing TOS */
#define ETHSWT_CFP_ACTION_CHANGE_TOS_MASK        (0x40U)     /**< @brief Mask for changing TOS */
#define ETHSWT_CFP_ACTION_TC_SHIFT               (0U)        /**< @brief Bit shift for TC */
#define ETHSWT_CFP_ACTION_TC_MASK                (0x7U)      /**< @brief Mask for TC */
#define ETHSWT_CFP_ACTION_CHANGE_TC_SHIFT        (3U)        /**< @brief Bit shift for changing TC */
#define ETHSWT_CFP_ACTION_CHANGE_TC_MASK         (0x8U)      /**< @brief Mask for changing TC */
#define ETHSWT_CFP_ACTION_MIRROR_OB_SHIFT        (7U)        /**< @brief Bit shift for mirroring Out of band data */
#define ETHSWT_CFP_ACTION_MIRROR_OB_MASK         (0x80U)     /**< @brief Mask for mirroring out of band data */
#define ETHSWT_CFP_ACTION_MIRROR_IB_SHIFT        (6U)        /**< @brief Bit shift for mirroring In band data */
#define ETHSWT_CFP_ACTION_MIRROR_IB_MASK         (0x40U)     /**< @brief Mask for mirroring In band data */
#define ETHSWT_CFP_ACTION_MAC_LIMIT_BYPASS_SHIFT (5U)        /**< @brief Bit shift for MAC limit bypass */
#define ETHSWT_CFP_ACTION_MAC_LIMIT_BYPASS_MASK  (0x20U)     /**< @brief Mask for MAC limit bypass */
#define ETHSWT_CFP_ACTION_USE_DFLT_RED_SHIFT     (4U)        /**< @brief Bit shift for default RED profile */
#define ETHSWT_CFP_ACTION_USE_DFLT_RED_MASK      (0x10U)     /**< @brief Mask for default RED profile */
#define ETHSWT_CFP_ACTION_LPBK_EN_SHIFT          (3U)        /**< @brief Bit shift for enabling loopback */
#define ETHSWT_CFP_ACTION_LPBK_EN_MASK           (0x8U)      /**< @brief Mask for enabling loopback */
#define ETHSWT_CFP_ACTION_BYPASS_STP_SHIFT       (2U)        /**< @brief Bit shift for bypass STP */
#define ETHSWT_CFP_ACTION_BYPASS_STP_MASK        (0x4U)      /**< @brief Mask for bypass STP */
#define ETHSWT_CFP_ACTION_BYPASS_EAP_SHIFT       (1U)        /**< @brief Bit shift for bypass EAP */
#define ETHSWT_CFP_ACTION_BYPASS_EAP_MASK        (0x2U)      /**< @brief Mask for bypass EAP */
#define ETHSWT_CFP_ACTION_BYPASS_VLAN_SHIFT      (0U)        /**< @brief Bit shift for bypass VLAN */
#define ETHSWT_CFP_ACTION_BYPASS_VLAN_MASK       (0x1U)      /**< @brief Mask for bypass VLAN */
#define ETHSWT_CFP_ACTION_COLOR_SHIFT            (1U)        /**< @brief Bit shift for color */
#define ETHSWT_CFP_ACTION_COLOR_MASK             (0x6U)      /**< @brief Mask for color */
#define ETHSWT_CFP_ACTION_CHANGE_COLOR_SHIFT     (0U)        /**< @brief Bit shift for changing color */
#define ETHSWT_CFP_ACTION_CHANGE_COLOR_MASK      (0x1U)      /**< @brief Mask for changing color */
/** @} */


/**
    @name ETHSWT_CFPUDFDefsType
    @{
    @brief Definitions for UDF

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPUDFDefsType;               /**< @brief typedef for UDF definitions */
#define ETHSWT_CFP_UDF_DEFS_OFFSET_SHIFT     (0U)    /**< @brief Bit shift for the UDF offset field
                                                            in the baseAndOffset parameter */
#define ETHSWT_CFP_UDF_DEFS_OFFSET_MASK      (0x1FU) /**< @brief Mask for the UDF offset field in
                                                            the baseAndOffset parameter */
#define ETHSWT_CFP_UDF_DEFS_BASE_SHIFT       (5U)    /**< @brief Bit shift for the UDF base field in
                                                            the baseAndOffset parameter */
#define ETHSWT_CFP_UDF_DEFS_BASE_MASK        (0xE0U) /**< @brief Mask for the UDF base field in the
                                                            baseAndOffset parameter */
/** @} */

/**
    @name Switch CFP Async IDs
    @{
    @brief Switch CFP Async IDs group

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPAsyncIdType;
#define ETHSWT_CFPASYNCID_STREAM_EXCEEDED     (0x1U) /**< @brief Stream-exceed asynchronous notification */
/** @} */

/**
    @name ETHSWT_CFPStreamPolicerActionType
    @{
    @brief Policer action definitions
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPStreamPolicerActionType;        /**< @brief typedef for Stream policer action definitions */
#define ETHSWT_CFPSTREAMPOLICERACTION_BLOCK_SHIFT  (0U)   /**< @brief Bit shift for action block */
#define ETHSWT_CFPSTREAMPOLICERACTION_BLOCK_MASK   (0x1U) /**< @brief Mask for action block */
#define ETHSWT_CFPSTREAMPOLICERACTION_REPORT_SHIFT (1U)   /**< @brief Bit shift for action report */
#define ETHSWT_CFPSTREAMPOLICERACTION_REPORT_MASK  (0x2U) /**< @brief Mask for action report */
/** @} */

/**
    @name ETHSWT_CFPStreamPolicerStateType
    @{
    @brief Policer status definitions
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPStreamPolicerStateType;         /**< @brief typedef for Stream policer status definitions */
#define ETHSWT_CFPSTREAMPOLICERSTATE_VALID_SHIFT   (0U)   /**< @brief Bit shift for valid */
#define ETHSWT_CFPSTREAMPOLICERSTATE_VALID_MASK    (0x1U) /**< @brief Mask for valid */
#define ETHSWT_CFPSTREAMPOLICERSTATE_BLOCKED_SHIFT (1U)   /**< @brief Bit shift for blocked */
#define ETHSWT_CFPSTREAMPOLICERSTATE_BLOCKED_MASK  (0x2U) /**< @brief Mask for blocked */
#define ETHSWT_CFPSTREAMPOLICERSTATE_STATIC_SHIFT  (2U)   /**< @brief Bit shift for static */
#define ETHSWT_CFPSTREAMPOLICERSTATE_STATIC_MASK   (0x4U) /**< @brief Mask for static */
/** @} */

/**
    @name ETHSWT_CFPPktLenCorrType
    @{
    @brief Definitions for packet length correction for flow meter computations

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPPktLenCorrType;         /**< @brief typedef for packet
                                                        length correction */
#define ETHSWT_CFP_PKTLENCORR_NONE            (0U) /**< @brief No packet length
                                                        correction */
#define ETHSWT_CFP_PKTLENCORR_ADD_PRE_SFD     (1U) /**< @brief Add Preamble and SFD to
                                                        packet length */
#define ETHSWT_CFP_PKTLENCORR_ADD_PRE_SFD_IFG (2U) /**< @brief Add Preamble, SFD and
                                                        IFG to packet length */
/** @} */


/**
    @brief Switch Port configuration
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPStreamPolicerType {
    uint32_t                      rate;               /**< @brief Policer committed information rate in Kbps */
    uint32_t                      burstSize;          /**< @brief Policer committed burst size in bytes */
    uint32_t                      dropThreshold;      /**< @brief Number of packets which are allowed to exceed the
                                                           bandwidth before the stream is blocked/reported */
    uint32_t                      monitoringInterval; /**< @brief Number of system ticks to be used as the polling
                                                           interval for checking if dropThreshold is exceeded */
    uint32_t                      portMask;           /**< @brief Ingress port mask */
    uint16_t                      arlEntryIndex;      /**< @brief Index (in ARL table) of associated ARL entry */
    ETHSWT_CFPStreamPolicerActionType action;             /**< @brief Policer action to be taken on exceeding dropThreshold */
    uint8_t                       reserved;           /**< @brief Reserved */
} ETHSWT_CFPStreamPolicerType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPStreamPolicerType, 24UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief CFP MAX UDFS
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CFP_MAX_UDFS             (9U)    /**< @brief Total number of UDFs per rule */

/**
    @brief CFP MAX SLICES
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CFP_MAX_SLICES           (3U)    /**< @brief Total number of slices */

/**
    @brief CFP NUM FORMATS
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CFP_NUM_FORMATS          (3UL)   /**< @brief Number of supported formats */

/**
    @brief Structure for global UDF allocation
    This stores the global UDF information, including the address it is mapped
    to

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPUDFEntryType {
    uint8_t  enable;                                 /**< @brief Flag indicating
                                                          whether the UDF is
                                                          enabled or not */
    uint8_t  address;                                /**< @brief Address (base
                                                           and offset) of the
                                                           UDF */
} ETHSWT_CFPUDFEntryType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPUDFEntryType, 2UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief List of all allocated global UDFs per format

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPUDFAllocListType {
    ETHSWT_CFPUDFEntryType udfs[ETHSWT_CFP_MAX_SLICES][ETHSWT_CFP_MAX_UDFS]; /**< @brief Array of all
                                                                                   UDFs across all
                                                                                   slices for a
                                                                                   particular format */
} ETHSWT_CFPUDFAllocListType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPUDFAllocListType, 54UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP table snapshot

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPTableSnapshotType {
    uint32_t                    numValidEntries;                 /**< @brief Number of valid entries */
    ETHSWT_CFPUDFAllocListType  udfList[ETHSWT_CFP_NUM_FORMATS]; /**< @brief List of allocated UDFs per format */
    uint16_t                    portEnableMask;                  /**< @brief Bitmask of ports where CFP
                                                                      lookup is enabled. Note that P16 will not
                                                                      be a part of this bitmask. The user can
                                                                      assume that P16 is enabled */
} ETHSWT_CFPTableSnapshotType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPTableSnapshotType, 168UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @name ETHSWT_CFPEntrySnapshotType
    @{
    @brief Definitions for CFP entry snapshot

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPEntrySnapshotType;           /**< @brief typedef for entry snapshot field definitions */
#define ETHSWT_CFP_ENTRYSNAPSHOT_ENABLE_MASK   (0x80U) /**< @brief Mask for the enable field in the entry snapshot */
#define ETHSWT_CFP_ENTRYSNAPSHOT_ENABLE_SHIFT  (7U)    /**< @brief Bit shift for the enable field in the entry snapshot */
#define ETHSWT_CFP_ENTRYSNAPSHOT_STATIC_MASK   (0x40U) /**< @brief Mask for the static field in the entry snapshot */
#define ETHSWT_CFP_ENTRYSNAPSHOT_STATIC_SHIFT  (6U)    /**< @brief Bit shift for the static field in the entry snapshot */
#define ETHSWT_CFP_ENTRYSNAPSHOT_SLICE_MASK    (0x30U) /**< @brief Mask for the slice field in the entry snapshot */
#define ETHSWT_CFP_ENTRYSNAPSHOT_SLICE_SHIFT   (4U)    /**< @brief Bit shift for the slice field in the entry snapshot */
#define ETHSWT_CFP_ENTRYSNAPSHOT_FORMAT_MASK   (0xCU)  /**< @brief Mask for the format field in the entry snapshot */
#define ETHSWT_CFP_ENTRYSNAPSHOT_FORMAT_SHIFT  (2U)    /**< @brief Bit shift for the format field in the entry snapshot */
/** @} */

/**
    @brief Structure to fetch CFP rules

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPRuleListType {
    uint32_t                    num ;          /**< @brief Index for rule fetch OR the number of rules that was filled */
    ETHSWT_CFPEntrySnapshotType entry[ETHSWT_CFPRULELIST_MAX_RULES];
                                               /**< @brief Table of per row snapshot
                                                    encoded in a bitfield as follows:
                                                    Enable (1) | Static (1) | Slice(2) | Format(2) | Resv(2) */
} ETHSWT_CFPRuleListType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPRuleListType, 388UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP statistics

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPStatsType {
    uint32_t green;  /**< @brief Green counter */
    uint32_t yellow; /**< @brief Yellow counter */
    uint32_t red;    /**< @brief Red counter */
} ETHSWT_CFPStatsType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPStatsType, 12UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the CFP statistics.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPRowStatsType {
    uint32_t            row;    /**< @brief Row number */
    ETHSWT_CFPStatsType stats;  /**< @brief Statistics */
} ETHSWT_CFPRowStatsType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPRowStatsType, 16UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage the CFP port mode.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPPortModeType {
    uint32_t port;             /**< @brief Port number */
    uint32_t mode;             /**< @brief Mode */
} ETHSWT_CFPPortModeType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPPortModeType, 8UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage stream policer

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPStreamType {
    uint8_t                       macAddr[6];    /**< @brief MAC address */
    ETHER_VLANIDType              vlanID;        /**< @brief CFP ID */
    ETHSWT_CFPStreamPolicerType   policerParams; /**< @brief Policer parameters */
    uint32_t                      streamIdx;     /**< @brief Stream index */
} ETHSWT_CFPStreamType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPStreamType, 36UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Stream policer status
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPStreamPolicerStatusType {
    uint32_t idx;            /**< @brief Stream index */
    uint8_t  macAddress[6U]; /**< @brief Destination MAC address */
    uint16_t vlan;           /**< @brief CFP identifier */
    uint32_t portMask;       /**< @brief Ingress port mask */
    uint32_t blocked;        /**< @brief Flag indicating whether the stream is blocked or functional */
    uint32_t isStatic;       /**< @brief Flag indicating whether the stream is static or not */
    uint32_t greenCntr;      /**< @brief Number of InBand frames */
    uint32_t redCntr;        /**< @brief Number of OutOfBand frames */
} ETHSWT_CFPStreamPolicerStatusType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPStreamPolicerStatusType, 32UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Stream policer snapshot
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CFPStreamPolicerSnapshotType {
    ETHSWT_CFPStreamPolicerStateType policer[ETHSWT_CFP_MAX_STREAM_POLICER_ENTRIES]; /**< @brief Stream policer state */
} ETHSWT_CFPStreamPolicerSnapshotType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPStreamPolicerSnapshotType, 256UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief CFP Configuration Type

    @trace #BRCM_SWREQ_ETHSWT
 */
typedef struct COMP_PACKED sETHSWT_CFPStreamPolicerConfigType {
    ETHSWT_CFPStreamPolicerType     streamPolicers[ETHSWT_CFP_MAX_STREAM_POLICER_ENTRIES];
                                                             /**< @brief Stream policers */
    uint32_t                        numStreamPolicers;       /**< @brief Number of stream policers */
} ETHSWT_CFPStreamPolicerConfigType;

/**
    @brief Structure for CFP Meter

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_CFPMeterType {
    uint32_t   cirTkBkt;     /**< @brief Committed token bucket size */
    uint32_t   cirBktSize;   /**< @brief Committed burst size */
    uint32_t   cirRefCnt;    /**< @brief Committed information rate */
    uint32_t   eirTkBkt;     /**< @brief Excess token bucket size */
    uint32_t   eirBktSize;   /**< @brief Excess burst size */
    uint32_t   eirRefCnt;    /**< @brief Excess information rate */
    uint8_t    policerFlags; /**< @brief Policer flags encoded as follows:
                                  For CFP:  bit7  : Reserved
                                            bit6  : Enable mark all frames red
                                            bit5  : Drop yellow frames
                                            bit3-4: Policer mode
                                            bit2  : Coupling flag
                                            bit1  : Action
                                            bit0  : Color mode
                              */
} ETHSWT_CFPMeterType;

/**
    @brief Structure for CFP Action

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_CFPActionType {
    ETHSWT_CFPMeterType   meter;   /**< @brief CFP meter */
    uint32_t        dstMapIBFlags; /**< @brief Destination map flags for In-bandwidth
                                        profile traffic encoded as follows:
                                        p16Enable(1) | resv(13) | changeFwdMap(2) | dstMap(16) */
    uint32_t        dstMapOBFlags; /**< @brief Destination map flags for Out-bandwidth
                                        profile traffic encoded as follows:
                                        p16Enable(1) | resv(13) | changeFwdMap(2) | dstMap(16) */
    uint8_t         tosIBFlags;    /**< @brief TOS flags for In-bandwidth profile
                                        traffic encoded as follows:
                                        resv(1) | changeTOS(1) | newTOS (6) */
    uint8_t         tosOBFlags;    /**< @brief TOS flags for Out-bandwidth profile
                                        traffic encoded as follows:
                                        resv(1) | changeTOS(1) | newTOS (6) */
    uint8_t         tcFlags;       /**< @brief TC flags encoded as follows:
                                        resv(4) | changeTC(1) | newTC (3) */
    uint8_t         reasonCode;    /**< @brief Reason code */
    uint8_t         otherFlags;    /**< @brief Fields encoded as follows:
                                        mirOB(1) | mirIB(1) | MAC limit bypass(1) | RED dflt(1) |
                                        lpbkEn(1) | bypassSTP(1) | bypassEAP(1) | bypassVLAN(1) */
    uint8_t         colorFlags;    /**< @brief Color flags encoded as follows:
                                        resv(5) | color(2) | changeColor(1) */
    uint16_t        chainID;       /**< @brief chain ID */
    uint8_t         rsv[3];        /**< @brief For structure size to be 4 byte aligned @xsd rsvd
                                        Note: IPC message size needs to be a multiple of 4 bytes */
} ETHSWT_CFPActionType;

/**
    @name CFP encoded CFP row and slice definitions
    @{
    @brief Definitions for encoded CFP row and slice

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint16_t ETHSWT_CFPRowAndSliceType;             /**< @brief typedef for CFP encoded row and slice */
#define ETHSWT_CFP_ROWANDSLICE_ROW_SHIFT      (0U)      /**< @brief Bit shift for row number */
#define ETHSWT_CFP_ROWANDSLICE_ROW_MASK       (0xFFFU)  /**< @brief Mask for row number */
#define ETHSWT_CFP_ROWANDSLICE_SLICE_SHIFT    (12U)     /**< @brief Bit shift for slice number */
#define ETHSWT_CFP_ROWANDSLICE_SLICE_MASK     (0x3000U) /**< @brief Mask for slice number */
/** @} */

/**
    @name Meter definitions
    @{
    @brief Definitions for CFP meter

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_CFPMeterDefsType;          /**< @brief typedef for meter definitions */
#define ETHSWT_CFP_METER_TKBKT_SHIFT    (0UL)        /**< @brief Bit shift for token bucket size */
#define ETHSWT_CFP_METER_TKBKT_MASK     (0x7FFFFFUL) /**< @brief Mask for token bucket size */
#define ETHSWT_CFP_METER_BKTSZ_SHIFT    (0UL)        /**< @brief Bit shift for burst size */
#define ETHSWT_CFP_METER_BKTSZ_MASK     (0xFFFFFUL)  /**< @brief Mask for burst size */
#define ETHSWT_CFP_METER_REFCNT_SHIFT   (0UL)        /**< @brief Bit shift for reference count */
#define ETHSWT_CFP_METER_REFCNT_MASK    (0x7FFFFUL)  /**< @brief Mask for reference count */
#define ETHSWT_CFP_METER_CM_MASK        (0x1UL)      /**< @brief Mask for color mode */
#define ETHSWT_CFP_METER_CM_SHIFT       (0UL)        /**< @brief Bit shift for color mode */
#define ETHSWT_CFP_METER_ACT_MASK       (0x2UL)      /**< @brief Mask for meter action mode */
#define ETHSWT_CFP_METER_ACT_SHIFT      (1UL)        /**< @brief Bit shift for meter action mode */
#define ETHSWT_CFP_METER_CF_MASK        (0x4UL)      /**< @brief Mask for coupling flag */
#define ETHSWT_CFP_METER_CF_SHIFT       (2UL)        /**< @brief Bit shift for coupling flag */
#define ETHSWT_CFP_METER_MODE_MASK      (0x18UL)     /**< @brief Mask for policer mode */
#define ETHSWT_CFP_METER_MODE_SHIFT     (3UL)        /**< @brief Bit shift for policer mode */
#define ETHSWT_CFP_METER_YELLOW_MASK    (0x20UL)     /**< @brief Mask for drop yellow frames */
#define ETHSWT_CFP_METER_YELLOW_SHIFT   (5UL)        /**< @brief Bit shift for drop yellow frames */
#define ETHSWT_CFP_METER_MARK_RED_EN_MASK  (0x40UL)  /**< @brief Mask for mark all frames red */
#define ETHSWT_CFP_METER_MARK_RED_EN_SHIFT (6UL)     /**< @brief Bit shift for mark all frame red */
/** @} */

/**
    @name ETHSWT_CFPPolicerModeType
    @{
    @brief Definitions for policer mode

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPPolicerModeType;   /**< @brief typedef for policer mode */
#define ETHSWT_CFP_POLICERMODE_RFC2698  (0U) /**< @brief Policer compliant with RFC2698 */
#define ETHSWT_CFP_POLICERMODE_RFC4115  (1U) /**< @brief Policer compliant with RFC4115 */
#define ETHSWT_CFP_POLICERMODE_MEF      (2U) /**< @brief Policer compliant with MEF */
#define ETHSWT_CFP_POLICERMODE_DISABLED (3U) /**< @brief Policer disabled */
/** @} */

/**
    @name ETHSWT_CFPColorType
    @{
    @brief Definitions for color

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPColorType;           /**< @brief typedef for color */
#define ETHSWT_CFP_COLOR_GREEN            (0U) /**< @brief Green color */
#define ETHSWT_CFP_COLOR_YELLOW           (1U) /**< @brief Yellow color */
#define ETHSWT_CFP_COLOR_RED              (2U) /**< @brief Red color */
/** @} */


/**
    @name ETHSWT_CFPChangeFwdMapType
    @{
    @brief Definitions for changing the forwarding map

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_CFPChangeFwdMapType;    /**< @brief typedef for changing
                                                        forwarding map */
#define ETHSWT_CFP_CHANGEFWDMAP_NON       (0UL) /**< @brief No change */
#define ETHSWT_CFP_CHANGEFWDMAP_REM       (1UL) /**< @brief Remove ARL destinations */
#define ETHSWT_CFP_CHANGEFWDMAP_REP       (2UL) /**< @brief Replace ARL destinations */
#define ETHSWT_CFP_CHANGEFWDMAP_ADD       (3UL) /**< @brief Add ARL destinations */
/** @} */


/**
    @brief Structure for CFP UDF

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_CFPUDFType {
    uint16_t  value;         /**< @brief Value of the UDF */
    uint16_t  mask;          /**< @brief Value of the UDF mask */
    uint8_t   baseAndOffset; /**< @brief Base and offset of
                                   the UDF encoded in a
                                   byte as follows:
                                   base(3) | offset (5)   */
} ETHSWT_CFPUDFType;

/**
    @name ETHSWT_CFPL2FramingType
    @{
    @brief Definitions for L2 framing

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPL2FramingType;      /**< @brief typedef for L2 framing type */
#define ETHSWT_CFP_L2FRAMING_DIXV2       (0U) /**< @brief DIXv2 */
#define ETHSWT_CFP_L2FRAMING_SNAP_PUB    (1U) /**< @brief SNAP Public */
#define ETHSWT_CFP_L2FRAMING_LLC         (2U) /**< @brief LLC */
#define ETHSWT_CFP_L2FRAMING_SNAP_PVT    (3U) /**< @brief SNAP Private */
/** @} */

/**
    @name ETHSWT_CFPL3FramingType
    @{
    @brief Definitions for L3 framing

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPL3FramingType;      /**< @brief typedef for L2 framing type */
#define ETHSWT_CFP_L3FRAMING_IPV4        (0U) /**< @brief IPv4 */
#define ETHSWT_CFP_L3FRAMING_IPV6        (1U) /**< @brief IPv6 */
#define ETHSWT_CFP_L3FRAMING_NONIP       (3U) /**< @brief non-IP */
/** @} */

/**
    @brief Structure for CFP TCAM key

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_CFPKeyType {
    uint32_t           flags;             /**< @brief Overloaded flags field
                                               Encoded as follows for non-IP:
                                               p16Enable(1) | resv(15) | ethType(16)
                                               Encoded as follows for IPv4/IPv6:
                                               p16Enable(1) | resv(10) / tos(8) / proto(8) / frag(1) / non-first-frag(1) /
                                               auth(1) / TTL(2) */
    uint32_t           flagsMask;         /**< @brief Mask for flags field */
    uint32_t           cTagFlags;         /**< @brief C-Tag Vlan and Status
                                               encoded in a bitfield as follows:
                                               Resv(8)| VLAN-Tagged(1) | Priority-Tagged(1) | Un-Tagged(1)|
                                               PCP Valid (1) | DEI Valid (1) | C-Vid Valid (1) | PCP (3) |
                                               DEI (1) | C-Vid(12) | Resv(2)*/
    uint16_t           cTagMask;          /**< @brief Mask for Vlan and PCP field in C-Tag
                                               PCP Mask(3) | Resv(1) | VLAN-ID Mask(12) */
    uint32_t           sTagFlags;         /**< @brief S-Tag Vlan and Status
                                               encoded in a bitfield as follows:
                                               Resv(8)| VLAN-Tagged(1) | Priority-Tagged(1) | Un-Tagged(1) |
                                               PCP Valid (1) | DEI Valid (1) | S-Vid Valid (1) | PCP (3) |
                                               DEI (1) | S-Vid(12) | Resv(2)*/
    uint16_t           sTagMask;          /**< @brief Mask for Vlan and PCP field in S-Tag
                                               PCP Mask(3) | Resv(1) | VLAN-ID Mask(12) */
    uint16_t           ingressPortBitmap; /**< @brief Bitmap representing the
                                               ingress ports to which the rule
                                               applies */
    ETHSWT_CFPUDFType  udfList[ETHSWT_CFP_MAX_UDFS]; /**< @brief List of UDFs for the
                                                          rule */
    uint8_t             numEnabledUDFs;         /**< @brief Number of enabled UDFs
                                                     for the rule  */
    ETHSWT_CFPL2FramingType  l2Framing;         /**< @brief L2 framing */
    ETHSWT_CFPL3FramingType  l3Framing;         /**< @brief L3 framing, used to
                                                     decide the slice type */
} ETHSWT_CFPKeyType;

/**
    @name CFP TCAM key definitions
    @{
    @brief Definitions for TCAM Key

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_CFPKeyDefsType;                    /**< @brief typedef for TCAM key definitions */
#define ETHSWT_CFP_KEY_TTL_MASK               (0x3UL)      /**< @brief Mask for the TTL field in the flags parameter */
#define ETHSWT_CFP_KEY_TTL_SHIFT              (0UL)        /**< @brief Bit shift for the TTL field in the flags parameter */
#define ETHSWT_CFP_KEY_AUTH_MASK              (0x4UL)      /**< @brief Mask for the IP authentication field in the flags parameter */
#define ETHSWT_CFP_KEY_AUTH_SHIFT             (2UL)        /**< @brief Bit shift for the IP authentication field in the flags parameter */
#define ETHSWT_CFP_KEY_NONFIRSTFRAG_MASK      (0x8UL)      /**< @brief Mask for the non first fragment field in the flags parameter */
#define ETHSWT_CFP_KEY_NONFIRSTFRAG_SHIFT     (3UL)        /**< @brief Bit shift for the non first fragment field in the flags parameter */
#define ETHSWT_CFP_KEY_FRAG_MASK              (0x10UL)     /**< @brief Mask for the fragmentation field in the flags parameter */
#define ETHSWT_CFP_KEY_FRAG_SHIFT             (4UL)        /**< @brief Bit shift for the fragmentation field in the flags parameter */
#define ETHSWT_CFP_KEY_PROTO_MASK             (0x1FE0UL)   /**< @brief Mask for the protocol field in the flags parameter */
#define ETHSWT_CFP_KEY_PROTO_SHIFT            (5UL)        /**< @brief Bit shift for the protocol field in the flags parameter */
#define ETHSWT_CFP_KEY_TOS_MASK               (0x1FE000UL) /**< @brief Mask for the TOS (type of service) field in the flags parameter */
#define ETHSWT_CFP_KEY_TOS_SHIFT              (13UL)       /**< @brief Bit shift for the TOS (type of service) field in the flags parameter */
#define ETHSWT_CFP_KEY_IP_MASK                (0x1FFFFFUL) /**< @brief Mask for the IP fields in the flags parameter */
#define ETHSWT_CFP_KEY_ETHTYPE_MASK           (0xFFFFUL)   /**< @brief Mask for the Ethertype field in the flags parameter */
#define ETHSWT_CFP_KEY_ETHTYPE_SHIFT          (0UL)        /**< @brief Bit shift for the Ethertype field in the flags parameter */
#define ETHSWT_CFP_KEY_P16ENABLE_MASK         (0x80000000UL)   /**< @brief Mask for the Enabling port 16 in the rule */
#define ETHSWT_CFP_KEY_P16ENABLE_SHIFT        (31UL)       /**< @brief Shift for the Enabling port 16 in the rule */
#define ETHSWT_CFP_KEY_NONIP_MASK             (0xFFFFUL)   /**< @brief Mask for the non-IP fields in the flags parameter */
#define ETHSWT_CFP_KEY_TAG_UN_TAGGED_MASK     (0x200000UL) /**< @brief Mask for the Un-Tagged field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_UN_TAGGED_SHIFT    (21UL)       /**< @brief Bit shift for Un-Tagged field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_PRIO_TAGGED_MASK   (0x400000UL) /**< @brief Mask for the Priority-Tagged field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_PRIO_TAGGED_SHIFT  (22UL)       /**< @brief Bit shift for Priority-Tagged field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_VLAN_TAGGED_MASK   (0x800000UL) /**< @brief Mask for the VLAN-Tagged field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_VLAN_TAGGED_SHIFT  (23UL)       /**< @brief Bit shift for VLAN-Tagged field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_ID_MASK            (0x3FFCUL)   /**< @brief Mask for the id field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_ID_SHIFT           (2UL)        /**< @brief Bit shift for the id field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_DEI_MASK           (0x4000UL)   /**< @brief Mask for the DEI field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_DEI_SHIFT          (14UL)       /**< @brief Bit shift for the DEI field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_PCP_MASK           (0x38000UL)  /**< @brief Mask for the PCP field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_PCP_SHIFT          (15UL)       /**< @brief Bit shift for the PCP field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_ID_VALID_MASK      (0x40000UL)  /**< @brief Mask for the VLAN id valid field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_ID_VALID_SHIFT     (18UL)       /**< @brief Bit shift for the VLAN id valid field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_DEI_VALID_MASK     (0x80000UL)  /**< @brief Mask for the DEI valid field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_DEI_VALID_SHIFT    (19UL)       /**< @brief Bit shift for the DEI valid field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_PCP_VALID_MASK     (0x100000UL) /**< @brief Mask for the PCP valid field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_PCP_VALID_SHIFT    (20UL)       /**< @brief Bit shift for the PCP valid field in the tag parameter */
#define ETHSWT_CFP_KEY_TAG_PCPMASK_MASK       (0xE000U)    /**< @brief Mask for the PCP Mask field in the cTagMask parameter */
#define ETHSWT_CFP_KEY_TAG_PCPMASK_SHIFT      (13U)        /**< @brief Bit shift for the PCP Mask field in the cTagMask parameter */
#define ETHSWT_CFP_KEY_TAG_IDMASK_MASK        (0xFFFU)     /**< @brief Mask for the VLAN-ID Mask field in the cTagMask parameter */
#define ETHSWT_CFP_KEY_TAG_IDMASK_SHIFT       (0U)         /**< @brief Bit shift for the VLAN-ID Mask field in the cTagMask parameter */
/** @} */

/**
    @name ETHSWT_CFPUDFBaseType
    @{
    @brief UDF Base definitions

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CFPUDFBaseType;             /**< @brief typedef for UDF Base */
#define ETHSWT_CFP_UDFBASE_SOP                (0U) /**< @brief Start of Packet */
#define ETHSWT_CFP_UDFBASE_ENDL2HDR           (2U) /**< @brief End of L2 header */
#define ETHSWT_CFP_UDFBASE_ENDL3HDR           (3U) /**< @brief End of L3 header  */
/** @} */

/**
    @brief Structure for CFP Rule

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_CFPRuleType {
    ETHSWT_CFPKeyType         key;         /**< @brief key */
    ETHSWT_CFPActionType      action;      /**< @brief action */
    ETHSWT_CFPRowAndSliceType rowAndSlice; /**< @brief row and slice number encoded as follows:
                                                    resv(2) | slice (2) | row (12) */
} ETHSWT_CFPRuleType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPRuleType, 116UL, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Vlan Union encapsulating all messages

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef union uETHSWT_CFPMsgUnionType {
    uint32_t                            data[ETHSWT_CFP_MAX_PAYLOAD_SIZE/4UL]; /**< @brief CFP data */
    ETHSWT_CFPRuleType                  cfpRule;               /**< @brief CFP Rule */
    ETHSWT_CFPTableSnapshotType         cfpSnapshot;           /**< @brief CFP Table Sanpshot */
    ETHSWT_CFPRuleListType              cfpRuleList;           /**< @brief CFP Rule list */
    ETHSWT_CFPRowStatsType              cfpStats;              /**< @brief CFP Statistics */
    ETHSWT_CFPPortModeType              cfpPortMode;           /**< @brief CFP Port mode */
    ETHSWT_CFPStreamType                streamPolicerEntry;    /**< @brief Stream Policer Entry */
    ETHSWT_CFPStreamPolicerSnapshotType streamPolicerSnapshot; /**< @brief Stream Policer Snapshot */
    ETHSWT_CFPStreamPolicerStatusType   streamPolicerStatus;   /**< @brief Stream Policer Status */
} ETHSWT_CFPMsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CFPMsgUnionType, ETHSWT_CFP_MAX_PAYLOAD_SIZE, ETHSWT_CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_CFPConfigType {
    uint32_t                    magicId;                        /**< @brief Magic number 'CFPC'
                                                                        (checked for validity) */
    ETHSWT_CFPRuleType          ruleList[ETHSWT_CFP_MAX_INIT_RULES];
                                                                /**< @brief List of rules  */
    uint16_t                    ruleListSz;                     /**< @brief Number of valid
                                                                        rules */
    ETHSWT_CFPPktLenCorrType    pktLenCorr;                     /**< @brief Packet length
                                                                        correction */
    uint16_t                    portEnableMask;                 /**< @brief Bitmask of ports
                                                                        where CFP lookup is
                                                                        enabled */
} ETHSWT_CFPConfigType;

/**
    @brief Add a CFP rule

    This API adds a rule to CFP TCAM and returns #aRow and #aSlice

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[inout]  aRow                Pointer to the requested row number (set to ETHSWT_CFP_MAX_RULES
                                       in case the driver needs to allocate) on input. On output
                                       it provides the configured row number
    @param[inout]  aSlice              Pointer to the requested slice number(set to ETHSWT_CFP_MAX_SLICES
                                       in case the driver needs to allocate) on input. On output
                                       it provides the configured slice number
    @param[in]     aRule               Rule configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Rule programmed successfully in CFP block
    @retval  #BCM_ERR_INVAL_PARAMS     #aRule/#aRow/#aSlice is NULL OR
                                       #aRow or #aSlice is invalid value OR
                                       Configuration provided is invalid
    @retval  #BCM_ERR_NOMEM            All rows in TCAM are occupied or unable
                                       to find a slice where the UDFs for this
                                       rule can be accomodated
    @retval  #BCM_ERR_NOPERM           Static rule configured at row which is
                                       being requested in aRule
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPAdd(BCM_HandleType aConnHdl, uint32_t* const aRow,
                               uint32_t* const aSlice, const ETHSWT_CFPRuleType* const aRule);

/**
    @brief Remove a CFP rule

    This API removes a rule (if it exists) from the CFP block. It also frees up
    any UDFs which are no longer used after deletion of this rule. This API returns
    an error in case an attempt to delete a static rule is made

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aRow                Row number

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Rule removed successfully from CFP block
    @retval  #BCM_ERR_INVAL_PARAMS     #aRow is not a valid CFP row number
    @retval  #BCM_ERR_NOT_FOUND        No rule configured at aRow
    @retval  #BCM_ERR_NOPERM           Static rule configured at aRow
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPDelete(BCM_HandleType aConnHdl, uint32_t aRow);

/**
    @brief Update a CFP rule

    This API updates an existing rule in the CFP block. Only the action policy
    RAM is updated. This API returns an error in case an attempt to update a
    static rule is made

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aRow                Row number
    @param[in]     aRule               Rule configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Action policy RAM successfully updated
    @retval  #BCM_ERR_INVAL_PARAMS     #aRow is not a valid CFP row number
                                       #aRule is NULL or has invalid configuration
    @retval  #BCM_ERR_NOT_FOUND        No rule configured at aRow
    @retval  #BCM_ERR_NOPERM           Static rule configured at aRow
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPUpdate(BCM_HandleType aConnHdl, uint32_t aRow,
                                      const ETHSWT_CFPRuleType* const aRule);

/**
    @brief Get statistic counters for a CFP rule

    This API fetches the red, yellow and green statistic counters for an
    existing CFP rule

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[in]     aRow              Row number
    @param[out]    aStats            Pointer to location to store Row statistics

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Statistics fetched successfully
    @retval  #BCM_ERR_INVAL_PARAMS   #aRow is not a valid CFP row number
                                     #aStats is NULL
    @retval  #BCM_ERR_INVAL_STATE    CFP is not in initialized state
    @retval  #BCM_ERR_NOT_FOUND      No rule configured at aRow
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPStats(BCM_HandleType aConnHdl, uint32_t aRow,
                                      ETHSWT_CFPRowStatsType *const aStats);

/**
    @brief Get configuration for a CFP rule

    This API fetches the configuration for an existing CFP rule

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl         Connection handle (from RPC_Connect)
    @param[in]     aRow             Row number
    @param[out]    aConfig          Pointer to location to store configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK            Configuration fetched successfully
    @retval  #BCM_ERR_INVAL_PARAMS  #aConfig is NULL or has invalid configuration
                                    #aRow is not a valid CFP row
    @retval  #BCM_ERR_NOT_FOUND     No rule configured at aRow
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPGetRowConfig(BCM_HandleType aConnHdl, uint32_t aRow,
                                            ETHSWT_CFPRuleType *const aConfig);
/**
    @brief Get summarised snapshot of the CFP table

    This API fetches the summarised snapshot of the CFP table

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[out]    aSnapshot         Pointer to location to store table snapshot
    @param[out]    aRuleList         Pointer to location to store Table of per row

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Snapshot fetched successfully
    @retval  #BCM_ERR_INVAL_PARAMS   #aSnapshot is NULL or #aID is invalid
    @retval  #BCM_ERR_INVAL_STATE    CFP is not in initialized state
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPGetSnapshot(BCM_HandleType aConnHdl,
                                          ETHSWT_CFPTableSnapshotType *const aSnapshot,
                                          ETHSWT_CFPRuleListType *const aRuleList);

/**
    @brief Control CFP lookup on a port

    This API enables/disables CFP lookup on a port

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[in]     aPortNum          Port number
    @param[in]     aMode             Mode 1:Enable 0:Disable

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK             Port enabled successfully
    @retval  #BCM_ERR_INVAL_PARAMS   port number is invalid
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPSetPortMode(BCM_HandleType aConnHdl, uint32_t aPortNum, uint32_t aMode);

/**
    @brief Add a Stream policer

    This API adds a stream policer

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]   aConnHdl        Connection handle (from RPC_Connect)
    @param[in]   aMacAddr        MAC address
    @param[in]   aVlanID         VLAN ID
    @param[in]   aCfg            Configuration pointer
    @param[out]  aStreamIdx      Pointer to Index of allocated slot

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Added successfully
    @retval     #BCM_ERR_NOMEM           No memory
    @retval     #BCM_ERR_INVAL_PARAMS    aMacAddr is NULL OR
                                         aCfg is NULL OR
                                         aStreamIdx is NULL
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPAddPolicer(BCM_HandleType aConnHdl,  const uint8_t *const aMacAddr,
                                       uint16_t aVlanID, const ETHSWT_CFPStreamPolicerType* const aCfg,
                                       uint32_t *const aStreamIdx);

/**
    @brief Delete Stream policer

    This API deletes a stream policer

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]   aConnHdl          Connection handle (from RPC_Connect)
    @param[in]   aStreamIdx        Index of the stream to be deleted

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Stream policer deleted successfully
    @retval     #BCM_ERR_NOT_FOUND     Stream not found at the provided index
    @retval     #BCM_ERR_NOPERM        Cannot delete Stream policer as the index
                                       points to a non-valatile entry
    @retval     #BCM_ERR_INVAL_PARAMS  Stream index is out of bounds
    @retval     #BCM_ERR_UNKNOWN       Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPDeletePolicer(BCM_HandleType aConnHdl, uint32_t aStreamIdx);

/**
    @brief Block a stream

    This API blocks a particular stream

    @behavior Sync, Non-Rentrant

    @pre none

    @param[in]   aConnHdl                  Connection handle (from RPC_Connect)
    @param[in]   aStreamIdx                Index of the stream

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Stream blocked successfully
    @retval     #BCM_ERR_NOT_FOUND      No Stream policer found
    @retval     #BCM_ERR_INVAL_PARAMS   aStreamIdx is out of bounds OR
                                        Stream is already blocked
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPBlockPolicer(BCM_HandleType aConnHdl, uint32_t aStreamIdx);

/**
    @brief Resume a stream

    This API resumes a particular stream

    @behavior Sync, Non-Rentrant

    @pre none

    @param[in]   aConnHdl                  Connection handle (from RPC_Connect)
    @param[in]   aStreamIdx                Index of the stream

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Stream resumed successfully
    @retval     #BCM_ERR_NOT_FOUND      No Stream policer found
    @retval     #BCM_ERR_INVAL_PARAMS   aStreamIdx is out of bounds
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPResumePolicer(BCM_HandleType aConnHdl, uint32_t aStreamIdx);

/**
    @brief Get stream policer status

    This API gets the status of stream policer

    @behavior Sync, Non-Rentrant

    @pre none

    @param[in]      aIndex                 Stream Index
    @param[out]     aStatus                Status pointer to retrieve the information

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Status retrieved successfully
    @retval     #BCM_ERR_NOT_FOUND      Stream policer not found
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL OR
                                        idx within aStatus is out of bounds
    @retval  #BCM_ERR_UNKNOWN           Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPGetStrmPolicer(BCM_HandleType aConnHdl, uint32_t aIndex,
                                           ETHSWT_CFPStreamPolicerStatusType *const aStatus);

/**
    @brief Snapshot Stream Policer

    This API gets the status of stream policer

    @behavior Sync, Non-Rentrant

    @pre none

    @param[out]   aSnapshot            Pointer to retrieve snapshot

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK         Snapshot retrieved successfully

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPSnapshotStrmPolicer(BCM_HandleType aConnHdl,
                                               ETHSWT_CFPStreamPolicerSnapshotType *const aSnapshot);
/**
    @brief Find Stream Policer Index

    This API finds the index of stream policer matching input criteria

    @behavior Sync, Non-Rentrant

    @pre none

    @param[in]   aConnHdl          Connection handle (from RPC_Connect)
    @param[in]   aMacAddr          MAC address
    @param[in]   aVlanID           VLAN ID
    @param[in]   aPortMask         Port Mask
    @param[out]  aStreamIdx        Pointer to Index of allocated slot

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Found the stream policer and index populated in aStreamIdx
    @retval     #BCM_ERR_NOT_FOUND      No Stream policer found matching the criteria
    @retval     #BCM_ERR_INVAL_PARAMS   aMacAddr is NULL OR
                                        aStreamIdx is NULL
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CFPFindPolicer(BCM_HandleType aConnHdl, const uint8_t *const aMacAddr,
                                       uint16_t aVlanID, uint32_t aPortMask, uint32_t *const aStreamIdx);
#endif /* ETHSWT_ABSTRACT_CFP_H */
/** @} */
