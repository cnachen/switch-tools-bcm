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
    @defgroup grp_nif_napt_ifc NIF NAPT Interface
    @ingroup grp_nif

    @addtogroup grp_nif_napt_ifc
    @{
    @file nif_napt.h
    @brief NAPT APIs
    This file contains interface APIs for NAPT implemented in nif
    @version 0.1 Initial Version
*/

#ifndef NIF_NAPT_H
#define NIF_NAPT_H

#include <stddef.h>
#include <inttypes.h>
#include <bcm_err.h>
#include <ethernet.h>
#include <ethernet_l3fw.h>

/**
    @name NAPT Architecture IDs
    @{
    @brief Architecture IDs for NAPT in NIF
*/
#define BRCM_SWARCH_NIF_NAPT_PROCESS_PKT_PROC         (0x8B01U)    /**< @brief #NIF_NaptProcessPkt       */
#define BRCM_SWARCH_NIF_NAPT_MOD_DELETE_PROC          (0x8B02U)    /**< @brief #NIF_ModNaptDeleteEntry   */
#define BRCM_SWARCH_NIF_NAPT_MOD_ADD_ENTRY_PROC       (0x8B03U)    /**< @brief #NIF_ModNaptAddEntry      */
#define BRCM_SWARCH_NIF_NAPT_MOD_PROCESS_PKT_PROC     (0x8B04U)    /**< @brief #NIF_ModNaptProcessPkt    */
#define BRCM_SWARCH_NIF_NAPT_ENTRY_CTXT_TYPE          (0x8B05U)    /**< @brief #NIF_NaptEntryCtxType     */
#define BRCM_SWARCH_NIF_NAPT_MOD_GET_REMAPENTRY_PROC  (0x8B06U)    /**< @brief #NIF_ModNaptGetRemapEntry */
#define BRCM_SWARCH_NIF_NAPT_ENTRY_STATUS_TYPE        (0x8B07U)    /**< @brief #NIF_NAPTEntryStatusType  */
#define BRCM_SWARCH_NIF_CHKSUM_FOLD_32TO16_MACRO      (0x8B08U)    /**< @brief #NIF_CHKSUM_FOLD_32TO16   */
#define BRCM_SWARCH_NIF_NAPT_TTN_CHKSUM_MACRO         (0x8B09U)    /**< @brief #NIF_NAPT_TTN_CHKSUM      */
#define BRCM_SWARCH_NIF_NAPT_MOD_GET_ROUTESTAT_PROC   (0x8B0AU)    /**< @brief #NIF_ModNaptGetRouteStats */
#define BRCM_SWARCH_NIF_NAPT_ROUTE_STATS_TYPE         (0x8B0BU)    /**< @brief #NIF_NAPTRouteStatsType   */
#define BRCM_SWARCH_NIF_NAPT_GLOBAL_STATS_TYPE        (0x8B0CU)    /**< @brief #NIF_NaptGlobalStatsType  */
#define BRCM_SWARCH_NIF_NAPT_MOD_GET_STAT_PROC        (0x8B0DU)    /**< @brief #NIF_ModNaptGetStats      */
#define BRCM_SWARCH_NIF_NAPT_MAX_STRUC_SZ_MACRO       (0x8B0EU)    /**< @brief #NIF_NAPT_MAX_STRUC_SZ    */
/** @} */

/**
    @brief Maximum size of NAPT structs

    @trace #BRCM_SWREQ_NIF_NAPT
*/
#define NIF_NAPT_MAX_STRUC_SZ        (256UL)

/**
    @brief Macro to fold 32 bit temporary checksum to actual 16 bit

    @trace #BRCM_SWREQ_NIF_NAPT
*/
#define NIF_CHKSUM_FOLD_32TO16(chksum32)                                \
                chksum32 = (chksum32 >> 16UL) + (chksum32 & 0xFFFFUL);  \
                chksum32 = (chksum32 >> 16UL) + (chksum32 & 0xFFFFUL);  \

/**
    @brief Macro for TTN checksum value to be subtracted from original

    @trace #BRCM_SWREQ_NIF_NAPT
*/
#define NIF_NAPT_TTN_CHKSUM                   (0x0100U)

/**
    @name NIF_NAPTEntryStatusType
    @{
    @brief NIF NAPT entry status type

    @trace #BRCM_SWREQ_NIF_NAPT
*/
typedef uint16_t NIF_NAPTEntryStatusType;
#define NIF_NAPT_ENTRY_STATUS_INVALID         (0x0U)
#define NIF_NAPT_ENTRY_STATUS_VALID           (0x1U)
/** @} */

/** @brief NAPT Internal Statistics type

    @trace #BRCM_SWREQ_NIF_NAPT
*/
typedef struct sNIF_NAPTRouteStatsType {
    uint32_t hit;               /**< @brief Count of hits                       */
    uint32_t noRouteErr;        /**< @brief Route entry not valid               */
    uint32_t ttlErr;            /**< @brief TTL field being 0                   */
    uint32_t vlanErr;           /**< @brief Untagged packet, remap config error */
    uint32_t protocolErr;       /**< @brief Unknown protocol                    */
    uint32_t txErr;             /**< @brief Error in sending packet             */
    uint32_t noMemErr;          /**< @brief Tx buffer full                      */
    uint32_t reserved[3];
    uint64_t lastTimestamp;     /**< @brief Timestamp of the last packet hit    */
} NIF_NAPTRouteStatsType;
BCM_STATIC_SIZE_ASSERT(NIF_NAPTRouteStatsType, 48, NIF_NAPT_MAX_STRUC_SZ);

/**
    @brief Struct type to store global stats of NAPT

    Struct type to store overall stats accross entries

    @trace #BRCM_SWREQ_NIF_NAPT
 */
typedef struct sNIF_NaptGlobalStatsType {
    uint64_t lastTimestamp;     /**< @brief Timestamp of the last NAPT packet hit */
} NIF_NaptGlobalStatsType;
BCM_STATIC_SIZE_ASSERT(NIF_NaptGlobalStatsType, 8, NIF_NAPT_MAX_STRUC_SZ);

/**
    @brief Struct type to store NAPT entry table

    Struct type to store NAPT rules entry.

    @trace #BRCM_SWREQ_NIF_NAPT
 */
typedef struct sNIF_NaptEntryCtxType {
    L3FW_NAPTRemapDataType  remapData;       /**< @brief L3FW remap data            */
    L3FW_InterfaceCfgType   remapIfcCfg;     /**< @brief Replacement parameters     */
    L3FW_InterfaceIdType    matchIfc;        /**< @brief L3FW Match Interface ID    */
    NIF_NAPTEntryStatusType valid;           /**< @brief Entry validity status type */
    uint16_t                ipDeltaChksum;   /**< @brief IP header delta chksum     */
    uint16_t                protDeltaChksum; /**< @brief TCP/UDP delta chksum       */
    NIF_NAPTRouteStatsType  stats;           /**< @brief Stats data                 */
} NIF_NaptEntryCtxType;
BCM_STATIC_SIZE_ASSERT(NIF_NaptEntryCtxType, 104, NIF_NAPT_MAX_STRUC_SZ);

/** @brief Add new entry in NAPT rule table

    @behavior Sync, Non-reentrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[in]       aRouteEntry    Pointer to rule entry parameters
    @param[in]       aRemapIfcCfg   Pointer to ifc cfg structure
    @param[out]      aIdx           Pointer to index of entry in the table.
                                    Used for deletion and query.

    @retval          #BCM_ERR_OK              Successful
    @return          #BCM_ERR_INVAL_PARAMS    Invalid entry details
    @return          #BCM_ERR_NOMEM           No memory for new rule.
    @return          #BCM_ERR_NOPERM          Not allowed due to duplicate Entry.

    @post describe post condition (status after execution of the function)

    @trace #BRCM_SWREQ_NIF_CNTRLR
*/
extern int32_t NIF_ModNaptAddEntry(const L3FW_NAPTRouteCfgType *aRouteEntry,
                                   L3FW_InterfaceCfgType *aRemapIfcCfg,
                                   uint16_t *aIdx);

/** @brief Get remapping details of entry from NAPT table

    @behavior Sync, Non-reentrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[in]       aIdx          Index of entry in the table.
    @param[out]      aEntryCfg     NAPT rule data

    @retval          #BCM_ERR_OK              Successful
    @return          #BCM_ERR_INVAL_PARAMS    Invalid entry index

    @post describe post condition (status after execution of the function)

    @trace #BRCM_SWREQ_NIF_CNTRLR
*/
extern int32_t NIF_ModNaptGetRemapEntry(uint16_t aIdx, L3FW_NAPTRouteCfgType *aEntryCfg);

/** @brief Get stats of a napt route

    @behavior Sync, Non-reentrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[in]       aIdx          Index of entry in the table.
    @param[out]      aStats        Pointer to route status

    @retval          #BCM_ERR_OK              Successful
    @return          #BCM_ERR_INVAL_PARAMS    Invalid entry index

    @post describe post condition (status after execution of the function)

    @trace #BRCM_SWREQ_NIF_CNTRLR
*/
extern int32_t NIF_ModNaptGetRouteStats(uint16_t aIdx, L3FW_NAPTRouteStatsType *const aStats);

/** @brief Get overall stats of napt routes

    @behavior Sync, Non-reentrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[out]      aStats        Pointer to route status

    @retval          #BCM_ERR_OK              Successful
    @return          #BCM_ERR_INVAL_PARAMS    Invalid entry index

    @post describe post condition (status after execution of the function)

    @trace #BRCM_SWREQ_NIF_CNTRLR
*/
extern int32_t NIF_ModNaptGetStats(L3FW_NAPTRouteStatsType *const aStats);


/** @brief Delete entry in NAPT rule table

    @behavior Sync, Non-reentrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[in]      aIdx          Index of entry in the table. Used for deletion.

    @retval          #BCM_ERR_OK              Successful
    @return          #BCM_ERR_INVAL_PARAMS    Index out of range.
    @return          #BCM_ERR_NOT_FOUND       No valid entry at index
    @return          #BCM_ERR_NOPERM          Entry cannot be deleted

    @post describe post condition (status after execution of the function)

    @trace #BRCM_SWREQ_NIF_CNTRLR
*/
extern int32_t NIF_ModNaptDeleteEntry(uint16_t aIdx);

/** @brief Process incoming packet as per entry in NAPT rule table

    This API calls NIF_NaptProcessPkt internally. API is used within NIF.

    @behavior Sync, Non-reentrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[in]      aID           HW ID of controller
    @param[in]      aBuf          Pointer to Rx buffer
    @param[in]      aLen          Length of buffer
    @param[in]      aMgmtInfo     BRCM header (Management Info)
    @param[in]      aIsVlanTag    Flag for vlan tag

    @retval          #BCM_ERR_OK              Successful
    @return          #BCM_ERR_INVAL_PARAMS    Entry not found.

    @post describe post condition (status after execution of the function)

    @trace #BRCM_SWREQ_NIF_CNTRLR
*/
extern int32_t NIF_ModNaptProcessPkt(ETHER_HwIDType aID,
                                     const uint8_t *const aBuf,
                                     const uint32_t aLen,
                                     const uint32_t aMgmtInfo,
                                     uint8_t aIsVlanTag);

/** @brief Process incoming packet as per entry in NAPT rule table

    This API looks at CFP rule in mgmt info and if there is valid entry for CFP
    rule, it updates fields of packet and sends back to switch.

    @behavior Sync, Non-reentrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[in]      aNaptCfgTable Pointer to NAPT config table
    @param[in]      aID           HW ID of controller
    @param[in]      aBuf          Pointer to Rx buffer
    @param[in]      aLen          Length of buffer
    @param[in]      aMgmtInfo     BRCM header (Management Info)
    @param[in]      aIsVlanTag    Flag for vlan tag

    @retval          #BCM_ERR_OK              Successful
    @return          #BCM_ERR_INVAL_PARAMS    Entry not found.

    @post describe post condition (status after execution of the function)

    @trace #BRCM_SWREQ_NIF_NAPT
*/
extern int32_t NIF_NaptProcessPkt(NIF_NaptEntryCtxType *aNaptCfgTable,
                                  NIF_NaptGlobalStatsType *aGlobalStats,
                                  ETHER_HwIDType aID,
                                  const uint8_t *const aBuf,
                                  const uint32_t aLen,
                                  const uint32_t aMgmtInfo,
                                  uint8_t aIsVlanTag);

#endif /* NIF_NAPT_H */
/** @} */
