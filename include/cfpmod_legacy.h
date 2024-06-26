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

    @file cfpmod_legacy.h
    @brief CFP Legacy Handler Header File.
    @version 0.1 Initial version
*/

#ifndef CFPMOD_LEGACY_H
#define CFPMOD_LEGACY_H

#include <ethernet_swt_cfp.h>

/**
    @name CFPMOD API IDs
    @{
    @brief API IDs for CFPMOD
 */
#define BRCM_SWARCH_CFPMOD_LEGACYINIT_PROC       (0x8201U) /**< @brief #CFPMOD_LegacyInit */
#define BRCM_SWARCH_CFPMOD_LEGACYPROCESSCMD_PROC (0x8202U) /**< @brief #CFPMOD_LegacyProcessCmd  */
/** @} */

/**
    @brief Handle driver initialization for legacy configuration

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]   aPktLenCorr  Packet length correction
    @param[in]   aPortMask    Port mask

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK         Processing complete
    @retval     #BCM_ERR_BUSY       In progress

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern int32_t CFPMOD_LegacyInit(ETHSWT_CFPPktLenCorrType aPktLenCorr,
                                 uint16_t                 aPortMask);

/**
    @brief Process the CFP legacy command

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]    aCmd         Legacy command identifier
    @param[inout] aMsg         Legacy command payload
    @param[in]    aLen         Legacy command length
    @param[out]   aReplyLen    Legacy response length
    @param[out]   aIsCmdHndld  Boolean flag indicating whether the command was
                               handled (BCM_BOOL_TRUE) or not (BCM_BOOL_FALSE)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK         Processing complete
    @retval     #BCM_ERR_BUSY       In progress

    @post None

    @trace #BRCM_SWREQ_CFPMOD

*/
extern int32_t CFPMOD_LegacyProcessCmd(uint32_t                      aCmd,
                                       ETHSWT_CFPMsgUnionType *const aMsg,
                                       uint32_t                      aLen,
                                       uint32_t               *const aReplyLen,
                                       BCM_BoolType           *const aIsCmdHndld);

#endif /* CFPMOD_LEGACY_H */
/** @} */
