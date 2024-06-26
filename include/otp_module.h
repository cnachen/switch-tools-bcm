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
    @defgroup grp_otpm_ifc OTP Module Interface
    @ingroup grp_otpm

    @addtogroup grp_otpm_ifc
    @{

    @file opt_module.h

    @brief OTP Module Interface
    This file contains the interfaces for the OTP module

    @version 0.1 Initial version
*/

#ifndef OTP_MODULE_H
#define OTP_MODULE_H

#include <module.h>
#include <nvm_otp.h>

/**
    @name OTP Module IDs
    @{
    @brief Architecture API IDs for OTP module
*/
#define BRCM_SWARCH_OTPM_GET_PATCH_VERSION_MACRO  (0x8101U)    /**< @brief #OTPM_GET_PATCH_VERSION */
#define BRCM_SWARCH_OTPM_ALT_MEM_HDR_TYPE         (0x8102U)    /**< @brief #OTPM_AltMemHdrType     */
#define BRCM_SWARCH_OTPM_ACCESS_MODE_CFG_TYPE     (0x8103U)    /**< @brief #OTPM_AccessModeCfgType */
#define BRCM_SWARCH_OTPM_PATCH_DATA_TYPE          (0x8104U)    /**< @brief #OTPM_PatchDataType     */
#define BRCM_SWARCH_OTPM_PATCH_CFG_TYPE           (0x8105U)    /**< @brief #OTPM_PatchCfgType      */
#define BRCM_SWARCH_OTPM_GEN_PATCH_DATA_PROC      (0x8106U)    /**< @brief #OTPM_GenratePatchData  */
/** @} */

/**
    @brief OTP Get Patch Version MACRO

    @trace #BRCM_SWREQ_OTPM_MODULE
*/
#define OTPM_GET_PATCH_VERSION(aArch, aMajor, aMinor, aRel)   \
                                       (((aArch)  << 24UL) |   \
                                        ((aMajor) << 16UL) |    \
                                        ((aMinor) << 8UL)  |     \
                                        (aRel))

/**
    @brief OTP Alternate memory header

    Alternate config memory header format

    @trace #BRCM_SWREQ_OTPM_MODULE
*/
typedef struct sOTPM_AltMemHdrType {
    uint32_t magic;         /**< @brief Alternate memory magic #OTPM_ALT_MEM_MAGIC (OTPA) */
    uint32_t crc;           /**< @brief CRC of the config region */
    uint32_t reserved[2];   /**< @brief Reserved */
} OTPM_AltMemHdrType;

/**
    @brief Interface Access info type

    @trace #BRCM_SWREQ_OTPM_MODULE
*/
typedef struct sOTPM_AccessModeCfgType {
    uint32_t       addr;
    uint32_t       mask;
    uint32_t       shift;
    uint32_t       val;
    OTPM_AccessModeType mode;
} OTPM_AccessModeCfgType;

/**
    @brief Patch Data type

    @trace #BRCM_SWREQ_OTPM_MODULE
*/
typedef struct sOTPM_PatchDataType {
    uint32_t startAddr;
    uint32_t size;                  /**< @brief Rows Count */
    const uint32_t *data;
} OTPM_PatchDataType;

/**
    @brief Patch Cfg type

    @trace #BRCM_SWREQ_OTPM_MODULE
*/
typedef struct sOTPM_PatchCfgType {
    const OTPM_PatchDataType* patchList;
    uint32_t            patchListsize;
    uint32_t            version;
} OTPM_PatchCfgType;

/** @brief Generate Patch Data Patch based on aPatchVer

    @behavior Sync, None re-entrant

    @pre None

    @param[in]     aPatchVer   Patch version
    @param[out]    aPatchBuf   Buffer to hold OTP Patch Data
    @param[in]     aOrgData    Original OTP data in the patch region

    Return values are documented in reverse-chronological order

    @retval      #BCM_ERR_OK              Patch Data genrated succesfully upto #aPatchVer
    @retval      #BCM_ERR_NOT_FOUND       No patch found for #aPatchVer
    @retval      #BCM_ERR_UNKNOWN         Invalid OTP patch data

    @post None

    @trace #BRCM_SWREQ_OTPM_MODULE
*/
extern int32_t OTPM_GenratePatchData(uint32_t aPatchVer,
                                     uint32_t* aPatchBuf,
                                     uint32_t const *aOrgData);

#endif /* OTP_MODULE_H */

/** @} */
