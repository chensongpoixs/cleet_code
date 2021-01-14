/***********************************************************************************************
	created: 		2021-01-13

	author:			chensong

	purpose:		面试题 17.07. 婴儿名字
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
#include <algorithm>
using namespace std;

class Solution {
private:
    struct name_size
    {
        std::string name;
        int size;
    };
private:
    int getfriend(int * unoin_find, int v)
    {
        if (unoin_find[v] == v)
        {
            return v;
        }
        return unoin_find[v] = getfriend(&unoin_find[0], unoin_find[v]);
    }
public:
    void init(int *unoin_find, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            unoin_find[i] = i;
        }
    }
    /**
     * 返回字典序最小的字符串
     * @param name1
     * @param name2
     * @return
     */
    std::string checkout_trie(std::string name1, std::string name2)
    {
        if (name1.size() >= name2.size())
        {
            for (int i = 0; i < name2.size(); ++i)
            {
                if (name1[i] < name2[i])
                {
                    return name1;
                }
                else if (name1[i] > name2[i])
                {
                    return name2;
                }
            }
            return name2;
        }
        else
        {
            for (int i = 0; i < name1.size(); ++i)
            {
                if (name1[i] < name2[i])
                {
                    return name1;
                }
                else if (name1[i] > name2[i])
                {
                    return name2;
                }
            }
            return name1;
        }
        return name1;
    }
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms)
    {
        std::unordered_map<std::string, int> m_name_index;
        int unoin_find[names.size()+1];
        init(&unoin_find[0], names.size() +1);
        for (int j = 0; j < names.size(); ++j)
        {
            std::string name ;
            std::string num ;
            bool  name_num = false;
            int name_index = 0;
            for (int i = 0; i < names[j].size(); ++i)
            {
                if (names[j][i] == '(')
                {
                    name.append(names[j], 0, i);
                    name_index = i;
                    name_num = true;
                }
                if (name_num)
                {
                    if (names[j][i] == '(' || names[j][i] == ')')
                    {}
                    else
                    {

                        num.append(names[j], name_index+1, names[j].size());
                        num.erase(std::remove(num.begin(), num.end(), ')'), num.end());
                        break;
                    }
                }
            }
            m_name_map[j].name = name;
            m_name_map[j].size = atoi(num.c_str()) ;
            m_name_index[name] = j;
        }


        for (int j = 0; j < synonyms.size(); ++j)
        {
            std::string name1 ;
            std::string name2;
            int name1_index = 0;
            bool  name_num = false;

            for (int i = 2; i < synonyms[j].size(); ++i)
            {
                if (name1_index == 0 && synonyms[j][i] == ',')
                {
                    name1_index = i;
                    name1.append(synonyms[j], 1, i-1);

                }
                if (name1_index> 0)
                {
                    if (synonyms[j][i] == ',' || synonyms[j][i] == ')')
                    {}
                    else
                    {
                        name2.append(synonyms[j], name1_index+1, synonyms[j].size());
                        name2.erase(std::remove(name2.begin(), name2.end(), ')'), name2.end());
                        break;
                    }

                }
            }
            int v1;
            {
                auto iter =  m_name_index.find(name1);
                if (iter == m_name_index.end())
                {
                    continue;
                }
                v1 = getfriend(&unoin_find[0], m_name_index[name1]);
            }
            int v2;
            {
                auto iter =  m_name_index.find(name2);
                if (iter == m_name_index.end())
                {
                    continue;
                }
                v2 = getfriend(&unoin_find[0], m_name_index[name2]);
            }
            if (v1 < v2)
            {
                unoin_find[m_name_index[name2]] = v1;
                for (int w = 0; w < names.size(); ++w)
                {
                    if (unoin_find[w] == v2)
                    {
                        unoin_find[w] = v1;
                    }
                }

            }
            else if (v1 > v2)
            {
                unoin_find[m_name_index[name1]] = v1;
                for (int w = 0; w < names.size(); ++w)
                {
                    if (unoin_find[w] == v1)
                    {
                        unoin_find[w] = v2;
                    }
                }
            }

        }

        std::vector<name_size> ret(names.size());

        for (int i = 0; i < names.size(); ++i)
        {
            ret[unoin_find[i]].size += m_name_map[i].size;
            if (ret[unoin_find[i]].name.size() <1)
            {
                ret[unoin_find[i]].name = m_name_map[i].name;
            }
            else
            {
                ret[unoin_find[i]].name = checkout_trie(ret[unoin_find[i]].name, m_name_map[i].name);
            }

        }



        std::vector<std::string> new_ret;
        for (const name_size& value: ret )
        {
            if (value.size > 0)
            {
                std::string new_name = value.name;
                new_name.append("(");
                new_name.append(std::to_string(value.size));
                new_name.append(")");
                new_ret.push_back(new_name);
            }
        }

        return new_ret;
    }

    std::unordered_map<int, name_size> m_name_map;

};

int main(int argc, char *argv[])
{

    return 0;
}
