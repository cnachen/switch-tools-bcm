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
    @defgroup grp_ethernet_swt_common_ifc Switch Common Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_common_ifc
    @{

    @file ethernet_swt_common.h

    @brief Ethernet Switch Common Interface
    This file contains the interfaces for the Ethernet Switch common

    @version 1.0 Initial version
*/

#ifndef ETHERNET_SWT_COMMON_H
#define ETHERNET_SWT_COMMON_H

#include <ethernet_common.h>
#include <compiler.h>
#include <bcm_utils.h>

/**
    @name Ethernet Common API IDs
    @{
    @brief API IDs for Ethernet Common
*/
#define BRCM_SWARCH_ETHSWT_COMMON_MAX_PAYLOAD_SIZE_MACRO    (0x8701U) /**< @brief #ETHSWT_COMMON_MAX_PAYLOAD_SIZE    */
#define BRCM_SWARCH_ETHSWT_VLAN_INGRESS_FILTER_MODE_TYPE    (0x8702U) /**< @brief #ETHSWT_VLANIngressFilterModeType  */
#define BRCM_SWARCH_ETHSWT_MGMTMODE_TYPE                    (0x8703U) /**< @brief #ETHSWT_MgmtModeType               */
#define BRCM_SWARCH_ETHSWT_PCP_TYPE                         (0x8704U) /**< @brief #ETHSWT_PCPType                    */
#define BRCM_SWARCH_ETHSWT_TE_TYPE                          (0x8705U) /**< @brief #ETHSWT_TEType                     */
#define BRCM_SWARCH_ETHSWT_TC_TYPE                          (0x8706U) /**< @brief #ETHSWT_TCType                     */
#define BRCM_SWARCH_ETHSWT_BRCMHDR_TYPE                     (0x8707U) /**< @brief #ETHSWT_BrcmHdrModeType            */
#define BRCM_SWARCH_ETHSWT_DUMBFWD_TYPE                     (0x8708U) /**< @brief #ETHSWT_DumbFwdModeType            */
#define BRCM_SWARCH_ETHSWT_MAX_MYDA_ENTRIES_MACRO           (0x8709U) /**< @brief #ETHSWT_MAX_MYDA_ENTRIES           */
#define BRCM_SWARCH_ETHSWT_ADDRESSLIMITING_TYPE             (0x870AU) /**< @brief #ETHSWT_AddressLimitingType        */
#define BRCM_SWARCH_ETHSWT_SECURITY_ACTION_TYPE             (0x870BU) /**< @brief #ETHSWT_SecurityActionType         */
#define BRCM_SWARCH_ETHSWT_PORT_ID_TYPE                     (0x870CU) /**< @brief #ETHSWT_PortIDType                 */
#define BRCM_SWARCH_ETHSWT_HW_ID_TYPE                       (0x870DU) /**< @brief #ETHSWT_HwIDType                   */
#define BRCM_SWARCH_ETHSWT_PORTSTATS_TYPE                   (0x870EU) /**< @brief #ETHSWT_PortStatsType              */
#define BRCM_SWARCH_ETHSWT_PORTMASK_TYPE                    (0x870FU) /**< @brief #ETHSWT_PortMaskType               */
#define BRCM_SWARCH_ETHSWT_VLANID_TYPE                      (0x8710U) /**< @brief #ETHSWT_VLANIDType                 */
#define BRCM_SWARCH_ETHSWT_PORT_TYPE                        (0x8711U) /**< @brief #ETHSWT_PortType                   */
#define BRCM_SWARCH_ETHSWT_SWITCH_TYPE                      (0x8712U) /**< @brief #ETHSWT_SwitchType                 */
#define BRCM_SWARCH_ETHSWT_P16_TYPE                         (0x8713U) /**< @brief #ETHSWT_P16Type                    */
/** @} */

/**
    @brief Maximum size of ethernet common message payload

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_COMMON_MAX_PAYLOAD_SIZE       (4UL)

/**
    @brief port 16 related Mask and Shift Macro

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint16_t ETHSWT_P16Type;
#define ETHSWT_P16_PORTMASK_SHIFT            (14U)
#define ETHSWT_P16_TAGMASK_SHIFT             (15U)
#define ETHSWT_P16_PORTMASK_MASK             (1U << ETHSWT_P16_PORTMASK_SHIFT)
#define ETHSWT_P16_TAGMASK_MASK              (1U << ETHSWT_P16_TAGMASK_SHIFT)
#define ETHSWT_P16_SHIFT                     (16U)
/**
    @name Hardware ID type
    @{
    @brief Switch hardware index type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_HwIDType;       /**< @brief Switch hardware ID type */
#define ETHSWT_HW_ID_0      (0UL)       /**< @brief Switch hardware ID 0    */
/** @} */

/**
    @name Port ID type
    @{
    @brief Switch port index type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef ETHER_PortIDType ETHSWT_PortIDType;            /**< @brief Switch port index type */
#define ETHSWT_PORT_ID_INVALID (ETHER_PORT_ID_INVALID) /**< @brief Invalid port index */
/** @} */

/**
    @name Port Mask type
    @{
    @brief Switch port mask type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint64_t ETHSWT_PortMaskType;
/** @} */

/**
    @name VLAN ID type
    @{
    @brief 802.1Q VLAN ID type

    VLAN range 0x0 to 4095 where 0x000 and 0xFFF are reserved.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint16_t ETHSWT_VLANIDType;       /**< @brief 802.1Q VLAN ID type */
#define ETHSWT_VLANID_MIN     (1UL)       /**< @brief Minimum VLAN ID */
#define ETHSWT_VLANID_MAX     (4094UL)    /**< @brief Maximum VLAN ID */
#define ETHSWT_VLANID_MASK    (0xFFFU)
/** @} */

/**
    @name Port type
    @{
    @brief Type of the switch port

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_PortType;   /**< @brief Switch port type */
#define ETHSWT_PORT_STANDARD  (0U)   /**< @brief A standard Port is a normal switch
                                        port connected to a transceiver. */
#define ETHSWT_PORT_HOST      (1U)   /**< @brief Port is connected to Host
                                                    ECU controlling the switch */
#define ETHSWT_PORT_UP_LINK   (2U)   /**< @brief Port is coupling port which is
                                        connected to another coupling
                                        element in the same ECU (to model a
                                        cascade switch). An uplink port
                                        have special behaviour w.r.t
                                        software and hardware. */
/** @} */

/**
    @name Type of the swtich
    @{
    @brief Type of the swtich

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_SwitchType;             /**< @brief Type of the switch */
#define ETHSWT_SWITCH_STANDARD            (0UL)     /**< @brief Standard switch
                                                        is an Ethernet switch
                                                        which operates as standalone switch */
#define ETHSWT_SWITCH_LIGHTSTACK_MASTER   (1UL)     /**< @brief Light stack master
                                                        switch is an Ethernet switch
                                                        which operates as master
                                                        switch in Light stack
                                                        configuration. Refer to
                                                        @ref sec_ref_trm for
                                                        Light stack switch operation */
#define ETHSWT_SWITCH_LIGHTSTACK_SLAVE    (2UL)     /**< @brief Light stack slave
                                                        switch is an Ethernet switch
                                                        which operates as slave
                                                        switch in Light stack
                                                        configuration. Refer to
                                                        @ref sec_ref_trm for
                                                        Light stack switch operation */
/** @} */


/**
    @name Security action
    @{
    @brief If packets try to breach the security,
    then appropriate action should be triggered.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_SecurityActionType;                  /**< @brief Security action */
#define ETHSWT_SECURITY_ACTION_DISABLED              (0U)   /**< @brief None of the action
                                                                 would be triggered, If the
                                                                 security feature is disabled */
#define ETHSWT_SECURITY_ACTION_DROP_PKT              (1U)   /**< @brief Drop-packet */
#define ETHSWT_SECURITY_ACTION_REDIRECT_TO_CPU       (2U)   /**< @brief Redirect to CPU */
#define ETHSWT_SECURITY_ACTION_NORMAL                (3U)   /**< @brief Normal ACL based forwarding */
#define ETHSWT_SECURITY_ACTION_COPY_TO_CPU           (4U)   /**< @brief Copy to CPU */
#define ETHSWT_SECURITY_ACTION_INVALID             (255U)   /**< @brief Invalid action */
/** @} */

/**
    @brief Address limiting configuration for port

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_AddressLimitingType {
    ETHSWT_SecurityActionType overLimitAction;      /**< @brief Indicates the actions
                                                          when the MAC Address limit counter
                                                          of the port is crossed the max
                                                          programmed value, If this field is
                                                          non-zero otherwise address limiting
                                                          is disabled for this port. */
    uint16_t macLearningLimit;                      /**< @brief Port SA Learned Limit
                                                          It defines the maximum number
                                                          of MAC addresses allowed to
                                                          learn on the ingress port.
                                                          The configured value of 0
                                                          will mean no dynamic address
                                                          will be learned on the chip.
                                                          When the maximum limit is set,
                                                          it can't over the #ETHSWT_ARL_SIZE.
                                                          If it is written above the
                                                          #ETHSWT_ARL_SIZE, it will be to
                                                          set to #ETHSWT_ARL_SIZE. */

} ETHSWT_AddressLimitingType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_AddressLimitingType, 3UL, ETHSWT_COMMON_MAX_PAYLOAD_SIZE)

/**
    @name Switch myDA No Of Entries
    @{
    @brief No of Switch myDA Entries

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_MAX_MYDA_ENTRIES        (0x8U)
/** @} */

/**
    @name Dumb forward mode
    @{
    @brief Dumb forward mode

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_DumbFwdModeType;    /**< @brief Dumb forward mode */
#define ETHSWT_DUMBFWD_DISABLE    (0UL)     /**< @brief Dumb forward disable */
#define ETHSWT_DUMBFWD_ENABLE     (1UL)     /**< @brief Dumb forward enable */
/** @} */

/**
    @name Broadcom header mode
    @{
    @brief Broadcom header mode

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_BrcmHdrModeType;    /**< @brief Broadcom header mode */
#define ETHSWT_BRCMHDR_DISABLE    (0UL)     /**< @brief Broadcom header disable */
#define ETHSWT_BRCMHDR_ENABLE     (1UL)     /**< @brief Broadcom header enable */
/** @} */

/**
    @name Traffic class type
    @{
    @brief Traffic class type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef ETHER_TCType ETHSWT_TCType;           /**< @brief Traffic class type */
#define ETHSWT_TC_0       (ETHER_TC_0)        /**< @brief Traffic class 0 */
#define ETHSWT_TC_1       (ETHER_TC_1)        /**< @brief Traffic class 1 */
#define ETHSWT_TC_2       (ETHER_TC_2)        /**< @brief Traffic class 2 */
#define ETHSWT_TC_3       (ETHER_TC_3)        /**< @brief Traffic class 3 */
#define ETHSWT_TC_4       (ETHER_TC_4)        /**< @brief Traffic class 4 */
#define ETHSWT_TC_5       (ETHER_TC_5)        /**< @brief Traffic class 5 */
#define ETHSWT_TC_6       (ETHER_TC_6)        /**< @brief Traffic class 6 */
#define ETHSWT_TC_7       (ETHER_TC_7)        /**< @brief Traffic class 7 */
#define ETHSWT_TC_INVALID (ETHER_TC_INVALID)  /**< @brief Invalid traffic
                                                        class */
#define ETHSWT_TC_MAX     (ETHER_TC_MAX)      /**< @brief Traffic class max */

/** @} */

/**
    @name ETHSWT_TEType
    @{
    @brief Tag Enforcement type in Ingress Broadcom Header/tag

    @note: This should be as per Broadcom Ingress header/tag

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_TEType;       /**< @brief Tag enforcement type */
#define ETHSWT_TE_NONE       (0U)   /**< @brief No enforcement */
#define ETHSWT_TE_UNTAG      (1U)   /**< @brief Untag enforcement */
#define ETHSWT_TE_HEADER     (2U)   /**< @brief Header enforcement */
#define ETHSWT_TE_RESERVED   (3U)   /**< @brief Reserved */
/** @} */

/**
    @name Priority type
    @{
    @brief 802.1Q Priority type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_PCPType;       /**< @brief 802.1Q Priority type */
#define ETHSWT_PCP_0          (0U)   /**< @brief PCP 0 */
#define ETHSWT_PCP_1          (1U)   /**< @brief PCP 1 */
#define ETHSWT_PCP_2          (2U)   /**< @brief PCP 2 */
#define ETHSWT_PCP_3          (3U)   /**< @brief PCP 3 */
#define ETHSWT_PCP_4          (4U)   /**< @brief PCP 4 */
#define ETHSWT_PCP_5          (5U)   /**< @brief PCP 5 */
#define ETHSWT_PCP_6          (6U)   /**< @brief PCP 6 */
#define ETHSWT_PCP_7          (7U)   /**< @brief PCP 7 */
/** @} */

/**
    @name Switch management mode
    @{
    @brief Switch management mode

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_MgmtModeType;  /**< @brief Management mode */
#define ETHSWT_MGMTMODE_DISABLE (0UL)  /**< @brief Unmanaged mode */
#define ETHSWT_MGMTMODE_ENABLE  (1UL)  /**< @brief Managed mode */
/** @} */

/**
    @name VLAN ingress filter mode
    @{
    @brief VLAN ingress filter mode

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_VLANIngressFilterModeType;       /**< @brief VLAN ingress
                                                                   filter mode type */
#define ETHSWT_VLAN_INGRESS_FILTER_MODE_DISABLED   (0U)  /**< @brief Vlan
                                                                   ingress filter mode disabled */
#define ETHSWT_VLAN_INGRESS_FILTER_MODE_ENABLED    (1U)  /**< @brief Vlan
                                                                   ingress filter mode enabled */
/** @} */

/**
    @brief Switch statistics type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PortStatsType {
    uint32_t linkStateChangeCount;      /**< @brief Link state change count */
} ETHSWT_PortStatsType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PortStatsType, 4UL, ETHSWT_COMMON_MAX_PAYLOAD_SIZE)

#endif /* ETHERNET_SWT_COMMON_H */
/** @} */
