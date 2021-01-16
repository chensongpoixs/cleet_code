@[TOC](并查集之1584. 连接所有点的最小费用)

# 前言
## 一， 1584. 连接所有点的最小费用

给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。

 

示例 1：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210116225919119.png#pic_center)


输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
输出：20
解释：

我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
示例 2：


![在这里插入图片描述](https://img-blog.csdnimg.cn/20210116230025601.png#pic_center)

输入：points = [[3,12],[-2,5],[-4,1]]
输出：18
示例 3：

输入：points = [[0,0],[1,1],[1,0],[-1,1]]
输出：4
示例 4：

输入：points = [[-1000000,-1000000],[1000000,1000000]]
输出：4000000
示例 5：

输入：points = [[0,0]]
输出：0
 

提示：

1 <= points.length <= 1000
-106 <= xi, yi <= 106
所有点 (xi, yi) 两两不同。
通过次数4,242提交次数8,071

[题目链接](https://leetcode-cn.com/problems/min-cost-to-connect-all-points)

## 二， 解题思路

根据题意: 

集合与集合之间的距离所以并查集建立模型

集合与集合之间的最小距离就需要全部遍历一次计算出最小的值







### ***一共要分为两个步骤来做***

1. 默认每个数都不在新集合中, 计算没有在新集合中点的距离（当前集合中的个数大于1[新集合]就不就计算了距离，留第二个步骤中计算）
2. 在第一步中多组集合，现在就需要计算集合与集合之间的关系，求得集合与集合的最小距离就要合并新的集合中去, 依次计算出每个集合与集合之间的最小距离。



举例：

```c
points = [[0,0],[2,2],[3,10],[5,2],[7,0],[5,6]]
```

### ***第一次合并集合得了***

并查集的数据变成了

```c
0, 0, 2 ,0, 0, 2
```

有两组集合分别是

集合0

```c
[0,0],[2,2],[5,2],[7,0]
```

新的集合0中最小距离是11


集合2

```c
[3,10],[5,6]
```

新的集合2中的最小的距离就是6

### ***第二次合并新的集合***

算得新的集合0中点[5,2]到新集合2中的点[5,6]是最小的距离是4


最终的最小是 11 + 6 +4 = 21



流程图

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210116230414923.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)





## 三， 代码

```cpp
class Solution 
{
private:
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
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int ans = 0;
        std::map<int, std::vector<int>> union_find_map;
        int union_find[points.size()];
        init(&union_find[0], points.size());

        for (int j = 0; j < points.size(); ++j)
        {
            int index = -1;//选择最小那个路径
            int vj = getfriend(&union_find[0], j);
            if (vj != j)
            {
                continue;//说明在集合中需要最后处理集合与集合资金的关系
            }
            int cost = 10 * 12;
            for (int i = 0; i < points.size(); ++i)
            {
                if (i != j)
                {
                    int vi = getfriend(&union_find[0], i);
                    if (vi != vj)
                    {
                        //计算最小曼哈顿距离
                        int value = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                        //最小距离
                        if (value < cost)
                        {
                            cost = value;
                            index = i;
                        }
                    }
                    else 
                    {
                        printf("error = %d\n", vi);
                    }
                }
            }
            
            if (index != -1)
            {
                 ans += cost;
                int vi = getfriend(&union_find[0], index);
                if(vi != vj)
                {
                    if (vi > vj)
                    {
                        union_find[index] = vj;
                    }
                    else 
                    {
                        union_find[j] = vi;
                    }
                }
            }
           
        }
        printf("ans = %d\n", ans);
        
        for (int i = 0; i < points.size(); ++i)
        {
            union_find_map[union_find[i]].push_back(i);
        }
        int hash[union_find_map.size()];
        int index = 0;
        for (const std::pair<int, std::vector<int>>& _pair: union_find_map)
        {
            hash[index++] = _pair.first;
        }
        index = 0;
        for (int i = 0; i < union_find_map.size()-1; ++i)
        {
             int cost = 1000000000; 
            if (i>= union_find_map.size())
            {
                continue;
            }
            for (const int& value1: union_find_map[hash[i]])
            {
                for (int j = i+1; j < union_find_map.size(); ++j)
                {
                    if (j>= union_find_map.size())
                    {
                        continue;
                    }
                    for (const int& value2 : union_find_map[hash[j]])
                    {
                        int pp = abs(points[value2][0]-points[value1][0]) + abs(points[value2][1]-points[value1][1]);
                        //   printf("i = %d, j = %d, value1 = %d, value2 = %d,  pp =%d\n", i, j, value1, value2,  pp);
                        //最小距离
                        if (pp < cost)
                        {
                            cost = pp;
                            index = j;
                        } 
                    }
                }
            }
                
           //合并到新的聚合中去
           for (const int & new_value: union_find_map[hash[i]])
           {
                union_find_map[hash[index]].push_back(new_value);
           }
           
            ans = ans + cost;
        }
       
        return ans;
    }
};

//[[5,8],[18,-6],[-18,13],[-8,-13],[-13,3],[-15,2],[-12,17],[14,16],[-4,3],[-17,-7],[8,9],[17,14],[-13,2],[-3,-1],[4,-20]]
```

时间复杂度$O(N^2+N^2)$
空间复杂度$O()$

# 总结