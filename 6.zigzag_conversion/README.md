# 6. Z ���α任


 6. Z ���α任
 
��һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "LEETCODEISHIRING" ����Ϊ 3 ʱ���������£�


``` 
L   C   I   R
E T O E S I I G
E   D   H   N
```

֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);
ʾ�� 1:



``` 
����: s = "LEETCODEISHIRING", numRows = 3
���: "LCIRETOESIIGEDHN"
ʾ�� 2:

����: s = "LEETCODEISHIRING", numRows = 4
���: "LDREOEIIECIHNTSG"
����:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
```


����˼·: 

�۲��ַ���������ص����:

������������ַ���, ÿһ����ʵ���Ƕ��� ���е��ص����Ƚ��ȳ����ص�


��������numRows��ֵ�ж϶����м����� Ȼ�����ǰ��ַ�����ѹ�˶����У���Ҫע����һ������������2ʱ��Ҫѹ�˶�����˳����Ҫ�ı�


ȡģ

����ȡ��

``` 
��ʽ = (numrows * 2 - 2) % numrows //�õ���ǰ����
```


```  
        int mod = 0;
        int num = (index +1) % ((numRows* 2) -2) ;
        if (num == 0)
        {
            mod = 1; // �����һ����  
        }
        else
        {    //������Ϊ �����inedx +1 ����Ҫȥ�� 1  ���������  
            // 1:һ���Ǵ���numRowsʱ��Ҫ��1
            // 2:С��numRowsҪ��ȥ1
             mod =  num >numRows ? ((numRows* 2) -2) - num +1 : num-1; //TODO@chensong 2020-06-06 �������У����� 
        }
```








�������㹫ʽ

``` 
//�������㹫ʽ  TODO@chensong  2020-06-07
        int interval1 = numRows + numRows -2 - (rows * 2);
        int interval2 = rows * 2;

```