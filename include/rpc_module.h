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

/** @defgroup grp_rpc_abstract_module_ifc RPC Abstract Module Interface
    @ingroup grp_rpc_abstract

    @addtogroup grp_rpc_abstract_module_ifc
    @{

    @file rpc_module.h
    @brief RPC Abstract Module Interface

    @version 1.0 Initial version
*/

#ifndef RPC_MODULE_H
#define RPC_MODULE_H

#include <module.h>
#include <rpc_types.h>

/**
    @name RPC Abstract Module Interface IDs
    @{
    @brief Integration Interface IDs for RPC Abstract Modules
*/
#define BRCM_SWARCH_RPC_SERVICE_GLOBAL      (0x8F00U) /**< @brief #RPC_Service      */
#define BRCM_SWARCH_DISPATCH_MODULE_GLOBAL  (0x8F01U) /**< @brief #DISPATCH_Module  */
#define BRCM_SWARCH_RPC_GETCFG_PROC         (0x8F02U) /**< @brief #RPC_GetCfg       */
/** @} */

/**
    @brief RPC Service
    @trace #BRCM_SWREQ_RPC
*/
extern const SERVICE_Type RPC_Service;

/**
    @brief RPC Module to be integrated to RPC service Task

    @trace #BRCM_SWREQ_DISPATCH
*/
extern const MODULE_Type DISPATCH_Module;

/**
    @brief Retrieve the RPC configuration

    @behavior Sync, Non-Rentrant

    @pre None

    @param[out]      aConfig            Pointer to the RPC configuration

    Return values are documented in reverse-chronological order
    @retval     BCM_ERR_OK              Configuration fetched successfully
    @retval     BCM_ERR_NOT_FOUND       No configuration could be fetched

    @post None

    @trace #BRCM_SWREQ_RPC

    @limitations None
*/
extern int32_t RPC_GetCfg(RPC_CfgType *aConfig);

#endif /* RPC_MODULE_H */
/** @} */
