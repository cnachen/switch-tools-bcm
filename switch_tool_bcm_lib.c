#define GNU
#define RPC_MSG_PAYLOAD_SZ 448UL
#define ITBL_MAX_NUM_ENTRIES 20

#define HOST_IP "192.168.1.1"
#define SWITCH_IP "192.168.1.100"
#define SWITCH_PORT 5555
#define SWITCH_FW_SIZE "4194304"

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <system_dmon.h>
#include <nvm_update.h>
#include <rpc_msg.h>
#include <bcm_err.h>
#include <cpu_utils.h>

#include "flasher_interface.h"

int get_switch_version(char *buffer, size_t buffer_size)
{
    BCM_HandleType handle;
    DMON_SwVersionMsgType swVersion;

    if (RPC_Open(SWITCH_IP, SWITCH_PORT, 60000, &handle) != BCM_ERR_OK) {
        fprintf(stderr, "RPC_Open failed...\n");
        return -BCM_ERR_UNKNOWN;
    }

    if (DMON_GetSwVersion(handle, &swVersion) != BCM_ERR_OK) {
        fprintf(stderr, "DMON_GetSwVersion failed...\n");
        return -BCM_ERR_INVAL_PARAMS;
    }
    strncpy(buffer, swVersion.str, buffer_size);

    RPC_Close(handle);
    return BCM_ERR_OK;
}

int flash_switch(const char *filename)
{
    const int argc = 13;
    const char *argv[] = {
        "flasher",
        "-f", filename,
        "-m", "0",
        "-l", HOST_IP,
        "-r", SWITCH_IP,
        "-p", "5555",
        "-e", SWITCH_FW_SIZE
    };
    return FLASHER_main(argc, argv);
}
