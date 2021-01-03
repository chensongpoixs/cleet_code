# 5642. 大餐计数之哈希O(1)

<font color=#999AAA >提示：文章写完后，目录可以自动生成，如何生成可参考右边的帮助文档

</font>

@[TOC](5642. 大餐计数之哈希)


<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 前言


5642. 大餐计数之哈希O(1)

# 一、5642. 大餐计数之哈希O(1)


大餐 是指 恰好包含两道不同餐品 的一餐，其美味程度之和等于 2 的幂。

你可以搭配 任意 两道餐品做一顿大餐。

给你一个整数数组 deliciousness ，其中 deliciousness[i] 是第 i?????????????? 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 大餐 的数量。结果需要对 109 + 7 取余。

注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。

 

示例 1：

输入：deliciousness = [1,3,5,7,9]
输出：4
解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。
示例 2：

输入：deliciousness = [1,1,1,3,3,3,7]
输出：15
解释：大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。
 

提示：

1 <= deliciousness.length <= 105
0 <= deliciousness[i] <= 220
通过次数2,097提交次数11,846



# 二、 程序


## 1，会超时的哦 
```c
struct arrays
{
    int value;
    int count;
}arrays;

struct hashmap
{
    struct arrays* table;
     long long used;
     long long size;
    
}hashmap;


bool Surplus(long long value)
{
    int count = 0;
    
    while (value>0 && count == 0)
    {
        if (value&1)
        {
            ++count;
        }
        value = value>>1;
    }
    if (value>0)
    {
        return false;
    }
    return count == 1;
}




int countPairs1(int* deliciousness, int deliciousnessSize)
{
    struct hashmap *map_ptr = malloc(sizeof(struct hashmap));
    map_ptr->size = deliciousnessSize;
    map_ptr->used = 0;
    
    map_ptr->table = malloc(sizeof(struct arrays) * deliciousnessSize);
   
    
    for (int i = 0; i < deliciousnessSize; ++i)
    {
        map_ptr->table[i].count = 0;
        bool find = false;
        int index = -1;
        for (int j = 0; j < map_ptr->used; ++j)
        {
            if (map_ptr->table[j].value == deliciousness[i])
            {
                ++map_ptr->table[j].count;
                find = true;
                break;
            }
            else if (map_ptr->table[j].value> deliciousness[i])
            {
                index = j;
                ++map_ptr->used;
                for (int w = map_ptr->used ; w >j; --w)
                {
                    map_ptr->table[w].value = map_ptr->table[w-1].value;
                    map_ptr->table[w].count = map_ptr->table[w-1].count;
                }
                
                    
                break;
            }
        }
        if (!find)
        {
            
            if (index != -1)
            {
                map_ptr->table[index].count = 1;
                map_ptr->table[index].value = deliciousness[i];
            }
            else 
            {
                map_ptr->table[map_ptr->used].count = 1;
                map_ptr->table[map_ptr->used].value = deliciousness[i];
                ++map_ptr->used;
            }
            
        }
    }
    int count = 0;
    for (int i = 0;i < map_ptr->used; ++i)
    {
        for (int j = i; j <  map_ptr->used; ++j)
        {
            if (i !=j)
            {
                
                if (Surplus(map_ptr->table[i].value + map_ptr->table[j].value))
                {
                    count += map_ptr->table[i].count * map_ptr->table[j].count;
                } 
            }
            else if (map_ptr->table[i].count>1)
            {
                if (Surplus(map_ptr->table[i].value + map_ptr->table[j].value))
                {
                    count += ((map_ptr->table[i].count-1) * map_ptr->table[i].count) /2; //等差数列
                } 
            }       
        }
    }
    if(map_ptr)
    {
		if(map_ptr->table)
		{
			free(map_ptr->table);
		}
		free(map_ptr);
	}
    long M = 1000000007;
    return count%M;
}
```

## 2，利用目标2的幂技巧
### ①， 这边为什么是22呢是因为$2^{21}$是最大值

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210103195118760.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)



### ②，比如： 1和什么数相加是2的幂

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210103200053542.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70)


<font color='red'>那可以把这些数放到哈希表中查询的时间复杂度就是$O(1)$</font>



```c
int countPairs(int* deliciousness, int deliciousnessSize)
{
        const int M = 1e9 + 7;
        int hash[3000000]={0}; //2的陪数 的差距保存哈希表
        long long ans = 0;
        for(int i = 0;i < deliciousnessSize; ++i)
        {
            //刚刚好是2的倍数
            ans += hash[deliciousness[i]];
            //距离 2的幂的距离统计个数 --》 这边为什么是22呢是因为2^21是最大值
            for(int j = 0; j < 22; j++)
            {
                if(((1<<j)-deliciousness[i])>=0) 
                {
                    hash[(1<<j)-deliciousness[i]]++;
                }
            }
        }
        return ans % M;
}

```


时间复杂度$O(21*N)$
空间复杂度$O(3000000)$

# 总结
