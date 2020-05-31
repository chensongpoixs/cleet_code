/***********************************************************************************************
	created: 		2020-05-31

	author:			chensong

	purpose:		208.trie_tree
�ҿ��ܻ������ܶ���ˣ������ǽ���2��Ĺ��£�����д�ɹ��»��ɸ裬����ѧ���ĸ���������������
Ȼ�󻹿�����һ����������һ�������ҵĹ�������ܻᱻ��˧����������ֻᱻ��������ں���������ĳ�������ҹ������ȫ����͸Ȼ��Ҫ������С��ס�������ϵ�ʪ�·���
3Сʱ���������������ʵ��������ҵĹ�������Ը���򸸻���顣�Ҳ����Ѹ��������Ǵ�Խ�����������ǣ���ʼ��Ҫ�ص��Լ������硣
Ȼ���ҵ���Ӱ������ʧ���ҿ������������ˮ������ȴû���κ�ʹ�࣬�Ҳ�֪����ԭ���ҵ��ı������ˣ�������ȫ�����ԭ�򣬾���Ҫ�һ��Լ��ı��ġ�
�����ҿ�ʼ����Ѱ�Ҹ��ָ���ʧȥ�ĵ��ˣ��ұ��һ��שͷ��һ������һ��ˮ��һ����ƣ�ȥ�����Ϊʲô��ʧȥ�Լ��ı��ġ�
�ҷ��֣��ճ����ı��������Ļ��ڣ������ģ����ǵı��ľͻ���ʧ���յ��˸��ֺڰ�֮�����ʴ��
��һ�����ۣ������ʺͱ��ߣ�����ί����ʹ�࣬�ҿ���һֻֻ���ε��֣������ǵı��ĳ��飬�ɱΣ�͵�ߣ���Ҳ�ز������˶���ߡ�
�ҽ����������֡��������Ǻ�����ͬ�ڵļ��� �����Ҳ������£�����ϸ�����Լ�ƽ����һ�� Ѱ�ұ������ֵĺۼ���
�����Լ��Ļ��䣬һ�����ĳ�����������������֣��ҵı��ģ�����д�����ʱ�򣬻������
��������Ȼ����������ҵ�һ�У�д��������ұ��Ļع����÷�ʽ���һ�û�ҵ��������֣��������ţ�˳�������������һ����˳�����ϣ�������������
************************************************************************************************/
/**
 *
 * # 208. ʵ�� Trie (ǰ׺��)



208. ��Ŀ��

ʵ��һ�� Trie (ǰ׺��)������ insert, search, �� startsWith ������������

ʾ��:

```
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // ���� true
trie.search("app");     // ���� false
trie.startsWith("app"); // ���� true
trie.insert("app");
trie.search("app");     // ���� true
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
    int m_flag ;//�Ƿ�һ���ַ���
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
    //��ʱ����trie tree�ı���
     Trie * ptr = obj;
     Trie * temp_node_ptr  = NULL;
     char c ;
    for (int i = 0; i < word_len; ++i)
    {
        c = word[i] - 'a' < 0?0: (word[i] -'a'+1);
        if(ptr->m_next_node_ptr[ (int)c] == NULL /*-1*/)
        {
            //û���ҵ������
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
// ������һ���ڵ�ָ��

            ptr->m_next_node_ptr[ (int)c] = temp_node_ptr;
            if ((i + 1) == word_len)
            {
                ptr->m_flag = 1;
                return;
            }

            //�ƶ�ָ��
            ptr = temp_node_ptr;
        }
        else
        {
//            printf("--->>>>>>>>next i = %d, word = %c\n", i, word[i]);
            //�ҵ������
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
            //û���ҵ�
            printf("i = %d, word_len = %d, flag = %d\n", i, word_len, ptr->m_flag);
            return 0;
        }
        else
        {
//            //�ҵ������
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
            //û���ҵ�
            return 0;
        }
        else
        {
            //�ҵ������
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
//    Ԥ�ڽ��
//    [null,null,true,false,true,null,true]

//    Trie trie = new Trie();
//
//    trie.insert("apple");
//    trie.search("apple");   // ���� true
//    trie.search("app");     // ���� false
//    trie.startsWith("app"); // ���� true
//    trie.insert("app");
//    trie.search("app");     // ���� true
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
//    //����һ��ָ������
//    int *arr[3];// = {&a, &b, &c};//Ҳ���Բ�ָ�����ȣ�ֱ��д�� int *arr[]
//
//    arr[0] = &a;arr[1] = &b;arr[2] = &c;
////    //����һ��ָ��ָ�������ָ��
//    int **parr = arr;
//    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
//    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));
//    return 0;
//}