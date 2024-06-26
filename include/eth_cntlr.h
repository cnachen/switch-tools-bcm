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
    @defgroup grp_eth_cntlrdrv_cntlr_ifc Ethernet Controller Interface
    @ingroup grp_eth_cntlrdrv

    @addtogroup grp_eth_cntlrdrv_cntlr_ifc
    @{

    @file ethernet/drivers/controller/inc/eth_cntlr.h
    @brief Ethernet Driver interface
    This header file contains the interface functions for Ethernet Controller

    @version 1.26 Imported from docx
*/

#ifndef ETH_CNTLR_H
#define ETH_CNTLR_H

#include <ethernet.h>



/**
    @name Ethernet Controller  API IDs
    @{
    @brief API IDs for Ethernet controller driver
*/
#define BRCM_SWARCH_ETHER_STATE_TYPE                            (0x8301U)    /**< @brief #ETHER_StateType                    */
#define BRCM_SWARCH_ETHER_CHANSTATE_TYPE                        (0x8302U)    /**< @brief #ETHER_ChanStateType                */
#define BRCM_SWARCH_ETHER_CLIENTBUFIDX2CHANIDXMASK_MACRO        (0x830AU)    /**< @brief #ETHER_CLIENTBUFIDX2CHANIDXMASK     */
#define BRCM_SWARCH_ETHER_CLIENTBUFIDX2CHANIDXSHIFT_MACRO       (0x830BU)    /**< @brief #ETHER_CLIENTBUFIDX2CHANIDXSHIFT    */
#define BRCM_SWARCH_ETHER_CLIENTBUFIDX2CHANBUFIDXMASK_MACRO     (0x830CU)    /**< @brief #ETHER_CLIENTBUFIDX2CHANBUFIDXMASK  */
#define BRCM_SWARCH_ETHER_CLIENTBUFIDX2CHANBUFIDXSHIFT_MACRO    (0x830DU)    /**< @brief #ETHER_CLIENTBUFIDX2CHANBUFIDXSHIFT */
#define BRCM_SWARCH_ETHER_CLIENTBUFIDX2CHANIDX_MACRO            (0x830EU)    /**< @brief #ETHER_CLIENTBUFIDX2CHANIDX         */
#define BRCM_SWARCH_ETHER_CLIENTBUFIDX2CHANBUFIDX_MACRO         (0x830FU)    /**< @brief #ETHER_CLIENTBUFIDX2CHANBUFIDX      */
#define BRCM_SWARCH_ETHER_GETCLIENTBUFIDX_MACRO                 (0x8310U)    /**< @brief #ETHER_GETCLIENTBUFIDX              */
#define BRCM_SWARCH_ETHER_TIMEGETEGRESSTS_PROC                  (0x8311U)    /**< @brief #ETHER_TimeGetEgressTS              */
#define BRCM_SWARCH_ETHER_TIMEGETINGRESSTS_PROC                 (0x8312U)    /**< @brief #ETHER_TimeGetIngressTS             */
#define BRCM_SWARCH_ETHER_SETBRCMHDRMODE_PROC                   (0x8313U)    /**< @brief #ETHER_SetBrcmHdrMode               */
#define BRCM_SWARCH_ETHER_SEEDVALMASK_MACRO                     (0x8317U)    /**< @brief #ETHER_SEEDVALMASK */

#define BRCM_SWARCH_ETHER_SEEDVALSHIFT_MACRO                    (0x8318U)    /**< @brief #ETHER_SEEDVALSHIFT */

#define BRCM_SWARCH_ETHER_ETHERTYPEMASK_MACRO                   (0x8319U)    /**< @brief #ETHER_ETHERTYPEMASK */

#define BRCM_SWARCH_ETHER_ETHERTYPESHIFT_MACRO                  (0x831AU)    /**< @brief #ETHER_ETHERTYPESHIFT */

#define BRCM_SWARCH_ETHER_CLIENTBUFIDXMASK_MACRO                (0x831BU)    /**< @brief #ETHER_CLIENTBUFIDXMASK */

#define BRCM_SWARCH_ETHER_GETCLIENTFINALBUFIDX_MACRO            (0x831CU)    /**< @brief #ETHER_GETCLIENTFINALBUFIDX */

/** @} */

/**
    @name ETHER_StateType
    @{
    @brief States of Ethernet driver

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef uint32_t ETHER_StateType; /**< @brief Ethernet state type */
#define ETHER_STATE_UNINIT  (0UL) /**< @brief Driver uninitialised &
                                        value must be set to zero*/
#define ETHER_STATE_INIT    (1UL) /**< @brief Driver initialised */
/** @} */

/**
    @name ETHER_ChanStateType
    @{
    @brief States of Ethernet driver channels

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef uint32_t ETHER_ChanStateType;   /**< @brief Ethernet channel state type */
#define ETHER_CHANSTATE_UNINIT          (0UL)   /**< @brief Uninitialised state */
#define ETHER_CHANSTATE_INIT            (1UL)   /**< @brief Initialised State */
/** @} */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_CLIENTBUFIDX2CHANIDXMASK      (0x000000F0UL) /**< @brief Ethernet Client buffer index to channel index mask */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_CLIENTBUFIDX2CHANIDXSHIFT     (4UL)          /**< @brief Ethernet Client buffer index to channel index shift */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_CLIENTBUFIDX2CHANBUFIDXMASK   (0x0000000FUL) /**< @brief Ethernet Client buffer index to channel buffer index mask */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_CLIENTBUFIDX2CHANBUFIDXSHIFT  (0UL)          /**< @brief Ethernet Client buffer index to channel buffer index shift */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_SEEDVALMASK                   (0xFFFF00000000ULL)  /**< @brief Ethernet Client buffer Seed Val mask */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_SEEDVALSHIFT                  (32ULL)          /**< @brief Ethernet Client buffer Seed Val shift */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_ETHERTYPEMASK                 (0xFFFF0000ULL)  /**< @brief Ethernet Client buffer ethertype mask */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_ETHERTYPESHIFT                (16ULL)   /**< @brief Ethernet Client buffer ether type shift */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_CLIENTBUFIDXMASK              (0xFFFFULL)  /**< @brief Ethernet Client buffer index mask */


/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_CLIENTBUFIDX2CHANIDX(aIdx)        \
    (uint32_t)(((aIdx) & ETHER_CLIENTBUFIDX2CHANIDXMASK)  \
     >> ETHER_CLIENTBUFIDX2CHANIDXSHIFT)        /**< @brief Ethernet client buffer index to channel index */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_CLIENTBUFIDX2CHANBUFIDX(aIdx)             \
    (uint32_t)(((aIdx) & ETHER_CLIENTBUFIDX2CHANBUFIDXMASK)       \
     >> ETHER_CLIENTBUFIDX2CHANBUFIDXSHIFT)     /**< @brief Ethernet Client buffer index to channel buffer index */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_GETCLIENTBUFIDX(aChan, aBufIdx)           \
    ((((uint64_t)(aChan) << ETHER_CLIENTBUFIDX2CHANIDXSHIFT)      \
      & ETHER_CLIENTBUFIDX2CHANIDXMASK)                \
      | (((aBufIdx) & ETHER_CLIENTBUFIDX2CHANBUFIDXMASK))) /**< @brief Ethernet get client buffer index */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_GETCLIENTFINALBUFIDX(aBufIdx,etherType,seedVal)           \
    (((((uint64_t)(seedVal) << ETHER_SEEDVALSHIFT) & ETHER_SEEDVALMASK)) \
      | ((((uint64_t)(etherType) << ETHER_ETHERTYPESHIFT) & ETHER_ETHERTYPEMASK)) \
      | (((aBufIdx) & ETHER_CLIENTBUFIDXMASK))) /**< @brief Ethernet get client buffer index */




/**
    @trace #BRCM_SWREQ_ETHER_TIME
*/
extern int32_t ETHER_TimeGetEgressTS(uint32_t aID,
                                     uint32_t aPortIdx,
                                     uint32_t aBufIdx,
                                     ETHER_TimestampType* const aFreeTS,
                                     ETHER_TimestampQualType* const aFreeTSQual,
                                     ETHER_TimestampType* const aDomainTS,
                                     ETHER_TimestampQualType* const aDomainTSQual);

/**
    @trace #BRCM_SWREQ_ETHER_TIME
*/
extern int32_t ETHER_TimeGetIngressTS(uint32_t aID,
                                      uint32_t aPortIdx,
                                      const uint8_t* const aPktBuf,
                                      ETHER_TimestampType* const aFreeTS,
                                      ETHER_TimestampQualType* const aFreeTSQual,
                                      ETHER_TimestampType* const aDomainTS,
                                      ETHER_TimestampQualType* const aDomainTSQual);

/**
    @trace #BRCM_SWREQ_ETHER_TIME
*/
extern void ETHER_SetBrcmHdrMode(uint32_t aPortIdx, BCM_BoolType aMode);

#endif /* ETH_CNTLR_H */
/** @} */
