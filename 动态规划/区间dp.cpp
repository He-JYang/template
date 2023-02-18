#include <bits/stdc++.h>
using namespace std;

#define rep(a, b, c) for (int a = b; a <= c; a++)

int dp[111][111];

void solve() {
    int n;
    rep(len, 2, n) {
        rep(i, 1, n) {
            int j = i + len - 1;
            if (j > n) break;
            rep(k, i, j - 1) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
}