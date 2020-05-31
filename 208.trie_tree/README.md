# 208. ʵ�� Trie (ǰ׺��)
   
   
   
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
   
   
   

   
�ܽ�
���������м��û������������������ݣ����ݽṹ Trie��ǰ׺������������Ĳ�����

����
Ӧ��
Trie (����Ϊ "try") ��ǰ׺����һ�������ݽṹ�����ڼ����ַ������ݼ��еļ�����һ��Ч�����ݽṹ�ж���Ӧ�ã�

1. �Զ���ȫ
   - �ȸ����������
   - ƴд���
2. ���ִ�������е�ƴд���
   - IP ·�� (�ǰ׺ƥ��)
3.  ʹ��Trie�����ǰ׺ƥ���㷨��Internet Э�飨IP��·��������ת����ѡ��·����
4. T9 (�Ź���) ����Ԥ��
   - T9���Ź������룩���� 20 ���� 90 ����������ֻ�����
5. ������Ϸ
   - Trie ����ͨ����֦�����ռ�����Ч��� Boggle ������Ϸ
6.�������û�����

�������������ݽṹ����ƽ�����͹�ϣ��ʹ�����ܹ����ַ������ݼ����������ʡ�Ϊʲô���ǻ���Ҫ Trie ���أ����ܹ�ϣ������� O(1)O(1) ʱ����Ѱ�Ҽ�ֵ��ȴ�޷���Ч��������²�����

�ҵ�����ͬһǰ׺��ȫ����ֵ��
���ʵ���ö���ַ��������ݼ���
Trie �����ڹ�ϣ�����һ�������ǣ����Ź�ϣ���С���ӣ�����ִ����ĳ�ͻ��ʱ�临�Ӷȿ������ӵ� O(n)O(n)������ nn �ǲ���ļ������������ϣ����ȣ�Trie ���ڴ洢���������ͬǰ׺�ļ�ʱ����ʹ�ý��ٵĿռ䡣��ʱ Trie ��ֻ��Ҫ O(m)O(m) ��ʱ�临�Ӷȣ����� mm Ϊ����������ƽ�����в��Ҽ�ֵ��Ҫ O(m \log n)O(mlogn) ʱ�临�Ӷȡ�

Trie ���Ľ��ṹ
Trie ����һ���и�������������������ֶΣ���

��� RR ��ָ���ӽ������ӣ�����ÿ�����Ӷ�Ӧ��ĸ�����ݼ��е�һ����ĸ��
�����мٶ� RR Ϊ 26��Сд������ĸ��������
�����ֶΣ���ָ���ڵ��Ƕ�Ӧ���Ľ�β����ֻ�Ǽ�ǰ׺��


 6. ���� "leet" �� Trie ���еı�ʾ

```

typedef struct {
    int m_flag ;//�Ƿ�һ���ַ���
    void*  m_next_node_ptr[128]; //ASCII  
} Trie;



```

Trie ������������������Ǽ��Ĳ���Ͳ��ҡ�

�� Trie ���в����
����ͨ������ Trie ��������һ���������ǴӸ���ʼ��������Ӧ�ڵ�һ�����ַ������ӡ������������

���Ӵ��ڡ����������ƶ���������һ���Ӳ㡣�㷨����������һ�����ַ���
���Ӳ����ڡ�����һ���µĽڵ㣬�������븸�ڵ�������������������뵱ǰ�ļ��ַ���ƥ�䡣
�ظ����ϲ��裬ֱ������������һ���ַ���Ȼ�󽫵�ǰ�ڵ���Ϊ�����ڵ㣬�㷨��ɡ�



 7. �� Trie ���в����

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
    //��ʱ����trie tree�ı���
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
            //û���ҵ������
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
// ������һ���ڵ�ָ��

            ptr->m_next_node_ptr[ (int)c] = temp_node_ptr;
            //�ƶ�ָ��
            ptr = temp_node_ptr;
        }
        else
        {
            //�ҵ������
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

���Ӷȷ���

ʱ�临�Ӷȣ�O(m)O(m)������ mm Ϊ���������㷨��ÿ�ε����У�����Ҫô���Ҫô����һ���ڵ㣬ֱ�������β��ֻ��Ҫ mm �β�����

�ռ临�Ӷȣ�O(m)O(m)���������£��²���ļ��� Trie �������еļ�û�й���ǰ׺����ʱ��Ҫ��� mm ����㣬ʹ�� O(m)O(m) �ռ䡣

�� Trie ���в��Ҽ�


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
            //û���ҵ�
//            printf("i = %d, word_len = %d, flag = %d\n", i, word_len, ptr->m_flag);
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

```

ÿ������ trie �б�ʾΪ�Ӹ����ڲ��ڵ��Ҷ��·���������õ�һ�����ַ��Ӹ���ʼ������鵱ǰ�ڵ�������ַ���Ӧ�����ӡ������������

�������ӡ������ƶ��������Ӻ���·���е���һ���ڵ㣬������������һ�����ַ���
���������ӡ������޼��ַ����ҵ�ǰ�����Ϊ m_flag���򷵻� true�����������ֿ��ܣ������� false :
���м��ַ�ʣ�࣬���޷����� Trie ���ļ�·�����Ҳ�������
û�м��ַ�ʣ�࣬����ǰ���û�б��Ϊ m_flag��Ҳ����˵�������Ҽ�ֻ��Trie������һ������ǰ׺��

���Ӷȷ���

ʱ�临�Ӷ� : O(m)O(m)���㷨��ÿһ����������һ�����ַ�������������Ҫ mm �β�����
�ռ临�Ӷ� : O(1)O(1)��
���� Trie ���еļ�ǰ׺
�÷������� Trie ����������ʱʹ�õķ����ǳ����ơ����ǴӸ����� Trie ����ֱ����ǰ׺��û���ַ��������޷��õ�ǰ�ļ��ַ����� Trie �е�·�����������ᵽ�ġ����������㷨Ψһ�������ǣ������ǰ׺��ĩβʱ�����Ƿ��� true�����ǲ���Ҫ���ǵ�ǰ Trie �ڵ��Ƿ��� ��isend�� ��ǣ���Ϊ�����������Ǽ���ǰ׺����������������

���Ӷȷ���

ʱ�临�Ӷ� : O(m)O(m)��
�ռ临�Ӷ� : O(1)O(1)��