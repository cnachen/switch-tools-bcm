/*****************************************************************************
 Copyright 2021-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ethernet_abstract_time_ifc Ethernet Time Module Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_abstract_time_ifc
    @{

    @file ethernet_time.h

    @brief Ethernet Time Module Interface
    This file contains the interfaces for the Ethernet Time module

    @version 0.1 Initial version
*/

#ifndef ETTM_H
#define ETTM_H

#include <module.h>
#include <bcm_utils.h>

/**
    @name Ethernet Time Module IDs
    @{
    @brief Architecture API IDs for Ethernet Time module
*/
#define BRCM_SWARCH_ETTM_TIME_MAX_PAYLOAD_SIZE_MACRO   (0x8101U) /**< @brief #ETTM_TIME_MAX_PAYLOAD_SIZE  */
#define BRCM_SWARCH_ETTM_CMDID_TYPE                    (0x8102U) /**< @brief #ETTM_CmdIDType              */
#define BRCM_SWARCH_ETTM_HEARTBEAT_TYPE                (0x8103U) /**< @brief #ETTM_HeartBeatType          */
#define BRCM_SWARCH_ETTM_PAYLOAD_TYPE                  (0x8104U) /**< @brief #ETTM_PayloadType            */
#define BRCM_SWARCH_ETTM_ID_OF_MACRO                   (0x8105U) /**< @brief #ETTM_ID_OF                  */
#define BRCM_SWARCH_ETTM_PKTINFO_TYPE                  (0x8106U) /**< @brief #ETTM_PktInfoType            */
#define BRCM_SWARCH_ETTM_NOTIFYTS_TYPE                 (0x8107U) /**< @brief #ETTM_NotifyTSType           */
#define BRCM_SWARCH_ETTM_NOTIFYDATAUNION_TYPE          (0x8108U) /**< @brief #ETTM_NotifyDataUnionType    */
/** @} */

/**
    @brief Maximum size of PSFP payload

    @trace #BRCM_SWREQ_ETTM
*/
#define ETTM_TIME_MAX_PAYLOAD_SIZE     (40UL)

/**
    @brief Macro to Construct Ethernet switch Ext Commands

    @trace #BRCM_SWREQ_ETTM
*/
#define ETTM_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_ETT_ID, aId)

/**
    @name ETTM_CmdIDType
    @{
    @brief Command identifiers
    @trace #BRCM_SWREQ_ETTM
*/
typedef BCM_MsgType ETTM_CmdIDType;             /**< @brief typedef for ETHTIME command ids */
#define ETTM_CMDID_PREPARE_SYNC                 ETTM_ID_OF(0x1U)    /**< @brief Prepare Sync command */
#define ETTM_CMDID_PREPARE_HEARTBEAT_READ       ETTM_ID_OF(0x2U)    /**< @brief Prepare Heartbeat command */
#define ETTM_CMDID_HEARTBEAT_GET                ETTM_ID_OF(0x3U)    /**< @brief Heartbeat Get command */
#define ETTM_CMDID_TIMESYNC_ACK                 ETTM_ID_OF(0x4U)    /**< @brief Acknowledge Timesync command */
#define ETTM_CMDID_READY_FOR_TIMESYNC           ETTM_ID_OF(0x1U)    /**< @brief Timesync Ready Notification Command*/

#define ETTM_CMDID_NOTIFY_TIMESTAMP             ETTM_ID_OF(0x10U)   /**< @brief Notification ID to ETS for Timestamp*/
/** @} */

/**
    @brief Structure to maintain the HeartBeat values

    @trace #BRCM_SWREQ_ETTM
*/
typedef struct sETTM_HeartBeatType {
    uint64_t hb0;
    uint64_t hb1;
} ETTM_HeartBeatType;
BCM_STATIC_SIZE_ASSERT(ETTM_HeartBeatType, 16UL, ETTM_TIME_MAX_PAYLOAD_SIZE)

/**
    @brief Union of all possible structures used for RPC communication.

    @note Stop gap arrangement until RPC V2 is enabled on endpoint SDKs
    @trace #BRCM_SWREQ_ETTM
*/
typedef union uETTM_PayloadType {
    uint8_t            *u8Ptr;      /**< @brief Memory */
    const uint8_t      *u8ConstPtr; /**< @brief Const memory  */
    ETTM_HeartBeatType *heartBeat;  /**< @brief 1588 heartbeat */
} ETTM_PayloadType;

/**
    @brief ETTM_pktInfo type

    @trace #BRCM_SWREQ_ETTM
*/

typedef uint32_t ETTM_PktInfoType;             /**< @brief vlanId(12 bit)|reserve(7 bit)|rxTx(1 bit)|(pktType(4 bit)|domainNum(8 bit))*/
#define ETTM_PKTINFO_DOMAINNUM_MASK            (0xFFUL)        /* @brief Domain Number Mask for Timestamp Packet  */
#define ETTM_PKTINFO_DOMAINNUM_SHIFT           (0UL)           /* @brief Domain Number Shift for Timestamp Packet */
#define ETTM_PKTINFO_PKTTYPE_MASK              (0xF00UL)       /* @brief Packet Type Mask for Timestamp Packet    */
#define ETTM_PKTINFO_PKTTYPE_SHIFT             (8UL)           /* @brief Packet Type Shift for Timestamp Packet   */
#define ETTM_PKTINFO_RXTXTYPE_MASK             (0x1000UL)      /* @brief Rx or Tx Type Mask for Timestamp Packet  */
#define ETTM_PKTINFO_RXTXTYPE_SHIFT            (12UL)          /* @brief Rx or Tx Type Shift for Timestamp Packet */
#define ETTM_PKTINFO_VLANID_MASK               (0xFFF00000UL)   /* @brief VLAN Id Mask for Timestamp Packet        */
#define ETTM_PKTINFO_VLANID_SHIFT              (20UL)          /* @brief VLAN Id Shift for Timestamp Packet       */

#define ETTM_PKTINFO_SET_DOMAIN_NUM(var)       (((uint32_t)(var) << ETTM_PKTINFO_DOMAINNUM_SHIFT) & ETTM_PKTINFO_DOMAINNUM_MASK) /**< @brief Domain Num for Gptp Packet*/
#define ETTM_PKTINFO_SET_PKT_TYPE(var)         (((uint32_t)(var) << ETTM_PKTINFO_PKTTYPE_SHIFT) & ETTM_PKTINFO_PKTTYPE_MASK)     /**< @bief Type of Gptp Packet*/
#define ETTM_PKTINFO_SET_ISTX_TYPE(var)        (((uint32_t)(var) << ETTM_PKTINFO_RXTXTYPE_SHIFT) & ETTM_PKTINFO_RXTXTYPE_MASK)   /**< @brief 0:Rx, 1:Tx*/
#define ETTM_PKTINFO_SET_VLAN_ID(var)          (((uint32_t)(var) << ETTM_PKTINFO_VLANID_SHIFT) & ETTM_PKTINFO_VLANID_MASK)       /**< @brief VLAN Id*/

#define ETTM_PKTINFO_GET_DOMAINNUM(var)        (((uint32_t)(var) & ETTM_PKTINFO_DOMAINNUM_MASK) >> ETTM_PKTINFO_DOMAINNUM_SHIFT)
#define ETTM_PKTINFO_GET_PKT_TYPE(var)         (((uint32_t)(var) & ETTM_PKTINFO_PKTTYPE_MASK) >> ETTM_PKTINFO_PKTTYPE_SHIFT)
#define ETTM_PKTINFO_GET_ISTX_TYPE(var)        (((uint32_t)(var) & ETTM_PKTINFO_RXTXTYPE_MASK) >> ETTM_PKTINFO_RXTXTYPE_SHIFT)
#define ETTM_PKTINFO_GET_VLAN_ID(var)          (((uint32_t)(var) & ETTM_PKTINFO_VLANID_MASK) >> ETTM_PKTINFO_VLANID_SHIFT)


/**
    @brief Structure to Notify Timestamp to Client
    @trace #BRCM_SWREQ_ETTM
*/
typedef struct sETTM_NotifyTSType {
    uint16_t             port;
    uint16_t             seqId;
    ETTM_PktInfoType     pktInfo;
    uint32_t             freeTsNsec;
    uint32_t             domainTsNsec;
    uint64_t             freeTsSec;
    uint64_t             domainTsSec;
    uint16_t             freeTsValid;
    uint16_t             domainTsValid;
    uint32_t             reserve;
} ETTM_NotifyTSType;
BCM_STATIC_SIZE_ASSERT(ETTM_NotifyTSType, 40UL, ETTM_TIME_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to Notify Timestamp to Client
    @trace #BRCM_SWREQ_ETTM
*/
typedef union uETTM_NotifyDataUnionType {
    BCM_NotifyDataType          custData;                    /**< @brief custom data */
    ETTM_NotifyTSType           payload;                     /**< @brief TimeStamp custom data */
} ETTM_NotifyDataUnionType;

#endif /* ETTM_H */

/** @} */
