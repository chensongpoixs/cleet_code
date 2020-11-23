/***********************************************************************************************
	created: 		2020-11-23

	author:			chensong

	purpose:		452. 用最少数量的箭引爆气球
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
    int x;
    int y;
    // struct ListNode* pre;
    struct cListNode* next;
}cListNode;
struct cListNode * list_ptr = NULL;
void insert_node( int x, int y)
{
    struct cListNode * pre_list_node_ptr = NULL;
    struct cListNode * cur_list_node_ptr = list_ptr;
    for (; cur_list_node_ptr != NULL; cur_list_node_ptr = cur_list_node_ptr->next )
    {
        // printf("[x = %d, y = %d][ cur_list_node_ptr->x = %d, cur_list_node_ptr->y = %d]\n", x, y, cur_list_node_ptr->x, cur_list_node_ptr->y);
        if (cur_list_node_ptr->x <= x && cur_list_node_ptr->y >=y)
        {
            //在这个范围
            //缩小范围操作
            if (cur_list_node_ptr->x < x )
            {
                cur_list_node_ptr->x = x;
            }
            if (cur_list_node_ptr->y > y)
            {
                // if ()
                cur_list_node_ptr->y = y;
            }
            return;
        }
        else if (cur_list_node_ptr->x < y && /*y <= cur_list_node_ptr->y &&*/ x <= cur_list_node_ptr->x)
        {
            // printf("[][][[][[][]]]\n");
            if (cur_list_node_ptr->y >y)
            {
                cur_list_node_ptr->y = y;
            }
            if (cur_list_node_ptr->x <x)
            {
                cur_list_node_ptr->x = x;
            }

            return;

        }
        else if (cur_list_node_ptr->y >=x  && cur_list_node_ptr->y <= y)
        {
            // printf("[][]\n");
            if(cur_list_node_ptr->x < x)
            {
                cur_list_node_ptr->x = x;
            }
            if (cur_list_node_ptr->y > y)
            {
                cur_list_node_ptr->y = y;
            }
            return;
        }
        else if (cur_list_node_ptr->x == y)
        {
            cur_list_node_ptr->y = y;
            return ;
        }
        else if (cur_list_node_ptr->y == x)
        {
            cur_list_node_ptr->x = x;
            return;
        }
        else  if (y < cur_list_node_ptr->x)//小于当前的值的了left的值了
        {
            break;
        }
        else if (x > cur_list_node_ptr->y)
        {
            //找下一个目标进行比较
            // break;
        }
        else
        {
            // printf("else {}\n");
        }
        // else
        // {

        // }
        pre_list_node_ptr = cur_list_node_ptr;
    }

    if (!pre_list_node_ptr)
    {
        // printf("[alloc head]\n");
        struct cListNode * new_list_ptr  = malloc(sizeof(struct cListNode));
        new_list_ptr->next = list_ptr;
        new_list_ptr->x = x;
        new_list_ptr->y = y;
        list_ptr = new_list_ptr;
    }
    else
    {
        //  printf("[alloc middle]\n");
        struct cListNode * new_list_ptr  = malloc(sizeof(struct cListNode));
        new_list_ptr->next = cur_list_node_ptr;
        new_list_ptr->x = x;
        new_list_ptr->y = y;
        pre_list_node_ptr->next = new_list_ptr;
    }


}


int parition(int ** points, int start, int end)
{
    int value = points[start][0];
    int left = start;
    int right = end +1;
    while (1)
    {
        //找到最大的数
        while (points[++left][0] < value)
        {
            if (left == end)
            {
                break;
            }
        }
        // 找到最小的数
        while (points[--right][0]> value)
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
        int * temp = points[left];
        points[left] = points[right];
        points[right] = temp;
    }
    int * temp = points[start];
    points[start] = points[right];
    points[right] = temp;
    return right;
}


void sort(int **points, int start, int end)
{
    if (start >= end)
    {
        return ;
    }
    int p = parition(points, start, end);
    sort(points, start, p -1);
    sort(points, p+1, end);
}

void quick_sort(int **points, int size)
{
    sort(points, 0, size-1);
}
//[[10,16],[2,8],[1,6],[7,12],[90, 100], [95, 1000],[58, 94],[90, 98]]
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
    quick_sort(points, pointsSize);
    for (int x = 0; x < pointsSize; ++x)
    {
        if (!list_ptr)
        {
            list_ptr = malloc(sizeof(struct cListNode));
            list_ptr->next = NULL;
            list_ptr->x = points[x][0];
            list_ptr->y = points[x][1];
        }
        else
        {
            insert_node( points[x][0], points[x][1]);
        }
    }

    int num = 0;

    while(list_ptr)
    {
        ++num;
        struct cListNode * next_list_node_ptr = list_ptr->next;
        // printf("[][][x = %d][y = %d]\n", list_ptr->x, list_ptr->y);
        free(list_ptr);
        list_ptr = NULL;
        list_ptr = next_list_node_ptr;
    }


    return num;
}


int main(int argc, char *argv[])
{

    int **points = malloc(sizeof(int *) *4);//{10, 16, 2, 8, 1, 6, 7, 12};
    points[0] = malloc(sizeof(int) *2);
    points[0][0] = 10;
    points[0][1] = 16;
    points[1] = malloc(sizeof(int) *2);
    points[1][0] = 2;
    points[1][1] = 8;
    points[2] = malloc(sizeof(int) *2);
    points[2][0] = 1;
    points[2][1] = 6;
    points[3] = malloc(sizeof(int) *2);
    points[3][0] = 7;
    points[3][1] = 12;
    int pointsSize = 4;
    int pointsColSize[4] = {0};
    for (int i = 0; i < 4; ++i)
    {
        pointsColSize[i] = 2;
    }

    printf("[[10,16],[2,8],[1,6],[7,12]]\n");
    //[[10,16],[2,8],[1,6],[7,12]]


    printf("num = %d\n", findMinArrowShots(points, pointsSize, pointsColSize));

    for (int j = 0; j < 4; ++j)
    {
        if (points[j])
        {
            free(points[j]);
            points[j] = NULL;
        }
    }
    if (points)
    {
        free(points);
        points = NULL;
    }


    return EXIT_SUCCESS;
}