/***********************************************************************************************
created: 		2020-05-25

author:			chensong

purpose:		5. longest_palindromic_substring

************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>
#include <string.h>
/*
 * 5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
 */

typedef  int bool;
#define true 1
#define false 0
/**
 * 返回回文字符串长度
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

	return right - left - 1;//回文字符串的长度
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
//    输入: "cbbd"
//    输出: "bb"

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