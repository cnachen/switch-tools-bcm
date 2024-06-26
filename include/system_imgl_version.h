/*****************************************************************************
 Copyright 2020-2023 Broadcom Limited.  All rights reserved.

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

/** @defgroup grp_system_imgl_version_ifc IMGL Interface
    @ingroup grp_system_abstract

    @addtogroup grp_system_imgl_version_ifc
    @{
    Version information and comtability checks for the images.

    @file system_imgl_version.h
    @brief Image version Interfaces
    @version 0.1 Initial Version
*/

#ifndef SYSTEM_IMGL_VERSION_H
#define SYSTEM_IMGL_VERSION_H

#include <bcm_err.h>
#include <bcm_utils.h>
#include <stdint.h>
#include <pt_utils.h>

/**
    @name Image version Integration Interface IDs
    @{
    @brief Integration Interface IDs for Image version

*/
#define BRCM_SWARCH_IMGL_GET_BOOT_VERSION_PROC      (0x8100U) /**< @brief #IMGL_GetBootVersion      */
#define BRCM_SWARCH_IMGL_GET_IMG_VERSION_PROC       (0x8101U) /**< @brief #IMGL_GetImgVersion       */

#define BRCM_SWARCH_IMGL_GET_IMG_SIZE_PROC          (0x8110U) /**< @brief #IMGL_GetImgSize          */
#define BRCM_SWARCH_IMGL_GET_IMG_BUFFER_PROC        (0x8111U) /**< @brief #IMGL_GetImgBuffer        */

#define BRCM_SWARCH_IMGL_ID_TYPE                    (0x8120U)   /**< @brief #IMGL_IDType                */
#define BRCM_SWARCH_IMGL_ID_MACRO                   (0x8121U)   /**< @brief #IMGL_ID                    */
#define BRCM_SWARCH_IMGL_MACRO                      (0x8122U)   /**< @brief #IMGL_MAGIC                 */
#define BRCM_SWARCH_IMGL_CHANNEL_TYPE               (0x8123U)   /**< @brief #IMGL_ChannelType           */

#define BRCM_SWARCH_IMGL_UPDATE_AUTOSYNC_MSG_TYPE   (0x8130U) /**< @brief #IMGL_UpdateAutoSyncMsgType */
#define BRCM_SWARCH_IMGL_INFO_TYPE                  (0x8131U) /**< @brief #IMGL_ImgInfoType         */
#define BRCM_SWARCH_IMGL_IMG_VERSION_TYPE           (0x8136U) /**< @brief #IMGL_ImgVersionType      */
#define BRCM_SWARCH_IMGL_BOOT_CFG_TYPE              (0x8138U) /**< @brief #IMGL_BootCfgType         */

#define BRCM_SWARCH_IMGL_VERSION_TYPE               (0x8140U)   /**< @brief #IMGL_VersionType           */
#define BRCM_SWARCH_IMGL_VERSION_MACRO              (0x8141U)   /**< @brief #IMGL_VERSION_MAGIC         */
#define BRCM_SWARCH_IMGL_MAJOR_VERSION_TYPE         (0x8142U)   /**< @brief #IMGL_MajorVersionType      */
#define BRCM_SWARCH_IMGL_MINOR_VERSION_TYPE         (0x8143U)   /**< @brief #IMGL_MinorVersionType      */
#define BRCM_SWARCH_IMGL_VERS_LEN_MACRO             (0x8147U)   /**< @brief #IMGL_VERS_LEN_TAG          */


#define BRCM_SWARCH_IMGL_MSG_UNION_TYPE             (0x8180U) /**< @brief #IMGL_MsgUnionType        */
#define BRCM_SWARCH_IMGL_MSG_TYPE                   (0x8181U) /**< @brief #IMGL_MsgType             */
#define BRCM_SWARCH_IMGL_BOOT_VERSION_MSG_TYPE      (0x8182U) /**< @brief #IMGL_BootVersionMsgType  */
#define BRCM_SWARCH_IMGL_IMG_VERSION_MSG_TYPE       (0x8183U) /**< @brief #IMGL_ImgVersionMsgType   */

/** @} */

/**
    @name IMGL Macros
    @{

    @trace #BRCM_SWREQ_IMGL
*/
#define IMGL_MAGIC                      (0x4C474D49UL)
#define IMGL_IMGH_MAGIC                 (0x494D4748UL)
#define IMGL_MSG_MAX_SIZE               (448UL)
#define IMGL_VERSION_MAX_NUM_ELEMENTS   (24UL)
/** @} */

/**
    @brief IMGL ID construction macro

    @trace #BRCM_SWREQ_IMGL
*/
#define IMGL_ID(x) BCM_MSG(BCM_GROUPID_SYS, BCM_IMG_ID, (x))

/**
    @name IMGL Message IDs
    @{
    @brief Message IDs for exchange on message queues and Host

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_IMGL
*/
typedef BCM_MsgType IMGL_IDType;     /**< @brief IMGL message ID Type */
#define IMGL_ID_UPDATE_AUTO_SYNC        IMGL_ID(0x01U) /**< @brief #IMGL_UpdateAutoSyncMsgType  #UPDATE_Status          */
#define IMGL_ID_GET_BOOT_VERSION        IMGL_ID(0x02U) /**< @brief #IMGL_BootVersionMsgType     #IMGL_GetBootVersion    */
#define IMGL_ID_GET_IMG_VERSION         IMGL_ID(0x03U) /**< @brief #IMGL_ImgVersionMsgType      #IMGL_GetImgVersion     */
/** @} */

/**
    @name IMGL_ChannelType
    @{
    @brief IMGL Channel ID

    @trace #BRCM_SWREQ_IMGL
*/
typedef uint32_t IMGL_ChannelType;               /**< @brief Loader channel ID */
#define IMGL_CHANNEL_ID_INVALID  (0x00UL)        /**< @brief Invalid           */
#define IMGL_CHANNEL_ID_NVM_0    (0x4E564D30UL)  /**< @brief NVM 0             */
#define IMGL_CHANNEL_ID_NVM_1    (0x4E564D31UL)  /**< @brief NVM 1             */
#define IMGL_CHANNEL_ID_RPC_IPC  (0x52495043UL)  /**< @brief RPC IPC           */
#define IMGL_CHANNEL_ID_RPC_UDP  (0x52554450UL)  /**< @brief RPC UDP           */
#define IMGL_CHANNEL_ID_RPC_FTP  (0x52465450UL)  /**< @brief RPC FTP           */
/** @} */

/**
    @brief Image version macros

    @trace #BRCM_SWREQ_IMGL
*/
#define IMGL_VERSION_MAGIC              (0x56455253UL)

/**
    @brief Image Major Version

    @trace #BRCM_SWREQ_IMGL
*/
typedef uint32_t IMGL_MajorVersionType;

/**
    @brief Image Minor Version

    @trace #BRCM_SWREQ_IMGL
*/
typedef uint32_t IMGL_MinorVersionType;

/**
    @name Build info fields
    @{
    @brief Build information

    Build information field lengths

    @trace #BRCM_SWREQ_IMGL
*/
#define IMGL_VERS_LEN_TAG          (24UL)   /**< @brief Tag string */
#define IMGL_VERS_LEN_OS           (8UL)    /**< @brief OS name */
#define IMGL_VERS_LEN_APP          (20UL)   /**< @brief Application Name */
#define IMGL_VERS_LEN_IMG_TYPE     (4UL)    /**< @brief 'Dev' or 'Rel' */
#define IMGL_VERS_LEN_IMG_VERS     (8UL)    /**< @brief Alpha numeric version */
#define IMGL_VERS_LEN_TIME         (52UL)   /**< @brief date, time, Server name and user name */
/** @} */

/**
    @brief Version type

    Version information

    @trace #BRCM_SWREQ_IMGL
 */
typedef struct sIMGL_VersionType {
    uint32_t              magic;           /**< @brief Magic VERS #IMGL_VERSION_MAGIC */
    IMGL_MajorVersionType major;           /**< @brief Major version number */
    IMGL_MinorVersionType minor;           /**< @brief Minor version number */
    uint8_t               buildInfo[IMGL_VERS_LEN_TAG +
                                    IMGL_VERS_LEN_OS +
                                    IMGL_VERS_LEN_APP +
                                    IMGL_VERS_LEN_IMG_TYPE +
                                    IMGL_VERS_LEN_IMG_VERS +
                                    IMGL_VERS_LEN_TIME];
                                            /**< @brief Build information */
} IMGL_VersionType;
BCM_STATIC_SIZE_ASSERT(IMGL_VersionType, 128UL, IMGL_MSG_MAX_SIZE)

/**
    @brief Basic Image Version

    @trace #BRCM_SWREQ_IMGL
*/
typedef struct sIMGL_ImgVersionType {
    uint16_t                imgId;  /**< @brief Image ID                        */
    uint16_t                rsvd;   /**< @brief reserved                        */
    IMGL_MajorVersionType   major;  /**< @brief Major version                   */
    IMGL_MinorVersionType   minor;  /**< @brief Minor version                   */
} IMGL_ImgVersionType;
BCM_STATIC_SIZE_ASSERT(IMGL_ImgVersionType, 12UL, IMGL_MSG_MAX_SIZE)

#pragma pack(push, 4)
/**
    @brief Image info

    @trace #BRCM_SWREQ_IMGL
 */
typedef struct sIMGL_ImgInfoType {
    uint8_t  isImgHdr;  /**< @brief set to TRUE if image is only entires and optional signature */
    uint8_t  pid;       /**< @brief Partition ID                                                */
    uint16_t imgID;     /**< @brief Image ID                                                    */
    uint32_t imgMaxSize;/**< @brief Image max size that can be downloaded                       */
} IMGL_ImgInfoType;
BCM_STATIC_SIZE_ASSERT(IMGL_ImgInfoType, 8UL, IMGL_MSG_MAX_SIZE)

/**
    @brief Image loader update with auto sync structure

    @trace #BRCM_SWREQ_IMGL
 */
typedef struct sIMGL_UpdateAutoSyncMsgType {
    uint32_t            flashId;
    uint32_t            flashAddr;
    uint32_t            numImgs;
    uint32_t            fetchChannel;
    IMGL_ImgInfoType    imgHdr[ITBL_MAX_NUM_ENTRIES];
} IMGL_UpdateAutoSyncMsgType;
_Static_assert(sizeof(IMGL_UpdateAutoSyncMsgType) <= IMGL_MSG_MAX_SIZE,
    "Ease of debug will be broken if the size is not properly aligned");

/**
    @brief Image loader boot version message type

    @trace #BRCM_SWREQ_IMGL
 */
typedef struct sIMGL_BootVersionMsgType {
    PTBL_IdType             pid;        /**< @brief Input:  Partition ID */
    uint16_t                numImages;  /**< @brief Output: Number of filled version info               */
    IMGL_MajorVersionType   major;      /**< @brief Output: Major version (max of all image versions)   */
    IMGL_MinorVersionType   minor;      /**< @brief Output: Minor version (max of all image versions)   */
    IMGL_ImgVersionType     imgVersion[IMGL_VERSION_MAX_NUM_ELEMENTS];  /**< @brief Output: Image version           */
} IMGL_BootVersionMsgType;
BCM_STATIC_SIZE_ASSERT(IMGL_BootVersionMsgType, 300UL, IMGL_MSG_MAX_SIZE)

/**
    @brief Image loader update with auto sync structure

    @trace #BRCM_SWREQ_IMGL
 */
typedef struct sIMGL_ImgVersionMsgType {
    PTBL_IdType         pid;    /**< @brief Input: Partition ID     */
    uint16_t            imgId;  /**< @brief Input: Image ID         */
    IMGL_VersionType    version;/**< @brief Output: Detailed Version*/
} IMGL_ImgVersionMsgType;
BCM_STATIC_SIZE_ASSERT(IMGL_ImgVersionMsgType, 132UL, IMGL_MSG_MAX_SIZE)

/**
    @brief Boot copy selection configuration

    @trace #BRCM_SWREQ_IMGL
 */
typedef struct sIMGL_BootCfgType {
    uint32_t            magic;          /**< @brief Must be #IMGL_MAGIC                     */
    uint32_t            version;        /**< @brief Must be 0                               */
    uint16_t            blCopyNum;      /**< @brief Bootloader Partition Copy Number to boot*/
    uint16_t            fwCopyNum;      /**< @brief Firmware Partition Copy Number to boot  */
    uint16_t            cfgCopyNum;     /**< @brief Config Partition Copy Number to boot    */
    uint16_t            altCopyEn;      /**< @brief Enable boot from alternate copies       */
    uint16_t            blCopyMask;     /**< @brief Alternate Bootloader Copies to boot from.
                                                        Used when altCopyEn is 1            */
    uint16_t            fwCopyMask;     /**< @brief Alternate Firmware Copies to boot from.
                                                        Used when altCopyEn is 1            */
    uint16_t            cfgCopyMask;     /**< @brief Alternate Config Copies to boot from.
                                                        Used when altCopyEn is 1            */
    uint16_t            reserved;
    uint32_t            rsvd[58UL];
} IMGL_BootCfgType;
BCM_STATIC_SIZE_ASSERT(IMGL_BootCfgType, 256UL, IMGL_MSG_MAX_SIZE)

#pragma pack(pop)

/**
    @brief IMGL Union encapsulating all messages

    @trace #BRCM_SWREQ_IMGL
*/
typedef union uIMGL_MsgUnionType {
    uint32_t                        data[IMGL_MSG_MAX_SIZE/4UL];
    IMGL_UpdateAutoSyncMsgType      updateAutoSync;
    IMGL_BootVersionMsgType         bootVersion;
    IMGL_ImgVersionMsgType          imgVersion;
} IMGL_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(IMGL_MsgUnionType, IMGL_MSG_MAX_SIZE, IMGL_MSG_MAX_SIZE)

/**
    @brief Verity Union encapsulating all messages

    @trace #BRCM_SWREQ_IMGL
*/
typedef struct sIMGL_MsgType {
    uint32_t                    magic;
    BCM_MsgType                 id;
    int32_t                     status;
    uint32_t                    len;
    IMGL_MsgUnionType           u;
} IMGL_MsgType;
BCM_STATIC_SIZE_ASSERT(IMGL_MsgType, 464UL, 464UL)

/** @brief Get booted software version

    Gives overall booted version information including minimalistic information
    on version of each image

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]       aConnHdl             Connection handle (from RPC_Connect)
    @param[in]       aPid                 Partition ID
    @param[out]      aVersionMsg          Version Message to be filled

    Return values are documented in reverse-chronological order
    @return     #BCM_ERR_OK             Boot version is filled correctly
    @return     #BCM_ERR_UNKNOWN        Failed to fetch version of all images
    @return     #BCM_ERR_EAGAIN         Boot not completed, try again after sometime
    @return     #BCM_ERR_INVAL_PARAMS   aVersionMsg is NULL

    @post None

    @trace  #BRCM_SWREQ_IMGL
*/
/*  @event         MISRA C-2012 Rule 5.8, MISRA C-2012 Identifiers
    @issue         Identifier IMGL_GetBootVersion is already used to represent a function\
                   with external linkage.
    @risk          Undefined behaviour.
    @justification Issue due to build configuration with multiple definitions in files\
                   system_imgl_host.c and imgl_module.c */
/* coverity[misra_c_2012_rule_5_8_violation] */
extern int32_t IMGL_GetBootVersion(BCM_HandleType aConnHdl, PTBL_IdType aPid,
                                        IMGL_BootVersionMsgType* aVersionMsg);

/** @brief Get booted image version

    Gives detailed information on version of each image

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]       aConnHdl             Connection handle (from RPC_Connect)
    @param[in]       aPid        Partition ID
    @param[in]       aImgId      Image ID
    @param[out]      aVersion    Version information to be filled

    Return values are documented in reverse-chronological order
    @return     #BCM_ERR_OK             Image version filled
    @return     #BCM_ERR_NOT_FOUND      Image not found
    @return     #BCM_ERR_EAGAIN         Boot not completed, try again after sometime
    @return     #BCM_ERR_INVAL_PARAMS   aVersion is NULL

    @post None

    @trace  #BRCM_SWREQ_IMGL
*/
/*  @event         MISRA C-2012 Rule 5.8, MISRA C-2012 Identifiers
    @issue         Identifier IMGL_GetImgVersion is already used to represent a function\
                   with external linkage.
    @risk          Undefined behaviour.
    @justification Issue due to build configuration with multiple definitions in files\
                   system_imgl_host.c and imgl_module.c */
/* coverity[misra_c_2012_rule_5_8_violation] */
extern int32_t IMGL_GetImgVersion(BCM_HandleType aConnHdl, PTBL_IdType aPid,
                                        uint16_t aImgId, IMGL_VersionType* aVersion);

/** @brief Get the remaining size of image after offset

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aIsImgTbl  Is Image Table
    @param[in]   aPid       Partition ID
    @param[in]   aImgID     Image ID
    @param[in]   aOffset    Offset within the size

    @retval     Remaining size of image in bytes, zero if the image is not found

    @post None

    @trace #BRCM_SWREQ_IMGL

    @limitations This API shall be called from the task context. This API also
    assumes that all APIs in  IMGL Osil are invoked from highest priority task
    in the system
*/
extern uint32_t IMGL_GetImgSize(uint32_t aIsImgTbl, PTBL_IdType aPid, uint16_t aImgID, uint32_t aOffset);

/** @brief Get the buffer pointer for an image

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aIsImgTbl  Is Image Table
    @param[in]   aPid       Partition ID
    @param[in]   aImgID     Image ID
    @param[in]   aOffset    Offset within the size

    @return     Buffer pointer

    @post None

    @trace #BRCM_SWREQ_IMGL

    @limitations This API shall be called from the task context. This API also
    assumes that all APIs in  IMGL Osil are invoked from highest priority task
    in the system
*/
extern const uint8_t* IMGL_GetImgBuffer(uint32_t aIsImgTbl, PTBL_IdType aPid, uint16_t aImgID);


#endif /* SYSTEM_IMGL_VERSION_H */
/** @} */
