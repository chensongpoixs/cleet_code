/***********************************************************************************************
	created: 		2020-10-30

	author:			chensong

	purpose:		13.罗马数字转整数

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

int romanToInt(char * s){
    int num = 0;
    char *ptr = s;

    int len = strlen(s);
    while (len > 0)
    {
        for (int i = 0; i < 13; ++i)
        {
            if (memcmp(ptr, num_arrays[i], strlen(num_arrays[i])) == 0)
            {
                num += nums[i];
                ptr += strlen(num_arrays[i]);
                len -= strlen(num_arrays[i]);
            }
            if (len <= 0 || NULL == ptr)
            {
                return num;
            }
        }
        
    }
    return num;
}
// cmd ./test MCMXCIV
int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        printf("./test str\n");
        return -1;
    }
    printf("int  = %d\n", romanToInt(argv[1]));
	
	return 0;
}