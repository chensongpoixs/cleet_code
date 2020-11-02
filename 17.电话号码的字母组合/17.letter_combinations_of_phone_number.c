/***********************************************************************************************
	created: 		2020-11-02

	author:			chensong

	purpose:		17.电话号码的字母组合
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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define bool int
#define  true 1
#define  false 0

static const  char* g_phone_number[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


bool check_digits(char * digits)
{

    if (*digits > '9' || *digits  < '2')
    {
        return false;
    }

    return true;
}




char ** letterCombinations(char * digits, int* returnSize)
{

    *returnSize = 0;

    if (!check_digits(digits) )
    {
        return NULL;
    }
    char * temp_digits = digits;
    *returnSize = 1;
    //求出组合的个数
    while (*temp_digits != '\0')
    {
        const char * ptr = g_phone_number[ *temp_digits - '0'];
        if (strlen(ptr) > 0)
        {
            (*returnSize) = (*returnSize) * strlen(ptr);
        }
        ++temp_digits;
    }
    printf("size = %d\n", *returnSize);


    char ** array = malloc(*returnSize * sizeof(char *));
    if (!array)
    {
        *returnSize = 0;
        return NULL;
    }
    for (int k = 0; k < *returnSize; ++k)
    {
        array[k] = malloc(*returnSize + 1);
        memset(array[k], 0, *returnSize +1);
    }
    int len = strlen(digits);


    int count = *returnSize;
    for (int i = 0; i < len; ++i)
    {
        *returnSize /= strlen( g_phone_number[ digits[i] - '0']);
        for (int j = 0; j < count; ++j)
        {
            //最关键的步骤
            // 例子： 输出: [ adm, adn, ado, aem, aen, aeo, afm, afn, afo, bdm, bdn, bdo, bem, ben, beo, bfm, bfn, bfo, cdm, cdn, cdo, cem, cen, ceo, cfm, cfn, cfo,  ]
            // 1. j / * returnSize 这一步是当前限定  比重概率 前面比如有27个数据
            //     ① 第一个字符 前面9个是一样的 ==> 例子：[axx, axx, axx, axx, axx, axx, axx, axx,]
            //     ② 第二个字符 前面3个是一样的 ==> 例子: [adx adx, adx,]

            // 2. 取于% 的数 正常的下标
            int index =(j / (*returnSize))  %  strlen( g_phone_number[ digits[i] - '0']);
            array[j][i] = g_phone_number[digits[i]-'0'][index];
        }

    }
    *returnSize = count;



    return array;
}

  int main(int argc, char *argv[])
  {
      if (argc < 2)
      {
          printf("Usage: ./test 3434\n");
          return  -1;
      }


      int size = 0;
      char * *array = letterCombinations(argv[1], &size);
      printf("[ ");
      for (int i = 0; i < size; ++i)
      {
          printf("%s, ", array[i]);
          free(array[i]);
      }
      free(array);
      printf(" ]");
      return 0;
  }
