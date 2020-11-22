/***********************************************************************************************
	created: 		2020-11-19

	author:			chensong

	purpose:		648.�����滻
�ҿ��ܻ������ܶ���ˣ������ǽ���2��Ĺ��£�����д�ɹ��»��ɸ裬����ѧ���ĸ�������������??
Ȼ�󻹿�����һ����������һ�������ҵĹ�������ܻᱻ��˧����������ֻᱻ��������ں���������ĳ�������ҹ������ȫ����͸Ȼ��Ҫ������С��ס�������ϵ�ʪ�·�??
3Сʱ���������������ʵ��������ҵĹ�������Ը���򸸻���顣�Ҳ����Ѹ��������Ǵ�Խ�����������ǣ���ʼ��Ҫ�ص��Լ�������??
Ȼ���ҵ���Ӱ������ʧ���ҿ������������ˮ������ȴû���κ�ʹ�࣬�Ҳ�֪����ԭ���ҵ��ı������ˣ�������ȫ�����ԭ�򣬾���Ҫ�һ��Լ��ı���??
�����ҿ�ʼ����Ѱ�Ҹ��ָ���ʧȥ�ĵ��ˣ��ұ��һ��שͷ��һ������һ��ˮ��һ����ƣ�ȥ�����Ϊʲô��ʧȥ�Լ��ı���??
�ҷ��֣��ճ����ı��������Ļ��ڣ������ģ����ǵı��ľͻ���ʧ���յ��˸��ֺڰ�֮�����ʴ??
��һ�����ۣ������ʺͱ��ߣ�����ί����ʹ�࣬�ҿ���һֻֻ���ε��֣������ǵı��ĳ��飬�ɱΣ�͵�ߣ���Ҳ�ز������˶����??
�ҽ����������֡��������Ǻ�����ͬ�ڵļ�??�����Ҳ������£�����ϸ�����Լ�ƽ����һ??Ѱ�ұ������ֵĺۼ�??
�����Լ��Ļ��䣬һ�����ĳ�����������������֣��ҵı��ģ�����д�����ʱ�򣬻����??
��������Ȼ����������ҵ�һ�У�д��������ұ��Ļع����÷�ʽ���һ�û�ҵ��������֣��������ţ�˳�������������һ����˳�����ϣ�����������??
************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie
{
    int index; // ����ID
    struct trie** table;//ָ������
}trie;


void insert(trie * trie_ptr, char ** dictionary, int dictionarySize)
{
    if (!trie_ptr)
    {
        trie_ptr = malloc(sizeof(struct trie));
        trie_ptr->table = malloc(sizeof(struct trie *) * (256));
        for(int i = 0; i <256; ++i)
        {
            trie_ptr->table[i] = NULL;
        }
        trie_ptr->index = -1;
    }

    for (int i = 0; i < dictionarySize; ++i)
    {
        char * p = dictionary[i];
        struct trie * cur_trie = trie_ptr;
        while (*p != '\0')
        {
            if (cur_trie->table[*p] )
            {


            }
            else
            {
                //�����µĽڵ������ֵ��
                trie *  new_trie_ptr = malloc(sizeof(struct trie));
                new_trie_ptr->table = malloc(sizeof(struct trie *) * (256));
                for(int i = 0; i <256; ++i)
                {
                    trie_ptr->table[i] = NULL;
                }
                trie_ptr->index = -1;
                cur_trie->table[*p] = new_trie_ptr;
            }
            cur_trie = cur_trie->table[*p];
            ++p;
        }
        cur_trie->index = i;
    }

}


void show(trie * trie_ptr)
{
    if (!trie_ptr)
    {
        return;
    }
    for(int i = 0; i < 256; ++i)
    {
        if (trie_ptr->table[i])
        {
            printf("[i = %d ][%c]\n", i, i);
            show(trie_ptr->table[i]);
        }

    }
}

void destroy(trie * trie_ptr)
{

}

char * replaceWords(char ** dictionary, int dictionarySize, char * sentence)
{

    // for (int i = 0; i < dictionarySize; ++i)
    // {
    //     printf("i = %d, str = %s\n", i, dictionary[i]);
    // }

    trie* trie_ptr = NULL;
    insert(trie_ptr, dictionary, dictionarySize);;

    show(trie_ptr);

    return NULL;
}
int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}