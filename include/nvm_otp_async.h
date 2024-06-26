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
    @defgroup grp_nvm_otp_async OTP Asynchronous Interface
    @ingroup grp_nvm_abstract_otp

    @defgroup grp_nvm_otp_async_ifc Interface
    @ingroup grp_nvm_otp_async

    @addtogroup grp_nvm_otp_async_ifc
    @{

    @limitations None

    @file nvm_otp_async.h
    @brief NVM OTP Asynchronous Interface
    This header file contains the interface functions for NVM OTP module message queue

    @version 1.0 Initial Version
*/

#ifndef NVM_OTP_ASYNC_H
#define NVM_OTP_ASYNC_H

#include <nvm_otp_types.h>

/**
    @name NVM OTP Architecture IDs
    @{
    @brief Architecture IDs for NVM OTP
*/
#define BRCM_SWARCH_OTP_MSG_UNION_TYPE                (0x8701U) /**< @brief #OTP_MsgUnionType          */
#define BRCM_SWARCH_OTP_MSG_TYPE                      (0x8702U) /**< @brief #OTP_MsgType               */
#define BRCM_SWARCH_OTP_READ_MAC_REQ_PROC             (0x8703U) /**< @brief #OTP_ReadMacReq            */
#define BRCM_SWARCH_OTP_WRITE_MAC_REQ_PROC            (0x8704U) /**< @brief #OTP_WriteMacReq           */
#define BRCM_SWARCH_OTP_READ_IP_CFG_REQ_PROC          (0x8705U) /**< @brief #OTP_ReadIPCfgReq          */
#define BRCM_SWARCH_OTP_WRITE_IP_CFG_REQ_PROC         (0x8706U) /**< @brief #OTP_WriteIPCfgReq         */
#define BRCM_SWARCH_OTP_READ_STACKING_INFO_REQ_PROC   (0x8707U) /**< @brief #OTP_ReadStackingInfoReq   */
#define BRCM_SWARCH_OTP_WRITE_STACKING_INFO_REQ_PROC  (0x8708U) /**< @brief #OTP_WriteStackingInfoReq  */
#define BRCM_SWARCH_OTP_READ_CUST_DATA_REQ_PROC       (0x8709U) /**< @brief #OTP_ReadCustDataReq       */
#define BRCM_SWARCH_OTP_WRITE_CUST_DATA_REQ_PROC      (0x870AU) /**< @brief #OTP_WriteCustDataReq      */
#define BRCM_SWARCH_OTP_GET_PROD_MODE_REQ_PROC        (0x870BU) /**< @brief #OTP_GetProdModeReq        */
#define BRCM_SWARCH_OTP_SET_PROD_MODE_REQ_PROC        (0x870CU) /**< @brief #OTP_SetProdModeReq        */
#define BRCM_SWARCH_OTP_GET_ACCESS_LOCK_REQ_PROC      (0x870DU) /**< @brief #OTP_GetAccessLockReq      */
#define BRCM_SWARCH_OTP_SET_ACCESS_LOCK_REQ_PROC      (0x870EU) /**< @brief #OTP_SetAccessLockReq      */
#define BRCM_SWARCH_OTP_GET_BOOT_MODE_REQ_PROC        (0x870FU) /**< @brief #OTP_GetBootModeReq        */
#define BRCM_SWARCH_OTP_DISABLE_BOOT_MODE_REQ_PROC    (0x8710U) /**< @brief #OTP_DisableBootModeReq    */
#define BRCM_SWARCH_OTP_GET_PATCH_VERSION_REQ_PROC    (0x8711U) /**< @brief #OTP_GetPatchVersionReq    */
#define BRCM_SWARCH_OTP_COMMIT_PATCH_REQ_PROC         (0x8712U) /**< @brief #OTP_CommitPatchReq        */
#define BRCM_SWARCH_OTP_GET_REQ_STATUS_PROC           (0x8713U) /**< @brief #OTP_GetReqStatus          */
/** @} */

/**
    @brief OTP Module Message Union

    @trace #BRCM_SWREQ_OTP
*/
typedef union uOTP_MsgUnionType {
    OTP_RawMsgType        readMsg;                          /**< @brief OTP read message             */
    OTP_RawMsgType        writeMsg;                         /**< @brief OTP write message            */
    OTP_MvkMsgType        mvkMsg;                           /**< @brief Public key message           */
    OTP_IpCfgMsgType      ipCfgMsg;                         /**< @brief IP Configuration message     */
    OTP_ProdMsgType       prodModeMsg;                      /**< @brief Production mode message      */
    OTP_AccessLockMsgType accessLockMsg;                    /**< @brief Access lock message          */
    OTP_BootModeMsgType   bootModeMsg;                      /**< @brief Boot mode message            */
    OTP_PatchVerMsgType   patchVerMsg;                      /**< @brief Patch version message        */
    OTP_DukMsgType        dukMsg;                           /**< @brief Device Unique Key message    */
    OTP_StackingInfoType  stackingInfo;                     /**< @brief Stacking information message */
    uint32_t              data[OTP_RPC_MAX_PAYLOAD_SIZE/4]; /**< @brief Data buffer                  */
} OTP_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(OTP_MsgUnionType, OTP_RPC_MAX_PAYLOAD_SIZE, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTP Module Message Type

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_MsgType {
    uint32_t             magic;          /**< @brief OTP Magic             */
    OTP_CmdIDType        cmd;            /**< @brief Command ID            */
    uint32_t             cmdLen;         /**< @brief Command length        */
    int32_t              status;         /**< @brief Message status        */
    OTP_MsgUnionType     u;              /**< @brief Message union         */
} OTP_MsgType;
BCM_STATIC_SIZE_ASSERT(OTP_MsgType, 304UL, 304UL)

/** @brief OTP Read MAC Request

    This API sends read MAC request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_ReadMacReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief OTP Write MAC Request

    This API sends write MAC request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status
    @param[in]      aMACBuf                Pointer to MAC address array

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL
    @retval     #BCM_ERR_INVAL_PARAMS      aMACBuf is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_WriteMacReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl, const uint8_t *const aMACBuf);

/** @brief OTP Read IP Configuration Request

    This API sends read IP configuration request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_ReadIPCfgReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief OTP Write IP Configuration Request

    This API sends write IP configuration request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status
    @param[in]      aIPCfg                 Pointer to IP configuration data

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL
    @retval     #BCM_ERR_INVAL_PARAMS      aIPCfg is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_WriteIPCfgReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl, const OTP_IpCfgMsgType* const aIPCfg);

/** @brief OTP Read Stacking Information Request

    This API sends read stacking information request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_ReadStackingInfoReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief OTP Write Stacking Information Request

    This API sends write stacking information request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status
    @param[in]      aStackingInfo          Pointer to stacking information data

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL
    @retval     #BCM_ERR_INVAL_PARAMS      aStackingInfo is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_WriteStackingInfoReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl, const OTP_StackingInfoType* const aStackingInfo);

/** @brief OTP Read Customer Data Request

    This API sends read customer data request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_ReadCustDataReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief OTP Write Customer Data Request

    This API sends write customer data request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status
    @param[in]      aCustData              Pointer to the customer data array
    @param[in]      aDataLen               No.of bytes in the customer data array

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL
    @retval     #BCM_ERR_INVAL_PARAMS      aCustData is NULL
    @retval     #BCM_ERR_INVAL_PARAMS      aDataLen is greater than #OTP_RAW_MAX_DATA_SIZE

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_WriteCustDataReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl, const uint8_t* const aCustData, const uint32_t aDataLen);

/** @brief OTP Get Production Mode Status Request

    This API sends get production mode status request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_GetProdModeReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief OTP Set Production Mode Status Request

    This API sends set production mode status request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_SetProdModeReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief OTP Get Access Lock Status Request

    This API sends get access lock status request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status
    @param[in]      aAccessLock            Interface ID to get access lock status #OTP_AccessModeType

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_GetAccessLockReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl, const OTP_AccessModeType aAccessLock);

/** @brief OTP Set Access Lock Status Request

    This API sends set access lock status request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status
    @param[in]      aAccessLock            Interface ID to set access lock status #OTP_AccessModeType

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_SetAccessLockReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl, const OTP_AccessModeType aAccessLock);

/** @brief OTP Get Boot Modes Status Request

    This API sends get boot modes status request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_GetBootModeReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief OTP Disable Boot Modes Request

    This API sends disable boot modes request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status
    @param[in]      aBootModes             Boot modes to be disabled

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_DisableBootModeReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl, const OTP_BootModeType aBootModes);

/** @brief OTP Get Patch Version Request

    This API sends get patch version request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_GetPatchVersionReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief OTP Commit Patch Version Request

    This API sends commit patch version request to NVM OTP module

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl               RPC connection handle (Dummy)
    @param[out]     aCmdHdl                Pointer to get the command handle to poll the status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command sent successfully
    @retval     #BCM_ERR_NOMEM             OTP module message queue is full
    @retval     #BCM_ERR_INVAL_PARAMS      Message length is greater than #OTP_RPC_MAX_PAYLOAD_SIZE
    @retval     #BCM_ERR_INVAL_PARAMS      aCmdHdl is NULL

    @post The message is posted into OTP module message queue

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_CommitPatchReq(BCM_HandleType aConnHdl, BCM_HandleType *aCmdHdl);

/** @brief Retreive status of OTP Async Request

    This API queries the status of completed NVM OTP commands which were
    previously issued

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aHandle                BCM Handle to retrieve response
    @param[out]  aReplyData             Pointer to the reply data payload

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                Command status retrieved successfully
    @retval     #BCM_ERR_BUSY              Command is in-progress
    @retval     #BCM_ERR_INVAL_PARAMS      aHandle is invalid

    @post None

    @trace #BRCM_SWREQ_OTP

    @limitations None
*/
int32_t OTP_GetReqStatus(BCM_HandleType aHandle, OTP_MsgUnionType *aReplyData);

#endif /* NVM_OTP_ASYNC_H */

/** @} */
