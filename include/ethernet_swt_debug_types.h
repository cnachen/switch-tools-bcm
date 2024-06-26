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
    @defgroup grp_ethernet_swt_dbg_types Types
    @ingroup grp_ethernet_swt_dbg_ifc

    @addtogroup grp_ethernet_swt_dbg_types
    @{

    @file ethernet_swt_debug_types.h

    @brief Switch debug types

    @version 1.0 Initial version
*/

#ifndef ETHERNET_SWT_DEBUG_TYPES_H
#define ETHERNET_SWT_DEBUG_TYPES_H

#include <bcm_utils.h>

/**
    @name Switch CORE API IDs
    @{
    @brief API IDs for CORE in Switch
*/
#define BRCM_SWARCH_ETHSWT_DEBUG_CFG_MAGIC_MACRO            (0x8C00U)   /**< @brief #ETHSWT_DEBUG_CFG_MAGIC         */
#define BRCM_SWARCH_ETHSWT_DEBUG_CFG_VER_TYPE               (0x8C01U)   /**< @brief #ETHSWT_DebugCfgVerType         */
#define BRCM_SWARCH_ETHSWT_DEBUG_MIRROR_MODE_TYPE           (0x8C02U)   /**< @brief #ETHSWT_DebugMirrorModeType     */
#define BRCM_SWARCH_ETHSWT_DEBUG_MIRROR_CTL_TYPE            (0x8C03U)   /**< @brief #ETHSWT_DebugMirrorCtlType      */
#define BRCM_SWARCH_ETHSWT_DEBUG_RSPAN_TYPE                 (0x8C04U)   /**< @brief #ETHSWT_DebugRspanType          */
#define BRCM_SWARCH_ETHSWT_DEBUG_MIRROR_FILTER_MODE_TYPE    (0x8C05U)   /**< @brief #ETHSWT_DebugMirrorFilterModeType   */

#define BRCM_SWARCH_ETHSWT_DEBUG_MIRROR_DIR_CFG_TYPE        (0x8C10U)   /**< @brief #ETHSWT_DebugMirrorDirCfgType   */
#define BRCM_SWARCH_ETHSWT_DEBUG_MIRROR_CFG_TYPE            (0x8C11U)   /**< @brief #ETHSWT_DebugMirrorCfgType      */
#define BRCM_SWARCH_ETHSWT_DEBUG_MIB_CFG_TYPE               (0x8C12U)   /**< @brief #ETHSWT_DebugMibCfgType         */
#define BRCM_SWARCH_ETHSWT_DEBUG_CFG_TYPE                   (0x8C13U)   /**< @brief #ETHSWT_DebugCfgType            */

/** @} */


/**
    @brief Debug config magic 'SWTD'

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_DEBUG_CFG_MAGIC        BCM_PACK32('S','W','T','D')

/**
    @name Debug config version
    @{
    @brief Debug config version

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_DebugCfgVerType;
#define ETHSWT_DEBUG_CFG_VER_1_0        (0x00010000UL)  /**< @brief version 1.0 */
/** @} */

/**
    @name Mirroring mode
    @{
    @brief Mirroring mode

    @note Capture port must be set when mirroring mode is not None.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_DebugMirrorModeType;
#define ETHSWT_DEBUG_MIRROR_MODE_NONE        (0U)   /**< @brief Mirroring disabled      */
#define ETHSWT_DEBUG_MIRROR_MODE_LOCAL       (1U)   /**< @brief Local mirroring mode    */
#define ETHSWT_DEBUG_MIRROR_MODE_REMOTE      (2U)   /**< @brief Remote mirroring mode   */
/** @} */

/**
    @name Mirroring controls
    @{
    @brief Mirroring controls

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_DebugMirrorCtlType;
#define ETHSWT_DEBUG_MIRROR_CTL_BLOCK_NON_MIRRORED_MASK     (0x0001U)   /**< @brief Block Non-mirrored traffic on capture port @xsd name:block_non_mirrored  */
#define ETHSWT_DEBUG_MIRROR_CTL_BLOCK_NON_MIRRORED_SHIFT    (0U)        /**< @brief Block Non-mirrored traffic on capture port*/
#define ETHSWT_DEBUG_MIRROR_CTL_L3_ENABLE_MASK              (0x0002U)   /**< @brief L3 forwarded packets to be mirrored for egress ports enable mask  @xsd name:l3_egress   */
#define ETHSWT_DEBUG_MIRROR_CTL_L3_ENABLE_SHIFT             (1U)        /**< @brief L3 forwarded packets to be mirrored for egress ports enable shift  */
/** @} */

/**
    @name Mirroring RSPAN type
    @{
    @brief Mirroring RSPAN type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_DebugRspanType;
#define ETHSWT_DEBUG_RSPAN_CFG_MODE_MASK            (0x00000003UL)  /**< @brief RSPAN config mode  @xsd default:0                   */
#define ETHSWT_DEBUG_RSPAN_CFG_MODE_SHIFT           (0UL)           /**< @brief RSPAN config mode shift                             */
#define ETHSWT_DEBUG_RSPAN_CFG_MODE_STD             (0UL)           /**< @brief Standard RSPAN mode                                 */
#define ETHSWT_DEBUG_RSPAN_CFG_MODE_1               (1UL)           /**< @brief RSPAN mode with customer VLAN preserved             */
#define ETHSWT_DEBUG_RSPAN_CFG_MODE_2               (2UL)           /**< @brief RSPAN mode with customer VLAN and 6 byte metadata   */
#define ETHSWT_DEBUG_RSPAN_DST_MODE_MASK            (0x0000000CUL)  /**< @brief Final destination mode mask  @xsd default:0         */
#define ETHSWT_DEBUG_RSPAN_DST_MODE_SHIFT           (2UL)           /**< @brief Final destination mode shift                        */
#define ETHSWT_DEBUG_RSPAN_DST_MODE_NONE            (0UL)           /**< @brief Not final destination                               */
#define ETHSWT_DEBUG_RSPAN_DST_MODE_FINAL           (1UL)           /**< @brief Final destination mode with RSPAN VLAN and ether type stripped off */
#define ETHSWT_DEBUG_RSPAN_DST_MODE_FINAL_RAW       (2UL)           /**< @brief Final destination mode with raw bytes sent out      */
#define ETHSWT_DEBUG_RSPAN_CFI_MASK                 (0x00000010UL)  /**< @brief RSPAN CFI  @xsd default:false                       */
#define ETHSWT_DEBUG_RSPAN_CFI_SHIFT                (4UL)           /**< @brief RSPAN CFI                                           */
#define ETHSWT_DEBUG_RSPAN_EAP_DROP_ENABLE_MASK     (0x00000020UL)  /**< @brief EAP drop enable flag  @xsd name:eap_drop            */
#define ETHSWT_DEBUG_RSPAN_EAP_DROP_ENABLE_SHIFT    (5U)            /**< @brief EAP drop enable flag                                */
#define ETHSWT_DEBUG_RSPAN_SPT_DROP_ENABLE_MASK     (0x00000040UL)  /**< @brief SPT drop enable flag  @xsd name:spt_drop            */
#define ETHSWT_DEBUG_RSPAN_SPT_DROP_ENABLE_SHIFT    (6U)            /**< @brief SPT drop enable flag                                */
#define ETHSWT_DEBUG_RSPAN_VLAN_MASK                (0x0FFF0000UL)  /**< @brief RSPAN VLAN Mask @xsd default:0                      */
#define ETHSWT_DEBUG_RSPAN_VLAN_SHIFT               (16UL)          /**< @brief RSPAN VLAN shift                                    */
#define ETHSWT_DEBUG_RSPAN_PCP_MASK                 (0x70000000UL)  /**< @brief RSPAN PCP Mask @xsd default:0                       */
#define ETHSWT_DEBUG_RSPAN_PCP_SHIFT                (28UL)          /**< @brief RSPAN PCP shift                                     */
#define ETHSWT_DEBUG_RSPAN_PCP_EN_MASK              (0x80000000UL)  /**< @brief RSPAN PCP enable flag @xsd default:false            */
#define ETHSWT_DEBUG_RSPAN_PCP_EN_SHIFT             (31UL)          /**< @brief RSPAN PCP enable flag                               */
/** @} */

/**
    @name Mirroring RSPAN type
    @{
    @brief Mirroring RSPAN type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint16_t ETHSWT_DebugMirrorFilterModeType;
#define ETHSWT_DEBUG_MIRROR_FILTER_MODE_ALL          (0U)   /**< @brief All packets to be mirrored                  */
#define ETHSWT_DEBUG_MIRROR_FILTER_MODE_MAC_DA       (1U)   /**< @brief Packets with specific MAC DA are mirrored   */
#define ETHSWT_DEBUG_MIRROR_FILTER_MODE_MAC_SA       (2U)   /**< @brief Packets with specific MAC SA are mirrored   */
#define ETHSWT_DEBUG_MIRROR_FILTER_MODE_VLAN         (3U)   /**< @brief Packets with specific VLAN are mirrored     */
/** @} */

/**
    @brief Mirroring directional config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMirrorDirCfgType {
    uint64_t                            portMask;       /**< @brief Port mask   @xsd hex;default:0x0            */
    uint16_t                            pktDivider;     /**< @brief Packet dividor @xsd default:0;maxValue:1023 */
    ETHSWT_DebugMirrorFilterModeType    filter;         /**< @brief Filter mode @xsd default:ALL                */
    uint16_t                            vlan;           /**< @brief Filter VLAN  @xsd default:0;maxValue:4094   */
    uint8_t                             mac[6U];        /**< @brief Filter MAC
                                                             @xsd type:mac;default:00:00:00:00:00:00            */
    uint8_t                             reserved[44U];  /**< @brief @xsd rsvd                                   */
} ETHSWT_DebugMirrorDirCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMirrorDirCfgType, 64UL, 64UL)

/**
    @brief Mirroring config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMirrorCfgType {
    ETHSWT_DebugMirrorModeType      mode;       /**< @brief Mirroring mode @xsd default:NONE            */
    ETHSWT_DebugMirrorCtlType       control;    /**< @brief Mirroring control                           */
    uint16_t                        capPort;    /**< @brief capture port @xsd maxvalue:16;minvalue:0    */
    ETHSWT_DebugRspanType           rspan;      /**< @brief RSPAN Configuration                         */
    uint8_t                         chipId;     /**< @brief RSPAN Chip ID @xsd default:0;maxValue:15    */
    uint8_t                         reserved0;  /**< @brief @xsd rsvd                                   */
    uint16_t                        etherType;  /**< @brief RSPAN Ether type  @xsd hex;default:0x0      */
    uint32_t                        reserved1[3UL];/**< @brief @xsd rsvd                                */
    ETHSWT_DebugMirrorDirCfgType    ingress;    /**< @brief ingress configuration                       */
    ETHSWT_DebugMirrorDirCfgType    egress;     /**< @brief egress configuration                        */
    uint32_t                        reserved2[26UL];/**< @brief @xsd rsvd                               */
} ETHSWT_DebugMirrorCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMirrorCfgType, 256UL, 256UL)

/**
    @brief MIB config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugMibCfgType {
    uint32_t            refreshInterval;        /**< @brief MIB referesh interval in milliseconds
                                                                @xsd default:100                    */
    uint32_t            reserved[61UL];         /**< @brief @xsd rsvd                               */
} ETHSWT_DebugMibCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugMibCfgType, 248UL, 248UL)

/**
    @brief Switch debug config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_DebugCfgType {
    uint32_t                        magic;          /**< @brief @xsd constant:ETHSWT_DEBUG_CFG_MAGIC    */
    ETHSWT_DebugCfgVerType          version;        /**< @brief @xsd constant:ETHSWT_DEBUG_CFG_VER_1_0  */
    ETHSWT_DebugMibCfgType          mib;            /**< @brief MIB configuration                       */
    ETHSWT_DebugMirrorCfgType       mirror;         /**< @brief Mirroring configuration                 */
    uint32_t                        reserved[768UL];/**< @brief @xsd rsvd                               */
} ETHSWT_DebugCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_DebugCfgType, 3584UL, 3584UL)


#endif /* ETHERNET_SWT_DEBUG_TYPES_H */
/** @} */
