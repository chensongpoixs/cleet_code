/***********************************************************************************************
	created: 		2020-05-07
	
	author:			chensong
					
	purpose:		1.sum_of_two_numbers
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
