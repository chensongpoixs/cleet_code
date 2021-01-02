/***********************************************************************************************
	created: 		2021-01-02

	author:			chensong

	purpose:		239. �����������ֵ
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
#include <map>
#include <iostream>
//#include <unoreded_map>
#include <vector>


using namespace std;
template <class _Tp>
struct  cless : binary_function<_Tp, _Tp, bool>
{
    bool operator()(const _Tp& __x, const _Tp& __y) const
    {return __x > __y;}
};

class Solution {
        public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {

            /**
     * Note: The returned array must be malloced, assume caller calls free().
     *//*
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)*/
            // for(int i = 0; i < numsSize; ++i)
            // {
            //     if(i != 0)
            //     {
            //         printf(", ");
            //     }
            //     printf("%d", nums[i]);
            // }
            /* *returnSize = numsSize - k + 1;
             int *arrays = malloc(sizeof(int) * (*returnSize));
             memset(arrays, 0, sizeof(int) * (*returnSize));
             */
            std::vector<int> arrays(nums.size() -k+1);
            // std::unordered_map<int, int> count_map;
            std::map<int, int, cless<int>> count_map;
            int index = 0;
            int *circle = static_cast<int*>(malloc(sizeof(int) *k));
            for (int i = 0; k <= static_cast<int>(nums.size())&&i < k; ++i)
            {
                circle[i%k]=nums[i];
                ++count_map[circle[i%k]];
                if (i == index)
                {
                    arrays[index] = nums[i];
                }
                if (arrays[index]<nums[i])
                {
                    arrays[index] = nums[i];
                }
            }
            ++index;
            int max = arrays[0];/*
    for (const std::pair<const int, int> & pair_: count_map)
        {
            printf("%d, ", pair_.first);
        }
        printf("]\n");*/
            for (int i = k; i < static_cast<int>(nums.size()); ++i)
            {

                int cur_nums = circle[i%k];
                circle[i%k] = nums[i];
                // --count_map[cur_nums];
                if (--count_map[cur_nums]<1)
                {
                    // printf("delete === %d\n", cur_nums);
                    count_map.erase(cur_nums);
                }
                ++count_map[nums[i]];/*
        for (const std::pair<const int, int> & pair_: count_map)
        {
            printf("%d, ", pair_.first);
        }
        printf("]\n");*/
                if (k>1)
                {
                    if (cur_nums == max && max>nums[i] )
                    {
                        for (const std::pair<const int, int> & pair_: count_map)
                        {
                            max = pair_.first;
                            break;
                        }

                    }
                    else if (max<nums[i])
                    {
                        max = nums[i];
                    }
                    // else if ()
                }
                else
                {
                    max = nums[i];
                }
                arrays[index++] = max;
            }
//            printf("nums= %u, size = %u\n", nums.size(), count_map.size());
            free(circle);
            circle = NULL;
            return arrays;
        }


};


int main(int argc, char *argv[])
{
    printf("[1,3,-1,-3,5,3,6,7]\n");
    std::vector<int> arrays{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution solution;
    std::vector<int>  ret = solution.maxSlidingWindow(arrays, k);
    printf("[");
    for (const int& value : ret)
    {
        printf("%d, ", value);
    }
    printf("]\n");
    return EXIT_SUCCESS;
}