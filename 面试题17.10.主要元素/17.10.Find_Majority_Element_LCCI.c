/***********************************************************************************************
	created: 		2020-11-18

	author:			chensong

	purpose:		������ 17.10. ��ҪԪ��
�ҿ��ܻ������ܶ���ˣ������ǽ���2��Ĺ��£�����д�ɹ��»��ɸ裬����ѧ���ĸ���������������
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

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int partition(int *nums, int start, int end)
{
    int value = nums[start];
    int right = start;
    int left = end +1;
    while(1)
    {
        //1. �ҵ������
        while (nums[++right] < value)
        {
            if (right == end)
            {
                break;
            }
        }
        //2. �ҵ���С����
        while (nums[--left]  > value)
        {
            if (left == start)
            {
                break;
            }
        }
        if (right>= left)
        {
            break;
        }
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
    }
    int temp = nums[start];
    nums[start] = nums[left];
    nums[left] = temp;
    return left;
}


void sort(int *nums, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int p = partition(nums, start, end);
    sort(nums, start, p -1);
    sort(nums, p +1, end);
}


void quick_sort(int *nums, int size)
{
    if (nums == NULL || size <= 0)
    {
        return;
    }
    sort(nums, 0, size-1);
}

int majorityElement_nums(int* nums, int numsSize)
{
    if (nums == NULL || numsSize<1)
    {
        return -1;
    }
    if (numsSize == 1)
    {
        return nums[0];
    }
    quick_sort(nums, numsSize);
    int number = (numsSize/2);
    int cur_num =0;
    for (int i = 0; i <numsSize; ++i)
    {
        if (i == 0)
        {
            cur_num = nums[i];
        }
       
        if (nums[i] == cur_num )
        {
            --number;
            if (number < 0)
            {
                return cur_num;
            }
        }
        else 
        {
            number =  (numsSize/2)-1;
            cur_num= nums[i];
        }
    }
    
    return -1;
}



//Ħ��ͶƱ�� ����֤ʵ��
int majorityElement(int* nums, int numsSize)
{
    if (numsSize <0 || nums == NULL)
    {
        return -1;
    }
    int temp = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] == temp)
        {
            ++count;
        }
        else 
        {
            --count;
        }
        if (count == 0)
        {
            temp = nums[i];
            count = 1;
        }
    }

     count = 0;
    for (int i = 0; i <numsSize; ++i)
    {
        if (nums[i] == temp)
        {
            ++count;
        }
    }
    if (count > (numsSize/2))
    {
        return temp;
    }
    return -1;
}
int main(int argc, char *argv[])
{
	int arrays[] = {1,2,5,9,5,9,5,5,5};
	printf("%d\n", majorityElement(&arrays, 9));

	return EXIT_SUCCESS;
}