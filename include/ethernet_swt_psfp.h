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
    @defgroup grp_ethernet_swt_psfp_ifc Switch PSFP abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_psfp_ifc
    @{
    <p>NOTE on intervalOctetMax: As per the 802.1Q 2022 specification (Section 17.7.24)
    intervalOctetMax is an integer representing the maximum number of SDU bytes that
    are allowed to pass in a particular gate interval. The existing platforms have
    support for upto 64 gates and upto a gate control list size of 16. However, the
    hardware only supports a limited number of pre-defined values that need to be
    shared across all gates and intervals. This means that the user needs to
    judiciously decide on these values so that it can cover their use case. The SDK
    interface complies to the specification but it will return an error when we run
    out of these pre-defined values. </p>
    <p> NOTE on SDU for Ethernet L2 streams: As per the 802.1Q 2022 specification
    (Section 6.8.1) the Ethernet MAC Service Data Unit (SDU) can be visualized as one
    of the following:

    Untagged Frame <br>
    "-------------------------------------------------------------"<br>
    | DA | SA | SDU payload (includes Ethertype) | FCS |<br>
    "-------------------------------------------------------------"

    Priority Tagged or (singly) VLAN tagged Frame <br>
    "-------------------------------------------------------------------------------" <br>
    | DA | SA | 0x8100 | Tag | SDU payload (includes Ethertype) | FCS | <br>
    "-------------------------------------------------------------------------------" <br>

    The SDU size is used for the following cases:
    -# Comparing with the configured maxSDUSz value to decide whether or not to admit the frame
    -# Deducting the intervalOctets for a gate (when a gate control list is configured)
    -# Deducting the tokens from the flow meter buckets (when rate limiting is enabled)

    </p>
    @file ethernet_swt_psfp.h

    @brief PSFP Interface
    This file contains the interfaces for the Ethernet abstract for PSFP

    @version 1.0 Initial version
*/

#ifndef ETHSWT_ABSTRACT_PSFP_H
#define ETHSWT_ABSTRACT_PSFP_H

#include <ethernet_common.h>
#include <ethernet_swt_common.h>
#include <module_msg.h>
#include <bcm_utils.h>

/**
    @name Ethernet Service PSFP API IDs
    @{
    @brief API IDs for PSFP in Ethernet Service
*/
#define BRCM_SWARCH_ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE_MACRO     (0x8D01U) /**< @brief #ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE       */
#define BRCM_SWARCH_ETHSWT_PSFP_MAX_GCL_ENTRIES_MACRO          (0x8D02U) /**< @brief #ETHSWT_PSFP_MAX_GCL_ENTRIES            */
#define BRCM_SWARCH_ETHSWT_PSFP_CONFIG_MAGIC_ID_MACRO          (0x8D03U) /**< @brief #ETHSWT_PSFP_CONFIG_MAGIC_ID            */
#define BRCM_SWARCH_ETHSWT_PSFP_ID_MACRO                       (0x8D04U) /**< @brief #ETHSWT_PSFP_ID                         */
#define BRCM_SWARCH_ETHSWT_PSFP_CFG_MAX_FLOW_METERS_MACRO      (0x8D05U) /**< @brief #ETHSWT_PSFP_CFG_MAX_FLOW_METERS        */
#define BRCM_SWARCH_ETHSWT_PSFP_CFG_MAX_GATES_MACRO            (0x8D06U) /**< @brief #ETHSWT_PSFP_CFG_MAX_GATES              */
#define BRCM_SWARCH_ETHSWT_PSFP_CFG_MAX_STREAM_FILTERS_MACRO   (0x8D07U) /**< @brief #ETHSWT_PSFP_CFG_MAX_STREAM_FILTERS     */
#define BRCM_SWARCH_ETHSWT_PSFP_CFG_MAX_STREAMS_MACRO          (0x8D08U) /**< @brief #ETHSWT_PSFP_CFG_MAX_STREAMS            */
#define BRCM_SWARCH_ETHSWT_PSFP_MAXSDU_INVALID_MACRO           (0x8D09U) /**< @brief #ETHSWT_PSFP_MAXSDU_INVALID             */
#define BRCM_SWARCH_ETHSWT_PSFP_STREAMIDX_WILDCARD_MACRO       (0x8D0AU) /**< @brief #ETHSWT_PSFP_STREAMIDX_WILDCARD         */
#define BRCM_SWARCH_ETHSWT_PSFP_FLOWMETERIDX_INVALID_MACRO     (0x8D0BU) /**< @brief #ETHSWT_PSFP_FLOWMETERIDX_INVALID       */
#define BRCM_SWARCH_ETHSWT_PSFP_STREAMHDL_TYPE                 (0x8D0CU) /**< @brief #ETHSWT_PSFPStreamHdlType               */
#define BRCM_SWARCH_ETHSWT_PSFP_STREAMFILTERHDL_TYPE           (0x8D0DU) /**< @brief #ETHSWT_PSFPStreamFilterHdlType         */
#define BRCM_SWARCH_ETHSWT_PSFP_FLOWMETERHDL_TYPE              (0x8D0EU) /**< @brief #ETHSWT_PSFPFlowMeterHdlType            */
#define BRCM_SWARCH_ETHSWT_PSFP_GATEHDL_TYPE                   (0x8D0FU) /**< @brief #ETHSWT_PSFPGateHdlType                 */
#define BRCM_SWARCH_ETHSWT_PSFP_ID_TYPE                        (0x8D10U) /**< @brief #ETHSWT_PSFPIdType                      */
#define BRCM_SWARCH_ETHSWT_PSFP_MAXOCTETS_TYPE                 (0x8D11U) /**< @brief #ETHSWT_PSFPMaxOctetsType               */
#define BRCM_SWARCH_ETHSWT_PSFP_PRIO_TYPE                      (0x8D12U) /**< @brief #ETHSWT_PSFPPrioType                    */
#define BRCM_SWARCH_ETHSWT_PSFP_FLOWMETERDEFS_TYPE             (0x8D13U) /**< @brief #ETHSWT_PSFPFlowMeterDefsType           */
#define BRCM_SWARCH_ETHSWT_PSFP_GATEBLOCKREASON_TYPE           (0x8D14U) /**< @brief #ETHSWT_PSFPGateBlockReasonType         */
#define BRCM_SWARCH_ETHSWT_PSFP_VLAN_TYPE                      (0x8D15U) /**< @brief #ETHSWT_PSFPVlanType                    */
#define BRCM_SWARCH_ETHSWT_PSFP_DSCP_TYPE                      (0x8D16U) /**< @brief #ETHSWT_PSFPDSCPType                    */
#define BRCM_SWARCH_ETHSWT_PSFP_PROTOCOL_TYPE                  (0x8D17U) /**< @brief #ETHSWT_PSFPProtocolType                */
#define BRCM_SWARCH_ETHSWT_PSFP_FLOWMETERCFG_TYPE              (0x8D18U) /**< @brief #ETHSWT_PSFPFlowMeterCfgType            */
#define BRCM_SWARCH_ETHSWT_PSFP_FRAMECOUNTERS_TYPE             (0x8D19U) /**< @brief #ETHSWT_PSFPFrameCountersType           */
#define BRCM_SWARCH_ETHSWT_PSFP_GATECONTROLLISTENTRY_TYPE      (0x8D1AU) /**< @brief #ETHSWT_PSFPGateControlListEntryType    */
#define BRCM_SWARCH_ETHSWT_PSFP_GATECFG_TYPE                   (0x8D1BU) /**< @brief #ETHSWT_PSFPGateCfgType                 */
#define BRCM_SWARCH_ETHSWT_PSFP_IDENT_TYPE                     (0x8D1CU) /**< @brief #ETHSWT_PSFPIdentType                   */
#define BRCM_SWARCH_ETHSWT_PSFP_STREAMIDENTITYCFG_TYPE         (0x8D1DU) /**< @brief #ETHSWT_PSFPStreamIdentityCfgType       */
#define BRCM_SWARCH_ETHSWT_PSFP_FILTERCFG_TYPE                 (0x8D1EU) /**< @brief #ETHSWT_PSFPFilterCfgType               */
#define BRCM_SWARCH_ETHSWT_PSFP_STREAMFILTER_TYPE              (0x8D1FU) /**< @brief #ETHSWT_PSFPStreamFilterType            */
#define BRCM_SWARCH_ETHSWT_PSFP_STREAMFILTERSTATUS_TYPE        (0x8D20U) /**< @brief #ETHSWT_PSFPStreamFilterStatusType      */
#define BRCM_SWARCH_ETHSWT_PSFP_FLOWMETERSTATUS_TYPE           (0x8D21U) /**< @brief #ETHSWT_PSFPFlowMeterStatusType         */
#define BRCM_SWARCH_ETHSWT_PSFP_GATESTATUS_TYPE                (0x8D22U) /**< @brief #ETHSWT_PSFPGateStatusType              */
#define BRCM_SWARCH_ETHSWT_PSFP_GLOBALCFG_TYPE                 (0x8D23U) /**< @brief #ETHSWT_PSFPGlobalCfgType               */
#define BRCM_SWARCH_ETHSWT_PSFP_CFG_TYPE                       (0x8D24U) /**< @brief #ETHSWT_PSFPCfgType                     */
#define BRCM_SWARCH_ETHSWT_PSFP_ADDSTREAMMSG_TYPE              (0x8D25U) /**< @brief #ETHSWT_PSFPAddStreamMsgType            */
#define BRCM_SWARCH_ETHSWT_PSFP_ADDSTREAMFILTERMSG_TYPE        (0x8D26U) /**< @brief #ETHSWT_PSFPAddStreamFilterMsgType      */
#define BRCM_SWARCH_ETHSWT_PSFP_UPDATESTREAMFILTERMSG_TYPE     (0x8D27U) /**< @brief #ETHSWT_PSFPUpdateStreamFilterMsgType   */
#define BRCM_SWARCH_ETHSWT_PSFP_GETFRAMECOUNTERSMSG_TYPE       (0x8D28U) /**< @brief #ETHSWT_PSFPGetFrameCountersMsgType     */
#define BRCM_SWARCH_ETHSWT_PSFP_ADDFLOWMETERMSG_TYPE           (0x8D29U) /**< @brief #ETHSWT_PSFPAddFlowMeterMsgType         */
#define BRCM_SWARCH_ETHSWT_PSFP_UPDATEFLOWMETERMSG_TYPE        (0x8D2AU) /**< @brief #ETHSWT_PSFPUpdateFlowMeterMsgType      */
#define BRCM_SWARCH_ETHSWT_PSFP_FLOWMETERDROPALLFRMSMSG_TYPE   (0x8D2BU) /**< @brief #ETHSWT_PSFPFlowMeterDropAllFrmsMsgType */
#define BRCM_SWARCH_ETHSWT_PSFP_ADDGATEMSG_TYPE                (0x8D2CU) /**< @brief #ETHSWT_PSFPAddGateMsgType              */
#define BRCM_SWARCH_ETHSWT_PSFP_UPDATEGATEMSG_TYPE             (0x8D2DU) /**< @brief #ETHSWT_PSFPUpdateGateMsgType           */
#define BRCM_SWARCH_ETHSWT_PSFP_SETTUNINGOFFSETMSG_TYPE        (0x8D2EU) /**< @brief #ETHSWT_PSFPSetTuningOffsetMsgType      */
#define BRCM_SWARCH_ETHSWT_PSFP_GETSTREAMFILTERSTATUSMSG_TYPE  (0x8D30U) /**< @brief #ETHSWT_PSFPGetStreamFilterStatusMsgType*/
#define BRCM_SWARCH_ETHSWT_PSFP_GETFLOWMETERSTATUSMSG_TYPE     (0x8D31U) /**< @brief #ETHSWT_PSFPGetFlowMeterStatusMsgType   */
#define BRCM_SWARCH_ETHSWT_PSFP_GETGATESTATUSMSG_TYPE          (0x8D32U) /**< @brief #ETHSWT_PSFPGetGateStatusMsgType        */
#define BRCM_SWARCH_ETHSWT_PSFP_MSGUNION_TYPE                  (0x8D33U) /**< @brief #ETHSWT_PSFPMsgUnionType                */
#define BRCM_SWARCH_ETHSWT_PSFP_ADDSTREAM_PROC                 (0x8D34U) /**< @brief #ETHSWT_PSFPAddStream                   */
#define BRCM_SWARCH_ETHSWT_PSFP_REMOVESTREAM_PROC              (0x8D35U) /**< @brief #ETHSWT_PSFPRemoveStream                */
#define BRCM_SWARCH_ETHSWT_PSFP_ADDSTREAMFILTER_PROC           (0x8D36U) /**< @brief #ETHSWT_PSFPAddStreamFilter             */
#define BRCM_SWARCH_ETHSWT_PSFP_UPDATESTREAMFILTER_PROC        (0x8D37U) /**< @brief #ETHSWT_PSFPUpdateStreamFilter          */
#define BRCM_SWARCH_ETHSWT_PSFP_REMOVESTREAMFILTER_PROC        (0x8D38U) /**< @brief #ETHSWT_PSFPRemoveStreamFilter          */
#define BRCM_SWARCH_ETHSWT_PSFP_GETFRAMECOUNTERS_PROC          (0x8D39U) /**< @brief #ETHSWT_PSFPGetFrameCounters            */
#define BRCM_SWARCH_ETHSWT_PSFP_ADDFLOWMETER_PROC              (0x8D3AU) /**< @brief #ETHSWT_PSFPAddFlowMeter                */
#define BRCM_SWARCH_ETHSWT_PSFP_UPDATEFLOWMETER_PROC           (0x8D3BU) /**< @brief #ETHSWT_PSFPUpdateFlowMeter             */
#define BRCM_SWARCH_ETHSWT_PSFP_FLOWMETERDROPALLFRAMES_PROC    (0x8D3CU) /**< @brief #ETHSWT_PSFPFlowMeterDropAllFrames      */
#define BRCM_SWARCH_ETHSWT_PSFP_ADDGATE_PROC                   (0x8D3DU) /**< @brief #ETHSWT_PSFPAddGate                     */
#define BRCM_SWARCH_ETHSWT_PSFP_UPDATEGATE_PROC                (0x8D3EU) /**< @brief #ETHSWT_PSFPUpdateGate                  */
#define BRCM_SWARCH_ETHSWT_PSFP_SETENABLEDPORTS_PROC           (0x8D3FU) /**< @brief #ETHSWT_PSFPSetEnabledPorts             */
#define BRCM_SWARCH_ETHSWT_PSFP_SETTUNINGOFFSET_PROC           (0x8D40U) /**< @brief #ETHSWT_PSFPSetTuningOffset             */
#define BRCM_SWARCH_ETHSWT_PSFP_ACKEVENT_PROC                  (0x8D41U) /**< @brief #ETHSWT_PSFPAckEvent                    */
#define BRCM_SWARCH_ETHSWT_PSFP_GETSTREAMFILTERSTATUS_PROC     (0x8D42U) /**< @brief #ETHSWT_PSFPGetStreamFilterStatus       */
#define BRCM_SWARCH_ETHSWT_PSFP_GETFLOWMETERSTATUS_PROC        (0x8D45U) /**< @brief #ETHSWT_PSFPGetFlowMeterStatus          */
#define BRCM_SWARCH_ETHSWT_PSFP_GETGATESTATUS_PROC             (0x8D46U) /**< @brief #ETHSWT_PSFPGetGateStatus               */
#define BRCM_SWARCH_ETHSWT_PSFP_CLEARFRAMECOUNTERS_PROC        (0x8D47U) /**< @brief #ETHSWT_PSFPClearFrameCounters          */
#define BRCM_SWARCH_ETHSWT_PSFP_PKTDROPREASON_TYPE             (0x8D48U) /**< @brief #ETHSWT_PSFPPktDropReasonType           */
#define BRCM_SWARCH_ETHSWT_PSFP_PKTDROPMSG_TYPE                (0x8D49U) /**< @brief #ETHSWT_PSFPPktDropEventMsgType         */
#define BRCM_SWARCH_ETHSWT_PSFP_MAX_EVENTS_PER_MSG_MACRO       (0x8D4AU) /**< @brief #ETHSWT_PSFP_MAX_EVENTS_PER_MSG         */
#define BRCM_SWARCH_ETHSWT_PSFP_EVENTLISTMSG_TYPE              (0x8D4BU) /**< @brief #ETHSWT_PSFPEventsListMsgType           */
#define BRCM_SWARCH_ETHSWT_PSFP_REMOVEGATE_PROC                (0x8D4CU) /**< @brief #ETHSWT_PSFPRemoveGate                  */
#define BRCM_SWARCH_ETHSWT_PSFP_REMOVEFLOWMETER_PROC           (0x8D4DU) /**< @brief #ETHSWT_PSFPRemoveFlowMeter             */
#define BRCM_SWARCH_ETHSWT_PSFP_GETHDLSFORSTRMFILTERINST_PROC  (0x8D4EU) /**< @brief #ETHSWT_PSFPGetHdlsForStreamFilterInst  */
#define BRCM_SWARCH_ETHSWT_PSFP_GETHDLSFORFILTERMSG_TYPE       (0x8D4FU) /**< @brief #ETHSWT_PSFPGetHdlsForFilterMsgType     */
#define BRCM_SWARCH_ETHSWT_PSFP_GETSTREAMCONFIG_PROC           (0x8D50U) /**< @brief #ETHSWT_PSFPGetStreamConfig             */
#define BRCM_SWARCH_ETHSWT_PSFP_GETGATECONFIG_PROC             (0x8D51U) /**< @brief #ETHSWT_PSFPGetGateConfig               */
#define BRCM_SWARCH_ETHSWT_PSFP_GETFLOWMETERCONFIG_PROC        (0x8D52U) /**< @brief #ETHSWT_PSFPGetFlowMeterConfig          */
#define BRCM_SWARCH_ETHSWT_PSFP_GETSTREAMFILTERCONFIG_PROC     (0x8D53U) /**< @brief #ETHSWT_PSFPGetStreamFilterConfig       */
#define BRCM_SWARCH_ETHSWT_PSFP_GETSTREAMCFG_TYPE              (0x8D54U) /**< @brief #ETHSWT_PSFPGetStreamCfgMsgType         */
#define BRCM_SWARCH_ETHSWT_PSFP_GETGATECFG_TYPE                (0x8D55U) /**< @brief #ETHSWT_PSFPGetGateCfgMsgType           */
#define BRCM_SWARCH_ETHSWT_PSFP_GETFLOWMETERCFG_TYPE           (0x8D56U) /**< @brief #ETHSWT_PSFPGetFlowMeterCfgMsgType      */
#define BRCM_SWARCH_ETHSWT_PSFP_GETSTREAMFILTERCFG_TYPE        (0x8D57U) /**< @brief #ETHSWT_PSFPGetStreamFilterCfgMsgType   */
/** @} */

/**
    @brief Maximum size of PSFP payload

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE     (440UL)

/**
    @brief Configuration Macro for maximum number of flow meters

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_CFG_MAX_FLOW_METERS      (64UL)

/**
    @brief Configuration Macro for maximum number of gates

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_CFG_MAX_GATES            (32UL)

/**
    @brief Configuration Macro for maximum number of stream filters

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_CFG_MAX_STREAM_FILTERS   (128UL)

/**
    @brief Configuration Macro for maximum number of streams

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_CFG_MAX_STREAMS          (64UL)

/**
    @brief Maximum number of entries in a gate control list

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_MAX_GCL_ENTRIES      (16U)

/**
    @brief Magic number for the configuration structure, containing 'PSFP'

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_CONFIG_MAGIC_ID      (0x50465350UL)

/**
    @name PSFP ID Macros
    @{
    @brief Macros to Construct PSFP ID

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_ID(aId)       BCM_MSG(BCM_GROUPID_ETHSRV, BCM_PSFP_ID, aId)
#define ETHSWT_PSFP_ID_ASYNC(aId) BCM_MSG_ASYNC(BCM_GROUPID_ETHSRV, BCM_PSFP_ID, aId)
/** @} */

/**
    @brief Invalid value of maxSDU parameter

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_MAXSDU_INVALID        (0xFFFFFFFFUL)

/**
    @brief Stream index for a wildcard stream

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_STREAMIDX_WILDCARD    (0xFFFFFFFFUL)

/**
    @brief Invalid flow meter index indicating that metering is not required

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_FLOWMETERIDX_INVALID  (0xFFFFFFFFUL)

/**
    @name Switch PSFP command IDs
    @{
    @brief Switch PSFP command IDs group

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PSFPIdType;                                       /**< @brief PSFP command message Type                                                       */
#define ETHSWT_PSFP_ID_ADDSTREAM              ETHSWT_PSFP_ID(0x1U)        /**< @brief #ETHSWT_PSFPAddStreamMsgType             #ETHSWT_PSFPAddStream                  */
#define ETHSWT_PSFP_ID_REMOVESTREAM           ETHSWT_PSFP_ID(0x2U)        /**< @brief #ETHSWT_PSFPStreamHdlType                #ETHSWT_PSFPRemoveStream               */
#define ETHSWT_PSFP_ID_ADDSTREAMFILTER        ETHSWT_PSFP_ID(0x3U)        /**< @brief #ETHSWT_PSFPAddStreamFilterMsgType       #ETHSWT_PSFPAddStreamFilter            */
#define ETHSWT_PSFP_ID_UPDATESTREAMFILTER     ETHSWT_PSFP_ID(0x4U)        /**< @brief #ETHSWT_PSFPUpdateStreamFilterMsgType    #ETHSWT_PSFPUpdateStreamFilter         */
#define ETHSWT_PSFP_ID_REMOVESTREAMFILTER     ETHSWT_PSFP_ID(0x5U)        /**< @brief #ETHSWT_PSFPStreamFilterHdlType          #ETHSWT_PSFPRemoveStreamFilter         */
#define ETHSWT_PSFP_ID_GETFRAMECOUNTERS       ETHSWT_PSFP_ID(0x6U)        /**< @brief #ETHSWT_PSFPGetFrameCountersMsgType      #ETHSWT_PSFPGetFrameCounters           */
#define ETHSWT_PSFP_ID_ADDFLOWMETER           ETHSWT_PSFP_ID(0x7U)        /**< @brief #ETHSWT_PSFPAddFlowMeterMsgType          #ETHSWT_PSFPAddFlowMeter               */
#define ETHSWT_PSFP_ID_UPDATEFLOWMETER        ETHSWT_PSFP_ID(0x8U)        /**< @brief #ETHSWT_PSFPUpdateFlowMeterMsgType       #ETHSWT_PSFPUpdateFlowMeter            */
#define ETHSWT_PSFP_ID_FLOWMETERDROPALLFRAMES ETHSWT_PSFP_ID(0x9U)        /**< @brief #ETHSWT_PSFPFlowMeterDropAllFrmsMsgType  #ETHSWT_PSFPFlowMeterDropAllFrames     */
#define ETHSWT_PSFP_ID_ADDGATE                ETHSWT_PSFP_ID(0xAU)        /**< @brief #ETHSWT_PSFPAddGateMsgType               #ETHSWT_PSFPAddGate                    */
#define ETHSWT_PSFP_ID_UPDATEGATE             ETHSWT_PSFP_ID(0xBU)        /**< @brief #ETHSWT_PSFPUpdateGateMsgType            #ETHSWT_PSFPUpdateGate                 */
#define ETHSWT_PSFP_ID_SETENABLEDPORTS        ETHSWT_PSFP_ID(0xCU)        /**< @brief #uint32_t                                #ETHSWT_PSFPSetEnabledPorts            */
#define ETHSWT_PSFP_ID_SETTUNINGOFFSET        ETHSWT_PSFP_ID(0xDU)        /**< @brief #ETHSWT_PSFPSetTuningOffsetMsgType       #ETHSWT_PSFPSetTuningOffset            */
#define ETHSWT_PSFP_ID_ACKEVENT               ETHSWT_PSFP_ID(0xEU)        /**< @brief #ETHSWT_PSFPStreamFilterHdlType          #ETHSWT_PSFPAckEvent                   */
#define ETHSWT_PSFP_ID_GETSTREAMFILTERSTATUS  ETHSWT_PSFP_ID(0x11U)       /**< @brief #ETHSWT_PSFPGetStreamFilterStatusMsgType #ETHSWT_PSFPGetStreamFilterStatus      */
#define ETHSWT_PSFP_ID_GETFLOWMETERSTATUS     ETHSWT_PSFP_ID(0x12U)       /**< @brief #ETHSWT_PSFPGetFlowMeterStatusMsgType    #ETHSWT_PSFPGetFlowMeterStatus         */
#define ETHSWT_PSFP_ID_GETGATESTATUS          ETHSWT_PSFP_ID(0x13U)       /**< @brief #ETHSWT_PSFPGetGateStatusMsgType         #ETHSWT_PSFPGetGateStatus              */
#define ETHSWT_PSFP_ID_CLEARFRAMECOUNTERS     ETHSWT_PSFP_ID(0x14U)       /**< @brief #ETHSWT_PSFPStreamFilterHdlType          #ETHSWT_PSFPClearFrameCounters         */
#define ETHSWT_PSFP_ID_REMOVEFLOWMETER        ETHSWT_PSFP_ID(0x15U)       /**< @brief #ETHSWT_PSFPFlowMeterHdlType             #ETHSWT_PSFPRemoveFlowMeter            */
#define ETHSWT_PSFP_ID_REMOVEGATE             ETHSWT_PSFP_ID(0x16U)       /**< @brief #ETHSWT_PSFPGateHdlType                  #ETHSWT_PSFPRemoveGate                 */
#define ETHSWT_PSFP_ID_GETHANDLESFORFILTER    ETHSWT_PSFP_ID(0x17U)       /**< @brief #ETHSWT_PSFPGetHdlsForFilterMsgType      #ETHSWT_PSFPGetHdlsForStreamFilterInst */
#define ETHSWT_PSFP_ID_GETSTREAMCONFIG        ETHSWT_PSFP_ID(0x18U)       /**< @brief #ETHSWT_PSFPGetStreamCfgMsgType          #ETHSWT_PSFPGetStreamConfig            */
#define ETHSWT_PSFP_ID_GETGATECONFIG          ETHSWT_PSFP_ID(0x19U)       /**< @brief #ETHSWT_PSFPGetGateCfgMsgType            #ETHSWT_PSFPGetGateConfig              */
#define ETHSWT_PSFP_ID_GETFLOWMETERCONFIG     ETHSWT_PSFP_ID(0x1AU)       /**< @brief #ETHSWT_PSFPGetFlowMeterCfgMsgType       #ETHSWT_PSFPGetFlowMeterConfig         */
#define ETHSWT_PSFP_ID_GETSTREAMFILTERCONFIG  ETHSWT_PSFP_ID(0x1BU)       /**< @brief #ETHSWT_PSFPGetStreamFilterCfgMsgType    #ETHSWT_PSFPGetStreamFilterConfig      */
#define ETHSWT_PSFP_ID_PKTDROPEVENTS          ETHSWT_PSFP_ID_ASYNC(0x1U)  /**< @brief Packet drop event notification                                                  */
/** @} */

/**
    @name Switch PSFP stream handle type
    @{
    @brief Switch PSFP stream handle type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef BCM_HandleType ETHSWT_PSFPStreamHdlType;                 /**< @brief Stream handle type */
#define ETHSWT_PSFP_STREAMHDL_WILDCARD   (0xFFFFFFFFFFFFFFFFULL) /**< @brief Wildcard stream handle */
/** @} */

/**
    @name Switch PSFP stream filter handle type
    @{
    @brief Switch PSFP stream filter handle type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef BCM_HandleType ETHSWT_PSFPStreamFilterHdlType;  /**< @brief Stream filter handle type */
/** @} */

/**
    @name Switch PSFP Flow Meter Handle type
    @{
    @brief Switch PSFP Flow Meter Handle type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef BCM_HandleType ETHSWT_PSFPFlowMeterHdlType;              /**< @brief Flow meter handle type */
#define ETHSWT_PSFP_FLOWMETERHDL_INVALID (0xFFFFFFFFFFFFFFFFULL) /**< @brief Flow meter handle value to be used
                                                                           when metering is not required */
/** @} */

/**
    @name Switch PSFP gate handle type
    @{
    @brief Switch PSFP gate handle type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef BCM_HandleType ETHSWT_PSFPGateHdlType;              /**< @brief Gate handle type */
/** @} */

/**
    @name Switch PSFP maxOctets type
    @{
    @brief Switch PSFP maxOctets type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PSFPMaxOctetsType;           /**< @brief PSFP maxOctets Type */
#define ETHSWT_PSFP_MAXOCTETS_ZERO    (0x0UL)        /**< @brief 0 bytes             */
#define ETHSWT_PSFP_MAXOCTETS_NOLIMIT (0xFFFFFFFFUL) /**< @brief Unlimited bytes     */
/** @} */

/**
    @name Switch PSFP stream identity type
    @{
    @brief Switch PSFP stream identity type
    Refer to Table 6-1 of IEEE 802.1CB-2017
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PSFPIdentType;                  /**< @brief PSFP Stream Identification Type */
#define ETHSWT_PSFP_IDENT_NULL           (0x0080C201UL) /**< @brief NULL stream identification:
                                                                    Destination MAC address, VLAN */
#define ETHSWT_PSFP_IDENT_SMACVLAN       (0x0080C202UL) /**< @brief Source MAC and VLAN stream
                                                                    identification: Source MAC
                                                                    address, VLAN */
#define ETHSWT_PSFP_IDENT_IP             (0x0080C204UL) /**< @brief IP stream identification:
                                                                    Destination MAC address, VLAN,
                                                                    Source IP address, Destination
                                                                    IP address, DSCP, IP next
                                                                    protocol, Source port,
                                                                    Destination port, Source MAC
                                                                    address */
/** @} */

/**
    @name Switch PSFP priority specification
    @{
    @brief Switch PSFP priority specification

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PSFPPrioType;       /**< @brief PSFP priority specification Type */
#define ETHSWT_PSFP_PRIO0             (0UL) /**< @brief Priority 0 */
#define ETHSWT_PSFP_PRIO1             (1UL) /**< @brief Priority 1 */
#define ETHSWT_PSFP_PRIO2             (2UL) /**< @brief Priority 2 */
#define ETHSWT_PSFP_PRIO3             (3UL) /**< @brief Priority 3 */
#define ETHSWT_PSFP_PRIO4             (4UL) /**< @brief Priority 4 */
#define ETHSWT_PSFP_PRIO5             (5UL) /**< @brief Priority 5 */
#define ETHSWT_PSFP_PRIO6             (6UL) /**< @brief Priority 6 */
#define ETHSWT_PSFP_PRIO7             (7UL) /**< @brief Priority 7 */
#define ETHSWT_PSFP_PRIOANY           (8UL) /**< @brief Wildcard priority value: Any priority */
/** @} */

/**
    @name Switch PSFP Flow Meter Definitions
    @{
    @brief Switch PSFP Flow Meter Definitions

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PSFPFlowMeterDefsType;                   /**< @brief PSFP Flow Meter Definitions Type */
#define ETHSWT_PSFP_FLOWMETERDEFS_MARKALLFRAMESRED_MASK  (0x1UL) /**< @brief Mask for mark all frames red     */
#define ETHSWT_PSFP_FLOWMETERDEFS_MARKALLFRAMESRED_SHIFT (0x0UL) /**< @brief Shift for mark all frames red    */
#define ETHSWT_PSFP_FLOWMETERDEFS_DROPYELLOW_MASK        (0x2UL) /**< @brief Mask for drop yellow             */
#define ETHSWT_PSFP_FLOWMETERDEFS_DROPYELLOW_SHIFT       (0x1UL) /**< @brief Shift for drop yellow            */
#define ETHSWT_PSFP_FLOWMETERDEFS_COUPLINGFLAG_MASK      (0x4UL) /**< @brief Mask for coupling flag           */
#define ETHSWT_PSFP_FLOWMETERDEFS_COUPLINGFLAG_SHIFT     (0x2UL) /**< @brief Shift for coupling flag          */
#define ETHSWT_PSFP_FLOWMETERDEFS_COLORMODE_MASK         (0x8UL) /**< @brief Mask for color mode              */
#define ETHSWT_PSFP_FLOWMETERDEFS_COLORMODE_SHIFT        (0x3UL) /**< @brief Shift for color mode             */
/** @} */

/**
    @name Switch PSFP gate block reason codes
    @{
    @brief Switch PSFP gate block reason codes

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PSFPGateBlockReasonType;                   /**< @brief PSFP Gate Block Reason Type           */
#define ETHSWT_PSFP_GATEBLOCKREASON_INVALIDRX       (0x1UL)        /**< @brief Gate blocked due to invalid reception */
#define ETHSWT_PSFP_GATEBLOCKREASON_OCTETSEXCEEDED  (0x2UL)        /**< @brief Gate blocked due to octets exceeded   */
#define ETHSWT_PSFP_GATEBLOCKREASON_ALL             (0xFFFFFFFFUL) /**< @brief Definition for all gate blocks        */
/** @} */

/**
    @name Switch PSFP VLAN tag type
    @{
    @brief Switch PSFP VLAN tag type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint16_t ETHSWT_PSFPVlanType;             /**< @brief VLAN type                    */
#define ETHSWT_PSFP_VLAN_PRIORITY      (0x0U)     /**< @brief Untagged or priority tagged (Vid = 0) */
#define ETHSWT_PSFP_VLAN_MAX           (0xFFEU)   /**< @brief Maximum allowed Vid value             */
#define ETHSWT_PSFP_VLAN_ALL           (0xFFFFU)  /**< @brief Untagged/priority tagged/VLAN tagged  */
/** @} */

/**
    @name Switch PSFP DSCP type
    @{
    @brief Switch PSFP DSCP (Differentiated Services Code Point) type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_PSFPDSCPType;       /**< @brief DSCP type                */
#define ETHSWT_PSFP_DSCP_MAX         (63U) /**< @brief Maximum valid DSCP value */
#define ETHSWT_PSFP_DSCP_NONE        (64U) /**< @brief DSCP to be ignored       */
/** @} */

/**
    @name Switch PSFP Protocol type
    @{
    @brief Switch PSFP Protocol

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef ETHER_L4ProtoType ETHSWT_PSFPProtocolType;                /**< @brief Protocol type                              */
#define ETHSWT_PSFP_PROTOCOL_NONE  (ETHER_L4PROTO_NONE) /**< @brief Do not match protocol field from IP header */
#define ETHSWT_PSFP_PROTOCOL_TCP   (ETHER_L4PROTO_TCP)  /**< @brief TCP (RFC793)                               */
#define ETHSWT_PSFP_PROTOCOL_UDP   (ETHER_L4PROTO_UDP)  /**< @brief UDP (RFC768)                               */
#define ETHSWT_PSFP_PROTOCOL_SCTP  (ETHER_L4PROTO_SCTP) /**< @brief SCTP (RFC4960)                             */
/** @} */

/**
    @name Switch PSFP event types
    @{
    @brief Switch PSFP event types

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint32_t ETHSWT_PSFPPktDropReasonType;          /**< @brief PSFP packet drop reason Type           */
#define ETHSWT_PSFP_PKTDROPREASON_OVRSZFRM       (1UL)  /**< @brief Frame dropped on being classified as oversized */
#define ETHSWT_PSFP_PKTDROPREASON_REDFRMDROPPED  (2UL)  /**< @brief Frame dropped on being classified as RED by the flow meter */
#define ETHSWT_PSFP_PKTDROPREASON_OCTETEXCEEDED  (4UL)  /**< @brief Frame dropped due to octets exceeded on the gate */
#define ETHSWT_PSFP_PKTDROPREASON_INVALIDRX      (8UL)  /**< @brief Frame dropped on being received when the gate was closed */
#define ETHSWT_PSFP_PKTDROPREASON_GATE           (16UL) /**< @brief Frame dropped on gate (exact reason i.e. octets
                                                                    exceeded or invalid reception could not be deduced) */
/** @} */

/**
    @brief Flow Meter configuration
    Refer to section 8.6.5.1.3 of IEEE 802.1Qci-2017
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPFlowMeterCfgType {
    ETHSWT_PSFPFlowMeterDefsType flags;  /**< @brief PSFP Flags encoded as follows:
                                              resv (28),
                                              colorMode (1),
                                              coupling flag (1),
                                              drop yellow frames (1) ,
                                              enable marking all frames as red (1)      */
    uint32_t                     cir;    /**< @brief Committed information rate in Kbps */
    uint32_t                     cbs;    /**< @brief Committed burst size in bytes      */
    uint32_t                     eir;    /**< @brief Excess information rate in Kbps    */
    uint32_t                     ebs;    /**< @brief Excess burst size in bytes         */
    uint32_t                     resv;   /**< @brief Reserved @xsd rsvd                 */
} ETHSWT_PSFPFlowMeterCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPFlowMeterCfgType, 24UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Per Stream Frame Counters
    Refer to section 8.6.5.1.1.f of IEEE 802.1Qci-2017
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPFrameCountersType {
    uint64_t  matchedFrames;    /**< @brief Count of frames that matched the
                                            stream filter */
    uint64_t  passingMaxSDU;    /**< @brief Count of frames that passed the
                                            maxSDU size check */
    uint64_t  failingMaxSDU;    /**< @brief Count of frames that failed the
                                            maxSDU size check */
    uint64_t  passingGate;      /**< @brief Count of frames that passed the
                                            gate check */
    uint64_t  failingGate;      /**< @brief Count of frames that failed the
                                            gate check */
    uint64_t  failingFlowMeter; /**< @brief Count of frames that failed the
                                            flow meter */
} ETHSWT_PSFPFrameCountersType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPFrameCountersType, 48UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Gate slot configuration
    Refer to 8.6.5.1.2 of IEEE 802.1Qci-2017
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGateControlListEntryType {
    uint32_t                    state;     /**< @brief Indicates whether the gate is closed (0) or open (1)  */
    uint32_t                    interval;  /**< @brief Time interval in nanoseconds for this slot. For legacy
                                                       platforms this is recommended to be in units of 4ns   */
    ETHSWT_PSFPMaxOctetsType    maxOctets; /**< @brief Maximum number of SDU bytes allowed to pass through
                                                       the gate in this interval. One may chose
                                                       #ETHSWT_PSFP_MAXOCTETS_ZERO to set the limit to 0
                                                       bytes thereby disabling any frames from passing.
                                                       Conversely, one may chose #ETHSWT_PSFP_MAXOCTETS_NOLIMIT
                                                       to remove any limit on the number of bytes allowed to
                                                       pass through.                                         */
    ETHSWT_PSFPPrioType         ipv;       /**< @brief Internal priority value. To chose the null priority
                                                       value i.e. use incoming frame's priority, use
                                                       #ETHSWT_PSFP_PRIOANY                                  */
    uint32_t                    resv;      /**< @brief Reserved @xsd rsvd                                    */
} ETHSWT_PSFPGateControlListEntryType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGateControlListEntryType, 20UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Gate configuration
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGateCfgType {
    uint32_t                            defaultState;                                 /**< @brief Indicates whether the gate is closed (0)
                                                                                                  or open (1). This is applicable when
                                                                                                  #gateControlListLen is 0 and also
                                                                                                  before gateConfig is loaded (but the
                                                                                                  gate has been enabled) */
    ETHSWT_PSFPPrioType                 defaultIPV;                                   /**< @brief Internal priority value. This is applicable
                                                                                                  when #gateControlListLen is 0 and also
                                                                                                  before gateConfig is loaded (but the
                                                                                                  gate has been enabled). To chose the
                                                                                                  null priority value i.e. use incoming
                                                                                                  frame's priority, use #ETHSWT_PSFP_PRIOANY.*/
    uint32_t                            baseTimeSecs;                                 /**< @brief Seconds part of the baseTime (based on the
                                                                                                  network time) */
    uint32_t                            baseTimeNanoSecs;                             /**< @brief Nanoseconds part of the baseTime (based on
                                                                                                  the network time) */
    uint32_t                            cycleTime;                                    /**< @brief Duration of the cycle in nanoseconds.
                                                                                                  Valid upto 1 second duration */
    uint32_t                            cycleTimeExtension;                           /**< @brief Cycle time extension (in nanoseconds). If
                                                                                                  newer configuration is about to get loaded
                                                                                                  and could result in truncation of the current
                                                                                                  cycle, then the current cycle would be
                                                                                                  extended till the newer
                                                                                                  base time if atmost cycleTimeExtension
                                                                                                  nanoseconds are remaining */
    uint32_t                            closeGateOnInvalidRxEnable;                   /**< @brief Enable subsequent (and persistent) closure of
                                                                                                  the gate if a frame is received in closed
                                                                                                  state */
    uint32_t                            closeGateOnOctetsExceededEnable;              /**< @brief Enable subsequent (and persistent) closure of
                                                                                                  the gate if a frame is received with
                                                                                                  insufficient octets */
    ETHSWT_PSFPGateControlListEntryType gateControlList[ETHSWT_PSFP_MAX_GCL_ENTRIES]; /**< @brief Gate control list configuration */
    uint32_t                            gateControlListLen;                           /**< @brief Number of valid entries in the gate control
                                                                                                  list @xsd count:gateControlList */
    uint32_t                            resv;                                         /**< @brief Reserved @xsd rsvd */
} ETHSWT_PSFPGateCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGateCfgType, 360UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Stream identification configuration
    Refer to Table 6-1 of IEEE 802.1CB-2017
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPStreamIdentityCfgType {
    ETHSWT_PortMaskType     portMask;          /**< @brief Ports on which the stream
                                                           is expected to ingress */
    ETHSWT_PSFPIdentType    type;              /**< @brief Type of the stream */
    ETHSWT_PSFPVlanType     vlan;              /**< @brief VLAN identifier */
    uint8_t                 mac[6U];           /**< @brief Overloaded MAC address field:
                                                           Interpreted as source MAC when
                                                           type is #ETHSWT_PSFP_IDENT_SMACVLAN
                                                           and as destination MAC in all other
                                                           cases. @xsd type:mac */
    ETHSWT_PSFPDSCPType     dscp;              /**< @brief DSCP field in IP header */
    ETHSWT_PSFPProtocolType protocol;          /**< @brief Protocol/Next Header. If this has
                                                           the value #ETHSWT_PSFP_PROTOCOL_NONE
                                                           then the sourcePort and destPort
                                                           fields are also ignored. */
    uint16_t                resv1;             /**< @brief Reserved @xsd rsvd */
    uint16_t                sourcePort;        /**< @brief Source port number */
    uint16_t                destPort;          /**< @brief Destination port number */
    uint32_t                isIPv4;            /**< @brief Flag indicating that the
                                                           stream is of IPv4 type (1)
                                                           or IPv6 (0) @xsd ipflag:sourceIP,destIP; */
    uint8_t                 sourceIP[16];      /**< @brief Source IP address:
                                                           4 bytes IPv4 or
                                                           16 bytes IPv6.
                                                           Interpreted on the basis
                                                           of type. Provided in
                                                           big endian format.
                                                           For IPv4 the first 4
                                                           indices are used. A value
                                                           of all 0's indicates
                                                           that this field is
                                                           ignored. @xsd type:ip; */
    uint8_t                 destIP[16];        /**< @brief Destination IP address:
                                                           4 bytes IPv4 or
                                                           16 bytes IPv6.
                                                           Interpreted on the basis
                                                           of type. Provided in
                                                           big endian format.
                                                           For IPv4 the first 4
                                                           indices are used @xsd type:ip; */
    uint32_t                resv2[2U];         /**< @brief Reserved @xsd rsvd */
} ETHSWT_PSFPStreamIdentityCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPStreamIdentityCfgType, 72UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to add stream

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPAddStreamMsgType {
    ETHSWT_PSFPStreamIdentityCfgType   identity;  /**< @brief Input: Stream identity */
    ETHSWT_PSFPStreamHdlType           hdl;       /**< @brief Output: Stream handle */
} ETHSWT_PSFPAddStreamMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPAddStreamMsgType, 80UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to get stream config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetStreamCfgMsgType {
    ETHSWT_PSFPStreamIdentityCfgType   identity;  /**< @brief Output: Stream identity */
    ETHSWT_PSFPStreamHdlType           hdl;       /**< @brief Input: Stream handle */
} ETHSWT_PSFPGetStreamCfgMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetStreamCfgMsgType, 80UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Stream filter configuration
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPFilterCfgType {
    ETHSWT_PSFPPrioType priority;                              /**< @brief Priority specification */
    uint32_t            maxSDUSz;                              /**< @brief Maximum SDU size
                                                                           that is allowed
                                                                           for this stream.
                                                                           The check is disabled
                                                                           if #ETHSWT_PSFP_MAXSDU_INVALID
                                                                           is provided. The
                                                                           check is enabled
                                                                           for all other
                                                                           values. A value of
                                                                           0 will enable
                                                                           dropping of all
                                                                           packets on this
                                                                           stream. */
    uint32_t            streamBlockedDueToOverSizeFrameEnable; /**< @brief Enable blocking
                                                                           the stream when
                                                                           a frame fails the
                                                                           maxSDUSz check.
                                                                           This is only valid
                                                                           in case the maxSDU
                                                                           check is enabled */
    uint32_t            resv;                                  /**< @brief Reserved @xsd rsvd */
    uint64_t            gate;                                  /**< @brief Reference to gate
                                                                           associated with this
                                                                           stream. This is an
                                                                           overloaded field.
                                                                           In the static (flash)
                                                                           configuration, this
                                                                           refers to the index
                                                                           into the gate table
                                                                           and is expected
                                                                           to be in the range
                                                                           0 to #numGates-1.
                                                                           For run time commands
                                                                           this refers to the
                                                                           gate handle*/
    uint64_t            meter;                                 /**< @brief Reference to flow
                                                                           meter associated with
                                                                           this stream. This is
                                                                           an overloaded field.
                                                                           In the static (flash)
                                                                           configuration, this
                                                                           refers to the index
                                                                           into the flow meter
                                                                           table. The check is
                                                                           only enabled if a
                                                                           valid index (0 to
                                                                           #numMeters-1) is
                                                                           is provided.
                                                                           Conversely, one can
                                                                           provide
                                                                           #ETHSWT_PSFP_FLOWMETERIDX_INVALID
                                                                           to disable metering.
                                                                           For run time commands
                                                                           this refers to the
                                                                           flow meter handle. The
                                                                           value #ETHSWT_PSFP_FLOWMETERHDL_INVALID
                                                                           may be used to disable
                                                                           metering */
} ETHSWT_PSFPFilterCfgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPFilterCfgType, 32UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Stream filter parameters
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPStreamFilterType {
    uint32_t                 streamIdx; /**< @brief Index into the streams table. A value
                                                    of #ETHSWT_PSFP_STREAMIDX_WILDCARD
                                                    indicates that the filter is
                                                    associated with a wildcard stream */
    uint32_t                 instId;    /**< @brief Index to the Stream filter instance
                                                    table. Expected range is from 0 to
                                                    #ETHSWT_PSFP_MAX_STREAM_FILTERS-1 */
    ETHSWT_PSFPFilterCfgType filters;   /**< @bried Stream filters configuration */
} ETHSWT_PSFPStreamFilterType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPStreamFilterType, 40UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Stream Filter status parameters
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPStreamFilterStatusType {
    uint32_t streamBlockedDueToOversizeFrame;  /**< @brief StreamBlockedDueToOversizeFrame
                                                            parameter 1(true), 0(false) */
} ETHSWT_PSFPStreamFilterStatusType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPStreamFilterStatusType, 4UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Flow meter status parameters
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPFlowMeterStatusType {
    uint32_t   allFramesMarkedRed;  /**< @brief MarkAllFramesRed parameter
                                                1 (true), 0 (false) */
} ETHSWT_PSFPFlowMeterStatusType;

/**
    @brief Gate status parameters
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGateStatusType {
    uint32_t                       closedDueToInvalidRx;      /**< @brief All frames are
                                                                          dropped as the
                                                                          gate blocked on
                                                                          receiving a frame
                                                                          in closed state */
    uint32_t                       closedDueToOctetsExceeded; /**< @brief All frames are
                                                                          dropped as the
                                                                          gate blocked on
                                                                          receiving a frame
                                                                          when the octets
                                                                          were not sufficient */
    uint32_t                       configChangePending;       /**< @brief Configuration
                                                                          change pending on
                                                                          the associated
                                                                          gate */
    uint32_t                       operBaseTimeSecs;          /**< @brief Seconds part of
                                                                          the operational
                                                                          baseTime */
    uint32_t                       operBaseTimeNanoSecs;      /**< @brief Nanoseconds part
                                                                          of the operational
                                                                          baseTime */
    uint32_t                       operCycleTime;             /**< @brief Operational cycle
                                                                          time in
                                                                          nanoseconds */
    uint32_t                       operCycleTimeExtension;    /**< @brief Operational cycle
                                                                          time extension
                                                                          (in nanoseconds) */
} ETHSWT_PSFPGateStatusType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGateStatusType, 28UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to add stream filter

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPAddStreamFilterMsgType {
    uint32_t                       instance;  /**< @brief Index to the Stream filter instance
                                                    table. Expected range is from 0 to
                                                    #ETHSWT_PSFP_MAX_STREAM_FILTERS-1 */
    ETHSWT_PSFPStreamHdlType       streamHdl; /**< @brief Input: Stream handle */
    ETHSWT_PSFPFilterCfgType       config;    /**< @brief Input: Stream filter configuration */
    ETHSWT_PSFPStreamFilterHdlType filterHdl; /**< @brief Output: Stream filter handle */
} ETHSWT_PSFPAddStreamFilterMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPAddStreamFilterMsgType, 56UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to update stream filter

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPUpdateStreamFilterMsgType {
    ETHSWT_PSFPStreamFilterHdlType hdl;      /**< @brief Input: Stream filter handle */
    ETHSWT_PSFPFilterCfgType       filter;   /**< @brief Input: Stream filter */
} ETHSWT_PSFPUpdateStreamFilterMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPUpdateStreamFilterMsgType, 40UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to get stream filter config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetStreamFilterCfgMsgType {
    ETHSWT_PSFPStreamFilterHdlType hdl;      /**< @brief Input: Stream filter handle */
    ETHSWT_PSFPFilterCfgType       filter;   /**< @brief Output: Stream filter */
} ETHSWT_PSFPGetStreamFilterCfgMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetStreamFilterCfgMsgType, 40UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)


/**
    @brief Structure with parameters for the PSFP command to get frame counters

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetFrameCountersMsgType {
    ETHSWT_PSFPStreamFilterHdlType hdl;    /**< @brief Input: Stream filter handle */
    ETHSWT_PSFPFrameCountersType counters; /**< @brief Output: Frame counters */
} ETHSWT_PSFPGetFrameCountersMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetFrameCountersMsgType, 56UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to add a flow meter

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPAddFlowMeterMsgType {
    ETHSWT_PSFPFlowMeterCfgType  config;   /**< @brief Input: Flow meter configuration */
    ETHSWT_PSFPFlowMeterHdlType  hdl;      /**< @brief Output: Flow meter handle */
} ETHSWT_PSFPAddFlowMeterMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPAddFlowMeterMsgType, 32UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to update a flow meter

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPUpdateFlowMeterMsgType {
    ETHSWT_PSFPFlowMeterHdlType  hdl;      /**< @brief Input: Flow meter handle */
    ETHSWT_PSFPFlowMeterCfgType  config;   /**< @brief Input: Flow meter configuration */
} ETHSWT_PSFPUpdateFlowMeterMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPUpdateFlowMeterMsgType, 32UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to get a flow meter config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetFlowMeterCfgMsgType {
    ETHSWT_PSFPFlowMeterHdlType  hdl;      /**< @brief Input: Flow meter handle */
    ETHSWT_PSFPFlowMeterCfgType  config;   /**< @brief Output: Flow meter configuration */
} ETHSWT_PSFPGetFlowMeterCfgMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetFlowMeterCfgMsgType, 32UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)


/**
    @brief Structure with parameters for the PSFP command to drop all flow meter frames

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPFlowMeterDropAllFrmsMsgType {
    ETHSWT_PSFPFlowMeterHdlType  hdl;    /**< @brief Input: Flow meter handle */
    uint32_t                     enable; /**< @brief Input: Feature enable */
} ETHSWT_PSFPFlowMeterDropAllFrmsMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPFlowMeterDropAllFrmsMsgType, 16UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to add gate

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPAddGateMsgType {
    ETHSWT_PSFPGateCfgType config;   /**< @brief Input: Gate configuration */
    ETHSWT_PSFPGateHdlType hdl;      /**< @brief Output: Gate handle */
} ETHSWT_PSFPAddGateMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPAddGateMsgType, 368UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to update gate

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPUpdateGateMsgType {
    ETHSWT_PSFPGateHdlType hdl;      /**< @brief Input: Gate handle */
    ETHSWT_PSFPGateCfgType config;   /**< @brief Input: Gate configuration */
} ETHSWT_PSFPUpdateGateMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPUpdateGateMsgType, 368UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to get gate config

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetGateCfgMsgType {
    ETHSWT_PSFPGateHdlType hdl;      /**< @brief Input: Gate handle */
    ETHSWT_PSFPGateCfgType config;   /**< @brief Output: Gate configuration */
} ETHSWT_PSFPGetGateCfgMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetGateCfgMsgType, 368UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)


/**
    @brief Structure with parameters for the PSFP command to set tuning offset

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPSetTuningOffsetMsgType {
    uint32_t secs;     /**< @brief Input: Seconds part of tuning offset */
    uint32_t nanosecs; /**< @brief Input: Nanoseconds part of tuning offset */
} ETHSWT_PSFPSetTuningOffsetMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPSetTuningOffsetMsgType, 8UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to get stream filter status

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetStreamFilterStatusMsgType {
    ETHSWT_PSFPStreamFilterHdlType     hdl;     /**< @brief Input: Stream filter handle */
    ETHSWT_PSFPStreamFilterStatusType  status;  /**< @brief Output: Stream filter status */
} ETHSWT_PSFPGetStreamFilterStatusMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetStreamFilterStatusMsgType, 16UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to get flow meter status

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetFlowMeterStatusMsgType {
    ETHSWT_PSFPFlowMeterHdlType    hdl;    /**< @brief Input: Flow Meter handle */
    ETHSWT_PSFPFlowMeterStatusType status; /**< @brief Output: Flow Meter status */
} ETHSWT_PSFPGetFlowMeterStatusMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetFlowMeterStatusMsgType, 16UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to get gate status

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetGateStatusMsgType {
    ETHSWT_PSFPGateHdlType    hdl;    /**< @brief Input: Gate handle */
    ETHSWT_PSFPGateStatusType status; /**< @brief Output: Gate status */
} ETHSWT_PSFPGetGateStatusMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetGateStatusMsgType, 40UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP command to get gate status

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGetHdlsForFilterMsgType {
    uint32_t                       instId;     /**< @brief Input: Stream filter instance */
    ETHSWT_PSFPStreamFilterHdlType filterHdl;  /**< @brief Output: Stream filter handle */
    ETHSWT_PSFPStreamHdlType       streamHdl;  /**< @brief Output: Stream handle */
    ETHSWT_PSFPGateHdlType         gateHdl;    /**< @brief Output: Gate handle */
    ETHSWT_PSFPFlowMeterHdlType    meterHdl;   /**< @brief Output: Flow meter handle */
} ETHSWT_PSFPGetHdlsForFilterMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPGetHdlsForFilterMsgType, 40UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Structure with parameters for the PSFP packet drop events

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPPktDropEventMsgType {
    ETHSWT_PSFPStreamFilterHdlType streamFilterHdl;  /**< @brief Input: Handle of stream filter to which
                                                                 the packet was classified */
    ETHSWT_PSFPPktDropReasonType   dropReasons;      /**< @brief Input: Bitmask representing all the packet
                                                                 drop events which have occurred on this
                                                                 stream filter */
} ETHSWT_PSFPPktDropEventMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPPktDropEventMsgType, 16UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Macro ETHSWT_PSFP_MAX_EVENTS_PER_MSG
    @{
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_PSFP_MAX_EVENTS_PER_MSG    (((ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE) - sizeof(uint32_t)) / sizeof(ETHSWT_PSFPPktDropEventMsgType))
/** @} */

/**
    @brief Structure with parameters for the PSFP packet drop events

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPEventsListMsgType {
    uint32_t                       numEvents;                               /**< @brief Input: Number of valid
                                                                                        events in the list */
    ETHSWT_PSFPPktDropEventMsgType events[ETHSWT_PSFP_MAX_EVENTS_PER_MSG];  /**< @brief Input: List of events */
} ETHSWT_PSFPEventsListMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPEventsListMsgType, 440UL, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Union encapsulating all messages for PSFP

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef union uETHSWT_PSFPMsgUnionType {
    uint32_t                                 data[ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE/4UL]; /**< @brief PSFP data */
    ETHSWT_PSFPAddStreamMsgType              addStream;             /**< @brief Add stream parameters */
    ETHSWT_PSFPGetStreamCfgMsgType           getStreamCfg;          /**< @brief Get stream configuration */
    ETHSWT_PSFPStreamHdlType                 removeStream;          /**< @brief Remove stream parameters */
    ETHSWT_PSFPAddStreamFilterMsgType        addStreamFilter;       /**< @brief Add stream filter parameters */
    ETHSWT_PSFPUpdateStreamFilterMsgType     updateStreamFilter;    /**< @brief Update stream filter parameters */
    ETHSWT_PSFPGetStreamFilterCfgMsgType     getStreamFilterCfg;    /**< @brief Get stream filter configuration */
    ETHSWT_PSFPStreamFilterHdlType           removeStreamFilter;    /**< @brief Remove stream filter parameters */
    ETHSWT_PSFPGetFrameCountersMsgType       getFrameCounters;      /**< @brief Get frame counters */
    ETHSWT_PSFPStreamFilterHdlType           clearFrameCounters;    /**< @brief Clear frame counters */
    ETHSWT_PSFPAddFlowMeterMsgType           addFlowMeter;         /**< @brief Add flow meter parameters */
    ETHSWT_PSFPUpdateFlowMeterMsgType        updateFlowMeter;       /**< @brief Update flow meter parameters */
    ETHSWT_PSFPGetFlowMeterCfgMsgType        getFlowMeterCfg;       /**< @brief Get flow meter configuration */
    ETHSWT_PSFPFlowMeterHdlType              removeFlowMeter;       /**< @brief Remove flow meter parameters */
    ETHSWT_PSFPFlowMeterDropAllFrmsMsgType   dropAllFlowMeterFrms;  /**< @brief Configure flow meter to drop all frames parameters */
    ETHSWT_PSFPAddGateMsgType                addGate;               /**< @brief Add gate parameters */
    ETHSWT_PSFPUpdateGateMsgType             updateGate;            /**< @brief Update gate parameters */
    ETHSWT_PSFPGetGateCfgMsgType             getGateCfg;            /**< @brief Get gate configuration */
    ETHSWT_PSFPGateHdlType                   removeGate;            /**< @brief Remove gate parameters */
    ETHSWT_PortMaskType                      setEnabledPorts;       /**< @brief Set enabled port mask parameters */
    ETHSWT_PSFPSetTuningOffsetMsgType        setTuningOffset;       /**< @brief Set tuning offset parameters */
    ETHSWT_PSFPStreamFilterHdlType           ackEvent;              /**< @brief Acknowledge event parameters */
    ETHSWT_PSFPGetStreamFilterStatusMsgType  getStreamFilterStatus; /**< @brief Get stream filter status parameters */
    ETHSWT_PSFPGetFlowMeterStatusMsgType     getFlowMeterStatus;    /**< @brief Get flow meter status parameters */
    ETHSWT_PSFPGetGateStatusMsgType          getGateStatus;         /**< @brief Get gate status parameters */
    ETHSWT_PSFPEventsListMsgType             eventNotification;     /**< @brief Event parameters */
    ETHSWT_PSFPGetHdlsForFilterMsgType       getHdlsForFilterInst;  /**< @brief Get handles for filter instance parameters */
} ETHSWT_PSFPMsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_PSFPMsgUnionType, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE, ETHSWT_PSFP_MAX_RPC_PAYLOAD_SIZE)

/**
    @brief Global configuration parameters
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPGlobalCfgType {
    ETHSWT_PortMaskType portEnableMask;       /**< @brief Enabled ports mask */
    uint32_t            tuningOffsetSecs;     /**< @brief Seconds part of the tuning
                                                          offset */
    uint32_t            tuningOffsetNanoSecs; /**< @brief Nanoseconds part of the tuning
                                                          offset */
    uint32_t            resv[8U];             /**< @brief Reserved @xsd rsvd */
} ETHSWT_PSFPGlobalCfgType;

/**
    @brief PSFP configuration parameters
    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_PSFPCfgType {
    uint32_t                         magicId;                                           /**< @brief Magic number 'PSFP'
                                                                                                    (checked for validity) */
    ETHSWT_PSFPGlobalCfgType         globalCfg;                                         /**< @brief Global configuration */
    ETHSWT_PSFPFlowMeterCfgType      meters[ETHSWT_PSFP_CFG_MAX_FLOW_METERS];           /**< @brief Flow meters */
    uint32_t                         numMeters;                                         /**< @brief Number of flow meters @xsd count:meters */
    ETHSWT_PSFPGateCfgType           gates[ETHSWT_PSFP_CFG_MAX_GATES];                  /**< @brief Gates @xsd minsize:1 */
    uint32_t                         numGates;                                          /**< @brief Number of gates @xsd count:gates */
    ETHSWT_PSFPStreamIdentityCfgType streams[ETHSWT_PSFP_CFG_MAX_STREAMS];              /**< @brief Stream identities @xsd minsize:1 */
    uint32_t                         numStreams;                                        /**< @brief Number of streams @xsd count:streams */
    ETHSWT_PSFPStreamFilterType      streamFilters[ETHSWT_PSFP_CFG_MAX_STREAM_FILTERS]; /**< @brief Stream Filter configuration @xsd minsize:1 */
    uint32_t                         numStreamFilters;                                  /**< @brief Number of stream filters @xsd count:streamFilters */
} ETHSWT_PSFPCfgType;

/**
    @brief Add a stream

    This API adds a stream identified by the parameters in #aCfg and returns a
    handle for it. Please note that the switch should be configured appropriately
    for the stream traffic to go through. For example, the VLAN which the stream
    is associated with should already have been programmed.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aCfg                Stream identity configuration
    @param[out]    aStreamHdl          Stream handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream added successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aCfg/aStreamHdl is NULL
    @retval  #BCM_ERR_NOMEM            No space for adding new streams
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPAddStream(BCM_HandleType                                aConnHdl,
                                    const ETHSWT_PSFPStreamIdentityCfgType *const aCfg,
                                    ETHSWT_PSFPStreamHdlType *const               aStreamHdl);

/**
    @brief Remove a stream

    This API removes the stream corresponding to the input #aStreamHdl. The user needs to ensure
    that there are no stream filters associated with this stream.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamHdl          Stream handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream removed successfully
    @retval  #BCM_ERR_NOT_FOUND        #aStreamHdl does not correspond to
                                       a known stream
    @retval  #BCM_ERR_NOPERM           Stream filters are still associated
                                       with the stream OR
                                       Removing a statically added stream
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPRemoveStream(BCM_HandleType           aConnHdl,
                                       ETHSWT_PSFPStreamHdlType aStreamHdl);

/**
    @brief Add a stream filter

    This API adds a stream filter instance at #aFilterInstId in the stream filter instance
    table and returns a handle for it. Any packets ingressing the switch matching the
    attributes of the input stream handle #aStreamHdl would be subject to the filter as per
    #aFilterCfg.
    If flow meter or gate based filtering is desired, the user is expected to configure those
    using the #ETHSWT_PSFPAddFlowMeter and #ETHSWT_PSFPAddGate APIs respectively before
    invoking this API.
    The typical use case would be to create a stream using #ETHSWT_PSFPAddStream prior to
    invoking this API though the user may provide #ETHSWT_PSFP_STREAMHDL_WILDCARD as the
    stream handle in case the filter needs to be associated with a wildcard stream (i.e.
    matching any stream)

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamHdl          Stream handle
    @param[in]     aFilterInstId       Stream filter instance identifier.
                                       Index to the Stream filter instance
                                       table. Expected range is from 0 to
                                       #ETHSWT_PSFP_MAX_STREAM_FILTERS-1
    @param[in]     aFilterCfg          Stream filter configuration
    @param[out]    aStreamFilterHdl    Stream filter handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream filter programmed successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aFilterCfg/aStreamFilterHdl is NULL OR
                                       #aFilterInstId is out of range
    @retval  #BCM_ERR_NOT_FOUND        #aStreamHdl does not correspond to any known stream
    @retval  #BCM_ERR_NOPERM           #aFilterInstId is already used/occupied
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPAddStreamFilter(BCM_HandleType                        aConnHdl,
                                          const ETHSWT_PSFPStreamHdlType        aStreamHdl,
                                          const uint32_t                        aFilterInstId,
                                          const ETHSWT_PSFPFilterCfgType *const aFilterCfg,
                                          ETHSWT_PSFPStreamFilterHdlType *const aStreamFilterHdl);

/**
    @brief Remove a PSFP stream filter

    This API removes an existing PSFP stream filter identified by #aStreamFilterHdl
    the new filter configuration in #aFilterCfg.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamFilterHdl    Stream filter handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream filter removed successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aStreamFilterHdl is invalid
    @retval  #BCM_ERR_NOPERM           Stream filter is added statically
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPRemoveStreamFilter(BCM_HandleType                        aConnHdl,
                                             ETHSWT_PSFPStreamFilterHdlType        aStreamFilterHdl);

/**
    @brief Update a PSFP stream filter

    This API updates an existing PSFP stream filter identified by #aStreamFilterHdl with
    the new filter configuration in #aFilterCfg.
    The same API may be used to disable filtering, re-enable filtering or
    to drop all packets on the stream.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamFilterHdl    Stream filter handle
    @param[in]     aFilterCfg          Stream filter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream filter updated successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aStreamFilterHdl is invalid OR
                                       #aFilterCfg is NULL OR
                                       meter/gate in input configuration is
                                       invalid
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPUpdateStreamFilter(BCM_HandleType                        aConnHdl,
                                             ETHSWT_PSFPStreamFilterHdlType        aStreamFilterHdl,
                                             const ETHSWT_PSFPFilterCfgType *const aFilterCfg);

/**
    @brief Get frame counters for a stream filter

    This API retrieves the frame counters for a stream filter

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamFilterHdl    Stream filter handle
    @param[out]    aCntrs              Frame counters

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Frame counters retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aStreamFilterHdl is invalid OR
                                       aCntrs is NULL
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetFrameCounters(BCM_HandleType                      aConnHdl,
                                           ETHSWT_PSFPStreamFilterHdlType      aStreamFilterHdl,
                                           ETHSWT_PSFPFrameCountersType *const aCntrs);

/**
    @brief Clear frame counters for a stream filter

    This API clears the frame counters for a stream filter

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamFilterHdl    Stream filter handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Frame counters cleared successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aStreamFilterHdl is invalid
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPClearFrameCounters(BCM_HandleType                      aConnHdl,
                                             ETHSWT_PSFPStreamFilterHdlType      aStreamFilterHdl);

/**
    @brief Add a flow meter

    This API adds a flow meter and returns its handle. One or more
    streams can be associated with this flow meter and it can be used to cap
    the rate and burstiness of incoming stream(s). For more information on the
    metering operation please refer to MEF (6.1, 10.2). The flow meter can also
    (optionally) be used to block the incoming stream(s) automatically in case a
    packet is marked as RED.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aCfg                Flow meter configuration
    @param[out]    aFlowMeterHdl       Flow meter handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter added successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aCfg is NULL OR
                                       #aFlowMeterHdl is NULL OR
    @retval  #BCM_ERR_NOMEM            All available flow meters are already used
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPAddFlowMeter(BCM_HandleType                     aConnHdl,
                                       ETHSWT_PSFPFlowMeterCfgType *const aCfg,
                                       ETHSWT_PSFPFlowMeterHdlType *const aFlowMeterHdl);

/**
    @brief Update an existing flow meter

    This API updates an existing flow meter and overwrites the previously
    programmed configuration. This may affect any existing associated stream(s).

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aFlowMeterHdl       Flow meter handle
    @param[in]     aCfg                Flow meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter updated successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aFlowMeterHdl is invalid OR
                                       #aCfg is NULL
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPUpdateFlowMeter(BCM_HandleType                     aConnHdl,
                                          ETHSWT_PSFPFlowMeterHdlType        aFlowMeterHdl,
                                          const ETHSWT_PSFPFlowMeterCfgType *const aCfg);

/**
    @brief Drop all frames on flow meter

    This API configures the "mark all frames red" parameter to enable/disable
    the feature to drop all packets on the flow meter. If multiple streams
    are associated with the flow meter, packets of all those streams would be
    affected. When the feature is disabled, the color of the packets would
    be determined on the basis of the incoming rate/burst (i.e. regular
    flow meter operation).

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aFlowMeterHdl       Flow meter handle
    @param[in]     aEnable             Flag indicating whether all frames are to
                                       be dropped (1) or not (0)

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter configured to drop all frames
                                       successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aFlowMeterHdl is invalid
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPFlowMeterDropAllFrames(BCM_HandleType              aConnHdl,
                                                 ETHSWT_PSFPFlowMeterHdlType aFlowMeterHdl,
                                                 uint32_t                    aEnable);

/**
    @brief Add a gate

    This API adds a gate with the input configuration and returns the
    gate handle. Gate based filtering is used to introduce time aware policing
    akin to time aware scheduling on the egress. For more details refer to
    IEEE 802.1Qbv-2017.
    Once the gate has been added, one or more streams may be associated it.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aCfg                Gate configuration
    @param[out]    aGateHdl            Gate handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Gate added successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aCfg is NULL OR
                                       #aGateHdl is NULL
    @retval  #BCM_ERR_NOMEM            All available gates are already used
    @retval  #BCM_ERR_CUSTOM           The maxOctets value provided in the gate
                                       configuration could not be supported in
                                       the hardware
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPAddGate(BCM_HandleType                      aConnHdl,
                                  const ETHSWT_PSFPGateCfgType *const aCfg,
                                  ETHSWT_PSFPGateHdlType       *const aGateHdl);

/**
    @brief Update an existing gate

    This API updates an an already added gate. This results in newer
    configuration overwriting the previous one. Since the gate operates in
    a cyclical fashion the newer configuration is loaded at a (potentially
    future) time aligned as per the input baseTime.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aGateHdl            Gate handle
    @param[in]     aCfg                Gate configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Gate updated successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aGateHdl is invalid OR
                                       aCfg is NULL
    @retval  #BCM_ERR_BUSY             A previously triggered configuration
                                       change is still pending
                                       Gate will be in this state from a successful
                                       gate config to one cycle time past the base time.
    @retval  #BCM_ERR_CUSTOM           The maxOctets value provided in the gate
                                       configuration could not be supported in
                                       the hardware
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPUpdateGate(BCM_HandleType                      aConnHdl,
                                     ETHSWT_PSFPGateHdlType              aGateHdl,
                                     const ETHSWT_PSFPGateCfgType *const aCfg);

/**
    @brief Set enabled ports

    This API sets the port(s) which are currently enabled for PSFP. No
    policing/filtering will be applied for any stream packets ingressing
    on ports which are disabled.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aPortMask           Enabled ports mask

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Enabled ports mask programmed successfully
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPSetEnabledPorts(BCM_HandleType      aConnHdl,
                                          ETHSWT_PortMaskType aPortMask);

/**
    @brief Set tuning offset

    This API sets the tuning offset. This is an offset added to the current
    Time of Day (TOD) before using it for any time comparisons (e.g. for
    gating/loading new gate control lists). The following table provides the
    maximum tuning offsets that can be configured for each platform:
    | Chip family | Max value of aSecs | Maxi value of aNanosecs |
    |:-----------:|:------------------:|:-----------------------:|
    |  bcm8957x   |        63          |       1073741823        |
    |  bcm8958x   |         0          |         65535           |

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aSecs               Seconds part of the tuning offset
    @param[in]     aNanosecs           Nanoseconds part of the tuning offset

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK            Tuning offset programmed successfully
    @retval  #BCM_ERR_UNKNOWN       Unknown Error
    @retval  #BCM_ERR_NOSUPPORT     Given offset is not supported by the
                                    platform

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPSetTuningOffset(BCM_HandleType aConnHdl,
                                          uint32_t       aSecs,
                                          uint32_t       aNanosecs);

/**
    @brief Acknowledge event on a stream filter

    This API acknowledges the event reported on a stream filter. This will re-enable
    the interrupts on the stream filter so that further packet drop events may be
    reported in the future. If the stream was blocked due to the event, invoking
    this API will also unblock it.
    When the packet of a stream filter causes blocking of a meter/gate it
    affects all other stream filters mapped to the same meter/gate. Similarly,
    removing the block using this API will affect the other associated stream filters.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamFilterHdl    Stream filter handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream filter event acknowledged
                                       successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aStreamFilterHdl is invalid
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPAckEvent(BCM_HandleType                  aConnHdl,
                                   ETHSWT_PSFPStreamFilterHdlType  aStreamFilterHdl);

/**
    @brief Get stream filter status

    This API retrieves the stream filter status

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamHdl          Stream handle
    @param[out]    aStatus             Stream status

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream filter status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aStreamFilterHdl is invalid OR
                                       #aStatus is NULL
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetStreamFilterStatus(BCM_HandleType                     aConnHdl,
                                                ETHSWT_PSFPStreamFilterHdlType     aStreamFilterHdl,
                                                ETHSWT_PSFPStreamFilterStatusType *const aStatus);

/**
    @brief Get flow meter status

    This API retrieves the flow meter status

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aFlowMeterHdl       Flow meter handle
    @param[out]    aStatus             Flow meter status

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aFlowMeterHdl is invalid OR
                                       #aStatus is NULL
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetFlowMeterStatus(BCM_HandleType                        aConnHdl,
                                             ETHSWT_PSFPFlowMeterHdlType           aFlowMeterHdl,
                                             ETHSWT_PSFPFlowMeterStatusType *const aStatus);

/**
    @brief Get gate status

    This API retrieves the gate status

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aGateHdl            Gate handle
    @param[out]    aStatus             Gate status

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Gate status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aGateHdl is invalid OR
                                       #aStatus is NULL
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetGateStatus(BCM_HandleType                   aConnHdl,
                                        ETHSWT_PSFPGateHdlType           aGateHdl,
                                        ETHSWT_PSFPGateStatusType *const aStatus);

/**
    @brief Remove gate

    This API removes a gate. The gate handle is no longer valid

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aGateHdl            Gate handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Gate removed successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aGateHdl is invalid
    @retval  #BCM_ERR_NOPERM           Stream filters are still associated
                                       with this gate
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPRemoveGate(BCM_HandleType                   aConnHdl,
                                     ETHSWT_PSFPGateHdlType           aGateHdl);

/**
    @brief Remove flow meter

    This API removes a flow meter. The flow meter handle is no longer valid

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aMeterHdl           Flow meter handle

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter removed successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aMeterHdl is invalid
    @retval  #BCM_ERR_NOPERM           Stream filters are still associated
                                       with this flow meter
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPRemoveFlowMeter(BCM_HandleType              aConnHdl,
                                          ETHSWT_PSFPFlowMeterHdlType aMeterHdl);


/**
    @brief Retrieve the associated handles for an input stream filter instance

    This API can be used to retrieve the stream filter, stream, gate and flow
    meter (if applicable) handles for an input stream filter instance. This is
    particularly useful when using the static configuration.

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aFilterInstId       Stream filter instance identifier
    @param[out]    aFilterHdl          Stream filter handle (populated if not NULL)
    @param[out]    aStreamHdl          Stream handle (populated if not NULL)
    @param[out]    aMeterHdl           Flow meter handle (populated if not NULL).
                                       #ETHSWT_PSFP_FLOWMETERHDL_INVALID is returned
                                       if the flow meter is not configured
    @param[out]    aGateHdl            Gate handle (populated if not NULL)

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Handles retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aFilterInstId is invalid (should be less than
                                       #ETHSWT_PSFP_MAX_STREAM_FILTERS)
    @retval  #BCM_ERR_NOT_FOUND        Stream filter corresponding to aFilterInstId is not
                                       added yet

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetHdlsForStreamFilterInst(BCM_HandleType                        aConnHdl,
                                                     uint32_t                              aFilterInstId,
                                                     ETHSWT_PSFPStreamFilterHdlType *const aFilterHdl,
                                                     ETHSWT_PSFPStreamHdlType *const       aStreamHdl,
                                                     ETHSWT_PSFPFlowMeterHdlType *const    aMeterHdl,
                                                     ETHSWT_PSFPGateHdlType *const         aGateHdl);


/**
    @brief Get Stream Configuration

    This API retrieves stream config for a stream handle

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl            Connection handle (from RPC_Connect)
    @param[in]     aStreamHdl          Stream handle
    @param[out]    aStreamConfig       Stream configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream Config retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aStreamConfig is NULL OR
                                       #aStreamHdl is invalid
    @retval  #BCM_ERR_NOT_FOUND        If aStreamHdl not found

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetStreamConfig(BCM_HandleType                           aConnHdl,
                                          const ETHSWT_PSFPStreamHdlType           aStreamHdl,
                                          ETHSWT_PSFPStreamIdentityCfgType *const  aStreamConfig);


/**
    @brief Get Gate Configuration

    This API retrieves gate config for a gate handle

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[in]     aGateHdl          Gate handle
    @param[out]    aGateConfig       Gate configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Gate Config retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aGateConfig is NULL OR
                                       #aGateHdl is invalid
    @retval  #BCM_ERR_NOT_FOUND        If aGateHdl not found
    @retval  #BCM_ERR_TIME_OUT         HW Access timed out
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetGateConfig(BCM_HandleType                       aConnHdl,
                                        const ETHSWT_PSFPGateHdlType         aGateHdl,
                                        ETHSWT_PSFPGateCfgType *const        aGateConfig);


/**
    @brief Get Flow Meter Configuration

    This API retrieves flow meter config for a flow meter handle

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[in]     aFlowMeterHdl     Flow meter handle
    @param[out]    aFlowMeterConfig  Flow meter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Flow meter Config retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aFlowMeterConfig is NULL OR
                                       #aFlowMeterHdl is invalid
    @retval  #BCM_ERR_NOT_FOUND        If aFlowMeterHdl not found
    @retval  #BCM_ERR_TIME_OUT         HW Access timed out
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetFlowMeterConfig(BCM_HandleType                         aConnHdl,
                                             const ETHSWT_PSFPFlowMeterHdlType      aFlowMeterHdl,
                                             ETHSWT_PSFPFlowMeterCfgType *const     aFlowMeterConfig);


/**
    @brief Get Stream Filter Configuration

    This API retrieves stream filter config for a stream filter handle

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aConnHdl          Connection handle (from RPC_Connect)
    @param[in]     aStreamFilterHdl  Stream filter handle
    @param[out]    aFilterConfig     Stream filter configuration

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Stream filter config retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aFilterConfig is NULL OR
                                       #aStreamFilterHdl is invalid
    @retval  #BCM_ERR_NOT_FOUND        If aStreamFilterHdl not found
    @retval  #BCM_ERR_TIME_OUT         HW Access timed out
    @retval  #BCM_ERR_UNKNOWN          Unknown Error

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_PSFPGetStreamFilterConfig(BCM_HandleType                         aConnHdl,
                                                const ETHSWT_PSFPStreamFilterHdlType   aStreamFilterHdl,
                                                ETHSWT_PSFPFilterCfgType *const        aFilterConfig);


#endif /* ETHSWT_ABSTRACT_PSFP_H */
/** @} */
