/*****************************************************************************
 Copyright 2022-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ethernet_tftp_ifc Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_tftp_ifc
    @{

    @file ethernet_tftp.h
    @brief Ethernet TFTP Interface

    @version 1.0 Initial Version
*/


#ifndef ETHERNET_TFTP_H
#define ETHERNET_TFTP_H

#include <system_imgl_interface.h>

/**
    @name Ethernet TFTP Architecture IDs
    @{
    @brief Architecture IDs for Ethernet TFTP
*/
#define BRCM_SWARCH_TFTP_MAX_PAYLOAD_SIZE_MACRO   (0x8001U) /**< @brief #TFTP_MAX_PAYLOAD_SIZE  */
#define BRCM_SWARCH_TFTP_MACRO                    (0x8002U) /**< @brief #TFTP_MAGIC             */
#define BRCM_SWARCH_TFTP_ID_MACRO                 (0x8003U) /**< @brief #TFTP_ID                */
#define BRCM_SWARCH_TFTP_ID_TYPE                  (0x8004U) /**< @brief #TFTP_IDType            */
#define BRCM_SWARCH_TFTP_IMGL_READ_MSG_TYPE       (0x8005U) /**< @brief #TFTP_ReadImgMsgType    */
#define BRCM_SWARCH_TFTP_FILE_READ_MSG_TYPE       (0x8006U) /**< @brief #TFTP_ReadFileMsgType   */

#define BRCM_SWARCH_TFTP_MSG_UNION_TYPE           (0x8010U) /**< @brief #TFTP_MsgUnionType      */
#define BRCM_SWARCH_TFTP_MSG_TYPE                 (0x8011U) /**< @brief #TFTP_MsgType           */

#define BRCM_SWARCH_TFTP_IMGL_INTERFACE_GLOBAL    (0x8020U) /**< @brief #TFTP_ImglInterface     */
/** @} */


/**
    @brief Maximum size of TFTP command payload in bytes

    @trace #BRCM_SWREQ_TFTP
*/
#define TFTP_MAX_PAYLOAD_SIZE   (136UL)

/**
    @name TFTP macros
    @{
    @brief Design IDs for TFTP Module

    @trace #BRCM_SWREQ_TFTP
*/
#define TFTP_MAGIC              (0UL)
#define TFTP_MAX_FILENAME_LEN   (127U)
/** @} */

/**
    @brief IMGL ID construction macro

    @trace #BRCM_SWREQ_TFTP
*/
#define TFTP_ID(x) BCM_MSG(BCM_GROUPID_ETHSRV, BCM_TFT_ID, (x))

/**
    @name TFTP Message IDs
    @{
    @brief Message IDs for exchange on message queues and Target side services.

    These are used for interaction over MSGQ interface and IMGL commands.
    Hence, this must be within 8-bit space.

    @limitation These commands must be used only on target side (Not to be used from Host)

    @trace #BRCM_SWREQ_TFTP
*/
typedef BCM_MsgType TFTP_IDType;     /**< @brief IMGL message ID Type */
#define TFTP_ID_READ_ITBL          TFTP_ID(0x01U) /**< @brief #TFTP_ReadImgMsgType  #TFTP_ImglGetStatus     */
#define TFTP_ID_READ_IMAGE         TFTP_ID(0x02U) /**< @brief #TFTP_ReadImgMsgType  #TFTP_ImglGetStatus     */
#define TFTP_ID_READ_FILE          TFTP_ID(0x03U) /**< @brief #TFTP_ReadFileMsgType                         */
/** @} */

/**
    @brief TFTP Read Image request

    @trace #BRCM_SWREQ_TFTP
 */
typedef struct sTFTP_ReadImgMsgType {
    uint8_t     isImgHdr;  /**< @brief set to TRUE if image is only entires and optional signature */
    uint8_t     pid;       /**< @brief Partition ID                                                */
    uint16_t    imgID;     /**< @brief Image ID                                                    */
    uint32_t    imgMaxSize;/**< @brief Image max size that can be downloaded                       */
    uint8_t*    imgAddress;/**< @brief Address to which fetched data to be copied                  */
    uint32_t    filledSize;/**< @brief Image filled size that is downloaded                        */
} TFTP_ReadImgMsgType;
BCM_STATIC_SIZE_ASSERT(TFTP_ReadImgMsgType, 16UL, TFTP_MAX_PAYLOAD_SIZE)

/**
    @brief TFTP Read File Request

    @trace #BRCM_SWREQ_TFTP
*/
typedef struct sTFTP_ReadFileMsgType {
    uint32_t    ipAddr;
    uint32_t    fileSize;
    uint8_t     fileName[TFTP_MAX_FILENAME_LEN];
} TFTP_ReadFileMsgType;
BCM_STATIC_SIZE_ASSERT(TFTP_ReadFileMsgType, 136UL, TFTP_MAX_PAYLOAD_SIZE)


/**
    @brief TFTP Union encapsulating all messages

    @trace #BRCM_SWREQ_TFTP
*/
typedef union uTFTP_MsgUnionType {
    uint32_t                        data[TFTP_MAX_PAYLOAD_SIZE/4UL];
    TFTP_ReadImgMsgType             readImg;
    TFTP_ReadFileMsgType            readFile;
} TFTP_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(TFTP_MsgUnionType, TFTP_MAX_PAYLOAD_SIZE, TFTP_MAX_PAYLOAD_SIZE)

/**
    @brief Union encapsulating all messages

    @trace #BRCM_SWREQ_TFTP
*/
typedef struct sTFTP_MsgType {
    uint32_t                    magic;
    BCM_MsgType                 id;
    int32_t                     status;
    uint32_t                    len;
    TFTP_MsgUnionType           u;
} TFTP_MsgType;

/**
    @brief IMGL Interface for TFTP

    @trace #BRCM_SWREQ_TFTP
*/
extern const IMGL_InterfaceType TFTP_ImglInterface;

#endif /* ETHERNET_TFTP_H */

/** @} */
