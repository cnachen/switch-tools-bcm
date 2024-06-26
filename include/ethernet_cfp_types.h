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
    @defgroup grp_cfp_ifc CFP abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_cfp_ifc
    @{

    @file ethernet_cfp_types.h

    @brief CFP Interface
    This file contains the CFP interface

    @version 1.0 Initial version
*/

#ifndef ETHERNET_CFP_TYPES_H
#define ETHERNET_CFP_TYPES_H

#include <ethernet_common.h>
#include <ethernet_swt_common.h>
#include <bcm_utils.h>

/**
    @name CFP API IDs
    @{
    @brief API IDs for CFP
*/
#define BRCM_SWARCH_CFP_MAX_PAYLOAD_SIZE_MACRO     (0x7101U) /**< @brief #CFP_MAX_PAYLOAD_SIZE         */
#define BRCM_SWARCH_CFP_RULELIST_MAX_RULES_MACRO   (0x7102U) /**< @brief #CFP_RULELIST_MAX_RULES       */
#define BRCM_SWARCH_CFP_ID_MACRO                   (0x7103U) /**< @brief #CFP_ID                       */
#define BRCM_SWARCH_CFP_MAX_SLICE_UDFS_MACRO       (0x7104U) /**< @brief #CFP_MAX_SLICE_UDFS           */
#define BRCM_SWARCH_CFP_MAX_SLICES_MACRO           (0x7105U) /**< @brief #CFP_MAX_SLICES               */
#define BRCM_SWARCH_CFP_NUM_FORMATS_MACRO          (0x7106U) /**< @brief #CFP_NUM_FORMATS              */
#define BRCM_SWARCH_CFP_PORTMASK_TYPE              (0x7107U) /**< @brief #CFP_PortMaskType             */
#define BRCM_SWARCH_CFP_METERID_TYPE               (0x7108U) /**< @brief #CFP_MeterIdType              */
#define BRCM_SWARCH_CFP_ID_TYPE                    (0x7109U) /**< @brief #CFP_IdType                   */
#define BRCM_SWARCH_CFP_UDF_ADDR_TYPE              (0x710AU) /**< @brief #CFP_UDFAddrType              */
#define BRCM_SWARCH_CFP_SLICESNAPSHOT_TYPE         (0x710BU) /**< @brief #CFP_SliceSnapshotType        */
#define BRCM_SWARCH_CFP_GLOBALSNAPSHOT_TYPE        (0x710DU) /**< @brief #CFP_GlobalSnapshotType       */
#define BRCM_SWARCH_CFP_ENTRYSNAPSHOT_TYPE         (0x710EU) /**< @brief #CFP_EntrySnapshotType        */
#define BRCM_SWARCH_CFP_RULESSNAPSHOT_TYPE         (0x710FU) /**< @brief #CFP_RulesSnapshotType        */
#define BRCM_SWARCH_CFP_METERSTATS_TYPE            (0x7110U) /**< @brief #CFP_MeterStatsType           */
#define BRCM_SWARCH_CFP_GETMETERSTATSMSG_TYPE      (0x7111U) /**< @brief #CFP_GetMeterStatsMsgType     */
#define BRCM_SWARCH_CFP_METER_TYPE                 (0x7112U) /**< @brief #CFP_MeterType                */
#define BRCM_SWARCH_CFP_ACTIONTYPE                 (0x7113U) /**< @brief #CFP_ActionType               */
#define BRCM_SWARCH_CFP_METERDEFS_TYPE             (0x7114U) /**< @brief #CFP_MeterDefsType            */
#define BRCM_SWARCH_CFP_CHNGFWDMAP_TYPE            (0x7115U) /**< @brief #CFP_ChngFwdMapType           */
#define BRCM_SWARCH_CFP_UDFDEF_TYPE                (0x7116U) /**< @brief #CFP_UDFDefType               */
#define BRCM_SWARCH_CFP_L3FRAMING_TYPE             (0x7117U) /**< @brief #CFP_L3FramingType            */
#define BRCM_SWARCH_CFP_KEYFLAGS_TYPE              (0x7118U) /**< @brief #CFP_KeyFlagsType             */
#define BRCM_SWARCH_CFP_UDFBASE_TYPE               (0x7119U) /**< @brief #CFP_UDFBaseType              */
#define BRCM_SWARCH_CFP_MSGUNION_TYPE              (0x711AU) /**< @brief #CFP_MsgUnionType             */
#define BRCM_SWARCH_CFP_TCPSTATEID_TYPE            (0x711BU) /**< @brief #CFP_TCPStateIdType           */
#define BRCM_SWARCH_CFP_SLICE_TYPE                 (0x711CU) /**< @brief #CFP_SliceType                */
#define BRCM_SWARCH_CFP_ROW_TYPE                   (0x711DU) /**< @brief #CFP_RowType                  */
#define BRCM_SWARCH_CFP_KEYPDFS_TYPE               (0x711EU) /**< @brief #CFP_KeyPDFsType              */
#define BRCM_SWARCH_CFP_KEY_TYPE                   (0x711FU) /**< @brief #CFP_KeyType                  */
#define BRCM_SWARCH_CFP_UPDATEACTIONMSG_TYPE       (0x7120U) /**< @brief #CFP_UpdateActionMsgType      */
#define BRCM_SWARCH_CFP_METERMSG_TYPE              (0x7121U) /**< @brief #CFP_MeterMsgType             */
#define BRCM_SWARCH_CFP_CONFIGUDFMSG_TYPE          (0x7122U) /**< @brief #CFP_ConfigUDFMsgType         */
#define BRCM_SWARCH_CFP_FORMATSNAPSHOT_TYPE        (0x7123U) /**< @brief #CFP_FormatSnapshotType       */
#define BRCM_SWARCH_CFP_GETRULESSNAPSHOTMSG_TYPE   (0x7124U) /**< @brief #CFP_GetRulesSnapshotMsgType  */
#define BRCM_SWARCH_CFP_IPKEYINFO_TYPE             (0x7126U) /**< @brief #CFP_IPKeyInfoType            */
#define BRCM_SWARCH_CFP_NONIPKEYINFO_TYPE          (0x7127U) /**< @brief #CFP_NonIPKeyInfoType         */
#define BRCM_SWARCH_CFP_SETENABLEDPORTSMSG_TYPE    (0x7128U) /**< @brief #CFP_SetEnabledPortsMsgType   */
#define BRCM_SWARCH_CFP_CTAG_TYPE                  (0x7129U) /**< @brief #CFP_CTagType                 */
#define BRCM_SWARCH_CFP_TTL_TYPE                   (0x712AU) /**< @brief #CFP_TTLType                  */
#define BRCM_SWARCH_CFP_RULE_TYPE                  (0x712BU) /**< @brief #CFP_RuleType                 */
#define BRCM_SWARCH_CFP_DSCPTYPE                   (0x712CU) /**< @brief #CFP_DSCPType                 */
#define BRCM_SWARCH_CFP_COLORTYPE                  (0x712DU) /**< @brief #CFP_ColorType                */
#define BRCM_SWARCH_CFP_POLICERMODETYPE            (0x712EU) /**< @brief #CFP_PolicerModeType          */
#define BRCM_SWARCH_CFP_MACADDR_TYPE               (0x712FU) /**< @brief #CFP_MACAddrType              */
#define BRCM_SWARCH_CFP_CTAGDEFS_TYPE              (0x7130U) /**< @brief #CFP_CTagDefsType             */
#define BRCM_SWARCH_CFP_TCPSTATEIDINFO_TYPE        (0x7131U) /**< @brief #CFP_TCPStateIdInfoType       */
#define BRCM_SWARCH_CFP_IPKEY_TYPE                 (0x7132U) /**< @brief #CFP_IPKeyType                */
#define BRCM_SWARCH_CFP_NONIPKEY_TYPE              (0x7133U) /**< @brief #CFP_NonIPKeyType             */
#define BRCM_SWARCH_CFP_PKTLENCORR_TYPE            (0x7134U) /**< @brief #CFP_PktLenCorrType           */
#define BRCM_SWARCH_CFP_SHORT_SLICE_UDFS_MACRO     (0x7135U) /**< @brief #CFP_SHORT_SLICE_UDFS         */
#define BRCM_SWARCH_CFP_LONG_SLICE_UDFS_MACRO      (0x7136U) /**< @brief #CFP_LONG_SLICE_UDFS          */
#define BRCM_SWARCH_CFP_L2FRAMING_TYPE             (0x7137U) /**< @brief #CFP_L2FramingType            */
#define BRCM_SWARCH_CFP_WILDCARDKEYINFO_TYPE       (0x7138U) /**< @brief #CFP_WildcardKeyInfoType      */
#define BRCM_SWARCH_CFP_WILDCARDKEY_TYPE           (0x7139U) /**< @brief #CFP_WildcardKeyType          */
#define BRCM_SWARCH_CFP_EVENT_TYPE                 (0x713AU) /**< @brief #CFP_EventType                */
#define BRCM_SWARCH_CFP_EVENTMSG_TYPE              (0x713BU) /**< @brief #CFP_EventMsgType             */
#define BRCM_SWARCH_CFP_MAX_EVENTS_PER_MSG_MACRO   (0x713CU) /**< @brief #CFP_MAX_EVENTS_PER_MSG       */
#define BRCM_SWARCH_CFP_EVENTLISTMSG_TYPE          (0x713DU) /**< @brief #CFP_EventsListMsgType        */
/** @} */

/**
    @brief Maximum size of CFP payload

    @trace #BRCM_SWREQ_CFP
*/
#define CFP_MAX_PAYLOAD_SIZE       (440UL)

/**
    @brief Total number of rules that is captured during
    a CFP snapshot

    @trace #BRCM_SWREQ_CFP
*/
#define CFP_RULELIST_MAX_RULES     (384U)

/**
    @brief Macro to Construct Ethernet CmdID

    @trace #BRCM_SWREQ_CFP
*/
#define CFP_ID(aId)       BCM_MSG(BCM_GROUPID_ETHSRV, BCM_CFPMOD_ID, aId)
#define CFP_ID_ASYNC(aId) BCM_MSG_ASYNC(BCM_GROUPID_ETHSRV, BCM_CFPMOD_ID, aId)

/**
    @brief CFP Maximum number of UDFs in a slice
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_MAX_SLICE_UDFS       (21U)

/**
    @brief CFP Number of UDFs in a slice containing long rules
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_LONG_SLICE_UDFS      (CFP_MAX_SLICE_UDFS)
/**
    @brief CFP Number of UDFs in a slice containing short rules
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_SHORT_SLICE_UDFS     (9U)

/**
    @brief Maximum number of slices
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_MAX_SLICES           (4U)    /**< @brief Number of slices      */

/**
    @brief Number of supported formats
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_NUM_FORMATS          (3UL)

/**
    @name CFP port mask type
    @{
    @brief CFP port mask type

    @trace #BRCM_SWREQ_CFP
*/
typedef uint32_t CFP_PortMaskType;
/** @} */

/**
    @name CFP DSCP type
    @{
    @brief CFP DSCP (Differentiated Services Code Point) type

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_DSCPType;       /**< @brief DSCP type                */
#define CFP_DSCP_MAX          (63U) /**< @brief Maximum valid DSCP value */
/** @} */

/**
    @name CFP_ColorType
    @{
    @brief Definitions for color

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_ColorType;       /**< @brief typedef for color */
#define CFP_COLOR_GREEN         (0U) /**< @brief Green color */
#define CFP_COLOR_YELLOW        (1U) /**< @brief Yellow color */
#define CFP_COLOR_RED           (2U) /**< @brief Red color */
/** @} */

/**
    @name CFP_PolicerModeType
    @{
    @brief Definitions for policer mode

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_PolicerModeType;  /**< @brief typedef for policer mode */
#define CFP_POLICERMODE_RFC2698  (0U) /**< @brief Policer compliant with RFC2698 */
#define CFP_POLICERMODE_RFC4115  (1U) /**< @brief Policer compliant with RFC4115 */
#define CFP_POLICERMODE_MEF      (2U) /**< @brief Policer compliant with MEF */
#define CFP_POLICERMODE_DISABLED (3U) /**< @brief Policer disabled */
/** @} */

/**
    @name CFP slice number definition
    @{
    @brief Definitions for CFP slice number

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_SliceType;         /**< @brief typedef for CFP slice */
#define CFP_SLICE_0            (0U)    /**< @brief Slice 0               */
#define CFP_SLICE_1            (1U)    /**< @brief Slice 1               */
#define CFP_SLICE_2            (2U)    /**< @brief Slice 2               */
#define CFP_SLICE_3            (3U)    /**< @brief Slice 3               */
#define CFP_SLICE_INVALID      (0xFFU) /**< @brief Invalid slice number
                                            @xsd hide                    */
/** @} */

/**
    @name CFP event types
    @{
    @brief CFP event types

    @trace #BRCM_SWREQ_CFP
*/
typedef uint32_t CFP_EventType;    /**< @brief CFP event Type           */
#define CFP_EVENT_HIT       (1UL)  /**< @brief Event generated on rule getting hit (policer disabled) */
#define CFP_EVENT_OUTOFBAND (2UL)  /**< @brief Event generated on out of band detected (policer enabled) */
/** @} */

/**
    @name CFP meter identifier definition
    @{
    @brief Definitions for meter identifier

    @trace #BRCM_SWREQ_CFP
*/
typedef uint16_t CFP_MeterIdType;          /**< @brief typedef for meter identifier
                                                @xsd input:int */
#define CFP_METERID_INVALID      (0xFFFFU) /**< @brief Invalid meter identifier */
/** @} */

/**
    @brief Structure for CFP statistics

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_MeterStatsType {
    uint64_t green;  /**< @brief Green counter */
    uint64_t yellow; /**< @brief Yellow counter */
    uint64_t red;    /**< @brief Red counter */
} CFP_MeterStatsType;
BCM_STATIC_SIZE_ASSERT(CFP_MeterStatsType, 24UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP_UDFAddrType
    @{
    @brief Definitions for UDF address

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_UDFAddrType;           /**< @brief typedef for UDF address */
#define CFP_UDF_ADDR_BASE_SHIFT    (5U)    /**< @brief Bit shift for the UDF base field in
                                                       the address parameter
                                                @xsd name:base;enum:CFP_UDFBASE_SOP@SOP
                                                @xsd enum:CFP_UDFBASE_ENDL2HDR@EndL2Hdr,CFP_UDFBASE_ENDL3HDR@EndL3Hdr */
#define CFP_UDF_ADDR_BASE_MASK     (0xE0U) /**< @brief Mask for the UDF base field in the
                                                       address parameter */
#define CFP_UDF_ADDR_OFFSET_SHIFT  (0U)    /**< @brief Bit shift for the UDF offset field
                                                       in the address parameter
                                                @xsd name:offset */
#define CFP_UDF_ADDR_OFFSET_MASK   (0x1FU) /**< @brief Mask for the UDF offset field in
                                                       the address parameter */
/** @} */

/**
    @name CFP_PktLenCorrType
    @{
    @brief Definitions for packet length correction for flow meter computations

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_PktLenCorrType;         /**< @brief typedef for packet
                                                        length correction */
#define CFP_PKTLENCORR_NONE            (0U) /**< @brief No packet length
                                                        correction */
#define CFP_PKTLENCORR_ADD_PRE_SFD     (1U) /**< @brief Add Preamble and SFD
                                                         (8 bytes) to packet length */
#define CFP_PKTLENCORR_ADD_PRE_SFD_IFG (2U) /**< @brief Add Preamble, SFD and
                                                        IFG (20 bytes) to packet length */
/** @} */

/**
    @brief Structure for format snapshot

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_FormatSnapshotType {
    uint32_t         validUDFMap;              /**< @brief Bitmap of valid UDFs */
    CFP_UDFAddrType  udfs[CFP_MAX_SLICE_UDFS]; /**< @brief List of UDFs         */
    uint8_t          resv1;                    /**< @brief Reserved             */
    uint16_t         numRules;                 /**< @brief Number of rules      */
    uint32_t         resv2;                    /**< @brief Reserved             */
} CFP_FormatSnapshotType;
BCM_STATIC_SIZE_ASSERT(CFP_FormatSnapshotType, 32UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for slice snapshot

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_SliceSnapshotType {
    CFP_FormatSnapshotType  nonIP;              /**< @brief non-IP */
    CFP_FormatSnapshotType  ipv4;               /**< @brief IPv4 */
    CFP_FormatSnapshotType  ipv6;               /**< @brief IPv6 */
    uint32_t                numWildcardEntries; /**< @brief Number of rules which
                                                            have a wildcard format
                                                            (i.e. CFP_L3FRAMING_WILDCARD) */
    uint32_t                resv;               /**< @brief Reserved */
} CFP_SliceSnapshotType;
BCM_STATIC_SIZE_ASSERT(CFP_SliceSnapshotType, 104UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP global snapshot

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_GlobalSnapshotType {
    uint32_t               numValidEntries;                          /**< @brief Number of valid entries */
    uint8_t                stateId;                                  /**< @brief Currently programmed
                                                                                 value of the state
                                                                                 identifier              */
    uint8_t                resv1[3U];                                /**< @brief Reserved                */
    CFP_PortMaskType       portEnableMask;                           /**< @brief Bitmask of ports where
                                                                                 CFP lookup is enabled   */
    uint32_t               resv2[3U];                                /**< @brief Reserved                */
    CFP_SliceSnapshotType  slices[CFP_MAX_SLICES];                   /**< @brief Slice snapshots         */
} CFP_GlobalSnapshotType;
BCM_STATIC_SIZE_ASSERT(CFP_GlobalSnapshotType, 440UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP_EntrySnapshotType
    @{
    @brief Definitions for CFP entry snapshot

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_EntrySnapshotType;            /**< @brief typedef for entry snapshot field definitions */
#define CFP_ENTRYSNAPSHOT_ENABLE_MASK     (0x80U) /**< @brief Mask for the enable field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_ENABLE_SHIFT    (7U)    /**< @brief Bit shift for the enable field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_CHAINED_MASK    (0x40U) /**< @brief Mask for the chained field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_CHAINED_SHIFT   (6U)    /**< @brief Bit shift for the chained field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_LONGRULE_MASK   (0x20U) /**< @brief Mask for the long rule field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_LONGRULE_SHIFT  (5U)    /**< @brief Bit shift for the long rule field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_SLICE_MASK      (0xCU)  /**< @brief Mask for the slice field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_SLICE_SHIFT     (2U)    /**< @brief Bit shift for the slice field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_FORMAT_MASK     (0x3U)  /**< @brief Mask for the format field in the entry snapshot */
#define CFP_ENTRYSNAPSHOT_FORMAT_SHIFT    (0U)    /**< @brief Bit shift for the format field in the entry snapshot */
/** @} */

/**
    @brief Structure for Rules snapshot

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_RulesSnapshotType {
    CFP_EntrySnapshotType entry[CFP_RULELIST_MAX_RULES]; /**< @brief Table of per row snapshot
                                                                     encoded in a bitfield as follows:
                                                                     Enable (1) | Chained (1) | Long Rule (1) | Resv (1) | Slice(2) | Format(2) */
} CFP_RulesSnapshotType;
BCM_STATIC_SIZE_ASSERT(CFP_RulesSnapshotType, CFP_RULELIST_MAX_RULES, CFP_MAX_PAYLOAD_SIZE)

/**
    @name Meter definitions
    @{
    @brief Definitions for CFP meter

    @trace #BRCM_SWREQ_CFP
*/
typedef uint32_t CFP_MeterDefsType;               /**< @brief typedef for meter definitions */
#define CFP_METERDEFS_TKBKT_SHIFT   (0UL)        /**< @brief Bit shift for token bucket size */
#define CFP_METERDEFS_TKBKT_MASK    (0x7FFFFFUL) /**< @brief Mask for token bucket size */
#define CFP_METERDEFS_BKTSZ_SHIFT   (0UL)        /**< @brief Bit shift for bucket (burst) size */
#define CFP_METERDEFS_BKTSZ_MASK    (0xFFFFFUL)  /**< @brief Mask for bucket (burst) size */
#define CFP_METERDEFS_REFCNT_SHIFT  (0UL)        /**< @brief Bit shift for reference count */
#define CFP_METERDEFS_REFCNT_MASK   (0x7FFFFUL)  /**< @brief Mask for reference count */
/** @} */

/**
    @brief Structure for CFP Meter configuration

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_MeterType {
    uint32_t             cirTkBkt;           /**< @brief Committed token bucket size in bits
                                                         (BPS mode) or packets (PPS mode) */
    uint32_t             cirBktSize;         /**< @brief Committed burst size in bytes (BPS
                                                         mode) or packets (PPS mode) */
    uint32_t             cirRefCnt;          /**< @brief Committed information rate in Kbps
                                                         (BPS mode) or packets per second
                                                         (PPS mode) */
    uint32_t             eirTkBkt;           /**< @brief Excess token bucket size in bits
                                                         (BPS mode) or packets (PPS mode) */
    uint32_t             eirBktSize;         /**< @brief Excess burst size in bytes (BPS
                                                         mode) or packets (PPS mode) */
    uint32_t             eirRefCnt;          /**< @brief Excess information rate in Kbps
                                                         (BPS mode) or packets per second
                                                         (PPS mode) */
    uint8_t              colorMode;          /**< @brief Flag indicating whether the policer
                                                         operation is color blind (1U) or
                                                         color aware (0U). This corresponds
                                                         to the color mode parameter described
                                                         in MEF 10.2 specification section 7.11.1 */
    uint8_t              policerAction;      /**< @brief Flag indicating whether the RED
                                                         color packets are subjected to
                                                         Out-Band actions (1U) or are
                                                         dropped (0U). This is not applicable
                                                         to MEF mode of operation */
    uint8_t              couplingFlag;       /**< @brief Flag corresponding to coupling flag
                                                         described in MEF 10.2 specification
                                                         section 7.11.1 */
    CFP_PolicerModeType  policerMode;        /**< @brief Policer mode selection */
    uint8_t              dropYellow;         /**< @brief Flag indicating if yellow frames are
                                                         dropped (1U) or not (0U) */
    uint8_t              markAllFramesRedEn; /**< @brief Flag indicating if markAllFramesRed
                                                         function is enabled (1U) or not (0U) */
    uint8_t              markAllFramesRed;   /**< @brief Flag indicating if all frames are dropped
                                                         (1U) or not (0U). Applicable only when
                                                         the markAllFramesRedEn is set to 1U */
    uint8_t              ppsMode;            /**< @brief Flag indicating whether the metering
                                                         is performed on the basis of packets per
                                                         second [PPS] (1U) or bits per second [BPS] (0U) */
    uint8_t              counterMode;        /**< @brief Flag indicating whether the meter counters
                                                         increments with packets (1U) or bytes (0U) */
    uint8_t resv[3U];
} CFP_MeterType;
BCM_STATIC_SIZE_ASSERT(CFP_MeterType, 36UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP_ChngFwdMapType
    @{
    @brief Definitions for changing the forwarding map

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_ChngFwdMapType;   /**< @brief Typedef for changing
                                                  forwarding map */
#define CFP_CHNGFWDMAP_NON       (0U) /**< @brief No change */
#define CFP_CHNGFWDMAP_REM       (1U) /**< @brief Remove ARL destinations */
#define CFP_CHNGFWDMAP_REP       (2U) /**< @brief Replace ARL destinations */
#define CFP_CHNGFWDMAP_ADD       (3U) /**< @brief Add ARL destinations */
/** @} */

/**
    @brief Structure for CFP Action

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_ActionType {
    uint8_t             changeDSCPOB;     /**< @brief Flag indicating whether the DSCP
                                                      for Out-Band packets needs to be
                                                      modified (1U) or not (0U) */
    CFP_DSCPType        newDSCPOB;        /**< @brief New DSCP value for Out-Band packets
                                                      (valid only if changeDSCPOB is set
                                                      to 1U) */
    CFP_ChngFwdMapType  changeFwdMapOB;   /**< @brief Indicates how to use the
                                                      Out-Bandwidth destination
                                                      map */
    uint8_t             changeDSCPIB;     /**< @brief Flag indicating whether the DSCP
                                                      for In-Band packets needs to be
                                                      modified (1U) or not (0U) */
    CFP_DSCPType        newDSCPIB;        /**< @brief New DSCP value for In-Band packets
                                                      (valid only if changeDSCPIB is set
                                                      to 1U) */
    CFP_ChngFwdMapType  changeFwdMapIB;   /**< @brief Indicates how to use the
                                                      In-Bandwidth destination
                                                      map */
    uint8_t             changeTCO;        /**< @brief Flag indicating whether the newTCO
                                                      value is to be used (1U) or not (0U) */
    ETHER_TCType        newTCO;           /**< @brief New TCO value to be used */
    uint8_t             changeTC;         /**< @brief Flag indicating whether the newTC
                                                      value is to be used (1U) or not (0U) */
    ETHER_TCType        newTC;            /**< @brief New TC value to be used */
    uint8_t             loopbackEn;       /**< @brief Flag indicating whether packet is
                                                      allowed (1U) or not (0U) to be
                                                      forwarded to the port it was
                                                      originally received from */
    uint8_t             bypassSTP;        /**< @brief Flag indicating whether CFP forward
                                                      decision can bypass STP based
                                                      filtering (1U) or not (0U) */
    uint8_t             bypassEAP;        /**< @brief Flag indicating whether CFP forward
                                                      decision can bypass EAP based
                                                      filtering (1U) or not (0U) */
    uint8_t             bypassVLAN;       /**< @brief Flag indicating whether CFP forward
                                                      decision can bypass VLAN based
                                                      filtering (1U) or not (0U) */
    uint8_t             interruptEn;      /**< @brief Flag indicating whether interrupt
                                                      is enabled (1U) or not (0). When
                                                      the interrupt is enabled, it will
                                                      be raised on one of the following
                                                      conditions:
                                                      -# if policer is disabled, on
                                                         hitting the rule
                                                      -# if policer is enabled, if the
                                                         packet is classified as Out-Band */
    uint8_t             mirrorOBEn;       /**< @brief Flag indicating whether the Out-Band
                                                      packet is mirrored to mirror port
                                                      (1U) or not (0U) */
    uint8_t             mirrorIBEn;       /**< @brief Flag indicating whether the In-Band
                                                      packet is mirrored to mirror port
                                                      (1U) or not (0U) */
    uint8_t             resv1;            /**< @brief Reserved */
    uint8_t             cPCPRemarkDis;    /**< @brief Flag indicating whether the PCP in
                                                      C-Tag is allowed to be remarked
                                                      (0U) or not (1U) */
    uint8_t             resv2;            /**< @brief Reserved */
    uint8_t             bypassMACLimit;   /**< @brief Flag indicating whether the drop
                                                      decision due to MAC limiting can
                                                      be bypassed (1U) or not (0U) */
    uint8_t             reasonCode;       /**< @brief Reason code */
    uint16_t            classificationId; /**< @brief Indicates the classification
                                                      identifier for packet forwarded
                                                      to the CPU. Also overloaded as
                                                      the chain ID for legacy IPv6
                                                      chaining feature */
    uint8_t             redDefault;       /**< @brief Flag indicating whether to use
                                                      the default RED profile (1U) or
                                                      not (0U) */
    CFP_ColorType       newColor;         /**< @brief New color value to be used (valid
                                                      only if changeColor is set to 1U) */
    uint8_t             changeColor;      /**< @brief Flag indicating whether the color
                                                      determined by the policer can be
                                                      over-ridden (1U) or not (0U) */
    uint8_t             resv3;            /**< @brief Reserved */
    CFP_MeterIdType     flowMeterId;      /**< @brief Identifier of the flow meter
                                                      associated with this rule */
    uint16_t            resv4;            /**< @brief Reserved */
    CFP_PortMaskType    dstMapIB;         /**< @brief Destination port mask for
                                                      In-Bandwidth profile traffic */
    CFP_PortMaskType    dstMapOB;         /**< @brief Destination port mask for
                                                      Out-Bandwidth profile traffic */
} CFP_ActionType;
BCM_STATIC_SIZE_ASSERT(CFP_ActionType, 40UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP_UDFBaseType
    @{
    @brief UDF Base definitions

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_UDFBaseType;            /**< @brief typedef for UDF Base */
#define CFP_UDFBASE_SOP                (0U) /**< @brief Start of Packet */
#define CFP_UDFBASE_ENDL2HDR           (2U) /**< @brief End of L2 header */
#define CFP_UDFBASE_ENDL3HDR           (3U) /**< @brief End of L3 header  */
/** @} */

/**
    @brief Structure for CFP UDF definition

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_UDFDefType {
    uint16_t  value;  /**< @brief Value of the UDF
                           @xsd hex */
    uint16_t  mask;   /**< @brief Value of the UDF mask
                           @xsd hex */
} CFP_UDFDefType;
BCM_STATIC_SIZE_ASSERT(CFP_UDFDefType, 4UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP_L2FramingType
    @{
    @brief Definitions for L2 framing

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_L2FramingType;                         /**< @brief typedef for L2 framing type */
#define CFP_L2FRAMING_DIXV2       (0U)                     /**< @brief DIXv2                       */
#define CFP_L2FRAMING_SNAP_PUB    (1U)                     /**< @brief SNAP Public                 */
#define CFP_L2FRAMING_LLC         (2U)                     /**< @brief LLC                         */
#define CFP_L2FRAMING_SNAP_PVT    (3U)                     /**< @brief SNAP Private                */
#define CFP_L2FRAMING_MAX         (CFP_L2FRAMING_SNAP_PVT) /**< @brief Maximum value of L2 framing */
/** @} */

/**
    @name CFP_L3FramingType
    @{
    @brief Definitions for L3 framing

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_L3FramingType;       /**< @brief typedef for L3 framing type */
#define CFP_L3FRAMING_IPV4        (0U)   /**< @brief IPv4 */
#define CFP_L3FRAMING_IPV6        (1U)   /**< @brief IPv6 */
#define CFP_L3FRAMING_NONIP       (3U)   /**< @brief non-IP */
#define CFP_L3FRAMING_WILDCARD    (255U) /**< @brief Any framing type */
/** @} */

/**
    @name CFP TCAM C-Tag definitions
    @{
    @brief C-Tag Definitions for TCAM Key: PCP (3) | DEI (1) | CVID (12)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint16_t CFP_CTagDefsType;          /**< @brief typedef for C-Tag definitions */
#define CFP_CTAGDEFS_PCP_MASK    (0xE000U)  /**< @brief Mask for PCP in C-Tag
                                                 @xsd name:pcp                        */
#define CFP_CTAGDEFS_PCP_SHIFT   (13UL)     /**< @brief Bit shift for PCP in C-Tag    */
#define CFP_CTAGDEFS_DEI_MASK    (0x1000U)  /**< @brief Mask for DEI in C-Tag
                                                 @xsd name:dei                        */
#define CFP_CTAGDEFS_DEI_SHIFT   (12U)      /**< @brief Bit shift for DEI in C-Tag    */
#define CFP_CTAGDEFS_CVID_MASK   (0xFFFU)   /**< @brief Mask for C-Vid in C-Tag
                                                 @xsd name:vlan                       */
#define CFP_CTAGDEFS_CVID_SHIFT  (0U)       /**< @brief Bit shift for C-Vid in C-Tag  */
/** @} */

/**
    @brief TCAM value and mask for C-Tag

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_CTagType {
    CFP_CTagDefsType value; /**< @brief C-Tag value */
    CFP_CTagDefsType mask;  /**< @brief C-Tag mask
                                 @xsd mask          */
} CFP_CTagType;
BCM_STATIC_SIZE_ASSERT(CFP_CTagType, 4UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief TCAM value and mask for MAC address fields

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_MACAddrType {
    uint8_t  value[ETHER_MACADDRESS_SIZE]; /**< @brief MAC address value
                                                @xsd type:mac */
    uint8_t  mask[ETHER_MACADDRESS_SIZE];  /**< @brief MAC address mask
                                                @xsd type:mac */
} CFP_MACAddrType;
BCM_STATIC_SIZE_ASSERT(CFP_MACAddrType, 12UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP TCAM wildcard key flags (unpacked) definition

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_WildcardKeyInfoType {
    uint8_t   usrTagNZ;      /**< @brief User tag (C-Vid) not zero */
    uint8_t   usrTagValid;   /**< @brief User tag (C-Vid) valid (present) */
    uint8_t   resv[10];      /**< @brief Reserved
                                  @xsd rsvd */
} CFP_WildcardKeyInfoType;
BCM_STATIC_SIZE_ASSERT(CFP_WildcardKeyInfoType, 12UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief TCAM value and mask for wildcard key fields used for runtime commands (unpacked)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_WildcardKeyType {
    CFP_WildcardKeyInfoType value; /**< @brief Value */
    CFP_WildcardKeyInfoType mask;  /**< @brief Mask  */
} CFP_WildcardKeyType;
BCM_STATIC_SIZE_ASSERT(CFP_WildcardKeyType, 24UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP TCAM non-IP key flags (unpacked) definition

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_NonIPKeyInfoType {
    uint8_t   usrTagNZ;      /**< @brief User tag (C-Vid) not zero */
    uint8_t   usrTagValid;   /**< @brief User tag (C-Vid) valid (present) */
    uint8_t   PPPoESession;  /**< @brief Identifies a PPPOE Session stage packet */
    uint8_t   resv1[2];      /**< @brief Reserved
                                  @xsd rsvd */
    uint16_t  etherType;     /**< @brief Ethertype */
    uint32_t  resv2;         /**< @brief Reserved
                                          @xsd rsvd */
} CFP_NonIPKeyInfoType;
BCM_STATIC_SIZE_ASSERT(CFP_NonIPKeyInfoType, 12UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief TCAM value and mask for non-IP key fields used for runtime commands (unpacked)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_NonIPKeyType {
    CFP_NonIPKeyInfoType value; /**< @brief Value */
    CFP_NonIPKeyInfoType mask;  /**< @brief Mask  */
} CFP_NonIPKeyType;
BCM_STATIC_SIZE_ASSERT(CFP_NonIPKeyType, 24UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP key TTL definitions
    @{
    @brief CFP key TTL definitions

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_TTLType;      /**< @brief Typedef for TTL */
#define CFP_TTL_0           (0UL) /**< @brief TTL value 0 */
#define CFP_TTL_1           (1UL) /**< @brief TTL value 1 */
#define CFP_TTL_OTHERS      (2UL) /**< @brief TTL value others  */
#define CFP_TTL_255         (3UL) /**< @brief TTL value 255 */
/** @} */

/**
    @brief Structure for CFP TCAM IP key flags (unpacked) definition

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_IPKeyInfoType {
    uint8_t      usrTagNZ;      /**< @brief User tag (C-Vid) not zero */
    uint8_t      usrTagValid;   /**< @brief User tag (C-Vid) valid (present) */
    uint8_t      PPPoESession;  /**< @brief PPP over Ethernet Session stage packet */
    uint8_t      frag;          /**< @brief IP fragment */
    uint8_t      nonFirstFrag;  /**< @brief Not first IP fragment */
    uint8_t      auth;          /**< @brief IP authentication */
    CFP_TTLType  ttl;           /**< @brief Time to Live */
    uint8_t      tos;           /**< @brief Type of Service */
    uint8_t      proto;         /**< @brief Protocol */
    uint8_t      resv[3];       /**< @brief Reserved
                                          @xsd rsvd */
} CFP_IPKeyInfoType;
BCM_STATIC_SIZE_ASSERT(CFP_IPKeyInfoType, 12UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief TCAM value and mask for IPv4/IPv6 key fields used for runtime commands (unpacked)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_IPKeyType {
    CFP_IPKeyInfoType value; /**< @brief Value */
    CFP_IPKeyInfoType mask;  /**< @brief Mask  */
} CFP_IPKeyType;
BCM_STATIC_SIZE_ASSERT(CFP_IPKeyType, 24UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Union representing the Key fields specific to the format (unpacked version)

    @trace #BRCM_SWREQ_CFP
*/
typedef union uCFP_KeyFlagsType {
    CFP_NonIPKeyType    nonIP;    /**< @brief non IP */
    CFP_IPKeyType       ipv4;     /**< @brief IPv4 */
    CFP_IPKeyType       ipv6;     /**< @brief IPv6 */
    CFP_WildcardKeyType wildcard; /**< @brief Wildcard/Any */
} CFP_KeyFlagsType;
BCM_STATIC_SIZE_ASSERT(CFP_KeyFlagsType, 24UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure representing the TCP and state Id fields used for runtime commands (unpacked)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_TCPStateIdInfoType {
    uint8_t stateId;        /**< @brief State Id */
    uint8_t tcpFlagsValid;  /**< @brief Validates tcpFlags */
    uint8_t resv[4];        /**< @brief Reserved
                                 @xsd rsvd */
    uint8_t tcpFlagUrg;     /**< @brief TCP URG flag */
    uint8_t tcpFlagAck;     /**< @brief TCP ACK flag */
    uint8_t tcpFlagPsh;     /**< @brief TCP PSH flag */
    uint8_t tcpFlagRst;     /**< @brief TCP RST flag */
    uint8_t tcpFlagSyn;     /**< @brief TCP SYN flag */
    uint8_t tcpFlagFin;     /**< @brief TCP FIN flag */
} CFP_TCPStateIdInfoType;
BCM_STATIC_SIZE_ASSERT(CFP_TCPStateIdInfoType, 12UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief TCAM value and mask for TCP flags and state id fields used for runtime commands (unpacked)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_TCPStateIdType {
    CFP_TCPStateIdInfoType value; /**< @brief Value */
    CFP_TCPStateIdInfoType mask;  /**< @brief Mask  */
} CFP_TCPStateIdType;
BCM_STATIC_SIZE_ASSERT(CFP_TCPStateIdType, 24UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP TCAM key with only the pre-defined fields (PDF)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_KeyPDFsType {
    uint8_t             ruleValid;           /**< @brief Flag indicating whether the
                                                         rule is enabled (1U) or not
                                                         (0U) */
    CFP_L3FramingType   l3Framing;           /**< @brief L3 Framing */
    CFP_L2FramingType   l2Framing;           /**< @brief L2 Framing */
    CFP_PortMaskType    ingressPortBitmap;   /**< @brief Ingress port bitmap
                                                  @xsd hex;default:0x0 */
    uint32_t            resv;                /**< @brief Reserved
                                                  @xsd rsvd */
    CFP_KeyFlagsType    flags;               /**< @brief Overloaded flags field */
    CFP_CTagType        cTag;                /**< @brief C-Tag */
    CFP_TCPStateIdType  tcpStateId;          /**< @brief TCP flags and state id  */
    CFP_MACAddrType     macDA;               /**< @brief Destination MAC address */
} CFP_KeyPDFsType;
BCM_STATIC_SIZE_ASSERT(CFP_KeyPDFsType, 76UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP TCAM key for dynamic commands

    This is used for for dynamic commands and caters to both short and long rules

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_KeyType {
    CFP_KeyPDFsType pdfs;                      /**< @brief PDF values/masks                      */
    CFP_UDFDefType  udfs[CFP_MAX_SLICE_UDFS];  /**< @brief UDFs values/masks                     */
    uint32_t        enabledUDFMap;             /**< @brief Bitmap of enabled UDFs for the slice  */
    CFP_MACAddrType macSA;                     /**< @brief Source MAC address                   */
} CFP_KeyType;
BCM_STATIC_SIZE_ASSERT(CFP_KeyType, 176UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP row definition
    @{
    @brief Definitions for CFP row

    @trace #BRCM_SWREQ_CFP
*/
typedef uint16_t CFP_RowType;          /**< @brief typedef for CFP row
                                            @xsd input:int */
#define CFP_ROW_INVALID      (0xFFFFU) /**< @brief Invalid row number:
                                                   this is an indication to
                                                   the SDK that it needs to
                                                   allocate a free row number */
/** @} */

/**
    @brief Structure for Add/Get Rule Message

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_RuleType {
    CFP_RowType     row;      /**< @brief row number
                                   @xsd default:CFP_ROW_INVALID */
    CFP_SliceType   slice;    /**< @brief slice number          */
    uint8_t         resv[5U]; /**< @brief reserved
                                   @xsd rsvd                    */
    CFP_KeyType     key;      /**< @brief key                   */
    CFP_ActionType  action;   /**< @brief action                */
    CFP_MeterType   meter;    /**< @brief meter                 */
} CFP_RuleType;
BCM_STATIC_SIZE_ASSERT(CFP_RuleType, 260UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for Update Action Message

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_UpdateActionMsgType {
    CFP_RowType     row;      /**< @brief Input: Row number           */
    uint8_t         resv[6U]; /**< @brief Reserved                    */
    CFP_ActionType  action;   /**< @brief Input: Action configuration */
} CFP_UpdateActionMsgType;
BCM_STATIC_SIZE_ASSERT(CFP_UpdateActionMsgType, 48UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for Set/Get Meter Message

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_MeterMsgType {
    CFP_MeterIdType  id;   /**< @brief Meter identifier    */
    uint16_t         resv; /**< @brief Reserved            */
    CFP_MeterType    cfg;  /**< @brief Meter configuration */
} CFP_MeterMsgType;
BCM_STATIC_SIZE_ASSERT(CFP_MeterMsgType, 40UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to fetch statistics.

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_GetMeterStatsMsgType {
    CFP_MeterIdType    id;       /**< @brief Input: Meter identifier */
    uint8_t            resv[6U]; /**< @brief Reserved                */
    CFP_MeterStatsType stats;    /**< @brief Output: Statistics      */
} CFP_GetMeterStatsMsgType;
BCM_STATIC_SIZE_ASSERT(CFP_GetMeterStatsMsgType, 32UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to configure slice UDF message

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_ConfigUDFMsgType {
    uint32_t          index;     /**< @brief Input: UDF index    */
    CFP_SliceType     slice;     /**< @brief Input: Slice number */
    CFP_L3FramingType l3Framing; /**< @brief Input: L3 framing   */
    CFP_UDFBaseType   base;      /**< @brief Input: UDF base     */
    uint8_t           offset;    /**< @brief Input: UDF offset   */
} CFP_ConfigUDFMsgType;
BCM_STATIC_SIZE_ASSERT(CFP_ConfigUDFMsgType, 8UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to fetch rules snapshot message

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_GetRulesSnapshotMsgType {
    CFP_RowType           startRow; /**< @brief Input: Start row index */
    CFP_RulesSnapshotType snapshot; /**< @brief Output: Snapshot */
} CFP_GetRulesSnapshotMsgType;
BCM_STATIC_SIZE_ASSERT(CFP_GetRulesSnapshotMsgType, CFP_RULELIST_MAX_RULES+2UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to set enabled ports

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_SetEnabledPortsMsgType {
    CFP_PortMaskType portMask; /**< @brief Input: Enabled ports mask */
    uint32_t         resv;     /**< @brief Reserved                  */
} CFP_SetEnabledPortsMsgType;
BCM_STATIC_SIZE_ASSERT(CFP_SetEnabledPortsMsgType, 8UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the CFP events

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_EventMsgType {
    CFP_RowType    row;         /**< @brief Input: CFP row number */
    uint16_t       resv[3U];    /**< @brief Reserved              */
    CFP_EventType  eventReason; /**< @brief Input: Event reason   */
} CFP_EventMsgType;
BCM_STATIC_SIZE_ASSERT(CFP_EventMsgType, 12UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Macro CFP_MAX_EVENTS_PER_MSG
    We use the full payload to be able to send maximum number of events in one go
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_MAX_EVENTS_PER_MSG    (((CFP_MAX_PAYLOAD_SIZE) - sizeof(uint32_t)) / sizeof(CFP_EventMsgType))

/**
    @brief Structure with parameters for the CFP events

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_EventsListMsgType {
    uint32_t         numEvents;                      /**< @brief Input: Number of valid
                                                                 events in the list */
    CFP_EventMsgType events[CFP_MAX_EVENTS_PER_MSG]; /**< @brief Input: List of events */
} CFP_EventsListMsgType;
BCM_STATIC_SIZE_ASSERT(CFP_EventsListMsgType, 436UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP command IDs
    @{
    @brief CFP command IDs group

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_IdType;                         /**< @brief CFP command message Type                              */
#define CFP_ID_CONFIGUDF         CFP_ID(0x01U)      /**< @brief #CFP_ConfigUDFMsgType         #CFP_ConfigUDF          */
#define CFP_ID_ADDRULE           CFP_ID(0x02U)      /**< @brief #CFP_RuleType                 #CFP_AddRule            */
#define CFP_ID_REMOVERULE        CFP_ID(0x03U)      /**< @brief #CFP_RowType                  #CFP_RemoveRule         */
#define CFP_ID_ENABLERULE        CFP_ID(0x04U)      /**< @brief #CFP_RowType                  #CFP_EnableRule         */
#define CFP_ID_DISABLERULE       CFP_ID(0x05U)      /**< @brief #CFP_RowType                  #CFP_DisableRule        */
#define CFP_ID_UPDATEACTION      CFP_ID(0x06U)      /**< @brief #CFP_UpdateActionMsgType      #CFP_UpdateAction       */
#define CFP_ID_GETRULE           CFP_ID(0x07U)      /**< @brief #CFP_RuleType                 #CFP_GetRule            */
#define CFP_ID_UPDATEMETER       CFP_ID(0x08U)      /**< @brief #CFP_MeterMsgType             #CFP_UpdateMeter        */
#define CFP_ID_GETMETERCFG       CFP_ID(0x09U)      /**< @brief #CFP_MeterMsgType             #CFP_GetMeterCfg        */
#define CFP_ID_GETMETERSTATS     CFP_ID(0x0AU)      /**< @brief #CFP_GetMeterStatsMsgType     #CFP_GetMeterStats      */
#define CFP_ID_RESETMETERSTATS   CFP_ID(0x0BU)      /**< @brief #CFP_MeterIdType              #CFP_ResetMeterStats    */
#define CFP_ID_SETENABLEDPORTS   CFP_ID(0x0CU)      /**< @brief #CFP_SetEnabledPortsMsgType   #CFP_SetEnabledPorts    */
#define CFP_ID_SETCURRENTSTATEID CFP_ID(0x0DU)      /**< @brief #uint8_t                      #CFP_SetCurrentStateId  */
#define CFP_ID_GETGLOBALSNAPSHOT CFP_ID(0x0EU)      /**< @brief #CFP_GlobalSnapshotType       #CFP_GetGlobalSnapshot  */
#define CFP_ID_GETRULESSNAPSHOT  CFP_ID(0x0FU)      /**< @brief #CFP_GetRulesSnapshotMsgType  #CFP_GetRulesSnapshot   */
#define CFP_ID_ACKEVENT          CFP_ID(0x10U)      /**< @brief #CFP_RowType                  #CFP_AckEvent           */
#define CFP_ID_EVENTNOTIFICATION CFP_ID_ASYNC(0x1U) /**< @brief Event notification                                    */
/** @} */

/**
    @brief Union encapsulating all CFP messages

    @trace #BRCM_SWREQ_CFP
*/
typedef union uCFP_MsgUnionType {
    uint32_t                     data[CFP_MAX_PAYLOAD_SIZE/4UL]; /**< @brief CFP data */
    CFP_ConfigUDFMsgType         configUDF;                      /**< @brief Configure UDF */
    CFP_RuleType                 addRule;                        /**< @brief Add Rule */
    CFP_RowType                  removeRule;                     /**< @brief Remove Rule */
    CFP_RowType                  enableRule;                     /**< @brief Enable Rule */
    CFP_RowType                  disableRule;                    /**< @brief Disable Rule */
    CFP_UpdateActionMsgType      updateAction;                   /**< @brief Update Action */
    CFP_RuleType                 getRule;                        /**< @brief Get Rule */
    CFP_MeterMsgType             updateMeter;                    /**< @brief Update Meter */
    CFP_MeterMsgType             getMeterCfg;                    /**< @brief Get Meter Configuration */
    CFP_GetMeterStatsMsgType     getMeterStats;                  /**< @brief Get Statistics */
    CFP_MeterIdType              resetMeterStats;                /**< @brief Reset Statistics */
    CFP_SetEnabledPortsMsgType   setEnablePorts;                 /**< @brief Set Enabled Ports */
    uint8_t                      setStateId;                     /**< @brief Set State Id */
    CFP_GlobalSnapshotType       getGlobalSnapshot;              /**< @brief Get Global Snapshot */
    CFP_GetRulesSnapshotMsgType  getRulesSnapshot;               /**< @brief Get Rules Snapshot */
    CFP_EventsListMsgType        eventNotification;              /**< @brief Event parameters */
    CFP_RowType                  ackEvent;                       /**< @brief Acknowledge event parameters */
} CFP_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(CFP_MsgUnionType, CFP_MAX_PAYLOAD_SIZE, CFP_MAX_PAYLOAD_SIZE)

#endif /* ETHERNET_CFP_TYPES_H */
/** @} */
