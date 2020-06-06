# 6. Z 字形变换


 6. Z 字形变换
 
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：


``` 
L   C   I   R
E T O E S I I G
E   D   H   N
```

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:



``` 
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
```


解题思路: 

观察字符串输出的特点分析:

从列是输入的字符串, 每一行其实就是队列 队列的特点是先进先出的特点


所以输入numRows的值判断队列有几个， 然后我们把字符依次压人队列中，需要注意有一个当行数大于2时需要压人队列中顺序需要改变


取模

行数取法

``` 
公式 = (numrows * 2 - 2) % numrows //得到当前行数
```
