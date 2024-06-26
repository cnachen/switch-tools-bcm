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
    @defgroup grp_aeadmod_cmd_ifc AEAD Send Receive command Interface
    @ingroup grp_aeadmod

    @addtogroup grp_aeadmod_cmd_ifc
    @{

    @limitations None

    @file aead_mod_cmd.h
    @brief AEAD Send Receive command Interface
    @version 0.1 Initial Version
*/
#ifndef CRYPTO_AEAD_CMD_H
#define CRYPTO_AEAD_CMD_H

/**
    @name AEAD send and recieve command architecture IDs
    @{
    @brief Architecture IDs for the functions to send and recieve the AEAD commands
*/
#define BRCM_SWARCH_CRYPTO_AEAD_SEND_CMD_PROC  (0x8201U) /**< @brief #CRYPTO_AeadSendCmd */
#define BRCM_SWARCH_CRYPTO_AEAD_GET_RESP_PROC  (0x8202U) /**< @brief #CRYPTO_AeadGetResp */
/** @} */

#include <crypto_aead.h>
#include <crypto_common.h>
#include <msg_queue.h>

/** @brief Send commands to AEAD module

    This API queues the crypto commands to crypto AEAD module

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aCmd                Command ID
    @param[in]      aLen                Length of the management command message
    @param[in]      aCmdData            Management command information
    @param[in]      aHandle             Pointer to BCM_HandleType for later query
    @param[out]     aForwardToSlaves    Is this message needed to be forwarded
                                        to slaves
    @param[in]      aTrusted            Boolean to indicate the trusted source
                                        TRUE - Trusted; FALSE - Non Trusted

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK         Command posted successfully

    @post None

    @trace #BRCM_SWREQ_CRYPTO
*/
int32_t CRYPTO_AeadSendCmd(BCM_MsgType aCmd, uint32_t aLen, const uint8_t *aCmdData,
                           BCM_HandleType *aHandle, uint32_t *aForwardToSlaves,
                           BCM_BoolType aTrusted);

/** @brief Retreive status of crypto AEAD commands

    This API queries the status of completed crypto AEAD commands which were
    previously issued

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aHandle                BCM Handle to retrieve response
    @param[in]   aReplyID               Reply ID (group, comp, cmd)
    @param[in]   aInLen                 Available Length of the reply data payload in bytes
    @param[out]  aReplyData             Pointer to the reply data payload
    @param[out]  aReplyDataLen          Actual Length of the reply data payload in bytes

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Command status retrieved successfully

    @post None

    @trace #BRCM_SWREQ_CRYPTO
*/
int32_t CRYPTO_AeadGetResp(BCM_HandleType aHandle, BCM_MsgType aReplyID, uint32_t aInLen,
                           uint8_t *aReplyData, uint32_t *aReplyDataLen, int32_t *aResponse,
                           uint32_t *aProgress);

#endif /* CRYPTO_AEAD_CMD_H */
/** @} */
