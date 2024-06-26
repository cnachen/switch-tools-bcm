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

#ifndef INSTALL_HELPER_H
#define INSTALL_HELPER_H

/**
    @brief Delay for a specified amount of time

    This API can be used to wait/sleep for aTime seconds

    @param[in]    aTime         Time in Seconds

    @retval  None

*/
extern void FLASHER_Wait(uint32_t aTime);

/**
    @brief User option to Full install

    This API can be used to read the user option to proceed to Full install or not

    @param[out]    aIsInstall         BCM_BOOL_TRUE:  Full Install
                                      BCM_BOOL_FALSE: Abort Full Install

    @retval  None

*/
extern void FLASHER_FullInstallOpt(BCM_BoolType *aIsInstall);

/**
    @brief User option to Rollback to old version

    This API can be used to read the user option to rollback to old version.
    If user wants rollback  then it will not sync the new version to copy1 and copy2.
    It just set the Boot config to boot from copy 1.
    User needs to explicitly sync and boot the newer version using host commands.

    @param[out]    aIsRollBack        BCM_BOOL_TRUE:  Full Install
                                      BCM_BOOL_FALSE: Abort Full Install

    @retval  None

*/
extern void FLASHER_SafeInstallRollbackOpt(BCM_BoolType *aIsRollBack);

/**
    @brief Install state handler

    This will install the image depends the board state.
    If board is in bad state then it will bring to good state and install.
    Depends on the user option it can set the board
    to boot from older copy or sync and boot from newer copy
    or exit by do nothing when running FW is not booted from flash.


    @param[in]    aSockName      Socket name
    @param[in]    aPort          Port number
    @param[in]    aIsSafeInstall BCM_BOOL_TRUE:  Safe Install
                                 BCM_BOOL_FALSE: Full Install
    @param[in]    aInstallMsg    Install command message

    @retval     #BCM_ERR_OK             Install is succesful
    @retval     #BCM_ERR_UNKNOWN        Install failed (due to missing images etc)
                                        Boot Copy Config update failed
    @retval     #BCM_ERR_AUTH_FAILED    Install failed due to authentication failure
    @retval     #BCM_ERR_BUSY           Busy processing
    @retval     #BCM_ERR_NOT_FOUND      Boot Copy Config not found
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid image received
                                        or aSockName is NULL

*/
extern int32_t FLASHER_InstallStateHandler(const uint8_t *aSockName,
                                              uint16_t aPort,
                                              BCM_BoolType aIsSafeInstall,
                                              UPDATE_InstallCfgMsgType *aInstallMsg);

/**
    @brief Get Required flash size

    This API returns the required memory size to install

    @param[in]    aPtbl          Pointer to PTBL
    @param[out]   aImageSize     Maximum required flash size

    @retval     #BCM_ERR_OK             valid size is returned
    @retval     #BCM_ERR_INVAL_PARAMS   aPtbl is NULL or
                                        aEraseSize is NULL

*/
extern int32_t FLASHER_GetImageMaxSize (const PTBL_Type *const aPtbl,
                                             uint32_t *const aImageSize);
#endif /* INSTALL_HELPER_H */

