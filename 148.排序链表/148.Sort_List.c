/***********************************************************************************************
	created: 		2020-11-21

	author:			chensong

	purpose:		148. ��������
�ҿ��ܻ������ܶ���ˣ������ǽ���2��Ĺ��£�����д�ɹ��»��ɸ裬����ѧ���ĸ���������������
Ȼ�󻹿�����һ����������һ�������ҵĹ�������ܻᱻ��˧����������ֻᱻ��������ں���������ĳ�������ҹ������ȫ����͸Ȼ��Ҫ������С��ס�������ϵ�ʪ�·���
3Сʱ���������������ʵ��������ҵĹ�������Ը���򸸻���顣�Ҳ����Ѹ��������Ǵ�Խ�����������ǣ���ʼ��Ҫ�ص��Լ������硣
Ȼ���ҵ���Ӱ������ʧ���ҿ������������ˮ������ȴû���κ�ʹ�࣬�Ҳ�֪����ԭ���ҵ��ı������ˣ�������ȫ�����ԭ�򣬾���Ҫ�һ��Լ��ı��ġ�
�����ҿ�ʼ����Ѱ�Ҹ��ָ���ʧȥ�ĵ��ˣ��ұ��һ��שͷ��һ������һ��ˮ��һ����ƣ�ȥ�����Ϊʲô��ʧȥ�Լ��ı��ġ�
�ҷ��֣��ճ����ı��������Ļ��ڣ������ģ����ǵı��ľͻ���ʧ���յ��˸��ֺڰ�֮�����ʴ��
��һ�����ۣ������ʺͱ��ߣ�����ί����ʹ�࣬�ҿ���һֻֻ���ε��֣������ǵı��ĳ��飬�ɱΣ�͵�ߣ���Ҳ�ز������˶���ߡ�
�ҽ����������֡��������Ǻ�����ͬ�ڵļ��� �����Ҳ������£�����ϸ�����Լ�ƽ����һ�� Ѱ�ұ������ֵĺۼ���
�����Լ��Ļ��䣬һ�����ĳ�����������������֣��ҵı��ģ�����д�����ʱ�򣬻������
��������Ȼ����������ҵ�һ�У�д��������ұ��Ļع����÷�ʽ���һ�û�ҵ��������֣��������ţ�˳�������������һ����˳�����ϣ�������������
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
        if (fast != tail) //���ʹ�ÿ���ָ��
        {
            fast = fast->next;
        }
    }
    struct ListNode* mid = slow;
    return merge(toSortList(head, mid), toSortList(mid, tail));
}

//�鲢���� ʱ�临�Ӷ�O(N * log N)
struct ListNode* sortList(struct ListNode* head) {
    return toSortList(head, NULL);
}


struct ListNode* sortLis000t1(struct ListNode* head)
{
    if (!head)
    {
        return head;
    }
    //�µ���������Ķ���
    struct ListNode * pre_list_node_ptr = NULL; //��ǰ�ڵ㸸�ڵ�
    struct ListNode * cur_list_node_ptr = head; //��ǰ�ڵ�
    struct ListNode * next_list_node_ptr = cur_list_node_ptr->next;

    //��ǰ�ҵ��ڵ�
    struct ListNode * pre_index_list_node_ptr = cur_list_node_ptr;
    struct ListNode * cur_index_list_node_ptr = pre_index_list_node_ptr->next;
    struct ListNode * next_index_list_node_ptr = NULL;
    //��������ĸ�����¼
    int num = 1;
    while (cur_index_list_node_ptr)
    {
        pre_list_node_ptr = NULL;
        cur_list_node_ptr = head;
        //1. ��¼��ǰ��ͷ�ڵ���ҵĸ���
        int  head_num  = 0;
        //2. ��ͷ�ڵ��ҵ��ȵ�ǰ�ڵ�ҪС������λ�ò���
        while (head_num < num && cur_list_node_ptr->val <= cur_index_list_node_ptr->val)//��ߵ������ҲҪ���ǵ���[4,19,14,5,-3,1,8,5,11,15, -3]
        {
            // printf("head_num = %d, num = %d\n", head_num, num);
            ++head_num;
            pre_list_node_ptr = cur_list_node_ptr;
            cur_list_node_ptr = pre_list_node_ptr->next;
        }
        next_index_list_node_ptr = cur_index_list_node_ptr->next;
        // if (cur_index_list_node_ptr->val )
        head_num = 1;  //�鿴���������Ƿ�С�ڵ�ǰֵ��ֹ�´��ٲ���
        while (next_index_list_node_ptr && next_index_list_node_ptr->val >= cur_index_list_node_ptr->val && next_index_list_node_ptr->val <= cur_list_node_ptr->val)
        {
            ++head_num;
            cur_index_list_node_ptr = next_index_list_node_ptr;
            next_index_list_node_ptr = cur_index_list_node_ptr->next;
        }
        // ����ͷ�ڵ�
        if (!pre_list_node_ptr)
        {

            // pre_index_list_node_ptr->next = cur_index_list_node_ptr->next;//�޸ĵ�ǰ�ڵ�ĸ��ڵ�ָ��ڵ�
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
            //  pre_index_list_node_ptr->next = cur_index_list_node_ptr->next;//�޸ĵ�ǰ�ڵ�ĸ��ڵ�ָ��ڵ�
            // pre_list_node_ptr->next = cur_index_list_node_ptr;
            // cur_index_list_node_ptr->next = cur_list_node_ptr;
            pre_list_node_ptr->next = pre_index_list_node_ptr->next;
            cur_index_list_node_ptr->next = cur_list_node_ptr;
            pre_index_list_node_ptr->next = next_index_list_node_ptr;

        }
        else
        {
            pre_index_list_node_ptr = cur_index_list_node_ptr; //�޸ĵ�ǰͷ�ڵ��ָ����
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