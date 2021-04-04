/***********************************************************************************************
	created: 		2021-04-04

	author:			chensong

	purpose:		������--�� Ӧ�ó��� ip��ַ  mask ����  ip����λ
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
#include  <stdlib.h>
#include  <string.h>
#include <assert.h>

typedef unsigned int	uint32;
typedef signed int		int32;

/**
 * Ĭ�ϵ�ַ
 */
#define default_ip "127.0.0.1"

// ������ Ӧ�ó���ip��ַӳ��
struct cradix_tree_node
{
    struct cradix_tree * left;
    struct cradix_tree * right;
    char * value; //ʵ�ʵ�ip����
}cradix_tree;

struct cradix_tree
{
    struct cradix_tree_node * root;
    uint32  size;
};


/**
 * ����������ip�ĵ�ַӳ���ϵ
 * @param tree_ptr
 * @param key
 * @param mask
 * @param value
 * @return
 */
void * cradix_tree_insert(struct cradix_tree * tree_ptr, uint32 key, uint32 mask, void * value)
{
    assert(tree_ptr != NULL);
    if (!tree_ptr)
    {
        return NULL;
    }

    struct cradix_tree_node * cur_node = tree_ptr->root;
    struct cradix_tree_node * next_node = tree_ptr->root;


    //uint32 mask = 0;
    uint32 bit = 0x80000000;
    while (bit & mask)
    {
        //�ҵ����ʵ�λ�ò���
        if (bit & key)
        {
            next_node = (struct cradix_tree_node *)cur_node->right;
        }
        else
        {
            next_node = (struct cradix_tree_node *)cur_node->left;
        }
        if (!next_node)
        {
            break;
        }
        cur_node = next_node;
        bit >>= 1; //��λ
    }

    if (next_node)
    {
        if (cur_node->value)
        {
            cur_node->value = value;
            return next_node;
        }

        cur_node->value = value;
        return cur_node;
    }

    while (bit & mask)
    {
        next_node = malloc(sizeof(struct cradix_tree_node));
        assert(next_node != NULL);

        {
            next_node->left = NULL;
            next_node->right = NULL;
            next_node->value = NULL;
        }
        if (bit & key)
        {
            cur_node->right = (void *)next_node;
        }
        else
        {
            cur_node->left = (void *)next_node;
        }
        bit >>= 1;
        cur_node = next_node;
        next_node = NULL;
    }

    if (cur_node)
    {
        cur_node->value = value;
    }
    return cur_node;
}

/**
 * ����������
 * Ԥ�ȷ���A���ַ����ǰ8bitλ
 * @return
 */
struct cradix_tree * create_radix_tree()
{
    struct cradix_tree * tree_ptr = malloc(sizeof(struct cradix_tree));
    assert(tree_ptr != NULL);
    if (!tree_ptr)
    {
        return  NULL;
    }

    tree_ptr->root = NULL;
    tree_ptr->size = 8;
    tree_ptr->root = malloc(sizeof(struct cradix_tree_node));
    assert(tree_ptr->root != NULL);
    if(!tree_ptr->root)
    {
        return NULL;
    }
    {
        tree_ptr->root->left = NULL;
        tree_ptr->root->right = NULL;
        tree_ptr->root->value = NULL;
    }


    //�����������߶�Ϊ 32Ϊip��ַ�����߶�

    uint32 inc = 0x80000000; // ��Ӧ32λ 1000 0000 0000 0000 0000 0000  0000 0000
    uint32 key = 0;
    uint32 mask = 0; //����

    uint32 preallocate = tree_ptr->size; //Ԥ�ȷ���A���ַ����ǰ8bitλ
    while (preallocate--)
    {
        key = 0;
        mask >>= 1;  // ip ��ַ���� �ǲ�ͬ��
        mask |= 0x80000000;
        // 1000 0000 0000 0000 0000 0000 0000 0000  0000 0000
        /**
         *   ip������ A���ַ[8bit]  B���ַ[16bit] C���ַ[24bit] D,E���͵�ַ������
         *   | ��   | ǰ׺����   |  ǰ׺
         *   |A���ַ|  8λ      | 0xxxxxxx                                              |
         *   |B���ַ| 16λ      | 10xxxxxx   xxxxxxxx                                   |
         *   |C���ַ| 24λ      | 110xxxxx   xxxxxxxx   xxxxxxxx                        |
         *   |D���ַ| ������     | 1110xxxx   xxxxxxxx   xxxxxxxx     xxxxxxxx           |
         *   |E���ַ| ������     | 11110xxx   xxxxxxxx   xxxxxxxx     xxxxxxxx           |
         * mask ��Ӧ ���� A���ַ��ǰ8λbitλ��Ĭ�ϵ�32λ��1�ڴ����У�
            mask = 2147483648 ==> 1000 0000 0000 0000 0000 0000 0000 0000
            mask = 3221225472 ==> 1100 0000 0000 0000 0000 0000 0000 0000
            mask = 3758096384 ==> 1110 0000 0000 0000 0000 0000 0000 0000
            mask = 4026531840 ==> 1111 0000 0000 0000 0000 0000 0000 0000
            mask = 4160749568 ==> 1111 1000 0000 0000 0000 0000 0000 0000
            mask = 4227858432 ==> 1111 1100 0000 0000 0000 0000 0000 0000
            mask = 4261412864 ==> 1111 1110 0000 0000 0000 0000 0000 0000
            mask = 4278190080 ==> 1111 1111 0000 0000 0000 0000 0000 0000
            mask = 4286578688 ==> 1111 1111 1000 0000 0000 0000 0000 0000
         */
        //���������Ķ������±���
        do
        {
            //���뵱ǰ�ڵ������
            cradix_tree_insert(tree_ptr, key, mask, NULL);
            //��߿���������  �ͼӵ��ڴ���� �ͱ��'0'��
            key += inc; // ����  == [0x80000000 + 0x80000000] = [0x100000000]  �����޷���int���ͷŲ�������������� ���� [0x00000000] ��λ���
        } while (key);
        inc >>= 1;
    }

    return tree_ptr;
}

/**
 * �������Ĳ���O(logn)
 * @param tree_ptr
 * @param key
 * @return
 */
char * cradix_tree_find(struct cradix_tree * tree_ptr, uint32 key)
{
    assert(tree_ptr != NULL);
    if (!tree_ptr)
    {
        return NULL;
    }
    uint32 bit = 0x80000000;
    struct cradix_tree_node * cur_node = tree_ptr->root;
    void * ptr = NULL;
    while (cur_node)
    {
        if (cur_node->value)
        {
            ptr = cur_node->value;
        }
        if (key & bit)
        {
            cur_node = (struct cradix_tree_node *)cur_node->right;
        }
        else
        {
            cur_node = (struct cradix_tree_node *)cur_node->left;
        }
        bit >>= 1;
    }
    if (!ptr)
    {
        return default_ip;
    }
    return ptr;
}

/**
 * �ݹ��ͷŻ������Ľڵ���ڴ�
 * @param tree_ptr
 */
void cradix_tree_node_destroy(struct cradix_tree_node *tree_ptr)
{
    if (!tree_ptr)
    {
        return;
    }
    cradix_tree_node_destroy((struct cradix_tree_node *)tree_ptr->left);
    if (tree_ptr->left)
    {
        free(tree_ptr->left);
        tree_ptr->left = NULL;
    }
    cradix_tree_node_destroy((struct cradix_tree_node *)tree_ptr->right);
    if (tree_ptr->right)
    {
        free(tree_ptr->right);
        tree_ptr->right = NULL;
    }
}

/**
 * �ͷŻ������ڴ�
 * @param tree_ptr
 */
void cradix_tree_destroy(struct cradix_tree** tree_ptr)
{
    assert(tree_ptr != NULL);
    if (!tree_ptr)
    {
        return ;
    }

    cradix_tree_node_destroy((struct cradix_tree_node *)(*tree_ptr)->root);

    if ((*tree_ptr))
    {
        if ((*tree_ptr)->root)
        {
            free((*tree_ptr)->root);
            (*tree_ptr)->root = NULL;
        }
        free((*tree_ptr));
        (*tree_ptr) = NULL;

    }
}

/**
 * �������ݽṹ
 */
struct ip_proxy {
    uint32  ip; // ip-> uint32
    uint32  mask; // ����
    char *  value; //ӳ�������
};

/**2^0 = 1;
 * 2^1 = 2;
 * 2^2 = 4
 * 2^3 = 8
 * 2^4 = 16
 * 2^5 = 32
 * 2^6 = 64
 * 2^7 = 128
 *
 *
 * ��������
 *
 */
struct ip_proxy ip_data[] =
{         // 128 + 64 + 32 +15 = 96+15 +128 = 111+128 = 239  === 255 - 16 = 239
        { 4009754624/*1110 1111 0000 0000 0000 0000 0000 0000 == 239.0.0.0*/,  4278190080 /*1111 1111 0000 0000 0000 0000 0000 0000 === 255.0.0.0*/, "192.168.1.90"},
        { 4093640704,  4278190080, "192.168.1.91"},
        { 4160749568,  4278190080, "192.168.1.93"},
        { 4244635648, 4278190080, "wangyang"},
        { 3841982464, 4278190080, "shanghui"},
        { 2566914048, 4278190080, "beijing"}
};



//void show(struct cradix_tree_node * tree)
//{
//    if (!tree)
//    {
//        return;
//    }
//    printf(" vlaue %s\n", tree->value);
//    show(tree->left);
//    show(tree->right);
//}



int main(int argc, char *argv[])
{

    struct cradix_tree * tree_ptr = create_radix_tree();
    if (!tree_ptr)
    {
        return -1;
    }

    for (int i = 0; i < (sizeof(ip_data) / sizeof(struct ip_proxy)); ++i)
    {
        cradix_tree_insert(tree_ptr, ip_data[i].ip, ip_data[i].mask, ip_data[i].value);
    }
    ///show(tree_ptr->root);
    for (int i = 0; i < (sizeof(ip_data) / sizeof(struct ip_proxy)); ++i)
    {
        printf("ip mask  = %u, ip_proxy = %s, new_ip_proxy = %s\n", ip_data[i].ip, ip_data[i].value, cradix_tree_find(tree_ptr, ip_data[i].ip) );
    }
    //Ĭ�ϴ���ip��ַ
    printf("not ip mask  = %u, ip_proxy = %s, new_ip_proxy = %s\n", 23432, "", cradix_tree_find(tree_ptr, 23432) );
    cradix_tree_destroy(&tree_ptr);
    return EXIT_SUCCESS;
}