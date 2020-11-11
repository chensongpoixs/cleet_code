/***********************************************************************************************
	created: 		2020-11-03

	author:			chensong

	purpose:		1074.元素和为目标值的子矩阵数量
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它�?
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服�?
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界�?
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心�?
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心�?
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀�?
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边�?
我叫他本心猎手。他可能是和宇宙同在的级�?但是我并不害怕，我仔细回忆自己平淡的一�?寻找本心猎手的痕迹�?
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来�?
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来�?
************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 哈希节点
 */
typedef struct table_entry
{
    unsigned long key;
    int value;
    struct table_entry * next;
} table_entry;

/**
 * 哈希表的信息
 */
typedef struct hash
{
    table_entry ** table; //哈希表 指针数组
    unsigned long size; //哈希表的大小
    unsigned long sizemask; //哈希因子
    unsigned long used; //已经使用的哈希表的个数
}hash_map;

#define HASH_INIT_SIZE 128
/**
 * 哈希表初始化
 * @return
 */
hash_map* init_hash()
{
    hash_map *map_ptr = malloc(sizeof( hash_map));
    if (!map_ptr)
    {
        return NULL;
    }
    table_entry ** table_ptr = malloc(sizeof(struct table_entry*) * HASH_INIT_SIZE);
    if (!table_ptr)
    {
        free(map_ptr);
        return NULL;
    }

    for (int i = 0; i < HASH_INIT_SIZE; ++i)
    {
        table_ptr[i] = NULL;
    }

    map_ptr->size = HASH_INIT_SIZE;
    map_ptr->sizemask = HASH_INIT_SIZE -1;
    map_ptr->used = 0;
    map_ptr->table = table_ptr;
    return map_ptr;
}

/**
 * 哈希函数
 * @param map_ptr
 * @param key
 * @return
 */
unsigned long get_key(hash_map * map_ptr, unsigned long key)
{
    if (!map_ptr)
    {
        return 0;
    }
    return key % map_ptr->sizemask;
}

/**
 * hashmap 扩容
 * @param map_ptr
 * @return
 */
hash_map * resize_hash_map(hash_map *map_ptr)
{
    map_ptr->size = map_ptr->size * 2;
    map_ptr->sizemask = map_ptr->size -1;

    table_entry** new_table_ptr = malloc( sizeof(struct table_entry*) * map_ptr->size);
    if (!new_table_ptr)
    {

        return NULL;
    }
    //从新布局hashmap
    for (int i = 0; i < (map_ptr->size/2); ++i)
    {
        table_entry * old_table_ptr  = map_ptr->table[i];
        while (old_table_ptr)
        {
            unsigned long key = get_key(map_ptr, (unsigned long)old_table_ptr->key);

            table_entry * old_next_table_ptr = old_table_ptr->next;


            if (new_table_ptr[key])
            {
                old_table_ptr->next = new_table_ptr[key];

            }
            else
            {
                old_table_ptr->next = NULL;
            }
            new_table_ptr[key] = old_table_ptr;



            old_table_ptr = old_next_table_ptr;
        }
    }
    if (map_ptr->table)
    {
        free(map_ptr->table);
        map_ptr->table = NULL;
    }
    if (new_table_ptr)
    {
        map_ptr->table = new_table_ptr;
    }
    return map_ptr;
}



/**
 * 查询
 * @param map_ptr
 * @param key
 * @return
 */
int get_key_value(hash_map * map_ptr, unsigned long key)
{
    unsigned long hash = get_key(map_ptr, key);
    table_entry *  cur_entry = map_ptr->table[hash];

    while (cur_entry)
    {
        // 判断key是否相等
        if (key == cur_entry->key)
        {
            return (cur_entry->value);
        }
        cur_entry = cur_entry->next;
    }
    return 0;
}

/**
 * 插入
 * @param map_ptr
 * @param key
 * @return
 */
table_entry * insert_entry(hash_map * map_ptr, unsigned long key)
{
    unsigned long hash = get_key(map_ptr, key);
    table_entry *  cur_entry = map_ptr->table[hash];
    while (cur_entry)
    {
        // 判断key是否相等
        if (key == (unsigned long)(cur_entry->key))
        {
            return cur_entry;
        }

        cur_entry = cur_entry->next;
    }
    if (!cur_entry)
    {
        table_entry * entry_ptr = malloc(sizeof(struct table_entry));
        if (!entry_ptr)
        {
            printf("alloc failed \n");
            return NULL;
        }
        entry_ptr->key = key;
        entry_ptr->value = 0;
        entry_ptr->next = NULL;
        if (map_ptr->table[hash])
        {
            entry_ptr->next = map_ptr->table[hash];

        }
        ++map_ptr->used;
        {
            map_ptr->table[hash] = entry_ptr;
        }
    }
    else
    {
        printf("[insert error]\n");
    }

    return map_ptr->table[hash];
}



/**
 * 哈希map插入
 * @param map_ptr
 * @param key
 * @param value
 * @return
 */
table_entry* make_insert(hash_map * map_ptr, unsigned long key, int value)
{

    unsigned long hash = get_key(map_ptr, key);

    table_entry *  cur_entry = map_ptr->table[hash];
    while (cur_entry)
    {
        // 判断key是否相等
        if (key == (unsigned long)(cur_entry->key))
        {
            break;
        }
        cur_entry = cur_entry->next;
    }
    if (!cur_entry)
    {
        //没有找到的处理
        //看需不需要扩容
        if (map_ptr->size <= map_ptr->used)
        {
            hash_map * new_map_ptr = resize_hash_map(map_ptr);
            if (!new_map_ptr)
            {
                printf("[hash_map resize error ]\n");
                return NULL;
            }
        }
        cur_entry = insert_entry(map_ptr, key);
        if (!cur_entry)
        {
            printf("entry alloc failed]\n");
            return NULL;
        }

    }

    // set value
    cur_entry->value = value;
    return cur_entry;
}




void hash_map_destroy(hash_map* map_ptr)
{
    if (!map_ptr)
    {
        return;
    }
    if (!map_ptr->table)
    {
        free(map_ptr);
        map_ptr = NULL;
        return;
    }

    for (int i = 0; i < map_ptr->size; ++i)
    {
        table_entry * entry_ptr = map_ptr->table[i];
        while (entry_ptr) //释放哈希表
        {
            table_entry * next_entry_ptr = entry_ptr->next;
            free(entry_ptr);
            entry_ptr = next_entry_ptr;
        }
    }
    free(map_ptr->table);
    map_ptr->table = NULL;
    free(map_ptr);
    map_ptr = NULL;

}




/**
 * TODO@chensong 2020-11-09  warr 超出时间限制  我也是头大啊啊
 * @param matrix
 * @param matrixSize
 * @param matrixColSize
 * @param target
 * @return
 */
// int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target){

//     int matrix_nums = 0;

//     if (!matrix)
//     {
//         return matrix_nums;
//     }
//     for (int i = 0; i < matrixSize; ++i)
//     {
//         for (int j = 0; j < matrixColSize[i]; ++j)
//         {
//             for (int x = j; x>=0; --x)
//             {
//                 for (int y = i; y>=0; --y)
//                 {
//                     int diff = 0;

//                     for (int yy = y; yy <= i; ++yy)
//                     {
//                         for (int xx = x; xx <= j; ++xx)
//                         {
//                             diff += matrix[yy][xx];
//                         }
//                     }
//                     if (diff == target )
//                     {
//                         ++matrix_nums;
//                     }
//                 }
//             }
//         }
//     }

//     return matrix_nums;
// }



/**
* 有符号问题 hash --> 是错误的了
*/
int numSubmatrixSumTargethash(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int matrix_nums = 0;

    // 把每一行的值累加起来 到当前x的数中
    //比如 j 到 i 之和 就是  =  matrix[y][i] - matrix[y][y-1]
    for (int y = 0; y < matrixSize; ++y)
    {
        for (int x = 1; x < matrixColSize[y]; ++x)
        {
            matrix[y][x] +=matrix[y][x -1]; //
        }
    }
    unsigned long * hash = NULL;

    unsigned long hash_size = 16;

    //  hash_map * hash_map_ptr = NULL;
    //x [x - xx]
    //y [0 - matrixSize]
    int colsize = matrixColSize[0];
    for (int x = 0; x < colsize; ++x)
    {
        for (int xx = x; xx < colsize; ++xx)
        {
            if (!hash)
            {
                hash = malloc(sizeof(unsigned long)* hash_size);
            }
            memset(hash, 0, sizeof(unsigned long)*hash_size);
            hash[0] = 1;
            int sum = 0;
            for (int y = 0; y < matrixSize; ++y)
            {
                if (x>0)
                {
                    sum += matrix[y][xx] - matrix[y][x-1];
                }
                else
                {
                    sum += matrix[y][xx];
                }
                if (((sum - target)>= 0) &&(sum - target) < hash_size)
                {
                    matrix_nums += hash[sum-target];
                }
                if (sum >= hash_size)
                {
                    hash_size *=2;
                    hash = realloc(hash, sizeof(unsigned long) *hash_size);
                }
                ++hash[sum];
            }
        }
    }
    return matrix_nums;
}


/**
 *
 * @param matrix
 * @param matrixSize
 * @param matrixColSize
 * @param target
 * @return
 */
int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int matrix_nums = 0;

    // 把每一行的值累加起来 到当前x的数中
    //比如 j 到 i 之和 就是  =  matrix[y][i] - matrix[y][y-1]
    for (int y = 0; y < matrixSize; ++y)
    {
        for (int x = 1; x < matrixColSize[y]; ++x)
        {
            matrix[y][x] +=matrix[y][x -1]; //
        }
    }
    hash_map * hash_map_ptr = NULL ;
    //x [x - xx]
    //y [0 - matrixSize]
    int colsize = matrixColSize[0];
    for (int x = 0; x < colsize; ++x)
    {
        for (int xx = x; xx < colsize; ++xx)
        {
            hash_map_destroy(hash_map_ptr);
            hash_map_ptr =  init_hash();
            make_insert(hash_map_ptr, 0, 1);

            int sum = 0;
            for (int y = 0; y < matrixSize; ++y)
            {
                if (x>0)
                {
                    sum += matrix[y][xx] - matrix[y][x-1];
                }
                else
                {
                    sum += matrix[y][xx];
                }
                matrix_nums += get_key_value(hash_map_ptr, sum-target);
                //累加前面的数总和 方便矩阵的高度小 计算大小
                /**
                 * 例如:   统一矩阵的高度为 4
                 *   例1: x  到 xx 距离是 4 时的变化
                 *                                           ####
                 *                             ####          ####
                 *                ####         ####          ####
                 *   ####         ####         ####          ####
                 *   上面高度不停变大的
                 *
                 *   例2: x 到 xx的距离是 3 时的变化
                 *
                 *                                           ###
                 *                             ###           ###
                 *               ###           ###           ###
                 *   ###         ###           ###           ###
                 *
                 *
                 *
                 *   例3: x 到 xx的距离是 2 时的变化
                 *
                 *                                        ##
                 *                           ##           ##
                 *              ##           ##           ##
                 *   ##         ##           ##           ##
                 */
                make_insert(hash_map_ptr, sum , get_key_value(hash_map_ptr, sum)+1);
            }
        }
    }
    hash_map_destroy(hash_map_ptr);
    return matrix_nums;
}


//int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target)
//{
//    int matrix_nums = 0;
//
//    // // 把每一行的值累加起来 到当前x的数中
//    // //比如 j 到 i 之和 就是  =  matrix[y][i] - matrix[y][y-1]
//    // for (int y = 0; y < matrixSize; ++j)
//    // {
//    //     for (int x = 1; x < matrixColSize[y]; ++x)
//    //     {
//    //         matrix[y][x] +=matrix[y][x -1]; //
//    //     }
//    // }
//
//    // hash_map * hash_map_ptr = NULL;
//
//    // //x [x - xx]
//    // //y [0 - matrixSize]
//    // for (int x = 0; x < matrixColSize[0]; ++x)
//    // {
//    //     for (int xx = x+1; xx << matrixColSize[0]; ++xx)
//    //     {
//    //         hash_map_destroy(hash_map_ptr);
//    //         hash_map_ptr = init_hash();
//    //         make_insert(hash_map_ptr, 0, 1);
//    //         int sum = 0;
//    //         for (int y = 0; y < matrixSize; ++y)
//    //         {
//    //             if (xx>0)
//    //             {
//    //                 sum += matrix[y][x] - matrix[y][xx-1]
//    //             }
//    //             else
//    //             {
//    //                 sum = matrix[y][xx];
//    //             }
//    //             matrix_nums += get_key(sum - target);
//    //             make_insert(hash_map_ptr, sum, get_key(sum) +1);
//    //         }
//    //     }
//    // }
//    // hash_map_destroy(hash_map_ptr);
//    return matrix_nums;
//}

void test_hash_map()
{
    printf("test hash map \n");
    hash_map * map_ptr = init_hash();
    if (!map_ptr)
    {
        printf("init map failed\n");
        return ;
    }
    else
    {
        printf("init map ok !!!\n");
    }

    for (int i = 0; i < 1000; ++i)
    {
        make_insert(map_ptr, i * 22/*这边乘以22是为了哈希冲突*/, i);
    }

    unsigned long hash_collisions = 0; //哈希表的冲突表的个数
    for (unsigned long j = 0; j < map_ptr->size; ++j)
    {
        if (map_ptr->table[j])
        {
            if (map_ptr->table[j]->next)
            {
                ++hash_collisions;
            }
        }
        printf("j = %lu key = %d\n ", j, get_key_value(map_ptr, j*22));
    }

    printf("hash table size = %lu, use table size = %lu, hash_collisions = %lu\n", map_ptr->size, map_ptr->used, hash_collisions);

    hash_map_destroy(map_ptr);
    printf("hash map destroy ok\n");
}

int main(int argc, char *argv[])
{

//    test_hash_map();

    printf("[[1,-1],[-1,1]]  target = 0\n");

    int ** array = malloc(sizeof(int *) * 4);
    array[0] = malloc(sizeof(int) *2);
    array[0][0] = 1;
    array[0][1] = -1;
    array[1] = malloc(sizeof(int) *2);
    array[1][0] = -1;
    array[1][1] = 1;
    int arraycolsize[2] = {2, 2};

    printf("matrix size = %d\n", numSubmatrixSumTarget(array, 2, arraycolsize, 0));

    return EXIT_SUCCESS;
}
