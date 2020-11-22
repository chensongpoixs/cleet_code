# 208. 实现 Trie (前缀树)
   
   
   
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
   
   
   

   
总结
本文面向中级用户。它介绍了以下内容：数据结构 Trie（前缀树）及其最常见的操作。

正文
应用
Trie (发音为 "try") 或前缀树是一种树数据结构，用于检索字符串数据集中的键。这一高效的数据结构有多种应用：

1. 自动补全
   - 谷歌的搜索建议
   - 拼写检查
2. 文字处理软件中的拼写检查
   - IP 路由 (最长前缀匹配)
3.  使用Trie树的最长前缀匹配算法，Internet 协议（IP）路由中利用转发表选择路径。
4. T9 (九宫格) 打字预测
   - T9（九宫格输入），在 20 世纪 90 年代常用于手机输入
5. 单词游戏
   - Trie 树可通过剪枝搜索空间来高效解决 Boggle 单词游戏
6.黑名单用户过滤

还有其他的数据结构，如平衡树和哈希表，使我们能够在字符串数据集中搜索单词。为什么我们还需要 Trie 树呢？尽管哈希表可以在 O(1)O(1) 时间内寻找键值，却无法高效的完成以下操作：

找到具有同一前缀的全部键值。
按词典序枚举字符串的数据集。
Trie 树优于哈希表的另一个理由是，随着哈希表大小增加，会出现大量的冲突，时间复杂度可能增加到 O(n)O(n)，其中 nn 是插入的键的数量。与哈希表相比，Trie 树在存储多个具有相同前缀的键时可以使用较少的空间。此时 Trie 树只需要 O(m)O(m) 的时间复杂度，其中 mm 为键长。而在平衡树中查找键值需要 O(m \log n)O(mlogn) 时间复杂度。

Trie 树的结点结构
Trie 树是一个有根的树，其结点具有以下字段：。

最多 RR 个指向子结点的链接，其中每个链接对应字母表数据集中的一个字母。
本文中假定 RR 为 26，小写拉丁字母的数量。
布尔字段，以指定节点是对应键的结尾还是只是键前缀。


 6. 单词 "leet" 在 Trie 树中的表示

```

typedef struct {
    int m_flag ;//是否一个字符串
    void*  m_next_node_ptr[128]; //ASCII  
} Trie;



```

Trie 树中最常见的两个操作是键的插入和查找。

向 Trie 树中插入键
我们通过搜索 Trie 树来插入一个键。我们从根开始搜索它对应于第一个键字符的链接。有两种情况：

链接存在。沿着链接移动到树的下一个子层。算法继续搜索下一个键字符。
链接不存在。创建一个新的节点，并将它与父节点的链接相连，该链接与当前的键字符相匹配。
重复以上步骤，直到到达键的最后一个字符，然后将当前节点标记为结束节点，算法完成。



 7. 向 Trie 树中插入键

``` 
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
    int word_len = strlen(word);
    printf("word_len = %d\n", word_len);
    //临时变量trie tree的变量
     Trie * ptr = obj;
     Trie * temp_node_ptr  = NULL;
     char c ;
    for (int i = 0; i < word_len; ++i)
    {
        if (!ptr)
        {
            printf("NULL i = %d\n", i);
            return;
        }
        c = word[i];
        if(ptr->m_next_node_ptr[ (int)c] == NULL /*-1*/)
        {
            //没有找到的情况
            if (ptr->m_next_node_ptr[ (int)c] != NULL )
            {
                printf("next i = %d, word = %c\n", i,  c);

            }
            if ((i + 1) == word_len)
            {
                ptr->m_flag = 1;

            }
            temp_node_ptr = trieCreate();
            if (!temp_node_ptr)
            {
                return;
            }
// 插入下一个节点指针

            ptr->m_next_node_ptr[ (int)c] = temp_node_ptr;
            //移动指针
            ptr = temp_node_ptr;
        }
        else
        {
            //找到的情况
            if ((i + 1) == word_len)
            {
                ptr->m_flag = 1;
                return;
            }
            ptr = ptr->m_next_node_ptr[ (int)c];
        }
    }
}
```

复杂度分析

时间复杂度：O(m)O(m)，其中 mm 为键长。在算法的每次迭代中，我们要么检查要么创建一个节点，直到到达键尾。只需要 mm 次操作。

空间复杂度：O(m)O(m)。最坏的情况下，新插入的键和 Trie 树中已有的键没有公共前缀。此时需要添加 mm 个结点，使用 O(m)O(m) 空间。

在 Trie 树中查找键


``` 

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
    int word_len = strlen(word);
     Trie * ptr = obj;
     Trie * temp_node_ptr  = NULL;
     char c ;
    for (int i = 0; i < word_len; ++i)
    {
        if (!ptr)
        {
            return 0;
        }
        c = word[i];
        if(ptr->m_next_node_ptr[(int)c] ==  NULL /*-1*/)
        {
            //没有找到
//            printf("i = %d, word_len = %d, flag = %d\n", i, word_len, ptr->m_flag);
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

```

每个键在 trie 中表示为从根到内部节点或叶的路径。我们用第一个键字符从根开始，。检查当前节点中与键字符对应的链接。有两种情况：

存在链接。我们移动到该链接后面路径中的下一个节点，并继续搜索下一个键字符。
不存在链接。若已无键字符，且当前结点标记为 m_flag，则返回 true。否则有两种可能，均返回 false :
还有键字符剩余，但无法跟随 Trie 树的键路径，找不到键。
没有键字符剩余，但当前结点没有标记为 m_flag。也就是说，待查找键只是Trie树中另一个键的前缀。

复杂度分析

时间复杂度 : O(m)O(m)。算法的每一步均搜索下一个键字符。最坏的情况下需要 mm 次操作。
空间复杂度 : O(1)O(1)。
查找 Trie 树中的键前缀
该方法与在 Trie 树中搜索键时使用的方法非常相似。我们从根遍历 Trie 树，直到键前缀中没有字符，或者无法用当前的键字符继续 Trie 中的路径。与上面提到的“搜索键”算法唯一的区别是，到达键前缀的末尾时，总是返回 true。我们不需要考虑当前 Trie 节点是否用 “isend” 标记，因为我们搜索的是键的前缀，而不是整个键。

复杂度分析

时间复杂度 : O(m)O(m)。
空间复杂度 : O(1)O(1)。