/***********************************************************************************************
	created: 		2021-03-22

	author:			chensong

	purpose:		268. 丢失的数字
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
#include <stdint.h>

/**
* 时间复杂度O(N)
* 空间复杂度O((N)
*/
int missingNumber_one(int* nums, int numsSize)
{
    int *array=  malloc(sizeof(int) * (numsSize+1));
    memset(array, 0, sizeof(int) *(numsSize+1));
    for (int i = 0; i < numsSize; ++i)
    {
        ++array[nums[i]];
    }
    for (int i = 0; i < (numsSize+1); ++i)
    {
        if (array[i] == 0)
        {
            free(array);
            array = NULL;
            return i;
        }
    }
    free(array);
    array = NULL;
    return 0;
}

/**
* 时间复杂度O(N)
* 空间复杂度O((N>>3) +1)
*/
int missingNumber_two(int* nums, int numsSize)
{
    int bit_size = (numsSize >> 3) +1; //实际需要内存大小
    uint8_t *bit=  malloc(sizeof(uint8_t) * bit_size);
    memset(bit, 0, sizeof(uint8_t) *bit_size );
    for (int i = 0; i < numsSize; ++i)
    {
        bit[(nums[i]>>3)] ^=   (1 << (nums[i] % 8));
    }

    for (int i = 0; i < numsSize; ++i)
    {
        //比较每一个比特是否是0
        if ( (bit[i>>3]  &  (1 << (i% 8))) == 0)
        {
            if (bit)
            {
                free(bit);
                bit = NULL;
            }
            return i;
        }
    }
    if (bit)
    {
        free(bit);
        bit = NULL;
    }
    return numsSize;
}



int main(int argc, char *argv[])
{
    int arrays[] = {9,6,4,2,3,5,7,0,1};
    printf("arrays = [");
    for (int i = 0; i < sizeof(arrays)/ sizeof(int); ++i)
    {
        printf("%d, ", arrays[i]);
    }
    printf("]\n");
    printf("[bit size = %d]\n", missingNumber_two(&arrays[0], sizeof(arrays)/ sizeof(int)));
    return EXIT_SUCCESS;
}