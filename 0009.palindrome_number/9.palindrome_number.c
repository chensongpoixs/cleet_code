/***********************************************************************************************
	created: 		2020-06-09

	author:			chensong

	purpose:		9.palindrome_number

************************************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * 9. 回文数
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？
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