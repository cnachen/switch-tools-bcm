#include <stdio.h>

#include "switch_tool_bcm.h"

int main()
{
    char buffer[114];
    get_switch_version(buffer, 114);
    printf("%s\n", buffer);

    flash_switch("/tmp/fwnt.img");
    printf("flash done\n");

    get_switch_version(buffer, 114);
    printf("%s\n", buffer);
}
