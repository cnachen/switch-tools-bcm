CFLAGS		:=	-g -std=gnu17 -Wall
INCLUDES	:=	-I. -Iinclude
LIBRARIES	:=	-lbcm_rpc

ifeq ($(family),qnx)
	CC = aarch64-unknown-nto-qnx7.1.0-gcc
	INCLUDES += -I/etc/prebuilt_QOS220/target/qnx7/usr/include/io-sock
	LIBRARIES += -lsocket
else
	CC = gcc
	LIBRARIES += -lpthread
endif

all: libstb stb

libstb:
	$(CC) flasher_common.c flasher_linux.c switch_tool_bcm_lib.c \
	$(INCLUDES) $(LIBRARIES) \
	-fPIC -shared -o libswitch_tool_bcm.so

stb:
	$(CC) switch_tool_bcm.c \
	$(INCLUDES) -L. -lswitch_tool_bcm \
	-o switch_tool_bcm

clean:
	rm -f switch_tool_bcm libswitch_tool_bcm.so
