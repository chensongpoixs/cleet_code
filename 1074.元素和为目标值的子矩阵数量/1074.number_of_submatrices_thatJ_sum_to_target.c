/***********************************************************************************************
	created: 		2020-11-03

	author:			chensong

	purpose:		1074.元素和为目标值的子矩阵数量
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





/**
 * TODO@chensong 2020-11-09  warr 超出时间限制  我也是头大啊啊
 * @param matrix
 * @param matrixSize
 * @param matrixColSize
 * @param target
 * @return
 */
int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target){

    int matrix_nums = 0;

    if (!matrix)
    {
        return matrix_nums;
    }
    for (int i = 0; i < matrixSize; ++i)
    {
        for (int j = 0; j < matrixColSize[i]; ++j)
        {
            //printf("matrix[%d][%d]=%d\n", i, j, matrix[i][j]);
            {
                //x
                // int x = j;
                // int diff = 0;
                // for (; x >=0; --x)
                // {
                //     diff += matrix[i][x];
                //     if (target == diff)
                //     {
                //         ++matrix_nums;
                //     }
                // }
            }
            {
                // int y = i;
                // int diff = 0;
                // for (; y >=0; --y)
                // {
                //      diff += matrix[y][j];
                //     //  printf("matrix[%d][%d]=%d\n", y, j, matrix[y][j]);
                //      //去除重复单一的元素
                //     if (y !=i && target == diff)
                //     {
                //          ++matrix_nums;
                //     }
                // }
            }
            {
                //矩阵收割机
                // if(i > 0 && j > 0)//成立
                {
                    // int diff = 0;
                    for (int x = j; x>=0; --x)
                    {
                        // if (x == j)
                        // {
                        //     continue;
                        // }
                        for (int y = i; y>=0; --y)
                        {
                            //非常关键一步   ？？
                            // if (y == i )
                            // {
                            //     //  printf("[y = %d, i = %d][x = %d, j = %d]1\n", y,i, x, j);
                            //     continue;
                            // }
                            // if (abs(i - y) < 1 && abs(j - x ) < 1  )
                            // {
                            //     // printf("[y = %d, i = %d][x = %d, j = %d]1\n", y,i, x, j);
                            //     continue;
                            // }
                            int diff = 0;

                            // int yy = y;
                            // int xx = x;
                            for (int yy = y; yy <= i; ++yy)
                            {
                                for (int xx = x; xx <= j; ++xx)
                                {
                                    //    printf("matrix[%d][%d]=%d, ", yy, xx, matrix[yy][xx]);
                                    diff += matrix[yy][xx];
                                }
                                // printf("\n");
                            }

//  printf("------\n");
                            // printf("[y = %d, i = %d][x = %d, j = %d]1\n", y,i, x, j);
                            if (diff == target )
                            {
                                // printf("[y = %d, i = %d][x = %d, j = %d]1\n", y,i, x, j);
                                // printf("   w \n");
                                ++matrix_nums;
                            }
                        }
                    }
                }
            }
        }
    }


    return matrix_nums;
}

