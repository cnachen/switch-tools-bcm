/*****************************************************************************
 Copyright 2020-2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_imgl_mmap_ifc Memory Mapped Loader
    @ingroup grp_imgl

    @addtogroup grp_imgl_mmap_ifc
    @{

    @limitations None

    @file imgl_mmap.h

    @brief Memory mapped Image Loader interface function headers

    This file contains the interface function definitions for Memory mapped loader

    @version 0.1 initial version
*/
#ifndef IMGL_MMAP_H
#define IMGL_MMAP_H

#include <stdint.h>
#include <system_imgl_interface.h>

/**
    @name IMGL Memory Map Modules Architecture IDs
    @{
    @brief Architecture IDs for IMGL Memory Map Modules
*/
#define BRCM_SWARCH_IMGL_MMAP_0_GLOBAL              (0x8501U)    /**< @brief #IMGL_Mmap0               */
#define BRCM_SWARCH_IMGL_MMAP_1_GLOBAL              (0x8502U)    /**< @brief #IMGL_Mmap1               */
#define BRCM_SWARCH_IMGL_MMAP_SERVER_TASK_FUN_PROC  (0x8503U)    /**< @brief #IMGL_MmapServer_TaskFunc */
/** @} */

/** @brief IMGL memory map 0

    @trace  #BRCM_SWREQ_IMGL_CORE
*/
#if defined(IMGL_MMAP_SIZE_0) && (IMGL_MMAP_SIZE_0 > 0)
extern uint8_t IMGL_Mmap0[IMGL_MMAP_SIZE_0];
#endif /* IMGL_MMAP_SIZE_0 */

/** @brief IMGL memory map 1

    @trace  #BRCM_SWREQ_IMGL_CORE
*/
#if defined(IMGL_MMAP_SIZE_1) && (IMGL_MMAP_SIZE_1 > 0)
extern uint8_t IMGL_Mmap1[IMGL_MMAP_SIZE_1];
#endif /* IMGL_MMAP_SIZE_1 */

/** @brief IMGL Memory Map task function

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      void

    @retval     void

    @post None

    @trace #BRCM_SWREQ_IMGL_CORE

    @limitations This function only be called as Task.
*/
#ifdef ENABLE_IMGL_MMAP_ASYNC_MODE
void IMGL_MmapServer_TaskFunc(void);
#endif /* ENABLE_IMGL_MMAP_ASYNC_MODE */

#endif /* IMGL_MMAP_H */
/** @} */
