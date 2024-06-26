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
    @defgroup grp_ethernet_est_ifc EST (Enhancements for Scheduled Traffic) abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_est_ifc
    @{

    @file ethernet_est_types.h

    @brief EST Interface
    This file contains the interfaces for the Ethernet abstract for EST

    @version 1.0 Initial version
*/

#ifndef ETHERNET_EST_TYPES_H
#define ETHERNET_EST_TYPES_H

#include <ethernet_common.h>
#include <bcm_utils.h>

/**
    @name Ethernet Service EST API IDs
    @{
    @brief API IDs for EST in Ethernet Service
*/
#define BRCM_SWARCH_EST_MAX_RPC_PAYLOAD_SIZE_MACRO       (0x8C01U) /**< @brief #EST_MAX_RPC_PAYLOAD_SIZE        */
#define BRCM_SWARCH_EST_CFG_MAX_PORTS_MACRO              (0x8C02U) /**< @brief #EST_CFG_MAX_PORTS               */
#define BRCM_SWARCH_EST_CFG_SUPPORTED_LIST_MAX_MACRO     (0x8C03U) /**< @brief #EST_CFG_SUPPORTED_LIST_MAX      */
#define BRCM_SWARCH_EST_CONFIG_MAGIC_ID_MACRO            (0x8C04U) /**< @brief #EST_CONFIG_MAGIC_ID             */
#define BRCM_SWARCH_EST_ID_TYPE                          (0x8C05U) /**< @brief #EST_IdType                      */
#define BRCM_SWARCH_EST_GATECFG_TYPE                     (0x8C06U) /**< @brief #EST_GateCfgType                 */
#define BRCM_SWARCH_EST_GATESTATUS_TYPE                  (0x8C07U) /**< @brief #EST_GateStatusType              */
#define BRCM_SWARCH_EST_GATECONTROLLIST_TYPE             (0x8C08U) /**< @brief #EST_GateControlListType         */
#define BRCM_SWARCH_EST_QUEUEMAXSDUTABLECFG_TYPE         (0x8C09U) /**< @brief #EST_QueueMaxSDUTableCfgType     */
#define BRCM_SWARCH_EST_PORTCFG_TYPE                     (0x8C0AU) /**< @brief #EST_PortCfgType                 */
#define BRCM_SWARCH_EST_CFG_TYPE                         (0x8C0BU) /**< @brief #EST_CfgType                     */
#define BRCM_SWARCH_EST_STATS_TYPE                       (0x8C0CU) /**< @brief #EST_StatsType                   */
#define BRCM_SWARCH_EST_GETSTATSMSG_TYPE                 (0x8C0DU) /**< @brief #EST_GetStatsMsgType             */
#define BRCM_SWARCH_EST_CLEARSTATSMSG_TYPE               (0x8C0EU) /**< @brief #EST_ClearStatsMsgType           */
#define BRCM_SWARCH_EST_MSGUNION_TYPE                    (0x8C0FU) /**< @brief #EST_MsgUnionType                */
#define BRCM_SWARCH_EST_QUEUEMAXSDUMSG_TYPE              (0x8C10U) /**< @brief #EST_QueueMaxSDUMsgType          */
#define BRCM_SWARCH_EST_GATECONFIGMSG_TYPE               (0x8C11U) /**< @brief #EST_GateConfigMsgType           */
#define BRCM_SWARCH_EST_GETGATESTATUSMSG_TYPE            (0x8C12U) /**< @brief #EST_GetGateStatusMsgType        */
#define BRCM_SWARCH_EST_LIMITS_TYPE                      (0x8C13U) /**< @brief #EST_LimitsType                  */
#define BRCM_SWARCH_EST_GETLIMITSMSG_TYPE                (0x8C14U) /**< @brief #EST_GetLimitsMsgType            */
#define BRCM_SWARCH_EST_GATESTATES_TYPE                  (0x8C15U) /**< @brief #EST_GateStatesType              */
#define BRCM_SWARCH_EST_SETPORTENABLEMSG_TYPE            (0x8C16U) /**< @brief #EST_SetPortEnableMsgType        */
#define BRCM_SWARCH_EST_MAXSDUNOLIMIT_MACRO              (0x8C17U) /**< @brief #EST_MAXSDU_NOLIMIT              */
#define BRCM_SWARCH_EST_CFG_MAX_GLOBAL_GCL_ENTRIES_MACRO (0x8C18U) /**< @brief #EST_CFG_MAX_GLOBAL_GCL_ENTRIES  */
#define BRCM_SWARCH_EST_GATECONTROLLISTENTRY_TYPE        (0x8C19U) /**< @brief #EST_GateControlListEntryType    */
#define BRCM_SWARCH_EST_GATECFGPARAMS_TYPE               (0x8C1AU) /**< @brief #EST_GateCfgParamsType           */
/** @} */

/**
    @brief Maximum size of EST payload

    @trace #BRCM_SWREQ_EST
*/
#define EST_MAX_RPC_PAYLOAD_SIZE     (440UL)

/**
    @brief Maximum number of ports supported

    @trace #BRCM_SWREQ_EST
*/
#define EST_CFG_MAX_PORTS            (16U)

/**
    @brief Maximum number of entries in a gate control list

    This parameter controls the maximum length of the administrative
    and operational gate control lists as described by
    IEEE8021-ST-MIB ieee8021STSupportedListMax

    @trace #BRCM_SWREQ_EST
*/
#define EST_CFG_SUPPORTED_LIST_MAX  (64U)

/**
    @brief Maximum number of global GCL entries across all ports

    @trace #BRCM_SWREQ_EST
*/
#define EST_CFG_MAX_GLOBAL_GCL_ENTRIES (245U)

/**
    @brief Magic number for the configuration structure, containing 'QBV0'

    @trace #BRCM_SWREQ_EST
*/
#define EST_CONFIG_MAGIC_ID         (0x30564251UL)


/**
    @brief Queue maxSDU value to disable the check i.e. to allow packets of all sizes to go through

    @trace #BRCM_SWREQ_EST
*/
#define EST_MAXSDU_NOLIMIT          (0UL)

/**
    @name Switch EST command IDs
    @{
    @brief Switch EST command IDs group

    @trace #BRCM_SWREQ_EST
*/
typedef uint32_t EST_IdType;                     /**< @brief EST command message Type                               */
#define EST_ID(aId)              BCM_MSG(BCM_GROUPID_ETHSRV, BCM_ESTMOD_ID, aId)       /**< @brief Command-Response */
#define EST_ID_SETQUEUEMAXSDU    EST_ID(0x1U)   /**< @brief #EST_QueueMaxSDUMsgType      #EST_SetQueueMaxSDU        */
#define EST_ID_GETQUEUEMAXSDU    EST_ID(0x2U)   /**< @brief #EST_QueueMaxSDUMsgType      #EST_GetQueueMaxSDU        */
#define EST_ID_SETGATECONFIG     EST_ID(0x3U)   /**< @brief #EST_GateConfigMsgType       #EST_SetGateConfig         */
#define EST_ID_GETSTATS          EST_ID(0x4U)   /**< @brief #EST_GetStatsMsgType         #EST_GetStats              */
#define EST_ID_CLRSTATS          EST_ID(0x5U)   /**< @brief #EST_ClearStatsMsgType       #EST_ClearStats            */
#define EST_ID_GETGATESTATUS     EST_ID(0x6U)   /**< @brief #EST_GetGateStatusMsgType    #EST_GetGateStatus         */
#define EST_ID_GETGATECONFIG     EST_ID(0x7U)   /**< @brief #EST_GateConfigMsgType       #EST_GetGateConfig         */
#define EST_ID_GETLIMITS         EST_ID(0x8U)   /**< @brief #EST_GetLimitsMsgType        #EST_GetLimits             */
#define EST_ID_SETPORTENABLE     EST_ID(0x9U)   /**< @brief #EST_SetPortEnableMsgType    #EST_SetPortEnable         */
/** @} */

/**
    @brief Gate States type

    Bitmap representing the traffic classes where the MS bit corresponds to
    traffic class 7 and the LS bit to traffic class 0. Each bit represents
    the state of the gate: 0 (closed), 1(open)

    @trace #BRCM_SWREQ_EST
*/
typedef uint8_t EST_GateStatesType;

/**
    @brief Limits
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_LimitsType {
    uint32_t  supportedListMax; /**< @brief The maximum length of the administrative
                                            and operational gate control lists as
                                            described by IEEE8021-ST-MIB parameter
                                            ieee8021STSupportedListMax */

    uint32_t  tickGranularity;  /**< @brief The granularity of the cycleTime and
                                            interval parameters represented in
                                            unit of nanoseconds.
                                            This refers to the ieee8021STTickGranularity
                                            parameter of the IEEE8021-ST-MIB */
    uint32_t  resv[6UL];        /**< @brief Reserved */
} EST_LimitsType;
BCM_STATIC_SIZE_ASSERT(EST_LimitsType , 32UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Statistics
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_StatsType {
    uint32_t  cfgChngErrCnt;               /**< @brief Config Change Error Counter.
                                                       The counter is incremented when a gate
                                                       configuration with Admin Base Time in
                                                       the past is loaded.
                                                       This refers to the ieee8021STConfigChangeError
                                                       parameter of the IEEE8021-ST-MIB */
    uint32_t  txOvrRunCnt[ETHER_TC_MAX];   /**< @brief Per Queue Transmission Overrun Counters.
                                                       The counter is incremented when a gate
                                                       closed during packet transmission.
                                                       This refers to the ieee8021TransmissionOverrun
                                                       parameter of the IEEE8021-ST-MIB */
    uint32_t  maxSDUDropCnt[ETHER_TC_MAX]; /**< @brief Per Queue maxSDU drop counters.
                                                       The counter is incremented when a packet
                                                       exceeds the size limit on a queue and is
                                                       dropped. */
} EST_StatsType;
BCM_STATIC_SIZE_ASSERT(EST_StatsType, 68UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Gate control list entry configuration
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GateControlListEntryType {
    EST_GateStatesType state;     /**< @brief Per entry bitmap of states, one for each traffic class.
                                              Refer 802.1Q 2022 Section 12.29.1.2.2
                                              Indicates whether the gate is closed (0) or open (1) */
    uint8_t            resv[3U];  /**< @brief Reserved @xsd rsvd */
    uint32_t           interval;  /**< @brief Per entry time intervals in nanoseconds.
                                              Refer 802.1Q 2022 Section 12.29.1.2.3
                                              This is expected to be a multiple of the #tickGranularity
                                              parameter returned by the EST_GetLimits API */
} EST_GateControlListEntryType;
BCM_STATIC_SIZE_ASSERT(EST_GateControlListEntryType, 8UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Gate control list configuration
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GateControlListType {
    EST_GateStatesType state[EST_CFG_SUPPORTED_LIST_MAX];     /**< @brief Per entry bitmap of states, one for each traffic class.
                                                                          Refer 802.1Q 2022 Section 12.29.1.2.2
                                                                          Indicates whether the gate is closed (0) or open (1) */
    uint32_t           interval[EST_CFG_SUPPORTED_LIST_MAX];  /**< @brief Per entry time intervals in nanoseconds.
                                                                          Refer 802.1Q 2022 Section 12.29.1.2.3
                                                                          This is expected to be a multiple of the #tickGranularity
                                                                          parameter returned by the EST_GetLimits API */
    uint8_t            resv[EST_CFG_SUPPORTED_LIST_MAX];      /**< @brief Reserved @xsd rsvd */
} EST_GateControlListType;
BCM_STATIC_SIZE_ASSERT(EST_GateControlListType, 384UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Gate status parameters
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GateStatusType {
    BCM_TimeType           configChangeTime;    /**< @brief The time at which the administrative
                                                            parameters are copied to the operational
                                                            parameters.
                                                            This refers to the ieee8021STConfigChangeTime
                                                            parameter of the IEEE8021-ST-MIB */
    uint32_t               configPending;       /**< @brief Configuration change pending on
                                                            the associated gate.
                                                            This refers to the ieee8021STConfigPending
                                                            parameter of the IEEE8021-ST-MIB */
    EST_GateStatesType     currentState;        /**< @brief Operational value of GateStates.
                                                            This refers to the ieee8021STOperGateStates
                                                            parameter of the IEEE8021-ST-MIB */
    uint8_t                resv1[3U];           /**< @brief Reserved */
    BCM_TimeType           baseTime;            /**< @brief Operational base time.
                                                            This refers to the ieee8021STOperBaseTime
                                                            parameter of the IEEE8021-ST-MIB */
    uint32_t               cycleTime;           /**< @brief Operational cycle time in
                                                            nanoseconds (valid upto 1 second total).
                                                            This refers to the ieee8021STOperCycleTime
                                                            parameters of the IEEE8021-ST-MIB */
    uint32_t               cycleTimeExtension;  /**< @brief Operational cycle time extension
                                                            (in nanoseconds).
                                                            This refers to the ieee8021STOperCycleTimeExtension
                                                            parameter of the IEEE8021-ST-MIB */
    EST_GateControlListType gateControlList;    /**< @brief Gate control list
                                                            This refers to the ieee8021STOperControlList
                                                            parameter of the IEEE8021-ST-MIB */
    uint32_t                gateControlListLen; /**< @brief Gate control list length.
                                                            This refers to the ieee8021ST4minControlListLength
                                                            parameter of the IEEE8021-ST-MIB */
    uint32_t                resv2[4U];          /**< @brief Reserved */
} EST_GateStatusType;
BCM_STATIC_SIZE_ASSERT(EST_GateStatusType, 436UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Queue max SDU configuration
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_QueueMaxSDUTableCfgType {
    uint32_t maxSDUSz[ETHER_TC_MAX]; /**< @brief A list of maximum SDU sizes, one for
                                           each queue. A value of #EST_MAXSDU_NOLIMIT
                                           will disable the check.
                                           This parameter refers to the ieee8021STMaxSDU
                                           parameter of the IEEE8021-ST-MIB */
    uint32_t resv[ETHER_TC_MAX];     /**< @brief Reserved @xsd rsvd */
} EST_QueueMaxSDUTableCfgType;
BCM_STATIC_SIZE_ASSERT(EST_QueueMaxSDUTableCfgType, 64UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Gate static configuration
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GateCfgParamsType {
    uint32_t                enable;             /**< @brief Flag determining whether traffic scheduling
                                                            is active (1) or inactive (0)
                                                            This refers to the ieee8021STGateEnabled
                                                            parameter of the IEEE8021-ST-MIB @xsd bool */
    EST_GateStatesType      defaultState;       /**< @brief Administrative value of GateStates.
                                                            Applicable when there is no gate control list.
                                                            This refers to the ieee8021STAdminGateStates
                                                            parameter of the IEEE8021-ST-MIB */
    uint8_t                 resv1[3U];          /**< @brief Reserved @xsd rsvd */
    BCM_TimeType            baseTime;           /**< @brief Administrative base time.
                                                            This refers to the ieee8021STAdminBaseTime
                                                            parameter of the IEEE8021-ST-MIB */
    uint32_t                cycleTime;          /**< @brief Administrative cycle time in
                                                            nanoseconds (valid upto 1 second total).
                                                            This refers to the ieee8021STAdminCycleTime
                                                            parameters of the IEEE8021-ST-MIB */
    uint32_t                cycleTimeExtension; /**< @brief Administrative cycle time extension
                                                            (in nanoseconds).
                                                            This refers to the ieee8021STAdminCycleTimeExtension
                                                            parameter of the IEEE8021-ST-MIB */
    uint32_t                gateControlListLen; /**< @brief Gate control list length. This would not be
                                                            greater than the #supportedListMax parameter
                                                            returned by the EST_GetLimits API.
                                                            This refers to the ieee8021STAdminControlListLength
                                                            parameter of the IEEE8021-ST-MIB */
    uint32_t                resv2;              /**< @brief Reserved @xsd rsvd */
} EST_GateCfgParamsType;
BCM_STATIC_SIZE_ASSERT(EST_GateCfgParamsType, 32UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Gate configuration
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GateCfgType {
    EST_GateCfgParamsType   params;    /**< @brief Gate config without the control list
                                                   configuration */
    EST_GateControlListType list;      /**< @brief Gate control list
                                                   This refers to the ieee8021STAdminControlList
                                                   parameter of the IEEE8021-ST-MIB */
    uint32_t                resv2[3U]; /**< @brief Reserved @xsd rsvd */
} EST_GateCfgType;
BCM_STATIC_SIZE_ASSERT(EST_GateCfgType, 428UL, EST_MAX_RPC_PAYLOAD_SIZE)


/**
    @brief EST port configuration parameters
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_PortCfgType {
    uint32_t                    id;                 /**< @brief Port number */
    EST_GateCfgParamsType       gate;               /**< @brief Gate configuration */
    EST_QueueMaxSDUTableCfgType queueMaxSDUTbl;     /**< @brief Queue maxSDU table */
} EST_PortCfgType;
BCM_STATIC_SIZE_ASSERT(EST_PortCfgType, 100UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief EST configuration parameters
    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_CfgType {
    uint32_t                     magicId;                                   /**< @brief Magic number 'QBV0'
                                                                                        (checked for validity)     */
    uint32_t                     version;                                   /**< @brief Configuration version      */
    EST_PortCfgType              portCfg[EST_CFG_MAX_PORTS];                /**< @brief Per port configuration     */
    uint32_t                     numPorts;                                  /**< @brief Number of valid ports @xsd count:portCfg */
    EST_GateControlListEntryType gateListEntryPool[EST_CFG_MAX_GLOBAL_GCL_ENTRIES]; /**< @brief Pool of gate state entries */
    uint32_t                     totalEntries;                              /**< @brief Total number of entries    */
} EST_CfgType;

/**
    @brief Structure with parameters for the EST command to set queue max SDU size

    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_QueueMaxSDUMsgType {
    ETHER_PortIDType  port;     /**< @brief Input: Port number */
    ETHER_TCType      queue;    /**< @brief Input: Queue number */
    uint32_t          maxSDUSz; /**< @brief Input(EST_ID_SETQUEUEMAXSDU)/Output(EST_ID_GETQUEUEMAXSDU): max SDU size */
} EST_QueueMaxSDUMsgType;
BCM_STATIC_SIZE_ASSERT(EST_QueueMaxSDUMsgType, 12UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the EST command to get statistics

    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GetStatsMsgType {
    ETHER_PortIDType port;  /**< @brief Input: Port number */
    EST_StatsType    stats; /**< @brief Output: Statistics */
} EST_GetStatsMsgType;
BCM_STATIC_SIZE_ASSERT(EST_GetStatsMsgType, 72UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the EST command to clear statistics

    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_ClearStatsMsgType {
    ETHER_PortIDType  port;  /**< @brief Input: Port number */
} EST_ClearStatsMsgType;
BCM_STATIC_SIZE_ASSERT(EST_ClearStatsMsgType, 4UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the EST command to set gate configuration

    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GateConfigMsgType {
    ETHER_PortIDType port; /**< @brief Input: Port number */
    EST_GateCfgType  cfg;  /**< @brief Input(EST_ID_SETGATECONFIG)/Output(EST_ID_GETGATECONFIG): Gate configuration */
} EST_GateConfigMsgType;
BCM_STATIC_SIZE_ASSERT(EST_GateConfigMsgType, 432UL, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the EST command to get gate status

    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GetGateStatusMsgType {
    ETHER_PortIDType  port;    /**< @brief Input: Port number */
    EST_GateStatusType status;  /**< @brief Output: Gate status */
} EST_GetGateStatusMsgType;
BCM_STATIC_SIZE_ASSERT(EST_GetGateStatusMsgType, 440, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the EST command to get limits

    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_GetLimitsMsgType {
    ETHER_PortIDType  port;    /**< @brief Input: Port number */
    EST_LimitsType    limits;  /**< @brief Output: Limits */
} EST_GetLimitsMsgType;
BCM_STATIC_SIZE_ASSERT(EST_GetLimitsMsgType, 36, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the EST command to set port enable

    @trace #BRCM_SWREQ_EST
*/
typedef struct sEST_SetPortEnableMsgType {
    ETHER_PortIDType port;   /**< @brief Input: Port number */
    uint32_t         enable; /**< @brief Input: Enable */
} EST_SetPortEnableMsgType;
BCM_STATIC_SIZE_ASSERT(EST_SetPortEnableMsgType, 8, EST_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Union encapsulating all messages for EST

    @trace #BRCM_SWREQ_EST
*/
typedef union uEST_MsgUnionType {
    uint32_t                   data[EST_MAX_RPC_PAYLOAD_SIZE/4UL]; /**< @brief EST data */
    EST_QueueMaxSDUMsgType     queueMaxSDU;                        /**< @brief Set/Get queue maxSDU size parameters */
    EST_GateConfigMsgType      gateCfg;                            /**< @brief Set/Get gate configuration */
    EST_GetStatsMsgType        getStats;                           /**< @brief Get statistics parameters */
    EST_ClearStatsMsgType      clearStats;                         /**< @brief Clear statistics parameters */
    EST_GetGateStatusMsgType   getGateStatus;                      /**< @brief Get gate status parameters */
    EST_GetLimitsMsgType       getLimits;                          /**< @brief Get Limits parameters */
    EST_SetPortEnableMsgType   setPortEnable;                      /**< @brief Set port enable */
} EST_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(EST_MsgUnionType, EST_MAX_RPC_PAYLOAD_SIZE, EST_MAX_RPC_PAYLOAD_SIZE)

#endif /* ETHERNET_EST_TYPES_H */
/** @} */
