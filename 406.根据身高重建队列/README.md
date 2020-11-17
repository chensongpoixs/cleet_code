@[TOC](文章目录)

# 一，406.根据身高重建队列


假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对 (h, k) 表示，其中 h 是这个人的身高，k 是应该排在这个人前面且身高大于或等于 h 的人数。 例如：[5,2] 表示前面应该有 2 个身高大于等于 5 的人，而 [5,0] 表示前面不应该存在身高大于等于 5 的人。

编写一个算法，根据每个人的身高 h 重建这个队列，使之满足每个整数对 (h, k) 中对人数 k 的要求。

示例：

输入：[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
输出：[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 

提示：

总人数少于 1100 人。
通过次数69,646提交次数97,421

# 二， 解题思路分析

## 1， 大致情况分为两种分别

1. 身高相同的
2. 身高不同的

下面我们就分析身高分析


## 2， 身高相同的情况

身高相同的，前面人数越多(k)是一定在后面的

例如:

$(4, 3)(4, 0)(4,  2)(4, 1)$

$(4.0)和（4， 1）坐标 中（4， 1）一定是在（4， 0）后面的$

## 3， 身高不同的情况

这个时候我们需要单独拿出一些数据来分析：

$（2, 0）, （4,0）,（5,0）,（3, 1）$




我们可以这样不同的身高按照身高从小到大的排序

得到$（2, 0）,（3, 1）, （4,0）,（5,0）$


如果是一个4的数组中 都没有使用，那么在第一个放$(2, 0)$,到放$(3, 1)$时 我检查前面是否为空如果是空记一个当到2个空再插入(3,1)数据 , <font color='red'>说明在$（3,1）$前面有一个大身高3的人，所以需要跳一个1位置</font>,所以到$(4,0)$主要有一个空位置可以插入进入了,$(5,0)$也是这样的处理的

## 4， 在这里面有一个非常关键概念就是：<font color='red'>当前要插入身高数小的数已经插入进入了， 而比它大身高数没有插入进入呢！！！ ， </font><font color='blue'>所以在当前这个数前面有几个数就空出几个位置，放比他的身高数大数</font>






# 三，解题代码


<!-- tabs:start -->

#### **C**
```c

int pratition(int **people, int start, int end)
{
    int value = people[start][0];
    int right = start;
    int left = end+1;
    while (1)
    {
        //找到最大的数的下标
        while (  people[++right][0] == value? people[right][1] > people[start][1] : people[start][0] > people[right][0] )
        {
            if(right == end)
            {
                break;
            }
        }
        //最小的值
        while ( people[--left][0] == value? people[left][1] < people[start][1] : people[start][0] < people[left][0]  /*people[--left][1] < value*/)
        {
            if (left == start)
            {
                break;
            }
        }
        if (left <= right)
        {
            break;
        }
        int * temp= people[right];
        people[right] = people[left];
        people[left] = temp;
        
    }
    int* temp = people[start];
    people[start] = people[left];
    people[left] = temp;
    return left;
}

void sort(int **people, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int p = pratition(people, start, end);
    sort(people, start, p-1);
    sort(people, p+1, end);
}
/**
*快速排序
*/
void quick_sort(int **people, int size)
{
    if (people == NULL || size <= 0)
    {
        return;
    }
    sort(people, 0, size-1);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void * ptr1, const void * ptr2)
{
    const int * value1 = *(const int **)ptr1;
    const int * value2 = *(const int **)ptr2;
    //a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]
    return (value1[0] == value2[0]) ? value2[1] - value1[1] : value1[0] - value2[0];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    //           [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    //1. 快速排序  [[5,2],[5,0],[6,1],[7,0],[4,4],[7,1]]
    quick_sort(people, peopleSize);
    // 2.        [[4,4],[5,2],[5,0],[6,1],[7,1],[7,0]]
    // qsort(people, peopleSize, sizeof(int *), comp );
    //  *returnSize = peopleSize;
    //  *returnColumnSizes = peopleColSize;
    //  return people;
    
    int **arrays = malloc(sizeof(int *) * peopleSize);
    *returnColumnSizes = malloc(sizeof(int) * peopleSize);
    memset(*returnColumnSizes, 0, sizeof(int)*peopleSize);
    for (int i = 0; i < peopleSize; ++i)
    {
        int split = people[i][1] +1;
        for (int j = 0; j < peopleSize; ++j)
        {
            if ((*returnColumnSizes)[j] == 0)
            {
                --split;
                if (!split)
                {
                    (*returnColumnSizes)[j] = 2;
                    arrays[j] = malloc(sizeof(int) * 2);
                    arrays[j][0] = people[i][0];
                     arrays[j][1] = people[i][1];
                      break;
                }
            }
        }
    }
  *returnSize = peopleSize;
    return arrays;
  }
```
<!-- tabs:end -->

# 四， 总结

总结：<font color='red'>当前要插入身高数小的数已经插入进入了， 而比它大身高数没有插入进入呢！！！ ， </font><font color='blue'>所以在当前这个数前面有几个数就空出几个位置，放比他的身高数大数</font>

[源码地址:https://github.com/chensongpoixs/cleet_code](https://github.com/chensongpoixs/cleet_code)