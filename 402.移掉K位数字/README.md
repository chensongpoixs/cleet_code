@[TOC](文章目录)


# 一， 移掉K位数字


给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:
num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :
输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。

示例 2 :
输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

示例 3 :
输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

通过次数32,819提交次数106,736


# 二， 解题思路

这个题目可以理解成<font color='red'>从一个数中删除一个数字使得变的最小</font>

## 1， 分析删除一个数字最大会影响到几位数字

下面我们来看一幅图

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201115193022882.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)


由上面的图我们发现删除一个数最多影响4个数字



## 2， 对已经删除的数和已经没有数字('0')处理

1. 对应已经删除的数我们可以使用小于‘0’字符表示 <font color='red'> $'0'-1$ </font>
2. 还有一个特殊情况因为删除第一数字第二位是‘0’时要修改<font color='red'> $'0'-1$ </font>已经删除的情况,方便最后删除操作

最大最后删除这些不需要<font color='red'> $'0'-1$ </font>字符就可以了


# 三， 解题程序


```


/**
*解题思路 去除k个数使 最小
* 在sum字符串中比较前2k个字符就可以啦
**/
char * removeKdigits(char * num, int k) {

	if (num == NULL)
	{
		return num;
	}
	int sum_length = 0;
	char * p = num;
	while (*p != '\0')
	{
		++sum_length;
		++p;
	}
	if (sum_length <= 1)
	{
		if (k <= 0)
		{
			return num;
		}
		return "0";
	}

	int add_length = 0;
	for (int i = 0; i < k; ++i)
	{

		p = num;
		add_length = 0;
		if (num[0] == ('0' - 1))
		{
			while (*++p != '\0' && (*p == '0' || *p == ('0' - 1)))
			{
				++add_length;
				*p = '0' - 1;
			}
		}

		// 最大数的下标  
		int two = 0;
		int max_index = add_length;
		//这里为什么第二个数要小与5呢
		// 是因为 在去除1个字符会影响最高位4个响应
		// 例如: 
		//   例1:     112   中去除1位 ==> 11   影响3位
		//   例2:     1124  中去除1位 ==> 112  影响4位
		//   例3:     11245 中去除1位 ==> 1125 影响4位---> 只要处理4位就可以了
		for (int j = add_length; two < 5 && j < sum_length; ++j)
		{

			if (num[j] == '0' - 1)
			{
				continue;
			}
			if (i == 0 && j == 0 && (j + 1) < sum_length && num[j + 1] == '0')
			{
				break;
			}
			++two;

			//两种情况
		// 1. 第二位是 '0'情况的处理
		// 2. 第二位上不是'0' 而第三位是 '0' -1情况
			while (((j + 1) < sum_length && (num[j + 1] == ('0' - 1) && num[j] == '0')))
			{
				++j;
			}

			if (num[j] >= num[max_index])
			{
				max_index = j;
			}
			else //说明当前值太小了 可以退出了啊啊
			{
				break;
			}
		}
		num[max_index] = '0' - 1;//记录已经被删除了
		
	}
	p = num;
	if (num[0] == ('0' - 1))
	{
		while (*++p != '\0' && (*p == '0' || *p == ('0' - 1)))
		{

			*p = '0' - 1;
		}
	}
	printf("[num = %s]\n", num);
	int cur_retnum_index = 0;
	for (int i = 0; i < sum_length; ++i)
	{
		if (num[i] != ('0' - 1))
		{
			if (cur_retnum_index != 0 || num[i] != '0')
			{
				num[cur_retnum_index++] = num[i];

			}

		}

	}

	//说明都删除了哈哈 所以要添加'0'
	if (cur_retnum_index == 0)
	{
		num[cur_retnum_index++] = '0';
	}
	num[cur_retnum_index] = '\0';
	return num;
}



```



# 四， 总结

本题考察是数学常识问题：<font color='red'>一个数中删除一个数字会影响到几位的问题 最多会影响到4位的</font>





 
 
 
 
 
 