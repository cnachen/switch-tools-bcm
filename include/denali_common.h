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
    @defgroup grp_xcvr_denali_common_imp DENALI Driver common Interface
    @ingroup grp_denali_phy

    @addtogroup grp_xcvr_denali_common_imp
    @{

    @file denali_common.h
*/

#ifndef DENALI_COMMON_H
#define DENALI_COMMON_H

#include <xcvr_common.h>
#include <xcvr_functbl.h>

/**
    @name DENALI API IDs
    @{
    @brief API IDs for DENALI driver
*/
#define BRCM_SWARCH_DENALI_BUS_READ_PROC                        (0x8801U) /**< @brief #DENALI_BusRead            */
#define BRCM_SWARCH_DENALI_BUS_WRITE_PROC                       (0x8802U) /**< @brief #DENALI_BusWrite           */
#define BRCM_SWARCH_DENALI_IS_SUPPORTED_PROC                    (0x8803U) /**< @brief #DENALI_IsSupported        */
#define BRCM_SWARCH_DENALI_CHECK_ERR_MACRO                      (0x8804U) /**< @brief #DENALI_CHECK_ERR          */
#define BRCM_SWARCH_DENALI_CHECK_ERR_VOID_RETURN_MACRO          (0x8805U) /**< @brief #DENALI_CHECK_ERR_VOID_RETURN */
#define BRCM_SWARCH_DENALI_BUS_READ_WRITE_PROC                  (0x8806U) /**< @brief #DENALI_BusReadWrite       */
#define BRCM_SWARCH_DENALI_MISC_TEMP_THRESH_HIGH_REG_TYPE       (0x8807U) /**< @brief #DENALI_MISC_TEMP_THRESH_HIGH_REG_TYPE     */
#define BRCM_SWARCH_DENALI_MISC_TEMP_THRESH_LOW_REG_TYPE        (0x8808U) /**< @brief #DENALI_MISC_TEMP_THRESH_LOW_REG_TYPE      */
#define BRCM_SWARCH_DENALI_MISC_V1P0_DATA_REG_TYPE              (0x8809U) /**< @brief #DENALI_MISC_V1P0_DATA_REG_TYPE            */
#define BRCM_SWARCH_DENALI_MISC_V1P0_THRESH_HIGH_REG_TYPE       (0x880AU) /**< @brief #DENALI_MISC_V1P0_THRESH_HIGH_REG_TYPE     */
#define BRCM_SWARCH_DENALI_MISC_V1P0_THRESH_LOW_REG_TYPE        (0x880BU) /**< @brief #DENALI_MISC_V1P0_THRESH_LOW_REG_TYPE      */
#define BRCM_SWARCH_DENALI_MISC_V1P8_DATA_REG_TYPE              (0x880CU) /**< @brief #DENALI_MISC_V1P8_DATA_REG_TYPE            */
#define BRCM_SWARCH_DENALI_MISC_V1P8_THRESH_HIGH_REG_TYPE       (0x880DU) /**< @brief #DENALI_MISC_V1P8_THRESH_HIGH_REG_TYPE     */
#define BRCM_SWARCH_DENALI_MISC_V1P8_THRESH_LOW_REG_TYPE        (0x880EU) /**< @brief #DENALI_MISC_V1P8_THRESH_LOW_REG_TYPE      */
#define BRCM_SWARCH_DENALI_MISC_V3P3_2P5_DATA_REG_TYPE          (0x880FU) /**< @brief #DENALI_MISC_V3P3_2P5_DATA_REG_TYPE        */
#define BRCM_SWARCH_DENALI_MISC_V3P3_2P5_THRESH_HIGH_REG_TYPE   (0x8810U) /**< @brief #DENALI_MISC_V3P3_2P5_THRESH_HIGH_REG_TYPE */
#define BRCM_SWARCH_DENALI_MISC_V3P3_2P5_THRESH_LOW_REG_TYPE    (0x8811U) /**< @brief #DENALI_MISC_V3P3_2P5_THRESH_LOW_REG_TYPE  */
#define BRCM_SWARCH_DENALI_MISC_VTMON_INTR_REG_TYPE             (0x8812U) /**< @brief #DENALI_MISC_VTMON_INTR_REG_TYPE           */
#define BRCM_SWARCH_DENALI_VTMON_TYPE                           (0x8813U) /**< @brief #DENALI_VTMonType                          */
#define BRCM_SWARCH_DENALI_MISC_LED_INTR_CTRL_REG_TYPE          (0x8814U) /**< @brief #DENALI_MISC_LED_INTR_CTRL_REG_TYPE        */
#define BRCM_SWARCH_DENALI_MISC_VTMON_CNTRL_REG_TYPE            (0x8815U) /**< @brief #DENALI_MISC_VTMON_CNTRL_REG_TYPE          */
#define BRCM_SWARCH_DENALI_MISC_TEMP_DATA_REG_TYPE              (0x8816U) /**< @brief #DENALI_MISC_TEMP_DATA_REG_TYPE            */
#define BRCM_SWARCH_DENALI_GET_HEALTHINFO_PROC                  (0x8817U) /**< @brief #DENALI_GetHealthInfo                      */
/** @} */

/**
    @brief Return value Error check

    @trace #BRCM_SWREQ_DENALI
*/
#define DENALI_CHECK_ERR(ret, data)                     \
    if ((BCM_ERR_OK != (ret))) {                        \
        BCM_LOG_ERROR(0U, (uint32_t)BCM_STATE_READY, ret, data);  \
        return ret;}

/**
    @brief Return value Error check

    @trace #BRCM_SWREQ_DENALI
*/
#define DENALI_CHECK_ERR_VOID_RETURN(ret, data)         \
    if ((BCM_ERR_OK != (ret))) {                        \
        BCM_LOG_ERROR(0U, (uint32_t)BCM_STATE_READY, ret, data);  \
        return ;}


/**
    @name DENALI_MISC_VTMON_CNTRL_REG_TYPE
    @{
    @brief VTMON Control Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_VTMON_CNTRL_REG_TYPE;
#define DENALI_MISC_VTMON_CNTRL_REG_VTMON_SEL_MASK (0xEU)
#define DENALI_MISC_VTMON_CNTRL_REG_VTMON_SEL_VTMON_ALL_MON_MASK (0x4U)
#define DENALI_MISC_VTMON_CNTRL_REG_VTMON_SEL_SHIFT (1U)
#define DENALI_MISC_VTMON_CNTRL_REG_PWRDN_MASK (0x1U)
#define DENALI_MISC_VTMON_CNTRL_REG_PWRDN_SHIFT (0U)
#define DENALI_MISC_VTMON_CNTRL_REG_CL45_ADDR (0x0771U)
/** @} */

/**
    @name DENALI_MISC_TEMP_DATA_REG_TYPE
    @{
    @brief Temperature Monitor Value

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_TEMP_DATA_REG_TYPE;
#define DENALI_MISC_TEMP_DATA_REG_VTMON_PHY_PWRDN_STS_MASK (0x8000U)
#define DENALI_MISC_TEMP_DATA_REG_VTMON_PHY_PWRDN_STS_SHIFT (15U)
#define DENALI_MISC_TEMP_DATA_REG_TEMP_DATA_MASK (0x3FFU)
#define DENALI_MISC_TEMP_DATA_REG_TEMP_DATA_SHIFT (0U)
#define DENALI_MISC_TEMP_DATA_REG_CL45_ADDR (0x0772U)
/** @} */

/**
    @name DENALI_MISC_TEMP_THRESH_HIGH_REG_TYPE
    @{
    @brief Temperature Monitor High Threshold Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_TEMP_THRESH_HIGH_REG_TYPE;
#define DENALI_MISC_TEMP_THRESH_HIGH_REG_MASK (0x3FFU)
#define DENALI_MISC_TEMP_THRESH_HIGH_REG_SHIFT (0U)
#define DENALI_MISC_TEMP_THRESH_HIGH_REG_CL45_ADDR (0x0773U)
/** @} */

/**
    @name DENALI_MISC_TEMP_THRESH_LOW_REG_TYPE
    @{
    @brief Temperature Monitor Low Threshold Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_TEMP_THRESH_LOW_REG_TYPE;
#define DENALI_MISC_TEMP_THRESH_LOW_REG_MASK (0x3FFU)
#define DENALI_MISC_TEMP_THRESH_LOW_REG_SHIFT (0U)
#define DENALI_MISC_TEMP_THRESH_LOW_REG_CL45_ADDR (0x0774U)
/** @} */

/**
    @name DENALI_MISC_V1P0_DATA_REG_TYPE
    @{
    @brief Voltage Monitor 1.0V Value

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V1P0_DATA_REG_TYPE;
#define DENALI_MISC_V1P0_DATA_REG_V1P0_DATA_MASK (0x7FFU)
#define DENALI_MISC_V1P0_DATA_REG_V1P0_DATA_SHIFT (0U)
#define DENALI_MISC_V1P0_DATA_REG_CL45_ADDR (0x0775U)
/** @} */

/**
    @name DENALI_MISC_V1P0_THRESH_HIGH_REG_TYPE
    @{
    @brief Voltage Monitor 1.0V High Threshold Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V1P0_THRESH_HIGH_REG_TYPE;
#define DENALI_MISC_V1P0_THRESH_HIGH_REG_V1P0_THRESH_HIGH_MASK (0x7FFU)
#define DENALI_MISC_V1P0_THRESH_HIGH_REG_V1P0_THRESH_HIGH_SHIFT (0U)
#define DENALI_MISC_V1P0_THRESH_HIGH_REG_CL45_ADDR (0x0776U)
/** @} */

/**
    @name DENALI_MISC_V1P0_THRESH_LOW_REG_TYPE
    @{
    @brief Voltage Monitor 1.0V Low Threshold Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V1P0_THRESH_LOW_REG_TYPE;
#define DENALI_MISC_V1P0_THRESH_LOW_REG_V1P0_THRESH_LOW_MASK (0x7FFU)
#define DENALI_MISC_V1P0_THRESH_LOW_REG_V1P0_THRESH_LOW_SHIFT (0U)
#define DENALI_MISC_V1P0_THRESH_LOW_REG_CL45_ADDR (0x0777U)
/** @} */

/**
    @name DENALI_MISC_V1P8_DATA_REG_TYPE
    @{
    @brief Voltage Monitor 1.8V Value

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V1P8_DATA_REG_TYPE;
#define DENALI_MISC_V1P8_DATA_REG_V1P8_DATA_MASK (0xFFFU)
#define DENALI_MISC_V1P8_DATA_REG_V1P8_DATA_SHIFT (0U)
#define DENALI_MISC_V1P8_DATA_REG_CL45_ADDR (0x077CU)
/** @} */

/**
    @name DENALI_MISC_V1P8_THRESH_HIGH_REG_TYPE
    @{
    @brief Voltage Monitor 1.8V High Threshold Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V1P8_THRESH_HIGH_REG_TYPE;
#define DENALI_MISC_V1P8_THRESH_HIGH_REG_V1P0_THRESH_HIGH_MASK (0xFFFU)
#define DENALI_MISC_V1P8_THRESH_HIGH_REG_V1P0_THRESH_HIGH_SHIFT (0U)
#define DENALI_MISC_V1P8_THRESH_HIGH_REG_CL45_ADDR (0x077DU)
/** @} */

/**
    @name DENALI_MISC_V1P8_THRESH_LOW_REG_TYPE
    @{
    @brief Voltage Monitor 1.8V Low Threshold Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V1P8_THRESH_LOW_REG_TYPE;
#define DENALI_MISC_V1P8_THRESH_LOW_REG_V1P0_THRESH_LOW_MASK (0xFFFU)
#define DENALI_MISC_V1P8_THRESH_LOW_REG_V1P0_THRESH_LOW_SHIFT (0U)
#define DENALI_MISC_V1P8_THRESH_LOW_REG_CL45_ADDR (0x077EU)
/** @} */

/**
    @name DENALI_MISC_V3P3_2P5_DATA_REG_TYPE
    @{
    @brief Voltage Monitor 3.3V/2.5V Value

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V3P3_2P5_DATA_REG_TYPE;
#define DENALI_MISC_V3P3_2P5_DATA_REG_V3P3_2P5_DATA_MASK (0xFFFU)
#define DENALI_MISC_V3P3_2P5_DATA_REG_V3P3_2P5_DATA_SHIFT (0U)
#define DENALI_MISC_V3P3_2P5_DATA_REG_CL45_ADDR (0x0778U)
/** @} */

/**
    @name DENALI_MISC_V3P3_2P5_THRESH_HIGH_REG_TYPE
    @{
    @brief Voltage Monitor 3.3V/2.5V High Threshold Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V3P3_2P5_THRESH_HIGH_REG_TYPE;
#define DENALI_MISC_V3P3_2P5_THRESH_HIGH_REG_V1P0_THRESH_HIGH_MASK (0xFFFU)
#define DENALI_MISC_V3P3_2P5_THRESH_HIGH_REG_V1P0_THRESH_HIGH_SHIFT (0U)
#define DENALI_MISC_V3P3_2P5_THRESH_HIGH_REG_CL45_ADDR (0x0779U)
/** @} */

/**
    @name DENALI_MISC_V3P3_2P5_THRESH_LOW_REG_TYPE
    @{
    @brief Voltage Monitor 3.3V/2.5V Low Threshold Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_V3P3_2P5_THRESH_LOW_REG_TYPE;
#define DENALI_MISC_V3P3_2P5_THRESH_LOW_REG_V1P0_THRESH_LOW_MASK (0xFFFU)
#define DENALI_MISC_V3P3_2P5_THRESH_LOW_REG_V1P0_THRESH_LOW_SHIFT (0U)
#define DENALI_MISC_V3P3_2P5_THRESH_LOW_REG_CL45_ADDR (0x077AU)
/** @} */

/**
    @name DENALI_MISC_VTMON_INTR_REG_TYPE
    @{
    @brief Voltage/Temperature Monitor Interrupt Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_VTMON_INTR_REG_TYPE;
#define DENALI_MISC_VTMON_INTR_REG_V3P3_2P5_INTR_MASK_MASK (0x800U)
#define DENALI_MISC_VTMON_INTR_REG_V3P3_2P5_INTR_MASK_SHIFT (11U)
#define DENALI_MISC_VTMON_INTR_REG_V1P8_INTR_MASK_MASK (0x400U)
#define DENALI_MISC_VTMON_INTR_REG_V1P8_INTR_MASK_SHIFT (10U)
#define DENALI_MISC_VTMON_INTR_REG_V1P0_INTR_MASK_MASK (0x200U)
#define DENALI_MISC_VTMON_INTR_REG_V1P0_INTR_MASK_SHIFT (9U)
#define DENALI_MISC_VTMON_INTR_REG_TEMP_INTR_MASK_MASK (0x100U)
#define DENALI_MISC_VTMON_INTR_REG_TEMP_INTR_MASK_SHIFT (8U)
#define DENALI_MISC_VTMON_INTR_REG_V3P3_2P5_INTR_MASK (0x8U)
#define DENALI_MISC_VTMON_INTR_REG_V3P3_2P5_INTR_SHIFT (3U)
#define DENALI_MISC_VTMON_INTR_REG_VOLT_INTR_MASK (0xEU)
#define DENALI_MISC_VTMON_INTR_REG_V1P8_INTR_MASK (0x4U)
#define DENALI_MISC_VTMON_INTR_REG_V1P8_INTR_SHIFT (2U)
#define DENALI_MISC_VTMON_INTR_REG_V1P0_INTR_MASK (0x2U)
#define DENALI_MISC_VTMON_INTR_REG_V1P0_INTR_SHIFT (1U)
#define DENALI_MISC_VTMON_INTR_REG_TEMP_INTR_MASK (0x1U)
#define DENALI_MISC_VTMON_INTR_REG_TEMP_INTR_SHIFT (0U)
#define DENALI_MISC_VTMON_INTR_REG_CL45_ADDR (0x077BU)
/** @} */

/**
    @name DENALI_MISC_LED_INTR_CTRL_REG
    @{
    @brief LED and INTR CONTROL Register

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_MISC_LED_INTR_CTRL_REG_TYPE;
#define DENALI_MISC_LED_INTR_CTRL_REG_LED4_INTR_SEL_MASK (0x20U)
#define DENALI_MISC_LED_INTR_CTRL_REG_LED4_INTR_SEL_SHIFT (2U)
#define DENALI_MISC_LED_INTR_CTRL_REG_LED1_INTR_SEL_MASK (0x10U)
#define DENALI_MISC_LED_INTR_CTRL_REG_LED1_INTR_SEL_SHIFT (4U)
#define DENALI_MISC_LED_INTR_CTRL_REG_VTMON_INTR_MASK (0x2U)
#define DENALI_MISC_LED_INTR_CTRL_REG_VTMON_INTR_SHIFT (1U)
#define DENALI_MISC_LED_INTR_CTRL_REG_CL45_ADDR (0x0727U)
/** @} */

/**
    @name DENALI_VTMonType
    @{
    @brief Denali VTMON Temp and Volt macros

    @trace #BRCM_SWREQ_DENALI
*/
typedef uint16_t DENALI_VTMonType;
#define DENALI_VTMON_TEMP_MIN                  DENALI_VTMON_TEMP(DENALI_MISC_TEMP_THRESH_LOW_REG_MASK)
#define DENALI_VTMON_TEMP_MAX                  DENALI_VTMON_TEMP(0)
#define DENALI_VTMON_TEMP_BIAS                 (41335000UL)
#define DENALI_VTMON_TEMP_PRESCALE             (49055UL)
#define DENALI_VTMON_TEMP_DIV                  (100000UL)
#define DENALI_VTMON_TEMP(aVal)                ((((int32_t)DENALI_VTMON_TEMP_BIAS - ((int32_t)(aVal) * (int32_t)DENALI_VTMON_TEMP_PRESCALE)) / (int32_t)DENALI_VTMON_TEMP_DIV))
#define DENALI_VTMON_TEMP_TOREG(aVal)          ((((int32_t)DENALI_VTMON_TEMP_BIAS - ((int32_t)(aVal) * (int32_t)DENALI_VTMON_TEMP_DIV)) / (int32_t)DENALI_VTMON_TEMP_PRESCALE))
#define DENALI_VTMON_VOLT_V1P0_MAX             DENALI_VTMON_VOLT_V1P0(DENALI_MISC_V1P0_THRESH_HIGH_REG_V1P0_THRESH_HIGH_MASK)
#define DENALI_VTMON_VOLT_V1P8_MAX             DENALI_VTMON_VOLT_V1P8(DENALI_MISC_V1P8_THRESH_HIGH_REG_V1P0_THRESH_HIGH_MASK)
#define DENALI_VTMON_VOLT_V3P3_2P5_MAX         DENALI_VTMON_VOLT_V3P3_2P5(DENALI_MISC_V3P3_2P5_THRESH_HIGH_REG_V1P0_THRESH_HIGH_MASK)
#define DENALI_VTMON_V1P0_SCALE                (1227U)
#define DENALI_VTMON_V1P8_SCALE                (537U)
#define DENALI_VTMON_V3P3_2P5_SCALE            (1074U)
#define DENALI_VTMON_VOLTAGE_SHIFT             (10U)
#define DENALI_VTMON_VOLT_V1P0(aVal)           (((DENALI_VTMON_V1P0_SCALE * (aVal)) >> DENALI_VTMON_VOLTAGE_SHIFT))
#define DENALI_VTMON_VOLT_V1P0_TOREG(aVal)     (((uint16_t)((((uint32_t)aVal) << DENALI_VTMON_VOLTAGE_SHIFT)/ DENALI_VTMON_V1P0_SCALE)))
#define DENALI_VTMON_VOLT_V1P8(aVal)           (((DENALI_VTMON_V1P8_SCALE * (aVal)) >> DENALI_VTMON_VOLTAGE_SHIFT))
#define DENALI_VTMON_VOLT_V1P8_TOREG(aVal)     (((uint16_t)((((uint32_t)aVal) << DENALI_VTMON_VOLTAGE_SHIFT)/ DENALI_VTMON_V1P8_SCALE)))
#define DENALI_VTMON_VOLT_V3P3_2P5(aVal)       (((DENALI_VTMON_V3P3_2P5_SCALE * (aVal)) >> DENALI_VTMON_VOLTAGE_SHIFT))
#define DENALI_VTMON_VOLT_V3P3_2P5_TOREG(aVal) (((uint16_t)((((uint32_t)aVal) << DENALI_VTMON_VOLTAGE_SHIFT)/ DENALI_VTMON_V3P3_2P5_SCALE)))
/** @} */

/**
    @trace #BRCM_SWREQ_DENALI
*/
int32_t DENALI_BusRead(BCM_HandleType aHdl, uint16_t aRegAddr, uint8_t aDevType, uint16_t *const aData);
/**
    @trace #BRCM_SWREQ_DENALI
*/

int32_t DENALI_BusWrite(BCM_HandleType aHdl, uint16_t aRegAddr, uint8_t aDevType, uint16_t aData);
/**
    @trace #BRCM_SWREQ_DENALI
*/
int32_t DENALI_IsSupported(BCM_HandleType aConnHdl, const ETHXCVR_PhyIDType *const aPhyID);

/**
    @trace #BRCM_SWREQ_DENALI
*/
int32_t DENALI_BusReadWrite(BCM_HandleType aHdl, uint16_t aRegAddr, uint8_t aDevType, uint16_t aData, uint16_t aMask);

/**
    @trace #BRCM_SWREQ_DENALI
*/
int32_t DENALI_GetHealthInfo(BCM_HandleType aConnHdl, ETHXCVR_IDType aID, ETHXCVR_ExtPhyHealthInfoType *const aInfo);

#endif /* DENALI_COMMON_H */
/** @} */
