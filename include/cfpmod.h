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
    @addtogroup grp_cfpmod
    @{

    @file cfpmod.h
    @brief CFP Module Header File.
    @version 0.1 Initial version
*/

#ifndef CFPMOD_H
#define CFPMOD_H

#include <module.h>
#include <ethernet_cfp_types.h>
#include <ethernet_common.h>

/**
    @name CFPMOD API IDs
    @{
    @brief API IDs for CFPMOD
 */
#define BRCM_SWARCH_CFPMOD_ADDRULE_PROC             (0x8101U) /**< @brief #CFPMOD_AddRule             */
#define BRCM_SWARCH_CFPMOD_REMOVERULE_PROC          (0x8102U) /**< @brief #CFPMOD_RemoveRule          */
#define BRCM_SWARCH_CFPMOD_GETRULE_PROC             (0x8103U) /**< @brief #CFPMOD_GetRule             */
#define BRCM_SWARCH_CFPMOD_ADDACLUDF_PROC           (0x8104U) /**< @brief #CFPMOD_AddACLUDF           */
#define BRCM_SWARCH_CFPMOD_ADDSTREAMUDF_PROC        (0x8105U) /**< @brief #CFPMOD_AddStreamUDF        */
#define BRCM_SWARCH_CFPMOD_ADDSTREAMRULE_PROC       (0x8106U) /**< @brief #CFPMOD_AddStreamRule       */
#define BRCM_SWARCH_CFPMOD_REMOVESTREAMRULE_PROC    (0x8107U) /**< @brief #CFPMOD_RemoveStreamRule    */
#define BRCM_SWARCH_CFPMOD_L3TOCFPKEY_PROC          (0x8108U) /**< @brief #CFPMOD_L3ToCFPKey          */
#define BRCM_SWARCH_CFPMOD_CFPKEYTOL3_PROC          (0x8109U) /**< @brief #CFPMOD_CFPKeyToL3          */
#define BRCM_SWARCH_CFPMOD_ISPSFPSUPPORTED_PROC     (0x810AU) /**< @brief #CFPMOD_IsPSFPSupported     */
#define BRCM_SWARCH_CFPMOD_INTERFACE_GLOBAL         (0x810BU) /**< @brief #CFPMOD_Interface           */
/** @} */

/** @brief Add a rule

    This routine adds a CFP rule

    @behavior Sync, Non-reentrant

    @pre none

    @param[inout] aRow               CFP row
    @param[in]    aSlice             CFP slice
    @param[in]    aKey               CFP key
    @param[in]    aAction            CFP action
    @param[in]    aMeter             CFP meter

    @retval  #BCM_ERR_OK               Rule added successfully
    @retval  #BCM_ERR_INVAL_PARAMS     #aKey/#aAction/#aRow/#aSlice is NULL OR
                                       #aRow or #aSlice is invalid value OR
                                       input UDF has not been configured OR
                                       aMeter is non NULL and aAction.flowMeterId is not CFP_METERID_INVALID
    @retVal  #BCM_ERR_NOT_FOUND        Input flow meter Id is not valid
    @retVal  #BCM_ERR_NOSUPPORT        Requested feature is not supported by
                                       this platform
    @retval  #BCM_ERR_NOMEM            All rows in TCAM are occupied
    @retval  #BCM_ERR_NOPERM           #aRow is occupied or #aRow+1 is not free (only for IPv6 long rule) or
                                       #aRow is not an even number (for IPv6 long rule) or
                                       #aSlice is not enabled for IPv6 chaining (for IPv6 long rule)
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFPMOD

    @limitations None
*/
int32_t CFPMOD_AddRule(CFP_RowType *const    aRow,
                       CFP_SliceType         aSlice,
                       CFP_KeyType *const    aKey,
                       CFP_ActionType *const aAction,
                       CFP_MeterType *const  aMeter);

/**
    @brief Remove a CFP rule

    This API removes a rule (if it exists).

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aRow                Row number

    @retval  #BCM_ERR_OK               Rule removed successfully
    @retval  #BCM_ERR_UNINIT           CFP has not been initialized
    @retval  #BCM_ERR_INVAL_PARAMS     #aRow is not valid or
                                       #aRow is not even (only for IPv6 chained rule)
    @retval  #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFPMOD

    @limitations None
*/
extern int32_t CFPMOD_RemoveRule(CFP_RowType aRow);

/**
    @brief Fetch CFP rule

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aRow                 Row number
    @param[out] aSlice               Slice number
    @param[out] aKey                 CFP key (optional if aAction is not NULL)
    @param[out] aAction              CFP action (optional if aKey is not NULL)
    @param[out] aMeter               CFP meter (optional)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK         Rule fetched successfully
    @retval     #BCM_ERR_UNKNOWN    Failure in fetching rule

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern int32_t CFPMOD_GetRule(CFP_RowType           aRow,
                              CFP_SliceType *const  aSlice,
                              CFP_KeyType *const    aKey,
                              CFP_ActionType *const aAction,
                              CFP_MeterType *const  aMeter);

/**
    @brief Add ACL UDFs

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aL3Framing           L3 framing
    @param[in]  aSlice               Slice
    @param[in]  aId                  UDF index
    @param[in]  aBase                UDF base
    @param[in]  aOffset              UDF offset

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK               UDF added successfully
    @retval     #BCM_ERR_INVAL_PARAMS     #aL3Framing/#aSlice/#aID/#aBase/#aOffset
                                          is invalid
    @retval     #BCM_ERR_NOPERM           #aSlice is disabled or
                                          #aSlice is not being managed by CFP
    @retVal     #BCM_ERR_NOSUPPORT        #aID is not valid for this slice. This
                                          could happen if we are accessing more than
                                          9 UDFs for a slice which is not enabled
                                          for chaining
    @retval     #BCM_ERR_TIME_OUT         Hardware access timed out

    @post None

    @trace #BRCM_SWREQ_CFPMOD
*/
extern int32_t CFPMOD_AddACLUDF(CFP_L3FramingType aL3Framing,
                                CFP_SliceType     aSlice,
                                uint32_t          aIndex,
                                CFP_UDFBaseType   aBase,
                                uint8_t           aOffset);

/**
    @brief Add a UDFs to the stream slice

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aL3Framing           L3 framing
    @param[in]  aId                  UDF index
    @param[in]  aBase                UDF base
    @param[in]  aOffset              UDF offset

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK         UDF added successfully
    @retval     #BCM_ERR_UNKNOWN    UDF addition failed

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern int32_t CFPMOD_AddStreamUDF(CFP_L3FramingType aL3Framing,
                                   uint32_t          aId,
                                   CFP_UDFBaseType   aBase,
                                   uint8_t           aOffset);

/**
    @brief Add a stream rule in the CFP TCAM

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aStreamFilterId      Stream filter identifier
    @param[in]  aKey                 CFP key

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK         Rule added successfully
    @retval     #BCM_ERR_UNKNOWN    Rule addition failed

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern int32_t CFPMOD_AddStreamRule(uint32_t           aStreamFilterId,
                                    CFP_KeyType *const aKey);

/**
    @brief Remove a stream rule from the CFP TCAM

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aStreamFilterId      Stream filter identifier

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK         Rule removed successfully
    @retval     #BCM_ERR_UNKNOWN    Rule removal failed

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern int32_t CFPMOD_RemoveStreamRule(uint32_t aStreamFilterId);

/**
    @brief Convert L3 params to CFP key

    NOTE: This API populates part of the CFP key which pertains to the L3
    parameters and the user is reponsible for initializing the rest of
    the key

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]  aSIP                Source IP address
    @param[in]  aDIP                Destination IP address
    @param[in]  aSPort              Source port
    @param[in]  aDPort              Destination port
    @param[in]  aProto              Protocol
    @param[in]  aDMac               Destination MAC address
    @param[out] aKey                CFP key

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern void CFPMOD_L3ToCFPKey(const ETHER_IpAddressType *const aSIP,
                              const ETHER_IpAddressType *const aDIP,
                              uint16_t                         aSPort,
                              uint16_t                         aDPort,
                              ETHER_L4ProtoType                aProto,
                              const uint8_t             *const aDMac,
                              CFP_KeyType               *const aKey);

/**
    @brief Convert CFP key to L3 params

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]   aKey                CFP key
    @param[in]   aSlice              Slice number
    @param[out]  aSIP                Source IP address
    @param[out]  aDIP                Destination IP address
    @param[out]  aSPort              Source port
    @param[out]  aDPort              Destination port
    @param[out]  aProto              Protocol
    @param[out]  aDMac               Destination MAC address

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern void CFPMOD_CFPKeyToL3(const CFP_KeyType   *const aKey,
                              CFP_SliceType              aSlice,
                              ETHER_IpAddressType *const aSIP,
                              ETHER_IpAddressType *const aDIP,
                              uint16_t            *const aSPort,
                              uint16_t            *const aDPort,
                              ETHER_L4ProtoType   *const aProto,
                              uint8_t             *const aDMac);

/**
    @brief Determine if PSFP can be supported

    @behavior Sync, Non-reentrant

    @pre None

    Return values are documented in reverse-chronological order
    @retval     #BCM_BOOL_TRUE      PSFP can be supported
    @retval     #BCM_BOOL_FALSE     PSFP cannot be supported

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern BCM_BoolType CFPMOD_IsPSFPSupported(void);

/**
    @brief Function pointer table for CFP module

    @trace #BRCM_SWREQ_CFPMOD
 */
extern const MODULE_Type CFPMOD_Interface;

#endif /* CFPMOD_H */
/** @} */
