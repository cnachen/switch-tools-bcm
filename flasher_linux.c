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

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/stat.h>
#include <cpu_utils.h>
#include <rpc_msg.h>
#include <nvm_update.h>
#include <system_imgl_interface.h>
#include <flasher_interface.h>

#ifdef __QNX__
#include <io-sock/sys/socket.h>
#endif

#undef BCM_LOG_ERROR
#define BCM_LOG_ERROR(aInstanceID, aState, aErr, ...) ((void)0);
#undef BCM_LOG_INFO
#define BCM_LOG_INFO(aInstanceID, aState, aErr, ...) ((void)0);

static const BCM_CompIDType BCM_LogCompID = BCM_FLM_ID;
static const uint16_t BCM_LogFileID = 0xB0U;

static FILE* FLASHER_Fp;                           /* File pointer which also used in the server thread */
static struct sockaddr_in address ={0};
static struct stat statbuf = {0};
static pthread_barrier_t FLASHER_BusBarrier;
static uint8_t FLASHER_FileBuff[5UL * 1024UL * 1024UL];

static BCM_BoolType isUserOption = BCM_BOOL_FALSE;
static uint32_t userOptionMask = 0UL;


#define FLASHER_CONFIRM_FULL_INSTALL    (0x1UL)
#define FLASHER_CONFIRM_ROLL_BACK       (0x2UL)

#define FLASHER_MAX_USER_OPT_MASK_STR_LENGTH     (10UL)
#define FLASHER_PTBL_TABLE_ENTRY_SIZE            (20UL)

static void FLASHER_PrintUsage(void)
{
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "------------------------------------------------------------------\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Required Arguments: \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -f <file>\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Optional Arguments: \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -m <mode>\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -s Safe Install\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -l <ip> \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -r <socket name or ip> (-p is needed if ip address is given)\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -p <port> \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -i <flash id> \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -e <erase size> \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "            -u <user selection options bitmask>\n\
                                                     \t\t\t\t\t\t[bit0: Confirm Full install\n\
                                                     \t\t\t\t\t\t bit1: Confirm Roll back]\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "------------------------------------------------------------------\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "[mode]              : Mode for flashing (Default: TCP) \n \
                                                           \t\t\t\t\t\t0 : TCP \t 1 : IPC \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "[ip]                : IP address where TCP server will be running on Linux PC \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "[socket name or ip] : socket to connect to target as/tmp/bcm_rpc_socket or 192.168.10.1 \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "[port]              : Port Number of target 5555 \n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "[file]              : image file to be flashed\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "[erase size]        : Flash size to be erased as 0x200000 (for Scorpio and Orion). Default : 4MB\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "[flash id]          : 0 or 1. Default 0\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Note: Default socket is /tmp/bcm_rpc_socket\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "------------------------------------------------------------------\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "TCP Example usage\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "./flasher -f <abs path of .img> -m 0 -l 192.168.10.1 -r 192.168.10.65 -p 5555\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "IPC Example usage\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "./flasher -f <abs path of .img> -m 1\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Note: In IPC case, the bcm_rpc_proxy should be running\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Transfer file to bcm_rpc_proxy over TCP socket. usage\n");
    BCM_LOG_INFO(0U, BCM_STATE_RUN, "./flasher -f <abs path of .img> -m 0 -l 127.0.0.1 -e 0x200000 -p 0 \n");

    BCM_LOG_INFO(0U, BCM_STATE_RUN, "------------------------------------------------------------------\n");

}

static int32_t FLASHER_ReadImgFromFile(FILE *aFp,
                                        uint8_t *aBuff,
                                        uint32_t *aLen)
{
    int32_t retVal = BCM_ERR_OK;
    uint32_t readLen;
    int32_t position = 0L;

    if((NULL == aFp) || (NULL == aBuff) || (NULL == aLen)){
        retVal = BCM_ERR_INVAL_PARAMS;
        BCM_LOG_ERROR(0U, retVal, BCM_STATE_RUN, "Could not open File.\n");
    }

    if((BCM_ERR_OK != retVal) || (fseek(aFp, 0, SEEK_END) < 0)) {
        retVal = BCM_ERR_INVAL_STATE;
        BCM_LOG_ERROR(0U, retVal, BCM_STATE_RUN, "Error seeking to end of File.\n");
    } else {
        position = ftell(aFp);
        if(position < 0L) {
            retVal = BCM_ERR_INVAL_STATE;
            BCM_LOG_ERROR(0U, retVal, BCM_STATE_RUN, "Error in getting the current position.\n");
        } else {
            *aLen = (uint32_t)position;
            if (fseek(aFp, 0, SEEK_SET) < 0) {
                retVal = BCM_ERR_INVAL_STATE;
                BCM_LOG_ERROR(0U, retVal, BCM_STATE_RUN, "Error seeking to beginning of File.\n");
            } else {
                readLen = fread(aBuff, 1, *aLen, aFp);
                if (readLen != *aLen) {
                    retVal = BCM_ERR_INVAL_STATE;
                    BCM_LOG_ERROR(0U, retVal, BCM_STATE_RUN, "Error reading File.\n");
                }
            }
        }
        /* Reset the file position to begining */
        if(fseek(aFp, 0, SEEK_SET) < 0) {
            retVal = BCM_ERR_UNKNOWN;
        }
    }

    return retVal;
}

/* Server to service the image */
static void* FLASHER_DataThread(void* r)
{
    int32_t ret;
    int32_t fd0;
    int32_t fd1 = -1;
    uint8_t buffer[256];
    socklen_t addrlen = sizeof(address);

    fd0 = socket(AF_INET, SOCK_STREAM, 0);

    if (0 > fd0) {
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "Socket open failed with return = %u\n", fd0);
    } else {
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(0);
        ret = bind(fd0, (struct sockaddr*)&address, sizeof(address));
        if (0 > ret) {
            BCM_LOG_ERROR(0U, BCM_STATE_RUN, 0L, "Socket bind failed with return = %d\n", ret);
        } else {
            BCM_LOG_INFO(0U, BCM_STATE_RUN, "socket bind returned = %d\n", ret);
        }
        if (0 == ret) {
            ret = listen(fd0, 2);
            BCM_LOG_INFO(0U, BCM_STATE_RUN, "socket listen returned = %d\n", ret);
            if (0 == ret) {
                uint32_t addr_len = sizeof(address);
                memset(&address, 0, sizeof(address));
                (void)getsockname(fd0, (struct sockaddr*)&address, &addr_len);
                BCM_LOG_INFO(0U, BCM_STATE_RUN, "socket getsockname returned = %d ip %x port %u\n", ret, address.sin_addr.s_addr, CPU_BEToNative16(address.sin_port));
                pthread_barrier_wait(&FLASHER_BusBarrier);

                fd1 = accept(fd0, (struct sockaddr*)&address, &addrlen);
                BCM_LOG_INFO(0U, BCM_STATE_RUN, "Connection is accepted\n");
                uint32_t sendsize = 0UL;
                if (fd1 > 0) {
                    uint32_t tmp = 0UL;
                    do {
                        tmp = fread(buffer, 1, 256, FLASHER_Fp);
                        if (tmp > 0) {
                            ret = send(fd1, buffer, tmp, 0);
                        }
                        sendsize += ret;
                    } while ((tmp > 0) && (ret >= 0));
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "completed\n");
                }
            }
        }
    }
    if (fd1 >= 0) {
        close(fd1);
    }
    if (fd0 >= 0) {
        close(fd0);
    }
    return NULL;
}

static int32_t FLASHER_AsciiToHex(char *aStr, uint32_t aStrLen, uint32_t *aHexVal)
{
    char hexStr[FLASHER_MAX_USER_OPT_MASK_STR_LENGTH];
    uint32_t val;
    uint32_t i = 0U;
    int32_t retVal = BCM_ERR_INVAL_PARAMS;

    if(FLASHER_MAX_USER_OPT_MASK_STR_LENGTH >= aStrLen) { /* only 32-bit support */
        BCM_MemCpy(hexStr, aStr, aStrLen);
        val = 0U;
        if((hexStr[0] == '0') && ((hexStr[1] == 'x') || (hexStr[1] == 'X'))) {
            i = 2U;
            while((aStrLen > i) && ((hexStr[i] >= '0' && hexStr[i] <= '9')
                       || (hexStr[i] >= 'a' && hexStr[i] <= 'f')
                       || (hexStr[i] >= 'A' && hexStr[i] <= 'F'))) {
                val *= (uint32_t)16;
                if ((hexStr[i] >= '0' && hexStr[i] <= '9')) {
                    val += ((uint32_t)(hexStr[i]) - 0x30U);
                } else if (hexStr[i] >= 'a' && hexStr[i] <= 'f') {
                    val += (10U + ((uint32_t)(hexStr[i]) - 0x61U));
                } else {
                    val += (10U + ((uint32_t)(hexStr[i]) - 0x41U));
                }
                i++;
                retVal = BCM_ERR_OK;
            }
        } else {
            retVal = BCM_ERR_INVAL_PARAMS;
        }
    }

    if(BCM_ERR_OK == retVal) {
        *aHexVal = val;
    }

    return retVal;
}

void FLASHER_FullInstallOpt(BCM_BoolType *aIsInstall)
{
    char option;
    *aIsInstall = BCM_BOOL_FALSE;

    if(BCM_BOOL_TRUE == isUserOption) {
        if(FLASHER_CONFIRM_FULL_INSTALL == (userOptionMask & FLASHER_CONFIRM_FULL_INSTALL)) {
            *aIsInstall = BCM_BOOL_TRUE;
        }
    } else {
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "Not booted from flash. Continue to Full install [Y/N] : ");
        (void)scanf("%c",&option);
        if(('Y' == option) || ('y' == option)) {
            *aIsInstall = BCM_BOOL_TRUE;
        }
    }
}

void FLASHER_SafeInstallRollbackOpt(BCM_BoolType *aIsRollBack)
{
    char option;

    *aIsRollBack = BCM_BOOL_FALSE;
    if(BCM_BOOL_TRUE == isUserOption) {
        if (FLASHER_CONFIRM_ROLL_BACK == (userOptionMask & FLASHER_CONFIRM_ROLL_BACK)) {
            *aIsRollBack = BCM_BOOL_TRUE;
        }
    } else {
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "Roll back to boot from previous version?\n");
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "[Y] Boot the old version from copy 1. Copy 3 still have new version\n");
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "    User have to manually sync and boot to new version\n");
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "[N] Sync new version to Copy1 and Copy2 and boot from Copy 1\n");
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "[Y/N] : ");
        (void)scanf("%c",&option);
        if(('Y' == option) || ('y' == option)) {
            *aIsRollBack = BCM_BOOL_TRUE;
        }
    }
}

void FLASHER_Wait(uint32_t aTime)
{
    sleep(aTime);
}

int FLASHER_main(int argc, const char *argv[])
{
    const uint8_t *sockName = (const uint8_t *)RPC_SOCKET_NAME;
    int32_t              retVal = BCM_ERR_OK;
    uint32_t             i;
    uint16_t             port          = 0U;
    uint32_t             flsId         = 0UL;
    uint32_t             eraseSize     = 0UL;
    uint32_t             errExit       = 0UL;
    uint32_t             line          = __LINE__;
    PTU_TarImageInfoType imagesInfo[PTU_TAR_MAX_IMG_COUNT] = {0};
    uint32_t             numImgs       = 0U;
    uint32_t             fileSize      = 0U;
    IMGL_ChannelType     mode          = IMGL_CHANNEL_ID_RPC_FTP;
    BCM_BoolType         isSafeInstall = BCM_BOOL_FALSE;
    pthread_t            threadId;
    UPDATE_InstallCfgMsgType install = {0}; /* Store the install related information given as input. */
    char userOpt[FLASHER_MAX_USER_OPT_MASK_STR_LENGTH];
    PTBL_Type ptbl;

     for(i = 1; i < argc; i++) {
        if (0 == strcmp("-l", argv[i])) {
            i++;
            if (NULL != argv[i]) {
                int err = inet_pton(AF_INET, argv[i], &address.sin_addr);
                if (0 < err) {
                    install.ipAddr = CPU_BEToNative32(address.sin_addr.s_addr);
                } else {
                    printf("inet_pton returned %d\n", err);
                }
                if (0U == port) {
                    port = 5555U;
                }
            } else {
                line = __LINE__;
                errExit = 1UL;
            }
        } else if (0 == strcmp("-r", argv[i])) {
            i++;
            if (NULL != argv[i]) {
                sockName = (const uint8_t *)argv[i];
            } else {
                line = __LINE__;
                errExit = 1UL;
            }
        } else if (0 == strcmp("-m", argv[i])) {
            i++;
            if (NULL != argv[i]) {
                mode = atoi(argv[i]);
                if (0UL == mode) {
                    mode = IMGL_CHANNEL_ID_RPC_FTP;
                } else {
                    mode = IMGL_CHANNEL_ID_RPC_IPC;
                }
            } else {
                line = __LINE__;
                errExit = 1UL;
            }
        } else if (0 == strcmp("-s", argv[i])) {
            isSafeInstall = BCM_BOOL_TRUE;
        } else if (0 == strcmp("-p", argv[i])) {
            i++;
            if (NULL != argv[i]) {
                port =atoi(argv[i]);
            } else {
                line = __LINE__;
                errExit = 1UL;
            }
        } else if (0 == strcmp("-i", argv[i])) {
            i++;
            if (NULL != argv[i]) {
                flsId =atoi(argv[i]);
            } else {
                line = __LINE__;
                errExit = 1UL;
            }
        } else if (0 == strcmp("-u", argv[i])) {
            i++;
            if (NULL != argv[i]) {
                isUserOption = BCM_BOOL_TRUE;
                if(FLASHER_MAX_USER_OPT_MASK_STR_LENGTH >= strlen(argv[i])) { /* expects Max of 32-bit Hex value */
                    (void)strcpy(userOpt,argv[i]);
                    if(BCM_ERR_OK != FLASHER_AsciiToHex(userOpt, strlen(argv[i]), &userOptionMask)) {
                        line = __LINE__;
                        errExit = 1UL;
                    }
                } else {
                    line = __LINE__;
                    errExit = 1UL;
                }
            } else {
                line = __LINE__;
                errExit = 1UL;
            }
        } else if (0 == strcmp("-e", argv[i])) {
            i++;
            if (NULL != argv[i]) {
                eraseSize = atoi(argv[i]);
            } else {
                line = __LINE__;
                errExit = 1UL;
            }
        } else if (0 == strcmp("-f", argv[i])) {
            i++;
            printf("file Name =  %s\n", argv[i]);
/* @event            Filesystem path, filename, or URI manipulation (PATH_MANIPULATION), Resource leak (RESOURCE_LEAK)
   @issue            Constructing a path or URI using the tainted value **argv and passing it to fopen.\
                     This may allow an attacker to access, modify, or test the existence of critical or sensitive files.\
                     Overwriting FLASHER_Fp in FLASHER_Fp = fopen(argv[i], "rb") leaks the storage that FLASHER_Fp points to.
   @risk             None.
   @justification    Allowing only static filename to fopen() would restrict the flexibilty of it's usage.\
                     FLASHER_Fp is closed at the end of this function. */
/* coverity[path_manipulation_sink] */
/* coverity[overwrite_var] */
            FLASHER_Fp = fopen(argv[i], "rb");
            if(FLASHER_Fp == NULL) {
                printf("Failed to open file %s\n", argv[i]);
                line = __LINE__;
                errExit = 1UL;
            }
            if((1UL != errExit) && (0L != stat(argv[i], &statbuf))) {
                printf("Failed to get file stats %s\n", argv[i]);
                line = __LINE__;
                errExit = 1UL;
            } else {
                BCM_MemCpy(install.name, argv[i], strlen(argv[i]));
            }
        } else {
            FLASHER_PrintUsage();
            line = __LINE__;
            errExit = 1UL;
        }

        if(1UL == errExit) {
           BCM_LOG_INFO(0U, BCM_STATE_RUN, "Inavlid arguments. Line number = %d\n", line);
           FLASHER_PrintUsage();
           exit(1);
        }
    }

    if ((NULL == FLASHER_Fp) ||
        ((IMGL_CHANNEL_ID_RPC_FTP != mode) && (IMGL_CHANNEL_ID_RPC_IPC != mode)) ||
        ((IMGL_CHANNEL_ID_RPC_FTP == mode) && (0UL == install.ipAddr))) {
        FLASHER_PrintUsage();
        exit(1);
    }

    /*
    if(0UL == eraseSize) {
        // Read the file to a buffer to parse and find the total image size
        retVal = FLASHER_ReadImgFromFile(FLASHER_Fp, FLASHER_FileBuff, &fileSize);
        if(BCM_ERR_OK == retVal) {
            retVal = PTU_ParseImage(FLASHER_FileBuff, fileSize, PTU_TAR_MAX_IMG_COUNT, imagesInfo, &numImgs);
            if(BCM_ERR_OK == retVal) {
                // read from first Partition Table Entry
                memcpy(&ptbl, &FLASHER_FileBuff[imagesInfo[0].offset + PTU_TAR_HDR_SIZE], sizeof(ptbl));
                retVal = FLASHER_GetImageMaxSize(&ptbl, &eraseSize);
                if(BCM_ERR_OK == retVal) {
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "eraseSize =  %x\n", eraseSize);
                } else {
                    BCM_LOG_INFO(0U, BCM_STATE_RUN, "Failed to get the Image size.\n");
                }
            }
        }
    }
    */

    if(BCM_ERR_OK == retVal) {
        if (IMGL_CHANNEL_ID_RPC_FTP == mode) {
            pthread_barrier_init(&FLASHER_BusBarrier, NULL, 2UL);
            (void)pthread_create(&threadId, NULL, &FLASHER_DataThread, NULL);
            pthread_barrier_wait(&FLASHER_BusBarrier);
        }

        install.nvmChannel   = IMGL_CHANNEL_ID_NVM_0 + flsId;
        install.fetchChannel = mode;
        install.nvmEraseSize = eraseSize;
        install.fileSize = statbuf.st_size;
        install.portNum      = CPU_BEToNative16(address.sin_port);;
        retVal = FLASHER_InstallStateHandler(sockName, port, isSafeInstall, &install);
    }

    if (BCM_ERR_OK == retVal) {
        BCM_LOG_INFO(0U, BCM_STATE_RUN, "Request completed Successfully\n");
    }
    fclose(FLASHER_Fp);
    return 0;
}
