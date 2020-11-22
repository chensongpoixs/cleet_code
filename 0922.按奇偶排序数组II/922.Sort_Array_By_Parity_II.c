/***********************************************************************************************
	created: 		2020-11-12

	author:			chensong

	purpose:		922. 按奇偶排序数组 II
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int* sortArrayByParityII(int* A, int ASize, int* returnSize)
 {
     *returnSize = 0;
     if (A == NULL || ASize <= 0)
     {
         return NULL;
     }

     int odd_index = 1; //奇数下标
     int even_index = 0;//偶数下标

     int index = 0;
     //奇偶是成对了的所以使用&&
     while (odd_index<ASize && even_index<ASize)
     {
         //先找出偶数
         index = even_index;
         while  (even_index < ASize && (A[even_index++] &1) > 0  ) ;
         if (even_index <= ASize)
         {
             int  temp =   A[index];
             A[index] = A[even_index -1];
             A[even_index -1] = temp;
         }
         even_index = index +2;
         //先找出奇数
          index = odd_index;
         while  (odd_index < ASize && (A[odd_index++] & 1) <=0    ) ;
         if (odd_index <= ASize)
         {
             int temp =   A[index];
             A[index] = A[odd_index -1];
             A[odd_index -1] = temp;
         }
         odd_index = index +2;
     }
     *returnSize = ASize;
     return A;
 }

/**
* 空间换时间
**/
int* sortArrayByParityII_two(int* A, int ASize, int* returnSize)
{
    *returnSize = 0;
    if (A == NULL || ASize <= 0)
    {
        return NULL;
    }
    int * arrays = malloc(sizeof(int) * ASize);
    if (!arrays)
    {
        return NULL;
    }

    int odd_index = 0; //奇数下标
    int even_index = 0;//偶数下标

    int index = 0;

    while (odd_index<ASize && even_index<ASize)
    {
        //先找出偶数
        while  (even_index < ASize && (A[even_index++] &1) > 0  ) ;
        if (even_index <= ASize)
        {
            arrays[index++] = A[even_index-1];
        }
        //先找出奇数
        while  (odd_index < ASize && (A[odd_index++] & 1) <=0    ) ;
        if (odd_index <= ASize)
        {
            arrays[index++] = A[odd_index-1];
        }
    }
    *returnSize = ASize;
    return arrays;
}

int main(int argc, char *argv[])
{
    if ((argc-1 & 1) > 0)
    {
        printf("usage: even number ./test 34 33 44 89");
        return -1;
    }

    int* input_array = malloc(sizeof(int) * (argc-1));
    if (!input_array)
    {
        return -1;
    }
    printf("[");
    for (int i = 1; i < argc; ++i)
    {
        if (i != 1)
        {
            printf(", ");
        }
        printf(" %s ", argv[i]);
        input_array[i-1] = atoi(argv[i]);
    }
    printf(" ]");
    int retsize = 0;
    int * output_array =  sortArrayByParityII_two(input_array, argc-1, &retsize);
    printf("[");
    for (int j = 0; j < retsize; ++j)
    {
        if (j != 0)
        {
            printf(", ");
        }
        printf(" %d ", output_array[j]);
    }
    printf("]\n");
    if (output_array)
    {
        free(output_array);
    }
    if (input_array)
    {
        free(input_array);
    }
    return EXIT_SUCCESS;
}