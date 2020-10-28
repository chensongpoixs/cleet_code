/***********************************************************************************************
	created: 		2020-06-09

	author:			chensong

	purpose:		10.regular_expression_matching
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它。
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服。
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界。
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心。
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心。
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀。
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边。
我叫他本心猎手。他可能是和宇宙同在的级别 但是我并不害怕，我仔细回忆自己平淡的一生 寻找本心猎手的痕迹。
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来。
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来。
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
    
    bool find = isMatch(argv[1], argv[2]);
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