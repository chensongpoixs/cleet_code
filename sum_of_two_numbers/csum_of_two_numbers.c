/***********************************************************************************************
	created: 		2020-05-07
	
	author:			chensong
					
	purpose:		1.sum_of_two_numbers
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
 *  给定一个整数数组和一个目标值, 找出数组中和为目标值的两个数。
 *  你可以假设每个输入只对应一个答案,且同样的元素不能被重复利用。
 *   
 *  示例:
 *    给定nums = [2, 7, 11, 15], target = 9
 *    因为nums[0] = nums[1] = 2 + 7 = 9
 *    所以返回[0, 1]
 */
 



#include <stdio.h>
#include <stdlib.h>

struct object 
{
	size_t m_index;
	int m_value;
};

static /*inline*/ int compare(const void * a, const void * b)
{
	return ((struct object *)a)->m_value - ((struct object *)a)->m_value;
}

static size_t* two_sum(int *nums, size_t nums_size, int target)
{
	size_t i = 0;
	size_t j = 0;
	struct object * objs = malloc(nums_size * sizeof(*objs));
	if (!objs)
	{
		printf("alloc failed nums_size = %lu\n", nums_size);
		return 0;
	}
	for (i = 0; i < nums_size; ++i)
	{
		objs[i].m_index = i;
		objs[i].m_value = nums[i];
	}
	//排序
	qsort(objs, nums_size, sizeof(*objs), compare);
	
	size_t * ret = malloc(2 * sizeof(size_t));
	i = 0;
	j = nums_size -1;
	while (i < j)
	{
		int diff = target - objs[i].m_value;
		if (diff > objs[j].m_value)
		{
			while (++i <j && objs[j].m_value == objs[i - 1].m_value){}
		}
		else if (diff < objs[j].m_value)
		{
			while (--j >i && objs[i].m_value == objs[i + 1].m_value){}
		}
		else 
		{
			ret[0] = objs[i].m_index;
		
			ret[1] = objs[j].m_index;
			if (objs)
			{
				free(objs);
				objs = NULL;
			}
			return ret;
		}
	}
	if (objs)
	{
		free(objs);
		objs = NULL;
	}
	return  NULL;
}

int main(int argc, char *argv[])
{
	int nums[] = {3, 2, 3};
	int counts = sizeof(nums) / sizeof(*nums);
	int target = 6;
	size_t *find = two_sum(nums, counts, target);
	if (find)
	{
		printf("find two index 1 = %lu, index 2 = %lu\n", find[0], find[1]);
	    free(find);
		find = NULL;
	}
	else 
	{
		printf("not find two!!!!! \n");
	}
	return 0;
}
