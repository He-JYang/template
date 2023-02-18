#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[22][11];
int f[22];
int a[11];

int c[22];

void cal(int n, int xs) {
    int m = 0;
    while (n) {
        c[++m] = n % 10;
        n /= 10;
    }
    reverse(c + 1, c + m + 1);
    for (int i = 1; i <= m; i++) {
        for (int k = 1; k < i; k++) {
            a[c[k]] += xs * f[m - i] * c[i];
        }

        for (int j = 1; j < c[i]; j++) {
            a[j] += xs * f[m - i];
        }
        if (i != 1 && c[i]) a[0] += xs * f[m - i];
        if (i != m) {
            for (int j = 1; j <= 9; j++) {
                a[j] += xs * (m - i) * f[m - i - 1] * c[i];
            }
            if (i != 1) a[0] += xs * (m - i) * f[m - i - 1] * c[i];
        }
        if (i == 1) {
            if (m >= 2) { a[0] += xs * (c[1] - 1) * f[m - 2] * (m - 1); }
            for (int k = 2; k < m; k++) {
                a[0] += xs * 9 * f[m - k - 1] * (m - k);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        a[c[i]] += xs;
    }
}

signed main() {
    int l, r;
    scanf("%lld%lld", &l, &r);
    f[0] = 1;
    for (int i = 1; i < 22; i++) {
        f[i] = f[i - 1] * 10;
    }
    cal(r, 1);
    cal(l - 1, -1);
    for (int i = 0; i < 10; i++) {
        printf("%lld ", a[i]);
    }
}