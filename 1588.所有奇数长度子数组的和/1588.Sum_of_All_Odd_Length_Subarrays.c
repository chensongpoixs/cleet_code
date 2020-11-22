/***********************************************************************************************
	created: 		2020-11-22
	
	author:			chensong

	purpose:		1588.所有奇数长度子数组的和
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sumOddLengthSubarrays_one(int* arr, int arrSize)
{
    int num = 0;
    for (int i = 0; i < arrSize; ++i)
    {
        for (int j = i; j< arrSize; j +=2 )
        {
            //都是数就加多少的个数
            for (int k = i; k <=j ; ++k)
            {
                num += arr[k]; //把前面的加起来  如果 odd个  1
            }
            
        }
    }

    return num;
}

/**
* 对于一个数字，它所在的数组，可以在它前面再选择 0, 1, 2, ... 个数字，一共有 left = i + 1 个选择；

可以在它后面再选择 0, 1, 2, ... 个数字，一共有 right = n - i 个选择。

如果在前面选择了偶数个数字，那么在后面，也必须选择偶数个数字，这样加上它自身，才构成奇数长度的数组；

如果在前面选择了奇数个数字，那么在后面，也必须选择奇数个数字，这样加上它自身，才构成奇数长度的数组；

数字前面共有 left 个选择，其中偶数个数字的选择方案有 left_even = (left + 1) / 2 个，奇数个数字的选择方案有 left_odd = left / 2 个；

数字后面共有 right 个选择，其中偶数个数字的选择方案有 right_even = (right + 1) / 2 个，奇数个数字的选择方案有 right_odd = right / 2 个；

所以，每个数字一共在 left_even * right_even + left_odd * right_odd 个奇数长度的数组中出现过。
* 
**/
int sumOddLengthSubarrays(int* arr, int arrSize)
{
    int res = 0;
    for(int i = 0; i < arrSize; i ++)
    {
        int left = i + 1;
        int  right = arrSize - i;
        int  left_even = (left + 1) / 2;
        int  right_even = (right + 1) / 2;
        int  left_odd = left / 2;
        int  right_odd = right / 2;
        res += (left_even * right_even + left_odd * right_odd) * arr[i];
    }
    return res;

}

int main(int argc, char *argv[])
{

	int arrays[]= {1,4,2,5,3,5};
	
	printf("[arrays = [");
	for (int i = 0;i < sizeof(arrays)/ sizeof(int); ++i)
	{
		if (0 != i)
		{
			printf(", ");
		}
		printf("%d", arrays[i]);
	}
	printf("]\n");

	printf("num = %d\n", sumOddLengthSubarrays(&arrays[0], sizeof(arrays)/ sizeof(int)));
	

    return EXIT_SUCCESS;
}
