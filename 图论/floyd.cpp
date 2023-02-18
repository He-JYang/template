#include <bits/stdc++.h>
using namespace std;
const int N = 500;
const int inf = 0x7fffffff;
int dis[N][N];

int floyd(int n) {
    for (int k = 1; k <= n; k++) {  // 整体上看k表示以前k个点作为中转点i能否到达j到达j的最短距离是多少
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}