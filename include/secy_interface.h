/*****************************************************************************
 Copyright 2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_secy_app_ifc Interface
    @ingroup grp_secy_app

    @addtogroup grp_secy_app_ifc
    @{
*/
#ifndef SECY_INTERFACE_H
#define SECY_INTERFACE_H

/**
    @name SecY application Architecture IDs
    @{
    @brief Architecture IDs for SecY application

*/
#define BRCM_SWARCH_SECY_APP_CONFIG_MAX_COUNT_MACRO    (0x8101U)   /**< @brief #SECY_APP_CONFIG_MAX_COUNT */
#define BRCM_SWARCH_SECY_APP_MAX_KEY_COUNT_MACRO       (0x8102U)   /**< @brief #SECY_APP_MAX_KEY_COUNT    */
#define BRCM_SWARCH_SECY_APPCONFIG_TYPE                (0x8103U)   /**< @brief #SECY_AppConfigType        */
#define BRCM_SWARCH_SECY_CONFIG_PROC                   (0x8104U)   /**< @brief #SECY_Config               */
#define BRCM_SWARCH_SECY_HOSTGETFULLSTATS_PROC         (0x8105U)   /**< @brief #SECY_HostGetFullStats     */
#define BRCM_SWARCH_SECY_HOSTGETPN_PROC                (0x8106U)   /**< @brief #SECY_HostGetPN            */
/** @} */

/**
    @brief Macro to define maximum no of configs are supported

    This macro will be used to validate the maximum number of
    configs supported by this application

    @trace #BRCM_SWREQ_SECY_APP
*/
#define SECY_APP_CONFIG_MAX_COUNT        (3U)

/**
    @brief Macro to define maximum no of keys are supported

    This macro will be used to validate the maximum number of\
    keys supported by this application

    @trace #BRCM_SWREQ_SECY_APP
*/
#define SECY_APP_MAX_KEY_COUNT           (4U)

/**
    @brief Config structure of the application

    This structure is the minimum requirement for this application to run

    @trace #BRCM_SWREQ_SECY_APP
 */
typedef struct sSECY_AppConfigType {
    SECY_CipherType     ciper;          /**< @brief Crypto EUI-64 cipher id  */
    SECY_CipherCapType  ciperCap;       /**< @brief Cipher capabilites       */
    SECY_ConfOffsetType confiOffset;    /**< @brief Confidentiality Offset   */
    uint32_t            keyNum;         /**< @brief SA Key ID                */
    uint32_t            explicitSCI;    /**< @brief Explicit SCI             */
    uint8_t             rxSciMac[6U];   /**< @brief RXSci Mac Address        */
    uint8_t             rsvd[2U];       /**< @brief Reserved                 */
    uint8_t             txSciMac[6U];   /**< @brief TXSci Mac Address        */
    uint8_t             rsvd1[2U];      /**< @brief Reserved                 */
} SECY_AppConfigType;

/**
    @brief Config SecY

    Interface to configure the secY on given aPortNum with aConfigNum
    and aAppCfg

    @behavior Async, Non-Rentrant

    @pre SDK booted and running

    @param[in]      aConnHdl           RPC Connection handle
    @param[in]      aPortNum           Port number to run the SecY
    @param[in]      aConfigNum         Config number to be used for SecY
    @param[in]      aAppCfg            User configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aAppCfg is NULL or
                                         aConfigNum is Invalid or
                                         aAppCfg is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY_APP

    @limitations None
*/
extern int32_t SECY_Config(BCM_HandleType *aConnHdl,
                            uint32_t aPortNum,
                            uint32_t aConfigNum,
                            const SECY_AppConfigType *const aAppCfg);


/**
    @brief Retrive the Full stats

    Interface to retrive the full stats from secY

    @behavior Async, Non-Rentrant

    @pre SDK booted and running

    @param[in]      aConnHdl          RPC Connection handle
    @param[out]     aStats            Full stats of secY


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aStats is NULL

    @post None

    @trace #BRCM_SWREQ_SECY_APP

    @limitations None
*/
extern int32_t SECY_HostGetFullStats(BCM_HandleType aConnHdl, SECY_AllStatsType *const aStats);

/**
    @brief Retrive the PN

    Interface to retrive the TxSA PN ans RxSA Next PN

    @behavior Async, Non-Rentrant

    @pre SDK booted and running

    @param[in]      aConnHdl          RPC Connection handle
    @param[out]     aTxSAPn           TxSA PN number
    @param[out]     aRxSAPn           RxSA PN number


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aTxSAPn is NULL or
                                         aRxSAPn is NULL

    @post None

    @trace #BRCM_SWREQ_SECY_APP

    @limitations None
*/
extern int32_t SECY_HostGetPN(BCM_HandleType aConnHdl, uint64_t *const aTxSAPn,
                                     uint64_t *const aRxSAPn);
#endif /* SECY_INTERFACE_H */
/** @} */
