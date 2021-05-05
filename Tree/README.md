

```c
struct cnode
{
    int m; // 有几个孩子节点
    struct centry * childern[1]; //arrays 柔性数组
}cnode;

// 数据节点
struct centry
{
    int key;
    int value;
    struct cnode * next;
}centry;


BTree 

int size;
int height;
int m = 4; //几阶B树

```


# M阶B树的性质

关键字数为n, 高度h

$[m/2]$ = p

||关键字||
|:---:|:---:|:---:|
|层|最少|最多|
|1|1|m-1|
|2|2(p-1)|m(m-1)|
|3|2p(p-1)|$m^2 (m-1)$|
|4|$2p^2(p-1)$|$m^3(m-1)$|
|h|$2p^(h-2)(p-1)$|$m^(h-1) (m-1)$|