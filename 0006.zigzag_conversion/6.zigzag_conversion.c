/***********************************************************************************************
created: 		2020-06-06

author:			chensong

purpose:		6.zigzag_conversion

************************************************************************************************/

/**
 * 6. Z ���α任
��һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "LEETCODEISHIRING" ����Ϊ 3 ʱ���������£�

L   C   I   R
E T O E S I I G
E   D   H   N
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);
ʾ�� 1:

����: s = "LEETCODEISHIRING", numRows = 3
���: "LCIRETOESIIGEDHN"
ʾ�� 2:

����: s = "LEETCODEISHIRING", numRows = 4
���: "LDREOEIIECIHNTSG"
����:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
ͨ������133,942�ύ����279,121
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct clist
{
    char m_data;
    int  m_index;
    void * m_next_ptr;
    void * m_tail_ptr;
}clist;


void free_list(clist * ptr)
{
    clist * temp_ptr = NULL;
    clist * next_ptr = ptr;
    int index = 0;
    while (next_ptr)
    {
        temp_ptr = next_ptr->m_next_ptr;
        printf("index = %d\n", next_ptr->m_index);
       if (index > 0)
       {
           free(next_ptr);
       }
       ++index;
        next_ptr = NULL;
        next_ptr = temp_ptr;
    }
}

/**
 *
 * @param s
 * @param numRows
 * @return
 */
char * convert(char * s, int numRows)
{
    //�ٽ�����
    if (strlen(s) < 3 || !s || numRows < 2 || numRows >= strlen(s))
    {
        return s;
    }
    clist* m_list = malloc(sizeof(struct clist) * numRows);
    if (!m_list)
    {
        printf("alloc failed !!!\n");
        return NULL;
    }
    for (int i = 0; i < numRows; ++i)
    {
        m_list[i].m_next_ptr = NULL;
        m_list[i].m_tail_ptr = &m_list[i];
    }
    int index = 0;
    int rows = 0;
    struct clist * data_ptr = NULL;
    while (index < strlen(s) )
    {
        if (index >= numRows)
        {
            clist * temp_ptr = malloc(sizeof(struct clist));
            if (!temp_ptr)
            {
                printf("alloc failed !!!\n");
                return NULL;
            }
            temp_ptr->m_next_ptr = NULL;
            temp_ptr->m_tail_ptr = temp_ptr;

            data_ptr = (struct clist *)m_list[rows].m_tail_ptr;
            if (data_ptr)
            {
                data_ptr->m_next_ptr = temp_ptr;
                data_ptr->m_tail_ptr = temp_ptr;
            }
            m_list[rows].m_tail_ptr = temp_ptr;
        }
        data_ptr = (struct clist *)(m_list[rows].m_tail_ptr);
        if (data_ptr)
        {
            data_ptr->m_data = s[index];
            data_ptr->m_index = index;
        }
//        ++index;
//        // ����һ����������
        if (rows+1  == numRows && numRows>2) //С�ڶ���ʱ ������
        {
            --rows;  //������� numrows -1 ��ʼ����
            ++index;
            while (index < strlen(s)  && rows > 0)
            {
                clist * temp_ptr = malloc(sizeof(struct clist));
                if (!temp_ptr)
                {
                    printf("alloc failed !!!\n");
                    return NULL;
                }
                temp_ptr->m_next_ptr = NULL;
                temp_ptr->m_tail_ptr = temp_ptr;
                {
                    data_ptr = (struct clist *)m_list[rows].m_tail_ptr;
                    if (data_ptr)
                    {
                        printf("alloc = %p[row = %d]\n", temp_ptr, rows);
                        data_ptr->m_next_ptr = temp_ptr;
                        data_ptr->m_tail_ptr = temp_ptr;
                    }
                    m_list[rows].m_tail_ptr = temp_ptr;
                }

                data_ptr = (struct clist *)(m_list[rows].m_tail_ptr);
                if (data_ptr)
                {
                    data_ptr->m_data = s[index];
                    data_ptr->m_index = index;
                }
                ++index;
                --rows;
            }
        }
        else
        {
            ++index;
            ++rows;
            if (rows == numRows)
            {
                rows = 0;
            }
        }
    }
    char  * zigzog = malloc(strlen(s) + 1);
    if (!zigzog)
    {
        return NULL;
    }
    clist * new_temp = NULL;
    clist * next_ptr = NULL;
    index = 0;
    for (int i = 0; i < numRows; ++i)
    {
        next_ptr = &m_list[i];
        while (next_ptr)
        {
            printf("index = %d, i = %d, list_index = %d, node_ptr =%p\n", index, i, next_ptr->m_index, next_ptr);
            new_temp = next_ptr->m_next_ptr;
            zigzog[index++] = next_ptr->m_data;
            next_ptr = new_temp;
        }
    }
    printf("convert = %s\n", zigzog);
    for (int i = 0; i < numRows; ++i)
    {
        free_list(&m_list[i]);
    }
    free(m_list); //ָ��������ͷ� �е�����
//    zigzog[strlen(s) + 1] = '\0'; //�ڴ������
    zigzog[strlen(s) ] = '\0';
    return zigzog;

}




/**
 *ȡģ
 * @param s
 * @param numRows
 * @return
 */
char * convertmod(char * s, int numRows)
{
    //�ٽ�����
    if (strlen(s) < 3 || !s || numRows < 2 || numRows >= strlen(s))
    {
        return s;
    }
    clist* m_list = malloc(sizeof(struct clist) * numRows);
    if (!m_list)
    {
        printf("alloc failed !!!\n");
        return NULL;
    }
    for (int i = 0; i < numRows; ++i)
    {
        m_list[i].m_next_ptr = NULL;
        m_list[i].m_tail_ptr = &m_list[i];
    }
    int index = 0;
//    int rows = 0;
    struct clist * data_ptr = NULL;
    while (index < strlen(s) )
    {
        int mod = 0;
        int num = (index +1) % ((numRows* 2) -2) ;
        if (num == 0)
        {
            mod = 1;
        }
        else
        {
            //������Ϊ �����inedx +1 ����Ҫȥ�� 1  ���������
            // 1:һ���Ǵ���numRowsʱ��Ҫ��1
            // 2:С��numRowsҪ��ȥ1
             mod =  num >numRows ? ((numRows* 2) -2) - num +1 : num-1; //TODO@chensong 2020-06-06 �������У�����
        }

        //((num > numRows )? (((numRows* 2) -2) - numRows  ):(num)) %numRows;
        if (index >= numRows)
        {
            clist * temp_ptr = malloc(sizeof(struct clist));
            if (!temp_ptr)
            {
                printf("alloc failed !!!\n");
                return NULL;
            }
            temp_ptr->m_next_ptr = NULL;
            temp_ptr->m_tail_ptr = temp_ptr;

            data_ptr = (struct clist *)m_list[mod].m_tail_ptr;
            if (data_ptr)
            {
                data_ptr->m_next_ptr = temp_ptr;
                data_ptr->m_tail_ptr = temp_ptr;
            }
            m_list[mod].m_tail_ptr = temp_ptr;
        }
        data_ptr = (struct clist *)(m_list[mod].m_tail_ptr);
        if (data_ptr)
        {
            data_ptr->m_data = s[index];
            data_ptr->m_index = index;
        }
        printf("mod = %d\n", mod);
        ++index;

    }
    char  * zigzog = malloc(strlen(s) + 1);
    if (!zigzog)
    {
        return NULL;
    }
    clist * new_temp = NULL;
    clist * next_ptr = NULL;
    index = 0;
    for (int i = 0; i < numRows; ++i)
    {
        next_ptr = &m_list[i];
        while (next_ptr)
        {
//            printf("index = %d, i = %d, list_index = %d, node_ptr =%p\n", index, i, next_ptr->m_index, next_ptr);
            new_temp = next_ptr->m_next_ptr;
            zigzog[index++] = next_ptr->m_data;
            next_ptr = new_temp;
        }
    }
    printf("convert = %s\n", zigzog);
    for (int i = 0; i < numRows; ++i)
    {
        free_list(&m_list[i]);
    }
    free(m_list); //ָ��������ͷ� �е�����
//    zigzog[strlen(s) + 1] = '\0'; //�ڴ������
    zigzog[strlen(s) ] = '\0';
    return zigzog;

}

/**
 *ȡģ
 * @param s
 * @param numRows
 * @return
 */
char * convert_c(char * s, int numRows)
{
    //�ٽ�����
    if (strlen(s) < 3 || !s || numRows < 2 || numRows >= strlen(s))
    {
        return s;
    }
    char *zigzag = malloc(strlen(s) +1);
    if (!zigzag)
    {
        return s;
    }
    char *p = zigzag;
    for (int rows = 0; rows < numRows; ++rows)
    {
        //�������㹫ʽ  TODO@chensong  2020-06-07
        // �������ַ��Ĳ���  ��Ӧ����
        int interval1 = numRows + numRows -2 - (rows * 2);
        // �ڶ��� ʱ��
        int interval2 = rows * 2;

        int i = rows;
        int flag = 0;
        while (i < strlen(s))
        {
            *p++ = s[i];
            int data = 0;
            do
            {
                data = flag == 0? interval1 : interval2;
                flag = !flag;
            }
            while(data == 0);
            i+=data;
        }

    }
    zigzag[strlen(s)] = '\0';
    return zigzag;
}




char* show(char * s, int numRows)
{
    clist* m_list = malloc(sizeof(struct clist) * numRows);
    if (!m_list)
    {
        printf("alloc failed !!!\n");
        return NULL;
    }
    for (int i = 0; i < numRows; ++i)
    {
        m_list[i].m_next_ptr = NULL;
        m_list[i].m_tail_ptr = &m_list[i];
    }
    int index = 0;
    int rows = 0;
    struct clist * data_ptr = NULL;
    while (index < strlen(s) )
    {
//        printf("index = %d, rows = %d, strlen(s) = %llu\n", index, rows, strlen(s));
        if (index >= numRows)
        {
            clist * temp_ptr = malloc(sizeof(struct clist));
            if (!temp_ptr)
            {
                printf("alloc failed !!!\n");
                return NULL;
            }
            temp_ptr->m_next_ptr = NULL;
            temp_ptr->m_tail_ptr = temp_ptr;

            //printf()
            data_ptr = (struct clist *)m_list[rows].m_tail_ptr;
            if (data_ptr)
            {
                printf("alloc = %p[row = %d]\n", temp_ptr, rows);
                data_ptr->m_next_ptr = temp_ptr;
//                data_ptr->m_tail_ptr = temp_ptr;
            }
            m_list[rows].m_tail_ptr = temp_ptr;
        }
//        (struct clist *)(m_list[rows].m_tail_ptr)->m_data = s[index]; //�ڵ���ַ���
        data_ptr = (struct clist *)(m_list[rows].m_tail_ptr);
        if (data_ptr)
        {
            data_ptr->m_data = s[index];
            data_ptr->m_index = index;
            printf("index = %d, rows = %d, [ node_ptr = %p]\n", index, rows, data_ptr);
        }

        // ����һ����������
        if (rows+1  == numRows && numRows>2) //С�ڶ���ʱ ������
        {
            --rows;  //������� numrows -1 ��ʼ����
            ++index;
            while (index < strlen(s)  && rows > 0)
            {
//                printf("index = %d, rows = %d\n", index, rows);
//                if (rows < numRows)
//                {
                    clist * temp_ptr = malloc(sizeof(struct clist));
                    if (!temp_ptr)
                    {
                        printf("alloc failed !!!\n");
                        return NULL;
                    }
                    temp_ptr->m_next_ptr = NULL;
                    temp_ptr->m_tail_ptr = temp_ptr;
                {
                    data_ptr = (struct clist *)m_list[rows].m_tail_ptr;
                    if (data_ptr)
                    {
                        printf("alloc = %p[row = %d]\n", temp_ptr, rows);
                        data_ptr->m_next_ptr = temp_ptr;
//                        data_ptr->m_tail_ptr = temp_ptr;
                    }
                    m_list[rows].m_tail_ptr = temp_ptr;
                }
//                }
//                m_list[rows].m_data = s[index]; //�ڵ���ַ���
                data_ptr = (struct clist *)(m_list[rows].m_tail_ptr);
                if (data_ptr)
                {
                    data_ptr->m_data = s[index];
                    data_ptr->m_index = index;
                    printf("[index = %d, rows = %d, [ node_ptr = %p]\n", index, rows, data_ptr);
                }
                ++index;
                --rows;
            }
//            -- index;
        }
        else
        {
            ++index;
            ++rows;
            if (rows == numRows)
            {
                rows = 0;
            }
        }
    }

    clist * new_temp = NULL;
    clist * next_ptr = NULL;
    index = 0;
    for (int i = 0; i < numRows; ++i)
    {
        next_ptr = &m_list[i];
        while (next_ptr)
        {
            printf("index = %d, i = %d, list_index = %d, node_ptr =%p\n", index, i, next_ptr->m_index, next_ptr);
            new_temp = next_ptr->m_next_ptr;

            next_ptr = new_temp;
        }
    }
    for (int i = 0; i < numRows; ++i)
    {
        free_list(&m_list[i]);
    }
    free(m_list); //ָ��������ͷ� �е�����

    return NULL;
}
int main(int argc, char *argv[])
{
//    ����: s = "LEETC ODEIS HIRIN G", numRows = 4
//    ���: "LDREOEIIECIHNTSG"
//    "PAYPALISHIRING"
//    4
    char * input = "PAYPALISHIRING";
                 // PINAALSRIGYHPI
                 // PINALSIGYAHRPI
                 // PINALSIGYHPAIR
                 // PAHNAPLSIIGYIR
                 // PAHNAPLSIIGYIR
//    char *ouput = convert(input, 4);
    char *ouput = convert_c(input, 4);
//    char *ouput = convertmod(input, 4);
    if (ouput)
    {
        printf("[output = %s]\n", ouput);
    }


    return EXIT_SUCCESS;
}