/***********************************************************************************************
created: 		2020-06-08

author:			chensong

purpose:		8.string_to_integer

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
