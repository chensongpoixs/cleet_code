/***********************************************************************************************
	created: 		2021-01-17

	author:			chensong

	purpose:		684. ��������
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
void init(int * union_find, int size)
{
    for (int i =  0; i < size; ++i)
    {
        union_find[i] = i;
    }
}
int getfriend(int *union_find, int v)
{
    if (union_find[v] == v)
    {
        return v;
    }
    return union_find[v] = getfriend(&union_find[0], union_find[v]);
}
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    *returnSize = 0;
    int union_find[edgesSize+1];
    init(&union_find[0], edgesSize+1);
    int *arrays = malloc(sizeof(int ) * edgesSize);
    for(int i = 0; i < edgesSize; ++i)
    {
        int vi = getfriend(&union_find[0], edges[i][0]);
        int vj = getfriend(&union_find[0], edges[i][1]);
        if (vi != vj)
        {
            if (vi > vj)
            {
                union_find[edges[i][0]] = vj;
                union_find[vi] = vj;
            }
            else if (vi < vj )
            {
                union_find[edges[i][1]] = vi;
                union_find[vj] = vi;
            }
        }
        else
        {
            //˵����һ��������
            arrays[(*returnSize)++] = edges[i][0];
            arrays[(*returnSize)++] = edges[i][1];
            return arrays;
        }
    }
    return arrays;
}

int main(int argc, char *argv[])
{

    printf("edges = [[1,2], [1,3], [2,3]]\n");

    int ** edges = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; ++i)
    {
        edges[i] = malloc (sizeof(int) * 2);
    }
    int index = 0;
    edges[index][0] = 1;
    edges[index++][1] = 2;
    edges[index][0] = 1;
    edges[index++][1] = 3;
    edges[index][0] = 2;
    edges[index++][1] = 3;
    int retsize = 0;
    int *arrays = findRedundantConnection(edges, 3, NULL, &retsize);
    if (retsize>1)
    {
        printf("[");
        for (int i = 0; i < retsize; ++i)
        {
            if (0 != i)
            {
                printf(", ");
            }
            printf("%d", arrays[i]);
        }
        printf("]\n");
    }
    if (arrays)
    {
        free(arrays);
        arrays = NULL;
    }
    if (!edges)
    {
        return 0;
    }
    for (int i = 0; i < 3; ++i)
    {
        if (    edges[i] )
        {
            free(edges[i]);
            edges[i] = NULL;
        }
    }
    if (edges)
    {
        free(edges);
        edges = NULL;
    }


    return 0;
}