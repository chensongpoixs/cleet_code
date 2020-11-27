/***********************************************************************************************
	created: 		2020-11-27

	author:			chensong

	purpose:		720. 词典中最长的单词
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它??
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服??
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界??
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心??
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心??
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀??
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边??
我叫他本心猎手。他可能是和宇宙同在的级??但是我并不害怕，我仔细回忆自己平淡的一??寻找本心猎手的痕迹??
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来??
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来??
************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct trie_tree
{
    int flag; //1是结束标记
    struct trie_tree** table;
}trie_tree;

void insert(struct trie_tree *trie_ptr, char * word)
{
    if (!trie_ptr || !word )
    {
        return;
    }
    if (strlen(word) <= 0)
    {
        return;
    }
    char *p = word;
    struct trie_tree *cur_trie_tree_ptr = trie_ptr;
    while (*p != '\0')
    {
        if (!cur_trie_tree_ptr->table[*p - 'a'])
        {
            struct trie_tree * new_trie_tree_ptr = malloc(sizeof(struct trie_tree));
            new_trie_tree_ptr->flag = 0;
            new_trie_tree_ptr->table = malloc(sizeof(struct trie_tree*) * 26);
            for (int i = 0; i < 26; ++i)
            {
                new_trie_tree_ptr->table[i] = NULL;
            }
            cur_trie_tree_ptr->table[*p -'a'] = new_trie_tree_ptr;
        }
        cur_trie_tree_ptr = cur_trie_tree_ptr->table[*p - 'a'];
        ++p;
    }
    if (cur_trie_tree_ptr)
    {
        cur_trie_tree_ptr->flag = 1;
    }
}
/**
* 深度遍历
*/
void dfs(struct trie_tree * trie_ptr, char *s, int index, int size)
{
    if (!trie_ptr)
    {
        return;
    }
    char *old_ptr = malloc(sizeof(char) * size);
    memset(old_ptr, 0, sizeof(char) * size);
    char *new_ptr = malloc(sizeof(char) * size);
    memset(new_ptr, 0, sizeof(char) * size);
    for (int i = 25; i >= 0; --i)
    {
        if (trie_ptr->table[i])
        {
            if(trie_ptr->table[i]->flag == 1)
            {
                new_ptr[0] = 'a' +i;
                new_ptr[1] = '\0';
                dfs(trie_ptr->table[i], new_ptr, 1, size);
                if (strlen(old_ptr) <= strlen(new_ptr))
                {
                    memcpy(old_ptr, new_ptr, strlen(new_ptr));
                }
            }

        }
    }
    char * p = old_ptr;
    while (*p != '\0')
    {
        s[index++] = *p++;
    }
    s[index] = '\0';
    free(old_ptr);
    free(new_ptr);
}

char * find_word(struct trie_tree * trie_ptr, int size)
{
    if (!trie_ptr)
    {
        return NULL;
    }
    char *old_ptr = malloc(sizeof(char) * size);
    memset(old_ptr, 0, sizeof(char) * size);
    char *new_ptr = malloc(sizeof(char) * size);
    memset(new_ptr, 0, sizeof(char) * size);
    for (int i = 25; i >= 0; --i)
    {
        if (trie_ptr->table[i])
        {
            if(trie_ptr->table[i]->flag == 1)
            {
                new_ptr[0] = 'a' +i;
                new_ptr[1] = '\0';
                dfs(trie_ptr->table[i], new_ptr, 1, size);

                if (strlen(old_ptr) <= strlen(new_ptr))
                {
                    memcpy(old_ptr, new_ptr, strlen(new_ptr));
                }
            }
        }
    }

    free(new_ptr);
    return old_ptr;
}
void show(struct trie_tree * trie_ptr)
{
    if (!trie_ptr)
    {
        return;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (trie_ptr->table[i])
        {
            show(trie_ptr->table[i]);
        }
    }
}

void destroy(struct trie_tree * trie_ptr)
{
    if (!trie_ptr)
    {
        return;
    }
    for(int i = 0; i < 26; ++i)
    {
        if(trie_ptr->table[i])
        {
            destroy(trie_ptr->table[i]);
        }
    }
    free(trie_ptr);
    trie_ptr = NULL;
}


char * longestWord(char ** words, int wordsSize)
{
    if (!words || wordsSize <= 0)
    {
        return NULL;
    }
    struct trie_tree * trie_tree_ptr =  malloc(sizeof(struct trie_tree));
    trie_tree_ptr->flag = 0;
    trie_tree_ptr->table = malloc(sizeof(struct trie_tree*) * 26);
    for (int i = 0; i < 26; ++i)
    {
        trie_tree_ptr->table[i] = NULL;
    }

    int max_str_length = 0;
    for (int i = 0; i < wordsSize; ++i)
    {
        if (max_str_length < strlen(words[i]))
        {
            max_str_length = strlen(words[i]);
        }
        insert(trie_tree_ptr, words[i]);
    }

    show(trie_tree_ptr);

    char* ret = find_word(trie_tree_ptr, max_str_length+1);
    destroy(trie_tree_ptr);
    return ret;
}


int main(int argc, char *argv[])
{
    char *words[] = { "a", "banana", "app", "appl", "ap", "apply", "apple"};
    printf("[\"a\", \"banana\", \"app\", \"appl\", \"ap\", \"apply\", \"apple\"]\n");
    char * output = longestWord(words, 7);
    printf("output = %s\n", output);
    if (output)
    {
        free(output);
    }
    return 0;
}