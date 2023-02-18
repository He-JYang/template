#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[22][22][2][2];

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
    reverse(num + 1, num + m + 1);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (dp[i - 1][j][k][l])
                        for (int x = 0; x < 10; x++) {
                            if (l) {
                                if (x == num[i]) {
                                    if (k == 0)
                                        dp[i][x][1][1] += dp[i - 1][j][k][l];
                                    else if (abs(x - j) <= 2)
                                        dp[i][x][1][1] += dp[i - 1][j][k][l];
                                } else if (x < num[i]) {
                                    if (k == 0) {
                                        if (x == 0) {
                                            dp[i][x][0][0] += dp[i - 1][j][k][l];
                                        } else {
                                            dp[i][x][1][0] += dp[i - 1][j][k][l];
                                        }
                                    } else if (abs(x - j) <= 2)
                                        dp[i][x][1][0] += dp[i - 1][j][k][l];
                                }
                            } else {
                                if (k == 1 && abs(x - j) <= 2) { dp[i][x][1][0] += dp[i - 1][j][k][l]; }
                                if (k == 0) {
                                    if (x == 0 && j == 0) {
                                        dp[i][x][0][0] += dp[i - 1][j][k][l];
                                    } else {
                                        dp[i][x][1][0] += dp[i - 1][j][k][l];
                                    }
                                }
                            }
                        }
                }
            }
        }
    }

    for (int i = 0; i <= 9; i++) {
        res += dp[m][i][1][0] + dp[m][i][1][1];
    }

    return res;
}

signed main() {
    int l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld", cal(r) - cal(l - 1));
    return 0;
}
