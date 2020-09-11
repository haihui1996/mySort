# ָ��������
CC := gcc
LD := ld
OBJCOPY := objcopy
OBJDUMP := objdump

# export CC LD OBJDUMP OBJCOPY

# include alg/bubble/makefile
# include alg/insertion/makefile
# include main/makefile

# # INCDIRS �����������̵�ͷ�ļ�
# INCDIRS := main	\
# 		common \
# 		alg/bubble\
# 		alg/insertion

# # SRCDIRS �����������̵�c�ļ�
# SRCDIRS := main	\
# 			common \
			


# # ͨ��patsubst������ͷ�ļ���ӡ�-I��
# INCLUDE	:= $(patsubst %, -I %, $(INCDIRS))

# # ͨ��foreach������wildcard����������Ŀ¼�µ�.S/.c�ļ���ӵ�SFILES��CFILES
# SFILES	:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
# CFILES	:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

# # ͨ��notdir����ȥ��SFILES��CFILES�е�·��ֻ�����ļ���
# SFILENDIR	:= $(notdir $(SFILES))
# SFILENDIR	:= $(notdir $(CFILES))

# # SOBJS	:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
# # COBJS	:= $(patsubst %, obj/%, $(SFILENDIR:.c=.o))
# # OBJS	:= $(SOBJS) $(COBJS)

# VPATH := $(SRCDIRS)

# .PHONY: clean

# # CFLAGS =  -Wall -nostdlib -c  -o

# main.out: $(OBJS)
# 	$(LD) -o $@ $<

# %.o: %.c %.h
# 	$(CC) $(INCLUDE) $@ $<


main.out: main/main.o alg/bubble/bubble_sort.o alg/insertion/insertion.o common/common.o
	$(LD) -o $@ $<

%.o: %.c %.h
	$(CC) -c $@ $<

.PHONY: clean
clean:
	-rm -rf *.o *.out 