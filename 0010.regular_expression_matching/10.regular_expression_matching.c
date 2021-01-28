/***********************************************************************************************
	created: 		2020-06-09

	author:			chensong

	purpose:		10.regular_expression_matching

************************************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 10. ������ʽƥ��
����һ���ַ��� s ��һ���ַ����� p��������ʵ��һ��֧�� '.' �� '*' ��������ʽƥ�䡣

'.' ƥ�����ⵥ���ַ�
'*' ƥ���������ǰ�����һ��Ԫ��
��νƥ�䣬��Ҫ���� ���� �ַ��� s�ģ������ǲ����ַ�����

˵��:

s ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ��
p ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ���Լ��ַ� . �� *��
ʾ�� 1:

����:
s = "aa"
p = "a"
���: false
����: "a" �޷�ƥ�� "aa" �����ַ�����
ʾ�� 2:

����:
s = "aa"
p = "a*"
���: true
����: ��Ϊ '*' �������ƥ���������ǰ�����һ��Ԫ��, ������ǰ���Ԫ�ؾ��� 'a'����ˣ��ַ��� "aa" �ɱ���Ϊ 'a' �ظ���һ�Ρ�
ʾ�� 3:

����:
s = "ab"
p = ".*"
���: true
����: ".*" ��ʾ��ƥ�����������'*'�������ַ���'.'����
ʾ�� 4:

����:
s = "aab"
p = "c*a*b"
���: true
����: ��Ϊ '*' ��ʾ������������� 'c' Ϊ 0 ��, 'a' ���ظ�һ�Ρ���˿���ƥ���ַ��� "aab"��
ʾ�� 5:

����:
s = "mississippi"
p = "mis*is*p*."
���: false
ͨ������80,332�ύ����285,022

 */

typedef int bool;
#define  true 1
#define  false 0

bool isMatch(char * s, char * p)
{
    //�ж��Ƿ���ַ�
    if (*p == '\0')
    {
        return *s == '\0';
    }
    // p�ڶ��ַ�һ������* �Ż�������Ĳ���  ����'*'����һ�����ж�
    // ��� 1: s = "abwd"; p = "a";
    // ��� 2: s = "abwd"; p = "."; 
    if (*(p +1) == '\0' || *(p +1) != '*')
    {
        if (*s == '\0' || (*p != '.' && *s != *p))
        {
            return false;
        }
        else 
        {
            return  isMatch(s +1, p + 1);
        }
    }
    // �����ǰp���ַ��� ��'*'����һ����   // ʹ�÷ֶ���֮��˼���������
    int len = strlen(s);
    int i = -1;
    // ǰ���һ���� '.'���� �� *p == *(s + i)  �п��� ��s������ͬ���ַ�  
    //���1: s = "bbbb" p = "b*";====> *p = *(s + i)�����
    //���2: s = "abcdw"; p = ".*"; ��Ӧ���� *p = ".";���
    while (i < len && (i < 0 || *p == '.' || *p == *(s +i)))
    {
        if (isMatch(s +i + 1, p + 2))
        {
            return true;
        }
        ++i;
    }
    return false;
}


/**
 * char * s = "mississippi";
    char * p = "mis*is*p*.";
 */

// cmd ./test mississippi   mis*is*p*.
int main(int argc, char *argv[])
{
    char * s = "mississippi";
    char * p = "mis*is*p*.";
    bool find = isMatch(s, p);
    if (find)
    {
        printf("find true\n");
    }
    else
    {
        printf("not find false\n");
    }
    return EXIT_SUCCESS;
}