/***********************************************************************************************
	created: 		2020-11-15

	author:			chensong

	purpose:		1476.子矩形查询
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

typedef struct {

	int **rect;//二维矩阵
	int rows; //行数
	int cols;//数组的个数
} SubrectangleQueries;


void show_rect(SubrectangleQueries * obj)
{
	if (!obj)
	{
		return;
	}
	//printf("[);
	for (int i = 0; i < obj->rows; ++i)
	{
		printf("[");
	    for (int j = 0; j < obj->cols ; ++j)
	    {
			if (0 != j)
			{
				printf(", ");
			}
			printf("%d", obj->rect[i][j]);
	       
	    }
		printf("]\n");
	}
	printf("\n");
}


SubrectangleQueries* subrectangleQueriesCreate(int** rectangle, int rectangleSize, int* rectangleColSize) {

	
	SubrectangleQueries * subrectangle_ptr = malloc(sizeof(*subrectangle_ptr));
	subrectangle_ptr->rows = rectangleSize;
	subrectangle_ptr->cols = rectangleColSize[0];
	subrectangle_ptr->rect = malloc(sizeof(int*) * rectangleSize);

	for (int i = 0; i < rectangleSize; ++i)
	{
		subrectangle_ptr->rect[i] = malloc(sizeof(int)*rectangleColSize[i]);
		for (int j = 0; j < rectangleColSize[i]; ++j)
		{
			subrectangle_ptr->rect[i][j] = rectangle[i][j];
		}
	}
	return subrectangle_ptr;
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries* obj, int row1, int col1, int row2, int col2, int newValue)
{
	if (!obj)
	{
		return;
	}
	if (row1 < 0)
	{
		row1 = 0;
	}
	if (col1 < 0)
	{
		col1 = 0;
	}
	for (int row = row1; row < obj->rows && row <= row2; ++row)
	{
		for (int col = col1; col < obj->cols && col <= col2; ++col)
		{
			obj->rect[row][col] = newValue;//赋上新的值
		}
	}
}

int subrectangleQueriesGetValue(SubrectangleQueries* obj, int row, int col) {

	if (!obj || (obj->rows < row) || (obj->cols - 1) < col || row < 0 || col < 0)
	{
		return 0;
	}

	return obj->rect[row][col];
}

void subrectangleQueriesFree(SubrectangleQueries* obj) {
	if (obj)
	{
		if (obj->rect)
		{
			for (int i = 0; i < obj->rows; ++i)
			{
				if (obj->rect[i])
				{
					free(obj->rect[i]);
					obj->rect[i] = NULL;
				}
			}
			free(obj->rect);
			obj->rect = NULL;
		}
		free(obj);
		obj = NULL;
	}
}

/**
 * Your SubrectangleQueries struct will be instantiated and called as such:
 * SubrectangleQueries* obj = subrectangleQueriesCreate(rectangle, rectangleSize, rectangleColSize);
 * subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);

 * int param_2 = subrectangleQueriesGetValue(obj, row, col);

 * subrectangleQueriesFree(obj);
*/

int main(int argc, char *argv[])
{
	int **rectangle = malloc(sizeof(int *) *3);// [][3] = { 1,1,1,2,2,2,3,3,3 };
	for (int i = 0; i < 3; ++i)
	{
		rectangle[i] = malloc(sizeof(int) * 3);
		for (int j = 0; j < 3; ++j)
		{
			rectangle[i][j] = i + 1;
		}
	}
	int rectangleSize = 3;
	int rectangleColSize[3] ;
	rectangleColSize[0] = 3;
	rectangleColSize[1] = 3;
	rectangleColSize[2] = 3;
	int newValue = 20;
	int row1 = 0;
	int col1 = 0;
	int row2 = 2;
	int col2 = 2;
	SubrectangleQueries* obj = subrectangleQueriesCreate(&rectangle[0], rectangleSize, rectangleColSize);
	show_rect(obj);
	subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);
	show_rect(obj);
	int row = 1;
	int col = 1;
	int param_2 = subrectangleQueriesGetValue(obj, row, col);
	printf("[1, 1] = %d\n", param_2);
	subrectangleQueriesFree(obj);
	if (rectangle)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (rectangle[i] != NULL)
			{
				free(rectangle[i]);
				rectangle[i] = NULL;
			}
			
		}
		free(rectangle);
	}

	return EXIT_SUCCESS;
}