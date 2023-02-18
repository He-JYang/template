#include <bits/stdc++.h>
using namespace std;
#define int long long

int m = 0;

int num[22];

int dp[22][11][3];

int dfs(int ind, int val, int pre) {
    if (ind > m) { return pre == 2; }
    if (dp[ind][val][pre] != -1) return dp[ind][val][pre];
    int ans = 0;

    for (int j = 0; j <= 9; j++) {
        int t1 = pre;
        if (t1 < 2)
            if (j > val) {
                t1 = pre + 1;
            } else
                t1 = 0;
        ans += dfs(ind + 1, j, t1);
    }

    return dp[ind][val][pre] = ans;
}

int cal(int n) {
    n++;
    m = 0;
    while (n) {
        num[++m] = n % 10;
        n /= 10;
    }
    reverse(num + 1, num + m + 1);
    int res = 0;
    memset(dp, -1, sizeof(dp));

    int pre = 0;
    int val = 99;
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= 9; j++) {
            res += dfs(i + 1, j, 0);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = (i == 1 ? 1 : 0); j < num[i]; j++) {
            int t1 = pre;
            if (t1 < 2)
                if (val < j)
                    t1++;
                else
                    t1 = 0;
            res += dfs(i + 1, j, t1);
        }
        if (pre < 2)
            if (val < num[i])
                pre++;
            else
                pre = 0;
        val = num[i];
    }

    return res;
}

signed main() {
    int l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld", cal(r) - cal(l - 1));
}