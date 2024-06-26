/*****************************************************************************
 Copyright 2016-2023 Broadcom Limited.  All rights reserved.

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
  @addtogroup grp_ets_ifc
  @{
  @file ets_config.h
  @brief Configuration data structure for the Ethernet TimeSync subsystem

  This file provides the definition of the configuration for Ethernet TimeSync
  subsystem which is used to provide the required initialization parameters
  via the ETS_Init() API

  @version 1.25 Imported from MS Word document
*/

#ifndef ETS_CONFIG_H
#define ETS_CONFIG_H

#include <stdint.h>
#include <compiler.h>
#include <ethernet_ets.h>

/**
    @name ETS Library API IDs
    @{
    @brief API IDs for ETS Library
 */
#define BRCM_SWARCH_ETS_CONFIGV1MAGIC_MACRO   (0x8701U)    /**< @brief #ETS_CONFIGV1_MAGIC_ID    */
#define BRCM_SWARCH_ETS_CLOCKMODE_TYPE        (0x8703U)    /**< @brief #ETS_ClockModeType        */
#define BRCM_SWARCH_ETS_OPERLOGPDELAY_TYPE    (0x8705U)    /**< @brief #ETS_OperLogPdelayType    */
#define BRCM_SWARCH_ETS_OPERLOGSYNC_TYPE      (0x8706U)    /**< @brief #ETS_OperLogSyncType      */
#define BRCM_SWARCH_ETS_INTFCONFIGV1_TYPE     (0x8707U)    /**< @brief #ETS_IntfConfigV1Type     */
#define BRCM_SWARCH_ETS_CONFIG_TYPE           (0x8708U)    /**< @brief #ETS_ConfigType           */
#define BRCM_SWARCH_ETS_OPERMODE_TYPE         (0x8709U)    /**< @brief #ETS_OperModeType         */
#define BRCM_SWARCH_ETS_DOMAININTFCONFIG_TYPE (0x870BU)    /**< @brief #ETS_DomainIntfConfigType */
#define BRCM_SWARCH_ETS_DOMAINCONFIGV1_TYPE   (0x870CU)    /**< @brief #ETS_DomainConfigV1Type   */
#define BRCM_SWARCH_ETS_TIMESCALE_TYPE        (0x8710U)    /**< @brief #ETS_TimescaleType        */
#define BRCM_SWARCH_ETS_INTFCONFIGV2_TYPE     (0x8711U)    /**< @brief #ETS_IntfConfigV2Type     */
#define BRCM_SWARCH_ETS_DOMAINCONFIGV2_TYPE   (0x8712U)    /**< @brief #ETS_DomainConfigV2Type   */
#define BRCM_SWARCH_ETS_CONFIGV2MAGIC_MACRO   (0x8713U)    /**< @brief #ETS_CONFIGV2_MAGIC_ID    */
#define BRCM_SWARCH_ETS_CONFIGV1_TYPE         (0x8714U)    /**< @brief #ETS_ConfigV1Type         */
#define BRCM_SWARCH_ETS_CONFIGV2_TYPE         (0x8715U)    /**< @brief #ETS_ConfigV2Type         */
#define BRCM_SWARCH_ETS_CONFIG_IMAGE_ID_MACRO (0x8716U)    /**< @brief #ETS_CONFIG_IMAGE_ID      */
#define BRCM_SWARCH_ETS_VLANTAGPKT_TYPE       (0x8717U)    /**< @brief #ETS_VlanTagPktType       */
/** @} */


/**
    @name ETS_VlanTagPktType
    @{
    @brief ETS pcp and vlan mask and shift
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef uint16_t ETS_VlanTagPktType;         /**< @brief <3 Bit pcp><1 Bit Reserve><12 Bit Vid>*/
#define ETS_VLANTAGPKT_VLAN_MASK    (0xFFFU) /**< @brief Mask value to extract VLAN Id from pcpVlan */
#define ETS_VLANTAGPKT_VLAN_SHIFT   (0U)     /**< @brief Shift value to extract VLAN Id from pcpVlan */
#define ETS_VLANTAGPKT_PCP_MASK     (0xE000U)/**< @brief Mask value to extract PCP from pcpVlan  */
#define ETS_VLANTAGPKT_PCP_SHIFT    (13U)    /**< @brief Shift value to extract PCP from pcpVlan  */

/**< @brief Extract VLAN Id from pcpVlan config*/
#define ETS_VLANTAGPKT_GET_VLAN_ID(pcpVlan)     (((pcpVlan) & ETS_VLANTAGPKT_VLAN_MASK) >> ETS_VLANTAGPKT_VLAN_SHIFT)
/**< @brief Extract pcp from  pcpVlan config*/
#define ETS_VLANTAGPKT_GET_PCP(pcpVlan)         (((pcpVlan) & ETS_VLANTAGPKT_PCP_MASK) >> ETS_VLANTAGPKT_PCP_SHIFT)
/** @} */

/**
    @name ETS_OperModeType
    @{
    @brief ETS Operational Mode
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef uint8_t ETS_OperModeType;      /**< @brief typedef for ETS Operational Mode */
#define ETS_OPERMODE_AVNU         (1U) /**< @brief AVnu mode */
#define ETS_OPERMODE_IEEE_2011    (2U) /**< @brief IEEE 802.1AS 2011 (single domain) */
#define ETS_OPERMODE_IEEE_2020    (3U) /**< @brief IEEE 802.1AS 2020 (multiple domains) */
#define ETS_OPERMODE_MAX          (ETS_OPERMODE_IEEE_2020) /**< @brief IEEE 802.1AS 2020 (multiple domains) */
/** @} */

/**
    @name ETS_ClockModeType
    @{
    @brief ETS Clock Mode
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef uint8_t ETS_ClockModeType;      /**< @brief typedef for ETS Admin Mode*/
#define ETS_CLOCKMODE_GM           (0U) /**< @brief Grandmaster mode */
#define ETS_CLOCKMODE_SLAVE        (1U) /**< @brief Slave mode */
/** @} */

/**
    @name ETS_OperLogPdelayType
    @{
    @brief Allowed values of operational logarithmic pdelay intervals
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef int32_t ETS_OperLogPdelayType;  /**< @brief typedef for oper pDelay intervals */
#define ETS_OPERLOGPDELAY_1S   (0L)     /**< @brief 1s operational pDelay period*/
#define ETS_OPERLOGPDELAY_2S   (1L)     /**< @brief 2s operational pDelay period*/
#define ETS_OPERLOGPDELAY_4S   (2L)     /**< @brief 4s operational pDelay period*/
#define ETS_OPERLOGPDELAY_8S   (3L)     /**< @brief 8s operational pDelay period*/
#define ETS_OPERLOGPDELAY_INF  (127L)   /**< @brief Operational pDelay disabled */
#define ETS_OPERLOGPDELAY_MIN  ETS_OPERLOGPDELAY_1S /**< @brief Operational
                                                         logarithmic pdelay
                                                         interval with
                                                         minimum period */
#define ETS_OPERLOGPDELAY_MAX  ETS_OPERLOGPDELAY_8S /**< @brief Operational
                                                         logarithmic pdelay
                                                         interval with
                                                         maximum period */
/** @} */

/**
    @name ETS_OperLogSyncType
    @{
    @brief Allowed values of operational logarithmic sync intervals
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef int32_t ETS_OperLogSyncType;    /**< @brief typedef for oper sync intervals */
#define ETS_OPERLOGSYNC_125MS     (-3L) /**< @brief 125ms oper sync period */
#define ETS_OPERLOGSYNC_250MS     (-2L) /**< @brief 250ms oper sync period */
#define ETS_OPERLOGSYNC_500MS     (-1L) /**< @brief 500ms oper sync period */
#define ETS_OPERLOGSYNC_1S        (0L)  /**< @brief 1s oper sync period    */
#define ETS_OPERLOGSYNC_MAX       ETS_OPERLOGSYNC_1S /**< @brief Operational
                                                          logarithmic sync
                                                          interval with
                                                          maximum period */
#define ETS_OPERLOGSYNC_MIN       ETS_OPERLOGSYNC_125MS /**< @brief Operational
                                                             logarithmic sync
                                                             interval with
                                                             minimum period */
/** @} */

/**
    @name ETS_TimescaleType
    @{
    @brief ETS Timescale
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef uint8_t ETS_TimescaleType;      /**< @brief typedef for ETS Timescale */
#define ETS_TIMESCALE_PTP          (0U) /**< @brief Timescale PTP */
#define ETS_TIMESCALE_ARB          (1U) /**< @brief Timescale ARB (arbitrary) */
/** @} */

/**
    @brief ETS Config Image ID
    @trace #BRCM_SWREQ_ETS_TYPES

    Image ID for ETS configuration
*/
#define ETS_CONFIG_IMAGE_ID         (0xBC20U)  /**< @brief ETS Config Image ID */

/**
    @brief Configuration structure magic number
    @trace #BRCM_SWREQ_ETS_TYPES

    Magic number for the configuration structure, containing 'GPTP'
*/
#define ETS_CONFIGV1_MAGIC_ID       (0x50545047UL)

/**
    @brief Configuration V2 structure magic number
    @trace #BRCM_SWREQ_ETS_TYPES

    Magic number for the configuration structure, containing 'PTP2'
*/
#define ETS_CONFIGV2_MAGIC_ID       (0x32505450UL)

/**
    @brief Per interface configuration
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef struct sETS_IntfConfigV1Type {
    uint8_t            hwPortNum;             /**< @brief Hardware port
                                                   corresponding to the
                                                   interface */

    ETS_LogIntervalType    initLogPdelayInterval; /**< @brief Initial PDelay
                                                   interval in logarithmic base
                                                   2 format*/

    ETS_OperLogPdelayType  avnuOperLogPdelayInterval; /**< @brief Operational PDelay
                                                   interval in logarithmic base
                                                   2 format. Only applicable for AVnu
                                                   mode */

    uint32_t           avnuNbrPropDelay;          /**< @brief Neighbour propagation
                                                   delay in nanoseconds. Only applicable
                                                   in AVnu mode */

    int32_t            avnuNbrRateRatio;          /**< @brief Neighbour rate ratio
                                                   (stored as 2^30 scale factor
                                                   fixed point). Only applicable
                                                   in AVnu mode */

    uint16_t           allowedLostResponses;  /**< @brief Maximum number of
                                                   PDelay Request messages for
                                                   which a valid response is not
                                                   received, above which a port
                                                   is considered to not be
                                                   exchanging peer delay
                                                   messages with its neighbor */

    uint8_t                allowedFaults;         /**< @brief Maximum number of
                                                       instances where computed
                                                       delay exceeds the threshold
                                                       above which port is considered
                                                       not capable of interoperating
                                                       with its neighbor */

    uint32_t               delayThreshold;        /**< @brief Delay threshold */

    int16_t                delayAsymmetry;        /**< @brief Delay asymmetry */

    uint16_t               ingressLatencyNs;      /**< @brief Ingress latency (ns) */

    uint16_t               egressLatencyNs;       /**< @brief Egress latency (ns) */

} COMP_PACKED ETS_IntfConfigV1Type;

/**
    @brief Per interface configuration
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef struct sETS_IntfConfigV2Type {
    uint8_t            hwPortNum;             /**< @brief Hardware port
                                                   corresponding to the
                                                   interface */

    ETS_LogIntervalType    initLogPdelayInterval; /**< @brief Initial PDelay
                                                   interval in logarithmic base
                                                   2 format*/

    ETS_OperLogPdelayType  avnuOperLogPdelayInterval; /**< @brief Operational PDelay
                                                   interval in logarithmic base
                                                   2 format. Only applicable for AVnu
                                                   mode */

    uint32_t           avnuNbrPropDelay;          /**< @brief Neighbour propagation
                                                   delay in nanoseconds. Only applicable
                                                   in AVnu mode */

    int32_t            avnuNbrRateRatio;          /**< @brief Neighbour rate ratio
                                                   (stored as 2^30 scale factor
                                                   fixed point). Only applicable
                                                   in AVnu mode */

    uint16_t           allowedLostResponses;  /**< @brief Maximum number of
                                                   PDelay Request messages for
                                                   which a valid response is not
                                                   received, above which a port
                                                   is considered to not be
                                                   exchanging peer delay
                                                   messages with its neighbor */

    uint8_t                allowedFaults;         /**< @brief Maximum number of
                                                       instances where computed
                                                       delay exceeds the threshold
                                                       above which port is considered
                                                       not capable of interoperating
                                                       with its neighbor. Not used
                                                       currently */

    uint32_t               delayThreshold;        /**< @brief Delay threshold */

    int16_t                delayAsymmetry;        /**< @brief Delay asymmetry. Not used
                                                       currently. */

    uint16_t               ingressLatencyNs;      /**< @brief Ingress latency (ns). Not used
                                                       currently. */

    uint16_t               egressLatencyNs;       /**< @brief Egress latency (ns). Not used
                                                       currently. */

    uint32_t               enableCMLDS;           /**< @brief Flag indicating whether
                                                       CMLDs is enabled or not. Only
                                                       applicable in IEEE 802.1AS
                                                       2020 mode */

    uint32_t               rsvd[4U];              /**< @brief Reserved for future use */
} COMP_PACKED ETS_IntfConfigV2Type;

/**
    @brief Per domain per interface configuration
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef struct sETS_DomainIntfConfigType {
    uint32_t            portEnable;             /**< @brief Indicates whether the
                                                     port is enabled for ETS operation */

    ETS_RoleType        avnuPortRole;           /**< @brief Port gPTP role.
                                                     Applicable in Avnu mode or if IEEE
                                                     2020 mode has extPortConfigModeEnable
                                                     set to true */

    ETS_LogIntervalType initLogSyncInterval;    /**< @brief Initial Sync interval
                                                     in logarithmic base 2
                                                     format*/

    ETS_OperLogSyncType avnuOperLogSyncInterval; /**< @brief Operational Sync
                                                     interval in logarithmic base
                                                     2 format. Applicable only for end
                                                     points */

    uint8_t             syncReceiptTimeout;     /**< @brief Intervals without
                                                     receiving sync before
                                                     declaring loss of sync.
                                                     Applicable only in slave mode */

    ETS_LogIntervalType initLogAnnInterval;     /**< @brief Initial Announce interval
                                                     in logarithmic base 2
                                                     format*/

    uint8_t             announceReceiptTimeout; /**< @brief Intervals without
                                                     receiving announce before
                                                     declaring loss of announce
                                                     and rerunning BMCA if needed */

    ETS_LogIntervalType initLogGptpCapInterval; /**< @brief Initial gPTP capable
                                                     interval in logarithmic base
                                                     2 format*/

    uint8_t             gptpCapReceiptTimeout;  /**< @brief Intervals without
                                                     receiving gPTP capable TLV
                                                     before declaring that the
                                                     neighbour is not capable
                                                     of gPTP */

} COMP_PACKED ETS_DomainIntfConfigType;

/**
    @brief Domain configuration information received from framework/application
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef struct sETS_DomainConfigV1Type {
    ETS_DomainType           domainNumber;                /**< @brief Domain number */

    uint32_t                 domainEnable;                /**< @brief Flag indicating
                                                               whether the domain is
                                                               enabled or not.
                                                               Applicable only in IEEE-2020
                                                               mode  */

    ETS_SystemIdentityType   systemIdentity;              /**< @brief System Identity.
                                                               application only in IEEE
                                                               mode */

    ETS_TimescaleType        timescale;                   /**< @brief Timescale.
                                                               Applicable only in IEEE-2020
                                                               mode  */

    ETS_RedundancyStateType  initState;                   /**< @brief Initial status of
                                                               the domain. Applicable only
                                                               in IEEE-2020 mode  */

    ETS_ClockModeType        avnuClockMode;               /**< @brief Clock mode. Only
                                                               applicable in Avnu mode */

    uint8_t                  avnuSyncAbsenceTimeout;      /**< @brief Duration to wait for
                                                               GM to appear on startup
                                                               before operating as proxy.
                                                               Only applicable for bridge
                                                               in AVnu slave mode */

    int32_t                  avnuGmRateRatio;             /**< @brief Grandmaster rate
                                                               ratio (stored as 2^30
                                                               scale factor fixed point).
                                                               Only applicable in AVnu
                                                               mode */

    ETS_DomainIntfConfigType intfCfg[ETS_MAX_INTERFACES]; /**< @brief Per port
                                                               configuration */
} COMP_PACKED ETS_DomainConfigV1Type;

/**
    @brief Domain configuration information received from framework/application
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef struct sETS_DomainConfigV2Type {
    ETS_DomainType           domainNumber;                /**< @brief Domain number */

    uint32_t                 domainEnable;                /**< @brief Flag indicating
                                                               whether the domain is
                                                               enabled or not.
                                                               Applicable only in IEEE-2020
                                                               mode  */

    ETS_SystemIdentityType   systemIdentity;              /**< @brief System Identity.
                                                               application only in IEEE
                                                               mode */

    ETS_TimescaleType        timescale;                   /**< @brief Timescale.
                                                               Applicable only in IEEE-2020
                                                               mode  */

    ETS_RedundancyStateType  initState;                   /**< @brief Initial status of
                                                               the domain. Applicable only
                                                               in IEEE-2020 mode. Not used
                                                               currently. */

    ETS_ClockModeType        avnuClockMode;               /**< @brief Clock mode.
                                                               Applicable in Avnu mode or
                                                               if IEEE 2020 mode
                                                               has extPortConfigModeEnable
                                                               set to true */

    uint8_t                  avnuSyncAbsenceTimeout;      /**< @brief Duration to wait for
                                                               GM to appear on startup
                                                               before operating as proxy.
                                                               Only applicable for bridge
                                                               in AVnu slave mode */

    int32_t                  avnuGmRateRatio;             /**< @brief Grandmaster rate
                                                               ratio (stored as 2^30
                                                               scale factor fixed point).
                                                               Only applicable in AVnu
                                                               mode */

    ETS_DomainIntfConfigType intfCfg[ETS_CFG_MAX_INTERFACES]; /**< @brief Per port
                                                               configuration */

    uint32_t                 extPortConfigModeEnable;     /**< @brief Flag indicating whether
                                                               external port configuration mode
                                                               is enabled or not.
                                                               Applicable only in IEEE-2020
                                                               mode  */
    ETS_VlanTagPktType       pcpVlan;                     /**< @brief <3 Bit pcp><1 Bit Vlan Enabled or Disabled>
                                                               <12 Bit Vid> */
    uint16_t                 rsvd[7U];                    /**< @brief Reserved for future use */
} COMP_PACKED ETS_DomainConfigV2Type;

/**
    @brief Configuration information received from framework/application
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef struct sETS_ConfigV1Type {
    uint32_t             magicId;                     /**< @brief Magic number
                                                           'GPTP' (checked for
                                                           validity) */

    ETS_OperModeType     operMode;                    /**< @brief Operational mode */

    uint32_t             globalEnable;                /**< @brief Global admin
                                                           mode */

    ETS_TimeSourceType   timeSource;                  /**< @brief Time source.
                                                           Only applicable in
                                                           IEEE mode */

    uint32_t             syncLocked;                  /**< @brief Flag indicating whether
                                                           SyncLocked feature is enabled
                                                           or not */

    uint32_t             boundaryModeEnable;          /**< @brief Flag indicating
                                                           that boundary mode
                                                           is enabled. Only
                                                           applicable for a
                                                           switch in slave mode */

    uint32_t             numInterfaces;               /**< @brief Number of
                                                           valid interfaces */

    ETS_IntfConfigV1Type   intfCfg[ETS_MAX_INTERFACES]; /**< @brief Per port
                                                           configuration */

    uint32_t             numDomains;                  /**< @brief Number of
                                                           valid domains */

    ETS_DomainConfigV1Type domainCfg[ETS_MAX_DOMAINS];  /**< @brief Per domain
                                                           configuration */
} COMP_PACKED ETS_ConfigV1Type;

/**
    @brief Configuration information received from framework/application
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef struct sETS_ConfigV2Type {
    uint32_t               magicId;                     /**< @brief Magic number
                                                             'PTP2' (checked for
                                                             validity) */

    ETS_OperModeType       operMode;                    /**< @brief Operational mode */

    uint32_t               globalEnable;                /**< @brief Global admin
                                                             mode */

    ETS_TimeSourceType     timeSource;                  /**< @brief Time source.
                                                             Only applicable in
                                                             IEEE mode */

    uint32_t               syncLocked;                  /**< @brief Flag indicating whether
                                                           SyncLocked feature is enabled
                                                           or not. Not used currently */

    uint32_t               boundaryModeEnable;          /**< @brief Flag indicating
                                                             that boundary mode
                                                             is enabled. Only
                                                             applicable for a
                                                             switch in slave mode */

    uint32_t               numInterfaces;               /**< @brief Number of
                                                              valid interfaces */

    ETS_IntfConfigV2Type   intfCfg[ETS_CFG_MAX_INTERFACES]; /**< @brief Per port
                                                             configuration */

    uint32_t               numDomains;                  /**< @brief Number of
                                                             valid domains */

    ETS_DomainConfigV2Type domainCfg[ETS_CFG_MAX_DOMAINS];  /**< @brief Per domain
                                                             configuration */

    uint32_t               rsvd[4U];                    /**< @brief Reserved for future use */
} COMP_PACKED ETS_ConfigV2Type;

/**
    @brief ETS Configuration Type

    @trace #BRCM_SWREQ_ETS_TYPES
 */
typedef union uETS_ConfigType {
    ETS_ConfigV1Type cfgV1;
    ETS_ConfigV2Type cfgV2;
} ETS_ConfigType;

#endif /* ETS_CONFIG_H */
/** @} */
