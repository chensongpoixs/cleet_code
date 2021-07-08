/***********************************************************************************************
	created: 		2021-07-08

	author:			chensong

	purpose:		930. 和相同的二元子数组
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



int numSubarraysWithSum(int* nums, int numsSize, int goal)
{
    int count = 0;
    printf("numsSize = %d\n", numsSize);
    int *prefix = malloc(sizeof(int) * (numsSize+1));
    memset(prefix, 0, sizeof(int) * (numsSize+1));
    int *prefix_cnt = malloc(sizeof(int) * (numsSize+1));
    memset(prefix_cnt, 0, sizeof(int) * (numsSize+1));
    int one_nums = 0;
    // appix[0] = nums[0];
    for (int i = 0; i < numsSize; ++i)
    {
        prefix[i+1] = prefix[i] + nums[i];
        if (nums[i] == 1)
        {
            ++one_nums;
        }
        // printf("appix[%d] = %d\n", i+1, appix[i+1] );
    }
    printf(" one_nums = %d\n", one_nums);

    for (int i = 0; i < numsSize +1; ++i)
    {
        int t = prefix[i] - goal;
        // 1. 判断当前是否有值符合目标值
        if (t >= 0)
        {
            count += prefix_cnt[t];
        }
        // 2. 保存当前值方便以后匹配目标值
        ++prefix_cnt[prefix[i]];
    }
    if (prefix_cnt)
    {
        free(prefix_cnt);
        prefix_cnt = NULL;
    }
    if (prefix)
    {
        free(prefix);
        prefix = NULL;
    }
    return count;


    // 时间复杂度O(N^2)
    int num_count = goal > 0 ? goal: 1 ;
    while (num_count <= numsSize)
    {
        for (int i = 0;  (num_count + i) <= numsSize; ++i)
        {
            if (prefix[i+num_count] - prefix[i] == goal)
            {
                // printf("-- %d-- num_count = %d\n", i, num_count);
                ++count;
            }
        }
        ++num_count;
    }



    // int index = goal ;
    // for (int j = goal; j < numsSize; ++j)
    // {
    //     for (int i = 0; i < numsSize  - goal; ++i)
    //     {

    //         // if (appix[numsSize-1] <  goal)
    //         // {
    //         //     continue;
    //         // }

    //         if ((i == 0 && appix[j] == goal)|| (appix[j] - appix[i] == goal))
    //         {

    //             //  printf("--appix[%d]= %d, appix[%d] = %d\n", j,  appix[j], i, appix[i]);
    //             ++count;
    //         }
    //         // else if (i != 0 && (appix[j] - appix[i] == goal) )
    //         // {
    //         //     printf("=appix[%d]= %d, appix[%d] = %d\n", j,  appix[j], i, appix[i]);
    //         //     ++count;;
    //         // }
    //         //++index;
    //     }
    // }



    return count;
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}