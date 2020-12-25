/***********************************************************************************************
	created: 		2020-11-18

	author:			chensong

	purpose:		1535. 找出数组游戏的赢家
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它??
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服??
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界??
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心??
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心??
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀??
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边??
我叫他本心猎手。他可能是和宇宙同在的级??但是我并不害怕，我仔细回忆自己平淡的一??寻找本心猎手的痕迹??
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来??
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来??
************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cListNode
{
    int value ;
    int sum ;
    struct cListNode * next;
}cListNode;

struct cListNode * add_win(struct cListNode*head, int value)
{
    if (!head)
    {
        return NULL;
    }
    struct cListNode * cur_list = head->next;
    struct cListNode * pre_list = head;
    while(cur_list)
    {
        if (cur_list->value > value)
        {
            struct cListNode * new_list_ptr = malloc(sizeof(struct cListNode ));
            new_list_ptr->value = value;
            new_list_ptr->sum = 1;
            new_list_ptr->next = cur_list;
            pre_list->next = new_list_ptr;
            return new_list_ptr;
        }
        else if (cur_list->value < value)
        {
            pre_list = cur_list;
            cur_list = cur_list->next;
        }
        else
        {
            ++cur_list->sum;
            return  cur_list;
        }
    }
    if (!cur_list)
    {
        struct cListNode * new_list_ptr = malloc(sizeof(struct cListNode ));
        new_list_ptr->value = value;
        new_list_ptr->sum = 1;
        new_list_ptr->next = NULL;
        pre_list->next = new_list_ptr;
        return new_list_ptr;
    }
    return cur_list;
}


struct entry
{
    unsigned long value ;
    unsigned long sum ;
    struct entry * next;
} entry;

struct hashmap
{
    struct entry ** table;//哈希表
    unsigned long   size; //哈希表的大小
    unsigned long   mask; //哈希因子
    unsigned long   used; //使用个数
} hashmap;

unsigned long get_hash(struct hashmap* map_ptr, unsigned long value)
{
    if (!map_ptr)
    {
        return 0;
    }
    return value %map_ptr->mask;
}

void resetsize(struct hashmap* map_ptr)
{
    if (!map_ptr)
    {
        return;
    }
    if (map_ptr->used >= map_ptr->size)
    {
        int size =  map_ptr->size;
        map_ptr->size = size * 2;
        map_ptr->mask = map_ptr->size -1;
        struct entry ** new_table_ptr = malloc(sizeof(struct entry*));
        for (int i = 0; i < size; ++i)
        {
            struct entry * cur_entry = map_ptr->table[i];

            while (cur_entry)
            {
                struct entry * next_entry = cur_entry->next;
                unsigned long hash = get_hash(map_ptr, cur_entry->value);
                //插入头结点上
                struct entry* new_entry_ptr = new_table_ptr[hash];
                if (new_table_ptr)
                {
                    cur_entry->next = new_entry_ptr;

                }
                new_table_ptr[hash] = next_entry;
            }
        }
        free(map_ptr->table);
        map_ptr->table = new_table_ptr;

    }
}

struct entry* insert_value(struct hashmap* map_ptr, unsigned long value)
{
    if (!map_ptr)
    {
        return NULL;
    }
    //是否需要扩容
    resetsize(map_ptr);
    unsigned long hash = get_hash(map_ptr, value);

    struct entry * cur_entry = map_ptr->table[hash];
    while (cur_entry)
    {
        if (cur_entry->value == value)
        {
            ++cur_entry->sum;
            return cur_entry;
        }
        cur_entry = cur_entry->next;
    }
    if (!cur_entry)
    {
        struct entry * new_entry_ptr = malloc(sizeof(struct entry));
        new_entry_ptr->value = value;
        new_entry_ptr->sum = 1;
        ++map_ptr->used;
        new_entry_ptr->next = map_ptr->table[hash];
        map_ptr->table[hash] = new_entry_ptr;
        return new_entry_ptr;
    }
    return NULL;

}


int getWinner(int* arr, int arrSize, int k)
{
    struct hashmap * map_ptr = malloc(sizeof(struct hashmap));
    map_ptr->table  = malloc(sizeof(struct entry*)*arrSize);
    for (int i = 0; i < arrSize; ++i)
    {
        map_ptr->table[i] = NULL;
    }
    map_ptr->size = arrSize;
    map_ptr->used = 0;
    map_ptr->mask = arrSize -1;
    unsigned long  cur_index = 0;
    unsigned long next_index = 1;
    int index = 0;
    while (1)
    {
        if (arr[cur_index]< arr[next_index % arrSize])
        {
            cur_index = next_index % arrSize;
            next_index = cur_index;
        }
        ++next_index;
        ++index;
        struct entry * cur_entry = insert_value(map_ptr, arr[cur_index]);
        //只需要遍历一次数组就可以找出玩家了
        if (cur_entry && (index > arrSize ||cur_entry->sum >= k))
        {
            return arr[cur_index];
        }
    }

    return 0;
}



int main(int argc, char *argv[])
{
//    输入
//    [2,1,3,5,4,6,7]
//    100000000000
//
     int arrays[] = {2,1,3,5,4,6,7};
     printf(" %d\n", getWinner(&arrays[0], sizeof(arrays)/ sizeof(int), 1000000));
    return EXIT_SUCCESS;
}