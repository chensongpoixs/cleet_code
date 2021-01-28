/***********************************************************************************************
	created: 		2020-11-01

	author:			chensong

	purpose:		15. ����֮��
************************************************************************************************/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * # 15. ����֮��
  ����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 �������ҳ��������������Ҳ��ظ�����Ԫ�顣

  ע�⣺���в����԰����ظ�����Ԫ�顣



  ʾ����

  �������� nums = [-1, 0, 1, 2, -1, -4]��

  ����Ҫ�����Ԫ�鼯��Ϊ��
  [
    [-1, 0, 1],
    [-1, -1, 2]
  ]

 */

int compare (const void *a ,const void *b)
{
	int *aa=(int * ) a,*bb = (int * )b;
	if( * aa >* bb) 
    {
        return 1;
    }
	if( * aa == * bb) 
    {
        return 0;
    }
	if( * aa < *bb) 
    {
        return -1;
    }
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    
        *returnSize = 0;
    if (nums == NULL || numsSize < 3 )
    {
        return NULL;
    }
    int alloc_size = 1;
    int* *arrayy = malloc(alloc_size * sizeof(int*));
    *returnColumnSizes = malloc(alloc_size * sizeof(int));
    qsort(&nums[0] , numsSize, sizeof(int), compare);
   
   
   
    
    int array_index = 0;
    int b = 0;
    int c = 0;
    for (int a = 0; a < numsSize; ++a)
    {
        if (a == 0 || a > 0 && nums[a] != nums[a-1])
        {
            b = a + 1;
            c = numsSize - 1;
            while (b < c)
            {
                int diff = nums[a] + nums[b];
                if ( diff + nums[c]  > 0)  // �Ƚϴ�С������������л���û������
                {
                    while (--c > b && nums[c] == nums[c+1]){}
                }
                else if (diff + nums[c] < 0)
                {
                    while (++b < c && nums[b] == nums[b-1]){}
                }
                else 
                {
                    (*returnColumnSizes)[ *returnSize] =3;
                    arrayy[ *returnSize] = malloc(3 * sizeof(int));
                    arrayy[ *returnSize][0] = nums[a];
                    arrayy[ *returnSize][1] = nums[b];
                    arrayy[ *returnSize][2] = nums[c];
                    (*returnSize)++;
                    while (--c > b && nums[c] == nums[c+1]){}
                    while (++b < c && nums[b] == nums[b-1]){}

                    //�ڴ治��ʱ���� 2������
                    if (*returnSize == alloc_size) 
                    {
                        alloc_size = 2 * alloc_size;
                        arrayy = realloc(arrayy, alloc_size*  sizeof(int*));
                        (*returnColumnSizes) = realloc((*returnColumnSizes),  alloc_size* sizeof(int));
                    }
                       
                }
                
            }
        }
        
    }
  
   
    return arrayy;
}

int main(int argc, char *argv[])
{

    int array[] = { -1, 0, 1, 2, -1, -4 };// {0, 0, 0, 0};
   
	printf("array [] = { -1, 0, 1, 2, -1, -4 }\n");
	int retsize = 0;
	int * retclomueesize = NULL;
	int ** retarray = threeSum(&array[0], 6, &retsize, &retclomueesize);
	
	for (int i = 0;  i < retsize; ++i)
	{
		printf("[%d][%d][%d]\n", retarray[i][0], retarray[i][1], retarray[i][2]);
	}

	

    return 0;
}