# ָ��������
CC := gcc
LD := ld
OBJCOPY := objcopy
OBJDUMP := objdump

# INCDIRS �����������̵�ͷ�ļ�
INCDIRS := main	\
		common \
		bubble

# SRCDIRS �����������̵�c�ļ�
SRCDIRS := main	

# ͨ��patsubst������ͷ�ļ���ӡ�-I��
INCLUDE	:= $(patsubst %, -I %, $(INCDIRS))

# ͨ��foreach������wildcard����������Ŀ¼�µ�.S/.c�ļ���ӵ�SFILES��CFILES
SFILES	:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES	:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

# ͨ��notdir����ȥ��SFILES��CFILES�е�·��ֻ�����ļ���
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