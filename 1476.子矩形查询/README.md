## 1476. �Ӿ��β�ѯ
����ʵ��һ���� SubrectangleQueries �����Ĺ��캯���Ĳ�����һ�� rows x cols �ľ��Σ����������������ʾ������֧���������ֲ�����

1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

�� newValue ������ (row1,col1) Ϊ���Ͻ����� (row2,col2) Ϊ���½ǵ��Ӿ��Ρ�
2. getValue(int row, int col)

���ؾ��������� (row,col) �ĵ�ǰֵ��
 
 
```

ʾ�� 1��

���룺
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue","getValue"]
[[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]
�����
[null,1,null,5,5,null,10,5]
���ͣ�
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,2,1],[4,3,4],[3,2,1],[1,1,1]]);  
// ��ʼ�� (4x3) �������£�
// 1 2 1
// 4 3 4
// 3 2 1
// 1 1 1
subrectangleQueries.getValue(0, 2); // ���� 1
subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
// �˴θ��º���α�Ϊ��
// 5 5 5
// 5 5 5
// 5 5 5
// 5 5 5 
subrectangleQueries.getValue(0, 2); // ���� 5
subrectangleQueries.getValue(3, 1); // ���� 5
subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
// �˴θ��º���α�Ϊ��
// 5   5   5
// 5   5   5
// 5   5   5
// 10  10  10 
subrectangleQueries.getValue(3, 1); // ���� 10
subrectangleQueries.getValue(0, 2); // ���� 5
ʾ�� 2��

���룺
["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue"]
[[[[1,1,1],[2,2,2],[3,3,3]]],[0,0],[0,0,2,2,100],[0,0],[2,2],[1,1,2,2,20],[2,2]]
�����
[null,1,null,100,100,null,20]
���ͣ�
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,1,1],[2,2,2],[3,3,3]]);
subrectangleQueries.getValue(0, 0); // ���� 1
subrectangleQueries.updateSubrectangle(0, 0, 2, 2, 100);
subrectangleQueries.getValue(0, 0); // ���� 100
subrectangleQueries.getValue(2, 2); // ���� 100
subrectangleQueries.updateSubrectangle(1, 1, 2, 2, 20);
subrectangleQueries.getValue(2, 2); // ���� 20
 
```



��ʾ��

```
����� 500 ��updateSubrectangle �� getValue ������
1 <= rows, cols <= 100
rows == rectangle.length
cols == rectangle[i].length
0 <= row1 <= row2 < rows
0 <= col1 <= col2 < cols
1 <= newValue, rectangle[i][j] <= 10^9
0 <= row < rows
0 <= col < cols

```

ͨ������6,726�ύ����7,619




������Ҫ������ϸ����


���⣺����һ������ Ȼ���޸������ֵ