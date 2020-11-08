/***********************************************************************************************
	created: 		2020-11-03

	author:			chensong

	purpose:		867.转置矩阵
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它�?
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服�?
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界�?
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心�?
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心�?
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀�?
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边�?
我叫他本心猎手。他可能是和宇宙同在的级�?但是我并不害怕，我仔细回忆自己平淡的一�?寻找本心猎手的痕迹�?
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来�?
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来�?
************************************************************************************************/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes) 
{

	*returnSize = 0;

	if (A == NULL || ASize <= 0 || AColSize == NULL)
	{
		return NULL;
	}

	int **arrays = malloc(sizeof(int*) *(AColSize[0]));

	*returnColumnSizes = malloc(sizeof(int) * (AColSize[0]));


	for (int j = 0; j <ASize; ++j)
	{
		for (int i = 0; i < AColSize[j]; ++i)
		{
			if (j == 0)
			{
				arrays[i] = malloc(sizeof(int)* ASize);
				(*returnColumnSizes)[i] = ASize;
			}
			arrays[i][j] = A[j][i];
		}
	}
	*returnSize = AColSize[0];
	return arrays;
}

int main(int argc, char *argv[])
{

	
	int **array = malloc(sizeof(int*) *6);
	for (int i = 0; i < 2; ++i)
	{
		array[i] = malloc(sizeof(int) * 3);
		for (int j = 0;j < 3; ++j)
		{
			array[i][j] = i+j +2;
		}
	}
	printf("[[1, 2, 3],[4, 5, 6]]\n");

	int colsize[2] = {0};
	colsize[0] = 3;
	colsize[1] = 3;
	int retsize = 0;
	int * returnColumnSizes = NULL;
	int **retarrays = transpose(array, 2, colsize, &retsize, &returnColumnSizes);
	printf("[");
	for (int i = 0; i < retsize; ++i)
	{
		printf("[");
		for (int j = 0; j < returnColumnSizes[i]; ++j)
		{
			printf("%d ", retarrays[i][j]);
		}
		free(retarrays[i]);
		printf("]\n");
	}
	free(returnColumnSizes);
	free(retarrays);
	for (int i = 0; i < 2; ++i)
	{
		free(array[i]);
	}
	free(array);
	printf("]\n");
	return 0;
}