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
#define GNU
#define RPC_MSG_PAYLOAD_SZ 448UL
#define ITBL_MAX_NUM_ENTRIES 20

#include <unistd.h>
#include <errno.h>
#include <bcm_utils.h>
#include <system_dmon.h>
#include <rpc_msg.h>
#include <nvm_update.h>
#include <flasher_interface.h>
#include <system_mcu.h>

static const BCM_CompIDType BCM_LogCompID = BCM_FLM_ID;
static const uint16_t BCM_LogFileID = 0xB1U;

#undef BCM_LOG_ERROR
#define BCM_LOG_ERROR(aInstanceID, aState, aErr, ...) ((void)0);
#undef BCM_LOG_INFO
#define BCM_LOG_INFO(aInstanceID, aState, aErr, ...) ((void)0);


#define FLASHER_INSTALL_RESET                (BCM_STATE_SUB_STATE_RESET)   /**< @brief Init and open socket               */
#define FLASHER_READ_BOOTCOPY_CHK_HEALTH     (BCM_STATE_SUB_STATE_STAGE0)  /**< @brief Read Boot copy and check health    */
#define FLASHER_FULL_INSTALL_USER_OPT        (BCM_STATE_SUB_STATE_STAGE1)  /**< @brief User option to Full install        */
#define FLASHER_FULL_INSTALL_OPERATION       (BCM_STATE_SUB_STATE_STAGE2)  /**< @brief Full install operation             */
#define FLASHER_SYNC_PARTITIONS              (BCM_STATE_SUB_STATE_STAGE3)  /**< @brief Sync partitions                    */
#define FLASHER_SETBOOTCFG_INC_LOOPCNT       (BCM_STATE_SUB_STATE_STAGE4)  /**< @brief Set boot config to copy 1 and loop */
#define FLASHER_SAFE_INSTALL_OPERATION       (BCM_STATE_SUB_STATE_STAGE5)  /**< @brief Safe install operation             */
#define FLASHER_SAFE_INSTALL_IS_ROLLBACK     (BCM_STATE_SUB_STATE_STAGE6)  /**< @brief Option to boot from older version  */
#define FLASHER_SYNC_COPY3                   (BCM_STATE_SUB_STATE_STAGE7)  /**< @brief Sync partitions to copy 3          */
#define FLASHER_SETBOOTCFG_REBOOT            (BCM_STATE_SUB_STATE_STAGE8)  /**< @brief Set boot config to copy 1 reboot   */
#define FLASHER_EXIT                         (BCM_STATE_SUB_STATE_DONE)    /**< @brief Exit the application               */



/* Update the boot configuration */
static int32_t FLASHER_updateBootCfg(BCM_HandleType aConnHdl, uint16_t aBlCopyNum,
                               uint16_t aFwCopyNum, uint16_t aCfgCopyNum,
                               uint16_t aAltCopyEn, uint16_t aBlCopyMask,
                               uint16_t aFwCopyMask, uint16_t aCfgCopyMask)
{
    UPDATE_BootCopyCfgMsgType bootCfg;

    bootCfg.cfg.magic       = IMGL_MAGIC;
    bootCfg.cfg.version     = 0UL;
    bootCfg.cfg.blCopyNum   = aBlCopyNum;
    bootCfg.cfg.fwCopyNum   = aFwCopyNum;
    bootCfg.cfg.cfgCopyNum  = aCfgCopyNum;
    bootCfg.cfg.altCopyEn   = aAltCopyEn;
    bootCfg.cfg.blCopyMask  = aBlCopyMask;
    bootCfg.cfg.fwCopyMask  = aFwCopyMask;
    bootCfg.cfg.cfgCopyMask = aCfgCopyMask;
    return UPDATE_SetBootCopyCfg(aConnHdl, &bootCfg);
}

static int32_t FLASHER_IsBlUpdateSupported(BCM_HandleType aConnHdl, BCM_BoolType *aIsBootLoader)
{
    DMON_HwVersionMsgType hwVersion;
    int32_t retVal;

    retVal = DMON_GetHwVersion(aConnHdl, &hwVersion);
    if(BCM_ERR_OK == retVal) {
        if((MCU_CHIP_FAMILY_8908X != (hwVersion.model & MCU_CHIP_FAMILY_8908X_MASK))
           && (MCU_CHIP_FAMILY_8910X != (hwVersion.model & MCU_CHIP_FAMILY_8910X_MASK))
           && (MCU_CHIP_FAMILY_8956X != (hwVersion.model & MCU_CHIP_FAMILY_MASK))
           && (MCU_CHIP_FAMILY_8957X != (hwVersion.model & MCU_CHIP_FAMILY_MASK))) {
            *aIsBootLoader = BCM_BOOL_TRUE;
        } else {
            *aIsBootLoader = BCM_BOOL_FALSE;
        }
    }

    return retVal;
}

/* Sync all copys with current running Copys */
static int32_t FLASHER_syncBootCopy(BCM_HandleType aConnHdl, uint16_t aBlBootCopyNum,
                            uint16_t aFwBootCopyNum, uint16_t aCfgBootCopyNum)
{
    UPDATE_SyncMsgType sync;
    uint32_t i = 1UL;
    int32_t retVal = BCM_ERR_OK;
    BCM_BoolType isBL = BCM_BOOL_FALSE;

    BCM_LOG_ERROR(0U, BCM_STATE_RUN, retVal, "Sync partitions\n")
    (void)FLASHER_IsBlUpdateSupported(aConnHdl, &isBL);
    for(i = 1UL; i < 4UL; i++) {
        BCM_MemSet(&sync, 0U, sizeof(UPDATE_SyncMsgType));
        if(BCM_BOOL_TRUE == isBL) {
            if(aBlBootCopyNum != i) {
                sync.blCopyNum  = i;
            }
        }

        if(aFwBootCopyNum != i) {
            sync.fwCopyNum  = i;
        }

        if(aCfgBootCopyNum != i) {
            sync.cfgCopyNum = i;
        }

        if((0UL!= sync.blCopyNum) || (0UL!= sync.fwCopyNum) || (0UL!= sync.cfgCopyNum)) {
            retVal = UPDATE_Sync(aConnHdl, &sync);
            if(BCM_ERR_OK != retVal) {
                break;
            }
        }
    }

    if(BCM_ERR_OK != retVal) {
        BCM_LOG_ERROR(0U, BCM_STATE_RUN, retVal, "Failed to Sync. Copy ID = %d\n", i)
    } else {
        BCM_LOG_ERROR(0U, BCM_STATE_RUN, retVal, "Done\n")
    }

    return retVal;
}

static int32_t FLASHER_CheckHealth(BCM_HandleType aConnHdl)
{
    int32_t retVal = BCM_ERR_OK;
    uint32_t i;
    uint32_t j;
    PTBL_IdType pid;
    IMGL_VersionType  version;

    for(i = 1UL; i <= 3UL; i++) { /* Copy ID */
        for(j = 1UL; j <= PTBL_ID_SYSCFG; j++) { /* Partition ID */
            pid = ((i << PTBL_ID_COPY_SHIFT) | j);
            if((PTBL_ID_FW == j) || (PTBL_ID_SYSCFG == j)) {
                retVal = UPDATE_HealthCheck(aConnHdl, pid, &version);
            }

            if(BCM_ERR_OK != retVal)
            {
                break;
            }
        } /* Partition ID */
        if(BCM_ERR_OK != retVal)
        {
            break;
        }
    } /* Copy ID */

    if(BCM_ERR_OK != retVal) {
        BCM_LOG_ERROR(0U, BCM_STATE_RUN, retVal, "pid %x.\n", (uint32_t)pid)
    }

    return retVal;
}

/** @brief Read Boot copy of all partitions

    @code{.unparsed}
    @endcode
*/
static int32_t FLASHER_ReadBootCopy (BCM_HandleType aConnHdl,
                                     uint16_t *aBlBootCopyNum,
                                     uint16_t *aFwBootCopyNum,
                                     uint16_t *aCfgBootCopyNum)
{
    int32_t retVal;
    IMGL_BootVersionMsgType bootVerBL;
    IMGL_BootVersionMsgType bootVerFW;
    IMGL_BootVersionMsgType bootVerSyscfg;

    BCM_MemSet(&bootVerBL, 0U, sizeof(IMGL_BootVersionMsgType));
    BCM_MemSet(&bootVerFW, 0U, sizeof(IMGL_BootVersionMsgType));
    BCM_MemSet(&bootVerSyscfg, 0U, sizeof(IMGL_BootVersionMsgType));

    (void)IMGL_GetBootVersion(aConnHdl, PTBL_ID_BL, &bootVerBL);
    retVal = IMGL_GetBootVersion(aConnHdl, PTBL_ID_FW, &bootVerFW);
    if(BCM_ERR_OK == retVal) {
        retVal = IMGL_GetBootVersion(aConnHdl, PTBL_ID_SYSCFG, &bootVerSyscfg);
        if(BCM_ERR_OK == retVal) {
            *aBlBootCopyNum     = ((bootVerBL.pid & PTBL_ID_COPY_MASK) >> PTBL_ID_COPY_SHIFT);
            *aFwBootCopyNum     = ((bootVerFW.pid & PTBL_ID_COPY_MASK) >> PTBL_ID_COPY_SHIFT);
            *aCfgBootCopyNum    = ((bootVerSyscfg.pid & PTBL_ID_COPY_MASK) >> PTBL_ID_COPY_SHIFT);
        }
    }

    return retVal;
}

static int32_t FLASHER_openSockAndWait(const uint8_t *aSockName,
                                         uint16_t aPort,
                                         uint32_t aTimeoutMs,
                                         BCM_HandleType *aHdl)
{
    int32_t retVal;
    DMON_SyncMsgType syncMsg;

    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Connecting to target\n");
    retVal = RPC_Open(aSockName, aPort, aTimeoutMs, aHdl);
    if(BCM_ERR_OK == retVal) {
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "Connected\n");
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "Waiting for Run state..\n");
        /* Wait for boot */
        retVal = DMON_SyncWait(*aHdl, BCM_STATE_RUN, &syncMsg);
        if(BCM_ERR_OK == retVal) {
            BCM_LOG_INFO(0U, BCM_STATE_RUN, "Running\n");
        }
    }

    return retVal;
}

static int32_t FLASHER_SendInstallCmd(BCM_HandleType aConnHdl,
                                        BCM_MsgType aCmd,
                                        UPDATE_InstallCfgMsgType *aInstallMsg)
{
    int32_t retVal = BCM_ERR_OK;
    uint32_t rcvdSz = 0UL;

    if(UPDATE_ID_FULL_INSTALL == aCmd) {
        retVal = UPDATE_FullInstall(aConnHdl, aInstallMsg, &rcvdSz);
    } else {
        retVal = UPDATE_SafeInstall(aConnHdl, aInstallMsg, &rcvdSz);
    }

    return retVal;
}

int32_t FLASHER_GetImageMaxSize (const PTBL_Type *const aPtbl,
                                      uint32_t *const aImageSize)
{
    int32_t  retVal = BCM_ERR_INVAL_PARAMS;
    uint32_t eraseSize  = 0UL;
    uint32_t newEraseSize  = 0UL;
    uint32_t i;

    if((NULL != aPtbl) && (NULL != aImageSize)) {
        for(i=0U; i<PTBL_MAX_NUM_ENTRIES; i++) {
            if(0UL != aPtbl->entry[i].addr) {
                newEraseSize = aPtbl->entry[i].addr + aPtbl->entry[i].maxSize;
                /* Check if it is the max size to erase */
                if(eraseSize < newEraseSize) {
                    eraseSize = newEraseSize;
                }
            }
        }

        *aImageSize = eraseSize;
        retVal = BCM_ERR_OK;
    }

    return retVal;
}

int32_t FLASHER_InstallStateHandler(const uint8_t *aSockName,
                                     uint16_t aPort,
                                     BCM_BoolType aIsSafeInstall,
                                     UPDATE_InstallCfgMsgType *aInstallMsg)
{
    int32_t retVal;
    BCM_HandleType hdl;
    uint16_t blBootCopyNum;
    uint16_t fwBootCopyNum;
    uint16_t cfgBootCopyNum;
    uint32_t loopCnt;
    BCM_BoolType isInstall;
    BCM_BoolType isRollBack;
    BCM_BoolType isBL = BCM_BOOL_FALSE;
    BCM_SubStateType state  = FLASHER_INSTALL_RESET;


    do {
        switch(state) {
            case FLASHER_INSTALL_RESET:
                loopCnt         = 0UL;
                isInstall       = BCM_BOOL_FALSE;
                isRollBack      = BCM_BOOL_FALSE;
                hdl             = 0UL;
                blBootCopyNum   = 0U;
                fwBootCopyNum   = 0U;
                cfgBootCopyNum  = 0U;
                retVal = FLASHER_openSockAndWait(aSockName, aPort, 60000, &hdl);
                if(BCM_ERR_OK != retVal) {
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Failed to open socket connection with target\n");
                    state = FLASHER_EXIT;
                } else {
                    if(BCM_BOOL_FALSE == aIsSafeInstall) {
                        state  = FLASHER_FULL_INSTALL_OPERATION;
                    } else {
                        state  = FLASHER_READ_BOOTCOPY_CHK_HEALTH;
                    }
                }
                break;
            case FLASHER_READ_BOOTCOPY_CHK_HEALTH:
                    /* Read Boot copy */
                    retVal = FLASHER_ReadBootCopy(hdl, &blBootCopyNum, &fwBootCopyNum, &cfgBootCopyNum);
                    if(BCM_ERR_OK == retVal) {
                        retVal = FLASHER_IsBlUpdateSupported(hdl, &isBL);
                        if(BCM_ERR_OK == retVal) {
                            retVal = BCM_ERR_INVAL_PARAMS;
                            if(BCM_BOOL_TRUE == isBL) {
                                /* Booted from flash? */
                                if((0UL != blBootCopyNum) && (0UL != fwBootCopyNum) && (0UL != cfgBootCopyNum)) {
                                    retVal = BCM_ERR_OK;
                                }
                            } else {
                                /* Booted from flash? */
                                if((0UL != fwBootCopyNum) && (0UL != cfgBootCopyNum)) {
                                    retVal = BCM_ERR_OK;
                                }
                            }
                            if(BCM_ERR_OK == retVal) {
                                /* Booted from flash. Check health of the partitions */
                                retVal = FLASHER_CheckHealth(hdl);
                                if(BCM_ERR_OK == retVal) {
                                    if((3UL != blBootCopyNum) && (3UL != fwBootCopyNum) && (3UL != cfgBootCopyNum)) {
                                        state = FLASHER_SAFE_INSTALL_OPERATION;
                                    } else {
                                        BCM_LOG_INFO(0U, BCM_STATE_RUN, "Booted from Copy 3. Setting the boot config to copy 1\n");
                                        state = FLASHER_SETBOOTCFG_INC_LOOPCNT;
                                    }
                                } else {
                                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Partitions are not healthy. Recovering the partitions\n");
                                    state = FLASHER_SYNC_PARTITIONS;
                                }
                            } else {
                                /* Not booted from flash. Proceed to Full install */
                                state = FLASHER_FULL_INSTALL_USER_OPT;
                            }
                        } else {
                            /* Read boot copy */
                            state = FLASHER_EXIT;
                        }
                    } else {
                        /* Socket open */
                        state = FLASHER_EXIT;
                    }
                break;
            case FLASHER_FULL_INSTALL_USER_OPT:
                FLASHER_FullInstallOpt(&isInstall);
                if(BCM_BOOL_TRUE == isInstall) {
                    isInstall = BCM_BOOL_FALSE;
                    state = FLASHER_FULL_INSTALL_OPERATION;
                } else {
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Exit\n");
                    state = FLASHER_EXIT;
                }
                break;
            case FLASHER_FULL_INSTALL_OPERATION:
                BCM_LOG_INFO(0U, BCM_STATE_RUN, "Full install is started\n");
                retVal = FLASHER_SendInstallCmd(hdl, UPDATE_ID_FULL_INSTALL, aInstallMsg);
                if(BCM_ERR_OK == retVal) {
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Install completed\n");
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Reboot\n");
                    (void)DMON_Reboot(hdl);
                    (void)RPC_Close(hdl);
                    hdl = 0ULL;
                } else {
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Failed\n");
                }
                state = FLASHER_EXIT;
                break;
            case FLASHER_SYNC_PARTITIONS:
                retVal = FLASHER_syncBootCopy(hdl, blBootCopyNum, fwBootCopyNum, cfgBootCopyNum);
                if(BCM_ERR_OK == retVal) {
                    state = FLASHER_SETBOOTCFG_INC_LOOPCNT;
                } else {
                    state = FLASHER_EXIT;
                }
                break;
            case FLASHER_SETBOOTCFG_INC_LOOPCNT:
                retVal = FLASHER_updateBootCfg(hdl, 1U, 1U, 1U, 0U, 0U, 0U, 0U);
                if(BCM_ERR_OK == retVal) {
                    (void)DMON_Reboot(hdl);
                    (void)RPC_Close(hdl);
                    hdl = 0ULL;
                    FLASHER_Wait(3);
                    retVal = FLASHER_openSockAndWait(aSockName, aPort, 60000, &hdl);
                    if(BCM_ERR_OK == retVal) {
                        loopCnt++;
                        if(2UL < loopCnt) {
                            state = FLASHER_EXIT;
                        } else {
                            state = FLASHER_READ_BOOTCOPY_CHK_HEALTH;
                        }
                    } else {
                        state = FLASHER_EXIT;
                    }
                }
                break;
            case FLASHER_SAFE_INSTALL_OPERATION:
                BCM_LOG_INFO(0U, BCM_STATE_RUN, "Safe install is started\n");
                retVal = FLASHER_SendInstallCmd(hdl, UPDATE_ID_SAFE_INSTALL, aInstallMsg);
                if(BCM_ERR_OK == retVal) {
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Install completed\n");
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Setting boot config to boot from copy 3\n");
                    retVal = FLASHER_updateBootCfg(hdl, 3U, 3U, 3U, 0U, 0U, 0U, 0U);
                    if(BCM_ERR_OK == retVal) {
                        BCM_LOG_INFO(0U, BCM_STATE_RUN, "Reboot\n");
                        (void)DMON_Reboot(hdl);
                        (void)RPC_Close(hdl);
                        hdl = 0ULL;
                        FLASHER_Wait(3);
                        retVal = FLASHER_openSockAndWait(aSockName, aPort, 60000, &hdl);
                        if(BCM_ERR_OK == retVal) {
                            state = FLASHER_SAFE_INSTALL_IS_ROLLBACK;
                        } else {
                            state = FLASHER_EXIT;
                        }
                    } else {
                        state = FLASHER_EXIT;
                    }
                } else {
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Failed\n");
                    state = FLASHER_EXIT;
                }
                break;
            case FLASHER_SAFE_INSTALL_IS_ROLLBACK:
                FLASHER_SafeInstallRollbackOpt(&isRollBack);
                if(BCM_BOOL_TRUE == isRollBack) {
                    isRollBack = BCM_BOOL_FALSE;
                    state = FLASHER_SETBOOTCFG_REBOOT;
                } else {
                    state = FLASHER_SYNC_COPY3;
                }
                break;
            case FLASHER_SYNC_COPY3:
                retVal = FLASHER_ReadBootCopy(hdl, &blBootCopyNum, &fwBootCopyNum, &cfgBootCopyNum);
                if(BCM_ERR_OK == retVal) {
                    retVal = FLASHER_syncBootCopy(hdl, blBootCopyNum, fwBootCopyNum, cfgBootCopyNum);
                    if(BCM_ERR_OK == retVal) {
                        state = FLASHER_SETBOOTCFG_REBOOT;
                    } else {
                        BCM_LOG_ERROR(0U, BCM_STATE_RUN, retVal, "Failed to Sync\n")
                        state = FLASHER_EXIT;
                    }
                } else {
                    state = FLASHER_EXIT;
                }
                break;
            case FLASHER_SETBOOTCFG_REBOOT:
                retVal = FLASHER_updateBootCfg(hdl, 1U, 1U, 1U, 0U, 0U, 0U, 0U);
                if(BCM_ERR_OK == retVal) {
                    retVal = DMON_Reboot(hdl);
                    (void)RPC_Close(hdl);
                    hdl = 0ULL;
                    if(BCM_ERR_OK != retVal) {
                        BCM_LOG_ERROR(0U, BCM_STATE_RUN, retVal, "Failed to Reboot\n")
                    }
                } else {
                    BCM_LOG_ERROR(0U, BCM_STATE_RUN, retVal, "Failed to update boot config\n")
                }
                state = FLASHER_EXIT;
                break;
            default:
                break;
        }
    } while(FLASHER_EXIT != state);

    if (0ULL != hdl) {
        (void)RPC_Close(hdl);
    }

    return retVal;
}
