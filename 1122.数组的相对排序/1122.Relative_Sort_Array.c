/***********************************************************************************************
	created: 		2020-11-14

	author:			chensong

	purpose:		1122. 数组的相对排序
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
 * Note: The returned array must be malloced, assume caller calls free().
 */


/**
* 对 arr1 中的元素进行排序
*/
int prartion(int *arrays, int start, int end)
{
    // int
    int  value = arrays[start];
    int   right = start;
    int left = end +1;
    while (1)
    {
        while (arrays[++right]< value)
        {
            if (right == end)
            {
                break;
            }
        }
        while (arrays[--left]>value)
        {
            if (left == start)
            {
                break;
            }
        }
        if (left <= right)
        {
            break;
        }

        int temp = arrays[left];
        arrays[left] = arrays[right];
        arrays[right] = temp;
    }
    //这里需要交换位置的
    int temp  = arrays[start];
    arrays[start] = arrays[left];
    arrays[left] = temp;
    return left;
}

void sort(int * arrays, int start, int end)
{
    if (start >= end)
    {
        return ;
    }
    //
    int p = prartion(arrays, start, end);
    sort(arrays, start, p-1);
    sort(arrays, p+1, end);
}

void quick_sort(int * arrays, int size)
{
    if (arrays == NULL || size <= 0)
    {
        return ;
    }
    sort(arrays, 0, size-1);
}


int comp(const void* v1, const void *v2)
{
    int *a = v1;
    int *b = v2;
    return *a >= *b;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    *returnSize = 0;

    if (arr1 == NULL && arr2 == NULL)
    {
        return NULL;
    }
    if ((arr1 == NULL|| arr1Size <=0 ) && (arr2 != NULL && arr2Size >0))
    {
        *returnSize = arr2Size;
        return arr2;
    }
    //  1. arr1排序
    // qsort(arr1, arr1Size, sizeof(int), comp);
    quick_sort(arr1, arr1Size);

    if (arr2 == NULL || arr2Size<=0)
    {
        *returnSize = arr1Size;
        return arr1;
    }
    int * arrays = malloc(sizeof(int) * (arr1Size ));
    int arrays_index = 0;
    for (int i = 0; i < arr2Size; ++i)
    {
        //这边查找arr1的时间复杂度比较高一点 因为是不知道
        for (int j = 0; j < arr1Size; ++j)
        {
            if (arr1[j] == arr2[i])
            {
                arrays[arrays_index++] = arr1[j];
                arr1[j] = arr2[0]; //标记位置 不需要比较了
                while (++j <arr1Size &&  arr1[j] == arr2[i])
                {
                    arrays[arrays_index++] = arr1[j] ;
                    arr1[j] = arr2[0];
                }
                break;
            }

        }
        // int index = 0;
        // //哨兵 = 0  北京大学数据结构 中哨兵的使用
        // while (index == 0 || (++index < arr1Size && arr1[index] != arr1[index -1]) )
        // {
        //     if (arr1[index] == arr2[i])
        //     {
        //         arrays[arrays_index++] = arr1[index];
        //         arrays[arrays_index++] = arr2[i];
        //          arr1[index] = arr2[0]; //标记位置 不需要比较了
        //         while (++index <arr1Size &&  arr1[index] == arr2[i])
        //         {
        //            arrays[arrays_index++] = arr1[index] ;
        //            arr1[index] = arr2[0];
        //         }
        //         continue; //结束   arr1数组是有序的不需要再比较了
        //     }
        //     else if (index == 0)
        //     {
        //         ++index;
        //     }
        // }
    }


    //2. 去重
    // int i = 0;
    for (int i = 0; i < arr1Size; ++i)
    {
        if(arr1[i] != arr2[0])
        {
            arrays[arrays_index++] = arr1[i];
        }
    }
    *returnSize = arr1Size ;


    return arrays;
}

int main(int argc, char *argv[])
{

    int arr1[] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr2[] = {2,1,4,3,9,6};
	
    printf("arr1 = [");
	for (int i = 0; i < sizeof(arr1)/ sizeof(int); ++i)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d ", arr1[i]);
		
    }
    printf("]\n");

	printf("arr2 = [");
    for (int i = 0; i < sizeof(arr2)/ sizeof(int); ++i)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d ", arr2[i]);
		
    }
    printf("]\n");
    int retsize = 0;
    int *arrays = relativeSortArray(&arr1[0], sizeof(arr1)/ sizeof(int), &arr2[0], sizeof(arr2)/ sizeof(int),&retsize);
    if (arrays)
    {
		printf("排序后:[");
        for (int i = 0; i < retsize; ++i)
        {
            if (i != 0)
            {
                printf(", ");
            }
            printf("%d", arrays[i]);
        }
        printf("]\n");
        free(arrays);
        arrays = NULL;
    }
	
    return EXIT_SUCCESS;
}