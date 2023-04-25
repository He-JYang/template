#include <bits/stdc++.h>

using namespace std;
const int N = 5010;

int mod = 998244353;

// 组合数杨辉三角

int C[N + 1][N + 1];

int calC() {
    for (int i = 0; i <= N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

int C_n_m(int n, int m) {
    return C[n][m];
}
