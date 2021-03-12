/***********************************************************************************************
	created: 		2020-10-31

	author:			chensong

	purpose:		14.最长公共前缀

************************************************************************************************/

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
* 编写一个函数来查找字符串数组中的最长公共前缀。
*/
char * res = NULL;
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int count = 0;
    int i = 0;
    if (!res)
    {
        res = malloc(1024);
    }
    while (strsSize > 0)
    {
        char c = strs[0][count];
        for (i = 1; i < strsSize; ++i)
        {
            //这边访问内存不会溢出的是因为 下面 有判断 c != '\0'退出的了非常关键
            if (c != strs[i][count] )
            {
                break;
            }
        }
        // 比较的个数 i = strsSize 相等
        if (i == strsSize && c != '\0')
        {
            res[count++] = c;
        }
        else  //说明不相等
        {
            break;
        }
    }
    res[count] = '\0';
    return res;
}


int main(int argc , char *argv[])
{
    if (argc < 4)
    {
        printf("./test flower flow flight ");
        return -1;
    }

    printf( "prefix = %s\n", longestCommonPrefix(&argv[1], argc-1));
    return 0;
}