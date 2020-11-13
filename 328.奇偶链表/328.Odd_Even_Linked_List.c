/***********************************************************************************************
	created: 		2020-11-13

	author:			chensong

	purpose:		328. 奇偶链表
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


struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head)
{
    if (!head)
    {
        return NULL;
    }
    struct ListNode * oddlist = NULL; //奇数链表
    struct ListNode * evenlist  = NULL; //偶数链表
    struct ListNode * oddlist_head = NULL;
    struct ListNode * eventlist_head = NULL; // 偶数链表头结点
    struct ListNode * cur_list = NULL;
    int cur_node_index = 0;
    while (head)
    {
        cur_list =  head;
        head = cur_list->next;
        cur_list->next = NULL;
        if (cur_node_index % 2 == 0)
        {
            if (!oddlist)
            {
                oddlist = cur_list;
                oddlist_head = oddlist;
            }
            else
            {
                oddlist->next = cur_list;
                oddlist = cur_list;
            }
        }
        else
        {
            if (!evenlist)
            {
                evenlist = cur_list;
                eventlist_head = evenlist;
            }
            else
            {
                evenlist->next = cur_list;
                evenlist = cur_list;
            }
        }
        ++cur_node_index;
    }
    //大于两个结点的情况
    if (eventlist_head)
    {
        oddlist->next = eventlist_head;
    }
    return oddlist_head;
}



int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("usage: ./test 23 3 33 3 4 5\n");
        return -1;
    }

    struct ListNode* list_head = NULL;

    struct ListNode * cur_list = NULL;
    printf("[ ");
    for (int i = 1; i < argc; ++i)
    {
        if (i != 1)
        {
            printf(", ");
        }
        struct ListNode* new_list = malloc(sizeof(struct ListNode));
        new_list->next = NULL;
        new_list->val  =atoi(argv[i]);;
        if (!list_head)
        {
            list_head = new_list;
            cur_list = new_list;
        }
        else
        {
            cur_list->next = new_list;
            cur_list = new_list;
        }

        printf("%s ", argv[i]);

    }
    printf("]\n");

    struct ListNode * order_arrays = oddEvenList(list_head);

    printf("[ ");
    while (order_arrays)
    {

        printf("%d ,", order_arrays->val);
        struct ListNode * next_list = order_arrays->next;
        free(order_arrays);
        order_arrays = NULL;
        order_arrays = next_list;
    }
    printf("]\n");
    return 0;
}
