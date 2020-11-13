/***********************************************************************************************
	created: 		2020-11-12

	author:			chensong

	purpose:		面试题17.21.直方图的水量
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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>



// typedef struct btree
// {
//     int value;
//     struct btree * left;
//     struct btree * right;
// } btree;


// btree * find(btree * tree, int value)
// {
//     if (!tree)
//     {
//         return NULL;
//     }
//     btree*  cur_tree = tree;
//     while (cur_tree)
//     {
//         // right
//         if (cur_tree->value > value)
//         {
//             cur_tree = cur_tree->right;
//         }
//         else if (cur_tree->value < value)
//         {
//             cur_tree = cur_tree->left;
//         }
//         else
//         {
//             return cur_tree;
//         }
//     }
//     return cur_tree;
// }

// void insert_tree(btree* tree, int value)
// {
//     if (!tree )
//     {
//         return;
//     }
//     btree * cur_tree = find(tree, value);
//     if (!cur_tree)
//     {

//     }

// }

typedef struct list
{
    int value;
    struct list * next;
    // struct list * pre;
} order_list;


void insert_value(order_list * list_ptr, int value)
{
    if (!list_ptr)
    {
        // list_ptr = malloc(sizeof(struct list));
        // list_ptr->value = value;
        // list_ptr->next = NULL;
        return;
    }
    order_list * cur_list_ptr = list_ptr->next;
//    if (!cur_list_ptr)
//    {
//        cur_list_ptr = malloc(sizeof(struct list));
//        cur_list_ptr->value = value;
//        cur_list_ptr->next = NULL;
//        list_ptr->next = cur_list_ptr;
//        return;
//    }
    order_list * pre_list_ptr = list_ptr;
    while (NULL != cur_list_ptr)
    {
        if (cur_list_ptr->value > value)
        {
            order_list * new_list_ptr = malloc(sizeof(struct list));
            new_list_ptr->value = value;
            new_list_ptr->next = cur_list_ptr;
            pre_list_ptr->next = new_list_ptr;
            printf("head total value = %u\n", value);
            return;
        }
        else if (cur_list_ptr->value < value)
        {
            cur_list_ptr = cur_list_ptr->next;
            pre_list_ptr = pre_list_ptr->next;
            printf("<<<\n");

        }
        else
        {
            return;
        }


    }
    if (!cur_list_ptr)
    {
        printf("! cur list ptr value = %d\n", value);
        order_list * new_list_ptr = malloc(sizeof(struct list));
        new_list_ptr->value = value;
        new_list_ptr->next = NULL;
        pre_list_ptr->next = new_list_ptr;
    }
}

int trap(int* height, int heightSize)
{
    if (height == NULL || heightSize <= 0)
    {
        return 0;
    }

    int big_height = 0;
    order_list * list_ptr = malloc(sizeof(struct list));
//    list_ptr->next = NULL;
    for (int i = 0; i < heightSize; ++i)
    {
        // if (big_height < height[i])
        // {
        //     big_height = height[i];
        // }
        printf("i = %d, value = %d\n", i, height[i]);
        insert_value(list_ptr, height[i]);
    }
    printf("www\n");
    for (order_list * cur_list_ptr = list_ptr->next; cur_list_ptr != NULL; cur_list_ptr = cur_list_ptr->next)
    {
        if (!cur_list_ptr)
        {
            return 0;
        }
        printf("value = %u\n", cur_list_ptr->value);
    }

//    return 0;




    //O(n^2)
    //面积
    int area_size = 0;

    // int i = 0;
    // int pre_height = 0;
    // while (++i < big_height && (height[i-1] != height[i]) )
    // {

    // // }
    // for (int i = 0; i < big_height; ++i)
    int pre_height = 0;
    for (order_list * cur_list_ptr = list_ptr->next; cur_list_ptr != NULL; cur_list_ptr = cur_list_ptr->next)
    {
        int left = -1;
        int right = -1;
        if (!cur_list_ptr || !cur_list_ptr->next)
        {
            return area_size;
        }

        for (int j = 0; j < heightSize; ++j)
        {
            // 一行的数据中的面积
            // left , right
            if ((height[j] - cur_list_ptr->value) > 0 && left < 0 )
            {
                left = j;
                right = 1;
            }
            else if ((height[j] - cur_list_ptr->value) > 0 && left >= 0 )
            {
                if ( height[j] >= height[j-1] && right == -1)
                {
                    left = j;
                }
                else
                {
                    area_size += ((j - left) * (cur_list_ptr->value - pre_height));
                    left = j;
                    right = -1;
                }
            }
        }
        pre_height = cur_list_ptr->value;
        //++i;
    }
    return area_size;
}


int main(int argc, char *argv[])
{

    int arrays[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    printf(" area_size = %u\n", trap(&arrays[0], sizeof(arrays)/ sizeof(int)));

    return EXIT_SUCCESS;
}