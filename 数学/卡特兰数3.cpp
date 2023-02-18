#include <cstdio>
#include <cstring>  //为了NOIP不用万能头文件
#include <iostream>
using namespace std;

//
int f[20][20];  //数据就给到18，开个20算大方的
int n;
int catalan(int n) {
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= n; i++)
        f[i][0] = 1;  //边界一定要有
    for (int j = 1; j <= n; j++)
        for (int i = 0; i <= n; i++)
        //我们要推f[0][n]，所以i要从零开始跑
        {
            if (i >= 1) f[i][j] = f[i - 1][j] + f[i + 1][j - 1];
            if (i == 0)  //栈内没有东西
                f[i][j] = f[i + 1][j - 1];
        }
    return f[0][n];
}