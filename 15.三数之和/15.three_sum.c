/***********************************************************************************************
	created: 		2020-11-01

	author:			chensong

	purpose:		15. ����֮��
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
   
	
	int retsize = 0;
	int * retclomueesize = NULL;
	int ** retarray = threeSum(&array[0], 6, &retsize, &retclomueesize);
	
	for (int i = 0;  i < retsize; ++i)
	{
		printf("[%d][%d][%d]\n", retarray[i][0], retarray[i][1], retarray[i][2]);
	}

	

    return 0;
}