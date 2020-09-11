# 指定编译器
CC := gcc
LD := ld
OBJCOPY := objcopy
OBJDUMP := objdump

# INCDIRS 包含整个工程的头文件
INCDIRS := main	\
		common \
		bubble

# SRCDIRS 包含整个工程的c文件
SRCDIRS := main	

# 通过patsubst函数给头文件添加“-I”
INCLUDE	:= $(patsubst %, -I %, $(INCDIRS))

# 通过foreach函数和wildcard函数将各个目录下的.S/.c文件添加到SFILES和CFILES
SFILES	:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES	:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

# 通过notdir函数去掉SFILES和CFILES中的路径只保留文件名
SFILENDIR	:= $(notdir $(SFILES))
SFILENDIR	:= $(notdir $(CFILES))

SOBJS	:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
COBJS	:= $(patsubst %, obj/%, $(SFILENDIR:.c=.o))
OBJS	:= $(SOBJS) $(COBJS)

VPATH := $(SRCDIRS)

.PHONY: clean

CFLAGS =  -Wall -nostdlib -c  -o

objs := main.o

main.out: $(objs)
	$(LD) -o $@ $<

%.o: %.c %.h
	$(CC) $(CCFLAGS) $(INCLUDE) $@ $<


clean:
	rm -rf *.o 