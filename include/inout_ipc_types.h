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
    @defgroup grp_inout_ipcbus Bus
    @ingroup grp_inout_ipc_overview

    @addtogroup grp_inout_ipcbus
    @{

    @file inout_ipc_types.h
    @brief IPC Bus interface
    This header file contains IPC Bus interfaces
    @version 0.1 Initial Version
*/

#ifndef INOUT_IPC_TYPES_H
#define INOUT_IPC_TYPES_H

#include <bcm_comp.h>
#include <bcm_utils.h>

/**
    @name IO Abstract Module Interface Ids
    @{
    @brief Architecture IDs for IPC Bus interface
*/
#define BRCM_SWARCH_IPCBUS_READ_MEM_PROC                  (0x7300U)   /**< @brief #IPCBUS_ReadMem           */
#define BRCM_SWARCH_IPCBUS_WRITE_MEM_PROC                 (0x7301U)   /**< @brief #IPCBUS_WriteMem          */
#define BRCM_SWARCH_IPCBUS_MAX_PAYLOAD_SIZE_GLOBAL        (0x7302U)   /**< @brief #IPCBUS_MAX_PAYLOAD_SIZE */
#define BRCM_SWARCH_IPCBUS_ID_OF_MACRO                    (0x7303U)   /**< @brief #IPCBUS_ID_OF            */
#define BRCM_SWARCH_IPCBUS_CMD_ID_TYPE                    (0x7304U)   /**< @brief #IPCBUS_CmdIdType         */
#define BRCM_SWARCH_IPCBUS_MEM_ACCESS_MSG_TYPE            (0x7305U)   /**< @brief #IPCBUS_MemAccessMsgType  */
#define BRCM_SWARCH_IPCBUS_MSG_UNION_TYPE                 (0x7306U)   /**< @brief #IPCBUS_MsgUnionType      */
#define BRCM_SWARCH_IPCBUS_MSG_TYPE                       (0x7307U)   /**< @brief #IPCBUS_MsgType           */
#define BRCM_SWARCH_IPCBUS_ACCESSWIDTH_TYPE               (0x7308U)   /**< @brief #IPCBUS_AccessWidthType   */
#define BRCM_SWARCH_IPCBUS_DEVICE_TYPE                    (0x7309U)   /**< @brief #IPCBUS_DeviceType        */
/** @} */

/**
    @brief Maximum size of IPC Bus payload

    @trace #BRCM_SWREQ_IPCBUS
*/
#define IPCBUS_MAX_PAYLOAD_SIZE       (136UL)

/**
    @brief Macro to Construct IPC Bus CmdID

    @trace #BRCM_SWREQ_IPCBUS
*/
#define IPCBUS_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_IO, BCM_IPCMOD_ID, aId)

/**
    @name IPC Bus command IDs
    @{
    @brief Switch IPC Bus command IDs group

    @trace #BRCM_SWREQ_IPCBUS
*/
typedef BCM_MsgType IPCBUS_CmdIdType;                    /**< @brief IPC Bus command message Type         */
#define IPCBUS_CMD_ID_RAW_READ                IPCBUS_ID_OF(0x01U)  /**< @brief #IPCBUS_MemAccessMsgType         #IPCBUS_ReadMem     */
#define IPCBUS_CMD_ID_RAW_WRITE               IPCBUS_ID_OF(0x02U)  /**< @brief #IPCBUS_MemAccessMsgType         #IPCBUS_WriteMem    */
/** @} */

/**
    @name IPC Bus Access width type
    @{
    @brief Switch IPC Bus command IDs group
    @trace #BRCM_SWREQ_IPCBUS
*/
typedef uint8_t IPCBUS_AccessWidthType;                    /**< @brief IPC Bus access width Type   */
#define IPCBUS_ACCESSWIDTH_8                 ((1U << 0U))  /**< @brief #8-bit access    */
#define IPCBUS_ACCESSWIDTH_16                ((1U << 1U))  /**< @brief #16-bit access   */
#define IPCBUS_ACCESSWIDTH_32                ((1U << 2U))  /**< @brief #32-bit access   */
#define IPCBUS_ACCESSWIDTH_64                ((1U << 3U))  /**< @brief #64-bit access   */
/** @} */

/**
   @name Device Master Slave ID
    @{
    @brief Switch IPC Bus command IDs group
   @trace #BRCM_SWREQ_IPCBUS
 */
typedef uint32_t IPCBUS_DeviceType;
#define IPCBUS_DEVICE_MASTER          (0UL)  /**< @brief Device master mode */
#define IPCBUS_DEVICE_SLAVE_1         (1UL)  /**< @brief Device ID slave_1 mode */
#define IPCBUS_DEVICE_SLAVE_2         (2UL)  /**< @brief Device ID slave_2 mode */
/** @} */

/**
    @brief Memory Access Message

    @trace #BRCM_SWREQ_IPCBUS
*/
typedef struct sIPCBUS_MemAccessMsgType {
    uint32_t                addr;
    uint8_t                 deviceID;
    IPCBUS_AccessWidthType  width;
    uint8_t                 len;
    uint8_t                 rsvd;
    uint8_t                 data[128UL];
} IPCBUS_MemAccessMsgType;
BCM_STATIC_SIZE_ASSERT(IPCBUS_MemAccessMsgType, 136UL, IPCBUS_MAX_PAYLOAD_SIZE)


/**
    @brief IPC Bus Union encapsulating all messages

    @trace #BRCM_SWREQ_IPCBUS
*/
typedef union uIPCBUS_MsgUnionType {
    uint32_t                data[IPCBUS_MAX_PAYLOAD_SIZE/4UL];
    IPCBUS_MemAccessMsgType   memAccess;
} IPCBUS_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(IPCBUS_MsgUnionType, IPCBUS_MAX_PAYLOAD_SIZE, IPCBUS_MAX_PAYLOAD_SIZE)

/**
    @brief IPC Bus Message Structure

    @trace #BRCM_SWREQ_IPCBUS
*/
typedef struct sIPCBUS_MsgType {
    uint32_t                    magic;
    BCM_MsgType                 id;
    int32_t                     status;
    uint32_t                    len;
    IPCBUS_MsgUnionType           u;
} IPCBUS_MsgType;
BCM_STATIC_SIZE_ASSERT(IPCBUS_MsgType, 152UL, 152UL)

/**
    @brief Read Data from Memory

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aAddr           Address to be Read
    @param[in]      aWidth          Data Width
    @param[in]      aDeviceId       Device ID
    @param[out]     aData           Data read from Memory

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aData is NULL or
                                              aWidth is Invalid

    @post None

    @trace #BRCM_SWREQ_IPCBUS

    @limitations None
*/
extern int32_t IPCBUS_ReadMem(const BCM_HandleType aHdl,
                              const uint32_t      aAddr,
                              const uint32_t      aWidth,
                              const uint32_t      aDeviceId,
                              uint32_t *const     aData);

/**
    @brief Write Data to Memory

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aAddr           Address to be Read
    @param[in]      aWidth          Data Width
    @param[in]      aData           Data to write in Memory
    @param[in]      aDeviceId       Device ID

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK               Success
    @retval         #BCM_ERR_INVAL_PARAMS     aWidth is Invalid

    @post None

    @trace #BRCM_SWREQ_IPCBUS

    @limitations None
*/
extern int32_t IPCBUS_WriteMem(const BCM_HandleType aHdl,
                               const uint32_t        aAddr,
                               const uint32_t        aWidth,
                               const uint32_t        aDeviceId,
                               const uint32_t        aData);

#endif /* INOUT_IPC_TYPES_H */
/** @} */