/***********************************************************************************************
created: 		2020-05-08

author:			chensong

purpose:		2. add_two_numbers
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

/**
*  2. 题目：给定两个非空链表来表示两个两个非负整数。位数按照逆序方式存储,他们的每个节点只存储单个数字。将两数相加返回一个新的链表。
*     你可以假设除了数字0之外,这两个数字都不会以零开头。
*
*  示例:
*    输入: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*    输出: 7 -> 0 -> 8
*    原因: 342 + 465 = 807
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct clist_node 
{
	int m_value;
	struct clist_node * m_next_node_ptr;
};


static struct clist_node* add_two_numbers(struct clist_node* l1, struct clist_node* l2)
{
	int carry_num = 0; ///是否进1
	int first = 1;
	struct clist_node * res = NULL;
	struct clist_node * p = NULL;
	struct clist_node * prev = NULL;
	while (l1 != NULL || l2 != NULL || carry_num)
	{
		int sum = 0;
		int last_carry = carry_num;
		if (l1 != NULL)
		{
			sum += l1->m_value;
			l1 = l1->m_next_node_ptr;
		}
		if (l2 != NULL)
		{
			sum += l2->m_value;
			l2 = l2->m_next_node_ptr;
		}

		if (sum >= 10)
		{
			sum -= 10;
			carry_num = 1;
		}
		else
		{
			carry_num = 0;
		}
		p = malloc(sizeof(*p));
		if (first)
		{
			res = p;
			first = 0;
		}
		p->m_value = sum + last_carry;
		if (p->m_value >= 10)
		{
			p->m_value -= 10;
			carry_num = 1;
		}
		p->m_next_node_ptr = NULL;
		if (prev != NULL)
		{
			prev->m_next_node_ptr = p;
		}
		prev = p;

	}
	return res;
}
static struct clist_node * node_build(const char * digits)
{
	struct clist_node * res = NULL, *p = NULL, *prev = NULL;
	int first = 1;
	size_t len = strlen(digits);
	const char * c = digits + len - 1;
	prev = NULL;
	while (len-- > 0)
	{
		p = malloc(sizeof(*p));
		if (first)
		{
			first = 0;
			res = p;
		}
		p->m_value = *c-- - '0';
		p->m_next_node_ptr = NULL;
		if (prev != NULL)
		{
			prev->m_next_node_ptr = p;
		}
		prev = p;
	}
	return res;
}



static void show(struct clist_node* ln)
{
	int sum = 0, factor = 1;
	while(ln != NULL)
	{
		sum += ln->m_value * factor;
		factor *= 10;
		ln = ln->m_next_node_ptr;
	}
	printf("%10d", sum);
}
int main(int argc, char *argv[])
{

	if (argc < 3)
	{
		fprintf(stderr, "Usage: ./test n1 n2");
		exit(-1);
	}

	struct clist_node * l1 = node_build(argv[1]);
	struct clist_node * l2 = node_build(argv[2]);
	struct clist_node * res = add_two_numbers(l1, l2);
	printf("one num = ");
	show(l1);
	printf("\none num = ");
	show(l2);
	printf("\nout num = ");
	show(res);
	printf("\n");
	struct clist_node * temp_ptr;
	while (l1)
	{
		temp_ptr = l1->m_next_node_ptr;
		free(l1);
		l1 = temp_ptr;
	}
	while (l2)
	{
		temp_ptr = l2->m_next_node_ptr;
		free(l2);
		l2 = temp_ptr;
	}
	while (res)
	{
		temp_ptr = res->m_next_node_ptr;
		free(res);
		res = temp_ptr;
	}
	return EXIT_SUCCESS;
}