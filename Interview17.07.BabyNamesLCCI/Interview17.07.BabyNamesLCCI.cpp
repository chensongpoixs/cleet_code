/***********************************************************************************************
	created: 		2021-01-13

	author:			chensong

	purpose:		������ 17.07. Ӥ������
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

using namespace std;

#include <iostream>
#include <vector>

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
     * �����ֵ�����С���ַ���
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