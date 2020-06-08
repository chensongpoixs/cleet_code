/***********************************************************************************************
created: 		2020-06-08

author:			chensong

purpose:		8.string_to_integer
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


signed int max = 0X7FFFFFFF;
signed int min = 0X80000000;

/**
 *
 * @param s
 * @return
 */
int myAtoi(char * s)
{
    if (!s)
    {
        return 0;
    }

    long ret = 0;
    char *p = s;
    int   positive = 0; //正数
    int   negative = 0; //负数
    int   index = 0;
    int   num = 0; //是否已经有值了
    while (p)
    {
        if (*p == '\0')
        {
            break;
        }
        printf("index = %d = %c\n", index, *p);
        if (*p == ' ')
        {
            if ((0 != ret)||positive||negative || num == 1)
            {
                break;
            }
//           ++p;
        }
        else if (*p  == '-')
        {
            if (positive == 1 || num == 1 || negative == 1)
            {
                break;
            }
            if (0 !=ret)
            {
                break;
            }
            negative = 1;
//           ++p;
        }
        else if (*p == '+' )
        {
            // if ()
            if (negative == 1 || num == 1 || positive == 1)
            {
                break;
            }
            if (0 != ret)
            {
                break;
            }
            positive =1;
        }
        else
        {
            if ((*p -'0')  < 10&&( *p -'0')  > -1)
            {
                //判断是否已经是最大值或者最小值
                if (ret * 10> max)
                {
                    if (negative == 1)
                    {
                        return min;
                    }

                    return max;
                }
                ret = ret* 10 + (*p -'0');
                num = 1;
            }
            else
            {

                break;
                //    }
            }
//           ++p;
        }
        ++p;
        ++index;
        printf("ret %ld\n", ret);
    }
    if (negative == 1)
    {
        ret = -1 * ret;
        if (ret < min)
        {
            return min;
        }
    }
    if (ret > max)
    {
        return max;
    }
    return ret;
}



// int main(int argc, char *argv[])
// {


//     char * s = "3.14159";
//     int num = myAtoi(s);
//     printf("num %d\n", num);
//     return  EXIT_SUCCESS;
// }



// int main(int argc, char *argv[])
// {


//     char * s = "3.14159";
//     int num = myAtoi(s);
//     printf("num %d\n", num);
//     return  EXIT_SUCCESS;
// }



int main(int argc, char *argv[])
 {
    // "  -0  23"
    // "++23423"
     // "+-3432"
     // "+322243"
     char * s = "3.14159";
     int num = myAtoi(s);
     printf("num %d\n", num);
     return  EXIT_SUCCESS;
 }
