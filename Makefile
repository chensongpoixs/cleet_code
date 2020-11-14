.SUFFIXES: .c .o  

V       := @                                                                                                                                                                                                                       
CC = gcc 
BIN_PATH = bin 
EXE21 = 21.合并两个有序链表
EXE328 = 328.奇偶链表

SRCS21 = $(EXE21)/21.merge_two_sorted_lists.c
SRCS328 = $(EXE328)/328.Odd_Even_Linked_List.c
OBJS21 = $(SRCS21:.c = .o)
OBJS328 = $(SRCS328:.c = .o)



all: $(OBJS21) $(OBJS328)
    $(CC) -o bin/$(EXE21)  $(OBJS21) -Wall -g
	$(CC) -o bin/$(EXE328)  $(OBJS328) -Wall -g
    $(V)echo '$(EXE21)  ^_^ ^_^ 陈丽 ^_^ ^_^'

#模式匹配
%.c%.o:
    $(V)echo '$@++++++$^ ^_^ ^_^ 陈丽 ^_^ ^_^'
    $(CC) -Wall -g -o $@ -c $^


.PHONY: exepath clean                                                                                                                                                                                                               
exepath:
	$(V)mkdir $(BIN_PATH)
#clean 清空二进制文件
clean:
    -rm -f bin