/***********************************************************************************************
	created: 		2020-11-15

	author:			chensong

	purpose:		402.移掉K位数字
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它??
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服??
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界??
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心??
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心??
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀??
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边??
我叫他本心猎手。他可能是和宇宙同在的级??但是我并不害怕，我仔细回忆自己平淡的一??寻找本心猎手的痕迹??
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来??
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来??
************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
*解题思路 去除k个数使 最小
* 在sum字符串中比较前2k个字符就可以啦
**/
char * removeKdigits(char * num, int k) {

	if (num == NULL)
	{
		return num;
	}
	int sum_length = 0;
	char * p = num;
	while (*p != '\0')
	{
		++sum_length;
		++p;
	}
	if (sum_length <= 1)
	{
		if (k <= 0)
		{
			return num;
		}
		return "0";
	}
	//要检查数的个数
	// int length = sum_length - k;
	// if (length -k > 1)
	// {
	//     length = sum_length;
	// }
	// else 
	// {
	//     length = 2*k;
	// }
	// if ( ((2*k) - sum_length) >0)
	// {
	//     length = sum_length;
	// }
	// else 
	// {
	//     length = 2*k;
	// }
	int add_length = 0;
	for (int i = 0; i < k; ++i)
	{

		p = num;
		add_length = 0;
		if (num[0] == ('0' - 1))
		{
			while (*++p != '\0' && (*p == '0' || *p == ('0' - 1)))
			{
				++add_length;
				*p = '0' - 1;
			}
		}
		//这边计算出  删除该字符影响到多少字符， 需要比较多少字符
		


		// 最大数的下标  
		int max_index = 0;
		int two = 0;
		if (num[max_index] != '0' - 1)
		{
			++two;
		}
		for (int j = 1; j < sum_length; ++j)
		{

			if (num[j] == '0' - 1)
			{
				continue;
			}

			++two;
			//两种情况
			// 1. 第二位是 '0'情况的处理
			// 2. 第二位上不是'0' 而第三位是 '0' -1情况

			/*if (i == 0 && j == 1 && (num[max_index] != '0' || num[max_index] != '0' - 1) && (j + 1) < sum_length && (num[j] == '0' || num[j + 1] == '0'))
			{
				break;
			}*/
			if (max_index == 0 && i == 0  && num[j] == '0' )
			{
				break;
			}
			else
			{
				while (((j + 1) < sum_length&& num[j + 1] == ('0' - 1)))
				{
					++j;
				}
			}

			//ASCII码表
		   // printf("[i = %d, length = %d]\n", i, length);

			if (num[j] > num[max_index])
			{
				max_index = j;
			}
			else
			{

			}
			// while (++j <sum_length &&  num[j] != num[j-1])
			// {
			// }
			if (two >= 4)
			{
				break;
			}
		}
		num[max_index] = '0' - 1;//记录已经被删除了
		p = num;
		if (num[0] == ('0' - 1))
		{
			while (*++p != '\0' && (*p == '0' || *p == ('0' - 1)))
			{

				*p = '0' - 1;
			}
		}
		printf("[i = %d][num = %s]\n", i, num);
	}
	int cur_retnum_index = 0;
	for (int i = 0; i < sum_length; ++i)
	{
		if (num[i] != ('0' - 1))
		{
			if (cur_retnum_index != 0 || num[i] != '0')
			{
				num[cur_retnum_index++] = num[i];

			}

		}

	}
	//说明都删除了哈哈 所以要添加'0'
	if (cur_retnum_index == 0)
	{
		num[cur_retnum_index++] = '0';
	}
	num[cur_retnum_index] = '\0';
	return num;
}



int main(int argc, char *argv[])
{

	return EXIT_SUCCESS;
}