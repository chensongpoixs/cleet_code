/***********************************************************************************************
created: 		2020-05-08

author:			chensong

purpose:		2. add_two_numbers
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

/**
*  2. ��Ŀ�����������ǿ���������ʾ���������Ǹ�������λ����������ʽ�洢,���ǵ�ÿ���ڵ�ֻ�洢�������֡���������ӷ���һ���µ�����
*     ����Լ����������0֮��,���������ֶ��������㿪ͷ��
*
*  ʾ��:
*    ����: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*    ���: 7 -> 0 -> 8
*    ԭ��: 342 + 465 = 807
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
	int carry_num = 0; ///�Ƿ��1
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