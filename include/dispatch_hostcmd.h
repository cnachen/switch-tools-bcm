/*****************************************************************************
 Copyright 2021 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_rpc_host_cmd Host Command Service
    @ingroup grp_rpc_v2

    @defgroup grp_rpc_host_cmd_ifc Host Command Interface
    @ingroup grp_rpc_host_cmd

    @addtogroup grp_rpc_host_cmd_ifc
    @{

    @file dispatch_hostcmd.h
    @brief DISPATCH Command Service Interface

    @version 0.1 Initial Version
*/

#ifndef DISPATCH_HOSTCMD_H
#define DISPATCH_HOSTCMD_H

#include <bcm_err.h>
#include <module.h>

/**
    @name Architecture IDs
    @{
    @brief Architecture IDs for DISPATCH Host command interface
*/
#define BRCM_SWARCH_DISPATCH_RPCSERVICE_GLOBAL            (0x8000U)  /**< @brief #DISPATCH_RPCService         */
#define BRCM_SWARCH_DISPATCH_NVMSERVICE_GLOBAL            (0x8001U)  /**< @brief #DISPATCH_NVMService         */
#define BRCM_SWARCH_DISPATCH_IPCMODULE_GLOBAL             (0x8002U)  /**< @brief #DISPATCH_IPCModule          */
#define BRCM_SWARCH_DISPATCH_UPDMODULE_GLOBAL             (0x8003U)  /**< @brief #DISPATCH_UPDModule          */
#define BRCM_SWARCH_DISPATCH_READTARGETIMG_PROC           (0x8004U)  /**< @brief #DISPATCH_ReadTargetImage    */
#define BRCM_SWARCH_DISPATCH_IMAGEDATA_GLOBAL             (0x8005U)  /**< @brief #DISPATCH_ImageData          */
#define BRCM_SWARCH_DISPATCH_IMAGEDATASIZE_GLOBAL         (0x8006U)  /**< @brief #DISPATCH_ImageDataSize      */
#define BRCM_SWARCH_DISPATCH_IOSERVICE_GLOBAL             (0x8007U)  /**< @brief #DISPATCH_IOService          */
/** @} */

/**
    @brief DISPATCH Host command service to be
    integrated into bcm_rpc_proxy

    @trace #BRCM_SWREQ_DISPATCH_HOST
*/
extern const SERVICE_Type DISPATCH_RPCService;

/**
    @brief DISPATCH Host NVM command service to be
    integrated into bcm_rpc_proxy

    @trace #BRCM_SWREQ_DISPATCH_HOST
*/
extern const SERVICE_Type DISPATCH_NVMService;

/**
    @brief DISPATCH Host IO command service to be
    integrated into bcm_rpc_proxy

    @trace #BRCM_SWREQ_DISPATCH_HOST
*/
extern const SERVICE_Type DISPATCH_IOService;

/**
    @brief DISPATCH Host IPC module

    @trace #BRCM_SWREQ_DISPATCH_HOST
*/
extern const MODULE_Type DISPATCH_IPCModule;

/**
    @brief DISPATCH Host NVM module

    @trace #BRCM_SWREQ_DISPATCH_HOST
*/
const MODULE_Type DISPATCH_UPDModule;

/**
    @brief Memory to store the file image

    @trace #BRCM_SWREQ_DISPATCH_HOST
*/
extern uint8_t DISPATCH_ImageData[5UL * 1024UL * 1024UL];

/**
    @brief Size of the file image in bytes

    @trace #BRCM_SWREQ_DISPATCH_HOST
*/
extern uint32_t DISPATCH_ImageDataSize;

/**
    @brief Fetch image using file/socket

    @trace #BRCM_SWREQ_DISPATCH_HOST
*/
int32_t DISPATCH_ReadTargetImage(char *aFileName,
                                 uint32_t aServerIP,
                                 uint16_t aServerPort,
                                 uint32_t aExpectedFileSize,
                                 uint8_t *aBuff,
                                 uint32_t *aLen);

#endif /* DISPATCH_HOSTCMD_H */
/** @} */
