#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[22][22][2];

int num[22];
int m;

int res;

int cal(int n) {
    if (n == 0) return 0;
    m = 0;
    res = 0;
    while (n) {
        num[++m] = n % 10;
        n /= 10;
    }
    int ok = 1;
    reverse(num + 1, num + m + 1);
    for (int i = 1; i <= m && ok; i++) {
        for (int j = 0; j < num[i]; j++) {
            if (i != 1 && abs(j - num[i - 1]) > 2) { continue; }
            memset(dp, 0, sizeof(dp));
            if (i == 1 && !j) {
                dp[i][j][0] = 1;
            } else {
                dp[i][j][1] = 1;
            }
            for (int k = i + 1; k <= m; k++) {
                for (int l = 0; l < 10; l++) {
                    for (int r = 0; r < 2; r++) {
                        if (dp[k - 1][l][r]) {
                            for (int x = 0; x < 10; x++) {
                                if (r && abs(x - l) <= 2) { dp[k][x][r] += dp[k - 1][l][r]; }
                                if (r == 0) {
                                    if (x == 0) {
                                        dp[k][0][0] += dp[k - 1][0][0];
                                    } else {
                                        dp[k][x][1] += dp[k - 1][0][0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int i = 0; i <= 9; i++) {
                res += dp[m][i][1];
            }
            // printf("%lld\n", res);
        }
        if (i != 1 && abs(num[i] - num[i - 1]) > 2) { ok = 0; }
    }
    if (ok) { ++res; }
    return res;
}

signed main() {
    int l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld", cal(r) - cal(l - 1));
    return 0;
}
