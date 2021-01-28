﻿# 5243. 同积元组

给你一个由 不同 正整数组成的数组 nums ，请你返回满足 a * b = c * d 的元组 (a, b, c, d) 的数量。其中 a、b、c 和 d 都是 nums 中的元素，且 a != b != c != d 。



示例 1：

``` 
输入：nums = [2,3,4,6]
输出：8
解释：存在 8 个满足题意的元组：
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (3,4,2,6) , (3,4,6,2) , (4,3,6,2)
示例 2：

输入：nums = [1,2,4,5,10]
输出：16
解释：存在 16 个满足题意的元组：
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
示例 3：

输入：nums = [2,3,4,6,8,12]
输出：40
示例 4：

输入：nums = [2,3,5,7]
输出：0

```

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 104
nums 中的所有元素 互不相同
通过次数2,416提交次数6,593




### 解题思路

根据题意可以理解为求得目标值的 和LeetCode上两数之和是一样的题型

那个这个目标值就要保存到哈希表中了查询的时候时间复杂度 $O(1)$

题中题意提示我们nums 中的所有元素 互不相同所以不需要去重和排序了

1. 直接结算目标值保存到哈希表
2. 哈希表中的个数大于1是就要使用等差数列结算出元组的个数

等差数列的公式

$a_n = a_1 +(n-1)*d$

$S_n = n*a_1 + \frac{(n-1)n}{2} *d$

d是公差

举例分析



nums = $[2,3,4,6,8,12]$


组合有

```c
[2,  3]  => 6
[2,  4]  => 8
[2,  6]  => 12
[2,  8]  => 16
[2, 12]  => 24
[3,  4]  => 12
[3,  6]  => 18
[3,  8]  => 24
[3, 12]  => 36
[4,  6]  => 24
[4,  8]  => 32
[4, 12]  => 48
[6,  8]  => 48
[6, 12]  => 72
[8, 12]  => 96
```

目标值有target = $[ 6, 8, 12, 16,18, 24, 32, 48, 72, 96 ]$
``` 
target[6]= 1
target[8]= 1
target[12]= 2
target[16]= 1
target[18]= 1
target[24]= 3
target[32]= 1
target[36]= 1
target[48]= 2
target[72]= 1
target[96]= 1
```

其中有目标值target[24]=3

这个需要使用等差数列来求和 大于目标值的个数大于等于2要使用等差数列求和

公差是1 

$a1=0$

带入公式求得个数是  $n*0 + \frac{a_(n-1)a_n}{2} *1 = \frac{3*2}{2} = 3$




### 代码

```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        int count = 0;
        //时间复杂度降低到O(N^2)
        std::unordered_map<long long , int>  m_target;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                if (i != j)
                {
                    ++m_target[nums[i]* nums[j]];
                }
            }
        }
        for (const std::pair<long long , int> &_pair: m_target)
        {
            if (_pair.second> 1)
            {
                //等差数列求和公式 [n (a1) + (a(n-1) +an)/2 ]
                count += ((_pair.second*(_pair.second-1))*4) ;
            }
        }
        return count;
    }
};
```