/***********************************************************************************************
	created: 		2020-10-29

	author:			chensong

	purpose:		11.container_with_most_water.c

************************************************************************************************/

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int maxArea(int* height, int heightSize)
{
    int min  = 0, max = heightSize - 1;

    int area_max = 0;
    //结束条件
    while (min < max)
    {
        //面积公式  取小高度
        int area = (max - min) * (height[min]> height[max]? height[max]: height[min]);
        if (area > area_max)
        {
            area_max = area;
        }
        // 比较高
        if (height[min] <= height[max])
        {
            //判断下一个坐标的高度是否比前一个坐标高度高
            while (++min < max && height[min] <= height[min-1])
            {
                continue;
            }
        }
        else
        {
            while (min < --max && height[max]<=height[max +1])
            {
                continue;
            }
        }
    }

    return area_max;  

}

// cmd ./test 1 8 6 2 5 4 8 3 7
int main(int argc, char *argv[])
{

	int count = argc -1;
	int * nums = malloc(count* sizeof(int));
	if (!nums)
	{
		return -1;
	}
	for (int i = 0; i < count; ++i)
	{
		nums[i+1] = atoi(argv[i+1]);
	}

	printf("area size = %d\n", maxArea(nums, count));
	if (nums)
	{
		free(nums);
		nums = NULL;
	}
	return 0;
}
