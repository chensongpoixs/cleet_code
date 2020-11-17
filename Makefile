.SUFFIXES: .c .o  

V       := @                                                                                                                                                                                                                       
CC = gcc 
BIN_PATH = bin 
EXE21 = 21.合并两个有序链表
EXE328 = 328.奇偶链表
EXE402 = 402.移掉K位数字
EXE406 = 406.根据身高重建队列
EXE1030 = 1030.距离顺序排列矩阵单元格
EXE1476 = 1476.子矩形查询

SRCS21 = $(EXE21)/21.merge_two_sorted_lists.c
SRCS328 = $(EXE328)/328.Odd_Even_Linked_List.c
SRCS402 = $(EXE402)/402.Remove_K_Digits.c
SRCS406 = $(EXE406)/406.Queue_Reconstruction_by_Height.c
SRCS1030 = $(EXE1030)/1030.Matrix_Cells_in_Distance_Order.c
SRCS1476 = $(EXE1476)/1476.Subrectangle_Queries.c
OBJS21 = $(SRCS21:.c = .o)
OBJS328 = $(SRCS328:.c = .o)
OBJS402 = $(SRCS402:.c = .o)
OBJS406 = $(SRCS406:.c = .o)
OBJS1030 = $(SRCS1030:.c = .o)
OBJS1476 = $(SRCS1476:.c = .o)

#编写makefile 必须使用tab 

all: $(OBJS21) $(OBJS328) $(OBJS402)  $(OBJS406) $(OBJS1030) $(OBJS1476)
	$(CC) -o bin/$(EXE21)  $(OBJS21) -Wall -g
	$(CC) -o bin/$(EXE328)  $(OBJS328) -Wall -g
	$(CC) -o bin/$(EXE402)  $(OBJS402) -Wall -g
	$(CC) -o bin/$(EXE406)  $(OBJS406) -Wall -g
	$(CC) -o bin/$(EXE1030)  $(OBJS1030) -Wall -g
	$(CC) -o bin/$(EXE1476)  $(OBJS1476) -Wall -g
	$(V)echo '$(EXE21)  ^_^ ^_^ 陈丽 ^_^ ^_^'

#模式匹配
%.c%.o:
	$(CC) -Wall -g -o $@ -c $^
	$(V)echo '$@++++++$^ ^_^ ^_^ 陈丽 ^_^ ^_^'

.PHONY: path clean                                                                                                                                                                                                               
path:
	$(V)mkdir $(BIN_PATH)
#clean 清空二进制文件
clean:
	-rm -f bin
