/***********************************************************************************************
	created: 		2020-11-17

	author:			chensong

	purpose:		406.根据身高重建队列
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



int pratition(int **people, int start, int end)
{
    int value = people[start][0];
    // (value1[0] == value2[0]) ? value2[1] - value1[1] : value1[0] - value2[0];
    int right = start;
    int left = end+1;
    while (1)
    {
        //找到最大的数的下标
        while (  people[++right][0] == value? people[right][1] > people[start][1] : people[start][0] > people[right][0] )
        {
            if(right == end)
            {
                break;
            }
        }
        //最小的值
        while ( people[--left][0] == value? people[left][1] < people[start][1] : people[start][0] < people[left][0]  /*people[--left][1] < value*/)
        {
            if (left == start)
            {
                break;
            }
        }
        if (left <= right)
        {
            break;
        }
        int * temp= people[right];
        people[right] = people[left];
        people[left] = temp;
        
    }
    int* temp = people[start];
    people[start] = people[left];
    people[left] = temp;
    return left;
}

void sort(int **people, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int p = pratition(people, start, end);
    sort(people, start, p-1);
    sort(people, p+1, end);
}
/**
*快速排序
*/
void quick_sort(int **people, int size)
{
    if (people == NULL || size <= 0)
    {
        return;
    }
    sort(people, 0, size-1);
}


//

typedef   struct cListNode
{
    int value;
    struct cListNode* next;
}cListNode;


void insert_node(cListNode * head, int value)
{
    if (!head)
    {
        return;
    }
    cListNode * cur_node = head->next;
    cListNode * pre_node = head;
    while (cur_node)
    {
        if (cur_node->value > value)
        {
            cListNode * new_list_node = malloc(sizeof(struct cListNode));
            new_list_node->value = value;
            new_list_node->next = cur_node;
            pre_node->next = new_list_node;
            return ;
        }
        else if (cur_node->value < value)
        {
            pre_node = cur_node;
            cur_node = cur_node->next;

        }
        else 
        {
            cListNode * new_list_node = malloc(sizeof(struct cListNode));
            new_list_node->value = value;
            new_list_node->next = cur_node;
            pre_node->next = new_list_node;
            return ;
        }
    }
    if (!cur_node)
    {
        cListNode * new_list_node = malloc(sizeof(struct cListNode));
        new_list_node->value = value;
        new_list_node->next = NULL;
        pre_node->next = new_list_node;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void * ptr1, const void * ptr2)
{
    const int * value1 = *(const int **)ptr1;
    const int * value2 = *(const int **)ptr2;
    //a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]
    return (value1[0] == value2[0]) ? value2[1] - value1[1] : value1[0] - value2[0];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    //           [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    //1. 快速排序  [[5,2],[5,0],[6,1],[7,0],[4,4],[7,1]]
    quick_sort(people, peopleSize);
    // 2.        [[4,4],[5,2],[5,0],[6,1],[7,1],[7,0]]
    // qsort(people, peopleSize, sizeof(int *), comp );
    //  *returnSize = peopleSize;
    //  *returnColumnSizes = peopleColSize;
    //  return people;
    
    int **arrays = malloc(sizeof(int *) * peopleSize);
    *returnColumnSizes = malloc(sizeof(int) * peopleSize);
    memset(*returnColumnSizes, 0, sizeof(int)*peopleSize);
    for (int i = 0; i < peopleSize; ++i)
    {
        int split = people[i][1] +1;
        for (int j = 0; j < peopleSize; ++j)
        {
            if ((*returnColumnSizes)[j] == 0)
            {
                --split;
                if (!split)
                {
                    (*returnColumnSizes)[j] = 2;
                    arrays[j] = malloc(sizeof(int) * 2);
                    arrays[j][0] = people[i][0];
                     arrays[j][1] = people[i][1];
                      break;
                }
            }
        }
    }
  *returnSize = peopleSize;
    return arrays;
    // //2. 插入排序
    // for (int i = 0; i < peopleSize; ++i)
    // {
    //     for (int j = i + 1; j < peopleSize; ++j)
    //     {
    //         if(people[i][0]  >= people[j][0] && people[i][1] == people[j][1])
    //         {
    //             int * temp = people[j];
    //             // people[j] = people[i];
    //             // people[i] = temp;
    //             printf("[i = %d, j = %d]\n", i, j);
    //             int temp_j = j;
    //             while (i < temp_j)
    //             {
    //                 printf("temp_j = %d\n", temp_j);
    //                 people[temp_j] = people[--temp_j]; 
    //             }
    //             people[i] = temp;
    //         }
    //         else if(people[i][0]  == people[j][0] && people[i][1] >= people[j][1])
    //         {
    //             int * temp = people[j];
    //             // people[j] = people[i];
    //             // people[i] = temp;
    //             printf("[i = %d, j = %d]\n", i, j);
    //             int temp_j = j;
    //             while (i < temp_j)
    //             {
    //                 printf("temp_j = %d\n", temp_j);
    //                 people[temp_j] = people[--temp_j]; 
    //             }
    //             people[i] = temp;
    //         }
    //         else if (people[i][0]  >= people[j][0] && people[i][1] >= people[j][1])
    //         {
    //             int * temp = people[j];
    //             // people[j] = people[i];
    //             // people[i] = temp;
    //             printf("[i = %d, j = %d]\n", i, j);
    //             int temp_j = j;
    //             while (i < temp_j)
    //             {
    //                 printf("temp_j = %d\n", temp_j);
    //                 people[temp_j] = people[--temp_j]; 
    //             }
    //             people[i] = temp;
    //         }
    //         else 
    //         {
    //             printf("[][][][][][][][][][][][][][][[][][][[][]]]\n");
    //         }
    //     }
    // }
    // cListNode * list_ptr = malloc(sizeof(struct cListNode));
    // list_ptr->next = NULL;
    // for (int i = 0; i < peopleSize; ++i)
    // {
    //     insert_node(list_ptr, people[i][1]);
    // }
    //  *returnColumnSizes = peopleColSize;
    // *returnSize = peopleSize;
    // int num = 0;//排序好的
    // for (cListNode * cur_node = list_ptr->next; cur_node!= NULL; cur_node = cur_node->next)
    // {
    //     if (!cur_node)
    //     {
    //         break;
    //     }
    //     printf("value = %d\n", cur_node->value);
    //     for (int i = num+1; i < peopleSize; ++i)
    //     {
    //         if ((people[i][1] == cur_node->value && (people[i][0] < people[num][0] || (people[i][0] == people[num][0] && (num -i) > 1)) )  )
    //         {
    //             int * cur_ptr = people[i];
    //             int index = i;
    //             while (num < index)
    //             {
    //                 --index;
    //                 printf("[index = %d, ===", index);
    //                 people[index+1] = people[index];
    //                 printf("index = %d]\n", index);
    //             }
    //             printf("[i = %d][num = %d][index = %d]\n", i, num, index);
    //              people[num] = cur_ptr;
    //             // return people;
                
    //         }
    //         // else 
    //         // {

    //         // }
    //     }
    //     ++num;
    // }

    // *returnColumnSizes = peopleColSize;
    // *returnSize = peopleSize;
    // return people;
}



int main(int argc, char *argv[])
{
	//输入：[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    //输出：[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


	
	return EXIT_SUCCESS;
}
