/***********************************************************************************************
	created: 		2020-11-21

	author:			chensong

	purpose:		148. 排序链表
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它。
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服。
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界。
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心。
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心。
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀。
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边。
我叫他本心猎手。他可能是和宇宙同在的级别 但是我并不害怕，我仔细回忆自己平淡的一生 寻找本心猎手的痕迹。
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来。
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来。
************************************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    struct ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != NULL) {
        temp->next = temp1;
    } else if (temp2 != NULL) {
        temp->next = temp2;
    }
    return dummyHead->next;
}

struct ListNode* toSortList(struct ListNode* head, struct ListNode* tail) {
    if (head == NULL) {
        return head;
    }
    if (head->next == tail) {
        head->next = NULL;
        return head;
    }
    struct ListNode *slow = head, *fast = head;

    while (fast != tail)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) //这边使用快慢指针
        {
            fast = fast->next;
        }
    }
    struct ListNode* mid = slow;
    return merge(toSortList(head, mid), toSortList(mid, tail));
}

//归并排序 时间复杂度O(N * log N)
struct ListNode* sortList(struct ListNode* head) {
    return toSortList(head, NULL);
}


struct ListNode* sortLis000t1(struct ListNode* head)
{
    if (!head)
    {
        return head;
    }
    //新的有序链表的定义
    struct ListNode * pre_list_node_ptr = NULL; //当前节点父节点
    struct ListNode * cur_list_node_ptr = head; //当前节点
    struct ListNode * next_list_node_ptr = cur_list_node_ptr->next;

    //当前找到节点
    struct ListNode * pre_index_list_node_ptr = cur_list_node_ptr;
    struct ListNode * cur_index_list_node_ptr = pre_index_list_node_ptr->next;
    struct ListNode * next_index_list_node_ptr = NULL;
    //有序链表的个数记录
    int num = 1;
    while (cur_index_list_node_ptr)
    {
        pre_list_node_ptr = NULL;
        cur_list_node_ptr = head;
        //1. 记录当前从头节点查找的个数
        int  head_num  = 0;
        //2. 从头节点找到比当前节点要小的数的位置插入
        while (head_num < num && cur_list_node_ptr->val <= cur_index_list_node_ptr->val)//这边等于情况也要考虑到的[4,19,14,5,-3,1,8,5,11,15, -3]
        {
            // printf("head_num = %d, num = %d\n", head_num, num);
            ++head_num;
            pre_list_node_ptr = cur_list_node_ptr;
            cur_list_node_ptr = pre_list_node_ptr->next;
        }
        next_index_list_node_ptr = cur_index_list_node_ptr->next;
        // if (cur_index_list_node_ptr->val )
        head_num = 1;  //查看后面数字是否小于当前值防止下次再查找
        while (next_index_list_node_ptr && next_index_list_node_ptr->val >= cur_index_list_node_ptr->val && next_index_list_node_ptr->val <= cur_list_node_ptr->val)
        {
            ++head_num;
            cur_index_list_node_ptr = next_index_list_node_ptr;
            next_index_list_node_ptr = cur_index_list_node_ptr->next;
        }
        // 插入头节点
        if (!pre_list_node_ptr)
        {

            // pre_index_list_node_ptr->next = cur_index_list_node_ptr->next;//修改当前节点的父节点指向节点
            // pre_list_node_ptr = cur_index_list_node_ptr;
            // pre_list_node_ptr->next = cur_list_node_ptr;
            // head = pre_list_node_ptr;

            pre_list_node_ptr = pre_index_list_node_ptr->next;
            cur_index_list_node_ptr->next = cur_list_node_ptr;
            pre_index_list_node_ptr->next = next_index_list_node_ptr;
            head = pre_list_node_ptr;
            // pre_index_list_node_ptr = cur_index_list_node_ptr;
            pre_index_list_node_ptr->next = next_index_list_node_ptr;
        }
        else if (cur_list_node_ptr && cur_list_node_ptr->val > cur_index_list_node_ptr->val )
        {
            //  pre_index_list_node_ptr->next = cur_index_list_node_ptr->next;//修改当前节点的父节点指向节点
            // pre_list_node_ptr->next = cur_index_list_node_ptr;
            // cur_index_list_node_ptr->next = cur_list_node_ptr;
            pre_list_node_ptr->next = pre_index_list_node_ptr->next;
            cur_index_list_node_ptr->next = cur_list_node_ptr;
            pre_index_list_node_ptr->next = next_index_list_node_ptr;

        }
        else
        {
            pre_index_list_node_ptr = cur_index_list_node_ptr; //修改当前头节点的指针了
        }
        cur_index_list_node_ptr = pre_index_list_node_ptr->next;
        num+=head_num;
        // return head;
        // printf("num = %d\n", num);

    }

    return head;
}

// [4,19,14,5,-3,1,8,5,11,15, -3]
int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}