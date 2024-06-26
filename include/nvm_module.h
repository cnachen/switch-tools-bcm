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

/** @defgroup grp_nvm_abstract_module_ifc NVM Abstract Module Interface
    @ingroup grp_nvm_abstract

    @addtogroup grp_nvm_abstract_module_ifc
    @{

    @file nvm_module.h
    @brief NVM Abstract Module Interface

    @version 1.0 Initial version
*/

#ifndef NVM_MODULE_H
#define NVM_MODULE_H

#include <module.h>

/**
    @name NVM Abstract Module Interface IDs
    @{
    @brief Integration Interface IDs for NVM Abstract Modules
*/
#define BRCM_SWARCH_NVM_SERVICE_GLOBAL         (0x8101U) /**< @brief #NVM_Service      */
#define BRCM_SWARCH_FLASHM_MODULE_GLOBAL       (0x8103U) /**< @brief #FLASHM_Module    */
#define BRCM_SWARCH_UPDATE_MODULE_GLOBAL       (0x8104U) /**< @brief #UPDATE_Module    */
/** @} */

/**
    @brief NVM Service
    @trace #BRCM_SWREQ_NVM
*/
extern const SERVICE_Type NVM_Service;

/**
    @brief Structure for Flash module

    @trace #BRCM_SWREQ_FLASHM
 */
extern const MODULE_Type FLASHM_Module;

/**
    @brief Updater Module (to update current version of software in Flash Memory)

    This Module is dependent on #IMGL_Module and #RPC_Module.

    @trace #BRCM_SWREQ_UPDATE
*/
extern const MODULE_Type UPDATE_Module;

#endif /* NVM_MODULE_H */
/** @} */
