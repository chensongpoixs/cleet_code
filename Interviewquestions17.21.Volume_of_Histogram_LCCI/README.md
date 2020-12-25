### һ�� ������ 17.21. ֱ��ͼ��ˮ��

����һ��ֱ��ͼ(Ҳ����״ͼ)���������˴�����ԴԴ���ϵص�ˮ�����ֱ��ͼ�ܴ����ˮ��?ֱ��ͼ�Ŀ��Ϊ 1��



������������ [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ��ֱ��ͼ������������£����Խ� 6 ����λ��ˮ����ɫ���ֱ�ʾˮ���� ��л Marcos ���״�ͼ��

```
ʾ��:

����: [0,1,0,2,1,0,1,3,2,1,2,1]
���: 6

```


ͨ������5,639�ύ����9,120


����һ��ֱ��ͼ(Ҳ����״ͼ)���������˴�����ԴԴ���ϵص�ˮ�����ֱ��ͼ�ܴ����ˮ��?ֱ��ͼ�Ŀ��Ϊ 1��

![���������ͼƬ����](https://img-blog.csdnimg.cn/20201114183225561.png#pic_center)


������������ [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ��ֱ��ͼ������������£����Խ� 6 ����λ��ˮ����ɫ���ֱ�ʾˮ���� ��л Marcos ���״�ͼ��

ʾ��:

```
����: [0,1,0,2,1,0,1,3,2,1,2,1]
���: 6

```

ͨ������5,639�ύ����9,120



### ���� ����˼·

![���������ͼƬ����](https://img-blog.csdnimg.cn/20201114190816792.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)
���Ͼ����ÿ���߶Ƚ���ɨ�������� �� �͵õ�ÿ����߶ȵ���� �������ÿһ�������õ��ܵ������

#### 1�� �߶Ⱦ���Ҫ���� ȥ��

ʹ��ʹ����������

ȥ���������������ظ��ĸ߶��ҾͲ������������

������������ʱ��������� ����С�����˳��
1. ��ǰ�ڵ�������ڸ�ֱֵ�Ӳ��뵽��ǰ�ڵ�ǰ��
2. ��ǰ�ڵ��ֵС�� Ҫ�����ֵ����Ҫ������һ���ڵ�������бȽ�
3. ˵����ǰ�ڵ��ֵ��Ҫ�Ƚϵ�ֵ��ȾͲ�Ҫ�������  ȥ�ص�


```
typedef  struct cListNode {
	int value;
	struct cListNode* next;
}cListNode;

// ���������Ǵ�С�����˳��
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
		//��ǰ�ڵ�������ڸ�ֱֵ�Ӳ��뵽��ǰ�ڵ�ǰ��
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
		{  // ��ǰ�ڵ��ֵС�� Ҫ�����ֵ����Ҫ������һ���ڵ�������бȽ�
			pre_list_ptr = cur_list_ptr;
			cur_list_ptr = cur_list_ptr->next;
		}
		else
		{ //˵����ǰ�ڵ��ֵ��Ҫ�Ƚϵ�ֵ��ȾͲ�Ҫ�������  ȥ�ص�
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

#### 2�� ����ÿһ�����������




```

/**
*  �����ֱ��ͼ�ĸ߶������б�Ȼ�� �ڸ��ݸ߶� һ��������� �������Ϳ��Ե� �������������÷��� Ҫ���� _^_^_
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
	//���
	int area_size = 0;
	int pre_height = 0; //��һ���߶�
	for (struct cListNode * cur_list_ptr = list_ptr->next; cur_list_ptr != NULL; cur_list_ptr = cur_list_ptr->next)
	{
		int left = -1;
		if (!cur_list_ptr)
		{
			return area_size;
		}
		for (int j = 0; j < heightSize; )
		{
			// һ�е������е����
			// left , right 
			if ((height[j] - cur_list_ptr->value) >= 0 && left < 0)
			{
				left = ++j;
			}
			else if ((height[j] - cur_list_ptr->value) >= 0 && left >= 0)
			{
				area_size += ((j - left) * (cur_list_ptr->value - pre_height));
				//2. ��һ��left��λ�ö�λ  �߶ȴ��ڵ�ǰ�ĸ߶�ʱƫ���±�++j
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


#### 3�� ����ʱ�临�Ӷ�

������ķ���������n������  �߶��ж������ݣ�ȥ������h��������Ҫɨ��h�����ݣ�����ʱ�临�Ӷ��Ƿǳ��ߵ� ��<font color='red'>$O($n*h$)$</font>

��û�з����������ʱ�临�ӶȽ����أ�������

�������ر���<font color='red'>$O(n)$</font>��

����ѧϰ�У�������

### �����ܽ�

1. �����������������Ҫ��Ҫ����