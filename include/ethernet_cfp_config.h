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
    @addtogroup grp_cfp_ifc
    @{

    @file ethernet_cfp_config.h

    @brief CFP Configuration
    This file contains the CFP configuration

    @version 1.0 Initial version
*/

#ifndef ETHERNET_CFP_CONFIG_H
#define ETHERNET_CFP_CONFIG_H

#include <ethernet_cfp_types.h>

/**
    @name CFP API IDs
    @{
    @brief API IDs for CFP
*/
#define BRCM_SWARCH_CFP_CONFIG_MAGIC_ID_MACRO      (0x7301U) /**< @brief #CFP_CONFIG_MAGIC_ID          */
#define BRCM_SWARCH_CFP_MAX_INIT_METERS_MACRO      (0x7302U) /**< @brief #CFP_MAX_INIT_METERS          */
#define BRCM_SWARCH_CFP_MAX_INIT_SHORT_RULES_MACRO (0x7303U) /**< @brief #CFP_MAX_INIT_SHORT_RULES     */
#define BRCM_SWARCH_CFP_MAX_INIT_LONG_RULES_MACRO  (0x7304U) /**< @brief #CFP_MAX_INIT_LONG_RULES      */
#define BRCM_SWARCH_CFP_DSCPFLAGS_TYPE             (0x7310U) /**< @brief #CFP_DSCPFlagsType            */
#define BRCM_SWARCH_CFP_ACTIONFLAGS1_TYPE          (0x7311U) /**< @brief #CFP_ActionFlags1Type         */
#define BRCM_SWARCH_CFP_ACTIONFLAGS2_TYPE          (0x7312U) /**< @brief #CFP_ActionFlags2Type         */
#define BRCM_SWARCH_CFP_COLORFLAGS_TYPE            (0x7314U) /**< @brief #CFP_ColorFlagsType           */
#define BRCM_SWARCH_CFP_POLICERFLAGS_TYPE          (0x7315U) /**< @brief #CFP_PolicerFlagsType         */
#define BRCM_SWARCH_CFP_TCPSTATEIDPACKED_TYPE      (0x7316U) /**< @brief #CFP_TCPStateIdPackedType     */
#define BRCM_SWARCH_CFP_TCFLAGS_TYPE               (0x7317U) /**< @brief #CFP_TCFlagsType              */
#define BRCM_SWARCH_CFP_SHORTFORMATUDFS_TYPE       (0x7320U) /**< @brief #CFP_ShortFormatUDFsType      */
#define BRCM_SWARCH_CFP_LONGFORMATUDFS_TYPE        (0x7321U) /**< @brief #CFP_LongFormatUDFsType       */
#define BRCM_SWARCH_CFP_SLICECFG_TYPE              (0x7322U) /**< @brief #CFP_SliceCfgType             */
#define BRCM_SWARCH_CFP_LONGKEYCFG_TYPE            (0x7323U) /**< @brief #CFP_LongKeyCfgType           */
#define BRCM_SWARCH_CFP_LONGRULECFG_TYPE           (0x7324U) /**< @brief #CFP_LongRuleCfgType          */
#define BRCM_SWARCH_CFP_STATICRULES_TYPE           (0x7325U) /**< @brief #CFP_StaticRulesType          */
#define BRCM_SWARCH_CFP_SHORTRULECFG_TYPE          (0x7326U) /**< @brief #CFP_ShortRuleCfgType         */
#define BRCM_SWARCH_CFP_IPKEYCFG_TYPE              (0x7327U) /**< @brief #CFP_IPKeyCfgType             */
#define BRCM_SWARCH_CFP_NONIPKEYCFG_TYPE           (0x7328U) /**< @brief #CFP_NonIPKeyCfgType          */
#define BRCM_SWARCH_CFP_KEYFLAGSCFG_TYPE           (0x7329U) /**< @brief #CFP_KeyFlagsCfgType          */
#define BRCM_SWARCH_CFP_KEYPDFCFG_TYPE             (0x732AU) /**< @brief #CFP_KeyPDFCfgType            */
#define BRCM_SWARCH_CFP_SHORTKEYCFG_TYPE           (0x732BU) /**< @brief #CFP_ShortKeyCfgType          */
#define BRCM_SWARCH_CFP_PACKEDRULES_TYPE           (0x732CU) /**< @brief #CFP_PackedRulesType          */
#define BRCM_SWARCH_CFP_ACTIONCFG_TYPE             (0x732DU) /**< @brief #CFP_ActionCfgType            */
#define BRCM_SWARCH_CFP_METERCFG_TYPE              (0x732EU) /**< @brief #CFP_MeterCfgType             */
#define BRCM_SWARCH_CFP_IPKEYPACKED_TYPE           (0x732FU) /**< @brief #CFP_IPKeyPackedType          */
#define BRCM_SWARCH_CFP_NONIPKEYPACKED_TYPE        (0x7330U) /**< @brief #CFP_NonIPKeyPackedType       */
#define BRCM_SWARCH_CFP_TCPSTATEIDCFG_TYPE         (0x7331U) /**< @brief #CFP_TCPStateIdCfgType        */
#define BRCM_SWARCH_CFP_CONFIG_TYPE                (0x7332U) /**< @brief #CFP_ConfigType               */
#define BRCM_SWARCH_CFP_WILDCARDKEYCFG_TYPE        (0x7333U) /**< @brief #CFP_WildcardKeyCfgType       */
#define BRCM_SWARCH_CFP_WILDCARDKEYPACKED_TYPE     (0x7334U) /**< @brief #CFP_WildcardKeyPackedType    */
/** @} */

/**
    @brief Magic number for the configuration structure, containing 'ACL0'

    @trace #BRCM_SWREQ_CFP
*/
#define CFP_CONFIG_MAGIC_ID         BCM_PACK32('A', 'C', 'L', '0')

/**
    @brief Maximum number of meters supported in static configuration
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_MAX_INIT_METERS      (84UL)

/**
    @brief Maximum number of short rules supported in static configuration
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_MAX_INIT_SHORT_RULES (256UL)

/**
    @brief Maximum number of long rules supported in static configuration
    This is computed as (sizeof(CFP_ShortRuleCfgType)*CFP_MAX_INIT_SHORT_RULES)/sizeof(CFP_LongRuleCfgType)
    @trace #BRCM_SWREQ_CFP
*/
#define CFP_MAX_INIT_LONG_RULES  (168UL)

/**
    @brief Structure for slice (containing long rules) UDFs for a format

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_LongFormatUDFsType {
    CFP_UDFAddrType udfs[CFP_MAX_SLICE_UDFS]; /**< @brief List of UDFs */
    uint8_t         num;                      /**< @brief Number of valid UDFs.
                                                          This can number can be upto
                                                          #CFP_MAX_SLICE_UDFS for IPv6
                                                          slice where chaining is enabled
                                                          else it can be upto 9.
                                                   @xsd count:udfs */
} CFP_LongFormatUDFsType;
BCM_STATIC_SIZE_ASSERT(CFP_LongFormatUDFsType, 22UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for slice (containing short rules) UDFs for a format

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_ShortFormatUDFsType {
    CFP_UDFAddrType udfs[CFP_SHORT_SLICE_UDFS]; /**< @brief List of UDFs
                                                     @xsd minsize:0 */
    uint8_t         num;                        /**< @brief Number of valid UDFs.
                                                     @xsd count:udfs */
} CFP_ShortFormatUDFsType;
BCM_STATIC_SIZE_ASSERT(CFP_ShortFormatUDFsType, 10UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP Slice configuration

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_SliceCfgType {
    uint8_t                 valid;           /**< @brief Flag indicating that this slice
                                                         is valid.
                                                  @xsd bool;default:false */
    uint8_t                 enableIPv6Chain; /**< @brief Enable IPv6 long rule/chaining.
                                                         Set to 1 to enable and 0 to
                                                         disable. For legacy platforms,
                                                         this can only be enabled on
                                                         slice 0.
                                                  @xsd bool;default:false */
    uint8_t                 enableStateId;   /**< @brief Enable State Id feature on
                                                         this slice. This is not
                                                         available on legacy platforms.
                                                  @xsd constant:0x1 */
    CFP_ShortFormatUDFsType nonIP;           /**< @brief List of non IP UDFs */
    CFP_ShortFormatUDFsType ipv4;            /**< @brief List of IPv4 UDFs */
    CFP_LongFormatUDFsType  ipv6;            /**< @brief List of IPv6 UDFs */
} CFP_SliceCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_SliceCfgType, 45UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name Policer definitions
    @{
    @brief Definitions for CFP policer flags encoded as follows:
    bit9  : Counting mode. 0 means incrementing one per packet,
            1 means incrementing one per byte
    bit8  : Enable packet per second [PPS] mode (0 means bits per second [BPS] mode)
    bit7  : Mark all frames as RED
    bit6  : Enable mark all frames RED
    bit5  : Drop yellow frames
    bit4-3: Policer mode
    bit2  : Coupling flag. Applicable only for MEF policer mode. When set,
            this bit allows tokens to get diverted to excess bucket when
            the commit bucket is full.
    bit1  : Policer Action: 0 means RED packet is dropped.
            1 means RED packet is treated with OB (out of bound) action
    bit0  : Color Mode. 0 means color blind. 1 means color aware.

    @trace #BRCM_SWREQ_CFP
*/
typedef uint16_t CFP_PolicerFlagsType;                /**< @brief typedef for policer flags definitions */
#define CFP_POLICERFLAGS_CM_MASK             (0x1U)   /**< @brief Mask for color mode
                                                           @xsd name:colorBlindMode */
#define CFP_POLICERFLAGS_CM_SHIFT            (0U)     /**< @brief Bit shift for color mode */
#define CFP_POLICERFLAGS_ACT_MASK            (0x2U)   /**< @brief Mask for meter action mode
                                                           @xsd name:policerAction */
#define CFP_POLICERFLAGS_ACT_SHIFT           (1U)     /**< @brief Bit shift for meter action mode */
#define CFP_POLICERFLAGS_CF_MASK             (0x4U)   /**< @brief Mask for coupling flag
                                                           @xsd name:couplingFlag */
#define CFP_POLICERFLAGS_CF_SHIFT            (2U)     /**< @brief Bit shift for coupling flag */
#define CFP_POLICERFLAGS_MODE_MASK           (0x18U)  /**< @brief Mask for policer mode
                                                           @xsd name:policerMode
                                                           @xsd enum:CFP_POLICERMODE_MEF@MEF,CFP_POLICERMODE_DISABLED@Disabled
                                                           @xsd enum:CFP_POLICERMODE_RFC2698@RFC2698,CFP_POLICERMODE_RFC4115@RFC4115 */
#define CFP_POLICERFLAGS_MODE_SHIFT          (3U)     /**< @brief Bit shift for policer mode */
#define CFP_POLICERFLAGS_DROP_YELLOW_MASK    (0x20U)  /**< @brief Mask for drop yellow frames
                                                           @xsd name:dropOnYellow */
#define CFP_POLICERFLAGS_DROP_YELLOW_SHIFT   (5U)     /**< @brief Bit shift for drop yellow frames */
#define CFP_POLICERFLAGS_MARK_RED_EN_MASK    (0x40U)  /**< @brief Mask for mark all frames red enable
                                                           @xsd name:markAllFrameRedEn */
#define CFP_POLICERFLAGS_MARK_RED_EN_SHIFT   (6U)     /**< @brief Bit shift for mark all frame red enable */
#define CFP_POLICERFLAGS_MARK_ALL_RED_MASK   (0x80U)  /**< @brief Mask for mark all frames red
                                                           @xsd name:markAllFrameRed */
#define CFP_POLICERFLAGS_MARK_ALL_RED_SHIFT  (7U)     /**< @brief Bit shift for mark all frame red */
#define CFP_POLICERFLAGS_ENABLE_PPS_MASK     (0x100U) /**< @brief Mask for enable PPS mode
                                                           @xsd name:PPSMode */
#define CFP_POLICERFLAGS_ENABLE_PPS_SHIFT    (8U)     /**< @brief Bit shift for enable PPS mode */
#define CFP_POLICERFLAGS_COUNTING_MODE_MASK  (0x200U) /**< @brief Mask for counting mode
                                                           @xsd name:countingMode */
#define CFP_POLICERFLAGS_COUNTING_MODE_SHIFT (9U)     /**< @brief Bit shift for counting mode */
/** @} */

/**
    @brief Structure for CFP Meter static configuration (packed)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_MeterCfgType {
    uint32_t             cirTkBkt;     /**< @brief Committed token bucket size in bits
                                                   (BPS mode) or packets (PPS mode)
                                            @xsd maxvalue:CFP_METERDEFS_TKBKT_MASK  */
    uint32_t             cirBktSize;   /**< @brief Committed burst size in bytes
                                                   (BPS mode) or packets (PPS mode)
                                            @xsd maxvalue:CFP_METERDEFS_BKTSZ_MASK  */
    uint32_t             cirRefCnt;    /**< @brief Committed information rate in Kbps
                                                   (BPS mode) or packets per second
                                                   (PPS mode)
                                            @xsd maxvalue:CFP_METERDEFS_REFCNT_MASK */
    uint32_t             eirTkBkt;     /**< @brief Excess token bucket size in bits
                                                   (BPS mode) or packets (PPS mode)
                                            @xsd maxvalue:CFP_METERDEFS_TKBKT_MASK  */
    uint32_t             eirBktSize;   /**< @brief Excess burst size in bytes
                                                   (BPS mode) or packets (PPS mode)
                                            @xsd maxvalue:CFP_METERDEFS_BKTSZ_MASK  */
    uint32_t             eirRefCnt;    /**< @brief Excess information rate in Kbps
                                                   (BPS mode) or packets per second
                                                   (PPS mode)
                                            @xsd maxvalue:CFP_METERDEFS_REFCNT_MASK */
    CFP_PolicerFlagsType policerFlags; /**< @brief Policer flags                    */
    uint16_t             resv;         /**< @brief Reserved
                                            @xsd rsvd                               */
} CFP_MeterCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_MeterCfgType, 28UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP color related action definitions
    @{
    @brief Definitions for CFP color related action encoded as follows:
    resv(5) | color(2) | changeColor(1)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_ColorFlagsType;         /**< @brief typedef for CFP color related action definitions */
#define CFP_COLORFLAGS_VAL_SHIFT     (1U)    /**< @brief Bit shift for new color value
                                                  @xsd name:value */
#define CFP_COLORFLAGS_VAL_MASK      (0x6U)  /**< @brief Mask for new color value*/
#define CFP_COLORFLAGS_CHANGE_SHIFT  (0U)    /**< @brief Bit shift for changing color
                                                  @xsd name:change */
#define CFP_COLORFLAGS_CHANGE_MASK   (0x1U)  /**< @brief Mask for changing color */
#define CFP_COLORFLAGS_VAL_GREEN     (0UL)   /**< @brief Green color value */
#define CFP_COLORFLAGS_VAL_YELLOW    (1UL)   /**< @brief Yellow color value */
#define CFP_COLORFLAGS_VAL_RED       (2UL)   /**< @brief Red color value */
/** @} */

/**
    @name CFP action flags 1 definitions
    @{
    @brief Definitions for CFP action flags 1 encoded as follows:
    resv (4) | lpbkEn(1) | bypassSTP(1) | bypassEAP(1) | bypassVLAN(1)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_ActionFlags1Type;             /**< @brief typedef for CFP action flags */
#define CFP_ACTIONFLAGS1_LPBK_EN_SHIFT     (3U)   /**< @brief Bit shift for enabling loopback
                                                       @xsd name:enLpbk */
#define CFP_ACTIONFLAGS1_LPBK_EN_MASK      (0x8U) /**< @brief Mask for enabling loopback */
#define CFP_ACTIONFLAGS1_BYPASS_STP_SHIFT  (2U)   /**< @brief Bit shift for bypass STP
                                                       @xsd name:bypassSTP */
#define CFP_ACTIONFLAGS1_BYPASS_STP_MASK   (0x4U) /**< @brief Mask for bypass STP */
#define CFP_ACTIONFLAGS1_BYPASS_EAP_SHIFT  (1U)   /**< @brief Bit shift for bypass EAP
                                                       @xsd name:bypassEAP */
#define CFP_ACTIONFLAGS1_BYPASS_EAP_MASK   (0x2U) /**< @brief Mask for bypass EAP */
#define CFP_ACTIONFLAGS1_BYPASS_VLAN_SHIFT (0U)   /**< @brief Bit shift for bypass VLAN
                                                       @xsd name:bypassVLAN */
#define CFP_ACTIONFLAGS1_BYPASS_VLAN_MASK  (0x1U) /**< @brief Mask for bypass VLAN */
/** @} */

/**
    @name CFP action flags 2 definitions
    @{
    @brief Definitions for CFP action flags 2 encoded as follows:
    resv (1) | InterruptEn(1) | resv (1)  | CPCPRmrkDis (1) |
    mirOB(1) | mirIB(1) | MAC limit bypass(1) | RED dflt(1)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_ActionFlags2Type;                   /**< @brief typedef for CFP action flags */
#define CFP_ACTIONFLAGS2_INTERRUPT_EN_SHIFT     (6U)    /**< @brief Bit shift for interrupt enable
                                                             @xsd name:interruptEn */
#define CFP_ACTIONFLAGS2_INTERRUPT_EN_MASK      (0x40U) /**< @brief Mask for interrupt  enable */
#define CFP_ACTIONFLAGS2_CPCP_REMARK_DIS_SHIFT  (4U)    /**< @brief Bit shift for C-Tag PCP remark disable
                                                             @xsd name:cPCPRemarkDis */
#define CFP_ACTIONFLAGS2_CPCP_REMARK_DIS_MASK   (0x10U) /**< @brief Mask for C-Tag PCP remark disable */
#define CFP_ACTIONFLAGS2_MIRROR_OB_SHIFT        (3U)    /**< @brief Bit shift for mirroring Out of band data
                                                             @xsd name:mirrorOB */
#define CFP_ACTIONFLAGS2_MIRROR_OB_MASK         (0x8U)  /**< @brief Mask for mirroring out of band data */
#define CFP_ACTIONFLAGS2_MIRROR_IB_SHIFT        (2U)    /**< @brief Bit shift for mirroring In band data
                                                             @xsd name:mirrorIB */
#define CFP_ACTIONFLAGS2_MIRROR_IB_MASK         (0x4U)  /**< @brief Mask for mirroring In band data */
#define CFP_ACTIONFLAGS2_MAC_LIMIT_BYPASS_SHIFT (1U)    /**< @brief Bit shift for MAC limit bypass
                                                             @xsd name:macLimitBypass */
#define CFP_ACTIONFLAGS2_MAC_LIMIT_BYPASS_MASK  (0x2U)  /**< @brief Mask for MAC limit bypass */
#define CFP_ACTIONFLAGS2_USE_DFLT_RED_SHIFT     (0U)    /**< @brief Bit shift for default RED profile
                                                             @xsd name:useDfltRedProfile */
#define CFP_ACTIONFLAGS2_USE_DFLT_RED_MASK      (0x1U)  /**< @brief Mask for default RED profile */
/** @} */

/**
    @name CFP DSCP related action definitions
    @{
    @brief Definitions for CFP DSCP related action encoded as follows:
    resv(1) | change DSCP(1) | new DSCP val (6)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_DSCPFlagsType;            /**< @brief typedef for CFP DSCP related actions */
#define CFP_DSCPFLAGS_VAL_SHIFT      (0U)     /**< @brief Bit shift for new DSCP value
                                                   @xsd name:value */
#define CFP_DSCPFLAGS_VAL_MASK       (0x3FU)  /**< @brief Mask for new DSCP value */
#define CFP_DSCPFLAGS_CHANGE_SHIFT   (6U)     /**< @brief Bit shift for changing DSCP
                                                   @xsd name:change */
#define CFP_DSCPFLAGS_CHANGE_MASK    (0x40U)  /**< @brief Mask for changing DSCP */
/** @} */

/**
    @name CFP TC related action definitions
    @{
    @brief Definitions for CFP TC related action encoded as follows:
    changeTC_O(1) | newTC_O (3)| changeTC(1) | newTC (3)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint8_t CFP_TCFlagsType;             /**< @brief typedef for CFP TC related actions */
#define CFP_TCFLAGS_NEWTC_SHIFT      (0U)    /**< @brief Bit shift for newTC
                                                  @xsd name:newTC */
#define CFP_TCFLAGS_NEWTC_MASK       (0x7U)  /**< @brief Mask for newTC */
#define CFP_TCFLAGS_CHANGETC_SHIFT   (3U)    /**< @brief Bit shift for changeTC
                                                  @xsd name:changeTC */
#define CFP_TCFLAGS_CHANGETC_MASK    (0x8U)  /**< @brief Mask for changeTC */
#define CFP_TCFLAGS_NEWTC_O_SHIFT    (4U)    /**< @brief Bit shift for newTC_O
                                                  @xsd name:newTC_O */
#define CFP_TCFLAGS_NEWTC_O_MASK     (0x70U) /**< @brief Mask for newTC_O */
#define CFP_TCFLAGS_CHANGETC_O_SHIFT (7U)    /**< @brief Bit shift for changeTC_O
                                                  @xsd name:changeTC_O */
#define CFP_TCFLAGS_CHANGETC_O_MASK  (0x80U) /**< @brief Mask for changeTC_O */
/** @} */

/**
    @brief Structure for CFP Action static configuration (packed)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_ActionCfgType {
    CFP_PortMaskType      dstMapIB;         /**< @brief Destination port mask for
                                                        In-Bandwidth profile traffic
                                                 @xsd hex;default:0x0 */
    uint32_t              resv1;            /**< @brief Reserved
                                                 @xsd rsvd */
    CFP_PortMaskType      dstMapOB;         /**< @brief Destination port mask for
                                                        Out-Bandwidth profile traffic
                                                 @xsd hex;default:0x0 */
    uint32_t              resv2;            /**< @brief Reserved
                                                 @xsd rsvd */
    CFP_DSCPFlagsType     dscpIBFlags;      /**< @brief DSCP flags for In-bandwidth
                                                        profile traffic */
    CFP_DSCPFlagsType     dscpOBFlags;      /**< @brief DSCP flags for Out-bandwidth
                                                        profile traffic */
    CFP_ChngFwdMapType    changeFwdMapIB;   /**< @brief Indicates how to use the
                                                        In-Bandwidth destination
                                                        map.
                                                 @xsd default:CFP_CHNGFWDMAP_NON */
    CFP_ChngFwdMapType    changeFwdMapOB;   /**< @brief Indicates how to use the
                                                        Out-Bandwidth destination
                                                        map.
                                                 @xsd default:CFP_CHNGFWDMAP_NON */
    CFP_TCFlagsType       tcFlags;          /**< @brief TC flags */
    CFP_ActionFlags1Type  flags1;           /**< @brief Action flags 1 */
    CFP_ActionFlags2Type  flags2;           /**< @brief Action flags 2 */
    uint8_t               resv;             /**< @brief Reserved
                                                 @xsd rsvd */
    uint16_t              classificationId; /**< @brief Indicates the classification
                                                        identifier for packet forwarded
                                                        to the CPU. Also overloaded as
                                                        the chain ID for legacy IPv6
                                                        chaining feature.
                                                 @xsd default:0 */
    uint16_t              meterIndex;       /**< @brief Meter index. If metering/policing
                                                        is not required, set this to
                                                        65535. Otherwise, set this to
                                                        index of a meter in the meterList.
                                                        If the user wants multiple rules to
                                                        be metered/policed together, all of
                                                        them should have the same meter index.
                                                        If dedicated metering/policing is desired,
                                                        no other rule should have the same meter index.
                                                 @xsd default:65535 */
    CFP_ColorFlagsType    colorFlags;       /**< @brief Color flags */
    uint8_t               reasonCode;       /**< @brief Reason code */
} CFP_ActionCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_ActionCfgType, 32UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP TCAM wildcard key definitions used for static configuration (packed)
    @{
    @brief Definitions for TCAM wildcard Key encoded as follows:
           resv (4) | usrTagValid (1) | usrTagNotZero (1) | resv (26)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint32_t CFP_WildcardKeyPackedType;                      /**< @brief typedef for wildcard TCAM key definitions */
#define CFP_WILDCARDKEYPACKED_USRTAGVALID_MASK    (0x8000000UL)  /**< @brief usrTagValid (i.e. C-Tag present) mask
                                                                      @xsd name:usrTagValid */
#define CFP_WILDCARDKEYPACKED_USRTAGVALID_SHIFT   (27UL)         /**< @brief usrTagValid (i.e. C-Tag present) shift */
#define CFP_WILDCARDKEYPACKED_USRTAGNOTZERO_MASK  (0x4000000UL)  /**< @brief usrTagNotZero (i.e. C-Vid not zero) mask
                                                                      @xsd name:usrTagNotZero */
#define CFP_WILDCARDKEYPACKED_USRTAGNOTZERO_SHIFT (26UL)         /**< @brief usrTagNotZero (i.e. C-Vid not zero) shift */
/** @} */

/**
    @brief TCAM value and mask for wildcard key fields used for static configuration (packed)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_WildcardKeyCfgType {
    CFP_WildcardKeyPackedType value;  /**< @brief Value
                                      */
    CFP_WildcardKeyPackedType mask;   /**< @brief Mask
                                           @xsd mask    */
} CFP_WildcardKeyCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_WildcardKeyCfgType, 8UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP TCAM non-IP key definitions used for static configuration (packed)
    @{
    @brief Definitions for TCAM non-IP Key encoded as follows:
           resv (4) | usrTagValid (1) | usrTagNotZero (1) | resv (9) |
           PPPoESession (1) | ethType(16)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint32_t CFP_NonIPKeyPackedType;                       /**< @brief typedef for non-IP TCAM key definitions */
#define CFP_NONIPKEYPACKED_USRTAGVALID_MASK    (0x8000000UL)   /**< @brief usrTagValid (i.e. C-Tag present) mask
                                                                    @xsd name:usrTagValid */
#define CFP_NONIPKEYPACKED_USRTAGVALID_SHIFT   (27UL)          /**< @brief usrTagValid (i.e. C-Tag present) shift */
#define CFP_NONIPKEYPACKED_USRTAGNOTZERO_MASK  (0x4000000UL)   /**< @brief usrTagNotZero (i.e. C-Vid not zero) mask
                                                                    @xsd name:usrTagNotZero */
#define CFP_NONIPKEYPACKED_USRTAGNOTZERO_SHIFT (26UL)          /**< @brief usrTagNotZero (i.e. C-Vid not zero) shift */
#define CFP_NONIPKEYPACKED_PPPOESESSION_MASK   (0x10000UL)     /**< @brief PPPoE Session mask
                                                                    @xsd name:PPPoESession */
#define CFP_NONIPKEYPACKED_PPPOESESSION_SHIFT  (16UL)          /**< @brief PPPoE Session shift */
#define CFP_NONIPKEYPACKED_ETHTYPE_MASK        (0xFFFFUL)      /**< @brief Ethertype mask
                                                                    @xsd name:etherType */
#define CFP_NONIPKEYPACKED_ETHTYPE_SHIFT       (0UL)           /**< @brief Ethertype shift */
/** @} */

/**
    @brief TCAM value and mask for non-IP key fields used for static configuration (packed)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_NonIPKeyCfgType {
    CFP_NonIPKeyPackedType value;  /**< @brief Value
                                    */
    CFP_NonIPKeyPackedType mask;   /**< @brief Mask
                                        @xsd mask    */
} CFP_NonIPKeyCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_NonIPKeyCfgType, 8UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP TCAM IP key definitions used for static configuration (packed)
    @{
    @brief Definitions for IP Key encoded as follows:
           resv (4) | usrTagValid (1) | usrTagNotZero (1) | resv (4) |
           frag(1) | non-first-frag(1) | auth(1) | TTL(2) | PPPoESession(1) |
           tos(8) | proto(8)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint32_t CFP_IPKeyPackedType;                        /**< @brief typedef for IP TCAM key definitions */
#define CFP_IPKEYPACKED_USRTAGVALID_MASK     (0x8000000UL)   /**< @brief usrTagValid (i.e. C-Tag present) mask
                                                                  @xsd name:usrTagValid */
#define CFP_IPKEYPACKED_USRTAGVALID_SHIFT    (27UL)          /**< @brief usrTagValid (i.e. C-Tag present) shift */
#define CFP_IPKEYPACKED_USRTAGNOTZERO_MASK   (0x4000000UL)   /**< @brief usrTagNotZero (i.e. C-Vid not zero) mask
                                                                  @xsd name:usrTagNotZero */
#define CFP_IPKEYPACKED_USRTAGNOTZERO_SHIFT  (26UL)          /**< @brief usrTagValid (i.e. C-Vid not zero) shift */
#define CFP_IPKEYPACKED_FRAG_MASK            (0x200000UL)    /**< @brief IP fragmentation mask
                                                                  @xsd name:ipFrag */
#define CFP_IPKEYPACKED_FRAG_SHIFT           (21UL)          /**< @brief IP fragmentation shift */
#define CFP_IPKEYPACKED_NONFIRSTFRAG_MASK    (0x100000UL)    /**< @brief IP non first fragment mask
                                                                  @xsd name:ipNonFirstFrag */
#define CFP_IPKEYPACKED_NONFIRSTFRAG_SHIFT   (20UL)          /**< @brief IP non first fragment shift */
#define CFP_IPKEYPACKED_AUTH_MASK            (0x80000UL)     /**< @brief IP authentication mask
                                                                  @xsd name:ipAuthHdr */
#define CFP_IPKEYPACKED_AUTH_SHIFT           (19UL)          /**< @brief IP authentication shift */
#define CFP_IPKEYPACKED_TTL_MASK             (0x60000UL)     /**< @brief TTL mask
                                                                  @xsd name:ttlValue;enum:CFP_TTL_0@0,CFP_TTL_1@1,CFP_TTL_OTHERS@Others
                                                                  @xsd enum:CFP_TTL_255@255 */
#define CFP_IPKEYPACKED_TTL_SHIFT            (17UL)          /**< @brief TTL shift */
#define CFP_IPKEYPACKED_PPPOESESSION_MASK    (0x10000UL)     /**< @brief PPPoE Session mask
                                                                  @xsd name:PPPoESession */
#define CFP_IPKEYPACKED_PPPOESESSION_SHIFT   (16UL)          /**< @brief PPPoE Session shift */
#define CFP_IPKEYPACKED_TOS_MASK             (0xFF00UL)      /**< @brief TOS (type of service) mask
                                                                  @xsd name:ipTypeOfService */
#define CFP_IPKEYPACKED_TOS_SHIFT            (8UL)           /**< @brief TOS (type of service) shift */
#define CFP_IPKEYPACKED_PROTO_MASK           (0xFFUL)        /**< @brief Protocol mask
                                                                  @xsd name:ipProtocol */
#define CFP_IPKEYPACKED_PROTO_SHIFT          (0UL)           /**< @brief Protocol shift */
/** @} */

/**
    @brief TCAM value and mask for IPv4/IPv6 key fields used for static configuration (packed)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_IPKeyCfgType {
    CFP_IPKeyPackedType value; /**< @brief Value
                                */
    CFP_IPKeyPackedType mask;  /**< @brief Mask
                                    @xsd mask    */
} CFP_IPKeyCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_IPKeyCfgType, 8UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Union representing the Key fields used for static configuration (packed)

    @trace #BRCM_SWREQ_CFP
*/
typedef union uCFP_KeyFlagsCfgType {
    CFP_NonIPKeyCfgType    nonIP;     /**< @brief non IP */
    CFP_IPKeyCfgType       ipv4;      /**< @brief IPv4 */
    CFP_IPKeyCfgType       ipv6;      /**< @brief IPv6 */
    CFP_WildcardKeyCfgType wildcard;  /**< @brief Wildcard/Any */
} CFP_KeyFlagsCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_KeyFlagsCfgType, 8UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @name CFP TCAM TCP flags and state id definitions used for static configuration (packed)
    @{
    @brief Definitions for TCAM Key when state id check is enabled:
           state-id (8) | TCP Flags Valid (1) | resv (1) |
           TCP URG flag (1) | TCP ACK flag (1) | TCP PSH flag (1) |
           TCP RST flag (1) | TCP SYN flag (1) | TCP FIN flag (1)

    @trace #BRCM_SWREQ_CFP
*/
typedef uint16_t CFP_TCPStateIdPackedType;                   /**< @brief typedef for TCP flags and state id definitions */
#define CFP_TCPSTATEIDPACKED_STATEID_MASK         (0xFF00U)  /**< @brief Mask for state id field
                                                                  @xsd name:stateId                                     */
#define CFP_TCPSTATEIDPACKED_STATEID_SHIFT        (8UL)      /**< @brief Bit shift for state id                         */
#define CFP_TCPSTATEIDPACKED_TCPFLAGSVALID_MASK   (0x80U)    /**< @brief Mask for TCP flags valid
                                                                  @xsd name:tcpFlagsValid                               */
#define CFP_TCPSTATEIDPACKED_TCPFLAGSVALID_SHIFT  (7U)       /**< @brief Bit shift for TCP flags valid                  */
#define CFP_TCPSTATEIDPACKED_TCPFLAGURG_MASK      (0x20U)    /**< @brief Mask for TCP URG flag
                                                                  @xsd name:tcpFlagURG                                  */
#define CFP_TCPSTATEIDPACKED_TCPFLAGURG_SHIFT     (5U)       /**< @brief Bit shift for TCP URG flag                     */
#define CFP_TCPSTATEIDPACKED_TCPFLAGACK_MASK      (0x10U)    /**< @brief Mask for TCP ACK flag
                                                                  @xsd name:tcpFlagACK                                  */
#define CFP_TCPSTATEIDPACKED_TCPFLAGACK_SHIFT     (4U)       /**< @brief Bit shift for TCP ACK flag                     */
#define CFP_TCPSTATEIDPACKED_TCPFLAGPSH_MASK      (0x8U)     /**< @brief Mask for TCP PSH flag
                                                                  @xsd name:tcpFlagPSH                                  */
#define CFP_TCPSTATEIDPACKED_TCPFLAGPSH_SHIFT     (3U)       /**< @brief Bit shift for TCP PSH flag                     */
#define CFP_TCPSTATEIDPACKED_TCPFLAGRST_MASK      (0x4U)     /**< @brief Mask for TCP RST flag
                                                                  @xsd name:tcpFlagRST                                  */
#define CFP_TCPSTATEIDPACKED_TCPFLAGRST_SHIFT     (2U)       /**< @brief Bit shift for TCP RST flag                     */
#define CFP_TCPSTATEIDPACKED_TCPFLAGSYN_MASK      (0x2U)     /**< @brief Mask for TCP SYN flag
                                                                  @xsd name:tcpFlagSYN                                  */
#define CFP_TCPSTATEIDPACKED_TCPFLAGSYN_SHIFT     (1U)       /**< @brief Bit shift for TCP SYN flag                     */
#define CFP_TCPSTATEIDPACKED_TCPFLAGFIN_MASK      (0x1U)     /**< @brief Mask for TCP FIN flag
                                                                  @xsd name:tcpFlagFIN                                  */
#define CFP_TCPSTATEIDPACKED_TCPFLAGFIN_SHIFT     (0U)       /**< @brief Bit shift for TCP FIN flag                     */
/** @} */

/**
    @brief TCAM value and mask for TCP flags and state id fields used for static configuration (packed)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_TCPStateIdCfgType {
    CFP_TCPStateIdPackedType value; /**< @brief Value */
    CFP_TCPStateIdPackedType mask;  /**< @brief Mask
                                         @xsd mask    */
} CFP_TCPStateIdCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_TCPStateIdCfgType, 4UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP TCAM key with only the pre-defined fields (PDF)

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_KeyPDFCfgType {
    uint8_t               ruleValid;         /**< @brief Flag indicating whether the
                                                         rule is valid (1U) or
                                                         not (0U)
                                                  @xsd bool;default:true */
    CFP_L3FramingType     l3Framing;         /**< @brief L3 framing */
    CFP_L2FramingType     l2Framing;         /**< @brief L2 framing */
    uint8_t               resv;              /**< @brief Reserved
                                                  @xsd rsvd */
    CFP_PortMaskType      ingressPortBitmap; /**< @brief Ingress port bitmap
                                                  @xsd hex;default:0x0 */
    CFP_KeyFlagsCfgType   flags;             /**< @brief Overloaded flags field */
    CFP_CTagType          cTag;              /**< @brief C-Tag */
    CFP_TCPStateIdCfgType tcpStateId;        /**< @brief Overloaded flags 2 field */
    CFP_MACAddrType       macDA;             /**< @brief Destination MAC address */
} CFP_KeyPDFCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_KeyPDFCfgType, 36UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP TCAM key (short rule)

    This is used for short rules in static configuration

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_ShortKeyCfgType {
    CFP_KeyPDFCfgType pdfs;                        /**< @brief PDF values/masks                     */
    CFP_UDFDefType    udfs[CFP_SHORT_SLICE_UDFS];  /**< @brief UDF values/masks                     */
    uint32_t          enabledUDFMap;               /**< @brief Bitmap of enabled UDFs for the slice
                                                               @xsd hex                             */
} CFP_ShortKeyCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_ShortKeyCfgType, 76UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP TCAM long key

    This is used for long rules in static configuration

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_LongKeyCfgType {
    CFP_KeyPDFCfgType  pdfs;                     /**< @brief PDF values/masks                     */
    CFP_UDFDefType     udfs[CFP_MAX_SLICE_UDFS]; /**< @brief UDFs values/masks                    */
    uint32_t           enabledUDFMap;            /**< @brief Bitmap of enabled UDFs for the slice
                                                             @xsd hex                             */
    CFP_MACAddrType    macSA;                    /**< @brief Source MAC address                   */
} CFP_LongKeyCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_LongKeyCfgType, 136UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP short rule

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_ShortRuleCfgType {
    CFP_ShortKeyCfgType  key;      /**< @brief key */
    CFP_ActionCfgType    action;   /**< @brief action */
    CFP_RowType          row;      /**< @brief row number
                                        @xsd default:CFP_ROW_INVALID */
    CFP_SliceType        slice;    /**< @brief slice number */
    uint8_t              resv[5U]; /**< @brief reserved
                                        @xsd rsvd */
} CFP_ShortRuleCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_ShortRuleCfgType, 116UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Structure for CFP long rule

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_LongRuleCfgType {
    CFP_LongKeyCfgType key;      /**< @brief key */
    CFP_ActionCfgType  action;   /**< @brief action */
    CFP_RowType              row;      /**< @brief row number
                                            @xsd default:CFP_ROW_INVALID */
    CFP_SliceType            slice;    /**< @brief slice number */
    uint8_t                  resv[5U]; /**< @brief reserved
                                            @xsd rsvd */
} CFP_LongRuleCfgType;
BCM_STATIC_SIZE_ASSERT(CFP_LongRuleCfgType, 176UL, CFP_MAX_PAYLOAD_SIZE)

/**
    @brief Union representing the total memory available for a combination of long and short rules

    @trace #BRCM_SWREQ_CFP
*/
typedef union uCFP_PackedRulesType {
    CFP_ShortRuleCfgType shortRules[CFP_MAX_INIT_SHORT_RULES]; /**< @brief Short rules */
    CFP_LongRuleCfgType  longRules[CFP_MAX_INIT_LONG_RULES];   /**< @brief Long rules */
} CFP_PackedRulesType;
BCM_STATIC_SIZE_ASSERT(CFP_PackedRulesType, 29696UL, 29696UL)

/**
    @brief Structure for storing the static rules
    The user can have a combination of short and long rules coexisting. A fixed amount of
    memory is used for storing these. The rules at the top of this memory are all short
    rules whereas the long rules are all packed up following the last short rule ensuring
    that {#numShortRules*sizeof(CFP_ShortRuleCfgType) + #numLongRules*sizeof(CFP_LongRuleCfgType)}
    does not exceeded {CFP_MAX_INIT_SHORT_RULES*sizeof(CFP_ShortRuleCfgType)}.
    The first long rule (if #numLongRules is non zero) would be found at index
    {ceil(#numShortRules*sizeof(CFP_ShortRuleCfgType)/sizeof(CFP_LongRuleCfgType))}
    in the #long list.

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_StaticRulesType {
    CFP_PackedRulesType rules;         /**< @brief Union of short and long rules
                                            @xsd struct */
    uint16_t            numShortRules; /**< @brief Number of valid short rules
                                            @xsd count:rules.shortRules */
    uint16_t            numLongRules;  /**< @brief Number of valid long rules
                                            @xsd count:rules.longRules */
} CFP_StaticRulesType;
BCM_STATIC_SIZE_ASSERT(CFP_StaticRulesType, 29700UL, 29700UL)

/**
    @brief Structure for CFP config
    @pyvalidate cfp_validate.ValidateConfig

    @trace #BRCM_SWREQ_CFP
*/
typedef struct sCFP_ConfigType {
    uint32_t                magicId;                         /**< @brief Magic number
                                                                         'ACL0' (checked
                                                                         for validity)
                                                                  @xsd constant:0x41434C30 */
    CFP_SliceCfgType        sliceCfg[CFP_MAX_SLICES];        /**< @brief List of slices
                                                                        @xsd minsize:4 */
    CFP_MeterCfgType        meterList[CFP_MAX_INIT_METERS];  /**< @brief List of meters */
    uint16_t                numMeters;                       /**< @brief Number of valid meters
                                                                   @xsd count:meterList
                                                              */
    uint16_t                resv1;                           /**< @brief Reserved
                                                                  @xsd rsvd */
    CFP_StaticRulesType     ruleList;                        /**< @brief List of rules  */
    CFP_PktLenCorrType      pktLenCorr;                      /**< @brief Packet length
                                                                         correction
                                                                  @xsd default:CFP_PKTLENCORR_NONE */
    uint8_t                 disableSlicePriority;            /**< @brief Flag disabling
                                                                         priority order
                                                                         amongst slices
                                                                  @xsd bool;default:false */
    uint8_t                 resv2[2U];                       /**< @brief Reserved
                                                                  @xsd rsvd */
    CFP_PortMaskType        portEnableMask;                  /**< @brief Bitmask of ports
                                                                         where CFP lookup
                                                                         is enabled
                                                                  @xsd hex;default:0x0 */
    uint16_t                numStreamRows;                   /**< @brief Number of rows reserved for
                                                                         streams/PSFP feature. A value of
                                                                         0 will disable the feature.
                                                                         This parameter will be
                                                                         ignored on legacy platforms.
                                                                  @xsd default:0 */
    uint16_t                numIPMCRows;                     /**< @brief Number of rows reserved for
                                                                         IP multicast feature. A value
                                                                         of 0 will disable the feature.
                                                                         This parameter will be
                                                                         ignored on legacy platforms.
                                                                  @xsd default:0 */
    uint32_t                resv3;                           /**< @brief Reserved
                                                                  @xsd rsvd */
} CFP_ConfigType;
BCM_STATIC_SIZE_ASSERT(CFP_ConfigType, 32256UL, 32256UL)


#endif /* ETHERNET_CFP_TYPES_H */
/** @} */
