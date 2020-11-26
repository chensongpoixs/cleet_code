/***********************************************************************************************
created: 		2020-11-26

author:			chensong

purpose:		0164.Maximum_Gap
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int pariation(int *nums, int start, int end)
{
    int value  = nums[start];
    int left = start;
    int right = end +1;
    while (1)
    {
        //找到最大值
        while (nums[++left] < value)
        {
            if (left == end)
            {
                break;
            }
        }
        //找到最小值
        while (nums[--right] >value)
        {
            if (right == start)
            {
                break;
            }
        }
        if (right<= left)
        {
            break;
        }
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    int temp = nums[start];
    nums[start] = nums[right];
    nums[right] = temp;
    //返回从left到right之间最大值是right
    return right;
}


void sort(int *nums, int start, int end)
{
    if(end <= start)
    {
        return;
    }

    int j = pariation(nums, start, end);
    sort(nums, start, j-1);
    sort(nums, j+1, end);
}

void quick_sort(int *nums, int size)
{
    if (nums == NULL || size < 2)
    {
        return ;
    }
    sort(nums, 0, size-1);
}



int maximumGap(int* nums, int numsSize)
{
    if (nums == NULL || numsSize<2)
    {
        return 0;
    }
    quick_sort(nums, numsSize);
    int num = 0;
    for (int i = 1; i < numsSize; ++i)
    {
        // printf("%d, ", nums[i]);
        int new_num = abs(nums[i] - nums[i-1]) ;
        if (new_num > num)
        {
            num = new_num;
        }
    }
    // [-100000, 1, 3,6,10, 90, 91, 100, 1000, 1001, 1003]
    // printf("\n");
    return num;
}


int main(int argc, char *argv[])
{
	
	int arrays[] = {3, -90,6,9,10, 0, 8, 4, 4, 4, 4};
	printf("[3, -90,6,9,10, 0, 8, 4, 4, 4, 4]\n");
	
	printf("num = %d \n", maximumGap(&arrays[0], sizeof(arrays)/sizeof(int)));
	
	return 0;
}