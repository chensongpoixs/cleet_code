/***********************************************************************************************
	created: 		2020-11-03

	author:			chensong

	purpose:		18.18. 四数之和
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


int partition(int *nums, int start, int end)
{
    int value = nums[start];
    int right = start;
    int left = end +1;
    while (1)
    {
        //判断结束条件
        //小于 value
        while(nums[++right] < value)
        {
            if (right == end)
            {
                break;
            }
        }
        // 大于 value
        while (nums[--left] > value)
        {
            if (left == start)
            {
                break;
            }
        }
        if (right>=left)
        {
            break;
        }
        int temp  = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
    }
    //这里需要交换位置的
    int temp  = nums[start];
    nums[start] = nums[left];
    nums[left] = temp;
    return left;
}

void sort(int *nums, int start, int end)
{
    //递归结束条件
    if (start>= end)
    {
        return;
    }
    int j = partition(nums, start, end);

    sort(nums, start, j -1);
    sort(nums, j +1, end);
}
/**
 * 快速排序
 * @param nums
 */
void quick_sort(int * nums, int size)
{
    if (nums == NULL || size <= 0)
    {
        return;
    }

    sort(nums, 0, size-1);
}



//
//void ksum(int * nums,int  numsSize, int target, int * returnSize, int ** returnColumnSizes, int k,  int i, int *** retarray, int alloc_size)
//{
//
//    int **array = *retarray;
//    if (k == 3)
//    {
//        //    *returnColumnSizes = malloc(alloc_size * sizeof(int));
//        for(int twosum = 0; twosum < numsSize-3; ++twosum)
//        {
//            int threesum =  twosum + 1;
//            int foursum = numsSize-1;
//
//            if ((twosum == 0 )||(twosum > 0 && nums[twosum] != nums[twosum-1] ))
//            {
//                printf("two = %d, three = %d\n", twosum, threesum);
//                while (twosum< threesum && threesum < foursum)
//                {
//                    int diff = nums[twosum] + nums[threesum];
//
//                    if (diff + nums[foursum]> target)
//                    {
//                        {
//                            while (--foursum > threesum && nums[foursum] == nums[foursum+1]){}
//                        }
//
//                    }
//                    else if (diff + nums[foursum] < target)
//                    {
//                        while (++threesum < foursum && nums[threesum] == nums[threesum-1]){}
//                    }
//                    else
//                    {
//                        if (alloc_size == *returnSize)
//                        {
//                            alloc_size *=2;
//                            array = realloc(array, alloc_size * sizeof(int*));
//                            (*returnColumnSizes) = realloc((*returnColumnSizes), alloc_size * sizeof(int));
//                        }
//                        printf("[ ------two = %d, three = %d]\n", twosum, threesum);
//                        (*returnColumnSizes)[*returnSize] = 4;
//                        array[*returnSize] = malloc(sizeof(int) * 4);
//                        array[*returnSize][0] = i;
//                        array[*returnSize][1] = nums[twosum];
//                        array[*returnSize][2] = nums[threesum];
//                        array[*returnSize][3] = nums[foursum];
//                        (*returnSize)++;
//                        //                    if (threesum == foursum-1)
//                        //                    {
//                        ////                        threesum_run = 0;
//                        //                        while (--threesum > twosum && nums[threesum] == nums[threesum+1]){}
//                        //                    }
//                        //                    else
//                        {
//                            //                        threesum_run = 1;
//                            while (--foursum > threesum && nums[foursum] == nums[foursum+1]){}
//                        }
//                        while (++threesum < foursum && nums[threesum] == nums[threesum-1]){}
//                        printf("[ ++++++two = %d, three = %d]\n", twosum, threesum);
//                    }
//                }
//            }
//        }
//    }
//    else
//    {
//
//        for (int i = 0; i < numsSize-3; ++i)
//        {
//
//        }
//
//    }
//
////        for (int twosum = i +1; twosum < numsSize -2; ++twosum)
////        {
////
////
////        }
//
//    }
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
//
//    *returnSize = 0;
//    if (nums == NULL || numsSize < 4)
//    {
//        return NULL;
//    }
//
//    quick_sort(nums, numsSize);
//    int alloc_size = 5;
//    int **array = malloc(alloc_size * sizeof(int*));
//    *returnColumnSizes = malloc(alloc_size * sizeof(int));
//     ksum(nums, numsSize, target, returnSize, returnColumnSizes, 4, 0, &array, alloc_size);
//    return array;
//    for(int i = 0; i < numsSize-3; ++i)
//    {
//        for (int twosum = i +1; twosum < numsSize -2; ++twosum)
//        {
//
//            int threesum =  twosum + 1;
//            int foursum = numsSize-1;
//            int threesum_run = 1;
//            if ((i == 0 && twosum == 1)||(i > 0 && nums[i] != nums[i-1] )||( twosum > 1 && nums[twosum] != nums[twosum-1]))
//            {
//                printf("two = %d, three = %d\n", twosum, threesum);
//                while (twosum< threesum && threesum < foursum)
//                {
//                    int diff = nums[i] + nums[twosum] + nums[threesum];
//
//                    if (diff + nums[foursum]> target)
//                    {
//                        {
//                            while (--foursum > threesum && nums[foursum] == nums[foursum+1]){}
//                        }
//
//                    }
//                    else if (diff + nums[foursum] < target)
//                    {
//                        while (++threesum < foursum && nums[threesum] == nums[threesum-1]){}
//                    }
//                    else
//                    {
//                        if (alloc_size == *returnSize)
//                        {
//                            alloc_size *=2;
//                            array = realloc(array, alloc_size * sizeof(int*));
//                            (*returnColumnSizes) = realloc((*returnColumnSizes), alloc_size * sizeof(int));
//                        }
//                        printf("[ ------two = %d, three = %d]\n", twosum, threesum);
//                        (*returnColumnSizes)[*returnSize] = 4;
//                        array[*returnSize] = malloc(sizeof(int) * 4);
//                        array[*returnSize][0] = nums[i];
//                        array[*returnSize][1] = nums[twosum];
//                        array[*returnSize][2] = nums[threesum];
//                        array[*returnSize][3] = nums[foursum];
//                        (*returnSize)++;
//                        //                    if (threesum == foursum-1)
//                        //                    {
//                        ////                        threesum_run = 0;
//                        //                        while (--threesum > twosum && nums[threesum] == nums[threesum+1]){}
//                        //                    }
//                        //                    else
//                        {
//                            //                        threesum_run = 1;
//                            while (--foursum > threesum && nums[foursum] == nums[foursum+1]){}
//                        }
//                        while (++threesum < foursum && nums[threesum] == nums[threesum-1]){}
//                        printf("[ ++++++two = %d, three = %d]\n", twosum, threesum);
//                    }
//                }
//            }
//        }
//
//
//
//
//    }
//
//
//    return array;
//}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){

    *returnSize = 0;
    if (nums == NULL || numsSize < 4)
    {
        return NULL;
    }

    quick_sort(nums, numsSize);

    int alloc_size = 5;
    int **array = malloc(alloc_size * sizeof(int*));
    *returnColumnSizes = malloc(alloc_size * sizeof(int));
    for(int i = 0; i < numsSize-3; ++i)
    {
        if ((i == 0 ) || (i > 0 && nums[i] != nums[i-1]) )
        {

            for (int twosum = i +1; twosum < numsSize -2; ++twosum)
            {
                int temp_twosum = i +1;
                int threesum = twosum + 1;
                int foursum = numsSize - 1;
                if (twosum == temp_twosum || (twosum > temp_twosum && nums[twosum] != nums[twosum - 1]))
                {
//                    printf("two = %d, three = %d\n", twosum, threesum);
                    while (twosum < threesum && threesum < foursum)
                    {
                        int diff = nums[i] + nums[twosum] + nums[threesum];

                        if (diff + nums[foursum] > target)
                        {
                            {
                                while (--foursum > threesum && nums[foursum] == nums[foursum + 1]) {}
                            }

                        } else if (diff + nums[foursum] < target)
                        {
                            while (++threesum < foursum && nums[threesum] == nums[threesum - 1]) {}
                        } else
                        {
                            if (alloc_size == *returnSize)
                            {
                                alloc_size *= 2;
                                array = realloc(array, alloc_size * sizeof(int *));
                                (*returnColumnSizes) = realloc((*returnColumnSizes), alloc_size * sizeof(int));
                            }
//                            printf("[ ------two = %d, three = %d]\n", twosum, threesum);
                            (*returnColumnSizes)[*returnSize] = 4;
                            array[*returnSize] = malloc(sizeof(int) * 4);
                            array[*returnSize][0] = nums[i];
                            array[*returnSize][1] = nums[twosum];
                            array[*returnSize][2] = nums[threesum];
                            array[*returnSize][3] = nums[foursum];
                            (*returnSize)++;

                            while (--foursum > threesum && nums[foursum] == nums[foursum + 1]) {}

                            while (++threesum < foursum && nums[threesum] == nums[threesum - 1]) {}
//                            printf("[ ++++++two = %d, three = %d]\n", twosum, threesum);
                        }
                    }
                }
            }
//            continue;
        }





    }


    return array;
}

void knums(int * nums, int numsSize, int target, int value,  int k, int * returnSize, int **returnColumuSize , int **array, int* alloc_size)
{
    printf("%s, ret size = %d \n", __FUNCTION__, *returnSize);
//    int **array = *retarray;
    if (k == 3)
    {
        if (nums == NULL || numsSize < 3)
        {
            printf("error   num == null, numsSize = %d\n", numsSize);
            return;
        }
        for (int i = 0; i < numsSize -2; ++i)
        {
            //
            if (i == 0 || (i > 0 && nums[i] != nums[i -1]))
            {

                int b = i +1;
                int c = numsSize -1;
//                printf("[ ------two = %d, three = %d]\n", b, c);
                while (b < c)
                {

                    int diff = nums[i] + nums[b];
                    if (target - diff > 0)
                    {
                        while (++b < c && nums[b] == nums[b -1]){}
                    }
                    else if (target - diff < 0)
                    {
                        while (--c > b && nums[c] == nums[c+1]){}
                    }
                    else
                    {
                        if (*alloc_size == *returnSize)
                        {
                            *alloc_size *= 2;
                            array = realloc(array, *alloc_size * sizeof(int *));
                            (*returnColumuSize) = realloc((*returnColumuSize), *alloc_size * sizeof(int));
                        }
                            printf("[ ------two = %d, three = %d]\n", b, c);
                        (*returnColumuSize)[*returnSize] = 4;
                        array[*returnSize] = malloc(sizeof(int) * 4);
                        array[*returnSize][0] = value;
                        array[*returnSize][1] = nums[i];
                        array[*returnSize][2] = nums[b];
                        array[*returnSize][3] = nums[c];
                        (*returnSize)++;

                        while (++b < c && nums[b] == nums[b -1]){}

                        while (--c > b && nums[c] == nums[c+1]){}
                    }
                }
            }
        }
        for (int i = 0; i < *returnSize; ++i)
        {
            printf("[%d, %d, %d, %d]\n", array[i][0], array[i][1], array[i][2], array[i][3]);

        }

    }
    else
    {
        for (int i = 0; i < numsSize-3; ++i)
        {
            if (i == 0 ||(i > 0 && nums[i] != nums[i -1]))
            {
//                (*stack)[0] = nums[i];
//                *stack_size = 1;
                knums(nums+i+1, numsSize -i-1, target - nums[i], nums[i], k -1, returnSize, returnColumuSize , array, alloc_size);
            }
        }
    }

}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourkSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (nums == NULL || numsSize < 4)
    {
        return NULL;
    }
    quick_sort(nums, numsSize);

    int alloc_size = 5;
    int **array = malloc(alloc_size * sizeof(int*));
    *returnColumnSizes = malloc(alloc_size *sizeof(int));
    int k = 4;
    int statck[4];
    int statck_size = 0;

    knums(nums, numsSize, target, 0, k, returnSize, &*returnColumnSizes, array, &alloc_size);

    printf("retsize = %d, alloc_size = %d\n", *returnSize, alloc_size);

    for (int i = 0; i < *returnSize; ++i)
    {
        printf("[%d, %d, %d, %d]\n", array[i][0], array[i][1], array[i][2], array[i][3]);

    }

    return array;
}


 int main(int argc, char *argv[])
 {
 //    int array[] = {1,0,-1,0,-2,2};
//     int array[] = {  -2,-1,-1,1,1,2,2};
        int array[] = {-4,-3,-2,-1,0,0,1,2,3,4};
     int target = 0;

     int returnsize = 0;
     int *returncolumnsizes = NULL;
    int **retarray =  fourSum(&array[0], sizeof(array)/ sizeof(int), target, &returnsize, &returncolumnsizes);

 //    for (int i = 0; i < sizeof(array)/ sizeof(int); ++i)
 //    {
 //        printf("array[%d]=%d\n", i, array[i]);
 //    }

     printf("returnsize = %d [ \n", returnsize);
     for (int i = 0; i < returnsize; ++i)
     {
         printf("[%d, %d, %d, %d]\n", retarray[i][0], retarray[i][1], retarray[i][2], retarray[i][3]);
         free(retarray[i]);
     }
     free(retarray);
     free(returncolumnsizes);
     printf("]\n");
     return 0;
 }