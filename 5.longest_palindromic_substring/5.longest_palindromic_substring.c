/***********************************************************************************************
created: 		2020-05-25

author:			chensong

purpose:		5. longest_palindromic_substring
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