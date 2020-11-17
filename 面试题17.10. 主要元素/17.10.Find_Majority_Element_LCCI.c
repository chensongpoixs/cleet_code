/***********************************************************************************************
	created: 		2020-11-18

	author:			chensong

	purpose:		面试题 17.10. 主要元素
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它。
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

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int partition(int *nums, int start, int end)
{
    int value = nums[start];
    int right = start;
    int left = end +1;
    while(1)
    {
        //1. 找到最大数
        while (nums[++right] < value)
        {
            if (right == end)
            {
                break;
            }
        }
        //2. 找到最小的数
        while (nums[--left]  > value)
        {
            if (left == start)
            {
                break;
            }
        }
        if (right>= left)
        {
            break;
        }
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
    }
    int temp = nums[start];
    nums[start] = nums[left];
    nums[left] = temp;
    return left;
}


void sort(int *nums, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int p = partition(nums, start, end);
    sort(nums, start, p -1);
    sort(nums, p +1, end);
}


void quick_sort(int *nums, int size)
{
    if (nums == NULL || size <= 0)
    {
        return;
    }
    sort(nums, 0, size-1);
}

int majorityElement_nums(int* nums, int numsSize)
{
    if (nums == NULL || numsSize<1)
    {
        return -1;
    }
    if (numsSize == 1)
    {
        return nums[0];
    }
    quick_sort(nums, numsSize);
    int number = (numsSize/2);
    int cur_num =0;
    for (int i = 0; i <numsSize; ++i)
    {
        if (i == 0)
        {
            cur_num = nums[i];
        }
       
        if (nums[i] == cur_num )
        {
            --number;
            if (number < 0)
            {
                return cur_num;
            }
        }
        else 
        {
            number =  (numsSize/2)-1;
            cur_num= nums[i];
        }
    }
    
    return -1;
}



//摩尔投票法 加验证实现
int majorityElement(int* nums, int numsSize)
{
    if (numsSize <0 || nums == NULL)
    {
        return -1;
    }
    int temp = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] == temp)
        {
            ++count;
        }
        else 
        {
            --count;
        }
        if (count == 0)
        {
            temp = nums[i];
            count = 1;
        }
    }

     count = 0;
    for (int i = 0; i <numsSize; ++i)
    {
        if (nums[i] == temp)
        {
            ++count;
        }
    }
    if (count > (numsSize/2))
    {
        return temp;
    }
    return -1;
}
int main(int argc, char *argv[])
{
	int arrays[] = {1,2,5,9,5,9,5,5,5};
	printf("%d\n", majorityElement(&arrays, 9));

	return EXIT_SUCCESS;
}