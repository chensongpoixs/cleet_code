# 4. find_the_median_of_two_positive_arrays

考点是中位数的性质   

题目:

给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

 

示例 1:

```
    nums1 = [1, 3]
    nums2 = [2]

    则中位数是 2.0
```

示例 2:

```
    nums1 = [1, 2]
    nums2 = [3, 4]

    则中位数是 (2 + 3)/2 = 2.5
```




两种方法：

1. 合并到新的数组就行直接计算出下标
2. 递归两个数组找到中位数（是计算出的）的值

