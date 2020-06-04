/***********************************************************************************************
created: 		2020-05-25

author:			chensong

purpose:		5. longest_palindromic_substring
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
#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>
#include <string.h>
/*
 * 5. ������Ӵ�
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�
ʾ�� 2��

����: "cbbd"
���: "bb"
 */

typedef  int bool;
#define true 1
#define false 0
/**
 * ���ػ����ַ�������
 * @param s
 * @param left
 * @param right
 * @return
 */
int expand_around_center(char * s, int left, int right)
{
	while ((left >= 0 && right <= strlen(s)) && (s[right] == s[left]) && (left <= right))
	{
		--left; ++right;
	}

	return right - left - 1;//�����ַ����ĳ���
}

char *ptr = NULL;

//bool dfs(char *s, bool * value, char *out_input)
//{
//
//    return false;
//}
/**
*
* @param s
* @return
*/
char * longestPalindrome(char * s)
{
	if (strlen(s)<2)
	{
		return s;
	}
	// between
	//    int len = strlen(s);
	int start = 0, end = 0;
	int max_len = 0;
	//    int str_len = strlen(s);
	for (int i = 0; i < strlen(s); ++i)
	{
		int left_len = expand_around_center(s, i, i);
		int right_len = expand_around_center(s, i, i + 1);
		int len = left_len >right_len ? left_len : right_len;
		printf("len = %d, right = %d, left = %d, i = %d\n", len, end, start, i);
		if (end - start <len)
		{
			start = i - (len - 1) / 2;
			end = i + len / 2;
			//            max_len = len;


		}
	}



	if (end - start > 0)
	{
		ptr = (char *)malloc(end - start + 2);
		if (!ptr)
		{
			printf("alloc failed !!!\n");
			return NULL;
		}
		memset(ptr, 0, end - start + 2);
		memcpy(ptr, s + start, end - start + 1);
		printf("ptr = %s, max_len = %d, right = %d, left = %d\n", (s + start), max_len, start, end);
		//        ptr[end -start +2] = '\0';
		return ptr;

	}

	printf("max_len = %d\n", max_len);

	return  &s[strlen(s) - 1];
}



int main(int argc, char *argv[])
{
//    ����: "cbbd"
//    ���: "bb"

    char * input = "cbbd";
    char * output =  longestPalindrome(input);
    if (!output)
    {
        printf("not find failed!!!\n");
    }
    else
    {
        printf("find = %s\n", output);
        if(ptr)
        {
            free(ptr);
            ptr = NULL;
        }
    }

//    pthread_create();
    return EXIT_SUCCESS;
}