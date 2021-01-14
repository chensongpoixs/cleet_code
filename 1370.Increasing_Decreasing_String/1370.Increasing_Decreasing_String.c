/***********************************************************************************************
	created: 		2020-11-25

	author:			chensong

	purpose:		1370. 上升下降字符串
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




int parition(char * s, int start, int end)
{
    char value = s[start];
    int left = start;
    int right = end +1;
    while (1)
    {
        //找到最大值
        while (s[++left] < value)
        {
            if (left == end)
            {
                break;
            }

        }
        //找到最小值
        while (s[--right] > value)
        {
            if (right == start)
            {
                break;
            }

        }

        if (right <= left)
        {
            break;
        }
        char c = s[left];
        s[left] = s[right];
        s[right] = c;
    }

    char c = s[start];
    s[start] = s[right];
    s[right] = c;
    return right;
}


void sort(char *s , int start, int end)
{
    if (start>= end)
    {
        return;
    }
    int p = parition(s, start, end);
    sort(s, start, p-1);
    sort(s, p+1, end);
}
void quick_sort(char *s, int size)
{
    if (size<= 1)
    {
        return;
    }

    sort(s, 0, size -1);
}

char * sortString(char * s)
{
    if (!s)
    {
        return "";
    }
    if (strlen(s)<= 1)
    {
        return s;
    }

    quick_sort(s, strlen(s));
    // int * arrays = malloc(strlen(s) * sizeof(int));
    // memset(arrays, 0, sizeof(int) * strlen(s));
    char * result = malloc((strlen(s)+1) * sizeof(char));
    char cur_str = 'a' - 1 ;

    int size = strlen(s);

    int run = 1;
    int result_size = 0;
    int left  = 1;
    
    while (run)
    {
        if (left == 1)
        {
            for (int i = 0; i < size; ++i)
            {
                if (s[i] != ('a'-1) && cur_str < s[i])
                {
                    result[result_size++] = s[i];
                    cur_str = s[i];
                    s[i] = ('a'-1);
                    // arrays[i] = 1;
                }
            }
            left = 0;
            cur_str = 'd' + 27;
        }
        else 
        {
            for (int i = size-1; i >= 0; --i)
            {
                
                if (s[i] != ('a'-1) && cur_str > s[i])
                {
                    // printf("i = %d , %c \n", i, s[i]);
                    result[result_size++] = s[i];
                     cur_str = s[i];
                     s[i] = ('a'-1);
                    // arrays[i] = 1;
                }
            } 
            left = 1;
             cur_str = 'a' -1 ;
        }
        if (result_size >= size)
        {
            run = 0;
            result[result_size] = '\0';
        }

        
    }
    // free(arrays);
    return result;
}

char * sortString_bucket(char * s)
{
    if (!s)
    {
        return "";
    }
    if (strlen(s)<= 1)
    {
        return s;
    }

    // quick_sort(s, strlen(s));
    // // int * arrays = malloc(strlen(s) * sizeof(int));
    // // memset(arrays, 0, sizeof(int) * strlen(s));
    // char * result = malloc((strlen(s)+1) * sizeof(char));
    // char cur_str = 'a' - 1 ;

    int size = strlen(s);
    int bucket[26] ={0};
    for (int i = 0; i < size; ++i)
    {
        ++bucket[s[i]-'a'] ;
    }
    int run = 1;
    int result_size = 0;
    int left  = 1;
    
    while (run)
    {
        if (left == 1)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (bucket[i] > 0)
                {
                    s[result_size++] = 'a'+i;
                    --bucket[i];
                    // arrays[i] = 1;
                }
            }
            left = 0;
        }
        else 
        {
            for (int i = 25; i >= 0; --i)
            {
                
                if (bucket[i] > 0)
                {
                    // printf("i = %d , %c \n", i, s[i]);
                     s[result_size++] = 'a'+i;
                    --bucket[i];
                    // arrays[i] = 1;
                }
            } 
            left = 1;
           
        }
        if (result_size >= size)
        {
            run = 0;
            s[result_size] = '\0';
        }

        
    }
    // free(arrays);
    return s;
}
int main(int argc, char *argv[])
{
	char *s = "rsdfdsafsadfyiuewopredsafdsafat";
	printf("s = %s\n", s);
	char *ptr = malloc(sizeof(char )* (strlen(s)+1));
	memcpy(ptr,s, strlen(s));
	ptr[strlen(s)] = '\0';
	char* out_s = sortString_bucket(ptr);
	if (out_s)
	{
		printf("out = %s\n", out_s);
		
	}
	
	
	return 0;
}
