/***********************************************************************************************
	created: 		2020-05-20

	author:			chensong

	purpose:		4.find_the_median_of_two_positive_arrays
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

int main(int argc, char *argv[])
{

    int arrayA[] = {1, 2};
    int arrayB[] = {10, 11, 12, 13, 14, 15, 16, 17, 18};


    double two_positive = find_the_median_of_two_positive_arrays(arrayA, sizeof(arrayA) /sizeof(int), arrayB, sizeof(arrayB) /sizeof(int));

    printf("two_positive = %lf\n", two_positive);
    return EXIT_SUCCESS;
}


