/*****************************************************************************
 Copyright 2016-2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_flashdrv_ifc Interface
    @ingroup grp_flashdrv

    @addtogroup grp_flashdrv_ifc
    @{
    @section sec_flash_overview Overview
    @image html flash_overview.jpg "Flash driver overview"
    Flash driver manages all the flashes in the system. Flash driver allows
    simultaneous access to different flashes (connected to different
    controller) in the system. Flash driver interface restricts single client
    per flash (QSPI) controller. For each flash controller, flash driver allows
    single operation request at a given time and doesn’t support request queue.

    Flash driver supports following operations on the flash:
    - Flash read
    - Flash erase
    - Flash write
    - Flash read lane configuration
    - Flash compare
    - Flash blank check
    - Flash read manufacturer and device ID
    - Flash read/write from/to device registers

    @section sec_flash_fsm State Machine
    This section describes driver state machines for status transition during
    flash driver operation.
    @image html flash_state_machine.jpg "Flash driver state machine"
    - #FLASH_STATUS_UNINIT: Flash driver uninitialized or de-initialized after
      initialization.
    - #FLASH_STATUS_IDLE: Flash driver is initialized and currently no flash
      operation in progress.
    - #FLASH_STATUS_BUSY: Flash driver is busy processing flash operation.

    @note If #FLASH_DeInit is called when flash status is #FLASH_STATUS_BUSY,
    the in-progress operation shall get aborted and state of flash-region of
    operation of flash command is unknown.

    @section sec_flash_seq Sequence Diagrams
    This section describes sequence diagrams for APIs to better understand Flash
    driver interface. Sequence diagrams are based on synchronous and
    asynchronous behavior of the interface.

    @subsection subsec_flash_sync_op_seq Flash Synchronous Operation sequence
    The following sequence diagram depicts #FLASH_Init as an example of
    synchronous flash operation. The other synchronous flash operations like
    #FLASH_DeInit, #FLASH_GetOpsResult and #FLASH_GetStatus shall follow the
    same sequence.

    @note #FLASH_Cancel operation is an exception and it will be represented as
    a separate sequence diagram [@ref subsec_flash_cancel_op_seq].

    @image html flash_seq_sync_op.jpg "Flash synchronous operation API sequence"

    @subsection subsec_flash_async_op_seq Flash Asynchronous Operation sequence
    The following sequence diagram depicts #FLASH_Read as an example of
    asynchronous flash operation.  Asynchronous flash operation call on
    successful return initiates the operation. On successful completion or
    error, flash driver shall call #FLASH_OpsDoneInd or #FLASH_OpsErrInd
    respectively.

    The other asynchronous flash operations #FLASH_Write, #FLASH_Erase,
    #FLASH_Compare, #FLASH_BlankCheck, #FLASH_CfgReadLane, #FLASH_ReadID and
    #FLASH_RegReadWrite shall follow the same sequence.

    @image html flash_seq_async_op.jpg "Flash Asynchronous operation API sequence"

    @subsection subsec_flash_cancel_op_seq Flash Cancel Operation sequence
    The following sequence diagram depicts #FLASH_Cancel operation.
    #FLASH_Cancel is a synchronous operation which invokes #FLASH_OpsErrInd to
    indicate cancellation of on-going flash operation.

    @image html flash_seq_cancel_op.jpg "Flash cancel operation API sequence"

    @subsection subsec_flash_use_case_seq Flash Driver Use Case sequence
    The following sequence diagram depicts the typical use case sequence for
    flash APIs.

    @image html flash_seq_use_case.jpg "Flash use case sequence"
    @section sec_flash_perf Performance & Memory

    | Performance       | Description                                       |
    |:-----------------:|:-------------------------------------------------:|
    | CPU Load          |   NA                                              |
    | Memory Bandwidth  |   TBD                                             |
    | HW Utilization    |   NA                                              |

    @includedoc drivers_flash.dep

    @limitations None

    @file flash.h
    @brief Interfaces for Flash driver
    This header file  defines interface for Flash driver.

    @version 1.31 Imported from docx
*/

#ifndef FLASH_H
#define FLASH_H

#include <stddef.h>
#include <inttypes.h>
#include <compiler.h>
#include <bcm_err.h>
#include <nvm_flash.h>

/**
    @name Flash driver API IDs
    @{
    @brief API IDs for Flash drier
 */
#define BRCM_SWARCH_FLASH_STATUS_TYPE               (0x8107U)   /**< @brief #FLASH_StatusType         */
#define BRCM_SWARCH_FLASH_OPS_RESULT_TYPE           (0x8108U)   /**< @brief #FLASH_OpsResultType      */
#define BRCM_SWARCH_FLASH_INIT_PROC                 (0x810CU)   /**< @brief #FLASH_Init               */
#define BRCM_SWARCH_FLASH_DEINIT_PROC               (0x810DU)   /**< @brief #FLASH_DeInit             */
#define BRCM_SWARCH_FLASH_CANCEL_PROC               (0x810EU)   /**< @brief #FLASH_Cancel             */
#define BRCM_SWARCH_FLASH_GET_STATUS_PROC           (0x810FU)   /**< @brief #FLASH_GetStatus          */
#define BRCM_SWARCH_FLASH_GET_OPS_RESULT_PROC       (0x8110U)   /**< @brief #FLASH_GetOpsResult       */
#define BRCM_SWARCH_FLASH_ERASE_PROC                (0x8111U)   /**< @brief #FLASH_Erase              */
#define BRCM_SWARCH_FLASH_WRITE_PROC                (0x8112U)   /**< @brief #FLASH_Write              */
#define BRCM_SWARCH_FLASH_READ_PROC                 (0x8113U)   /**< @brief #FLASH_Read               */
#define BRCM_SWARCH_FLASH_COMPARE_PROC              (0x8114U)   /**< @brief #FLASH_Compare            */
#define BRCM_SWARCH_FLASH_BLANK_CHECK_PROC          (0x8115U)   /**< @brief #FLASH_BlankCheck         */
#define BRCM_SWARCH_FLASH_CFG_READ_LANE_PROC        (0x8116U)   /**< @brief #FLASH_CfgReadLane        */
#define BRCM_SWARCH_FLASH_READ_ID_PROC              (0x8117U)   /**< @brief #FLASH_ReadID             */
#define BRCM_SWARCH_FLASH_REG_READ_WRITE_PROC       (0x8118U)   /**< @brief #FLASH_RegReadWrite       */
#define BRCM_SWARCH_FLASH_GET_CONFIG_PROC           (0x8119U)   /**< @brief #FLASH_GetConfig          */
#define BRCM_SWARCH_FLASH_READ_DEV_CAPABILTIES_PROC (0x811BU)   /**< @brief #FLASH_ReadDevCapabilties */
#define BRCM_SWARCH_FLASH_GET_FLASH_ID_PROC         (0x811CU)   /**< @brief #FLASH_GetFlashID         */
#define BRCM_SWARCH_FLASH_GET_PARAMETERS_INFO_PROC  (0x811DU)   /**< @brief #FLASH_GetParametersInfo  */
#define BRCM_SWARCH_FLASH_READ_PARAMETER_DATA_PROC  (0x811EU)   /**< @brief #FLASH_ReadParameterData  */
/** @} */


/**
    @name COMP_State IDs
    @{
    @brief Brief description of COMP_State

    Detailed description of COMP_State.
    Typedef name shall be PascalCase

    @trace #BRCM_SWREQ_FLASH_KERNEL_INTERFACE
*/
typedef uint32_t FLASH_StatusType;          /**< @brief typedef for flash status */
#define FLASH_STATUS_UNINIT         (0UL)   /**< @brief Flash status uninitialised */
#define FLASH_STATUS_IDLE           (1UL)   /**< @brief Flash status idle */
#define FLASH_STATUS_BUSY           (2UL)   /**< @brief Flash status busy */
/** @} */

/**
    @name FLASH_OpsResultType
    @{
    @brief Flash operation result type

    @trace #BRCM_SWREQ_FLASH_KERNEL_INTERFACE
*/
typedef uint32_t FLASH_OpsResultType;       /**< @brief typedef for flash operation result */
#define FLASH_OPS_RESULT_OK         (1UL)   /**< @brief Operation result OK */
#define FLASH_OPS_RESULT_FAIL       (2UL)   /**< @brief Operation result failure */
#define FLASH_OPS_RESULT_PENDING    (3UL)   /**< @brief Operation result pending */
#define FLASH_OPS_RESULT_CANCELLED  (4UL)   /**< @brief Operation result cancelled */
/** @} */


/**
    @brief Initialize Flash driver

    This API initializes flash driver.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aID         Index of the controller
    @param[in]      aConfig     Pointer to configuration structure

    Return values are documented in reverse-chronological order
    @return     void

    @post API to initialize flash driver. Up on successful initialization,
    flash driver state changes to #FLASH_STATUS_IDLE.

    @note When aConfig is set to NULL, Flash driver uses a default config with
    16 MB of Flash with Dual lane and 80 MHz

    @trace #BRCM_SWREQ_FLASH_INIT

    @limitations None
*/
extern void FLASH_Init(FLASH_HwIDType aID,
                       const FLASH_CfgType *const aConfig);

/** @brief De-initialize Flash driver

    API to de-initialize flash driver.
    @note If this API is called during an on-going flash operation then:
    -# Completion of on-going operation is not guaranteed
    -# State of flash-region (of operation) is unknown

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aID         Index of the controller

    @return     void

    @post TBD

    @trace #BRCM_SWREQ_FLASH_INIT

    @limitations None
*/
extern void FLASH_DeInit(FLASH_HwIDType aID);

/** @brief Flash cancel

    API to cancel current flash operation. This API is expected to cancel an
    on-going flash operation if any. Flash_Cancel invokes #FLASH_OpsErrInd to
    indicate cancellation of an operation.

    @note It is possible that when FLASH_Cancel is called there is an actual
    flash command in progress. Due to asynchronous behavior of flash hardware,
    it may not be possible to stop that command. So, state of flash-region of
    operation of flash command is unknown after successful completion of
    FLASH_Cancel.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successful completion of flash cancel operation
    @retval     #BCM_ERR_INVAL_PARAMS   API called with invalid parameters i.e. aID is wrong
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_Cancel(FLASH_HwIDType aID);

/** @brief  Get flash driver status

    API to retrieve flash driver status.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID
    @param[out]     aStatus     Pointer to output flash driver status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successful retrieval of flash driver status
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aStatus is NULL)

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_GetStatus(FLASH_HwIDType aID,
                               FLASH_StatusType *const aStatus);

/** @brief Get flash operation results

    API to get result of last flash operation.
    If no flash operation is requested before calling this API, driver shall
    return #FLASH_OPS_RESULT_OK as operation result.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID
    @param[out]     aOpsRes     Pointer to output last flash operation result

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successful retrieval of last flash operation result
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aOpsRes is NULL)

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_GetOpsResult(FLASH_HwIDType aID,
                                  FLASH_OpsResultType *const aOpsRes);

/** @brief  Get flash driver configuration

    API to retrieve current flash config.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aID      Controller ID
    @param[out]     aCfg     Pointer to output flash driver config

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successful retrieval of flash driver status
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aCfg is NULL)

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_GetConfig(FLASH_HwIDType aID, FLASH_CfgType *const aCfg);

/** @brief Erase flash

    API to erase flash sector/s. Number of sectors to be erased will be
    determined using aAddr and aLen parameters.

    @behavior Async, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID
    @param[in]      aAddr       Flash start address for operation. It shall be
                                a Flash sector/sub-sector size aligned address
    @param[in]      aLen        Length in bytes. It shall be Flash
                                sector/sub-sector size aligned.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash erase
                                        operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aLen is zero) or
                                        (aAddr + aLen > Total flash size) or
                                        Either aAddr or aLen is not aligned
                                        to sector boundary
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver
                                        state
    @retval     #BCM_ERR_BUSY           API called before completion of previous
                                        flash operation

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_Erase(FLASH_HwIDType aID,
                           FLASH_AddrType aAddr,
                           FLASH_LenType aLen);

/** @brief Flash write

    API to write flash from aAddr for aLen bytes. Flash write will happen for
    one or more flash page sizes.

    @behavior Async, Re-entrant

    @pre describe any pre-condition (expectation before calling this function)

    @param[in]      aID         Controller ID
    @param[in]      aAddr       Flash start address for operation. It shall be
                                Flash page size aligned address.
    @param[in]      aBuf        Pointer to input data buffer
    @param[in]      aLen        Length in bytes. It shall be aligned to Flash
                                page size.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash write operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aLen is zero) or
                                        (aAddr + aLen > Total flash size) or
                                        (aBuf is NULL) or
                                        (aAddr unaligned to flash page boundary) or
                                        aLen is not multiple of flash page size
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state
    @retval     #BCM_ERR_BUSY           API called before completion of previous
                                        flash operation

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_Write(FLASH_HwIDType aID,
                           FLASH_AddrType aAddr,
                           const uint8_t *const aBuf,
                           FLASH_LenType aLen);

/** @brief Flash read

    API to read flash from aAddr for aLen bytes.

    @behavior Async, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID
    @param[in]      aAddr       Flash address
    @param[out]     aBuf        Pointer to output data buffer
    @param[in]      aLen        Length in bytes

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash read operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aLen is zero) or
                                        (aAddr + aLen > Total flash size) or
                                        (aBuf is NULL)
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state
    @retval     #BCM_ERR_BUSY           API called when previous operation in progress

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_Read(FLASH_HwIDType aID,
                          FLASH_AddrType aAddr,
                          uint8_t *const aBuf,
                          FLASH_LenType aLen);

/** @brief Flash Compare

    API to compare data present in flash-region starting from aAddr for aLen
    bytes with data in input buffer.

    @behavior Async, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID
    @param[in]      aAddr       Flash address
    @param[in]      aBuf        Pointer to data buffer
    @param[in]      aLen        Length in bytes

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash compare operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aLen is zero) or
                                        (aAddr + aLen > Total flash size) or
                                        (aBuf is NULL)
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state
    @retval     #BCM_ERR_BUSY           API called before completion of previous flash operation

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_Compare(FLASH_HwIDType aID,
                             FLASH_AddrType aAddr,
                             const uint8_t *const aBuf,
                             FLASH_LenType aLen);

/** @brief Flash blank check

    API to check whether flash-region starting from aAddr for aLen bytes is
    erased.

    @behavior Async, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID
    @param[in]      aAddr       Flash address
    @param[in]      aLen        Length in bytes

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash blank check operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aLen is zero) or
                                        (aAddr + aLen > Total flash size)
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state
    @retval     #BCM_ERR_BUSY           API called before completion of previous flash operation

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_BlankCheck(FLASH_HwIDType aID,
                                FLASH_AddrType aAddr,
                                FLASH_LenType aLen);

/** @brief configure flash read lane

    API to configure read lanes.
    The read lane parameter will be configured according to the configuration
    structure passed during #FLASH_Init.

    @behavior Async, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash read lane
                                        configuration operation
    @retval     #BCM_ERR_INVAL_STATE    Read lane is already configured and
                                        re-configuration is not allowed
    @retval     #BCM_ERR_INVAL_PARAMS   aID is invalid
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state
    @retval     #BCM_ERR_BUSY           API called before completion of previous
                                        flash operation
    @retval     #BCM_ERR_NOSUPPORT      Configuring read lane is not supported

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations Re-configuration of read lane is not allowed, if read lane is
    already configured. For re-configuration of read lanes, call #FLASH_DeInit,
    #Flash_Init and then this API.
*/
extern int32_t FLASH_CfgReadLane(FLASH_HwIDType aID);

/** @brief Flash Read ID

    API to read manufacturer and device ID.
    For manufacturer ID and device ID of the specific flash device, refer to
    flash device data sheet.

    @behavior Async, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID
    @param[out]     aFlsID      Pointer to retrieve flash ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash read ID
                                        operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aFlsID is NULL)
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state
    @retval     #BCM_ERR_BUSY           API called before completion of previous
                                        flash operation

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_ReadID(FLASH_HwIDType aID,
                            FLASH_FlsIDType *const aFlsID);

/** @brief Flash Register read and write

    API to read/write from/to device registers.
    @note The data will be pushed to Data Input and Data Output line as it is in
    the Tx and Rx buffer in the order aTxBuf[0], aTxBuf[1] and so on. aRxBuf can
    be NULL if it is just register write operation. For read, aRxBuf and aTxBuf
    should be of equal size and max it can be of 16 bytes

    @behavior Async, Re-entrant

    @pre TBD

    @param[in]      aID         Controller ID
    @param[out]     aRxBuf      Pointer to retrieve RX data buffer
    @param[in]      aTxBuf      Pointer to TX data buffer
    @param[in]      aLen        Length to read or write in bytes

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash register
                                        read-write operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aTxBuf is NULL) or
                                        (aLen is zero) or
                                        (aLen > 16bytes)
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state
    @retval     #BCM_ERR_BUSY           API called before completion of previous
                                        flash operation

    @post TBD

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_RegReadWrite(FLASH_HwIDType aID,
                                  uint8_t *const aRxBuf,
                                  const uint8_t *const aTxBuf,
                                  FLASH_LenType aLen);

/** @brief Flash read device parameters (SFDP)

    API to read the device parameters (SFDP) from flash.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aID         Controller ID
    @param[out]     aSFDPInfo   Pointer to retrieve SFDP data

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated SFDP
                                        read operation
    @retval     #BCM_ERR_INVAL_PARAMS   aSFDPInfo is NULL
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state

    @post None

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_ReadDevCapabilties(FLASH_HwIDType aID,
                                      FLASH_DevCapabiltiesType *const aSFDPInfo);

/** @brief Flash get device ID

    API to read the device ID from flash.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aID              Controller ID
    @param[out]     aFlashID         Pointer to flash ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated operation
    @retval     #BCM_ERR_INVAL_PARAMS   aParameterInfo is NULL
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state

    @post None

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_GetFlashID(FLASH_HwIDType aID, FLASH_IDType *const aFlashID);

/** @brief Flash get parameters information (SFDP)

    API to read the parameters information (SFDP) from flash.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aID              Controller ID
    @param[out]     aParameterInfo   Pointer to SFDP parameters information

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated operation
    @retval     #BCM_ERR_INVAL_PARAMS   aParameterInfo is NULL
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state

    @post None

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_GetParametersInfo(FLASH_HwIDType aID,
                                       FLASH_ParametersInfoType *const aParameterInfo);

/** @brief Flash get parameter data (SFDP)

    API to read the parameter data (SFDP) of the paramter ID from flash.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aID              Controller ID
    @param[in]      paramID          Parameter ID
    @param[out]     aParameterData   Pointer to SFDP parameter data

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated operation
    @retval     #BCM_ERR_INVAL_PARAMS   aParameterData is NULL
    @retval     #BCM_ERR_UNINIT         API called in uninitialized driver state

    @post None

    @trace #BRCM_SWREQ_FLASH_OPERATIONS

    @limitations None
*/
extern int32_t FLASH_ReadParameterData(FLASH_HwIDType aID, FLASH_SFDPParamIDType paramID,
                                       FLASH_ReadParameterDataType *const aParameterData);

#endif /* FLASH_H */
/** @} */
