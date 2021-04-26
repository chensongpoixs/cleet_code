/***********************************************************************************************
	created: 		2021-04-26

	author:			chensong

	purpose:		1011. 在 D 天内送达包裹的能力
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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void show(int *arrays, int size)
{
    printf("arrays:[");
    for (int i = 0; i < size; ++i)
    {
        printf("%d, ", arrays[i]);
    }
    printf("]\n");
}
int shipWithinDays(int* weights, int weightsSize, int D)
{
    // int * arrays = malloc(sizeof(int) * weightsSize);
    // arrays[0] = weights[0];
    // for (int i = 1; i < weightsSize; ++i)
    // {
    //     arrays[i] = arrays[i-1] +weights[i];
    // }
    // show(&arrays[0], weightsSize);

    int left = 0;
    int right = 0;
    //找出左右边界问题
    for (int i = 0; i < weightsSize; ++i)
    {
        left = left > weights[i] ? left: weights[i];
        right += weights[i]; //
    }

    while(left < right)
    {
        int mid = (left + right)/ 2;

        int need = 0;
        int cur = 0;
        for (int i = 0; i < weightsSize; ++i)
        {
            if ((cur + weights[i]) > mid)
            {
                ++need;
                cur = 0;
            }
            cur += weights[i];; //前景和
        }
        if (need < D) //说明mid值太大了
        {
            right = mid;
        }
        else
        {
            left = mid +1;
        }
    }



    return left;
}
int main(int argc, char *argv[])
{
    printf("[1,2,3,4,5,6,7,8,9,10]\n"
           "5\n");
    int arr[] = {1,2,3,4,5,6,7,8,9,10};


    printf("min = %d \n", shipWithinDays(&arr[0], sizeof(arr)/ sizeof(int), 5));
    return EXIT_SUCCESS;
}
