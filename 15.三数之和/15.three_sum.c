/***********************************************************************************************
	created: 		2020-11-01

	author:			chensong

	purpose:		15. 三数之和
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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * # 15. 三数之和
  给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

  注意：答案中不可以包含重复的三元组。



  示例：

  给定数组 nums = [-1, 0, 1, 2, -1, -4]，

  满足要求的三元组集合为：
  [
    [-1, 0, 1],
    [-1, -1, 2]
  ]

 */

int compare (const void *a ,const void *b)
{
	int *aa=(int * ) a,*bb = (int * )b;
	if( * aa >* bb) 
    {
        return 1;
    }
	if( * aa == * bb) 
    {
        return 0;
    }
	if( * aa < *bb) 
    {
        return -1;
    }
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    
        *returnSize = 0;
    if (nums == NULL || numsSize < 3 )
    {
        return NULL;
    }
    int alloc_size = 1;
    int* *arrayy = malloc(alloc_size * sizeof(int*));
    *returnColumnSizes = malloc(alloc_size * sizeof(int));
    qsort(&nums[0] , numsSize, sizeof(int), compare);
   
   
   
    
    int array_index = 0;
    int b = 0;
    int c = 0;
    for (int a = 0; a < numsSize; ++a)
    {
        if (a == 0 || a > 0 && nums[a] != nums[a-1])
        {
            b = a + 1;
            c = numsSize - 1;
            while (b < c)
            {
                int diff = nums[a] + nums[b];
                if ( diff + nums[c]  > 0)  // 比较大小来看这个数组中还有没有数字
                {
                    while (--c > b && nums[c] == nums[c+1]){}
                }
                else if (diff + nums[c] < 0)
                {
                    while (++b < c && nums[b] == nums[b-1]){}
                }
                else 
                {
                    (*returnColumnSizes)[ *returnSize] =3;
                    arrayy[ *returnSize] = malloc(3 * sizeof(int));
                    arrayy[ *returnSize][0] = nums[a];
                    arrayy[ *returnSize][1] = nums[b];
                    arrayy[ *returnSize][2] = nums[c];
                    (*returnSize)++;
                    while (--c > b && nums[c] == nums[c+1]){}
                    while (++b < c && nums[b] == nums[b-1]){}

                    //内存不足时扩容 2倍扩大
                    if (*returnSize == alloc_size) 
                    {
                        alloc_size = 2 * alloc_size;
                        arrayy = realloc(arrayy, alloc_size*  sizeof(int*));
                        (*returnColumnSizes) = realloc((*returnColumnSizes),  alloc_size* sizeof(int));
                    }
                       
                }
                
            }
        }
        
    }
  
   
    return arrayy;
}

int main(int argc, char *argv[])
{

    int array[] = { -1, 0, 1, 2, -1, -4 };// {0, 0, 0, 0};
   
	
	int retsize = 0;
	int * retclomueesize = NULL;
	int ** retarray = threeSum(&array[0], 10, &retsize, &retclomueesize);
	
	for (int i = 0;  i < retsize; ++i)
	{
		printf("[%d][%d][%d]\n", retarray[i][0], retarray[i][1], retarray[i][2]);
	}

	while (1);

    return 0;
}