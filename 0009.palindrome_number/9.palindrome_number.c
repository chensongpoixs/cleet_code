/***********************************************************************************************
	created: 		2020-06-09

	author:			chensong

	purpose:		9.palindrome_number

************************************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * 9. ������
�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

ʾ�� 1:

����: 121
���: true
ʾ�� 2:

����: -121
���: false
����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
ʾ�� 3:

����: 10
���: false
����: ���������, Ϊ 01 �����������һ����������
����:

���ܲ�������תΪ�ַ�����������������
 * @param argc
 * @param argv
 * @return
 */

typedef  int bool;
#define  true 1
#define  false 0

bool isPalindrome(int x){

    if(x < 0)
    {
        return false;
    }
    long num = 0;
    long temp_x = x;
    while (temp_x > 0)
    {

        num = num * 10 + temp_x%10;
        if (num > 0X7FFFFFFF)
        {
            return false;
        }
        temp_x = temp_x /10;

    }
    if (num != x )
    {
        return false;
    }
    return true;
}


int main(int argc, char *argv[])
{
    int x = 121;
    printf("bool = %d\n", isPalindrome(x));
    return 0;
}