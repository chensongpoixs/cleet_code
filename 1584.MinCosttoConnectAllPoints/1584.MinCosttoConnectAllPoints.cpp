/***********************************************************************************************
	created: 		2021-01-16

	author:			chensong

	purpose:		1584. �������е����С����
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
#include <unordered_map>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
private:
    void init(int *union_find, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            union_find[i] = i;
        }
    }

    int getfriend(int *union_find, int v)
    {
        if (union_find[v] == v)
        {
            return v;
        }
        return union_find[v] = getfriend(&union_find[0], union_find[v]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int ans = 0;
        std::map<int, std::vector<int>> union_find_map;
        int union_find[points.size()];
        init(&union_find[0], points.size());

        for (int j = 0; j < static_cast<int>( points.size()); ++j)
        {
            int index = -1;//ѡ����С�Ǹ�·��
            int vj = getfriend(&union_find[0], j);
            if (vj != j)
            {
                continue;//˵���ڼ�������Ҫ��������뼯���ʽ�Ĺ�ϵ
            }
            int cost = 10 * 12;
            for (int i = 0; i < static_cast<int>(points.size()); ++i)
            {
                if (i != j)
                {
                    int vi = getfriend(&union_find[0], i);
                    if (vi != vj)
                    {
                        //������С�����پ���
                        int value = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                        //��С����
                        if (value < cost)
                        {
                            cost = value;
                            index = i;
                        }
                    }
                    else
                    {
                        printf("error = %d\n", vi);
                    }
                }
            }

            if (index != -1)
            {
                ans += cost;
                int vi = getfriend(&union_find[0], index);
                if(vi != vj)
                {
                    if (vi > vj)
                    {
                        union_find[index] = vj;
                    }
                    else
                    {
                        union_find[j] = vi;
                    }
                }
            }

        }
        printf("ans = %d\n", ans);

        for (int i = 0; i < static_cast<int>(points.size()); ++i)
        {
            union_find_map[union_find[i]].push_back(i);
        }
        int hash[union_find_map.size()];
        int index = 0;
        for (const std::pair<int, std::vector<int>>& _pair: union_find_map)
        {
            hash[index++] = _pair.first;
        }
        index = 0;
        for (int i = 0; i < static_cast<int>(union_find_map.size()-1); ++i)
        {
            int cost = 1000000000;
            if (i>= static_cast<int>(union_find_map.size()))
            {
                continue;
            }
            for (const int& value1: union_find_map[hash[i]])
            {
                for (int j = i+1; j < static_cast<int>(union_find_map.size()); ++j)
                {
                    if (j>= static_cast<int>(union_find_map.size()))
                    {
                        continue;
                    }
                    for (const int& value2 : union_find_map[hash[j]])
                    {
                        int pp = abs(points[value2][0]-points[value1][0]) + abs(points[value2][1]-points[value1][1]);
                        //   printf("i = %d, j = %d, value1 = %d, value2 = %d,  pp =%d\n", i, j, value1, value2,  pp);
                        //��С����
                        if (pp < cost)
                        {
                            cost = pp;
                            index = j;
                        }
                    }
                }
            }

            //�ϲ����µľۺ���ȥ
            for (const int & new_value: union_find_map[hash[i]])
            {
                union_find_map[hash[index]].push_back(new_value);
            }

            ans = ans + cost;
        }

        return ans;
    }
};

//[[5,8],[18,-6],[-18,13],[-8,-13],[-13,3],[-15,2],[-12,17],[14,16],[-4,3],[-17,-7],[8,9],[17,14],[-13,2],[-3,-1],[4,-20]]




int main(int argc, char *argv[])
{
    return 0;
}