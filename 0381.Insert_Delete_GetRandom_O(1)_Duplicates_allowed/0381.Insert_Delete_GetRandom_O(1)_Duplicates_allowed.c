/***********************************************************************************************
	created: 		2020-11-24

	author:			chensong

	purpose:		381. O(1) 时间插入、删除和获取随机元素 - 允许重复
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它。
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服。
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界。
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心。
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心。
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀。
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边。
我叫他本心猎手。他可能是和宇宙同在的级别 但是我并不害怕，我仔细回忆自己平淡的一生 寻找本心猎手的痕迹。
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来。
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来。
************************************************************************************************/

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0


typedef struct entry
{
    unsigned long long value;
    unsigned long long count;//个数
	struct entry * next;
}entry;

typedef struct {
    entry** table;// 数组指针
    unsigned long long   size; //hash大小
    unsigned long long   mask; //哈希因子
    unsigned long long   used; 
    int *  arrays ; // 动态数组 查询时的时间复杂度O(N)
    unsigned long long arrays_size; //动态数组总有数据的个数
} RandomizedCollection;

#define hash_init_size  5

unsigned long long get_hash(RandomizedCollection * random_ptr, int value)
{
    return value %random_ptr->mask;
}

//动态扩容
void reset_size(RandomizedCollection * random_ptr)
{
    random_ptr->size = random_ptr->size *2;
    random_ptr->mask = random_ptr->size - 1;
    //alloc 空间
    entry ** new_table_ptr = malloc(sizeof(struct entry *)*random_ptr->size);
    for (unsigned long long i = 0; i < random_ptr->size; ++i)
    {
        new_table_ptr[i] = NULL;
    }
    random_ptr->arrays = realloc(random_ptr->arrays, sizeof(int) * random_ptr->size);
    for (unsigned long long i = 0; i < random_ptr->size/2; ++i)
    {
        if (random_ptr->table[i])
        {
            entry * cur_entry_ptr = random_ptr->table[i];
            while(cur_entry_ptr)
            {
                entry * next_entry_ptr = cur_entry_ptr->next;
                unsigned long long hash = get_hash(random_ptr, cur_entry_ptr->value);

                entry * pre_new_entry_ptr = NULL;
                entry * new_entry_ptr = new_table_ptr[hash];
                while (new_entry_ptr)
                {
                    if (new_entry_ptr->value > cur_entry_ptr->value)
                    {
                        break;
                    }
                    else if (new_entry_ptr->value < cur_entry_ptr->value)
                    {
                        pre_new_entry_ptr = new_entry_ptr;
                        new_entry_ptr = new_entry_ptr->next;

                    }
                    else 
                    {
                        // printf("error reset size hash table  \n");
                    }
                }


                if (pre_new_entry_ptr &&new_entry_ptr)
                {
                    pre_new_entry_ptr->next = cur_entry_ptr;
                    cur_entry_ptr->next = new_entry_ptr;
                }
                else if (pre_new_entry_ptr && !new_entry_ptr)//插入末尾
                {
                    pre_new_entry_ptr->next = cur_entry_ptr;
                    cur_entry_ptr->next = new_entry_ptr;
                }
                else if (!pre_new_entry_ptr && new_entry_ptr)//插入头部
                {
                     cur_entry_ptr->next = new_entry_ptr;
                     new_table_ptr[hash] = cur_entry_ptr;
                }
                else if (!pre_new_entry_ptr &&  !new_entry_ptr) //该表格没有数据
                {
                     new_table_ptr[hash] = cur_entry_ptr;
                     cur_entry_ptr->next = NULL;
                }
                 cur_entry_ptr = next_entry_ptr;
            }
             
        }
       
    }
    if (random_ptr->table)
    {
        free(random_ptr->table);
        random_ptr->table = NULL;
    }
    random_ptr->table = new_table_ptr;

}

/** Initialize your data structure here. */
RandomizedCollection* randomizedCollectionCreate() 
{
    RandomizedCollection * random_ptr = malloc(sizeof(*random_ptr));
    random_ptr->size = hash_init_size;
    random_ptr->mask = hash_init_size -1;
    random_ptr->used = 0;
    random_ptr->arrays_size = 0;
    random_ptr->table = malloc(sizeof(struct entry*)*hash_init_size);
    for (unsigned long long i = 0; i < hash_init_size; ++i)
    {
        random_ptr->table[i] = NULL;
    }
    random_ptr->arrays = malloc(sizeof(int) * hash_init_size);
    memset(random_ptr->arrays, 0, sizeof(int) * hash_init_size);

    return random_ptr;
}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool randomizedCollectionInsert(RandomizedCollection* obj, int val) 
{
    if (!obj)
    {
        return false;
    }
    if (obj->used>= obj->size)
    {
        reset_size(obj);
    }
    unsigned long long hash = get_hash(obj,val);
   
    obj->arrays[obj->arrays_size++] = val;
    ++obj->used;
    if (obj->table[hash])
    {
        entry * pre_new_entry_ptr = NULL;
        entry * cur_entry_ptr = obj->table[hash];
        while (cur_entry_ptr)
        {
            if (cur_entry_ptr->value >val)
            {
                break;
            }
            else if (cur_entry_ptr->value < val)
            {
                pre_new_entry_ptr = cur_entry_ptr;
                cur_entry_ptr = pre_new_entry_ptr->next;
            }
            else if(cur_entry_ptr->value == val)
            {
                ++cur_entry_ptr->count;
                return false;
            }
        }
        entry * new_entry_ptr = malloc(sizeof(struct entry));
        new_entry_ptr->value = val;
        new_entry_ptr->next = NULL;
        new_entry_ptr->count = 1;
        
        if (pre_new_entry_ptr)
        {
            pre_new_entry_ptr->next = new_entry_ptr;
            new_entry_ptr->next = cur_entry_ptr;
        }
        else if (!pre_new_entry_ptr && cur_entry_ptr)
        {
            new_entry_ptr->next = cur_entry_ptr;
            obj->table[hash] = new_entry_ptr;
        }
        return true;

    }
    else 
    {
         entry * new_entry_ptr = malloc(sizeof(struct entry));
        new_entry_ptr->value = val;
        new_entry_ptr->next = NULL;
        new_entry_ptr->count = 1;
        obj->table[hash] = new_entry_ptr;
    }
    return true;
}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool randomizedCollectionRemove(RandomizedCollection* obj, int val) 
{

    if (!obj)
    {
        return false;
    }
   
    unsigned long long hash = get_hash(obj, val);
    // printf("val = %d, hash = %lu, obj->size = %lu\n", val, hash, obj->size);
    if (obj->table[hash])
    {
        entry * cur_entry_ptr = obj->table[hash];
        entry * pre_entry_ptr = NULL;
        while (cur_entry_ptr)
        {
            entry * next_entry_ptr = cur_entry_ptr->next;
            if (cur_entry_ptr->value == val)
            {
                 --obj->used;
                if (cur_entry_ptr->count < 2)
                {
                    if (!pre_entry_ptr)
                    {
                        obj->table[hash] = next_entry_ptr;
                    }
                    else 
                    {
                        pre_entry_ptr->next = next_entry_ptr;

                    }
                    // printf("value = %d, count = %d\n", cur_entry_ptr->value,  cur_entry_ptr->count);
               
                    free(cur_entry_ptr);
                    cur_entry_ptr = NULL;
                }
                else 
                {
                    //  printf("--value = %d, count = %d\n", cur_entry_ptr->value,  cur_entry_ptr->count);
                    --cur_entry_ptr->count;
                }

                for(int i = 0; i < obj->arrays_size; ++i)
                {
                    if (obj->arrays[i] == val)
                    {
                        obj->arrays[i] = obj->arrays[--obj->arrays_size];
                        break;
                    }
                }
                return true;
            }
            else if(cur_entry_ptr->value < val)
            {
                // printf("cur value = %d, value = %d\n",  cur_entry_ptr->value, val);
            }
            else if (cur_entry_ptr->value > val)
            {
                // printf("remove value = %d\n", val);
                return false;
            }
            // else 
            {
                // printf("remove value = %d\n", val);
            }
            pre_entry_ptr = cur_entry_ptr;
            cur_entry_ptr = next_entry_ptr;
        }
        

    }
   
    return false;
}


/** Get a random element from the collection. */
int randomizedCollectionGetRandom(RandomizedCollection* obj) 
{
    if (!obj||obj->used <1)
    {
        return 0;  
    }
    if (obj->arrays_size<1)
    {
        return -1;
    }
    return obj->arrays[rand() % obj->arrays_size];
}

void randomizedCollectionFree(RandomizedCollection* obj) 
{
    if (!obj)
    {
        return;
    }
    if(obj->arrays)
    {
        free(obj->arrays);
    }
     for (int i = 0; i< obj->size; ++i)
    {
        if (obj->table[i])
        {
           
            entry * cur_entry_ptr = obj->table[i];
            while (cur_entry_ptr)
            {
                entry * next_entry_ptr = cur_entry_ptr->next;
                free(cur_entry_ptr);
                cur_entry_ptr = NULL;
                cur_entry_ptr = next_entry_ptr;
            }
            
        }
    }
    free(obj->table);
    obj->table = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your RandomizedCollection struct will be instantiated and called as such:
 * RandomizedCollection* obj = randomizedCollectionCreate();
 * bool param_1 = randomizedCollectionInsert(obj, val);
 
 * bool param_2 = randomizedCollectionRemove(obj, val);
 
 * int param_3 = randomizedCollectionGetRandom(obj);
 
 * randomizedCollectionFree(obj);
*/



// 1 1
//  2 
 
//  2 1 

// // ["RandomizedCollection","insert","insert","insert","insert","insert",
// "remove","remove","remove",
// "insert","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
// // [[],[1],[1],
// [2],[2],[2]
// ,[1],[1],[2]
// ,[1],[2],

// [],[],[],[],[],[],[],[],[],[]]








/**


**/





int main(int argc, char *argv[])
{
	return 0;
}


