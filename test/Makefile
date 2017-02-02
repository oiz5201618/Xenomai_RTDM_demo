obj-m += testmod.o

#ccflags-y := -I/usr/xenomai/include/cobalt -I/usr/xenomai/include -march=armv7-a -mtune=cortex-a8 -mfpu=neon -ffast-math -D_GNU_SOURCE -D_REENTRANT -D__COBALT__ -D__COBALT_WRAP__

CROSS_COMPILE = arm-linux-gnueabihf-
CC = $(CROSS_COMPILE)gcc
ARCH = arm
KERNELDIR := ~/Desktop/kernel_source_full
ldflags-y := -L/usr/arm-linux-gnueabihf


all:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNELDIR) M=`pwd` modules

clean:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNELDIR) M=`pwd` clean
