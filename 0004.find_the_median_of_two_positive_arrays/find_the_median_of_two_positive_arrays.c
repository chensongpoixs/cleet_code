/***********************************************************************************************
	created: 		2020-05-20

	author:			chensong

	purpose:		4.find_the_median_of_two_positive_arrays

************************************************************************************************/

/**
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

 

示例 1:

    nums1 = [1, 3]
    nums2 = [2]

    则中位数是 2.0

示例 2:

    nums1 = [1, 2]
    nums2 = [3, 4]

    则中位数是 (2 + 3)/2 = 2.5
 */


#include <stdio.h>
#include <stdlib.h>
/**
 * 复杂度分析

时间复杂度：O(log(min(m, n)))
首先，查找的区间是 [0,m]。
而该区间的长度在每次循环之后都会减少为原来的一半。
所以，我们只需要执行 log(m) 次循环。由于我们在每次循环中进行常量次数的操作，所以时间复杂度为 O(log(m)))。
由于 m≤n，所以时间复杂度是 O(log(min(m,n)))。

空间复杂度：O(1)O(1)，
我们只需要恒定的内存来存储 9 个局部变量， 所以空间复杂度为 O(1)O(1)。

 * @param arrayA
 * @param arrayA_len
 * @param arrayB
 * @param arrayB_len
 * @return
 */
#define  min(a, b)  ((a)>(b)?b:a)
#define  max(a, b)  ((a)>(b)?a:b)

double  find_the_median_of_two_positive_arrays(int *A, int arrayA_len, int *B, int arrayB_len)
{
    int *b = NULL;

    // 判断两个有序数组 那个长度大的
    if (arrayB_len < arrayA_len)
    {
        int temp_len = arrayA_len;
        arrayA_len = arrayB_len;
        arrayB_len = temp_len;
        b = A;
        A = B;
        B = b;
    }

    int iMin = 0, iMax = arrayA_len;
    // 两个有序数组中间数
    int halfLen = (arrayA_len + arrayB_len + 1)/2;

    // log(m)
    while (iMin <= iMax)
    {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i < iMax && B[j-1] > A[i]){
            iMin = i + 1; // i is too small
        }
        else if (i > iMin && A[i-1] > B[j])
        {
            iMax = i - 1; // i is too big
        }
        else
        { // i is perfect
            int maxLeft = 0;
            if (i == 0) { maxLeft = B[j-1]; }
            else if (j == 0) { maxLeft = A[i-1]; }
            else { maxLeft = max(A[i-1], B[j-1]); }
            if ( (arrayA_len + arrayB_len) % 2 == 1 )
            {
                return maxLeft;
            }

            int minRight = 0;
            if (i == arrayB_len)
            {
                minRight = B[j];
            }
            else if (j == arrayA_len)
            {
                minRight = A[i];
            }
            else
            {
                    minRight = min(B[j], A[i]);
            }

            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
}

/**
 *  TODO@chensong 2020-11-09
 * @param nums1
 * @param nums1Size
 * @param nums2
 * @param nums2Size
 * @return
 */
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    double median = 0.0;

    if (nums2Size <= 0 && nums1Size <= 0)
    {

    }
    else if (nums1Size <= 0)
    {
        if (nums2Size & 1)//奇数
        {
            if (nums2Size >> 1)
            {
                median = (double)nums2[(nums2Size>>1)];
            }
            else
            {
                median = (double)nums2[0];
            }
        }
        else
        {
            median = (double)(nums2[(nums2Size>>1)-1] + nums2[(nums2Size >> 1)])/2;
        }

    }
    else if (nums2Size <= 0)
    {
        if (nums1Size & 1)//奇数
        {
            if (nums1Size >> 1)
            {
                median = nums1[(nums1Size>>1)];
            }
            else
            {
                median = nums1[0];
            }
        }
        else
        {
            median = (double)(nums1[(nums1Size>>1)-1] + nums1[(nums1Size >> 1)])/2;
        }
    }
    else
    {
        int total_size = nums1Size + nums2Size;
        int media_index = 0; //开始位置
        int nums1_index = 0;
        int nums2_index = 0;
        //手动计算出中位数的下标
        if(total_size & 1) //奇数 只有一个下标
        {
            media_index = total_size >> 1;
        }
        else
        {
            media_index = (total_size >> 1) - 1;
        }
        /**
        * 三种情况:
        *
        */
        while (nums1_index < nums1Size || nums2_index < nums2Size)
        {
            // printf("media_index = %d, num1_index = %d, nums2_index = %d\n",media_index, nums1_index, nums1_index);
            if ((nums1_index + nums2_index) == media_index )
            {
                if (nums1_index == nums1Size )
                {
                    if(total_size & 1)
                    {
                        median = nums2[nums2_index] ;
                    }
                    else
                    {
                        // printf("%d, %d\n", nums2[nums2_index], nums2[nums2_index+1]);
                        median = (double)(nums2[nums2_index] + nums2[nums2_index+1] )/2 ;
                    }
                }
                else if (nums2Size ==  nums2_index)
                {
                    if(total_size & 1)
                    {
                        median = nums1[nums1_index] ;
                    }
                    else
                    {
                        printf("%d, %d\n", nums1[nums1_index], nums1[nums1_index+1]);
                        median = (double)(nums1[nums1_index] + nums1[nums1_index+1] )/2 ;
                    }
                }
                else
                {
                    if (total_size & 1)
                    {
                        if (nums1[nums1_index] <= nums2[nums2_index])
                        {
                            median = (double)nums1[nums1_index++];
                        }
                        else
                        {
                            median = (double)nums2[nums2_index++];
                        }
                    }
                    else
                    {
                        // int first_num = 0;
                        // int two_num = 0;
                        if (nums1[nums1_index] <= nums2[nums2_index])
                        {
                            median += nums1[nums1_index++];
                        }
                        else
                        {
                            median += nums2[nums2_index++];
                        }
                        if (nums1_index == nums1Size)
                        {
                            median += nums2[nums2_index++];
                        }
                        else if (nums2_index == nums2Size)
                        {
                            median += nums1[nums1_index++];
                        }
                        else
                        {
                            if (nums1[nums1_index] <= nums2[nums2_index])
                            {
                                median += nums1[nums1_index++];
                            }
                            else
                            {
                                median += nums2[nums2_index++];
                            }
                        }
                        // printf("first_num = %d, two_num = %d\n", first_num, two_num);
                        median /= 2;
                    }
                }
                break;
            }
            if (nums1_index < nums1Size && nums2_index >= nums2Size)
            {
                ++nums1_index;
            }
            else if (nums2_index < nums2Size && nums1_index >= nums1Size)
            {
                ++nums2_index;
            }
            else
            {
                if (nums1[nums1_index] <= nums2[nums2_index])
                {
                    ++nums1_index;
                }
                else
                {
                    ++nums2_index;
                }
            }

        }

    }
    return median;
}




int postion(int * nums, int start, int end)
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


void sort(int *arrays, int start, int end)
{
    if (end <= start)
    {
        return;
    }

    //取中位置
    int p = postion(arrays, start, end);

    sort(arrays, start,  p -1);
    sort(arrays, p+1 , end);
}


void quick_sort(int * arrays, int size)
{
    if (arrays == NULL || size <= 0)
    {
        return ;
    }

    sort(arrays, 0, size -1);
}



/**
 * TODO@chensong 2020-11-09
 * 合并到新的数组中 排序 查找法
 * @param nums1
 * @param nums1Size
 * @param nums2
 * @param nums2Size
 * @return
 */
double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double median = 0.0;
    int * arrays = malloc(sizeof(int)*(nums1Size + nums2Size));
    if (!arrays)
    {
        return median;
    }
    for (int i = 0; i  < nums1Size; ++i )
    {
        arrays[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; ++i)
    {
        arrays[i+nums1Size] = nums2[i];
    }

    quick_sort(arrays, nums1Size + nums2Size);
    // for (int i = 0; i < nums2Size; ++i)
    if ((nums2Size + nums1Size) & 1)
    {
        if (((nums2Size + nums1Size) == 1))
        {
            median = (double) arrays[0];
        }
        else
        {
            median = (double) arrays[((nums1Size+nums2Size)>>1)];
        }
    }
    else
    {
        median = (double) (arrays[((nums1Size+nums2Size)>>1)-1] + arrays[((nums1Size+nums2Size)>>1)])/2.0;
    }

    free(arrays);
    return median;
}





int main(int argc, char *argv[])
{

    int arrayA[] = {1, 233};
    int arrayB[] = {10, 11, 12, 13, 14, 15, 16, 17, 18};


    double two_positive = find_the_median_of_two_positive_arrays(arrayA, sizeof(arrayA) /sizeof(int), arrayB, sizeof(arrayB) /sizeof(int));

    printf("two_positive = %lf\n", two_positive);
    return EXIT_SUCCESS;
}


