# 5642. ��ͼ���֮��ϣO(1)

<font color=#999AAA >��ʾ������д���Ŀ¼�����Զ����ɣ�������ɿɲο��ұߵİ����ĵ�

</font>

@[TOC](5642. ��ͼ���֮��ϣ)


<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# ǰ��


5642. ��ͼ���֮��ϣO(1)

# һ��5642. ��ͼ���֮��ϣO(1)


��� ��ָ ǡ�ð���������ͬ��Ʒ ��һ�ͣ�����ζ�̶�֮�͵��� 2 ���ݡ�

����Դ��� ���� ������Ʒ��һ�ٴ�͡�

����һ���������� deliciousness ������ deliciousness[i] �ǵ� i?????????????? ����Ʒ����ζ�̶ȣ�����������������еĲ�Ʒ�����Ĳ�ͬ ��� �������������Ҫ�� 109 + 7 ȡ�ࡣ

ע�⣬ֻҪ��Ʒ�±겻ͬ���Ϳ�����Ϊ�ǲ�ͬ�Ĳ�Ʒ���������ǵ���ζ�̶���ͬ��

 

ʾ�� 1��

���룺deliciousness = [1,3,5,7,9]
�����4
���ͣ���͵���ζ�̶����Ϊ (1,3) ��(1,7) ��(3,5) �� (7,9) ��
���Ǹ��Ե���ζ�̶�֮�ͷֱ�Ϊ 4 ��8 ��8 �� 16 ������ 2 ���ݡ�
ʾ�� 2��

���룺deliciousness = [1,1,1,3,3,3,7]
�����15
���ͣ���͵���ζ�̶����Ϊ 3 �� (1,1) ��9 �� (1,3) ���� 3 �� (1,7) ��
 

��ʾ��

1 <= deliciousness.length <= 105
0 <= deliciousness[i] <= 220
ͨ������2,097�ύ����11,846



# ���� ����


## 1���ᳬʱ��Ŷ 
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
                    count += ((map_ptr->table[i].count-1) * map_ptr->table[i].count) /2; //�Ȳ�����
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

## 2������Ŀ��2���ݼ���
### �٣� ���Ϊʲô��22������Ϊ$2^{21}$�����ֵ

![���������ͼƬ����](https://img-blog.csdnimg.cn/20210103195118760.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70#pic_center)



### �ڣ����磺 1��ʲô�������2����

![���������ͼƬ����](https://img-blog.csdnimg.cn/20210103200053542.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1BvaXN4,size_16,color_FFFFFF,t_70)


<font color='red'>�ǿ��԰���Щ���ŵ���ϣ���в�ѯ��ʱ�临�ӶȾ���$O(1)$</font>



```c
int countPairs(int* deliciousness, int deliciousnessSize)
{
        const int M = 1e9 + 7;
        int hash[3000000]={0}; //2������ �Ĳ�ౣ���ϣ��
        long long ans = 0;
        for(int i = 0;i < deliciousnessSize; ++i)
        {
            //�ոպ���2�ı���
            ans += hash[deliciousness[i]];
            //���� 2���ݵľ���ͳ�Ƹ��� --�� ���Ϊʲô��22������Ϊ2^21�����ֵ
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


ʱ�临�Ӷ�$O(21*N)$
�ռ临�Ӷ�$O(3000000)$

# �ܽ�
