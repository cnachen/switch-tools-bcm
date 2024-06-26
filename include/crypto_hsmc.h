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

 2. TO THE COMP_MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
    AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
    WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
    TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND ALL IMPLIED
    WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A
    PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS,
    QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION.
    YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR PERFORMANCE OF THE
    SOFTWARE.

 3. TO THE COMP_MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR ITS
    LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL, INDIRECT,
    OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY WAY RELATING TO
    YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS
    OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR U.S. $1, WHICHEVER
    IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING ANY FAILURE OF
    ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
******************************************************************************/
/**
    @defgroup grp_crypto_hsmc_ifc Crypto HSMC interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_hsmc_ifc
    @{

    @limitations None

    @file crypto_hsmc.h
    @brief Crypto HSMC Interface
    This header file contains the interface functions to control the HSM subsystem
    @version 0.1 Initial Version
*/

#ifndef CRYPTO_HSM_CTRL_H
#define CRYPTO_HSM_CTRL_H

#include <crypto_common.h>
#include <msg_queue.h>

/**
    @name Crypto HSMC Architecture IDs
    @{
    @brief Architecture IDs for Crypto HSMC
*/
#define BRCM_SWARCH_HSMC_ID_OF_MACRO   (0x8F01U) /**< @brief #HSMC_ID_OF   */
#define BRCM_SWARCH_HSMC_ID_TYPE       (0x8F02U) /**< @brief #HSMC_IDType  */
/** @} */

/**
    @brief Macro to Construct CmdID

    @trace #BRCM_SWREQ_HSMC_MODULE
*/
#define HSMC_ID_OF(aId) BCM_MSG(BCM_GROUPID_CRYPTO, BCM_HSMMOD_ID, aId)

/**
    @name HSMC Message IDs
    @{
    @brief Message IDs for exchange on message queues and Host

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_HSMC_MODULE
*/
typedef BCM_MsgType HSMC_IDType;            /**< @brief HSMC message ID Type          */
#define HSMC_ID_RPC     HSMC_ID_OF(0x1UL)   /**< @brief Command to initiate an RPC    */
#define HSMC_ID_LOAD_FW HSMC_ID_OF(0x2UL)   /**< @brief Command to load the HSM FW    */
/** @} */

#endif
/** @} */
