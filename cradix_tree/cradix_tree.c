/***********************************************************************************************
	created: 		2021-04-04

	author:			chensong

	purpose:		基数树--》 应用场景 ip地址  mask 掩码  ip区域定位
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
#include  <stdlib.h>
#include  <string.h>
#include <assert.h>

typedef unsigned int	uint32;
typedef signed int		int32;

/**
 * 默认地址
 */
#define default_ip "127.0.0.1"

// 基数树 应用场景ip地址映射
struct cradix_tree_node
{
    struct cradix_tree * left;
    struct cradix_tree * right;
    char * value; //实际的ip数据
}cradix_tree;

struct cradix_tree
{
    struct cradix_tree_node * root;
    uint32  size;
};


/**
 * 基数树插入ip的地址映射关系
 * @param tree_ptr
 * @param key
 * @param mask
 * @param value
 * @return
 */
void * cradix_tree_insert(struct cradix_tree * tree_ptr, uint32 key, uint32 mask, void * value)
{
    assert(tree_ptr != NULL);
    if (!tree_ptr)
    {
        return NULL;
    }

    struct cradix_tree_node * cur_node = tree_ptr->root;
    struct cradix_tree_node * next_node = tree_ptr->root;


    //uint32 mask = 0;
    uint32 bit = 0x80000000;
    while (bit & mask)
    {
        //找到合适的位置插入
        if (bit & key)
        {
            next_node = (struct cradix_tree_node *)cur_node->right;
        }
        else
        {
            next_node = (struct cradix_tree_node *)cur_node->left;
        }
        if (!next_node)
        {
            break;
        }
        cur_node = next_node;
        bit >>= 1; //高位
    }

    if (next_node)
    {
        if (cur_node->value)
        {
            cur_node->value = value;
            return next_node;
        }

        cur_node->value = value;
        return cur_node;
    }

    while (bit & mask)
    {
        next_node = malloc(sizeof(struct cradix_tree_node));
        assert(next_node != NULL);

        {
            next_node->left = NULL;
            next_node->right = NULL;
            next_node->value = NULL;
        }
        if (bit & key)
        {
            cur_node->right = (void *)next_node;
        }
        else
        {
            cur_node->left = (void *)next_node;
        }
        bit >>= 1;
        cur_node = next_node;
        next_node = NULL;
    }

    if (cur_node)
    {
        cur_node->value = value;
    }
    return cur_node;
}

/**
 * 创建基数树
 * 预先分配A类地址的数前8bit位
 * @return
 */
struct cradix_tree * create_radix_tree()
{
    struct cradix_tree * tree_ptr = malloc(sizeof(struct cradix_tree));
    assert(tree_ptr != NULL);
    if (!tree_ptr)
    {
        return  NULL;
    }

    tree_ptr->root = NULL;
    tree_ptr->size = 8;
    tree_ptr->root = malloc(sizeof(struct cradix_tree_node));
    assert(tree_ptr->root != NULL);
    if(!tree_ptr->root)
    {
        return NULL;
    }
    {
        tree_ptr->root->left = NULL;
        tree_ptr->root->right = NULL;
        tree_ptr->root->value = NULL;
    }


    //建立基数树高度为 32为ip地址的树高度

    uint32 inc = 0x80000000; // 对应32位 1000 0000 0000 0000 0000 0000  0000 0000
    uint32 key = 0;
    uint32 mask = 0; //掩码

    uint32 preallocate = tree_ptr->size; //预先分配A类地址的数前8bit位
    while (preallocate--)
    {
        key = 0;
        mask >>= 1;  // ip 地址掩码 是不同的
        mask |= 0x80000000;
        // 1000 0000 0000 0000 0000 0000 0000 0000  0000 0000
        /**
         *   ip的掩码 A类地址[8bit]  B类地址[16bit] C类地址[24bit] D,E类型地址不可用
         *   | 类   | 前缀长度   |  前缀
         *   |A类地址|  8位      | 0xxxxxxx                                              |
         *   |B类地址| 16位      | 10xxxxxx   xxxxxxxx                                   |
         *   |C类地址| 24位      | 110xxxxx   xxxxxxxx   xxxxxxxx                        |
         *   |D类地址| 不可用     | 1110xxxx   xxxxxxxx   xxxxxxxx     xxxxxxxx           |
         *   |E类地址| 不可用     | 11110xxx   xxxxxxxx   xxxxxxxx     xxxxxxxx           |
         * mask 对应 就是 A类地址的前8位bit位（默认第32位是1在代码中）
            mask = 2147483648 ==> 1000 0000 0000 0000 0000 0000 0000 0000
            mask = 3221225472 ==> 1100 0000 0000 0000 0000 0000 0000 0000
            mask = 3758096384 ==> 1110 0000 0000 0000 0000 0000 0000 0000
            mask = 4026531840 ==> 1111 0000 0000 0000 0000 0000 0000 0000
            mask = 4160749568 ==> 1111 1000 0000 0000 0000 0000 0000 0000
            mask = 4227858432 ==> 1111 1100 0000 0000 0000 0000 0000 0000
            mask = 4261412864 ==> 1111 1110 0000 0000 0000 0000 0000 0000
            mask = 4278190080 ==> 1111 1111 0000 0000 0000 0000 0000 0000
            mask = 4286578688 ==> 1111 1111 1000 0000 0000 0000 0000 0000
         */
        //遍历从树的顶层向下遍历
        do
        {
            //插入当前节点的数据
            cradix_tree_insert(tree_ptr, key, mask, NULL);
            //这边看出来了吗？  就加到内存溢出 就变成'0'啊
            key += inc; // 举例  == [0x80000000 + 0x80000000] = [0x100000000]  但是无符号int类型放不下这个数据所以 就是 [0x00000000] 高位溢出
        } while (key);
        inc >>= 1;
    }

    return tree_ptr;
}

/**
 * 基数树的查找O(logn)
 * @param tree_ptr
 * @param key
 * @return
 */
char * cradix_tree_find(struct cradix_tree * tree_ptr, uint32 key)
{
    assert(tree_ptr != NULL);
    if (!tree_ptr)
    {
        return NULL;
    }
    uint32 bit = 0x80000000;
    struct cradix_tree_node * cur_node = tree_ptr->root;
    void * ptr = NULL;
    while (cur_node)
    {
        if (cur_node->value)
        {
            ptr = cur_node->value;
        }
        if (key & bit)
        {
            cur_node = (struct cradix_tree_node *)cur_node->right;
        }
        else
        {
            cur_node = (struct cradix_tree_node *)cur_node->left;
        }
        bit >>= 1;
    }
    if (!ptr)
    {
        return default_ip;
    }
    return ptr;
}

/**
 * 递归释放基数树的节点的内存
 * @param tree_ptr
 */
void cradix_tree_node_destroy(struct cradix_tree_node *tree_ptr)
{
    if (!tree_ptr)
    {
        return;
    }
    cradix_tree_node_destroy((struct cradix_tree_node *)tree_ptr->left);
    if (tree_ptr->left)
    {
        free(tree_ptr->left);
        tree_ptr->left = NULL;
    }
    cradix_tree_node_destroy((struct cradix_tree_node *)tree_ptr->right);
    if (tree_ptr->right)
    {
        free(tree_ptr->right);
        tree_ptr->right = NULL;
    }
}

/**
 * 释放基数树内存
 * @param tree_ptr
 */
void cradix_tree_destroy(struct cradix_tree** tree_ptr)
{
    assert(tree_ptr != NULL);
    if (!tree_ptr)
    {
        return ;
    }

    cradix_tree_node_destroy((struct cradix_tree_node *)(*tree_ptr)->root);

    if ((*tree_ptr))
    {
        if ((*tree_ptr)->root)
        {
            free((*tree_ptr)->root);
            (*tree_ptr)->root = NULL;
        }
        free((*tree_ptr));
        (*tree_ptr) = NULL;

    }
}

/**
 * 测试数据结构
 */
struct ip_proxy {
    uint32  ip; // ip-> uint32
    uint32  mask; // 掩码
    char *  value; //映射的数据
};

/**2^0 = 1;
 * 2^1 = 2;
 * 2^2 = 4
 * 2^3 = 8
 * 2^4 = 16
 * 2^5 = 32
 * 2^6 = 64
 * 2^7 = 128
 *
 *
 * 测试数据
 *
 */
struct ip_proxy ip_data[] =
{         // 128 + 64 + 32 +15 = 96+15 +128 = 111+128 = 239  === 255 - 16 = 239
        { 4009754624/*1110 1111 0000 0000 0000 0000 0000 0000 == 239.0.0.0*/,  4278190080 /*1111 1111 0000 0000 0000 0000 0000 0000 === 255.0.0.0*/, "192.168.1.90"},
        { 4093640704,  4278190080, "192.168.1.91"},
        { 4160749568,  4278190080, "192.168.1.93"},
        { 4244635648, 4278190080, "wangyang"},
        { 3841982464, 4278190080, "shanghui"},
        { 2566914048, 4278190080, "beijing"}
};



//void show(struct cradix_tree_node * tree)
//{
//    if (!tree)
//    {
//        return;
//    }
//    printf(" vlaue %s\n", tree->value);
//    show(tree->left);
//    show(tree->right);
//}



int main(int argc, char *argv[])
{

    struct cradix_tree * tree_ptr = create_radix_tree();
    if (!tree_ptr)
    {
        return -1;
    }

    for (int i = 0; i < (sizeof(ip_data) / sizeof(struct ip_proxy)); ++i)
    {
        cradix_tree_insert(tree_ptr, ip_data[i].ip, ip_data[i].mask, ip_data[i].value);
    }
    ///show(tree_ptr->root);
    for (int i = 0; i < (sizeof(ip_data) / sizeof(struct ip_proxy)); ++i)
    {
        printf("ip mask  = %u, ip_proxy = %s, new_ip_proxy = %s\n", ip_data[i].ip, ip_data[i].value, cradix_tree_find(tree_ptr, ip_data[i].ip) );
    }
    //默认代理ip地址
    printf("not ip mask  = %u, ip_proxy = %s, new_ip_proxy = %s\n", 23432, "", cradix_tree_find(tree_ptr, 23432) );
    cradix_tree_destroy(&tree_ptr);
    return EXIT_SUCCESS;
}