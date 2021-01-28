/***********************************************************************************************
created: 		2020-05-08

author:			chensong

purpose:		 3.longest_substring_without_repeating_characters

************************************************************************************************/

/**
*  2. 题目：
*		给定一个字符串,找出不含有重复字符的最长子串的长度。
*		
*
*  示例:
*    给定"abcabcbb"，没有重复字符的最长子串是"abc",那么长度就是3
*    给定"bbbbb"  最长的子串是"b",长度是1
*    给定"pwwkew",最长子串是"wke“，长度是3
*    请注意答案必须是一个子串,"pwke"是子序列 而不是子串。
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int length_of_longest_substring(char *s)
{
	int offset[128];
	int max_len = 0;
	int len = 0;
	int index = 0;
	memset(offset, 0XFF, sizeof(offset));
	while (*s != '\0')
	{
		if (offset[*s] == -1)
		{
			++len;
		}
		else
		{
			if (index - offset[*s] > len)
			{
				++len;
			}
			else
			{
				len = index - offset[*s];
			}
		}
		if (len > max_len)
		{
			max_len = len;
		}
		offset[*s++] = index++;
	}
	
	return max_len;
}

int main(int argc, char *argv[])
{
	if (argc !=2)
	{
		fprintf(stderr, "Usage ./test string");
		exit(-1);
	}
	printf("%d\n", length_of_longest_substring(argv[1]));


	return EXIT_SUCCESS;
}