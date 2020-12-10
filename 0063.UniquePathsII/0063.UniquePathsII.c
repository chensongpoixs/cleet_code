/***********************************************************************************************
	created: 		2020-12-10

	author:			chensong

	purpose:		63. 不同路径 II
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


//动态规划
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int **arrays = malloc(sizeof(int *) * obstacleGridSize);
    for (int i = 0; i < obstacleGridSize; ++i)
    {
        arrays[i] = malloc(sizeof(int) * obstacleGridColSize[0]);
        for (int j = 0; j < obstacleGridColSize[0]; ++j)
        {
            arrays[i][j] = 1;
        }
    }
    for (int i = 0; i <obstacleGridSize; ++i)
    {
        for( int j = 0; j <obstacleGridColSize[0]; ++j)
        {
            if (obstacleGrid[i][j] == 1)
            {
                arrays[i][j] = 0;
            }
            else if (i > 0 && j > 0&& obstacleGrid[i-1][j] == 1)
            {
                arrays[i][j] = arrays[i][j-1];
            }
            else if (i > 0 && j > 0 && obstacleGrid[i][j-1]== 1)
            {
                arrays[i][j] = arrays[i-1][j];
            }
            else if (i > 0 && j > 0)
            {
                arrays[i][j] = arrays[i][j-1] +arrays[i-1][j];
            }
            else if (i > 0 && j ==0)
            {
                if (obstacleGrid[i-1][j] == 1)
                {
                arrays[i][j] = 0;
                }
                else 
                {
                arrays[i][j] =  arrays[i-1][j];
                }
                 
            }
            else if (j > 0 && i ==0)
            {
               if (obstacleGrid[i][j-1] == 1)
                {
                arrays[i][j] = 0;
                }
                else 
                {
                arrays[i][j] =  arrays[i][j-1];
                } 
            }
        }
    }
    int ans = arrays[obstacleGridSize-1][obstacleGridColSize[0]-1];
    for (int i = 0; i < obstacleGridSize; ++i)
    {
        if (arrays[i] )
        {
            free(arrays[i]);
            arrays[i]  = NULL;
        }
        
    }
    free(arrays);
    arrays = NULL;
    return ans;
}



int main(int argc, char *argv[])
{
	//[[0,0,0],[0,1,0],[0,0,0]]
	printf("[[0 0 0]\n [0 1 0]\n [0 0 0]]\n");
	int **arrays = malloc(sizeof(int *)*3);
	int * obstacleGridColSize = malloc(sizeof(int )* 3);
	for (int i = 0; i < 3; ++i)
	{
		obstacleGridColSize[i] = 3;
	}
	
	arrays[0] = malloc(sizeof(int) * 3);
	for (int i = 0; i < 3; ++i)
	{
		arrays[0][i] = 0;
	}
	arrays[1] = malloc(sizeof(int) * 3);
	for (int i = 0; i < 3; ++i)
	{
		if (i == 1)
		{
			arrays[1][i] = 1;
		}
		else 
		{
			arrays[1][i] = 0;
		}
		
	}
	arrays[2] = malloc(sizeof(int) * 3);
	for (int i = 0; i < 3; ++i)
	{
		arrays[2][i] = 0;
	}
	printf("[count = %d]\n", uniquePathsWithObstacles(arrays, 3, obstacleGridColSize));
	
	for (int i = 0; i < 3; ++i)
	{
		if (arrays[i])
		{
			free(arrays[i]);
			arrays[i]= NULL;
		}
	}
	free(arrays);
	arrays = NULL;
	if (obstacleGridColSize)
	{
		free(obstacleGridColSize);
		obstacleGridColSize = NULL;
	}
	return 0;
}

