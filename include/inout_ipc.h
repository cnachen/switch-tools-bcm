/*****************************************************************************
 Copyright 2021-2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_inout_ipc_overview IPC
    @ingroup grp_inout

    @addtogroup grp_inout_ipc_overview
    @{

    @file inout_ipc.h
    @brief IPC Command/Responses for Host or for IMGL/Update

    @version 0.1 Initial Version
*/

#ifndef INOUT_IPC_H
#define INOUT_IPC_H

#include <stdint.h>
#include <rpc_msg.h>
#include <inout_ipc_native_types.h>
#include <bcm_utils.h>

/**
    @name IPC Architecture IDs
    @{
    @brief Architecture IDs for IPC
*/
#define BRCM_SWARCH_IPC_ID_TYPE                     (0x7100U)   /**< @brief #IPC_IDType                 */

#define BRCM_SWARCH_IPC_IMGL_READ_MSG_TYPE          (0x7101U)    /**< @brief #IPC_ReadImgMsgType        */
#define BRCM_SWARCH_IPC_FILE_READ_MSG_TYPE          (0x7102U)   /**< @brief #IPC_ReadFileMsgType        */
#define BRCM_SWARCH_IPC_MSG_UNION_TYPE              (0x7103U)   /**< @brief #IPC_MsgUnionType           */
#define BRCM_SWARCH_IPC_MSG_TYPE                    (0x7104U)   /**< @brief #IPC_MsgType                */
/** @} */

/**
    @name IPC Module Message IDs
    @{
    @brief Message IDs for exchange on message queues and Target side services.

    These are used for interaction over MSGQ interface and IMGL commands.
    Hence, this must be within 8-bit space.

    -# 0x00 -- 0x7F are reserved for streams
    -# 0x80 -- 0xEF are for commands from Host
    -# 0xF0 -- 0xFF are reserved for Local commands (from IMGL/Update)

    @limitation These commands must be used only on target side (Not to be used from Host)

    @trace #BRCM_SWREQ_IPC
*/
typedef BCM_MsgType IPC_IDType;     /**< @brief IPC message ID Type */
#define IPC_ID_EXECUTE          IPC_MSG_ID(0x80U)  /**< @brief Execute setup     */
#define IPC_ID_IMGL_HDR_REQ     IPC_MSG_ID(0x81U)  /**< @brief Get image headers */
#define IPC_ID_GET_ASYNC_MSG    IPC_MSG_ID(0x82U)  /**< @brief Get Async message */

#define IPC_ID_READ_ITBL        IPC_MSG_ID(0xF0U) /**< @brief Local command for ITBL Read  */
#define IPC_ID_READ_IMAGE       IPC_MSG_ID(0xF1U) /**< @brief Local command for Image Read */
#define IPC_ID_READ_FILE        IPC_MSG_ID(0xF2U) /**< @brief Local command for File Read  */
/** @} */


/**
    @brief IPC Module Read Image request

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_ReadImgMsgType {
    uint8_t     isImgHdr;    /**< @brief set to TRUE if image is only entires and optional signature */
    uint8_t     pid;         /**< @brief Partition ID                                                */
    uint16_t    imgID;       /**< @brief Image ID                                                    */
    uint32_t    imgMaxSize;  /**< @brief Image max size that can be downloaded                       */
    uint8_t    *imgAddress;  /**< @brief Address to which fetched data to be copied                  */
    uint32_t    filledSize;  /**< @brief Image filled size that is downloaded                        */
} IPC_ReadImgMsgType;

/**
    @brief IPC Module Read File Request

    @trace #BRCM_SWREQ_IPC
*/
typedef struct sIPC_ReadFileMsgType {
    uint32_t    fileSize;                           /**< @brief File size in bytes */
    uint8_t     fileName[IPC_MSG_FILENAME_LEN]; /**< @brief File name          */
} IPC_ReadFileMsgType;
BCM_STATIC_SIZE_ASSERT(IPC_ReadFileMsgType, 132UL, IPC_MSG_MAX_SIZE)

/**
    @brief IPC Module Union encapsulating all messages

    @trace #BRCM_SWREQ_IPC
*/
typedef union uIPC_MsgUnionType {
    uint32_t                data[IPC_MSG_MAX_SIZE/4UL]; /**< @brief Max data size           */
    IPC_ReadImgMsgType      readImg;                    /**< @brief Read image structure    */
    IPC_ReadFileMsgType     readFile;                   /**< @brief Read file structure     */
    IPC_DwnldHdrV2Type      dlHdrv2;                    /**< @brief Download image header   */
    IPC_DwnldHdrV1Type      dlHdrv1;                    /**< @brief Download image header   */
    IPC_DwnldImageType      dlImg;                      /**< @brief Download image date     */
    IPC_FileReqType         reqFile;                    /**< @brief Request a file stream   */
    IPC_ImgReqV2Type        reqImgv2;                   /**< @brief Request Image           */
    IPC_ImgPartReqV1Type    reqPartImg;                 /**< @brief Request partial image   */
    IPC_ConnectMsgType      connect;                    /**< @brief Connect related message */
    RPC_MsgType             msg;                        /**< @brief RPC Message structure   */
} IPC_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(IPC_MsgUnionType, IPC_MSG_MAX_SIZE, IPC_MSG_MAX_SIZE)

/**
    @brief Structure for posting request to IPC module

    @trace #BRCM_SWREQ_IPC
*/
typedef struct sIPC_MsgType {
    uint32_t            magic;  /**< @brief Magic             */
    BCM_MsgType         id;     /**< @brief Request ID        */
    int32_t             status; /**< @brief Status of request */
    uint32_t            len;    /**< @brief Length of payload */
    IPC_MsgUnionType    u;      /**< @brief Payload           */
} IPC_MsgType;
BCM_STATIC_SIZE_ASSERT(IPC_MsgType, 512UL, 512UL)

#endif /* INOUT_IPC_H */
/** @} */
