/***********************************************************************************************
created: 		2020-06-07

author:			chensong

purpose:		7.reverse_integer

************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 7. 整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [?2^31,  2^31 ? 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 *
 */
signed int max = 0X7FFFFFFF;
signed int min = 0X80000000;// ?1000 0000 0000 0000 0000 0000 0000 0000?

int reverse(int x)
{
    signed long ret = 0;
    for (; x;x /=10)
    {
        // 最低位上的值
        ret = ret * 10 + x %10;

    }
    return (ret > max || ret < min) ? 0: ret;
}


/**
 * TODO@chensong 2021-05-03
 * int 类型有符号内存溢出问题
 *  [-2147483648, 1534236469]
 * @param x
 * @return
 */
int reverse_two(int x)
{
    long cur_x = x;
    int ans_signed = 1;
    if (cur_x < 0)
    {
        ans_signed = -1;
        cur_x *= -1;
    }
    long ans = 0;

    while (cur_x != 0)
    {
        long temp = cur_x / 10;
        ans = ans * 10 + (cur_x - (temp * 10));
        cur_x = temp;
    }
    return ans * ans_signed;
}

int main(int argc, char *argv[])
{

    int num = 120;
    int ret = reverse(num);
    printf("ret = %d\n", ret);

    return EXIT_SUCCESS;
}