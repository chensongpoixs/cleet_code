/***********************************************************************************************
	created: 		2020-11-17

	author:			chensong

	purpose:		1030.距离顺序排列矩阵单元格
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


struct cListNode
{
    int x;
    int y;
    int value;
    struct cListNode * next;
}cListNode;

//列表是从小到大的排序
void insert_node(struct cListNode * head, int x, int y, int value)
{
    if (!head)
    {
        return;
    }
    struct cListNode * cur_list = head->next;
    struct cListNode * pre_list = head;
    while (cur_list)
    {
        if (cur_list->value >= value)
        {
            struct cListNode * new_list_node = malloc(sizeof(struct cListNode));
            new_list_node->value = value;
            new_list_node->x = x;
            new_list_node->y = y;
            new_list_node->next = cur_list;
            pre_list->next = new_list_node;
            return;
        }
        else
        {
            pre_list = cur_list;
            cur_list = cur_list->next;
        }
    }
    if (!cur_list)
    {
        struct cListNode * new_list_node = malloc(sizeof(struct cListNode));
        new_list_node->value = value;
        new_list_node->x = x;
        new_list_node->y = y;
        new_list_node->next = NULL;
        pre_list->next = new_list_node;
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allCellsDistOrder_list(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    struct cListNode* list_ptr = malloc(sizeof(struct cListNode));
    list_ptr->next = NULL;
    int number = 1;
    for (int x = 0; x < R; ++x)
    {
        for (int y = 0; y < C; ++y)
        {
            if (r0 == x && y == c0)
            {
                continue;
            }
            int value = abs(x-r0)+abs(y-c0);
            insert_node(list_ptr, x, y, value);
            ++number;
        }
    }
    int ** arrays = malloc(sizeof(int *)* number);
    * returnColumnSizes = malloc(sizeof(int)* number);
    *returnSize = number;
    number = 0;
    {
        (*returnColumnSizes)[number] = 2;
        arrays[number] = malloc(sizeof(int)*2);
        arrays[number][0] = r0;
        arrays[number][1] = c0;
        ++number;
    }
    for (struct cListNode* cur_list_ptr = list_ptr->next; cur_list_ptr != NULL; cur_list_ptr = cur_list_ptr->next)
    {
        if (!cur_list_ptr)
        {
            break;
        }
        (*returnColumnSizes)[number] = 2;
        arrays[number] = malloc(sizeof(int)*2);
        arrays[number][0] = cur_list_ptr->x;
        arrays[number][1] = cur_list_ptr->y;
        ++number;
    }
    struct cListNode* cur_list_ptr = list_ptr;
    while (cur_list_ptr)
    {
        struct cListNode * next_list_ptr = cur_list_ptr->next;
        free(cur_list_ptr);
        cur_list_ptr = NULL;
        cur_list_ptr = next_list_ptr;
    }

    return arrays;
}



int prartion(int **arrays, int start, int end, int x, int y)
{
    int value = abs(x - arrays[start][0])+ abs(y - arrays[start][1]);
    int right = start;
    int left = end +1;
    while (1)
    {
        //找到最大值
        while ( value > (abs(arrays[++right][0] -x  )+ abs(y - arrays[right][1])))
        {
            if (right == end)
            {
                break;
            }
        }
        //找到最小值
        while (value  <(abs(arrays[--left][0] -x )+ abs(y - arrays[left][1])))
        {
            if (left == start)
            {
                break;
            }
        }
        if (left<= right)
        {
            break;
        }
        int * temp = arrays[right];
        arrays[right] = arrays[left];
        arrays[left] = temp;
    }

    int * temp = arrays[start];
    arrays[start] = arrays[left];
    arrays[left] = temp;
    return left;
}

void sort(int **arrays, int start, int end, int x, int y)
{
    if (end <= start)
    {
        return ;
    }
    int p = prartion(arrays, start, end, x, y);
    sort(arrays, start, p-1, x, y);
    sort(arrays, p +1, end, x, y);
}

void quick_sort(int **arrays, int size, int x, int y)
{
    if (arrays == NULL || size <= 0)
    {
        return;
    }
    sort(arrays, 0, size -1, x, y);
}
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes)
{
    *returnSize = R * C;
    *returnColumnSizes = malloc(sizeof(int) *(*returnSize));
    int **arrays = malloc(sizeof(int *)* (*returnSize));
    int number = 0;
    for (int x = 0; x < R; ++x)
    {
        for (int y = 0; y < C; ++y)
        {
            (*returnColumnSizes)[number] = 2;
            arrays[number] = malloc(sizeof(int) * 2);
            arrays[number][0] = x;
            arrays[number][1] = y;
            ++number;
        }
    }
    //[[0,0],[1,1],[1,0],[0,1],[0,2],[1,2]]
    quick_sort(arrays, number, r0, c0);


    return arrays;
}





int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        printf("usage: ./test 2 3 1 2");
        return -1;
    }

    int retsize = 0;
    int * returncolumnsizes = NULL;
    int **arrsys = allCellsDistOrder(stoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), &retsize, &returncolumnsizes);
    if (arrsys)
    {
        for (int i = 0; i < retsize; ++i)
        {
            for (int j = 0; j < returncolumnsizes[i]; ++j)
            {
                if (i != 0 )
                {
                    printf(", ");
                }
                printf("[%d, %d]", arrsys[i][0], arrsys[i][1]);
                free(arrsys[i]);
                arrsys[i] = NULL;
            }
        }
        free(arrsys);
        free(returncolumnsizes);
    }
    return EXIT_SUCCESS;
}