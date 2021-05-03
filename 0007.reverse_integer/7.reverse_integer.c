/***********************************************************************************************
created: 		2020-06-07

author:			chensong

purpose:		7.reverse_integer

************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 7. ������ת
����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��

ʾ�� 1:

����: 123
���: 321
 ʾ�� 2:

����: -123
���: -321
ʾ�� 3:

����: 120
���: 21
ע��:

�������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ [?2^31,  2^31 ? 1]�������������裬�����ת�����������ô�ͷ��� 0��
 *
 */
signed int max = 0X7FFFFFFF;
signed int min = 0X80000000;// ?1000 0000 0000 0000 0000 0000 0000 0000?

int reverse(int x)
{
    signed long ret = 0;
    for (; x;x /=10)
    {
        // ���λ�ϵ�ֵ
        ret = ret * 10 + x %10;

    }
    return (ret > max || ret < min) ? 0: ret;
}


/**
 * TODO@chensong 2021-05-03
 * int �����з����ڴ��������
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