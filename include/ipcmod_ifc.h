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
    @addtogroup grp_ipcmod_ifc
    @{

    @file ipcmod_ifc.h
    @brief IPC interface

    @version 0.1 Initial version
*/
#ifndef IPCMOD_IFC_H
#define IPCMOD_IFC_H

#include <inout_ipc.h>
#include <inout_ipc_types.h>

/**
    @name IPC Module Integration Interface IDs
    @{
    @brief Integration Interface IDs for IPC module

*/
#define BRCM_SWARCH_IPCMOD_IFC_INIT_PROC                (0x8100U)   /**< @brief #IPCMOD_IfcInit     */
#define BRCM_SWARCH_IPCMOD_IFC_SEND_PROC                (0x8101U)   /**< @brief #IPCMOD_IfcSend     */
#define BRCM_SWARCH_IPCMOD_IFC_RECEIVE_PROC             (0x8102U)   /**< @brief #IPCMOD_IfcReceive  */
#define BRCM_SWARCH_IPCMOD_IFC_DEINIT_PROC              (0x8103U)   /**< @brief #IPCMOD_IfcDeInit   */
#define BRCM_SWARCH_IPCMOD_IFC_NOTIF_COUNTER_INC_PROC   (0x8104U)   /**< @brief #IPCMOD_IfcNotifCounterInc */
#define BRCM_SWARCH_IPCMOD_IFC_NOTIF_GET_PROC           (0x8105U)   /**< @brief #IPCMOD_IfcNotifGet */
#define BRCM_SWARCH_IPCMOD_IFC_READ_PROC                (0x8107U)   /**< @brief #IPCMOD_IfcRead     */
#define BRCM_SWARCH_IPCMOD_IFC_WRITE_PROC               (0x8108U)   /**< @brief #IPCMOD_IfcWrite    */
#define BRCM_SWARCH_IPCMOD_IFC_EVENT_HANDLER_PROC       (0x8109U)   /**< @brief #IPCMOD_IfcEventHandler */

/** @} */

/** @brief Initialize IPC intrface

    This API initializes and configures IPC interface.

    @behavior Sync, Non-reentrant

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_BUSY           In progress, invoke on event again
    @retval     #BCM_ERR_UNKNOWN        Integration fault

    @post If successfully initialized, the IPC driver shall move to INIT state

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern int32_t IPCMOD_IfcInit();

/** @brief Read a register or memory

    This API reads a register

    @behavior Sync, Non-reentrant

    @param[in]      aMsg        Pointer to message

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_BUSY           In progress, invoke on event again
    @retval     #BCM_ERR_NOSUPPORT      Not supported
    @retval     #BCM_ERR_INVAL_PARAMS   aMsg is NULL

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern int32_t IPCMOD_IfcRead(IPCBUS_MsgType *aMsg);

/** @brief Write a register or memory

    This API writes a register or memory

    @behavior Sync, Non-reentrant

    @param[in]      aMsg        Pointer to message

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_BUSY           In progress, invoke on event again
    @retval     #BCM_ERR_NOSUPPORT      Not supported
    @retval     #BCM_ERR_INVAL_PARAMS   aMsg is NULL

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern int32_t IPCMOD_IfcWrite(IPCBUS_MsgType *aMsg);

/** @brief Send IPC message

    This API sends a message through IPC Bus.

    @behavior Sync, Non-reentrant

    @param[in]      aMsg        Pointer to message

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_BUSY           In progress, invoke on event again
    @retval     #BCM_ERR_NOMEM          No slots available to send the message
    @retval     #BCM_ERR_NODEV          Target is not available (may be undergoing a reboot)
    @retval     #BCM_ERR_INVAL_PARAMS   aMsg->len is out of range
    @retval     #BCM_ERR_INVAL_PARAMS   aMsg is NULL

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern int32_t IPCMOD_IfcSend(IPC_MsgType *aMsg);

/** @brief Receive message

    This API retrieves a message obtained through IPC

    @behavior Sync, Non-reentrant

    @param[out]     aMsg        Pointer to message buffer

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_BUSY           In progress, Invoke on event again (partially written)
    @retval     #BCM_ERR_NOT_FOUND      No new message found
    @retval     #BCM_ERR_UNINIT         IPC is not yet initialized
    @retval     #BCM_ERR_INVAL_PARAMS   aMsg is NULL

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern int32_t IPCMOD_IfcReceive(IPC_MsgType *aMsg);

/** @brief Handle bus events

    @behavior Sync, Non-reentrant

    @param[in]   aHdl           Message ID
    @param[in]   aTimeStamp     Timestamp
    @param[in]   aCustomData    Message specific data

    @return void

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern void IPCMOD_IfcEventHandler(BCM_MsgType aHdl, uint64_t aTimeStamp,
                                      BCM_NotifyDataType const *aCustomData);

/** @brief Increment the notification counter

    This API used to increment the notification counter

    @behavior Sync, Non-reentrant

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern void IPCMOD_IfcNotifCounterInc();

/** @brief Get critical notifications

    This API retrieves if there are any critical notifications obtained through IPC

    @behavior Sync, Non-reentrant

    @param[out]     isCricNotifAvail        Pointer if any new critical notification is available

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   Input argument is NULL

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern int32_t IPCMOD_IfcNotifGet(uint32_t *isCritNotifAvail);

/** @brief De-initialize IPC driver

    This API deinitializes IPC driver.

    @behavior Sync, Non-reentrant

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_BUSY           In progress, invoke on event again
    @retval     #BCM_ERR_UNKNOWN        Integration fault

    @post If successfully de-initialized, the IPC driver shall move to UNINIT state

    @trace #BRCM_SWREQ_IPCMOD

    @limitations None
*/
extern int32_t IPCMOD_IfcDeInit(void);

#endif /* IPCMOD_IFC_H */
/** @} */
