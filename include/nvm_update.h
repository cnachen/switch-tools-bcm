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
    @defgroup grp_nvm_update_ifc Update Interface
    @ingroup grp_nvm_abstract

    @addtogroup grp_nvm_update_ifc
    @{

    @limitations None

    @file nvm_update.h
    @brief NVM Update Interface
    This header file contains the interface functions for NVM Update

    @version 1.0 Initial Version
*/

#ifndef NVM_UPDATE_H
#define NVM_UPDATE_H

#include <bcm_comp.h>
#include <module_msg.h>
#include <pt_utils.h>
#include <system_imgl_version.h>
#include <msg_queue.h>
#include <bcm_utils.h>
#include <crypto_common.h>

/**
    @name System IMGL Architecture IDs
    @{
    @brief Architecture IDs for System IMGL
*/
#define BRCM_SWARCH_UPDATE_HEALTH_CHECK_PROC            (0x8410U) /**< @brief #UPDATE_HealthCheck       */
#define BRCM_SWARCH_UPDATE_GET_BOOT_COPY_CFG_PROC       (0x8411U) /**< @brief #UPDATE_GetBootCopyCfg    */
#define BRCM_SWARCH_UPDATE_SET_BOOT_COPY_CFG_PROC       (0x8412U) /**< @brief #UPDATE_SetBootCopyCfg    */
#define BRCM_SWARCH_UPDATE_SAFE_INSTALL_PROC            (0x8413U) /**< @brief #UPDATE_SafeInstall       */
#define BRCM_SWARCH_UPDATE_FULL_INSTALL_PROC            (0x8414U) /**< @brief #UPDATE_FullInstall       */
#define BRCM_SWARCH_UPDATE_RAW_INSTALL_PROC             (0x8415U) /**< @brief #UPDATE_RawInstall        */
#define BRCM_SWARCH_UPDATE_SYNC_PROC                    (0x8416U) /**< @brief #UPDATE_Sync              */
#define BRCM_SWARCH_UPDATE_IMGS_HASH_PROC               (0x8417U) /**< @brief #UPDATE_GetImgsHash       */

#define BRCM_SWARCH_UPDATE_ID_TYPE                      (0x8420U) /**< @brief #UPDATE_IDType            */
#define BRCM_SWARCH_UPDATE_MACRO                        (0x8421U) /**< @brief #UPDATE_ID                */
#define BRCM_SWARCH_UPDATE_IMG_HASH_TYPE                (0x8422U) /**< @brief #UPDATE_ImgHashType       */
#define BRCM_SWARCH_UPDATE_IMG_HASH_INFO_TYPE           (0x8423U) /**< @brief #UPDATE_ImgHashInfoType   */

#define BRCM_SWARCH_UPDATE_MSG_UNION_TYPE               (0x8440U) /**< @brief #UPDATE_MsgUnionType      */
#define BRCM_SWARCH_UPDATE_MSG_TYPE                     (0x8441U) /**< @brief #UPDATE_MsgType           */
#define BRCM_SWARCH_UPDATE_HEALTH_CHECK_MSG_TYPE        (0x8442U) /**< @brief #UPDATE_HealthCheckMsgType*/
#define BRCM_SWARCH_UPDATE_BOOT_PART_MSG_TYPE           (0x8443U) /**< @brief #UPDATE_BootCopyCfgMsgType*/
#define BRCM_SWARCH_UPDATE_INSTALL_MSG_TYPE             (0x8444U) /**< @brief #UPDATE_InstallMsgType    */
#define BRCM_SWARCH_UPDATE_SYNC_MSG_TYPE                (0x8445U) /**< @brief #UPDATE_SyncMsgType       */
#define BRCM_SWARCH_UPDATE_INSTALL_CFG_MSG_TYPE         (0x8446U) /**< @brief #UPDATE_InstallCfgMsgType */
#define BRCM_SWARCH_UPDATE_IMG_HASH_MSG_TYPE            (0x8447U) /**< @brief #UPDATE_ImgHashMsgType    */


/** @} */


/**
    @name UPDATE Version macros
    @{
    @brief Image version macros

    @trace #BRCM_SWREQ_UPDATE
*/
#define UPDATE_ID(x)            BCM_MSG(BCM_GROUPID_NVM, BCM_UPD_ID, (x)) /**< @brief UPDATE ID construction macro */
#define UPDATE_MAGIC            (0x55504454UL)      /**< @brief ASCII "UPDT"        */
#define UPDATE_MAX_FILENAME     (256UL)             /**< @brief Max file name size  */
#define UPDATE_MAX_INFO         (4UL)               /**< @brief Max Info length     */
#define UPDATE_MAX_MSG_SIZE     (448UL)             /**< @brief Max Message size    */

#define UPDATE_MAX_HASH_IMG_COUNT (7UL)             /**< @brief Max Image Hash count  */
/** @} */

/**
    @name UPDATE Message IDs
    @{
    @brief Message IDs for exchange on message queues and Host

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_UPDATE
*/
typedef BCM_MsgType UPDATE_IDType;     /**< @brief UPDATE message ID Type */
#define UPDATE_ID_HEALTH_CHECK          UPDATE_ID(0x00U) /**< @brief #UPDATE_HealthCheckMsgType #UPDATE_HealthCheck     */
#define UPDATE_ID_GET_IMG_HASH          UPDATE_ID(0x01U) /**< @brief #UPDATE_ImgHashMsgType     #UPDATE_GetImgsHash     */
#define UPDATE_ID_GET_BOOT_COPY_CFG     UPDATE_ID(0x10U) /**< @brief #UPDATE_BootCopyCfgMsgType #UPDATE_GetBootCopyCfg  */
#define UPDATE_ID_SET_BOOT_COPY_CFG     UPDATE_ID(0x11U) /**< @brief #UPDATE_BootCopyCfgMsgType #UPDATE_SetBootCopyCfg  */
#define UPDATE_ID_SAFE_INSTALL          UPDATE_ID(0x20U) /**< @brief #UPDATE_InstallMsgType     #UPDATE_SafeInstall     */
#define UPDATE_ID_FULL_INSTALL          UPDATE_ID(0x21U) /**< @brief #UPDATE_InstallMsgType     #UPDATE_FullInstall     */
#define UPDATE_ID_RAW_INSTALL           UPDATE_ID(0x22U) /**< @brief #UPDATE_InstallMsgType     #UPDATE_RawInstall      */
#define UPDATE_ID_SYNC                  UPDATE_ID(0x30U) /**< @brief #UPDATE_SyncMsgType        #UPDATE_Sync            */
/** @} */


/**
    @brief Image Hash

    @trace #BRCM_SWREQ_UPDATE
 */
typedef struct sUPDATE_ImgHashType {
    uint16_t imgId;
    uint16_t rsvd;
    uint8_t sha[48];
} UPDATE_ImgHashType;
BCM_STATIC_SIZE_ASSERT(UPDATE_ImgHashType, 52UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Image Hash

    @trace #BRCM_SWREQ_UPDATE
 */
typedef struct sUPDATE_ImgHashInfoType {
    uint32_t               imgCount;                                 /**< @brief Output: Fetched Hash Image count */
    UPDATE_ImgHashType     imgHash[UPDATE_MAX_HASH_IMG_COUNT];       /**< @brief Output: Image Hash */
    uint32_t               rsvd;
} UPDATE_ImgHashInfoType;
BCM_STATIC_SIZE_ASSERT(UPDATE_ImgHashInfoType, 372UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Image Hash Message

    @trace #BRCM_SWREQ_UPDATE
 */
typedef struct sUPDATE_ImgHashMsgType {
    PTBL_IdType            pid;                            /**< @brief Input: Partition ID to perform Hash calculation*/
    uint16_t               startImgIdx;                    /**< @brief Input: image index */
    CRYPTO_HashFuncType    hashFunc;                       /**< @brief Input: Hash Type */
    UPDATE_ImgHashInfoType hashInfo;                       /**< @brief Output: Hash Info Type */
    uint32_t               rsvd[8];
} UPDATE_ImgHashMsgType;
BCM_STATIC_SIZE_ASSERT(UPDATE_ImgHashMsgType, 412UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Health check message

    @trace #BRCM_SWREQ_UPDATE
 */
typedef struct sUPDATE_HealthCheckMsgType {
    PTBL_IdType         pid;    /**< @brief Input: Partition ID to perform health check on (including copy id)*/
    IMGL_VersionType    version;/**< @brief Output: Version of image (image which has the maximum version that appeared first */
} UPDATE_HealthCheckMsgType;
BCM_STATIC_SIZE_ASSERT(UPDATE_HealthCheckMsgType, 132UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Boot copy selection message

    @trace #BRCM_SWREQ_UPDATE
 */
typedef struct sUPDATE_BootCopyCfgMsgType {
    IMGL_BootCfgType    cfg;      /**< @brief Input/Output: Boot configuration */
} UPDATE_BootCopyCfgMsgType;
BCM_STATIC_SIZE_ASSERT(UPDATE_BootCopyCfgMsgType, 256UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Configuration to perform installation of new SW version

    @trace #BRCM_SWREQ_UPDATE
 */
typedef struct sUPDATE_InstallCfgMsgType {
    IMGL_ChannelType    nvmChannel;     /**< @brief Input: NVM Channel to write to                  */
    IMGL_ChannelType    fetchChannel;   /**< @brief Input: Fetch Channel to read from               */
    uint32_t            reserved[2UL];  /**< @brief Input: Reserved field                           */
    uint32_t            nvmEraseSize;   /**< @brief Input: NVM Erase size                           */
    uint32_t            fileSize;       /**< @brief Input: File size                                */
    uint32_t            ipAddr;         /**< @brief Input: IP Address of file server                */
    uint32_t            portNum;        /**< @brief Input: Port number if applicable                */
    uint32_t            info[UPDATE_MAX_INFO];  /**< @brief Input: Info specific to fetch channel   */
    uint8_t             name[UPDATE_MAX_FILENAME];  /**< @brief Input: File Name                    */
} UPDATE_InstallCfgMsgType;
BCM_STATIC_SIZE_ASSERT(UPDATE_InstallCfgMsgType, 304UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Message to perform installation of new SW version

    @trace #BRCM_SWREQ_UPDATE
 */
typedef struct sUPDATE_InstallMsgType {
    UPDATE_InstallCfgMsgType cfg;            /**< @brief Input: Install configuration                    */
    uint32_t                 recvFileSize;   /**< @brief Output: Received file size                      */
} UPDATE_InstallMsgType;
BCM_STATIC_SIZE_ASSERT(UPDATE_InstallMsgType, 308UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Message to perform SW version sync

    @trace #BRCM_SWREQ_UPDATE

    @note Set the copy number to 0 to skip syncing for that partition
 */
typedef struct sUPDATE_SyncMsgType {
    uint16_t      blCopyNum;    /**< @brief Input: Bootloader Partition Copy Number to sync */
    uint16_t      fwCopyNum;    /**< @brief Input: Firmware Partition Copy Number to sync   */
    uint16_t      cfgCopyNum;   /**< @brief Input: Config Partition Copy Number to sync     */
} UPDATE_SyncMsgType;
BCM_STATIC_SIZE_ASSERT(UPDATE_SyncMsgType, 6UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Update Union encapsulating all messages

    @trace #BRCM_SWREQ_UPDATE
*/
typedef union uUPDATE_MsgUnionType {
    uint32_t                        data[UPDATE_MAX_MSG_SIZE/4UL];
                                                 /**< @brief Unformatted request   */
    UPDATE_ImgHashMsgType           hash;        /**< @brief Health check          */
    UPDATE_HealthCheckMsgType       healthCheck; /**< @brief Health check          */
    UPDATE_BootCopyCfgMsgType       bootCfg;     /**< @brief Boot configuration    */
    UPDATE_InstallMsgType           install;     /**< @brief Install               */
    UPDATE_SyncMsgType              sync;        /**< @brief Sync                  */
} UPDATE_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(UPDATE_MsgUnionType, 448UL, UPDATE_MAX_MSG_SIZE)

/**
    @brief Verity Union encapsulating all messages

    @trace #BRCM_SWREQ_UPDATE
*/
typedef struct sUPDATE_MsgType {
    uint32_t                    magic;  /**< @brief Magic                         */
    BCM_MsgType                 id;     /**< @brief Command ID of #UPDATE_IDType  */
    int32_t                     status; /**< @brief Status                        */
    uint32_t                    len;    /**< @brief Length of the payload         */
    UPDATE_MsgUnionType         u;      /**< @brief Payload                       */
} UPDATE_MsgType;
BCM_STATIC_SIZE_ASSERT(UPDATE_MsgType, 464UL, 464UL)

/**
    @brief Calulate the Images Hash of given partition

    @behavior Async, Non-Rentrant

    @pre None

    @param[in]    aConnHdl     Connection handle (from RPC_Connect)
    @param[in]    aPid         Partition ID and copy index as #PTBL_IdType
                               #PTBL_ID_CONSTRUCT can be used to construct.
    @param[in/out] aHashFunc   Pointer to Hash Type to calculate the Hash
                               [in]  : - Valid #CRYPTO_HashFuncType or
                                       - #CRYPTO_HASH_FUNC_NONE : This will calculate
                                        the Hash based on flashed image Hash Type.
                               [out] : HashType used for generating the Hash.

    @param[out]    aImgHashInfo   Pointer to hold the Fetched Hash of images

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Hash Calculation is completed
    @retval     #BCM_ERR_NOT_FOUND      Partition not found
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_BUSY           Busy processing
    @retval     #BCM_ERR_NOSUPPORT      aHashFunc Value is not supported
    @retval     #BCM_ERR_INVAL_PARAMS   aHashFunc is NULL or aImgHashInfo is NULL

    @post None

    @trace #BRCM_SWREQ_UPDATE

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host. This API is not intended for user data partition.
*/
int32_t UPDATE_GetImgsHash(BCM_HandleType aConnHdl, PTBL_IdType aPid, uint16_t aStartImgIdx,
                                                    CRYPTO_HashFuncType *aHashFunc,
                                                    UPDATE_ImgHashInfoType *aImgHashInfo);

/**
    @brief Perform health check on a specific partition

    Reads content from a specific partition, authenticates the integrity of the content,
    and reports the status to caller. This is used in conjuction with #UPDATE_ID_HEALTH_CHECK

    @behavior Async, Non-Rentrant

    @pre None

    @param[in]    aConnHdl    Connection handle (from RPC_Connect)
    @param[in]    aPid        Partition ID and copy index as #PTBL_IdType
                              #PTBL_ID_CONSTRUCT can be used to construct.
    @param[out]   aVersion    Pointer to the store the maximum version of images in the given partition

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Health check is complete and the partition is healthy
    @retval     #BCM_ERR_AUTH_FAILED    Health check failed due to authentication failure
    @retval     #BCM_ERR_NOT_FOUND      Partition not found
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_BUSY           Busy processing

    @post None

    @trace #BRCM_SWREQ_UPDATE

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host. This API is not intended for user data partition.
*/
int32_t UPDATE_HealthCheck(BCM_HandleType aConnHdl, PTBL_IdType aPid, IMGL_VersionType *aVersion);

/**
    @brief Get Boot Copy configuaration

    Queries the previously selected boot copy configuration.
    This is used in conjuction with #UPDATE_ID_GET_BOOT_COPY_CFG

    @behavior Async, Non-Rentrant

    @pre None

    @param[in]   aConnHdl     Connection handle (from RPC_Connect)
    @param[out]  aBootCfgMsg  Pointer to the store the boot configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Boot Copy Config is retrieved
    @retval     #BCM_ERR_NOT_FOUND      Boot Copy Config not found
    @retval     #BCM_ERR_BUSY           Busy processing

    @post None

    @trace #BRCM_SWREQ_UPDATE

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t UPDATE_GetBootCopyCfg(BCM_HandleType aConnHdl, UPDATE_BootCopyCfgMsgType *aBootCfgMsg);

/**
    @brief Set Boot Copy configuaration

    Updates the boot copy configuration. This is used in conjuction with
    #UPDATE_ID_SET_BOOT_COPY_CFG

    @behavior Async, Non-Rentrant

    @pre None

    @param[in]   aConnHdl    Connection handle (from RPC_Connect)
    @param[in]   aBootCfgMsg Pointer to the boot configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Boot Copy Config is updated
    @retval     #BCM_ERR_UNKNOWN        Boot Copy Config update failed
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid parameters (copy numbers could be out of range)
    @retval     #BCM_ERR_BUSY           Busy processing

    @post None

    @trace #BRCM_SWREQ_UPDATE

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t UPDATE_SetBootCopyCfg(BCM_HandleType aConnHdl, UPDATE_BootCopyCfgMsgType *aBootCfgMsg);

/**
    @brief Safe Install

    Performs erase of partitions with copy id set to 3. Writes user provided content
    into partitions with copy id 3. Missing images are picked up from the current
    booted version. This API performs authentication of received images, and erases
    upon failure.This is used in conjuction with #UPDATE_ID_SAFE_INSTALL

    @behavior Async, Non-Rentrant

    @pre None

    @param[in]   aConnHdl      Connection handle (from RPC_Connect)
    @param[in]   aInstallMsg   Pointer to the installation configuration
    @param[out]  aRecvFileSize Pointer to store the received file size

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Safe install is succesful
    @retval     #BCM_ERR_UNKNOWN        Safe install failed (due to missing images etc)
    @retval     #BCM_ERR_AUTH_FAILED    Safe install failed due to authentication failure
    @retval     #BCM_ERR_BUSY           Busy processing
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid image received

    @post None

    @trace #BRCM_SWREQ_UPDATE

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host.
*/
int32_t UPDATE_SafeInstall(BCM_HandleType aConnHdl, UPDATE_InstallCfgMsgType *aInstallMsg, uint32_t *aRecvFileSize);

/**
    @brief Full Install

    Performs full erase of Flash and writes user provided into Flash partitions
    (all copies). This API performs authentication of images, however does not restore
    to older version upon failure.This is used in conjuction with #UPDATE_ID_FULL_INSTALL

    @behavior Async, Non-Rentrant

    @pre None

    @param[in]   aConnHdl      Connection handle (from RPC_Connect)
    @param[in]   aInstallMsg   Pointer to the installation configuration
    @param[out]  aRecvFileSize Pointer to store the received file size

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Full install is succesful
    @retval     #BCM_ERR_UNKNOWN        Full install failed
    @retval     #BCM_ERR_AUTH_FAILED    Full install failed due to authentication failure
    @retval     #BCM_ERR_BUSY           Busy processing
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid parameters (copy numbers could be out of range)

    @post None

    @trace #BRCM_SWREQ_UPDATE

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host. During this API, target must not be powed off or rebooted.
*/
int32_t UPDATE_FullInstall(BCM_HandleType aConnHdl, UPDATE_InstallCfgMsgType *aInstallMsg, uint32_t *aRecvFileSize);

/**
    @brief Raw Install

    Performs full erase of Flash and writes user provided content into Flash memory.
    This API does not perform authentication of images.This is used in conjuction
    with #UPDATE_ID_RAW_INSTALL

    @behavior Async, Non-Rentrant

    @pre None

    @param[in]   aConnHdl      Connection handle (from RPC_Connect)
    @param[in]   aInstallMsg   Pointer to the installation configuration
    @param[out]  aRecvFileSize Pointer to store the received file size

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Raw install is succesful
    @retval     #BCM_ERR_UNKNOWN        Raw install failed
    @retval     #BCM_ERR_AUTH_FAILED    Raw install failed due to authentication failure
    @retval     #BCM_ERR_BUSY           Busy processing
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid parameters (copy numbers could be out of range)

    @post None

    @trace #BRCM_SWREQ_UPDATE

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host. During this API, target must not be powed off or rebooted.
*/
int32_t UPDATE_RawInstall(BCM_HandleType aConnHdl, UPDATE_InstallCfgMsgType *aInstallMsg, uint32_t *aRecvFileSize);

/**
    @brief Sync current booted version (from Flash) to a different partition in Flash

    Performs erase of partitions with copy id as set in UPDATE_SyncMsgType.
    Writes current booted content into partitions with copy id as set in UPDATE_SyncMsgType.
    This API does not perform authentication of images. Authentication of images may be
    triggered using #UPDATE_HealthCheck. This is used in conjuction with #UPDATE_ID_SYNC

    @behavior Async, Non-Rentrant

    @pre None

    @param[in]   aConnHdl    Connection handle (from RPC_Connect)
    @param[in]   aSyncMsg    Pointer to the the sync configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Sync is succesful
    @retval     #BCM_ERR_UNKNOWN        Sync failed
    @retval     #BCM_ERR_BUSY           Busy processing
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid parameters (copy numbers could be out of range)

    @post None

    @trace #BRCM_SWREQ_UPDATE

    @limitations This API must not be called by anyone directly. #BCM_ERR_BUSY is
    never returned to Host. During this API, target must not be powed off or rebooted.
*/
int32_t UPDATE_Sync(BCM_HandleType aConnHdl, UPDATE_SyncMsgType *aSyncMsg);

#endif /* NVM_UPDATE_H */
/** @} */
