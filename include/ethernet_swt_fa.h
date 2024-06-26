/*****************************************************************************
 Copyright 2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ethernet_swt_fa_ifc Switch FA abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_fa_ifc
    @{

    @file ethswtm_abs_fa.h

    @brief FA Interface
    This file contains the interfaces for the Ethernet abstract for FA

    @version 1.0 Initial version
*/

#ifndef ETHSWT_ABSTRACT_FA_H
#define ETHSWT_ABSTRACT_FA_H

#include <module_msg.h>
#include <bcm_utils.h>
#include <ethernet_common.h>
#include <ethernet_swt_common.h>
#include <rpc_msg.h>
#include <system_mcu.h>
#include <bcm_msg.h>

/**
    @name Ethernet Service FA API IDs
    @{
    @brief API IDs for FA in Ethernet Service
*/
#define BRCM_SWARCH_ETHSWT_FACMDID_TYPE               (0x8A01U)    /**< @brief #ETHSWT_FACmdIdType         */
#define BRCM_SWARCH_ETHSWT_FAFLOWOPERATION_TYPE       (0x8A03U)    /**< @brief #ETHSWT_FAFlowOperationType */
#define BRCM_SWARCH_ETHSWT_FAMACOPERATION_TYPE        (0x8A04U)    /**< @brief #ETHSWT_FAMacOperationType  */
#define BRCM_SWARCH_ETHSWT_FAMACSNAPSHOT_TYPE         (0x8A05U)    /**< @brief #ETHSWT_FAMacSnapshotType   */
#define BRCM_SWARCH_ETHSWT_FAATTRIBUTE_TYPE           (0x8A06U)    /**< @brief #ETHSWT_FAAttributeType     */
#define BRCM_SWARCH_ETHSWT_FAFLOWSTATUSDATA_TYPE      (0x8A07U)    /**< @brief #ETHSWT_FAFlowStatusDataType*/
#define BRCM_SWARCH_ETHSWT_FASTATS_TYPE               (0x8A08U)    /**< @brief #ETHSWT_FAStatsType         */
#define BRCM_SWARCH_ETHSWT_FAFLOWDATA_TYPE            (0x8A09U)    /**< @brief #ETHSWT_FAFlowDataType      */
#define BRCM_SWARCH_ETHSWT_FAMACGROUP_TYPE            (0x8A0AU)    /**< @brief #ETHSWT_FAMacGroupType      */
#define BRCM_SWARCH_ETHSWT_FAFLOWID_TYPE              (0x8A0BU)    /**< @brief #ETHSWT_FAFlowIDType        */
#define BRCM_SWARCH_ETHSWT_FAINTRFLAGS_TYPE           (0x8A0CU)    /**< @brief #ETHSWT_FAIntrFlagsType     */
#define BRCM_SWARCH_ETHSWT_FAOPERATION_TYPE           (0x8A0DU)    /**< @brief #ETHSWT_FAOperationType     */
#define BRCM_SWARCH_ETHSWT_FAFLAGS_TYPE               (0x8A0EU)    /**< @brief #ETHSWT_FAFlagsType         */
#define BRCM_SWARCH_ETHSWT_FAFLOWVALID_TYPE           (0x8A0FU)    /**< @brief #ETHSWT_FAFlowValidType     */
#define BRCM_SWARCH_ETHSWT_FAMATCH_TYPE               (0x8A10U)    /**< @brief #ETHSWT_FAMatchType         */
#define BRCM_SWARCH_ETHSWT_FAREMAPDATA_TYPE           (0x8A11U)    /**< @brief #ETHSWT_FARemapDataType     */
#define BRCM_SWARCH_ETHSWT_FAMACADDRINFO_TYPE         (0x8A12U)    /**< @brief #ETHSWT_FAMacAddrInfoType   */
#define BRCM_SWARCH_ETHSWT_FAFLOWSTATS_TYPE           (0x8A13U)    /**< @brief #ETHSWT_FAFlowStatsType     */
#define BRCM_SWARCH_ETHSWT_FACTFMODE_TYPE             (0x8A14U)    /**< @brief #ETHSWT_FACtfModeType       */
#define BRCM_SWARCH_ETHSWT_FACRC_TYPE                 (0x8A15U)    /**< @brief #ETHSWT_FACrcType           */
#define BRCM_SWARCH_ETHSWT_FACTFCFG_TYPE              (0x8A16U)    /**< @brief #ETHSWT_FACtfCfgType        */
#define BRCM_SWARCH_ETHSWT_FAMSGUNION_TYPE            (0x8A17U)    /**< @brief #ETHSWT_FAMsgUnionType      */
#define BRCM_SWARCH_ETHSWT_FA_MAX_PAYLOAD_SIZE_MACRO  (0x8A1BU)    /**< @brief #ETHSWT_FA_MAX_PAYLOAD_SIZE */
#define BRCM_SWARCH_ETHSWT_FA_CFG_MAGIC_MACRO         (0x8A1CU)    /**< @brief #ETHSWT_FA_CFG_MAGIC        */
#define BRCM_SWARCH_ETHSWT_FAMODCFG_TYPE              (0x8A1DU)    /**< @brief #ETHSWT_FAModCfgType        */
#define BRCM_SWARCH_ETHSWT_FA_MAX_CONFIG_SIZE_MACRO   (0x8A1EU)    /**< @brief #ETHSWT_FA_MAX_CONFIG_SIZE  */
#define BRCM_SWARCH_ETHSWT_FA_ID_OF_MACRO             (0x8A1FU)    /**< @brief #ETHSWT_FA_ID_OF            */
#define BRCM_SWARCH_ETHSWT_FAADDFLOW_PROC             (0x8A20U)    /**< @brief #ETHSWT_FAAddFlow           */
#define BRCM_SWARCH_ETHSWT_FADELETEFLOW_PROC          (0x8A21U)    /**< @brief #ETHSWT_FADeleteFlow        */
#define BRCM_SWARCH_ETHSWT_FAGETFLOW_PROC             (0x8A22U)    /**< @brief #ETHSWT_FAGetFlow           */
#define BRCM_SWARCH_ETHSWT_FAGETFLOWSTATUS_PROC       (0x8A23U)    /**< @brief #ETHSWT_FAGetFlowStatus     */
#define BRCM_SWARCH_ETHSWT_FAGETFLOWSTATS_PROC        (0x8A24U)    /**< @brief #ETHSWT_FAGetFlowStats      */
#define BRCM_SWARCH_ETHSWT_FAADDMAC_PROC              (0x8A25U)    /**< @brief #ETHSWT_FAAddMAC            */
#define BRCM_SWARCH_ETHSWT_FADELETEMAC_PROC           (0x8A26U)    /**< @brief #ETHSWT_FADeleteMAC         */
#define BRCM_SWARCH_ETHSWT_FAGETMACSNAPSHOT_PROC      (0x8A27U)    /**< @brief #ETHSWT_FAGetMacSnapshot    */
#define BRCM_SWARCH_ETHSWT_FAINTERRUPTENABLE_PROC     (0x8A28U)    /**< @brief #ETHSWT_FAInterruptEnable   */
#define BRCM_SWARCH_ETHSWT_FARESET_PROC               (0x8A29U)    /**< @brief #ETHSWT_FAReset             */
/** @} */

/**
    @brief Maximum size of FA command payload in bytes

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_FA_MAX_PAYLOAD_SIZE     (160UL)

/**
    @brief Magic for FA configuration- 'F''L''A''C'

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_FA_CFG_MAGIC      (0x464C4143UL)   /**< @brief MAGIC for FA configuration- 'F''L''A''C' */

/**
    @brief Macro to Construct FA CmdID
    @{
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_FA_ID_OF(aId)  BCM_MSG(BCM_GROUPID_ETHSRV, BCM_FAC_ID, aId)
#define ETHSWT_FA_ID_OF_ASYNC(aId)  BCM_MSG_ASYNC(BCM_GROUPID_ETHSRV, BCM_FAC_ID, aId)
/** @} */

/**
    @name Switch FA command IDs
    @{
    @brief Switch FA command IDs group

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef BCM_MsgType ETHSWT_FACmdIdType;                             /**< @brief FA command message Type                                      */
#define ETHSWT_FACMDID_FLOW_ADD           ETHSWT_FA_ID_OF(0xD0U) /**< @brief #ETHSWT_FAFlowOperationType       #ETHSWT_FAFlowAdd          */
#define ETHSWT_FACMDID_FLOW_DELETE        ETHSWT_FA_ID_OF(0xD1U) /**< @brief #ETHSWT_FAFlowOperationType       #ETHSWT_FAFlowDelete       */
#define ETHSWT_FACMDID_FLOW_GET           ETHSWT_FA_ID_OF(0xD2U) /**< @brief #ETHSWT_FAFlowOperationType       #ETHSWT_FAFlowGet          */
#define ETHSWT_FACMDID_STATS              ETHSWT_FA_ID_OF(0xD3U) /**< @brief #ETHSWT_FAStatsType               #ETHSWT_FAStats            */
#define ETHSWT_FACMDID_MAC_SNAPSHOT       ETHSWT_FA_ID_OF(0xD4U) /**< @brief #ETHSWT_FAMacSnapshotType         #ETHSWT_FAMacPoolGet
                                                                                                               #ETHSWT_GetARLMyDASnapshot */
#define ETHSWT_FACMDID_MAC_ADD            ETHSWT_FA_ID_OF(0xD5U) /**< @brief #ETHSWT_FAMacOperationType        #ETHSWT_FAMacAdd
                                                                                                               #ETHSWT_AddARLMyDAEntry    */
#define ETHSWT_FACMDID_MAC_DELETE         ETHSWT_FA_ID_OF(0xD6U) /**< @brief #ETHSWT_FAMacOperationType        #ETHSWT_FAMacDelete
                                                                                                               #ETHSWT_DeleteARLMyDAEntry */
#define ETHSWT_FACMDID_FLOW_STATUS        ETHSWT_FA_ID_OF(0xD7U) /**< @brief #ETHSWT_FAFlowStatusDataType      #ETHSWT_FAStats            */
#define ETHSWT_FACMDID_INTERRUPT_ENABLE   ETHSWT_FA_ID_OF(0xD8U) /**< @brief #ETHSWT_FAIntrFlagsType           #ETHSWT_FAEnableInterrupt  */
#define ETHSWT_FACMDID_RESET              ETHSWT_FA_ID_OF(0xD9U) /**< @brief #ETHSWT_FACtfCfgType              #ETHSWT_FADeinit           */
#define ETHSWT_FACMDID_START              ETHSWT_FA_ID_OF(ETHSWT_FACMDID_FLOW_ADD)
#define ETHSWT_FACMDID_END                ETHSWT_FA_ID_OF(ETHSWT_FACMDID_RESET)
#define ETHSWT_FACMDID_ASYNCEVENT_INT     ETHSWT_FA_ID_OF_ASYNC(0x00U) /**< @brief Asynchronous event interrupt */
/** @} */

/**
    @name ETHSWT_FAFlowIDType
    @{
    @brief Flow Identifier

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_FAFlowIDType;
#define ETHSWT_FAFLOWID_RSVD_MASK    (0xFF000000UL)
#define ETHSWT_FAFLOWID_RSVD_SHIFT   (24UL)
#define ETHSWT_FAFLOWID_GROUP_MASK   (0x00FF0000UL)
#define ETHSWT_FAFLOWID_GROUP_SHIFT  (16UL)
#define ETHSWT_FAFLOWID_FLOW_MASK    (0x0000FFFFUL)
#define ETHSWT_FAFLOWID_FLOW_SHIFT   (0UL)
/** @} */

/**
    @name ETHSWT_FAAttributeType
    @{
    @brief ETHSWTM FA flow attributes

    Attributes of the flow for which a bitmask is being queried

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_FAAttributeType;
#define ETHSWT_FAATTRIBUTE_ACTIVE    (1UL) /**< @brief Active mask */
#define ETHSWT_FAATTRIBUTE_STATIC    (2UL) /**< @brief Static mask */
#define ETHSWT_FAATTRIBUTE_MAC_USE   (3UL) /**< @brief MAC address usage mask */
/** @} */

/**
    @brief ETHSWTM FA Flow Status Type

    Structure to retrieve flow status corresponding to attribute

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FAFlowStatusDataType {
    uint8_t mask[ETHSWT_FA_FLOWS_MAX / 8UL]; /**< @brief bitmask of flows
                                                  satisfying the attribute */
    ETHSWT_FAAttributeType  attribute;      /**< @brief Attributes of mask */
    MCU_DeviceType          mstSlvDevice;   /**< @brief 0: Master, 1: Slave-1, 2: Slave-2 */
    uint8_t                 mac[6UL];       /**< @brief MAC address */
    uint8_t                 rsvd[2];        /**< @brief Reserved */
} ETHSWT_FAFlowStatusDataType;

/**
    @name ETHSWT_FAIntrFlagsType
    @{
    @brief Interrupt flags type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_FAIntrFlagsType;
#define ETHSWT_FAINTRFLAGS_EDIT_BH         (0x00000001UL) /**< @brief Broadcom header edit invalid */
#define ETHSWT_FAINTRFLAGS_IPV4_CHECKSUM   (0x00000002UL) /**< @brief Checksum error detected on incoming IPv4 frame */
#define ETHSWT_FAINTRFLAGS_PARSE_L3        (0x00000004UL) /**< @brief Parsing did not complete during l3 stage */
#define ETHSWT_FAINTRFLAGS_PARSE_L2        (0x00000008UL) /**< @brief Parsing did not complete during l2 stage */
#define ETHSWT_FAINTRFLAGS_PARSE_BH        (0x00000010UL) /**< @brief Parsing did not complete during brcm header stage */
#define ETHSWT_FAINTRFLAGS_OVERFLOW_HWQ    (0x00000020UL) /**< @brief HW queue overflow */
#define ETHSWT_FAINTRFLAGS_OVERFLOW_HB     (0x00000040UL) /**< @brief Header buffer overflow */
#define ETHSWT_FAINTRFLAGS_OVERFLOW_RXQ    (0x00000080UL) /**< @brief RXQ buffer overflow */
#define ETHSWT_FAINTRFLAGS_SOP_EOP         (0x00000100UL) /**< @brief Sop/Eop error */
#define ETHSWT_FAINTRFLAGS_OVERFLOW_SPB    (0x00000200UL) /**< @brief Split buffer overflow */
#define ETHSWT_FAINTRFLAGS_OVERFLOW_LAB    (0x00000400UL) /**< @brief Latency buffer overflow */
#define ETHSWT_FAINTRFLAGS_INTERNAL_MERGE  (0x00000800UL) /**< @brief Merge error */
#define ETHSWT_FAINTRFLAGS_OVERFLOW_TXQ    (0x00001000UL) /**< @brief Tx queue overflow error */
#define ETHSWT_FAINTRFLAGS_OVERFLOW_RSV    (0x00002000UL) /**< @brief RSV buffer overflow error */
#define ETHSWT_FAINTRFLAGS_COR_HB          (0x00004000UL) /**< @brief Correctable ECC error has been detected in the header buffer */
#define ETHSWT_FAINTRFLAGS_COR_HWQ_1       (0x00008000UL) /**< @brief Correctable ECC error has been detected in the HWQ buffer */
#define ETHSWT_FAINTRFLAGS_COR_HWQ_0       (0x00010000UL) /**< @brief Correctable ECC error has been detected in the HWQ buffer */
#define ETHSWT_FAINTRFLAGS_COR_LAB         (0x00020000UL) /**< @brief Correctable ECC error has been detected in the latency buffer */
#define ETHSWT_FAINTRFLAGS_COR_NAPT_FLOW   (0x00040000UL) /**< @brief Correctable ECC error has been detected in the napt flow table */
#define ETHSWT_FAINTRFLAGS_COR_NEXT_HOP    (0x00080000UL) /**< @brief Correctable ECC error has been detected in the next hop table */
#define ETHSWT_FAINTRFLAGS_UNCOR_HB        (0x00100000UL) /**< @brief Uncorrectable ECC error has been detected in the header buffer */
#define ETHSWT_FAINTRFLAGS_UNCOR_HWQ_1     (0x00200000UL) /**< @brief Uncorrectable ECC error has been detected in the HWQ buffer */
#define ETHSWT_FAINTRFLAGS_UNCOR_HWQ_0     (0x00400000UL) /**< @brief Uncorrectable ECC error has been detected in the HWQ buffer */
#define ETHSWT_FAINTRFLAGS_UNCOR_LAB       (0x00800000UL) /**< @brief Uncorrectable ECC error has been detected in the latency buffer */
#define ETHSWT_FAINTRFLAGS_UNCOR_NAPT_FLOW (0x01000000UL) /**< @brief Uncorrectable ECC error has been detected in the napt flow table */
#define ETHSWT_FAINTRFLAGS_UNCOR_NEXT_HOP  (0x02000000UL) /**< @brief Uncorrectable ECC error has been detected in the next hop table */
/** @} */

/**
    @name ETHSWT_FAStatsType

    @brief Statistics type

    @note  Some of the counters are cleared upon read and hence the client is
           expected to accumulate them and then present to application or host.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FAStatsType {
    uint32_t hit;               /**< @brief Count of hits- clear-on-read */
    uint32_t miss;              /**< @brief Count of misses- clear-on-read */
    uint32_t snapFail;          /**< @brief Count of SNAP failures- clear-on-read */
    uint32_t etypeFail;         /**< @brief Count of etype failures- clear-on-read */
    uint32_t versionFail;       /**< @brief Count of version failures- clear-on-read */
    uint32_t fragFail;          /**< @brief Count of fragmentation failures- clear-on-read */
    uint32_t protocolFail;      /**< @brief Count of UDP/TCP protocol failures- clear-on-read */
    uint32_t checksumFail;      /**< @brief Count of IPv4 checksum failures- clear-on-read */
    uint32_t optionsFail;       /**< @brief Count of IPv4 option failures- clear-on-read */
    uint32_t headerLengthFail;  /**< @brief Count of IPv4 header length failures- clear-on-read */
    ETHSWT_FAIntrFlagsType intrFlags; /**< @brief Interrupt flags */
    uint32_t flowTableUsage;    /**< @brief Number of entries used in Flow Table */
    uint32_t poolTableUsage;    /**< @brief Number of entries used in Pool Table */
    uint32_t nextHopTableUsage; /**< @brief Number of entries used in Next-Hop Table */
    uint32_t currentTimestamp;  /**< @brief Current timestamp */
} ETHSWT_FAStatsType;

/**
    @name ETHSWT_FAOperationType

    @brief Operation to be performed on the L2 header

    @trace #BRCM_SWREQ_ETHSWT
    @{
*/
typedef uint8_t ETHSWT_FAOperationType;
#define ETHSWT_FAOPERATION_S_TAG      (0U)    /**< @brief Replace MAC header, use Service Provider Tag */
#define ETHSWT_FAOPERATION_C_TAG      (1U)    /**< @brief Replace MAC header, use Customer Tag */
#define ETHSWT_FAOPERATION_NO_TAG     (2U)    /**< @brief Replace MAC header, use no VLAN tag */
#define ETHSWT_FAOPERATION_NO_OP      (3U)    /**< @brief Do not replace MAC header, just update Source and Destination MAC addresses */
/** @} */

/**
    @name ETHSWT_FAFlagsType

    @brief Flags pertaining to the packet type

    @trace #BRCM_SWREQ_ETHSWT
    @{
*/
typedef uint8_t ETHSWT_FAFlagsType;
#define ETHSWT_FAFLAGS_L4TCP      (0x01U)    /**< @brief TCP / UDP */
#define ETHSWT_FAFLAGS_L3IPV4     (0x02U)    /**< @brief IP v4/v6 */
#define ETHSWT_FAFLAGS_L2LLCSNAP  (0x04U)    /**< @brief LLCSNAP/DIXv2 */
#define ETHSWT_FAFLAGS_INBOUND    (0x08U)    /**< @brief Inboud/Outbound */
/** @} */

/**
    @name ETHSWT_FAFlowValidType

    @brief Flow entry validity type

    @trace #BRCM_SWREQ_ETHSWT
    @{
*/
typedef uint8_t ETHSWT_FAFlowValidType;
#define ETHSWT_FAFLOWVALID_TILLREBOOT   (0x0U)  /**< @brief Entry valid till reboot
                                                     and cannot be deleted once added */
#define ETHSWT_FAFLOWVALID_TILLDELETE   (0x1U)  /**< @brief Entry valid till it is deleted */
/** @} */

/**
    @name ETHSWT_FAMatchType

    @brief Flow accelerator Match type

    @trace #BRCM_SWREQ_ETHSWT
 */
typedef struct COMP_PACKED sETHSWT_FAMatchType {
    uint8_t     da[6];          /**< @brief Ingress Destination Address, valid
                                     when #ETHSWT_FAModCfgType
                                     validateMatchDA parameter is true */
    uint16_t    srcPort;        /**< @brief L4 Source Port */
    uint16_t    dstPort;        /**< @brief L4 destination Port */
    uint8_t     srcIp[16];      /**< @brief Source IP Address */
    uint8_t     dstIp[16];      /**< @brief Destination IP Address */
    ETHSWT_FAFlagsType flags;   /**< @brief Packet type flags combination */
} ETHSWT_FAMatchType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAMatchType, 43UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/**
    @name ETHSWT_FARemapDataType
    @{
    @brief Flow accelerator Remap type

    @trace #BRCM_SWREQ_ETHSWT
 */
typedef struct COMP_PACKED sETHSWT_FARemapDataType {
    ETHSWT_FAOperationType operation; /**< @brief Operation to be performed on L2 header */
    uint8_t     sa[6];                /**< @brief Remap Source Address */
    uint8_t     da[6];                /**< @brief Remap Destination Address */
    uint16_t    vlan;                 /**< @brief Remap VLAN ID */
    uint16_t    port;                 /**< @brief L4 Remap Port, set to 0 if overwrite is not required */
    uint8_t     ip[16];               /**< @brief Remap IP Address, set to 0 if overwrite is not required */
    ETHSWT_TCType tc;                 /**< @brief Traffic Class */
    ETHSWT_TEType te;                 /**< @brief Tag Reinforcement */
    uint32_t    portMask;             /**< @brief Portmask. If 0UL, opcode=0 will be used.
                                           Otherwise opcode=1 will be used in Broadcom header/tag */
} ETHSWT_FARemapDataType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FARemapDataType, 39UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)
/** @} */

/**
    @name ETHSWT_FAFlowDataType
    @{
    @brief Flow accelerator Flow type

    @trace #BRCM_SWREQ_ETHSWT
 */
typedef struct COMP_PACKED sETHSWT_FAFlowDataType {
    ETHSWT_FAMatchType      match;          /**< @brief Match parameters */
    ETHSWT_FARemapDataType  remap;          /**< @brief Remap parameters */
    MCU_DeviceType          mstSlvDevice;   /**< @brief 0: Master, 1: Slave-1, 2: Slave-2 */
} ETHSWT_FAFlowDataType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAFlowDataType, 86UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)
/** @} */

/**
    @name ETHSWT_FAMacAddrInfoType

    @brief MAC Information

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FAMacAddrInfoType {
    uint32_t external;      /**< @brief Domain: TRUE:External, FALSE:Internal */
    uint8_t mac[6UL];       /**< @brief MAC Address */
} ETHSWT_FAMacAddrInfoType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAMacAddrInfoType, 10UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/**
    @name ETHSWT_FAMacGroupType

    @brief MAC Address Configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FAMacGroupType {
    uint32_t count;                                    /**< @brief Number of valid entries */
    ETHSWT_FAMacAddrInfoType info[ETHSWT_FA_POOL_MAX]; /**< @brief Pool Table entries */
} ETHSWT_FAMacGroupType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAMacGroupType, 44UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/**
    @name ETHSWT_FAFlowStatsType
    @brief Flow Statistics type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FAFlowStatsType {
    uint32_t hits;          /**< Number of hits */
    uint8_t lastTimestamp;  /**< Last timestamp */
} ETHSWT_FAFlowStatsType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAFlowStatsType, 5UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/**
    @brief Ethernet Service FA Flow operation Type

    Structure to manage FA flow related operations

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FAFlowOperationType {
    ETHSWT_FAFlowIDType flowID;         /**< @brief Flow ID */
    ETHSWT_FAFlowDataType flow;         /**< @brief Flow parameters */
    ETHSWT_FAFlowStatsType flowStats;   /**< @brief Flow Statistics */
    uint8_t rsvd;                       /**< Reserved */
} ETHSWT_FAFlowOperationType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAFlowOperationType, 96UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/**
    @brief Ethernet Service FA MAC operation Type

    Structure to manage FA MAC related operations

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FAMacOperationType {
    MCU_DeviceType              mstSlvDevice;   /**< @brief Master/Slave identifier */
    ETHSWT_FAMacAddrInfoType    info;           /**< @brief MAC information */
    uint8_t                     rsvd[2] ;       /**< @brief Reserved */
} ETHSWT_FAMacOperationType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAMacOperationType, 16UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/**
    @brief Ethernet Service FA MAC Snapshot Type

    Structure to hold FA MAC snapshot

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FAMacSnapshotType {
    ETHSWT_FAMacAddrInfoType info[2UL][ETHSWT_FA_POOL_MAX]; /**< @brief Mac Info */
    uint8_t deviceMac[2UL][6UL];                        /**< @brief List of Device MAC addresses */
} ETHSWT_FAMacSnapshotType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAMacSnapshotType, 92UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/**
    @name ETHSWT_FACtfModeType
    @{
    @brief CTF Operational Mode type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_FACtfModeType;
#define ETHSWT_FACTFMODE_NORMAL   (0U)    /**< @brief Normal mode */
#define ETHSWT_FACTFMODE_BYPASS   (1U)    /**< @brief Bypass mode */
/** @} */

/**
    @name ETHSWT_FACrcType
    @{
    @brief CRC types

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_FACrcType;
#define ETHSWT_FACRC_CCITT    (0U)        /**< @brief CCITT polynomial (X^16 + X^12 + X^5 + 1) */
#define ETHSWT_FACRC_CRC16    (1U)        /**< @brief CRC16 polynomial (X^16 + X^15 + X^2 + 1) */
/** @} */

/**
    @name ETHSWT_FACtfCfgType

    @brief CTF configuration Type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_FACtfCfgType {
    ETHSWT_FACtfModeType mode;        /**< @brief CTF Operational Mode */
    ETHSWT_FACrcType crc;             /**< @brief CRC type */
    uint16_t seedValue;               /**< @brief Inital seed value */
    uint32_t timestampPeriodSec;      /**< @brief Timestamp period in seconds */
    BCM_BoolType validateMatchDA;     /**< @brief TRUE:Validation of Match-DA will be enabled, FALSE: disabled */
} ETHSWT_FACtfCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FACtfCfgType, 12UL, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/**
    @name ETHSWT_FAModCfgType
    @{
    @brief Flow accelerator Configuration type

    @note  An all zero MAC address(0:0:0:0:0:0) will be replaced by device's MAC
           address during initialisation. However during rest of the execution,
           an all zero MAC address obtained through application/host will be
           considered as invalid.

    @trace #BRCM_SWREQ_ETHSWT
 */
typedef struct COMP_PACKED sETHSWT_FAModCfgType {
    uint32_t magic;                                         /**< @brief Magic ID of FA */
    uint16_t flowCount;                                     /**< @brief Number of valid flows */
    ETHSWT_FACtfCfgType ctf;                                /**< @brief CTF configuration */
    ETHSWT_FAMacGroupType macGroup[2UL];                    /**< @brief MAC Group Configuration */
    ETHSWT_FAFlowDataType flow[ETHSWT_FA_STATIC_FLOWS_MAX]; /**< @brief flow configuration */
} ETHSWT_FAModCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAModCfgType, 11114UL, 11114UL)
/** @} */

/**
    @brief FA Config maximum binary size

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_FA_MAX_CONFIG_SIZE       (sizeof(ETHSWT_FAModCfgType))

/**
    @brief Vlan Union encapsulating all messages

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef union uETHSWT_FAMsgUnionType {
    uint32_t                     data[ETHSWT_FA_MAX_PAYLOAD_SIZE/4UL];
    ETHSWT_FAStatsType           faStats;       /**< @brief Statistics */
    ETHSWT_FAFlowOperationType   flowOperation; /**< @brief Flow Operation */
    ETHSWT_FAMacSnapshotType     macSnapshot;   /**< @brief MAC Snapshot */
    ETHSWT_FAMacOperationType    macOperation;  /**< @brief MAC Operation */
    ETHSWT_FAFlowStatusDataType  flowStatus;    /**< @brief Flow Status */
    ETHSWT_FAIntrFlagsType       intrFlags;     /**< @brief Interrupt Flags */
    ETHSWT_FACtfCfgType          ctfCfg;        /**< @brief CFT Configuration */
} ETHSWT_FAMsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_FAMsgUnionType, ETHSWT_FA_MAX_PAYLOAD_SIZE, ETHSWT_FA_MAX_PAYLOAD_SIZE)

/** @brief Add a Flow

    This API adds a new flows into Flow accelerator

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aHdl             Connection handle (from RPC_Connect)
    @param[in]  aFACfg           FA config image containing flows to be added
    @param[in]  aFlowIDList      Pointer to array of ETHSWT_FAFlowIDType of
                                 size ETHSWT_FA_STATIC_FLOWS_MAX
    @param[in]  aFlowIDListCount Count of flows added successfully

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Flow added successfully
    @retval    #BCM_ERR_NOMEM           Insufficient memory to add
    @retval    #BCM_ERR_NOT_FOUND       Matching entry not found in Pool table
    @retval    #BCM_ERR_INVAL_STATE     FA is configured in BYPASS mode
    @retval    #BCM_ERR_UNINIT          FA is uninitialised
    @retval    #BCM_ERR_INVAL_PARAMS    aFACfg/aFlowIDList/aFlowIDListCount is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FAAddFlow(BCM_HandleType aConnHdl,
                                ETHSWT_FAModCfgType *aFACfg,
                                ETHSWT_FAFlowIDType *aFlowIDList,
                                uint32_t *aFlowIDListCount);


/** @brief Delete a Flow

    This API deletes an existing flow from Flow accelerator by providing the
    Flow ID obtained after adding the same.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl        Connection handle (from RPC_Connect)
    @param[in]  aFlowID         Flow ID of the flow to be deleted.

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Flow deleted successfully
    @retval    #BCM_ERR_NOPERM          Permission denied(#ETHSWT_FAFLOWVALID_TILLREBOOT)
    @retval    #BCM_ERR_UNINIT          FA is uninitialised
    @retval    #BCM_ERR_INVAL_PARAMS    aFlowID is invalid

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FADeleteFlow(BCM_HandleType aConnHdl,
                                   const uint16_t aFlowID);

/** @brief Flow Get

    This API retrieves flow parameters pertaining to a Flow ID

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aFlowID     Flow ID for the fetch
    @param[out]     aFlow       Pointer to retrieve flow parameters

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Flow parameters obtained successfully
    @retval    #BCM_ERR_UNINIT          FA is uninitialised
    @retval    #BCM_ERR_INVAL_PARAMS    Invalid aFlowID OR aFlow is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FAGetFlow(BCM_HandleType aConnHdl,
                                const uint16_t aFlowID,
                                ETHSWT_FAFlowOperationType *const aFlow);

/** @brief Get Flow Status

    This API retrieves flow status

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aAttribute  Attribute of the flow for getting status
    @param[in]      aMstSlv     Master or slave device
    @param[in]      aMac        MAC address needed when #aAttribute is
                                #ETHSWT_FAATTRIBUTE_MAC_USE
    @param[out]     aFlow       Pointer to retrieve flow status

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Flow parameters obtained successfully
    @retval    #BCM_ERR_NOT_FOUND       MAC address doesn't match existing ones

    @retval    #BCM_ERR_UNINIT          FA is uninitialised
    @retval    #BCM_ERR_INVAL_PARAMS    aFlow is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FAGetFlowStatus(BCM_HandleType aConnHdl,
                                      ETHSWT_FAAttributeType aAttribute,
                                      MCU_DeviceType aMstSlv,
                                      uint8_t const *aMac,
                                      ETHSWT_FAFlowStatusDataType *const aFlow);

/** @brief Retrieve statistics

    This API retrieves statistics from Flow accelerator

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl    Connection handle (from RPC_Connect)
    @param[out] aStats      Pointer to statistics structure

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Statistics retrieved successfully
    @retval    #BCM_ERR_UNINIT          FA is uninitialised
    @retval    #BCM_ERR_INVAL_PARAMS    aStats is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FAGetFlowStats(BCM_HandleType aConnHdl,
                                     ETHSWT_FAStatsType *const aStats);

/** @brief Add MAC entry

    This API will add a pool table entry

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl    Connection handle (from RPC_Connect)
    @param[in]  aMac        Pointer to MAC address
    @param[in]  aExternal   TRUE:External MAC
                            FALSE: Internal MAC
    @param[in]  aMstSlv     Master or slave device

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK           Successfully added or same exists already
    @retval     #BCM_ERR_NOMEM        No memory available to add a new entry
    @retval     #BCM_ERR_NOPERM       No permission to overwrite existing MAC
                                      with different "external" field
    @retval     #BCM_ERR_INVAL_STATE  FA is configured in BYPASS mode
    @retval     #BCM_ERR_UNINIT       FA is uninitialised
    @retval     #BCM_ERR_INVAL_PARAMS aMac is NULL OR MAC address is all 0s OR
                                      aExternal is neither TRUE nor FALSE
                                      Invalid aMstSlv

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FAAddMAC(BCM_HandleType aConnHdl,
                               uint8_t *const aMac,
                               uint32_t aExternal,
                               MCU_DeviceType aMstSlv);

/** @brief Delete MAC entry

    This API will will delete a pool table entry if it is no more referenced by
    any of the flows.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl         Connection handle (from RPC_Connect)
    @param[in]  aMac             Pointer to MAC address
    @param[in]  aMstSlv          Master or slave device
    @param[in]  aIsForceDelete   Flag to indicate force delete of the MAC

    Return values are documented in reverse-chronological order
    @retval    #BCM_ERR_OK              Entry deleted successfully
    @retval    #BCM_ERR_BUSY            Entry cannot be deleted as it is in use
    @retval    #BCM_ERR_NOT_FOUND       Entry not found
    @retval    #BCM_ERR_INVAL_STATE     FA is configured in BYPASS mode
    @retval    #BCM_ERR_UNINIT          FA is uninitialised
    @retval    #BCM_ERR_INVAL_PARAMS    Invalid aMstSlv
                                        aMac is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FADeleteMAC(BCM_HandleType aConnHdl,
                                  const uint8_t *const aMac,
                                  MCU_DeviceType aMstSlv,
                                  uint32_t aIsForceDelete);

/** @brief Get Table of MAC addresses

    This API will retrieve Pool Table MAC addresses, their domain(internal/
    external) and their usage as a bitmask of flow IDs

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aConnHdl        Connection handle (from RPC_Connect)
    @param[out]   aMacSnapshot    Pointer to retrieve MAC snapshot

    Return values are documented in reverse-chronological order
    @retval   #BCM_ERR_OK           Successfully retrieved MAC addresses
    @retval   #BCM_ERR_UNINIT       FA is uninitialised
    @retval   #BCM_ERR_INVAL_PARAMS aMacSnapshot is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FAGetMacSnapshot(BCM_HandleType aConnHdl,
                                       ETHSWT_FAMacSnapshotType *const aMacSnapshot);

/** @brief Enable Interrupts

    This API will enable interrupts

    @behavior Sync, Re-entrant

    @pre None

    @param[in]  aConnHdl          Connection handle (from RPC_Connect)
    @param[in]  aFlags            Flag mask of interrupts to be enabled
                                  (listed below)

    0x00000001: Broadcom header edit invalid
    0x00000002: Checksum error detected on incoming IPv4 frame
    0x00000004: Parsing did not complete during l3 stage
    0x00000008: Parsing did not complete during l2 stage
    0x00000010: Parsing did not complete during brcm header stage
    0x00000020: HW queue overflow
    0x00000040: Header buffer overflow
    0x00000080: RXQ buffer overflow
    0x00000100: Sop/Eop error
    0x00000200: Split buffer overflow
    0x00000400: Latency buffer overflow
    0x00000800: Merge error
    0x00001000: Tx queue overflow error
    0x00002000: RSV buffer overflow error
    0x00004000: Correctable ECC error has been detected in the header buffer
    0x00008000: Correctable ECC error has been detected in the HWQ buffer
    0x00010000: Correctable ECC error has been detected in the HWQ buffer
    0x00020000: Correctable ECC error has been detected in the latency buffer
    0x00040000: Correctable ECC error has been detected in the napt flow table
    0x00080000: Correctable ECC error has been detected in the next hop table
    0x00100000: Uncorrectable ECC error has been detected in the header buffer
    0x00200000: Uncorrectable ECC error has been detected in the HWQ buffer
    0x00400000: Uncorrectable ECC error has been detected in the HWQ buffer
    0x00800000: Uncorrectable ECC error has been detected in the latency buffer
    0x01000000: Uncorrectable ECC error has been detected in the napt flow table
    0x02000000: Uncorrectable ECC error has been detected in the next hop table

    Return values are documented in reverse-chronological order
    @retval   #BCM_ERR_OK           Successfully enabled interrupts
    @retval   #BCM_ERR_UNINIT       FA is uninitialised
    @retval   #BCM_ERR_NOPERM       No permission when CTF is in BYPASS Mode

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FAInterruptEnable(BCM_HandleType aConnHdl,
                                        ETHSWT_FAIntrFlagsType aFlags);

/** @brief Reset FA

    This API will reset FA block and reinitialize it with the passed
    configuration

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aConnHdl          Connection handle (from RPC_Connect)
    @param[in]   aFACtfCfg         FA CTF configuration

    Return values are documented in reverse-chronological order
    @retval   #BCM_ERR_OK           Reset successfull
    @retval   #BCM_ERR_INVAL_PARAMS aFACtfCfg is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHSWT
*/
extern int32_t ETHSWT_FAReset(BCM_HandleType aConnHdl,
                              ETHSWT_FACtfCfgType *aFACtfCfg);

#endif /* ETHSWT_ABSTRACT_FA_H */
/** @} */
