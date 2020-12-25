/***********************************************************************************************
	created: 		2020-11-14

	author:			chensong

	purpose:		1122. ������������
�ҿ��ܻ������ܶ���ˣ������ǽ���2��Ĺ��£�����д�ɹ��»��ɸ裬����ѧ���ĸ�������������??
Ȼ�󻹿�����һ����������һ�������ҵĹ�������ܻᱻ��˧����������ֻᱻ��������ں���������ĳ�������ҹ������ȫ����͸Ȼ��Ҫ������С��ס�������ϵ�ʪ�·�??
3Сʱ���������������ʵ��������ҵĹ�������Ը���򸸻���顣�Ҳ����Ѹ��������Ǵ�Խ�����������ǣ���ʼ��Ҫ�ص��Լ�������??
Ȼ���ҵ���Ӱ������ʧ���ҿ������������ˮ������ȴû���κ�ʹ�࣬�Ҳ�֪����ԭ���ҵ��ı������ˣ�������ȫ�����ԭ�򣬾���Ҫ�һ��Լ��ı���??
�����ҿ�ʼ����Ѱ�Ҹ��ָ���ʧȥ�ĵ��ˣ��ұ��һ��שͷ��һ������һ��ˮ��һ����ƣ�ȥ�����Ϊʲô��ʧȥ�Լ��ı���??
�ҷ��֣��ճ����ı��������Ļ��ڣ������ģ����ǵı��ľͻ���ʧ���յ��˸��ֺڰ�֮�����ʴ??
��һ�����ۣ������ʺͱ��ߣ�����ί����ʹ�࣬�ҿ���һֻֻ���ε��֣������ǵı��ĳ��飬�ɱΣ�͵�ߣ���Ҳ�ز������˶����??
�ҽ����������֡��������Ǻ�����ͬ�ڵļ�??�����Ҳ������£�����ϸ�����Լ�ƽ����һ??Ѱ�ұ������ֵĺۼ�??
�����Լ��Ļ��䣬һ�����ĳ�����������������֣��ҵı��ģ�����д�����ʱ�򣬻����??
��������Ȼ����������ҵ�һ�У�д��������ұ��Ļع����÷�ʽ���һ�û�ҵ��������֣��������ţ�˳�������������һ����˳�����ϣ�����������??
************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


/**
* �� arr1 �е�Ԫ�ؽ�������
*/
int prartion(int *arrays, int start, int end)
{
    // int
    int  value = arrays[start];
    int   right = start;
    int left = end +1;
    while (1)
    {
        while (arrays[++right]< value)
        {
            if (right == end)
            {
                break;
            }
        }
        while (arrays[--left]>value)
        {
            if (left == start)
            {
                break;
            }
        }
        if (left <= right)
        {
            break;
        }

        int temp = arrays[left];
        arrays[left] = arrays[right];
        arrays[right] = temp;
    }
    //������Ҫ����λ�õ�
    int temp  = arrays[start];
    arrays[start] = arrays[left];
    arrays[left] = temp;
    return left;
}

void sort(int * arrays, int start, int end)
{
    if (start >= end)
    {
        return ;
    }
    //
    int p = prartion(arrays, start, end);
    sort(arrays, start, p-1);
    sort(arrays, p+1, end);
}

void quick_sort(int * arrays, int size)
{
    if (arrays == NULL || size <= 0)
    {
        return ;
    }
    sort(arrays, 0, size-1);
}


int comp(const void* v1, const void *v2)
{
    int *a = v1;
    int *b = v2;
    return *a >= *b;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    *returnSize = 0;

    if (arr1 == NULL && arr2 == NULL)
    {
        return NULL;
    }
    if ((arr1 == NULL|| arr1Size <=0 ) && (arr2 != NULL && arr2Size >0))
    {
        *returnSize = arr2Size;
        return arr2;
    }
    //  1. arr1����
    // qsort(arr1, arr1Size, sizeof(int), comp);
    quick_sort(arr1, arr1Size);

    if (arr2 == NULL || arr2Size<=0)
    {
        *returnSize = arr1Size;
        return arr1;
    }
    int * arrays = malloc(sizeof(int) * (arr1Size ));
    int arrays_index = 0;
    for (int i = 0; i < arr2Size; ++i)
    {
        //��߲���arr1��ʱ�临�ӶȱȽϸ�һ�� ��Ϊ�ǲ�֪��
        for (int j = 0; j < arr1Size; ++j)
        {
            if (arr1[j] == arr2[i])
            {
                arrays[arrays_index++] = arr1[j];
                arr1[j] = arr2[0]; //���λ�� ����Ҫ�Ƚ���
                while (++j <arr1Size &&  arr1[j] == arr2[i])
                {
                    arrays[arrays_index++] = arr1[j] ;
                    arr1[j] = arr2[0];
                }
                break;
            }

        }
        // int index = 0;
        // //�ڱ� = 0  ������ѧ���ݽṹ ���ڱ���ʹ��
        // while (index == 0 || (++index < arr1Size && arr1[index] != arr1[index -1]) )
        // {
        //     if (arr1[index] == arr2[i])
        //     {
        //         arrays[arrays_index++] = arr1[index];
        //         arrays[arrays_index++] = arr2[i];
        //          arr1[index] = arr2[0]; //���λ�� ����Ҫ�Ƚ���
        //         while (++index <arr1Size &&  arr1[index] == arr2[i])
        //         {
        //            arrays[arrays_index++] = arr1[index] ;
        //            arr1[index] = arr2[0];
        //         }
        //         continue; //����   arr1����������Ĳ���Ҫ�ٱȽ���
        //     }
        //     else if (index == 0)
        //     {
        //         ++index;
        //     }
        // }
    }


    //2. ȥ��
    // int i = 0;
    for (int i = 0; i < arr1Size; ++i)
    {
        if(arr1[i] != arr2[0])
        {
            arrays[arrays_index++] = arr1[i];
        }
    }
    *returnSize = arr1Size ;


    return arrays;
}

int main(int argc, char *argv[])
{

    int arr1[] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr2[] = {2,1,4,3,9,6};
	
    printf("arr1 = [");
	for (int i = 0; i < sizeof(arr1)/ sizeof(int); ++i)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d ", arr1[i]);
		
    }
    printf("]\n");

	printf("arr2 = [");
    for (int i = 0; i < sizeof(arr2)/ sizeof(int); ++i)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d ", arr2[i]);
		
    }
    printf("]\n");
    int retsize = 0;
    int *arrays = relativeSortArray(&arr1[0], sizeof(arr1)/ sizeof(int), &arr2[0], sizeof(arr2)/ sizeof(int),&retsize);
    if (arrays)
    {
		printf("�����:[");
        for (int i = 0; i < retsize; ++i)
        {
            if (i != 0)
            {
                printf(", ");
            }
            printf("%d", arrays[i]);
        }
        printf("]\n");
        free(arrays);
        arrays = NULL;
    }
	
    return EXIT_SUCCESS;
}