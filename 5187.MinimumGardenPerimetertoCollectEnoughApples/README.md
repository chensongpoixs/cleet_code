@[TOC](LeetCode5187. 收集足够苹果的最小花园周长
)


<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 前言
数学知识

## 一，5187. 收集足够苹果的最小花园周长

给你一个用无限二维网格表示的花园，每一个 整数坐标处都有一棵苹果树。整数坐标 (i, j) 处的苹果树有 |i| + |j| 个苹果。

你将会买下正中心坐标是 (0, 0) 的一块 正方形土地 ，且每条边都与两条坐标轴之一平行。

给你一个整数 neededApples ，请你返回土地的 最小周长 ，使得 至少 有 neededApples 个苹果在土地 里面或者边缘上。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x
如果 x < 0 ，那么值为 -x
 

示例 1：
![在这里插入图片描述](https://img-blog.csdnimg.cn/6384009257de4901afcf6f1fa4783c89.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)

```c
输入：neededApples = 1
输出：8
解释：边长长度为 1 的正方形不包含任何苹果。
但是边长为 2 的正方形包含 12 个苹果（如上图所示）。
周长为 2 * 4 = 8 。
```

示例 2：

```c
输入：neededApples = 13
输出：16
```

示例 3：

```c
输入：neededApples = 1000000000
输出：5040
 ```

提示：

```c
1 <= neededApples <= 1015
```


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-garden-perimeter-to-collect-enough-apples
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 二，解题思路

一个项限推理找规律


![在这里插入图片描述](https://img-blog.csdnimg.cn/7149bc87777d4737bdbc7acbc8425467.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)


上面推理一个象限的公式 只需要乘以4就可以了

 $\vec N$ $\Longrightarrow$ [$n_{w - 1}$+$n_{w - 2}$+ ...+ $n_1$]

一个象限中全部的值： $\vec N$  * (2n -1) 


全部象限中的值是 ： $S(n)$ = $\vec N$  * (2n -1)  * 4 



 公式： $S(n)$ = $\vec N$  * (2n -1)  * 4


## 三， 代码

```c
long long minimumPerimeter(long long neededApples)
{
    long long ans = 0;  
    long long need = 0;
    for (long long  i  = 1; i < 1e15+1; ++i)
    {
    	//一个象限中 （1 + 2 + ... + n） 
        need +=i;
        ans =   (need * (2* i +1)) * 4 ;
        if ( ans >= neededApples) 
        {
            return i * 8;
        }
    }
    return ans;
}

```

# 总结

时间复杂度$O(N)$



[源码地址:https://github.com/chensongpoixs/cleet_code](https://github.com/chensongpoixs/cleet_code)


