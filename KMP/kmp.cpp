


#include <string>
#include <vector>
#include <iostream>

/**
 *
 * @param S
 * @param T
 * @return
 */
int kmp(std::string S, std::string T)
{
    std::string s = " " + S + "#" + T; // [ chenli#chensongldskfjsdlkfchenlijdchensyangylsdkfjlds]
    ::printf("[%s][%d][%s]\n", __FUNCTION__, __LINE__, s.c_str());
    std::vector<int> next(s.size());
    for(int i = 1; i < s.size(); ++i)
    {
//         printf("=================[index = %d]=======================\n", i);
//         show(next);
        for(int len = next[i]; ; len = next[len])
        {
//            printf("[i = %d][len = %d]\n", i, len);
            if(s[len + 1] == s[i + 1])
            {
                next[i + 1] = len + 1;
                break;
            }
            else
            {
                if(len == 0)
                {
                    break;
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i <= T.size(); ++i)
    {
        count += next[i + S.size() + 1] == S.size();
        if (next[i + S.size() + 1] == S.size())
        {
            ::printf("[i = %d][str = %s]\n", i, &T[i-S.size()]);
        }
    }

    return count;
}


int main(int argc, char *argv[])
{
    std::string s = "chenchenlisongldschenlikfjsdlkfchenlijdchensyangchenliylsdkfjlchenlidschenli";
    std::string p = "c";
    int count = kmp(p, s);
    printf("[s = %s][p = %s][count = %d]\n", s.c_str(), p.c_str(), count);
    return EXIT_SUCCESS;
}