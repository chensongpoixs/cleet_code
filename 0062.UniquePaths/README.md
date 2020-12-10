@[TOC](目录)


# 一， 62. 不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

 

示例 1：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201210215815630.png#pic_center)


输入：m = 3, n = 7
输出：28
示例 2：

输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 3：

输入：m = 7, n = 3
输出：28
示例 4：

输入：m = 3, n = 3
输出：6
 

提示：

1 <= m, n <= 100
题目数据保证答案小于等于 2 * 109
通过次数192,359提交次数302,076

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# 二， 解题思路

## 1， 动态规划

权重

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201210221108929.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)

最后取finish中的值就是路径数

时间复杂度O(n*m)

空间复杂度O(n*m)

## 2，排列组合公式

m有向右有m-1次偏移， n向下偏移n-1次就 总共有 $(m+n-2)!$路径

上面的路径满足向右偏移$m-1$的就有公式 $C{(m+n-2) \atop (m-1)!}$ =  $\frac{(m+n-2)!}{(m-1)!}$ 


# 三， 解题程序

```c
// C (n+m-2)! / (m-1)! 
int uniquePaths1(int m, int n)
{
    long long ans = 1;
    for (int x = n, y = 1; y < m; ++x, ++y) 
    {
        ans = ans * x / y;
    }
    return ans;
}


//动态规划 ----》》》》》
int uniquePaths(int m, int n)
{
  

    int **arrays = malloc(sizeof(int *)*m);
    for (int i = 0; i < m; ++i)
    {
        arrays[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; ++j)
        {
            arrays[i][j] = 1;
        }
    }
    
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j <n; ++j)
        {
            arrays[i][j] = arrays[i-1][j]+arrays[i][j-1];
        }
    }
    int ans = arrays[m-1][n-1];
    for (int i = 0; i < m; ++i)
    {
        if (arrays[i])
        {
            free(arrays[i]);
            arrays[i] = NULL;
        }
    }
    free(arrays);
    arrays = NULL;
    return ans;
}
```



# 四， 63. 不同路径 II

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201210222954586.png#pic_center)


网格中的障碍物和空位置分别用 1 和 0 来表示。

 

示例 1：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201210223008963.jpg#pic_center)


输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
示例 2：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201210223023700.jpg#pic_center)


输入：obstacleGrid = [[0,1],[0,0]]
输出：1
 

提示：

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] 为 0 或 1
通过次数113,302提交次数304,675
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


# 五， 解题思路

和上面动态规划是一样的思路

# 六， 解题程序

```c
//动态规划
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int **arrays = malloc(sizeof(int *) * obstacleGridSize);
    for (int i = 0; i < obstacleGridSize; ++i)
    {
        arrays[i] = malloc(sizeof(int) * obstacleGridColSize[0]);
        for (int j = 0; j < obstacleGridColSize[0]; ++j)
        {
            arrays[i][j] = 1;
        }
    }
    for (int i = 0; i <obstacleGridSize; ++i)
    {
        for( int j = 0; j <obstacleGridColSize[0]; ++j)
        {
            if (obstacleGrid[i][j] == 1)
            {
                arrays[i][j] = 0;
            }
            else if (i > 0 && j > 0&& obstacleGrid[i-1][j] == 1)
            {
                arrays[i][j] = arrays[i][j-1];
            }
            else if (i > 0 && j > 0 && obstacleGrid[i][j-1]== 1)
            {
                arrays[i][j] = arrays[i-1][j];
            }
            else if (i > 0 && j > 0)
            {
                arrays[i][j] = arrays[i][j-1] +arrays[i-1][j];
            }
            else if (i > 0 && j ==0)
            {
                if (obstacleGrid[i-1][j] == 1)
                {
                arrays[i][j] = 0;
                }
                else 
                {
                arrays[i][j] =  arrays[i-1][j];
                }
                 
            }
            else if (j > 0 && i ==0)
            {
               if (obstacleGrid[i][j-1] == 1)
                {
                arrays[i][j] = 0;
                }
                else 
                {
                arrays[i][j] =  arrays[i][j-1];
                } 
            }
        }
    }
    int ans = arrays[obstacleGridSize-1][obstacleGridColSize[0]-1];
    for (int i = 0; i < obstacleGridSize; ++i)
    {
        if (arrays[i] )
        {
            free(arrays[i]);
            arrays[i]  = NULL;
        }
        
    }
    free(arrays);
    arrays = NULL;
    return ans;
}
```
# 七， 总结

时间复杂度是$O(n*m)$

[源码地址:https://github.com/chensongpoixs/cleet_code](https://github.com/chensongpoixs/cleet_code)
