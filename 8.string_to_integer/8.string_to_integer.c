/***********************************************************************************************
created: 		2020-06-08

author:			chensong

purpose:		8.string_to_integer
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


signed int max = 0X7FFFFFFF;
signed int min = 0X80000000;

/**
 *
 * @param s
 * @return
 */
int myAtoi(char * s)
{
    if (!s)
    {
        return 0;
    }

    long ret = 0;
    char *p = s;
    int   positive = 0; //����
    int   negative = 0; //����
    int   index = 0;
    int   num = 0; //�Ƿ��Ѿ���ֵ��
    while (p)
    {
        if (*p == '\0')
        {
            break;
        }
        printf("index = %d = %c\n", index, *p);
        if (*p == ' ')
        {
            if ((0 != ret)||positive||negative || num == 1)
            {
                break;
            }
//           ++p;
        }
        else if (*p  == '-')
        {
            if (positive == 1 || num == 1 || negative == 1)
            {
                break;
            }
            if (0 !=ret)
            {
                break;
            }
            negative = 1;
//           ++p;
        }
        else if (*p == '+' )
        {
            // if ()
            if (negative == 1 || num == 1 || positive == 1)
            {
                break;
            }
            if (0 != ret)
            {
                break;
            }
            positive =1;
        }
        else
        {
            if ((*p -'0')  < 10&&( *p -'0')  > -1)
            {
                //�ж��Ƿ��Ѿ������ֵ������Сֵ
                if (ret * 10> max)
                {
                    if (negative == 1)
                    {
                        return min;
                    }

                    return max;
                }
                ret = ret* 10 + (*p -'0');
                num = 1;
            }
            else
            {

                break;
                //    }
            }
//           ++p;
        }
        ++p;
        ++index;
        printf("ret %ld\n", ret);
    }
    if (negative == 1)
    {
        ret = -1 * ret;
        if (ret < min)
        {
            return min;
        }
    }
    if (ret > max)
    {
        return max;
    }
    return ret;
}



// int main(int argc, char *argv[])
// {


//     char * s = "3.14159";
//     int num = myAtoi(s);
//     printf("num %d\n", num);
//     return  EXIT_SUCCESS;
// }



// int main(int argc, char *argv[])
// {


//     char * s = "3.14159";
//     int num = myAtoi(s);
//     printf("num %d\n", num);
//     return  EXIT_SUCCESS;
// }



int main(int argc, char *argv[])
 {
    // "  -0  23"
    // "++23423"
     // "+-3432"
     // "+322243"
     char * s = "3.14159";
     int num = myAtoi(s);
     printf("num %d\n", num);
     return  EXIT_SUCCESS;
 }
