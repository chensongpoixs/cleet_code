    


@[TOC](并查集之LeetCode1319. 连通网络的操作次数)


<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 前言

算法之并查集

# 一、1319. 连通网络的操作次数

用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。

网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。

给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回 -1 。 

 

示例 1：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210123161603806.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)


输入：n = 4, connections = [[0,1],[0,2],[1,2]]
输出：1
解释：拔下计算机 1 和 2 之间的线缆，并将它插到计算机 1 和 3 上。
示例 2：

![在这里插入图片描述](https://img-blog.csdnimg.cn/2021012316161643.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)


输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
输出：2
示例 3：

输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
输出：-1
解释：线缆数量不足。
示例 4：

输入：n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
输出：0
 

提示：

1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
没有重复的连接。
两台计算机不会通过多条线缆连接。
通过次数16,741提交次数28,117

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


# 二、解题思路

这题是并查集有多少个集合的问题 ， 根据题意可以知道要求有一个集合就可以了。那只要我们求出现在有多少个集合然后减去1就是要最少操作次数


# 三，代码

```c
/**
*并查集的初始化
*/
void init(int *union_find, int size)
{
    for (int i = 0; i < size; ++i)
    {
        union_find[i] = i;
    }
}
/**
* 查询集合的id
*/
int getfriend(int *union_find, int v)
{
    if (union_find[v] == v)
    {
        return v;
    }
    return union_find[v] = getfriend(&union_find[0], union_find[v]);
}
/**
* 这个问题还是求集合的个数的问题 现在只是需求集合的个数为1个就可以了
*/
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize)
{
    if (n > connectionsSize+1)
    {
        return -1;
    }

    int union_find[n] ;
    init(&union_find[0], n);

    int union_count = n-1; //集合的个数

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
```



# 总结
时间复杂度O(N)
空间复杂度O(N)

[源码地址:https://github.com/chensongpoixs/cleet_code](https://github.com/chensongpoixs/cleet_code)
