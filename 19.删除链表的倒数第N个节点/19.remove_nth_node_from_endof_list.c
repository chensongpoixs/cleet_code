/***********************************************************************************************
	created: 		2020-11-05

	author:			chensong

	purpose:		18.18. 四数之和
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它�?
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服�?
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界�?
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心�?
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心�?
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀�?
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边�?
我叫他本心猎手。他可能是和宇宙同在的级�?但是我并不害怕，我仔细回忆自己平淡的一�?寻找本心猎手的痕迹�?
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来�?
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来�?
************************************************************************************************/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define bool int
#define true 1
#define false 0


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    if (!head || n<=0)
    {
        return head;
    }
    struct ListNode* new_node_ptr = head;

    struct ListNode* pre_node_ptr = head; //它走先n步我再走一步的操作
    struct ListNode* new_head_ptr = pre_node_ptr;
//    struct ListNode* node_ptr = NULL;
    int step = 0;//步长
    while (new_node_ptr->next)
    {
        if (step>=n)
        {
            pre_node_ptr =  pre_node_ptr->next;

        }
        new_node_ptr = new_node_ptr->next;
        ++step;
    }
    //1.去除第一个节点特殊位置的节点 字符串第一个字符的取出
    if ((step+1) <= n)
    {
        new_head_ptr = (struct ListNode *)pre_node_ptr->next;
    }

    //2. 去除中的节点
    if (step>=n)
    {
        new_node_ptr = pre_node_ptr->next;
        if (!new_node_ptr)
        {
            pre_node_ptr->next = NULL;
        }
        else
        {
            pre_node_ptr->next = new_node_ptr->next;
        }
    }

    return (struct ListNode*)new_head_ptr;
}

int main(int argc, char *argv[])
{

    if (argc < 1)
    {
        printf("use ./test 2 3 4 5 6 4  3");
        return -1;
    }
    struct ListNode * input_list_node = NULL;
    struct ListNode * input_head_node = NULL;
    for (int i = 1; i < argc -1; ++i)
    {
        struct ListNode * new_list_node = malloc(sizeof(struct ListNode));
        if (!input_head_node)
        {
            input_head_node = new_list_node;
            input_list_node = new_list_node;
        }
        else
        {
            input_list_node->next = new_list_node;
            input_list_node = new_list_node;
        }
        input_list_node->val = atoi(argv[i]);
    }

    struct ListNode * out_list_node = removeNthFromEnd(input_head_node, atoi(argv[argc-1]) );
    printf("[");
    if (out_list_node)
    {
        while (out_list_node)
        {
            printf("%d, ", out_list_node->val);
            struct ListNode * next_list_node = out_list_node->next;
            free(out_list_node);
            out_list_node = next_list_node;
        }
    }
    printf("]\n");

//    while (input_head_node)
//    {
//        struct ListNode * next_list_node = input_head_node->next;
//        free(input_head_node);
//        input_head_node = next_list_node;
//    }
    return 0;
}