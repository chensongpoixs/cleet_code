/***********************************************************************************************
	created: 		2021-01-12

	author:			chensong

	purpose:		547. 省份数量
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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * 并查集初始化
 * @param union_find
 * @param size
 */
void init(int * union_find, int size)
{
    for (int i = 0; i <=size; ++i)
    {
        union_find[i] = i ;
    }
}

/**
 * 并查集 查找 那个集合
 * @param union_find
 * @param v
 * @return
 */
int getfriend(int * union_find, int v)
{
    if (union_find[v] == v)
    {
        return v;
    }
    //查找上一个节点的数据
    return union_find[v] = getfriend(&union_find[0], union_find[v]);
}
/**
* 并查集
*/
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
{
    int arrays[(int)2e2+1] ={0}; // 科学计数法 e = 10
//    printf("%d\n", isConnectedSize);
    init(&arrays[0], isConnectedSize );
    int hash[isConnectedSize+1];
    for (int i = 1; i <= isConnectedSize; ++i)
    {
        hash[i] = 0;
        int connect = 0;

        for (int j = 1; j <= isConnectedColSize[i-1]; ++j)
        {

            if (  isConnected[i-1][j-1] == 1)
            {
                int iv = getfriend(&arrays[0], i);
                int jv = getfriend(&arrays[0], j);
                if (iv != jv)
                {
                    if (iv <= jv)
                    {
                        arrays[j] = iv;
                        // printf("=====j = %d, iv= %d, jv = %d\n", j, iv, jv);
                        for (int w = 1; w <=isConnectedSize; ++w )
                        {
                            if (arrays[w] == jv)
                            {
                                arrays[w] = iv;
                            }
                        }
                    }
                    else
                    {
                        arrays[j] = jv;
                        // printf("---===j = %d, iv= %d\n", j, iv);
                        for (int w = 1; w <=isConnectedSize; ++w )
                        {
                            if (arrays[w] == iv)
                            {
                                arrays[w] = jv;
                            }
                        }
                    }
                    // printf("i = %d, j = %d, iv = %d, jv = %d\n", i, j, iv, jv);
                }
            }
            else
            {
                ++connect;
            }
        }
        if (  connect == isConnectedColSize[i-1])
        {
            arrays[i] = 0;
        }
    }

     //多出统计不同集合
     // 需要时间复杂度O(N) , 空间复杂度O(N)
     //
    int count = 0;
    for (int i = 1; i <= isConnectedSize; ++i)
    {
            ++hash[arrays[i]];
    }
    for (int i = 1; i <= isConnectedSize; ++i)
    {
        if (hash[i]>0)
        {
            ++count;
        }
    }

    return count;
}


/**
* 查并集  优化过的代码 时间复杂度是O(n^2)
*/
int findCircleNumCount(int** isConnected, int isConnectedSize, int* isConnectedColSize)
{
    int arrays[(int)2e2+1] ={0}; // 科学计数法 e = 10
    init(&arrays[0], isConnectedSize );
    int count = isConnectedSize;
    int j = 0;
    int iv = 0;
    int jv = 0;
    for (int i = 1; i <= isConnectedSize; ++i)
    {
        for (j = i+1; j <= isConnectedColSize[i-1]; ++j)
        {
            if (i < j &&  isConnected[i-1][j-1] == 1)
            {
                iv = getfriend(&arrays[0], i);
                jv = getfriend(&arrays[0], j);
                if (iv != jv)
                {
                    --count;
                    if (iv <= jv)
                    {
                        arrays[j] = iv;
                        arrays[jv] = iv;

                    }
                    else
                    {
                        arrays[j] = jv;
                        arrays[iv] = jv;

                    }
                    // printf("i = %d, j = %d, iv = %d, jv = %d\n", i, j, iv, jv);
                }
            }
        }
    }
    return count;
}
int main(int argc, char *argv[])
{
    int **arrays_ptr = malloc(sizeof(int *) *3);
    arrays_ptr[0] = malloc(sizeof(int) *3);
    arrays_ptr[0][0] = 1;
    arrays_ptr[0][1] = 1;
    arrays_ptr[0][2] = 0;
    arrays_ptr[1] = malloc(sizeof(int) *3);
    arrays_ptr[1][0] = 1;
    arrays_ptr[1][1] = 1;
    arrays_ptr[1][2] = 0;
    arrays_ptr[2] = malloc(sizeof(int) *3);
    arrays_ptr[2][0] = 0;
    arrays_ptr[2][1] = 0;
    arrays_ptr[2][2] = 1;
    printf("{{1,1,0},{1,1,0},{0,0,1}}\n");
    int arraycol[3] = {3, 3, 3};
    printf("count = %d\n", findCircleNumCount(arrays_ptr, 3, &arraycol[0]));
    if (arrays_ptr)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (arrays_ptr[i])
            {
                free(arrays_ptr[i]);
                arrays_ptr[i] = NULL;
            }
        }
        free(arrays_ptr);
        arrays_ptr = NULL;
    }
    return EXIT_SUCCESS;
}