/***********************************************************************************************
	created: 		2020-12-20

	author:			chensong

	purpose:		5630. 删除子数组的最大得分
我可能会遇到很多的人，听他们讲好2多的故事，我来写成故事或编成歌，用我学来的各种乐器演奏它�?
然后还可能在一个国家遇到一个心仪我的姑娘，她可能会被我帅气的外表捕获，又会被我深邃的内涵吸引，在某个下雨的夜晚，她会全身淋透然后要在我狭小的住处换身上的湿衣服�?
3小时候后她告诉我她其实是这个国家的公主，她愿意向父皇求婚。我不得已告诉她我是穿越而来的男主角，我始终要回到自己的世界�?
然后我的身影慢慢消失，我看到她眼里的泪水，心里却没有任何痛苦，我才知道，原来我的心被丢掉了，我游历全世界的原因，就是要找回自己的本心�?
于是我开始有意寻找各种各样失去心的人，我变成一块砖头，一颗树，一滴水，一朵白云，去听大家为什么会失去自己的本心�?
我发现，刚出生的宝宝，本心还在，慢慢的，他们的本心就会消失，收到了各种黑暗之光的侵蚀�?
从一次争论，到嫉妒和悲愤，还有委屈和痛苦，我看到一只只无形的手，把他们的本心扯碎，蒙蔽，偷走，再也回不到主人都身边�?
我叫他本心猎手。他可能是和宇宙同在的级�?但是我并不害怕，我仔细回忆自己平淡的一�?寻找本心猎手的痕迹�?
沿着自己的回忆，一个个的场景忽闪而过，最后发现，我的本心，在我写代码的时候，会回来�?
安静，淡然，代码就是我的一切，写代码就是我本心回归的最好方式，我还没找到本心猎手，但我相信，顺着这个线索，我一定能顺藤摸瓜，把他揪出来�?
************************************************************************************************/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <iostream>
//#include "clog_server.h"
#include <signal.h>
#include <iostream>
//#include <cstring>
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        std::vector<int> new_nums(nums.size());
        new_nums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            new_nums[i] = nums[i] + new_nums[i-1];
        }
        
        int count = 0;
        int start = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if(m_data[nums[i]] > 0)
            {
               int temp_start = m_data[nums[i]] -1 ;
               // 当开始位置是大于等于0下标和时需要加1  这个我调试几个小时
                for (int j =( start)>=0?(start+1):0; j <= temp_start; ++j)
                {
                    m_data[nums[j]] = 0;
                }
                start = temp_start;
                
            }
             m_data[nums[i]] = i+1;

            if ((start != -1 && count < new_nums[i] - new_nums[start]) )
            {
                count = new_nums[i] - new_nums[start];
            }
            else if (i == start && count <new_nums[i])
            {
                count = new_nums[i];
            }
            else if (start == -1 && count < new_nums[i])
            {
                 count = new_nums[i];
            }
        }
        return count;
    }
    
    
    std::unordered_map<int, int>        m_data;
};


void test()
{
    int old_ante[] = { 0 ,0 ,0 ,0  ,0 ,50 ,100 ,100   ,200 ,200 ,300  ,300  ,300      ,400 ,500
            ,500
            ,1000
            ,1000
            ,2000
            ,2000
            ,3000
            ,3000
            ,3000
            ,4000
            ,5000
            ,5000
            ,10000
            ,10000
            ,20000
            ,20000
            ,30000
            ,30000
            ,30000
            ,40000
            ,50000
            ,50000
            ,100000
            ,100000
            ,200000
            ,200000
            ,300000
            ,300000
            ,300000
            ,400000
            ,500000
            ,500000
            ,1000000
            ,1000000
            ,2000000
            ,2000000
            ,3000000
            ,3000000
            ,3000000
            ,4000000
            ,5000000
            ,5000000
            ,10000000
            ,10000000
            ,10000000
            ,20000000
            ,30000000
            ,30000000
            ,30000000
            ,40000000
            ,50000000
            ,50000000
            ,100000000
            ,100000000
            ,100000000
    };

    int old_small_blind[] = { 50
            ,75
            ,100
            ,150
            ,200
            ,300
            ,400
            ,500
            ,600
            ,800
            ,1000
            ,1200
            ,1500
            ,2000
            ,2500
            ,3000
            ,4000
            ,5000
            ,6000
            ,8000
            ,10000
            ,12000
            ,15000
            ,20000
            ,25000
            ,30000
            ,40000
            ,50000
            ,60000
            ,80000
            ,100000
            ,120000
            ,150000
            ,200000
            ,250000
            ,300000
            ,400000
            ,500000
            ,600000
            ,800000
            ,1000000
            ,1200000
            ,1500000
            ,2000000
            ,2500000
            ,3000000
            ,4000000
            ,5000000
            ,6000000
            ,8000000
            ,10000000
            ,12000000
            ,15000000
            ,20000000
            ,25000000
            ,30000000
            ,40000000
            ,50000000
            ,60000000
            ,80000000
            ,100000000
            ,120000000
            ,150000000
            ,200000000
            ,250000000
            ,300000000
            ,400000000
            ,500000000
            ,600000000
    };


    int two_new_ante[] = { 12
            ,15
            ,20
            ,25
            ,30
            ,40
            ,50
            ,60
            ,75
            ,100
            ,125
            ,150
            ,175
            ,200
            ,225
            ,250
            ,300
            ,350
            ,400
            ,500
            ,600
            ,750
            ,1000
            ,1250
            ,1500
            ,1750
            ,2000
            ,2500
            ,3000
            ,4000
            ,5000
            ,6000
            ,7500
            ,8500
            ,10000
            ,12500
            ,15000
            ,20000
            ,25000
            ,30000
            ,35000
            ,40000
            ,50000
            ,60000
            ,75000
            ,100000
            ,125000
            ,150000
            ,175000
            ,200000
            ,250000
            ,300000
            ,400000
            ,500000
            ,600000
            ,750000
            ,850000
            ,1000000
            ,1250000
            ,1500000
            ,2000000
            ,2500000
            ,3000000
            ,3500000
            ,4000000
            ,5000000
            ,6000000
            ,7500000
            ,10000000
            ,12500000
    };

    int two_new_small_blind[] = { 50
            ,60
            ,80
            ,100
            ,120
            ,160
            ,200
            ,250
            ,300
            ,400
            ,500
            ,600
            ,700
            ,800
            ,900
            ,1000
            ,1200
            ,1400
            ,1600
            ,2000
            ,2500
            ,3000
            ,4000
            ,5000
            ,6000
            ,7000
            ,8000
            ,10000
            ,12000
            ,16000
            ,20000
            ,25000
            ,30000
            ,35000
            ,40000
            ,50000
            ,60000
            ,80000
            ,100000
            ,120000
            ,140000
            ,160000
            ,200000
            ,250000
            ,300000
            ,400000
            ,500000
            ,600000
            ,700000
            ,800000
            ,1000000
            ,1200000
            ,1600000
            ,2000000
            ,2500000
            ,3000000
            ,3500000
            ,4000000
            ,5000000
            ,6000000
            ,8000000
            ,10000000
            ,12000000
            ,14000000
            ,16000000
            ,20000000
            ,25000000
            ,30000000
            ,40000000
            ,50000000
    };




    int three_new_ante[] = { 5
            ,6
            ,8
            ,9
            ,11
            ,12
            ,14
            ,15
            ,18
            ,21
            ,24
            ,27
            ,30
            ,38
            ,50
            ,60
            ,80
            ,90
            ,110
            ,120
            ,140
            ,150
            ,180
            ,210
            ,240
            ,270
            ,300
            ,380
            ,500
            ,550
            ,600
            ,800
            ,900
            ,1100
            ,1200
            ,1400
            ,1500
            ,1800
            ,2100
            ,2400
            ,2700
            ,3000
            ,3800
            ,5000
            ,5500
            ,6000
            ,8000
            ,9000
            ,11000
            ,12000
            ,14000
            ,15000
            ,18000
            ,21000
            ,24000
            ,27000
            ,30000
            ,38000
            ,50000
            ,55000
            ,60000
            ,80000
            ,90000
            ,110000
            ,120000
            ,140000
            ,150000
            ,180000
            ,210000
            ,240000
            ,270000
    };

    int three_small_bliud[] = { 15
            ,20
            ,25
            ,30
            ,35
            ,40
            ,45
            ,50
            ,60
            ,70
            ,80
            ,90
            ,100
            ,125
            ,150
            ,200
            ,250
            ,300
            ,350
            ,400
            ,450
            ,500
            ,600
            ,700
            ,800
            ,900
            ,1000
            ,1250
            ,1500
            ,1750
            ,2000
            ,2500
            ,3000
            ,3500
            ,4000
            ,4500
            ,5000
            ,6000
            ,7000
            ,8000
            ,9000
            ,10000
            ,12500
            ,15000
            ,17500
            ,20000
            ,25000
            ,30000
            ,35000
            ,40000
            ,45000
            ,50000
            ,60000
            ,70000
            ,80000
            ,90000
            ,100000
            ,125000
            ,150000
            ,175000
            ,200000
            ,250000
            ,300000
            ,350000
            ,400000
            ,450000
            ,500000
            ,600000
            ,700000
            ,800000
            ,900000
    };

    {
        std::ofstream			one_fd;
        std::string one_log_name ("one_build.json");
        one_fd.open(one_log_name, std::ios::out | std::ios::trunc);
        if (!one_fd.is_open())
        {
            std::cout << "not open log file dest url = " << one_log_name.c_str() << std::endl;
            return ;
        }
        for (int i = 0; i < sizeof(old_ante)/sizeof(int); ++i)
        {
            /*"level":1,
                "ante" : 50,
                "small_blind" : 25,
                "build_level_time" : 300*/

            one_fd << "{\n \"level\":" << (i + 1) << ",\n";
            one_fd << "\"ante\":" << old_ante[i] << ", \n";
            one_fd << "\"small_blind\":" << old_small_blind[i] << ", \n";
            one_fd << "\"build_level_time\": 60\n},";
        }
        if (one_fd.is_open())
        {
            one_fd.flush();
            one_fd.close();
        }
    }

    {
        std::ofstream			one_fd;
        std::string one_log_name ("two_build.json");
        one_fd.open(one_log_name, std::ios::out | std::ios::trunc);
        if (!one_fd.is_open())
        {
            std::cout << "not open log file dest url = " << one_log_name.c_str() << std::endl;
            return ;
        }
        for (int i = 0; i < sizeof(two_new_ante)/sizeof(int); ++i)
        {
            /*"level":1,
                "ante" : 50,
                "small_blind" : 25,
                "build_level_time" : 300*/

            one_fd << "{\n \"level\":" << (i + 1) << ",\n";
            one_fd << "\"ante\":" << two_new_ante[i] << ", \n";
            one_fd << "\"small_blind\":" << two_new_small_blind[i] << ", \n";
            one_fd << "\"build_level_time\": 60\n},";
        }
        if (one_fd.is_open())
        {
            one_fd.flush();
            one_fd.close();
        }
    }

    {
        std::ofstream			one_fd;
        std::string one_log_name ("three_build.json");
        one_fd.open(one_log_name, std::ios::out | std::ios::trunc);
        if (!one_fd.is_open())
        {
            std::cout << "not open log file dest url = " << one_log_name.c_str() << std::endl;
            return ;
        }
        for (int i = 0; i < sizeof(three_new_ante)/sizeof(int); ++i)
        {
            /*"level":1,
                "ante" : 50,
                "small_blind" : 25,
                "build_level_time" : 300*/

            one_fd << "{\n \"level\":" << (i + 1) << ",\n";
            one_fd << "\"ante\":" << three_new_ante[i] << ", \n";
            one_fd << "\"small_blind\":" << three_small_bliud[i] << ", \n";
            one_fd << "\"build_level_time\": 60\n},";
        }
        if (one_fd.is_open())
        {
            one_fd.flush();
            one_fd.close();
        }
    }


}



int main(int argc, char *argv[])
{
    test();
    return 0;
	Solution test;
	vector<int> vec{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5,   6,  1,  2,   3,   4,  5,  6};
	
	printf("[1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5,   6,  1,  2,   3,   4,  5,  6]\n count = %d\n", test.maximumUniqueSubarray(vec));
	return 0;
}