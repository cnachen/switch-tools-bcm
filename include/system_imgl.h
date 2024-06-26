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
    @defgroup grp_system_imgl_ifc Image Loader Interface
    @ingroup grp_system_abstract

    @addtogroup grp_system_imgl_ifc
    @{

    @section sec_imgl_seq Sequence Diagrams
    @tagseq imgl_seq_diagram.svg "Sequence diagram"
    @startseq
    group {label = "client"; color = "#EFFFFF";  Client;};
    group {label = "imgl"; color = "#FFEFFF"; ImageLoader;ServerIf};
    group {label = "server"; color = "#FFFFEF"; ModeServer;};
    loop {
        Client -> ImageLoader [label = "IMGL_LoadImg"];
        ImageLoader -> ServerIf [label = "<MODE>_LoadImg"];
        ServerIf -> ModeServer [label = "signal", rightnote = "Image Loading Start"] {
        Client <-- ServerIf;
            Client <-- ModeServer [label = "notify", rightnote = "Image Loading Complete"];
        };
        Client =>  ImageLoader [label = "IMGL_GetStatus", return="return"]{
            ImageLoader =>  ServerIf [label = "<MODE>_GetStatus"];
        };
    };
    @endseq

    @limitations None

    @file system_imgl.h
    @brief System Image Loader Interface
    This header file contains the interface functions for System Image Loader Interface

    @version 1.0 Initial Version
*/

#ifndef SYSTEM_IMGL_H
#define SYSTEM_IMGL_H

#include <bcm_comp.h>
#include <pt_utils.h>
#include <system_imgl_version.h>
#include <bcm_utils.h>

/**
    @name System IMGL Architecture IDs
    @{
    @brief Architecture IDs for System IMGL
*/
#define BRCM_SWARCH_IMGL_USER_IMGID_MACRO           (0x8300U) /**< @brief #IMGL_USER_IMG_ID         */
#define BRCM_SWARCH_IMGL_HSMFW_IMG_ID_MACRO         (0x8301U) /**< @brief #IMGL_HSMFW_IMG_ID        */

#define BRCM_SWARCH_IMGL_VER_CMP_RESULT_TYPE        (0x8314U)   /**< @brief #IMGL_VerCmpResultType      */
#define BRCM_SWARCH_IMGL_VER_CMP_PROC               (0x8315U)   /**< @brief #IMGL_VersionCompare        */
#define BRCM_SWARCH_IMGL_IS_VER_COMPATIBLE_PROC     (0x8316U)   /**< @brief #IMGL_IsVersionCompatible   */
#define BRCM_SWARCH_IMGL_GET_VERSION_INFO_PROC      (0x8317U)   /**< @brief #IMGL_GetVersionInfo        */

#define BRCM_SWARCH_IMGL_LOAD_IMG_PROC              (0x83B0U) /**< @brief #IMGL_LoadImg             */
#define BRCM_SWARCH_IMGL_GET_STATUS_PROC            (0x83B1U) /**< @brief #IMGL_GetStatus           */
#define BRCM_SWARCH_IMGL_LOAD_IMG_TBL_PROC          (0x83B2U) /**< @brief #IMGL_GetImgTbl           */
#define BRCM_SWARCH_IMGL_LOAD_RAW_IMG_PROC          (0x83B3U) /**< @brief #IMGL_LoadRawImg          */
#define BRCM_SWARCH_IMGL_LOAD_CANCEL_PROC           (0x83B5U) /**< @brief #IMGL_LoadCancel          */
#define BRCM_SWARCH_IMGL_LOAD_MODE_TYPE             (0x83B6U) /**< @brief #IMGL_ModeType            */
#define BRCM_SWARCH_IMGL_LOAD_STATUS_TYPE           (0x83B7U) /**< @brief #IMGL_LoadStatusType      */
#define BRCM_SWARCH_IMGL_GET_CFG_PROC               (0x83B8U) /**< @brief #IMGL_GetCfg              */

/** @} */


/**
    @name Image Loader Modes
    @{
    @brief Image Loader Modes

    @trace #BRCM_SWREQ_IMGL
*/
typedef uint32_t IMGL_ModeType;             /**< @brief Load Mode Type               */
#define IMGL_LOAD_MODE_MAX  (0x03UL)        /**< @brief Maximum number of interfaces */
#define IMGL_LOAD_MODE_NONE (0x00UL)        /**< @brief Load Mode None. Must be zero */
#define IMGL_LOAD_MODE_NVM  (0x4E564D20UL)  /**< @brief Load Mode NVM                */
#define IMGL_LOAD_MODE_RPC  (0x52504320UL)  /**< @brief Load Mode RPC                */
/** @} */

/**
    @name IMGL user Image ID

    @trace #BRCM_SWREQ_IMGL
*/
#define IMGL_USER_IMG_ID    (0x1000U)   /**< @brief User Img ID     */

/**
    @name IMGL HSMFW Image ID

    @trace #BRCM_SWREQ_IMGL
*/
#define IMGL_HSMFW_IMG_ID   (0x4U)      /**< @brief HSM FW image ID */

/**
    @brief Image Load status type

    @trace #BRCM_SWREQ_IMGL
 */
typedef struct sIMGL_LoadStatusType {
    IMGL_ModeType       mode;   /**< @brief load mode      */
    uint32_t            size;   /**< @brief filled size    */
    BCM_HandleType      hdr;    /**< @brief message handle */
} IMGL_LoadStatusType;
BCM_STATIC_SIZE_ASSERT(IMGL_LoadStatusType, 16UL, 16UL)

/** @brief get an image table

    This is a synchronous API which retrieves Image Table.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aImgTblID   8-bit Image Table ID

    @return     NULL if aImgTblID is invalid or not found or a valid Image Table pointer

    @post None

    @trace #BRCM_SWREQ_IMGL

    @limitations This API shall be called from the task context.
*/
extern const ITBL_Type *IMGL_GetImgTbl(uint8_t aImgTblID);

/** @brief Request to load an image

    This is an asynchronous API which sends a message to IMGL Server.
    Upon the completion, client is signaled.

    Client may
     -# call @ref IMGL_GetStatus API to get the status of the image header load request
     -# call @ref IMGL_LoadCancel API to cancel the request

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aImgID      16-bit Image ID
    @param[out]     aAddr       Address where image shall be loaded. It is
                                client's responsibility to ensure that this
                                address is valid until the load request is
                                completed by the server (upon the completion
                                of the load request, client shall be signaled
                                using @c aClientMask)
    @param[in]      aBufSize    Size of the image
    @param[in]      aClientMask Client event mask
    @param[out]     aStatus     Status type structure to contain mode of operation
                                and message handle from server.
                                Shall be used by the client in #IMGL_GetStatus
                                API to query the result of this request

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Request to Load image is accepted and
                                        shall be processed asynchronously. Upon
                                        completion of the request, client shall
                                        be signaled using @c aClientMask
    @return     #BCM_ERR_NOMEM          Insufficient memory to load image
    @return     #BCM_ERR_NOT_FOUND      Image not found
    @return     #BCM_ERR_NODEV          No Method to load image
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL or
                                        aBufSize is zero or
                                        aAddr is NULL

    @post None

    @trace #BRCM_SWREQ_IMGL

    @limitations This API shall be called from the task context.
*/
extern int32_t IMGL_LoadImg(uint16_t aImgID, uint8_t *const aAddr,
                           uint32_t aBufSize, const uint32_t aClientMask,
                           IMGL_LoadStatusType* const aStatus);

/** @brief Request to load an image header

   This is an asynchronous API which sends a message to IMGL Server.
   Upon the completion, client is signaled.

   Client may
    -# call @ref IMGL_GetStatus API to get the status of the image header load request
    -# call @ref IMGL_LoadCancel API to cancel the request

   @behavior Async, Re-entrant

   @pre None

   @param[in]      aPid        Partition ID
   @param[in]      aImgID      16-bit Image ID
   @param[out]     aAddr       Address where image shall be loaded. It is
                               client's responsibility to ensure that this
                               address is valid until the load request is
                               completed by the server (upon the completion
                               of the load request, client shall be signaled
                               using @c aClientMask)
   @param[in]      aOffset     Offset, within the image, from where to load
   @param[in]      aBufSize    Size of the image
   @param[in]      aClientMask Client event mask
   @param[out]     aStatus     Status type structure to contain mode of operation
                               and message handle from server.
                               Shall be used by the client in #IMGL_GetStatus
                               API to query the result of this request

   Return values are documented in reverse-chronological order
   @retval     #BCM_ERR_OK             Request to Load image is accepted and
                                       shall be processed asynchronously. Upon
                                       completion of the request, client shall
                                       be signaled using @c aClientMask
   @return     #BCM_ERR_NODEV          No Method to load image
   @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL or
                                       aAddr is NULL

   @post None

   @trace #BRCM_SWREQ_IMGL

   @limitations This API shall be called from the task context.
*/
extern int32_t IMGL_LoadRawImg(PTBL_IdType aPid, uint16_t aImgID, uint8_t *const aAddr,
                            uint32_t aOffset, uint32_t aBufSize, const uint32_t aClientMask,
                            IMGL_LoadStatusType* const aStatus);

/** @brief Cancel previous posted request

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aStatus     Status type structure to contain mode of operation
                                and message handle from server.
                                Returned to the client in #IMGL_LoadImg or #IMGL_LoadRawImg API

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Request to Load image is completed
    @retval     #BCM_ERR_CANCELLED      Request is cancelled
    @retval     #BCM_ERR_BUSY           Server busy processing request, cannot be cancelled
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL

   @post None

   @trace #BRCM_SWREQ_IMGL

   @limitations This API shall be called from the task context.
*/
int32_t IMGL_LoadCancel(IMGL_LoadStatusType* const aStatus);

/** @brief Get the status of Load request

    @behavior Sync, Re-entrant

    @pre None

    @param[inout]   aStatus     Status type structure

    @return     #BCM_ERR_OK             Load completed successfully
    @return     #BCM_ERR_BUSY           Load is in progress
    @return     #BCM_ERR_NOT_FOUND      Image ID not found in aStatus->mode
    @return     #BCM_ERR_INVAL_STATE    Loader (of that mode) was not initialized
    @return     #BCM_ERR_DATA_INTEG     Data integrity check failed
    @return     #BCM_ERR_NOMEM          Insufficient memory
    @return     #BCM_ERR_INVAL_PARAMS   aStatus is NULL
                                        or aStatus->hdr is NULL
                                        or aStatus->mode is invalid

    @post TBD

    @trace #BRCM_SWREQ_IMGL

    @limitations This API shall be called from the task context.
*/
extern int32_t IMGL_GetStatus(IMGL_LoadStatusType *const aStatus);

/** @brief Get configuration data

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aImgID      Image ID
    @param[out]     aSize       Size of the image (valid only when return value
                                is not NULL)

    @return     Buffer pointer

    @post None

    @trace #BRCM_SWREQ_IMGL

    @limitations This API shall be called from the task context. This API also
    assumes that all APIs in  IMGL Osil are invoked from highest priority task
    in the system
*/
/*  @event         MISRA C-2012 Rule 5.8, MISRA C-2012 Rule 8.3
    @issue         Identifier IMGL_GetCfg is already used to represent a function\
                   with external linkage. Symbol IMGL_GetCfg is declared more than once.
    @risk          Undefined behaviour.
    @justification Issue reported due to Coverity build configuration.\
                   Issue at definition in test file (code.c). */
/* coverity[misra_c_2012_rule_5_8_violation] */
/* coverity[misra_c_2012_rule_8_3_violation] */
extern const uint8_t* IMGL_GetCfg(uint16_t aImgID, uint32_t * const aSize);

/**
    @name Image version comparasion result type
    @{
    @brief Image version comparasion result type

    @trace #BRCM_SWREQ_IMGL
*/
typedef int32_t IMGL_VerCmpResultType;  /**< @brief Load Mode Type         */
#define IMGL_VER_CMP_RESULT_UNKNOWN  (-2L) /**< @brief Unknown             */
#define IMGL_VER_CMP_RESULT_LOWER    (-1L) /**< @brief Lower version       */
#define IMGL_VER_CMP_RESULT_MATCH    (0L)  /**< @brief Matched version     */
#define IMGL_VER_CMP_RESULT_HIGHER   (1L)  /**< @brief Higher version      */
/** @} */


/** @brief Version comparision

    Compares the aNewVersion w.r.t to aOldVersion.

   @behavior Sync, Non-reentrant

   @pre None

   @param[in]       aNewVersion          Pointer to new version
   @param[in]       aOldVersion          Pointer to old version

   Return values are documented in reverse-chronological order
   @return     #IMGL_VER_CMP_RESULT_MATCH             (aNewVersion is match with aOldVersion) or
                                                      (aNewVersion is NULL and aOldVersion is NULL) or
                                                      (aNewVersion is not valid and aOldVersion is not valid)
   @return     #IMGL_VER_CMP_RESULT_LOWER             (aNewVersion is lower compared to aOldVersion) or
                                                      (aNewVersion is NULL) or
                                                      (aNewVersion is not valid)
   @return     #IMGL_VER_CMP_RESULT_HIGHER            (aNewVersion is higher compared to aOldVersion) or
                                                      (aOldVersion is NULL) or
                                                      (aOldVersion is not valid)
   @return     #IMGL_VER_CMP_RESULT_UNKNOWN           (aNewVersion tag is not same as aOldVersion tag)

   @post None

   @trace  #BRCM_SWREQ_IMGL
*/
IMGL_VerCmpResultType IMGL_VersionCompare(const IMGL_VersionType* const aNewVersion,
                                          const IMGL_VersionType* const aOldVersion);

/** @brief Version compatibility check

    Compatability of aVersion2 w.r.t to aVersion1

   @behavior Sync, Non-reentrant

   @pre None

   @param[in]       aVersion1            Pointer to version 1
   @param[in]       aVersion2            Pointer to version 2


   Return values are documented in reverse-chronological order
   @retval     #BCM_ERR_OK             aVersion2 is compatible with aVersion1
   @retval     #BCM_ERR_NOSUPPORT      aVersion2 is not compatible with aVersion1
   @retval     #BCM_ERR_INVAL_PARAMS   (aVersion1 is NULL) or
                                       (aVersion2 is NULL)

   @post None

   @trace  #BRCM_SWREQ_IMGL
*/
int32_t IMGL_IsVersionCompatible(const IMGL_VersionType* const aVersion1,
                                 const IMGL_VersionType* const aVersion2);

/** @brief Get Build version information

    This API retrieves the build version information.

    @behavior Sync, Re-entrant

    @pre None

    @param[out]      aVersionInfo    Pointer to buffer
    @param[inout]    aSize           in: Size of aVersionInfo
                                     out: Size of the filled buffer

    @return      void

    @post None

    @trace #BRCM_SWREQ_IMGL

    @limitations This API shall be called only in firmware
*/
extern void IMGL_GetVersionInfo(char *const aVersionInfo, uint32_t *const aSize);

#endif /* SYSTEM_IMGL_H */
/** @} */
