/***********************************************************************************************
	created: 		2020-11-15

	author:			chensong

	purpose:		1476.�Ӿ��β�ѯ
�ҿ��ܻ������ܶ���ˣ������ǽ���2��Ĺ��£�����д�ɹ��»��ɸ裬����ѧ���ĸ���������������
Ȼ�󻹿�����һ����������һ�������ҵĹ�������ܻᱻ��˧����������ֻᱻ��������ں���������ĳ�������ҹ������ȫ����͸Ȼ��Ҫ������С��ס�������ϵ�ʪ�·���
3Сʱ���������������ʵ��������ҵĹ�������Ը���򸸻���顣�Ҳ����Ѹ��������Ǵ�Խ�����������ǣ���ʼ��Ҫ�ص��Լ������硣
Ȼ���ҵ���Ӱ������ʧ���ҿ������������ˮ������ȴû���κ�ʹ�࣬�Ҳ�֪����ԭ���ҵ��ı������ˣ�������ȫ�����ԭ�򣬾���Ҫ�һ��Լ��ı��ġ�
�����ҿ�ʼ����Ѱ�Ҹ��ָ���ʧȥ�ĵ��ˣ��ұ��һ��שͷ��һ������һ��ˮ��һ����ƣ�ȥ�����Ϊʲô��ʧȥ�Լ��ı��ġ�
�ҷ��֣��ճ����ı��������Ļ��ڣ������ģ����ǵı��ľͻ���ʧ���յ��˸��ֺڰ�֮�����ʴ��
��һ�����ۣ������ʺͱ��ߣ�����ί����ʹ�࣬�ҿ���һֻֻ���ε��֣������ǵı��ĳ��飬�ɱΣ�͵�ߣ���Ҳ�ز������˶���ߡ�
�ҽ����������֡��������Ǻ�����ͬ�ڵļ��� �����Ҳ������£�����ϸ�����Լ�ƽ����һ�� Ѱ�ұ������ֵĺۼ���
�����Լ��Ļ��䣬һ�����ĳ�����������������֣��ҵı��ģ�����д�����ʱ�򣬻������
��������Ȼ����������ҵ�һ�У�д��������ұ��Ļع����÷�ʽ���һ�û�ҵ��������֣��������ţ�˳�������������һ����˳�����ϣ�������������
************************************************************************************************/

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int **rect;//��ά����
	int rows; //����
	int cols;//����ĸ���
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
			obj->rect[row][col] = newValue;//�����µ�ֵ
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