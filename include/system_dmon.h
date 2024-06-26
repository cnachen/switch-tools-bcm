/*****************************************************************************
 Copyright 2018-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_system_dmon_overview Device Monitor
    @ingroup grp_system_abstract

    @addtogroup grp_system_dmon_overview
    @{

    @limitations None

    @file system_dmon.h
    @brief System Device Monitor Interface
    This header file contains the interface functions for System Device Monitor Interface

    @version 1.0 Initial Version
*/


#ifndef SYSTEM_DMON_H
#define SYSTEM_DMON_H

#include <stdint.h>
#include <stdlib.h>
#include <bcm_comp.h>
#include <bcm_utils.h>
#include <system_dmon_types.h>

/**
    @name System Device Monitor Architecture IDs
    @{
    @brief Architecture IDs for System Device Monitor
*/
#define BRCM_SWARCH_DMON_READMEM_PROC                   (0x8200U)   /**< @brief #DMON_ReadMem           */
#define BRCM_SWARCH_DMON_WRITEMEM_PROC                  (0x8201U)   /**< @brief #DMON_WriteMem          */
#define BRCM_SWARCH_DMON_PING_PROC                      (0x8202U)   /**< @brief #DMON_Ping              */
#define BRCM_SWARCH_DMON_SYNC_PROC                      (0x8203U)   /**< @brief #DMON_Sync              */
#define BRCM_SWARCH_DMON_GETSWVERSION_PROC              (0x8204U)   /**< @brief #DMON_GetSwVersion      */
#define BRCM_SWARCH_DMON_GETHWVERSION_PROC              (0x8205U)   /**< @brief #DMON_GetHwVersion      */
#define BRCM_SWARCH_DMON_REBOOT_PROC                    (0x8206U)   /**< @brief #DMON_Reboot            */
#define BRCM_SWARCH_DMON_GETHEARTBEAT_COUNT_PROC        (0x8207U)   /**< @brief #DMON_GetHeartBeatCount */
#define BRCM_SWARCH_DMON_SYNC_WAIT_PROC                 (0x8208U)   /**< @brief #DMON_SyncWait          */
#define BRCM_SWARCH_DMON_DEEPSLEEP_PROC                 (0x8209U)   /**< @brief #DMON_DeepSleep         */
#define BRCM_SWARCH_DMON_STOP_PROC                      (0x820AU)   /**< @brief #DMON_Stop              */
/** @} */


/**
    @brief Read Data from  Memory

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aAddr           Address to be Read
    @param[in]      aWidth          Data Width
    @param[in]      aDeviceID       Device ID
    @param[out]     aData           Data read from Memory

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aData is NULL or
                                              aWidth is Invalid

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_ReadMem(BCM_HandleType aHdl,
                             uint32_t        aAddr,
                             uint32_t        aWidth,
                             DMON_DeviceType aDeviceID,
                             uint32_t        *aData);

/**
    @brief Write Data to  Memory

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aAddr           Address to be Read
    @param[in]      aWidth          Data Width
    @param[in]      aData           Data to write in Memory
    @param[in]      aDeviceID       Device ID

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aWidth is Invalid

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_WriteMem(BCM_HandleType aHdl,
                             uint32_t        aAddr,
                             uint32_t        aWidth,
                             DMON_DeviceType aDeviceID,
                             uint32_t        aData);

/**
    @brief Ping Message

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[out]     aPing           Ping Message

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aPing is NULL

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_Ping(BCM_HandleType aHdl,
                          DMON_PingMsgType *aPing);

/**
    @brief Sync Message

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[out]     aSync           Sync Message

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aSync is NULL

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_Sync(BCM_HandleType aHdl, DMON_SyncMsgType *aSync);

/**
    @brief Wait until device reaches aState

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aState          State of the device to wait for
    @param[out]     aSync           Sync Message

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aSync is NULL

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_SyncWait(BCM_HandleType aHdl, BCM_StateType aState,
                            DMON_SyncMsgType *aSync);

/**
    @brief Get Software Version

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[out]     aSwVersion      Software Version

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aSwVersion is NULL

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_GetSwVersion(BCM_HandleType aHdl,
                                  DMON_SwVersionMsgType *aSwVersion);

/**
    @brief Get Hardware version

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[out]     aHwVersion      Hardware Version

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aHwVersion is NULL

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_GetHwVersion(BCM_HandleType aHdl,
                                  DMON_HwVersionMsgType *aHwVersion);

/**
    @brief Reboot the Device

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_Reboot(BCM_HandleType aHdl);

/**
    @brief Get HeartBeat count

    Get the current time as a indication of heartbeat count
    It also fetches voltage and temperature

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[out]     aHeartBeat      HeartBeat response

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations None
*/
extern int32_t DMON_GetHeartBeatCount(BCM_HandleType aHdl, DMON_HeartBeatMsgType *aHeartBeat);

/**
    @brief Put the device in DeepSleep Mode

    This API initiates a transtition of all tc10 enabled transceivers to tc10
    sleep state and the remaining(except Port 8) to standby mode. Once the
    transceivers transition to expected state, the target responds back to host
    that the command has been accepted and then signals an external controller
    about its readiness to enter deep-sleep state. The external controller is
    expected to shutdown the power to the chip thereby putting it in Deep-Sleep

    A tc10 wake-up through on any of the tc10 enabled ports would signal the
    external chip to bring the chip out of deep-sleep.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Command accepted
    @retVal     #BCM_ERR_BUSY           Device is busy processing the previous DEEPSLEEP command
    @retval     #BCM_ERR_INVAL_PARAMS   aHdl is invalid
    @retval     #BCM_ERR_NOSUPPORT      Unsupported
    @retval     #BCM_ERR_UNKNOWN        Unknown error

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations This API not supported on BCM8910X and BCM8908X platforms
*/
extern int32_t DMON_DeepSleep(BCM_HandleType aHdl);

/**
    @brief Stop Device

    This API disables traffic on requested ports and brings them down.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[inOut]   aStopMsg        Pointer to message structure

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Command accepted
    @retval     #BCM_ERR_INVAL_PARAMS   aHdl is invalid
    @retval     #BCM_ERR_NOSUPPORT      Unsupported
    @retval     #BCM_ERR_UNKNOWN        Unknown error

    @post None

    @trace #BRCM_SWREQ_DMON

    @limitations This API not supported on BCM8910X and BCM8908X platforms
*/
extern int32_t DMON_Stop(BCM_HandleType aHdl, DMON_StopMsgType *aStopMsg);

#endif /* SYSTEM_DMON_H */
/** @} */
