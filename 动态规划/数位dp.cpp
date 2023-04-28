#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int a[20];
int dp[20][2];
/*
    pos 当前枚举到第几位了
    pre 前一位是什么
    sta 是否满足条件
    limit 是否为上界或下界
 */
int dfs(int pos, int pre, int sta, bool limit) {
    if (pos == -1) return 1;
    if (!limit && dp[pos][sta] != -1) return dp[pos][sta];
    int up = limit ? a[pos] : 9;
    int tmp = 0;
    for (int i = 0; i <= up; i++) {
        if (pre == 6 && i == 2) continue;
        if (i == 4) continue;  // 都是保证枚举合法性
        tmp += dfs(pos - 1, i, i == 6, limit && i == a[pos]);
    }
    if (!limit) dp[pos][sta] = tmp;
    return tmp;
}
int solve(int x) {
    int pos = 0;
    while (x) {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, -1, 0, true);
}
signed use() {
    int le, ri;
    // memset(dp,-1,sizeof dp);可优化
    while (~scanf("%d%d", &le, &ri) && le + ri) {
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(ri) - solve(le - 1));
    }
    return 0;
}