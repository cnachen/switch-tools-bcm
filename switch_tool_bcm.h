#ifndef _SWITCH_TOOL_BCM_H
#define _SWITCH_TOOL_BCM_H

int get_switch_version(char *buffer, size_t buffer_size);

int flash_switch(const char *filename);

#endif
