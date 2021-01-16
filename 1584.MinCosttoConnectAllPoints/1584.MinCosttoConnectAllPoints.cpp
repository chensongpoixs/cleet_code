/***********************************************************************************************
	created: 		2021-01-16

	author:			chensong

	purpose:		1584. 连接所有点的最小费用
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它??
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服??
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界??
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心??
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心??
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀??
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边??
我叫他本心猎手。他可能是和宇宙同在的级??但是我并不害怕，我仔细回忆自己平淡的一??寻找本心猎手的痕迹??
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来??
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来??
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
            int index = -1;//选择最小那个路径
            int vj = getfriend(&union_find[0], j);
            if (vj != j)
            {
                continue;//说明在集合中需要最后处理集合与集合资金的关系
            }
            int cost = 10 * 12;
            for (int i = 0; i < static_cast<int>(points.size()); ++i)
            {
                if (i != j)
                {
                    int vi = getfriend(&union_find[0], i);
                    if (vi != vj)
                    {
                        //计算最小曼哈顿距离
                        int value = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                        //最小距离
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
                        //最小距离
                        if (pp < cost)
                        {
                            cost = pp;
                            index = j;
                        }
                    }
                }
            }

            //合并到新的聚合中去
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