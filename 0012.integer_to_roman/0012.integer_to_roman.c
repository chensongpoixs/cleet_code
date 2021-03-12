/***********************************************************************************************
	created: 		2020-10-30

	author:			chensong

	purpose:		12.整数转罗马数字

************************************************************************************************/

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
static const int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

static const char *num_arrays[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
static char str_num [1024]={0};
/**
*查看表法
*/
char * intToRoman(int num)
{
    memset(&str_num[0], 0, 1024 * sizeof(char));
    int index = 0;
    for (int i = 0; i < 13; ++i)
    {
        //大于当前罗马数字
        if (nums[i]<=num)
        {
            int m = num / nums[i];
            num -= (m*nums[i]);
            while (m>0)
            {
                size_t len = strlen(num_arrays[i]);
                memcpy(&str_num[index], num_arrays[i], len);
                index += len;
                --m;
            }
        }
    }
    return str_num;
}

// cmd ./test 1994
int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        printf("./test number\n");
        return -1;
    }
    printf("罗马数字 = %s\n", intToRoman(atoi(argv[1])));
	
	return 0;
}