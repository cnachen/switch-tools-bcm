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
    @defgroup grp_inout_ipc_native_types Native types
    @ingroup grp_inout_ipc_overview

    @addtogroup grp_inout_ipc_native_types
    @{

    @file inout_ipc_native_types.h
    @brief IPC native types

    @version 0.1 Initial Version
*/

#ifndef INOUT_IPC_NATIVE_TYPES_H
#define INOUT_IPC_NATIVE_TYPES_H

#include <stdint.h>
#include <rpc_msg.h>

/**
    @name RPC IPC Common Architecture IDs
    @{
    @brief Architecture IDs for RPC IPC Common
*/
#define BRCM_SWARCH_IPC_MACRO                           (0x7200U)   /**< @brief #IPC_MSG_MAGIC             */
#define BRCM_SWARCH_IPC_ID_MACRO                        (0x7202U)   /**< @brief #IPC_ID_PING               */
#define BRCM_SWARCH_IPC_STREAM_HDL_TYPE                 (0x7203U)   /**< @brief #IPC_StreamHdlType         */
#define BRCM_SWARCH_IPC_RESPONSEMSG_TYPE                (0x7204U)   /**< @brief #IPC_ResponseMsgType       */
#define BRCM_SWARCH_IPC_SECURITY_MODE_TYPE              (0x7205U)   /**< @brief #IPC_SecurityModeType      */
#define BRCM_SWARCH_IPC_TARGET_VERSION_TYPE             (0x7206U)   /**< @brief #IPC_TargetVersionType     */
#define BRCM_SWARCH_IPC_MSG_ID_MACRO                    (0x7207U)   /**< @brief #IPC_MSG_ID                 */

#define BRCM_SWARCH_IPC_PING_TYPE                       (0x7210U)   /**< @brief #IPC_PingType              */
#define BRCM_SWARCH_IPC_IMGREQV1_TYPE                   (0x7211U)   /**< @brief #IPC_ImgReqV1Type          */
#define BRCM_SWARCH_IPC_IMGPARTREQV1_TYPE               (0x7212U)   /**< @brief #IPC_ImgPartReqV1Type      */
#define BRCM_SWARCH_IPC_IMGREQV2_TYPE                   (0x7213U)   /**< @brief #IPC_ImgReqV2Type          */
#define BRCM_SWARCH_IPC_DWNLDHDRV2_TYPE                 (0x7214U)   /**< @brief #IPC_DwnldHdrV2Type        */
#define BRCM_SWARCH_IPC_DWNLDIMAGE_TYPE                 (0x7215U)   /**< @brief #IPC_DwnldImageType        */
#define BRCM_SWARCH_IPC_DWNLDHDRV1_TYPE                 (0x7216U)   /**< @brief #IPC_DwnldHdrV1Type        */
#define BRCM_SWARCH_IPC_FILEREQ_TYPE                    (0x7217U)   /**< @brief #IPC_FileReqType            */

#define BRCM_SWARCH_IPC_PORT_TYPE                       (0x7220U)   /**< @brief #IPC_PortType           */
#define BRCM_SWARCH_IPC_CONNECT_STATS_TYPE              (0x7221U)   /**< @brief #IPC_ConnectStatsType   */
#define BRCM_SWARCH_IPC_CONNECT_MSG_TYPE                (0x7222U)   /**< @brief #IPC_ConnectMsgType     */

/** @} */

/**
    @name IPC Module macros
    @{
    @brief Design IDs for IPC Module

    @trace #BRCM_SWREQ_IPC
*/
#define IPC_MSG_MAGIC                   (0x4950434DUL) /**< @brief 'I''P''C''M' */
#define IPC_MSG_HDR_SIZE                (16UL)
#define IPC_MSG_MAX_SIZE                (496UL)
#define IPC_MSG_FILENAME_LEN            (127U)
#define IPC_STREAM_MAGIC                (0x49504353UL) /**< @brief 'I''P''C''S' */
#define IPC_STREAMDATA_PAYLOAD_SIZE     (384UL)        /**< @brief Max Stream payload length */
/** @} */

/**
    @name IPC ID macros
    @{
    @brief IMGL ID construction macro

    @trace #BRCM_SWREQ_IPC
*/
#define IPC_MSG_ID(x)       BCM_MSG(0U, 0U, (x))
#define IPC_MSG_ID_ASYNC(x) BCM_MSG_ASYNC(0U, 0U, (x))
/** @} */

/**
    @name IPC Module Message IDs
    @{
    @brief Message IDs for exchange on message queues and Target side services.

    These are used for interaction over MSGQ interface and IMGL commands.
    Hence, this must be within 8-bit space.

    @limitation These commands must be used only on target side (Not to be used from Host)

    @trace #BRCM_SWREQ_IPC
*/
#define IPC_ID_PING                IPC_MSG_ID(0x01U)  /**< @brief PING */
#define IPC_ID_DWNLD_IMG_HDR_V1    IPC_MSG_ID(0x02U)  /**< @brief Image Header */
#define IPC_ID_DWNLD_IMG_V1        IPC_MSG_ID(0x03U)  /**< @brief Image */
#define IPC_ID_DWNLD_IMG_HDR_V2    IPC_MSG_ID(0x04U)  /**< @brief Image Header - V2 */
#define IPC_ID_DWNLD_IMG_V2        IPC_MSG_ID(0x05U)  /**< @brief Image - V2 */
#define IPC_ID_IMAGE_FETCH_V1      IPC_MSG_ID_ASYNC(0x10U)  /**< @brief Fetch */
#define IPC_ID_IMAGE_PART_FETCH_V1 IPC_MSG_ID_ASYNC(0x11U)  /**< @brief Part Fetch */
#define IPC_ID_IMAGE_FETCH_V2      IPC_MSG_ID_ASYNC(0x12U)  /**< @brief Fetch - V2 */
#define IPC_ID_IMAGE_PART_FETCH_V2 IPC_MSG_ID_ASYNC(0x13U)  /**< @brief Part Fetch - V2 */
#define IPC_ID_IMAGE_FILE_FETCH_V2 IPC_MSG_ID_ASYNC(0x14U)  /**< @brief File Fetch - V2 */
#define IPC_ID_TABLE_FETCH_V1      IPC_MSG_ID_ASYNC(0x20U)  /**< @brief Fetch Image/Partition Table */
#define IPC_ID_DEBUG               IPC_MSG_ID_ASYNC(0x40U)  /**< @brief DEBUG    */
#define IPC_ID_CONNECT             IPC_MSG_ID(0xFCU)  /**< @brief #IPC_ConnectMsgType   */
#define IPC_ID_DISCONNECT          IPC_MSG_ID(0xFDU)  /**< @brief #IPC_ConnectMsgType   */
#define IPC_ID_KEEP_ALIVE          IPC_MSG_ID(0xFEU)  /**< @brief #IPC_ConnectMsgType   */
#define IPC_ID_DATA                IPC_MSG_ID(0xFFU)  /**< @brief This message ID uses RPC payload  */
/** @} */

/**
    @name Stream Handle Type
    @{
    @trace #BRCM_SWREQ_IPC
*/
typedef uint32_t IPC_StreamHdlType;
#define IPC_STREAM_HDL_INDEX_MASK       (0xFFUL)      /**< @brief Mask: Stream index of context       */
#define IPC_STREAM_HDL_INDEX_SHIFT      (0x0UL)       /**< @brief Index: Stream index of context      */
#define IPC_STREAM_HDL_COUNTER_MASK     (0xFFFFFFUL)  /**< @brief Mask: Running stream counter value  */
#define IPC_STREAM_HDL_COUNTER_SHIFT    (0x8UL)       /**< @brief Index: Running stream counter value */
/** @} */

/**
    @name Security Mode Type
    @{
    @brief MCU security modes

    @trace #BRCM_SWREQ_IPC
*/
typedef uint32_t IPC_SecurityModeType;     /**< @brief typedef for MCU Security mode */
#define IPC_SECURITY_MODE_UNKNOWN (0x0UL)  /**< @brief Unknown mode */
#define IPC_SECURITY_MODE_NONE    (0x1UL)  /**< @brief Unsecured */
#define IPC_SECURITY_MODE_ECC     (0x2UL)  /**< @brief Secured through ECC */
#define IPC_SECURITY_MODE_RSA     (0x3UL)  /**< @brief Secured through RSA */
#define IPC_SECURITY_MODE_MAX     (IPC_SECURITY_MODE_RSA) /**< @brief Maximum mode value supported */
/** @} */

/**
    @brief IPC legacy response structure

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_ResponseMsgType {
    int32_t              status;      /**< @brief Response error code */
    uint8_t              payload[sizeof(RPC_MsgType) - sizeof(int32_t)];
                                      /**< @brief Response payload */
} IPC_ResponseMsgType;
BCM_STATIC_SIZE_ASSERT(IPC_ResponseMsgType, 496UL, 496UL)

#pragma pack(push, 4)

/**
    @brief MCU version information structure

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_TargetVersionType {
    uint32_t manuf;     /**< @brief manufacturer ID */
    uint32_t model;     /**< @brief model number */
    uint32_t rev;       /**< @brief revision number */
    IPC_SecurityModeType securityMode; /**< @brief Security Mode */
} IPC_TargetVersionType;
BCM_STATIC_SIZE_ASSERT(IPC_TargetVersionType, 16UL, 16UL)

/**
    @brief RPC Ping Type

    @trace #BRCM_SWREQ_IPC
*/
typedef struct sIPC_PingType {
    uint32_t                mode;       /**< mode: Firmware/Bootloader */
    IPC_TargetVersionType   version;    /**< MCU version */
} IPC_PingType;
BCM_STATIC_SIZE_ASSERT(IPC_PingType, 20UL, 20UL)

/**
    @brief Image request identifying an image

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_ImgReqV1Type {
    uint8_t  isImgHdr;  /**< @brief set to TRUE if image is only entires and optional signature */
    uint8_t  pid;       /**< @brief Partition ID                                                */
    uint16_t imgID;     /**< @brief Image ID                                                    */
    uint32_t imgMaxSize;/**< @brief Image max size that can be downloaded                       */
} IPC_ImgReqV1Type;
BCM_STATIC_SIZE_ASSERT(IPC_ImgReqV1Type, 8UL, 8UL)

/**
    @brief Image request identifying an image

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_ImgPartReqV1Type {
    uint8_t  isImgHdr;  /**< @brief set to TRUE if image is only entires and optional signature */
    uint8_t  pid;       /**< @brief Partition ID                                                */
    uint16_t imgID;     /**< @brief Image ID                                                    */
    uint32_t imgMaxSize;/**< @brief Image max size that can be downloaded                       */
    uint32_t offset;    /**< @brief offset                                                      */
} IPC_ImgPartReqV1Type;
BCM_STATIC_SIZE_ASSERT(IPC_ImgPartReqV1Type, 12UL, 12UL)

/**
    @brief Image request identifying an image

    Used when sending an ASYNC message with IPC_ID_IMAGE_FETCH_V2 OR
    IPC_ID_IMAGE_PART_FETCH_V2 from IPC Slave to connected master

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_ImgReqV2Type {
    uint8_t           isTbl;          /**< @brief set to TRUE if image is only
                                           entires and optional signature */
    uint8_t           pid;            /**< @brief Partition ID */
    uint16_t          imgID;          /**< @brief Image ID */
    uint32_t          imgMaxSize;     /**< @brief Image max size that can
                                           be downloaded */
    uint32_t          targetStrmHdl;  /**< @brief Stream handle got from RPC MEM on the target device */
    uint32_t          offset;         /**< @brief offset is zero for full image fetch
                                           Valid offset to be specified for part image fetch */
} IPC_ImgReqV2Type;
BCM_STATIC_SIZE_ASSERT(IPC_ImgReqV2Type, 16UL, 16UL)


/**
    @brief RPC Download image header type

    Used by IPC Master to send the image header details only
    on the image request from the IPC slave

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_DwnldHdrV2Type {
    uint32_t          magicNum;      /**< @brief IMGL_IMGH_MAGIC */
    uint8_t           pid;           /**< @brief Partition ID */
    uint8_t           rsv;           /**< @brief Reserved */
    uint16_t          imgID;         /**< @brief Image ID */
    uint32_t          imgSize;       /**< @brief Size of the image */
    uint32_t          targetStrmHdl; /**< @brief Stream handle for target reference*/
    uint32_t          hostStrmHdl;   /**< @brief Stream handle for host reference */
    int32_t           response;      /**< @brief Response code from slave device */
} IPC_DwnldHdrV2Type;
BCM_STATIC_SIZE_ASSERT(IPC_DwnldHdrV2Type, 24UL, 24UL)

/**
    @brief RPC Download image header type- v1

    Used by IPC Master to send the image header details only
    on the image request from the IPC slave

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_DwnldHdrV1Type {
    uint32_t          magicNum;      /**< @brief IMGL_IMGH_MAGIC */
    uint32_t          imgSize;       /**< @brief Size of the image */
    uint32_t          flags;         /**< @brief #IMGL_ImgFlagsType */
    uint64_t          errDetCode;    /**< @brief Error detection code */
} IPC_DwnldHdrV1Type;
BCM_STATIC_SIZE_ASSERT(IPC_DwnldHdrV1Type, 20UL, 20UL)

/**
    @brief RPC Download image type

    Used to send one or more stream packets from IPC master to
    IPC slave to transfer the requested image

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_DwnldImageType {
    uint32_t          magicNum;      /**< @brief IPC_STREAM_MAGIC */
    uint8_t           pid;           /**< @brief Partition ID */
    uint8_t           rsv1;          /**< @brief Reserved */
    uint16_t          imgID;         /**< @brief Image ID */
    uint32_t          offset;        /**< @brief Offset of packet content in actual file */
    uint32_t          targetStrmHdl; /**< @brief Stream handle got from RPC MEM on the target device */
    uint32_t          hostStrmHdl;   /**< @brief Stream handle got from RPC MEM on the host device */
    uint32_t          len;           /**< @brief Length of stream data in payload - imgData */
    int32_t           response;      /**< @brief Response code from slave device */
    uint32_t          rsv2;          /**< @brief Reserved */
    uint8_t           imgData[IPC_STREAMDATA_PAYLOAD_SIZE];
                                     /**< @brief IMG data TODO : Macro usage for 384 */
} IPC_DwnldImageType;
BCM_STATIC_SIZE_ASSERT(IPC_DwnldImageType, 416UL, 416UL)
#pragma pack(pop)

/**
    @brief IPC Port type

    @trace #BRCM_SWREQ_IPC
*/
typedef uint16_t IPC_PortType;
#define IPC_PORT_INVALID    (0x0000U)   /**< @brief Invalid port    */
#define IPC_PORT_LEGACY     (0x8000U)   /**< @brief Special port for legacy mode*/
#define IPC_PORT_TEST       (0xFFFFU)   /**< @brief Test port. Not to be used   */

/**
    @brief IPC connection statistics

    This is information only, and must not be used for any decision making

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_ConnectStatsType {
    uint64_t    numActiveConn;  /**< @brief Number of active connections*/
    uint64_t    curControlPkts; /**< @brief Control packets sent in current connection  */
    uint64_t    curSentPkts;    /**< @brief Number of sent packets in current connection */
    uint64_t    curRcvdPkts;    /**< @brief Number of received packets in current connection */
    uint64_t    totalControlPkts;/**< @brief Total num ber of Control packets sent  */
    uint64_t    totalSentPkts;  /**< @brief Number of sent packets in current connection */
    uint64_t    totalRcvdPkts;  /**< @brief Number of received packets in current connection */
    uint64_t    numClosedConn;  /**< @brief Number of closed connections*/
    uint64_t    numRejectedConn;/**< @brief Number of closed connections*/
    uint8_t     reserved[24UL]; /**< @brief Reserved */
} IPC_ConnectStatsType;
BCM_STATIC_SIZE_ASSERT(IPC_ConnectStatsType, 96UL, 96UL)


/** @brief IPC connection message type.

    Port number must be between 0x8001-0xFFFE.
    0xFFFF is reserved for debug purposes and uses infinite timeout.

    A timeout is requested from Host/Master.
    Target/Slave responds with accepted timeout.

    @trace #BRCM_SWREQ_IPC
*/
typedef struct sIPC_ConnectMsgType {
    int32_t                 response;   /**< @brief Response code from slave #BCM_ERR_OK or #BCM_ERR_NACK        */
    IPC_PortType            activePort; /**< @brief Active connection port number.
                                                Host requests,.target responds with accepted connection*/
    IPC_PortType            failedPort; /**< @brief Failed connection port number   */
    uint16_t                timeoutMs;  /**< @brief Timeout in milliseconds.        */
    uint8_t                 reserved[22UL];
    IPC_ConnectStatsType    stats;
} IPC_ConnectMsgType;
BCM_STATIC_SIZE_ASSERT(IPC_ConnectMsgType, 128UL, 128UL)

/**
    @brief File request type

    Used when sending an ASYNC message with IPC_ID_IMAGE_FETCH_V2
    from IPC Module to connected master

    @trace #BRCM_SWREQ_IPC
 */
typedef struct sIPC_FileReqType {
    IPC_StreamHdlType targetStrmHdl;                  /**< @brief Stream handle on the target device */
    uint8_t           fileName[IPC_MSG_FILENAME_LEN]; /**< @brief File name to be fetched            */
} IPC_FileReqType;
BCM_STATIC_SIZE_ASSERT(IPC_FileReqType, 132UL, 132UL)

#endif /* INOUT_IPC_NATIVE_TYPES_H */
/** @} */
