/***********************************************************************************************
	created: 		2020-06-02

	author:			chensong

	purpose:		211.add_and_search_word
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
/**
 * 题目: 211. 添加与搜索单词 - 数据结构设计

设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

```
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
```

说明:

你可以假设所有单词都是由小写字母 a-z 组成的。
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef  int bool;
#define  false 0
#define  true 1

typedef struct
{
    char m_flag;
    void * m_next_word_ptr[27];
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate()
{
    WordDictionary * word_ptr = malloc(sizeof(*word_ptr));
    if (!word_ptr)
    {
        return NULL;
    }
    memset(word_ptr->m_next_word_ptr , 0, sizeof(word_ptr->m_next_word_ptr));
    return word_ptr;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    if (!obj)
    {
        return;
    }
    if (!word)
    {
        return;
    }
    char c;
    WordDictionary * ptr = obj;
    WordDictionary * temp_word_ptr = NULL;
//    int index = 0;
    while (ptr)
    {
        c = *word - 'a' <0?0 :(*word -'a' +1);
        // c = word[index] - 'a' <0?0 :(word[index] -'a' +1);
//        printf("c = %d\n", (int)c);
        if (ptr->m_next_word_ptr[(int)c] == NULL)
        {
            if (*(word +1) == '\0')
            {
                ptr->m_flag = 1;
            }
            temp_word_ptr = wordDictionaryCreate();
            if (!temp_word_ptr)
            {
                return;
            }

            ptr->m_next_word_ptr[(int)c] = temp_word_ptr;
            ptr = temp_word_ptr;
        }
        else
        {
            if ( *(word +1) == '\0')
            {
                ptr->m_flag = 1;

            }
//            if ( *(word +1) == '\0')
//            {
//                ptr->m_flag = 1;
////                return;
//            }
            ptr = ptr->m_next_word_ptr[(int)c];
        }
        if (*(word +1) == '\0')
        {

            return;
            //   ptr->m_flag = 1;
        }
        *word++;


    }
}



/**
 * dfs (深度优先搜索算法)
 * @param obj
 * @param word
 * @param index
 * @param value
 */
void dfs(WordDictionary * obj, char *word, bool *  value)
{
    if (!obj)
    {
//        if (word[0] == '\0')
//        {
//            *value = true; //b.的情况
//        }
//        printf("obj == null\n");
        return;
    }
    if (!word)
    {
//        printf("word == null\n");
        return;
    }
    if (word[0] == '\0')
    {
//        if (obj->m_flag == 1)
        {
//            printf("0 == 'o\n");
//            *value = true;
        }
//        printf("000000 word [0]\n");
        return ;
    }
    //偏移量
    char * word_ptr = word ;
    char c ;
    while ( word_ptr && obj)
    {

        if (*word_ptr == '.'/*0X2E*/ /*'.'*/)
        {
//            printf("..\n");
            for (int i = 0; i < 27; ++i)
            {
                if (*(word_ptr +1) == '\0' && obj->m_flag == 1)
                {
                    *value = true;
                    printf("word \n");
                           return;;
                }
                dfs(obj->m_next_word_ptr[i], word_ptr+1, value);

            }
            return;
        }
        else
        {
//            //一个对象是否有的
            //数组中是否存储字符了
            c = *word_ptr - 'a' < 0 ? 0: *word_ptr -'a'+1;
            if (obj->m_next_word_ptr[(int)c] == NULL)
            {
                printf("next = %d\n", c);
                return;
            }
            if (*(word_ptr +1) == '\0' && obj->m_flag == 1)
            {
                printf("word ptr = %d\n", c);
                *value = true;
                return;;
            }
            obj = obj->m_next_word_ptr[(int)c];
        }
        *word_ptr++;
//        ++index;
    }

}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    if (!obj)
    {
        return false;
    }
    if (!word)
    {
        return false;
    }

    bool value = false;

    dfs(obj, word, &value);

    return  value;

}

void wordDictionaryFree(WordDictionary* obj)
{
    if(!obj)
    {
        return;
    }

    for (int i = 0; i < 27; ++i)
    {
        if (obj->m_next_word_ptr[i])
        {
            wordDictionaryFree(obj->m_next_word_ptr[i]);
        }
    }
    free(obj);
    obj = NULL;

}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);

 * bool param_2 = wordDictionarySearch(obj, word);

 * wordDictionaryFree(obj);
*/

void show(WordDictionary* obj, int count)
{
    if(!obj)
    {
        return;
    }
    ++count;
    for (int i = 0; i < 27; ++i)
    {

        if (obj->m_next_word_ptr[i])
        {
            printf("count = %d, index = %d\n", count, i);
            show(obj->m_next_word_ptr[i], count);

        }
    }

//    printf("i = %d, ");

}


int main(int argc, char *argv[])
{
//    char * word = "bad";
    char * word = "a";
//    ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
//    [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]

//    ["WordDictionary","addWord","addWord","search","search","search","search","search","search"]
//    [[],["a"],["a"],["."],["a"],["aa"],["a"],[".a"],["a."]]
    WordDictionary* obj = wordDictionaryCreate();
    int  count = 0;
    wordDictionaryAddWord(obj, word);
    printf("add word\n");
//    show(obj, count);
//    word = "dad";
//    wordDictionaryAddWord(obj, word);
//    printf("add word\n");
    count = 0;
    show(obj, count);
//    word = "pad";
//    wordDictionaryAddWord(obj, word);
//    printf("add word\n");
//    count = 0;
//    show(obj, count);
//    word = "bad";
//    wordDictionaryAddWord(obj, word);
//    printf("add word\n");
//    count = 0;
//    show(obj, count);
//    word = ".ad";
    word = ".a";
    bool param_2 = wordDictionarySearch(obj, word);
    printf("param_2 = %d\n", param_2);
    word = "b..";
    param_2 = wordDictionarySearch(obj, word);
    printf("param_2 = %d\n", param_2);
    wordDictionaryFree(obj);
    return EXIT_SUCCESS;
}