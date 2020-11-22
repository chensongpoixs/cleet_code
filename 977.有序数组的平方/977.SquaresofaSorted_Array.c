/***********************************************************************************************
	created: 		2020-11-19

	author:			chensong

	purpose:		977.���������ƽ��
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


int parition(int * A, int start, int end)
{
    int value = A[start];
    int left = start;
    int right = end +1;
    while (1)
    {
        //�ҳ�������
        while (A[++left] < value)
        {
            if (left == end)
            {
                break;
            }
        }
        //�ҳ���С����
        while (A[--right] > value)
        {
            if (right == start)
            {
                break;
            }
        }
        if (right <= left)
        {
            break;
        }
        int temp = A[right];
        A[right] = A[left];
        A[left] = temp;
    }
    int temp = A[start];
    A[start]  = A[right];
    A[right] = temp;
    return right;
}
void sort(int *A, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int p = parition(A, start, end);
    sort(A, start, p -1);
    sort(A, p +1, end);
}
void quick_sort(int *A, int size)
{
    if (A == NULL || size <2)
    {
        return;
    }
    sort(A, 0, size-1);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){


    for(int i = 0; i < ASize; ++i)
    {
        A[i] = abs(A[i]) * abs(A[i]);
    }
    quick_sort(A, ASize);
    *returnSize = ASize;
    return A;
}

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}