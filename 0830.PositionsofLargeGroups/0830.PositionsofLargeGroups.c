/***********************************************************************************************
	created: 		2021-01-05

	author:			chensong

	purpose:		830. �ϴ�����λ��
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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char * s, int* returnSize, int** returnColumnSizes)
{
    int size = strlen(s);
    int **arrays = malloc(sizeof(int*) * size/3);
    *returnColumnSizes= malloc(sizeof(int) * size/3);
    *returnSize = 0;

    int count = -1;
    int index = -1;
    char c = 0;
    char *p = s;
    while (*p  != '\0')
    {
        if (count != -1)
        {
            if (c == *p )
            {
                ++count;
                // printf("nums = %d, c = %c, s[nums] = %c", nums, c, s[nums]);
                if (p[1] == '\0')
                {
                    if (count >2)
                    {
                        (*returnColumnSizes)[*returnSize] = 2;
                        arrays[(*returnSize)] = malloc(sizeof(int) *2);
                        arrays[(*returnSize)][0] = index;
                        arrays[(*returnSize)][1] = index + count-1;
                        ++(*returnSize);

                    }
                }
            }
            else
            {
                if (count >2)
                {
                    (*returnColumnSizes)[*returnSize] = 2;
                    arrays[(*returnSize)] = malloc(sizeof(int) *2);
                    arrays[(*returnSize)][0] = index;
                    arrays[(*returnSize)][1] = index + count-1;
                    ++(*returnSize);

                }
                index = index + count;

                count =1;
                c = *p;
            }
        }
        else
        {
            count = 1;
            c = *p;
            index = 0;
        }
        ++p;
    }

    return arrays;
}


int main(int argc, char *argv[])
{
//    char * s = "ssshhhzzlllllqqqqggggfsssssnnnnniiiiibbbkkkkkkkkkv";

    return EXIT_SUCCESS;
}