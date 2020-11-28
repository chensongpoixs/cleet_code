/***********************************************************************************************
	created: 		2020-11-28

	author:			chensong

	purpose:		454. 四数相加 II
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


int parition(int *nums, int start, int end)
{
    int value = nums[start];
    int left = start;
    int right = end +1;
    while (1)
    {
        //找到最大的数
        while (nums[++left] < value)
        {
            if (left == end)
            {
                break;
            }
        }
        //找到最小的值
        while (nums[--right] >value)
        {
            if (right == start)
            {
                break;
            }
        }
        if (right<= left)
        {
            break;
        }
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }

    int temp = nums[start];
    nums[start] = nums[right];
    nums[right] = temp;
    return right;
}

void sort(int *nums, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int p = parition(nums, start, end);
    sort(nums, start, p-1);
    sort(nums, p+1, end);
}

void quick_sort(int *nums, int size)
{
    if (nums == NULL || size <= 1)
    {
        return;
    }
    sort(nums, 0, size-1);
}

void show(int* nums, int size)
{
    printf("[");
    for (int i = 0; i < size ; ++i)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", nums[i]);
    }
    printf("]\n");
}

struct entry
{
    int value;
    int count ;
    struct entry * next;
}entry;

struct hashmap
{
    struct entry ** table;
    unsigned long long size;
    unsigned long long mask;
    unsigned long long used;
}hashmap;


unsigned long long get_hash(struct hashmap *map_ptr, unsigned long long key)
{
    return key % map_ptr->mask;
}


void insert(struct hashmap* map_ptr, int value)
{
    if (!map_ptr)
    {
        return;
    }
    unsigned long long hash = get_hash(map_ptr, value);
    ++map_ptr->used;
    // if (map_ptr->table[hash])
    {
        struct entry * cur_entry_ptr = map_ptr->table[hash];
        struct entry * prev_entry_ptr = NULL;
        while (cur_entry_ptr)
        {
            if (cur_entry_ptr->value > value)
            {
                struct entry * new_entry_ptr = malloc(sizeof(struct entry));
                  new_entry_ptr->count = 1;
                    new_entry_ptr->value = value;
                    new_entry_ptr->next = NULL;
                if (!prev_entry_ptr)
                {
                    prev_entry_ptr = new_entry_ptr;
                    prev_entry_ptr->next = cur_entry_ptr;

                    // prev_entry_ptr = malloc(sizeof(struct entry));
                  
                    map_ptr->table[hash] = prev_entry_ptr;
                }
                else 
                {
                  prev_entry_ptr->next = new_entry_ptr;
                  new_entry_ptr->next = cur_entry_ptr;
                }
                return;
            }
            else if (cur_entry_ptr->value < value)
            {
                prev_entry_ptr = cur_entry_ptr;
                cur_entry_ptr = prev_entry_ptr->next;
            }
            else if (cur_entry_ptr->value == value)
            {
                ++cur_entry_ptr->count;
                return;

            }
            else 
            {
                printf("error{}\n");
            }
        }
 struct entry* new_entry_ptr = malloc(sizeof(struct entry));
                  new_entry_ptr->count = 1;
                    new_entry_ptr->value = value;
                    new_entry_ptr->next = NULL;
        if (!cur_entry_ptr && !prev_entry_ptr)
        {

            map_ptr->table[hash] = new_entry_ptr;
                    
        }
        else if (!cur_entry_ptr && prev_entry_ptr)
        {
            prev_entry_ptr->next = new_entry_ptr;
        }
        else 
        {
            printf("error map[]\n");
        }
    }
}

struct entry * find(struct hashmap * map_ptr, int value)
{
    if (!map_ptr)
    {
        return NULL;
    }
      unsigned long long hash = get_hash(map_ptr, value);
        struct entry * cur_entry_ptr = map_ptr->table[hash];
        while (cur_entry_ptr)
        {
            if (cur_entry_ptr->value > value)
            {

               return NULL;
            }
            else if (cur_entry_ptr->value < value)
            {
                cur_entry_ptr = cur_entry_ptr->next;
            }
            else if (cur_entry_ptr->value == value)
            {
                return cur_entry_ptr;

            }
            else 
            {
                printf("error{}\n");
            }
        }
        return NULL;
}


void destroy(struct hashmap * map_ptr)
{
    if (!map_ptr)
    {
        return;
    }
    for (int i = 0; i < map_ptr->size; ++i)
    {
        if (map_ptr->table[i])
        {
            struct entry * cur_entry_ptr = map_ptr->table[i];
            while(cur_entry_ptr)
            {
                struct entry* prev_entry_ptr = cur_entry_ptr->next;
                free(cur_entry_ptr);
                cur_entry_ptr = NULL;
                cur_entry_ptr = prev_entry_ptr;
            }
        }
    }
    free(map_ptr);
    map_ptr = NULL;
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
    // quick_sort(A, ASize);
    // quick_sort(B, BSize);
    // quick_sort(C, CSize);
    // quick_sort(D, DSize);
    // show(A, ASize);
    // show(B, BSize);
    // show(C, CSize);
    // show(D, DSize);
    int num = 0;


    struct hashmap * mapab_ptr = malloc(sizeof(struct hashmap));
    mapab_ptr->size = ASize * BSize;
    mapab_ptr->used = 0;
    mapab_ptr->mask = mapab_ptr->size ==1?1:mapab_ptr->size -1;
    mapab_ptr->table = malloc(sizeof(struct entry*) * mapab_ptr->size);
    for (int i = 0; i < mapab_ptr->size; ++i)
    {
        mapab_ptr->table[i] = NULL;
    }
    for (int i = 0; i  < ASize; ++i)
    {
        for (int j = 0; j < BSize; ++j)
        {
            insert(mapab_ptr, A[i]+B[j]);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    struct hashmap * mapcd_ptr = malloc(sizeof(struct hashmap));
    mapcd_ptr->size = CSize * DSize;
    mapcd_ptr->used = 0;
    mapcd_ptr->mask = mapcd_ptr->size == 1?1:mapcd_ptr->size -1;
    mapcd_ptr->table = malloc(sizeof(struct entry*) * mapcd_ptr->size);
    for (int i = 0; i < mapcd_ptr->size; ++i)
    {
        mapcd_ptr->table[i] = NULL;
    }
    for (int i = 0; i  < CSize; ++i)
    {
        for (int j = 0; j < DSize; ++j)
        {
            insert(mapcd_ptr, C[i]+D[j]);
        }
    }

    for (int i = 0; i < mapab_ptr->size; ++i)
    {
        if (mapab_ptr->table[i])
        {
            struct entry * cur_entry_ptr = mapab_ptr->table[i];
            while(cur_entry_ptr)
            {
                int diff = 0 - cur_entry_ptr->value;
                struct entry * find_entry_ptr = find(mapcd_ptr, diff);
                if (find_entry_ptr)
                {
                    num += cur_entry_ptr->count * find_entry_ptr->count;
                }
                cur_entry_ptr = cur_entry_ptr->next;
            }
        }
    }


   destroy(mapab_ptr);
   destroy(mapcd_ptr);

    return num;
}

void show_arrays(int * arrays, int size)
{
	printf("[");
	for (int i = 0; i < size; ++i)
	{
		if (i != 0)
		{
			printf(", ");
		}
		printf("%d", arrays[i]);
	}
	printf("]\n");
}

int main(int argc, char *argv[])
{
	int A[] = { 9, 4, -31, -24, -6, -6, -18, -25, 2, 1, -20, -17, -18, 5, -11, -26, -31, -23, 2, 9, -28, -15, 10, -21, -12, -17, -13, -29, 3, -26, -3, -15, -13, -31, -27, -30, 5, -27, -32, 1, -26, -30, -10, 8, -21, -28, -32, -12, -4, 5, -10, -2, 0, -1, -3, -17, -15, -1, 3, -4, -30, 6, 2, 4, -27, -3, -15, -30, -20, -18, -16, -6, -16, -2, -31, -22, -20, -14, -22, 5, -4, 7, -16, -8, -16, -3, 3, -9, -3, -4, 0, -27, -10, -12, -3, -8, -7, -16, -27, 8 };
	int B[] = { -21, -22, -9, -32, -14, -32, 9, -26, -26, 2, 5, -13, -21, -27, -28, -15, -2, -21, 9, -30, -16, -16, 5, -13, -21, -4, -15, -2, -1, 0, -5, 10, -10, 8, -13, -4, 6, -17, 0, -30, -31, -32, 2, -9, 5, -30, 9, -30, -13, 4, -3, 4, -23, 3, -25, -17, 2, -9, -16, -25, -19, -10, -23, -14, -13, -18, -21, 10, -15, -4, -8, 8, -19, 6, -26, -4, -9, 9, -29, 1, 5, -27, -32, -20, -31, 5, -24, 2, -3, -13, -32, 6, 3, -2, -15, -2, 1, -7, -29, -25 };
	int C[] = { 4, -3, 6, -29, -28, -4, 0, 2, -4, -5, -13, -11, 6, -23, 9, -19, -16, 5, -20, -7, -20, -1, -22, 8, -24, 4, -9, -27, -31, -7, -20, -22, -15, 4, 5, 2, -13, -27, 6, -30, -12, 3, -10, 4, -20, -19, -13, -27, 2, -27, -18, -3, -26, 8, -27, -25, -3, -5, -25, -32, -4, -15, -7, -23, -6, -8, 6, -9, -25, 3, 6, -10, -13, -6, 6, -21, -25, -3, -24, -30, -28, -12, -24, -18, -15, 10, -7, -22, -13, -22, -19, -19, -14, -9, -21, -17, -29, 0, -5, 5 };
	int D[] = { -17, 8, -3, -24, 8, -7, -11, -6, -32, -8, -13, -6, -16, -11, 3, -18, -5, -25, -11, -30, -6, -10, 0, 6, -13, -11, -3, 0, -22, -32, -4, -28, -11, -15, -15, -24, -9, -29, -22, -2, -10, 0, 3, -20, -32, -8, 3, -3, 5, -14, -16, -8, -6, 3, -12, 5, -15, -22, -14, -11, -8, -28, 10, -1, 1, -20, 3, -30, -2, -27, -26, -31, 10, -29, -16, 7, -16, -5, 7, 2, 7, -20, -29, -1, -27, -26, 0, -16, -16, -22, -24, -23, -23, 5, -25, 3, 7, -14, -20, 6 };
	
	printf("A = ");
	show_arrays(&A[0], sizeof(A) / sizeof(int));
	printf("B = ");
	show_arrays(&B[0], sizeof(B) / sizeof(int));
	printf("C = ");
	show_arrays(&C[0], sizeof(C) / sizeof(int));
	printf("D = ");
	show_arrays(&D[0], sizeof(D) / sizeof(int));

	printf("count = %d\n", fourSumCount(&A[0], sizeof(A) / sizeof(int), &B[0], sizeof(B) / sizeof(int), &C[0], sizeof(C) / sizeof(int), &D[0], sizeof(D) / sizeof(int)));

	return 0;

}