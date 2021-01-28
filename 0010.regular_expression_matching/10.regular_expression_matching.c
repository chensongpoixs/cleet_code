/***********************************************************************************************
	created: 		2020-06-09

	author:			chensong

	purpose:		10.regular_expression_matching

************************************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 10. 正则表达式匹配
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
通过次数80,332提交次数285,022

 */

typedef int bool;
#define  true 1
#define  false 0

bool isMatch(char * s, char * p)
{
    //判断是否空字符
    if (*p == '\0')
    {
        return *s == '\0';
    }
    // p第二字符一定不是* 才会走下面的步骤  不是'*'走这一步骤判断
    // 情况 1: s = "abwd"; p = "a";
    // 情况 2: s = "abwd"; p = "."; 
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
    // 如果当前p的字符串 是'*'走这一步骤   // 使用分而治之的思想来整理的
    int len = strlen(s);
    int i = -1;
    // 前面第一个是 '.'或者 和 *p == *(s + i)  有可能 在s中有相同的字符  
    //情况1: s = "bbbb" p = "b*";====> *p = *(s + i)的情况
    //情况2: s = "abcdw"; p = ".*"; 对应的是 *p = ".";情况
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