/***********************************************************************************************
	created: 		2020-10-31

	author:			chensong

	purpose:		14.�����ǰ׺

************************************************************************************************/

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
* ��дһ�������������ַ��������е������ǰ׺��
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
            //��߷����ڴ治�����������Ϊ ���� ���ж� c != '\0'�˳����˷ǳ��ؼ�
            if (c != strs[i][count] )
            {
                break;
            }
        }
        // �Ƚϵĸ��� i = strsSize ���
        if (i == strsSize && c != '\0')
        {
            res[count++] = c;
        }
        else  //˵�������
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