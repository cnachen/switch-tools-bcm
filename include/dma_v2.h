/*****************************************************************************
 Copyright 2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_dma_v2_ifc Interface
    @ingroup grp_dma_v2

    @addtogroup grp_dma_v2_ifc
    @{
    @file dma_v2.h

    @brief DMA V2 Interface

    @version 0.1 Initial revision
*/
#ifndef DMA_V2_H
#define DMA_V2_H

#include <stddef.h>
#include <inttypes.h>
#include <compiler.h>
#include <bcm_comp.h>
#include <bcm_err.h>

/**
    @name DMA V2 Architecture IDs
    @{
    @brief Architecture IDs for DMA V2
*/
#define BRCM_SWARCH_DMA_MAX_NUM_XFER_REQ_MACRO  (0x8000U) /**< @brief #DMA_MAX_NUM_XFER_REQ */
#define BRCM_SWARCH_DMA_XFER_REQ_TYPE           (0x8001U) /**< @brief #DMA_XferReqType      */
#define BRCM_SWARCH_DMA_INIT_PROC               (0x8002U) /**< @brief #DMA_Init             */
#define BRCM_SWARCH_DMA_START_XFER_PROC         (0x8003U) /**< @brief #DMA_StartXfer        */
#define BRCM_SWARCH_DMA_START_XFER_PRIV_PROC    (0x8004U) /**< @brief #DMA_StartXferPriv    */
#define BRCM_SWARCH_DMA_GET_XFER_STATUS_PROC    (0x8005U) /**< @brief #DMA_GetXferStatus    */
#define BRCM_SWARCH_DMA_DEINIT_PROC             (0x8006U) /**< @brief #DMA_Deinit           */
/** @} */

/**
    @brief Maximum number of Xfer requests supported by @ref DMA_StartXfer and @ref DMA_StartXferPriv APIs

    @trace #BRCM_SWREQ_DMA_V2_KERNEL_INTERFACE
 */
#define DMA_MAX_NUM_XFER_REQ                 (9UL)

/**
    @brief DMA Transfer data structure

    @trace #BRCM_SWREQ_DMA_V2_KERNEL_INTERFACE
*/
typedef struct sDMA_XferReqType {
    uint32_t srcAddr;     /**< source address */
    uint32_t dstAddr;     /**< destination address */
    uint32_t rowSize;     /**< DMA transfer size in bytes */
    uint32_t numRows;     /**< Number of rows to be transferred */
    uint32_t srcAddrInc;  /**< Source address increment in bytes */
    uint32_t dstAddrInc;  /**< Destination address increment in bytes */
} DMA_XferReqType;

/** @brief Initialize the DMA instance

    @behavior Sync, reentrant

    @pre DMA instance not initialized

    @param[in]   aHwId    DMA Instance number

    @retval     #BCM_ERR_OK           Init successful
    @retval     #BCM_ERR_INVAL_PARAMS aHwId invalid
    @retval     #BCM_ERR_INVAL_STATE  Already initialized

    @post if successful, DMA instance initialized

    @trace #BRCM_SWREQ_DMA_V2_DRIVER

    @limitations None
*/
int32_t DMA_Init(uint32_t aHwId);

/** @brief Start a DMA transfer, issuer is executing in the un-privilaged CPU mode

    @behavior Sync, reentrant

    @pre DMA instance initalized

    @param[in]   aHwId    DMA Instance number
    @param[in]   aXferReq List of transfer requests
                          Cannot be greater than @ref DMA_MAX_NUM_XFER_REQ
    @param[in]   aNumReq  Number of transfer requests
    @param[out]  aJobHdl  Job handler for this transfer

    @retval     #BCM_ERR_OK           Transfer started successfully
    @retval     #BCM_ERR_UNINIT       Driver Not initialized
    @retval     #BCM_ERR_INVAL_PARAMS aHwId or aXferReq or aNumReq is invalid
    @retval     #BCM_ERR_INVAL_STATE  If the issuer is not executing in the
                                      un-privilaged CPU mode
    @retval     #BCM_ERR_NOSUPPORT    Given request is not supported in this
                                      platform
    @retval     #BCM_ERR_NOMEM        No free channels to start this DMA request

    @post if successful, DMA transfer started

    @trace #BRCM_SWREQ_DMA_V2_KERNEL_HANDLER

    @limitations None
*/
int32_t DMA_StartXfer(uint32_t aHwId,
                      DMA_XferReqType const *const aXferReq,
                      uint32_t aNumReq,
                      BCM_HandleType *const aJobHdl);

/** @brief Start a DMA transfer, issuer is excuting in the privilaged CPU mode

    @behavior Sync, reentrant

    @pre DMA instance initalized

    @param[in]   aHwId          DMA Instance number
    @param[in]   aCompId        Component ID of the SW issuing the Xfer request
    @param[in]   aEnableNotif   Set to 1 if the component wishes to get a callback
                                notification on the DMA Xfer completion
    @param[in]   aXferReq       List of transfer requests
                                Cannot be greater than @ref DMA_MAX_NUM_XFER_REQ
    @param[in]   aNumReq        Number of transfer requests
    @param[out]  aJobHdl        Job handler for this transfer

    @retval     #BCM_ERR_OK           Transfer started successfully
    @retval     #BCM_ERR_UNINIT       Driver Not initialized
    @retval     #BCM_ERR_INVAL_PARAMS aHwId or aXferReq or aNumReq or aCompId is invalid
    @retval     #BCM_ERR_INVAL_STATE  If the issuer is not executing in the
                                      privilaged CPU mode
    @retval     #BCM_ERR_NOSUPPORT    Given request is not supported in this
                                      platform
    @retval     #BCM_ERR_NOMEM        No free channels to start this DMA request

    @post if successful, DMA transfer started

    @trace #BRCM_SWREQ_DMA_V2_KERNEL_HANDLER

    @limitations None
*/
int32_t DMA_StartXferPriv(uint32_t aHwId,
                          BCM_CompIDType aCompId,
                          uint32_t aEnableNotif,
                          DMA_XferReqType const *const aXferReq,
                          uint32_t aNumReq,
                          BCM_HandleType *const aJobHdl);

/** @brief Get DMA transfer status

    @behavior Sync, reentrant

    @pre DMA transfer already started

    @param[in]   aHwId    DMA Instance number
    @param[in]   aJobHdl  DMA transfer job handle returned by the DMA_StartXfer()

    @retval     #BCM_ERR_OK     DMA transfer completed successfully
    @retval     #BCM_ERR_BUSY   DMA transfer in progress
    @retval     #BCM_ERR_INVAL_PARAMS aHwId or aJobHdl is invalid
    @retval     #BCM_ERR_UNINIT Driver Not initialized

    @post None

    @trace #BRCM_SWREQ_DMA_V2_KERNEL_HANDLER

    @limitations None
*/
int32_t DMA_GetXferStatus(uint32_t aHwId, BCM_HandleType aJobHdl);

/** @brief Deinitialize the DMA instance

    @behavior Sync, reentrant

    @pre DMA instance is initialized

    @param[in]  aHwId    DMA Instance number

    @retval     #BCM_ERR_OK           Deinit successful
    @retval     #BCM_ERR_INVAL_PARAMS aHwId invalid
    @retval     #BCM_ERR_UNINIT       Not initialized
    @retval     #BCM_ERR_BUSY         Transfer in progress

    @post if successful, DMA instance de-initialized

    @trace #BRCM_SWREQ_DMA_V2_DRIVER

    @limitations None
*/
int32_t DMA_Deinit(uint32_t aHwId);

#endif /* DMA_V2_H */

/** @} */
