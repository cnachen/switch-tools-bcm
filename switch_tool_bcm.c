#include <stdio.h>
#include <string.h>

#include "switch_tool_bcm.h"

#define VERSION "1.0.0"
#define BUFFER_SIZE 128

int main(int argc, char *argv[])
{
    if (argc == 1)
        goto help;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-h")) {
            goto help;
        } else if (!strcmp(argv[i], "-v")) {
            char buffer[BUFFER_SIZE];
            if (get_switch_version(buffer, BUFFER_SIZE)) {
                printf("get_switch_version failed...\n");
                return 1;
            }
            printf("%s\n", buffer);
        } else if (!strcmp(argv[i], "-f")) {
            if (i + 1 >= argc || flash_switch(argv[++i])) {
                printf("flash_switch failed...\n");
                return 1;
            }
        }
    }

    return 0;
help:
    printf("stb %s\n", VERSION);
    printf("Usage: %s <OPTION>\n", argv[0]);
    printf("Options:\n");
    printf("\t-h\t\tPrint this help\n");
    printf("\t-v\t\tGet switch version\n");
    printf("\t-f <FILE>\tFlash switch firmware\n");
}
