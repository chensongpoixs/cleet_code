/***********************************************************************************************
	created: 		2021-01-23

	author:			chensong

	purpose:		1319. ��ͨ����Ĳ�������
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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void init(int *union_find, int size)
{
    for (int i = 0; i < size; ++i)
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
/**
* ������⻹���󼯺ϵĸ��������� ����ֻ�����󼯺ϵĸ���Ϊ1���Ϳ�����
*/
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize)
{
    if (n > connectionsSize+1)
    {
        return -1;
    }

    int union_find[n] ;
    init(&union_find[0], n);

    int union_count = n-1;

    for (int i = 0; i < connectionsSize; ++i)
    {
        int vi = getfriend(&union_find[0], connections[i][0]);
        int vj = getfriend(&union_find[0], connections[i][1]);
        if (vi != vj)
        {
            --union_count;
            if (vi < vj)
            {
                union_find[connections[i][1]] = vi;
                union_find[vj] = vi;

            }
            else if (vi > vj)
            {
                union_find[connections[i][0]] = vj;
                union_find[vi] = vj;
            }
        }
    }



    return union_count;
}

int main(int argc, char *argv[])
{
    printf("n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]\n");
    return 0;
}