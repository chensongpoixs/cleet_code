/***********************************************************************************************
	created: 		2020-06-09

	author:			chensong

	purpose:		10.regular_expression_matching
�ҿ��ܻ������ܶ���ˣ������ǽ���2��Ĺ��£�����д�ɹ��»��ɸ裬����ѧ���ĸ���������������
Ȼ�󻹿�����һ����������һ�������ҵĹ�������ܻᱻ��˧������������ֻᱻ��������ں���������ĳ�������ҹ��������ȫ����͸Ȼ��Ҫ������С��ס�������ϵ�ʪ�·���
3Сʱ���������������ʵ��������ҵĹ�������Ը���򸸻���顣�Ҳ����Ѹ��������Ǵ�Խ�����������ǣ���ʼ��Ҫ�ص��Լ������硣
Ȼ���ҵ���Ӱ������ʧ���ҿ������������ˮ������ȴû���κ�ʹ�࣬�Ҳ�֪����ԭ���ҵ��ı������ˣ�������ȫ�����ԭ�򣬾���Ҫ�һ��Լ��ı��ġ�
�����ҿ�ʼ����Ѱ�Ҹ��ָ���ʧȥ�ĵ��ˣ��ұ��һ��שͷ��һ������һ��ˮ��һ����ƣ�ȥ�����Ϊʲô��ʧȥ�Լ��ı��ġ�
�ҷ��֣��ճ����ı��������Ļ��ڣ������ģ����ǵı��ľͻ���ʧ���յ��˸��ֺڰ�֮�����ʴ��
��һ�����ۣ������ʺͱ��ߣ�����ί����ʹ�࣬�ҿ���һֻֻ���ε��֣������ǵı��ĳ��飬�ɱΣ�͵�ߣ���Ҳ�ز������˶����ߡ�
�ҽ����������֡��������Ǻ�����ͬ�ڵļ��� �����Ҳ������£�����ϸ�����Լ�ƽ����һ�� Ѱ�ұ������ֵĺۼ���
�����Լ��Ļ��䣬һ�����ĳ�����������������֣��ҵı��ģ�����д�����ʱ�򣬻������
��������Ȼ����������ҵ�һ�У�д��������ұ��Ļع����÷�ʽ���һ�û�ҵ��������֣��������ţ�˳�������������һ����˳�����ϣ�������������
************************************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 10. �������ʽƥ��
����һ���ַ��� s ��һ���ַ����� p��������ʵ��һ��֧�� '.' �� '*' ���������ʽƥ�䡣

'.' ƥ�����ⵥ���ַ�
'*' ƥ���������ǰ�����һ��Ԫ��
��νƥ�䣬��Ҫ���� ���� �ַ��� s�ģ������ǲ����ַ�����

˵��:

s ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ��
p ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ���Լ��ַ� . �� *��
ʾ�� 1:

����:
s = "aa"
p = "a"
���: false
����: "a" �޷�ƥ�� "aa" �����ַ�����
ʾ�� 2:

����:
s = "aa"
p = "a*"
���: true
����: ��Ϊ '*' ��������ƥ���������ǰ�����һ��Ԫ��, ������ǰ���Ԫ�ؾ��� 'a'����ˣ��ַ��� "aa" �ɱ���Ϊ 'a' �ظ���һ�Ρ�
ʾ�� 3:

����:
s = "ab"
p = ".*"
���: true
����: ".*" ��ʾ��ƥ�����������'*'�������ַ���'.'����
ʾ�� 4:

����:
s = "aab"
p = "c*a*b"
���: true
����: ��Ϊ '*' ��ʾ������������� 'c' Ϊ 0 ��, 'a' ���ظ�һ�Ρ���˿���ƥ���ַ��� "aab"��
ʾ�� 5:

����:
s = "mississippi"
p = "mis*is*p*."
���: false
ͨ������80,332�ύ����285,022

 */

typedef int bool;
#define  true 1
#define  false 0

bool isMatch(char * s, char * p)
{

    return true;
}



int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}