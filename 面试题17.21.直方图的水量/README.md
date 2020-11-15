### 一， 面试题 17.21. 直方图的水量

给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢 Marcos 贡献此图。

```
示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

```


通过次数5,639提交次数9,120


给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201114183225561.png#pic_center)


上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢 Marcos 贡献此图。

示例:

```
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

```

通过次数5,639提交次数9,120



### 二， 解题思路

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201114190816792.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)
对上矩阵的每个高度进行扫描计算面积 ， 就得到每个层高度的面积 ，再相加每一层的面积得到总的面积。

#### 1， 高度就需要排序 去重

使用使用有序链表，

去重在有序链表中重复的高度我就不添加链表中了

插入有序链表时的三种情况 （从小到大的顺序）
1. 当前节点的数大于该值直接插入到当前节点前面
2. 当前节点的值小于 要插入的值就需要查找下一个节点的数进行比较
3. 说明当前节点的值和要比较的值相等就不要插入的了  去重的


```
typedef  struct cListNode {
	int value;
	struct cListNode* next;
}cListNode;

// 有序链表是从小到大的顺序
void insert_value(struct cListNode * list_ptr, int value)
{
	if (!list_ptr)
	{
		return;
	}
	struct cListNode * cur_list_ptr = list_ptr->next;
	struct cListNode * pre_list_ptr = list_ptr;
	while (cur_list_ptr)
	{
		//当前节点的数大于该值直接插入到当前节点前面
		if (cur_list_ptr->value > value)
		{
			// insert
			struct cListNode  * new_list_ptr = malloc(sizeof(struct cListNode));
			new_list_ptr->value = value;
			new_list_ptr->next = NULL;
			pre_list_ptr->next = new_list_ptr;
			new_list_ptr->next = cur_list_ptr;
			return;
		}
		else if (cur_list_ptr->value < value)
		{  // 当前节点的值小于 要插入的值就需要查找下一个节点的数进行比较
			pre_list_ptr = cur_list_ptr;
			cur_list_ptr = cur_list_ptr->next;
		}
		else
		{ //说明当前节点的值和要比较的值相等就不要插入的了  去重的
			return;
		}


	}
	if (!cur_list_ptr)
	{
		struct  cListNode * new_list_ptr = (struct cListNode*)malloc(sizeof(struct cListNode));
		new_list_ptr->value = value;
		new_list_ptr->next = NULL;
		pre_list_ptr->next = new_list_ptr;
	}
}
```

#### 2， 进行每一个层面积计算




```

/**
*  计算出直方图的高度有序列表然后 在根据高度 一层计算出面积 加起来就可以的 但是这个不是最好方法 要哭了 _^_^_
*/
int trap(int* height, int heightSize)
{
	if (height == NULL || heightSize <= 0)
	{
		return 0;
	}
	int big_height = 0;
	struct  cListNode * list_ptr = (struct cListNode*)malloc(sizeof(struct cListNode));
	list_ptr->next = NULL;
	for (int i = 0; i < heightSize; ++i)
	{
		insert_value(list_ptr, height[i]);
	}
	//O(n^2)
	//面积
	int area_size = 0;
	int pre_height = 0; //上一个高度
	for (struct cListNode * cur_list_ptr = list_ptr->next; cur_list_ptr != NULL; cur_list_ptr = cur_list_ptr->next)
	{
		int left = -1;
		if (!cur_list_ptr)
		{
			return area_size;
		}
		for (int j = 0; j < heightSize; )
		{
			// 一行的数据中的面积
			// left , right 
			if ((height[j] - cur_list_ptr->value) >= 0 && left < 0)
			{
				left = ++j;
			}
			else if ((height[j] - cur_list_ptr->value) >= 0 && left >= 0)
			{
				area_size += ((j - left) * (cur_list_ptr->value - pre_height));
				//2. 下一个left的位置定位  高度大于当前的高度时偏移下标++j
				while ((j + 1) < heightSize && height[j + 1] >= cur_list_ptr->value)
				{
					++j;
				}
				left = ++j;
			}
			else
			{
				++j;
			}

		}
		pre_height = cur_list_ptr->value;
		//++i;
	}
	return area_size;
}
```


#### 3， 分析时间复杂度

由上面的分析可以有n个数据  高度有多少数据（去重了有h个）就需要扫描h次数据，所以时间复杂度是非常高的 是<font color='red'>$O($n*h$)$</font>

有没有方法把上面的时间复杂度降低呢！！！！

降线性呢比如<font color='red'>$O(n)$</font>呢

正在学习中！！！！

### 三，总结

1. 计算有序问题基本都要需要排序