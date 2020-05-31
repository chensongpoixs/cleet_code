/***********************************************************************************************
	created: 		2020-05-31

	author:			chensong

	purpose:		208.trie_tree
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
 *
 * # 208. 实现 Trie (前缀树)



208. 题目：

实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

```
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true
```
 *
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
//    int m_word[128];  // ASCII
    int m_flag ;//是否一个字符串
    void*  m_next_node_ptr[27];
} Trie;
//
///** Initialize your data structure here. */
//
Trie* trieCreate()
{
      Trie *ptr = malloc(sizeof( Trie));
    if (!ptr)
    {
        printf("malloc failed\n");
        return NULL;
    }
//    ptr->m_next_node_ptr = NULL;
    ptr->m_flag = 0;
    for (int i = 0; i < 27; ++i)
    {
            ptr->m_next_node_ptr[i] = NULL;
    }
    return ptr;
}
//
///** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    if (!obj)
    {
        printf(" obj == null \n");
        return;
    }
    if (!word)
    {
        printf("word == null ptr\n");
        return;
    }
    int word_len = strlen(word)+1;;
    printf("word_len = %d\n", word_len);
    //临时变量trie tree的变量
     Trie * ptr = obj;
     Trie * temp_node_ptr  = NULL;
     char c ;
    for (int i = 0; i < word_len; ++i)
    {
        c = word[i] - 'a' < 0?0: (word[i] -'a'+1);
        if(ptr->m_next_node_ptr[ (int)c] == NULL /*-1*/)
        {
            //没有找到的情况
//            printf("insert ok i = %d\n", i);
//            ptr->m_word[(word[i])] = word[i];
//            if (ptr->m_next_node_ptr[ (int)c] != NULL )
//            {
//                printf("next i = %d, word = %c\n", i,  c);
//
//            }
            temp_node_ptr = trieCreate();
            if (!temp_node_ptr)
            {
                return;
            }
//            printf("== -1i = %d, word = %c\n", i, (word[i]));
//
// 插入下一个节点指针

            ptr->m_next_node_ptr[ (int)c] = temp_node_ptr;
            if ((i + 1) == word_len)
            {
                ptr->m_flag = 1;
                return;
            }

            //移动指针
            ptr = temp_node_ptr;
        }
        else
        {
//            printf("--->>>>>>>>next i = %d, word = %c\n", i, word[i]);
            //找到的情况
            if ((i + 1) == word_len)
            {
                ptr->m_flag = 1;
                return;
            }
            if (ptr->m_next_node_ptr[ (int)c] == NULL)
            {
                ptr->m_next_node_ptr[ (int)c] = trieCreate();
            }
            ptr = ptr->m_next_node_ptr[ (int)c];


        }


    }
}
//
///** Returns if the word is in the trie. */
int trieSearch(Trie* obj, char * word) {
    if (!obj)
    {
        printf(" obj == null \n");
        return 0;
    }
    if (!word)
    {
        printf("word == null ptr\n");
        return 0;
    }
    int word_len = strlen(word) +1;
     Trie * ptr = obj;
     Trie * temp_node_ptr  = NULL;
     char c ;
    for (int i = 0; i < word_len; ++i)
    {
        c = word[i] - 'a' < 0?0: (word[i] -'a'+1);
        //c = word[i];
        if(ptr->m_next_node_ptr[(int)c] ==  NULL /*-1*/)
        {
            //没有找到
            printf("i = %d, word_len = %d, flag = %d\n", i, word_len, ptr->m_flag);
            return 0;
        }
        else
        {
//            //找到的情况
            if ((i + 1) == word_len)
            {

                if (ptr->m_flag == 1)
                {
                    return 1;
                }

            }
            temp_node_ptr = ptr->m_next_node_ptr[(int)c];
            ptr = temp_node_ptr;

        }
    }

    return 0;
}
//
///** Returns if there is any word in the trie that starts with the given prefix. */
int  trieStartsWith(Trie* obj, char * prefix) {
    if (!obj)
    {
        printf(" obj == null \n");
        return 0;
    }
    if (!prefix)
    {
        printf("prefix == null ptr\n");
        return 0;
    }
    int prefix_len = strlen(prefix) +1;;
     Trie * ptr = obj;
     Trie * temp_node_ptr  = NULL;
     char c ;
    for (int i = 0; i < prefix_len; ++i)
    {
//        c = prefix[i];
        c = prefix[i] - 'a' < 0?0: (prefix[i] -'a'+1);
        if(ptr->m_next_node_ptr[(int)c] == NULL   && c != '\0')
        {
            //没有找到
            return 0;
        }
        else
        {
            //找到的情况
            temp_node_ptr = ptr->m_next_node_ptr[(int)c];
            ptr = temp_node_ptr;
        }
    }
    return 1;
}
static int count = 0;
//
void trieFree(Trie* obj) {
    if (!obj)
    {

        return ;
    }

     Trie * ptr = obj;
//    int i = 0;
    if (ptr)
    {
        int i ;
        for ( i = 0; i < 128; ++i)
        {
//                printf("start i = %d\n", i);
            if (ptr->m_next_node_ptr[i])
            {
                ++count;
                trieFree(ptr->m_next_node_ptr[i]);
                printf("i = %d\n", i);
                free(ptr->m_next_node_ptr[i]);
                ptr->m_next_node_ptr[i] = NULL;
                --count;
            }

        }
        if (count == 0)
        {
            free(ptr);
            ptr = NULL;
        }
        printf("end i = %d\n", i);
    }

}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/

void show(Trie * obj)
{

    if (!obj)
    {

        return ;
    }

    Trie * ptr = obj;


    if (ptr)
    {
        for (int i = 0; i < 128; ++i)
        {
            if (ptr->m_next_node_ptr[i])
            {

                show(ptr->m_next_node_ptr[i]);
//                for (int j = 0; j < 128; ++j)
                {
                    printf("i = %d\n", i);
                    //                if (ptr->m_word[j] == -1)
                    //                {
                    //                    printf("j = %d, ok ff\n", j);
                    //                }
                }
//                free(ptr->m_next_node_ptr[i]);
//                ptr->m_next_node_ptr[i] = NULL;
            }
        }
//        free(ptr);
//        ptr = NULL;
//        ptr = temp_node_ptr;
    }
//    }
}

int main(int argc, char *argv[])
{

//    ["Trie","insert","search","search","startsWith","insert","search"]
//    [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]

//    [null,null,true,true,true,null,true]
//    预期结果
//    [null,null,true,false,true,null,true]

//    Trie trie = new Trie();
//
//    trie.insert("apple");
//    trie.search("apple");   // 返回 true
//    trie.search("app");     // 返回 false
//    trie.startsWith("app"); // 返回 true
//    trie.insert("app");
//    trie.search("app");     // 返回 true
//    ["Trie","insert","search","search","startsWith","insert","search"]
//    [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]


//    ["Trie","startsWith"]
//    [[],["a"]]
    char * word = "";
    char * prefix = "app";
    Trie* obj = trieCreate();;
//    printf("obj = %p\n", obj);
//    show(obj);
    trieInsert(obj, word);
//    printf("obj = %p\n", obj);
//    show(obj);
    word = "";
     int param_2 = trieSearch(obj, word);
//    show(obj);
//    printf("obj = %p\n", obj);
    printf("param_2 = %d\n", param_2);
//    param_2 = trieSearch(obj, prefix);
//    show(obj);
//    printf("obj = %p\n", obj);
//    printf("param_2 = %d\n", param_2);
//    param_2 = trieStartsWith(obj, prefix);
//    word = "app";
//       trieInsert(obj, prefix);
//    printf("obj = %p\n", obj);
//    printf("param_2 = %d\n", param_2);
//    int param_3 = trieSearch(obj, prefix);

//    printf("param_3 = %d\n", param_3);
     trieFree(obj);
    return 0;
}


//#include <stdio.h>
//int maintest(){
//    int a = 16, b = 932, c = 100;
//    //定义一个指针数组
//    int *arr[3];// = {&a, &b, &c};//也可以不指定长度，直接写作 int *arr[]
//
//    arr[0] = &a;arr[1] = &b;arr[2] = &c;
////    //定义一个指向指针数组的指针
//    int **parr = arr;
//    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
//    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));
//    return 0;
//}