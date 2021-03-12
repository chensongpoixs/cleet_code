/***********************************************************************************************
	created: 		2021-01-28

	author:			chensong

	purpose:		1579. 保证图可完全遍历

************************************************************************************************/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define bool int
#define true 1
#define false 0


void init(int * union_find, int size)
{
    for (int i = 0; i < size; ++i)
    {
        union_find[i] = i;
    }

}


void show(int *union_find, int size)
{
    printf("[");
    for (int i = 0; i < size; ++i)
    {
        printf("%d, ", union_find[i]);
    }
    printf("]\n");
}

int getfriend(int * union_find, int v)
{
    if (union_find[v] == v)
    {
        return v;
    }
    return union_find[v] = getfriend(&union_find[0], union_find[v]);
}
bool merge(int * union_find, int v1, int v2)
{
    int index1 = getfriend(&union_find[0], v1);
    int index2 = getfriend(&union_find[0], v2);
    if (index1 != index2)
    {
        if (index2 > index1)
        {
            union_find[v2] = v1;
            union_find[index2] = v1;
        }
        else if (index2 < index1)
        {
            union_find[v1] = v2;
            union_find[index1] = v2;
        }
        return true;
    }
    return false;
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize)
{
    int union_finda[n+1];
    int union_findb[n+1];
    init(&union_finda[0], n+1);
    init(&union_findb[0], n+1);
    int counta = n-1;
    int countb = n-1;
    int count = 0;

    //共同的边
    for (int i = 0; i < edgesSize; ++i)
    {
        if (edges[i][0] == 3)
        {
            if(merge(&union_finda[0], edges[i][1], edges[i][2]))
            {
                --counta;
            }
            if (merge(&union_findb[0], edges[i][1], edges[i][2]))
            {
                --countb;
            }
             else 
            {
                ++count;
            }
        }
    }
    
    // show(&union_finda[0], n+1);
    // show(&union_findb[0], n+1);
    for (int i = 0; i < edgesSize; ++i)
    {
        if (edges[i][0] == 1)
        {
            //判断当前集合是否可以删除 不可以删除放到union_finda中，  可以删除放 删除的边数到count中
            if (merge(&union_finda[0], edges[i][1], edges[i][2]))
            {
                --counta;
            }
            else if (merge(&union_findb[0], edges[i][1], edges[i][2]))
            {
                --countb;
            }
            else 
            {
                ++count;
            }
            // _union(&union_findb, edges[i][1], edges[i][2]);
        }
       
    }
    // show(&union_finda[0], n+1);
    
    for (int i = 0; i < edgesSize; ++i)
    {
        if (edges[i][0] == 2)
        {
           if (merge(&union_findb[0], edges[i][1], edges[i][2]))
           {
               --countb;
           }
           else if (merge(&union_finda[0], edges[i][1], edges[i][2]))
            {
                --counta;
            }
            else 
            {
                ++count;
            }
            // _union(&union_findb, edges[i][1], edges[i][2]);
        }
    }
    // show(&union_findb[0], n+1);
    // if ()
    // printf("w = %d, b = %d,  count = %d, counta = %d, countb = %d\n", w , b, count, counta, countb);
    if (countb != 0|| counta != 0)
    {
        return -1;
    }
    return count;

}


int main(int argc, char *argv[])
{
	printf("13\n"
           "[[1,1,2],[2,2,3],[2,3,4],[1,3,5],[3,2,6],[2,3,7],[3,7,8],[3,2,9],[2,4,10],[2,9,11],[1,2,12],[3,4,13],[2,2,7],[1,1,9],[1,2,13],[2,7,13],[3,2,3],[1,7,10],[2,8,11],[1,2,7],[2,1,9],[2,2,9],[1,5,6],[2,4,9],[1,7,8],[1,4,6],[1,4,9],[3,7,13],[2,2,8],[2,2,6],[1,1,10],[1,1,11],[2,5,10],[1,2,9],[2,1,2],[1,3,4],[3,6,8],[3,6,13],[1,3,8],[1,1,6],[3,3,9],[1,2,3],[1,11,13]]\n");
	return 0;
}