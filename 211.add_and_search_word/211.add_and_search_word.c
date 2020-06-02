/***********************************************************************************************
	created: 		2020-06-02

	author:			chensong

	purpose:		211.add_and_search_word
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
 * ��Ŀ: 211. ������������� - ���ݽṹ���

���һ��֧���������ֲ��������ݽṹ��

void addWord(word)
bool search(word)
search(word) �����������ֻ�������ʽ�ַ������ַ���ֻ������ĸ . �� a-z �� . ���Ա�ʾ�κ�һ����ĸ��

ʾ��:

```
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
```

˵��:

����Լ������е��ʶ�����Сд��ĸ a-z ��ɵġ�
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
 * dfs (������������㷨)
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
//            *value = true; //b.�����
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
    //ƫ����
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
//            //һ�������Ƿ��е�
            //�������Ƿ�洢�ַ���
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