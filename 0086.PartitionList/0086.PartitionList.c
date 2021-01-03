/***********************************************************************************************
	created: 		2021-01-03

	author:			chensong

	purpose:		86. �ָ�����
�ҿ��ܻ������ܶ���ˣ������ǽ���2��Ĺ��£�����д�ɹ��»��ɸ裬����ѧ���ĸ�������������??
Ȼ�󻹿�����һ����������һ�������ҵĹ�������ܻᱻ��˧����������ֻᱻ��������ں���������ĳ�������ҹ������ȫ����͸Ȼ��Ҫ������С��ס�������ϵ�ʪ�·�??
3Сʱ���������������ʵ��������ҵĹ�������Ը���򸸻���顣�Ҳ����Ѹ��������Ǵ�Խ�����������ǣ���ʼ��Ҫ�ص��Լ�������??
Ȼ���ҵ���Ӱ������ʧ���ҿ������������ˮ������ȴû���κ�ʹ�࣬�Ҳ�֪����ԭ���ҵ��ı������ˣ�������ȫ�����ԭ�򣬾���Ҫ�һ��Լ��ı���??
�����ҿ�ʼ����Ѱ�Ҹ��ָ���ʧȥ�ĵ��ˣ��ұ��һ��שͷ��һ������һ��ˮ��һ����ƣ�ȥ�����Ϊʲô��ʧȥ�Լ��ı���??
�ҷ��֣��ճ����ı��������Ļ��ڣ������ģ����ǵı��ľͻ���ʧ���յ��˸��ֺڰ�֮�����ʴ??
��һ�����ۣ������ʺͱ��ߣ�����ί����ʹ�࣬�ҿ���һֻֻ���ε��֣������ǵı��ĳ��飬�ɱΣ�͵�ߣ���Ҳ�ز������˶����??
�ҽ����������֡��������Ǻ�����ͬ�ڵļ�??�����Ҳ������£�����ϸ�����Լ�ƽ����һ??Ѱ�ұ������ֵĺۼ�??
�����Լ��Ļ��䣬һ�����ĳ�����������������֣��ҵı��ģ�����д�����ʱ�򣬻����??
��������Ȼ����������ҵ�һ�У�д��������ұ��Ļع����÷�ʽ���һ�û�ҵ��������֣��������ţ�˳�������������һ����˳�����ϣ�����������??
************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
        int val;
         struct ListNode *next;
     };

struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode * first_head = NULL;
    struct ListNode * first = NULL;
    struct ListNode * second_head = NULL;
    struct ListNode * second = NULL;
    for (struct ListNode * cur_node = head; cur_node != NULL; )
    {
        /*cur_node = cur_node->next*/
        if (cur_node->val < x)
        {
            if (!first)
            {
                first_head = cur_node;
                cur_node = cur_node->next;
                first_head->next = NULL;
                first = first_head;
            }
            else
            {
                first->next = cur_node;
                cur_node = cur_node->next;
                first = first->next;
                first->next = NULL;
            }
        }
        else
        {
            if (!second)
            {
                second_head = cur_node;
                cur_node = cur_node->next;
                second_head->next = NULL;
                second = second_head;
            }
            else
            {
                second->next = cur_node;
                cur_node = cur_node->next;
                second = second->next;
                second->next = NULL;
            }
        }
    }

    if (first)
    {
        first->next = second_head;
        return first_head;
    }

    return second_head;
}



int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}