#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

// init时间复杂度（nlogn）查询时间复杂度O1

int st[N][__lg(N) + 1];  // N为要查询的最大范围

// __lg(n)返回log2(n)向向下取整,最高位的位数减一,可理解为将n最高位移到&1需要移动的位数

// 在不使用第0层时st表不会访问第0层，当然st表可以使用第0层
// 使用st(i, j) 来表示区间[i, i + 2 ^ j - 1] 中的最值
void init_st(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j <= __lg(n); j++) {                                //__lg(len)len为要查询的范围
        for (int i = 1; i + (1 << j - 1) <= n; i++) {                   // 防RE,多开30列可直接写n,标准写法i + (1 << j) - 1 <= n
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);  // rmq(range max/min query)问题的st表
            // st[i][j] = st[st[i][j - 1]][j - 1];                         //路径倍增st表
        }
    }
}

int queryRMQst(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int queryRoadSt(int x, int k) {
    int i = __lg(k);  // 也行, 加上 if (k != 0) 即可
    if (k != 0)
        for (int i = __lg(k); i >= 0; i--)
            if (x & (1 << i)) x = st[x][i];
    return x;
}