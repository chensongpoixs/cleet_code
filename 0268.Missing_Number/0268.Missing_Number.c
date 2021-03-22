/***********************************************************************************************
	created: 		2021-03-22

	author:			chensong

	purpose:		268. ��ʧ������
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
#include <stdint.h>

/**
* ʱ�临�Ӷ�O(N)
* �ռ临�Ӷ�O((N)
*/
int missingNumber_one(int* nums, int numsSize)
{
    int *array=  malloc(sizeof(int) * (numsSize+1));
    memset(array, 0, sizeof(int) *(numsSize+1));
    for (int i = 0; i < numsSize; ++i)
    {
        ++array[nums[i]];
    }
    for (int i = 0; i < (numsSize+1); ++i)
    {
        if (array[i] == 0)
        {
            free(array);
            array = NULL;
            return i;
        }
    }
    free(array);
    array = NULL;
    return 0;
}

/**
* ʱ�临�Ӷ�O(N)
* �ռ临�Ӷ�O((N>>3) +1)
*/
int missingNumber_two(int* nums, int numsSize)
{
    int bit_size = (numsSize >> 3) +1; //ʵ����Ҫ�ڴ��С
    uint8_t *bit=  malloc(sizeof(uint8_t) * bit_size);
    memset(bit, 0, sizeof(uint8_t) *bit_size );
    for (int i = 0; i < numsSize; ++i)
    {
        bit[(nums[i]>>3)] ^=   (1 << (nums[i] % 8));
    }

    for (int i = 0; i < numsSize; ++i)
    {
        //�Ƚ�ÿһ�������Ƿ���0
        if ( (bit[i>>3]  &  (1 << (i% 8))) == 0)
        {
            if (bit)
            {
                free(bit);
                bit = NULL;
            }
            return i;
        }
    }
    if (bit)
    {
        free(bit);
        bit = NULL;
    }
    return numsSize;
}



int main(int argc, char *argv[])
{
    int arrays[] = {9,6,4,2,3,5,7,0,1};
    printf("arrays = [");
    for (int i = 0; i < sizeof(arrays)/ sizeof(int); ++i)
    {
        printf("%d, ", arrays[i]);
    }
    printf("]\n");
    printf("[bit size = %d]\n", missingNumber_two(&arrays[0], sizeof(arrays)/ sizeof(int)));
    return EXIT_SUCCESS;
}