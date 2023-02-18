#include <bits/stdc++.h>

#define int long long

using namespace std;

int f[22][222];
int num[22];
int prime[222];

int cal(int n) {
    int m = 0;
    while (n) {
        num[++m] = n % 10;
        n /= 10;
    }
    reverse(num + 1, num + m + 1);
    int sum = 0;
    int t1 = 0;
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < num[i]; j++) {
            memset(f, 0, sizeof(f));
            t1 = sum + j;
            f[i][t1] = 1;

            for (int k = i + 1; k <= m; k++) {
                for (int l = 0; l <= 9 * k; l++) {
                    for (int x = 0; x <= 9; x++) {
                        if (f[k - 1][l]) { f[k][l + x] += f[k - 1][l]; }
                    }
                }
            }
            for (int l = 0; l <= 200; l++) {
                // printf("%lld ", f[m][i]);

                if (prime[l]) res += f[m][l];
            }
        }
        sum += num[i];
    }
    if (prime[sum]) res++;

    return res;
}

signed main() {
    for (int i = 2; i <= 200; i++) {
        prime[i] = 1;
    }

    for (int i = 2; i <= 200; i++) {
        if (prime[i]) {
            for (int j = 2; i * j <= 200; j++) {
                prime[i * j] = 0;
            }
        }
    }

    int l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld", cal(r) - cal(l - 1));
}