#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[22][11][3][2];
int c[22];

int get_status(int status, int x, int y) {
    if (status == 2) return 2;
    if (x >= y) return 0;
    return status + 1;
}

int cal(int n) {
    if (!n) return 0;
    int m = 0;
    while (n) {
        c[++m] = n % 10;
        n /= 10;
    }
    reverse(c + 1, c + 1 + m);

    int status = 0;
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < c[i]; j++) {
            int ns = get_status(status, c[i - 1], j);
            if (i == 1) ns = 0;
            memset(f, 0, sizeof(f));
            if (i == 1 && !j)
                f[i][j][0][0] = 1;
            else
                f[i][j][ns][1] = 1;

            for (int k = i + 1; k <= m; k++) {
                for (int w = 0; w <= 9; w++) {
                    for (int l = 0; l <= 2; l++) {
                        for (int q = 0; q < 2; q++) {
                            if (f[k - 1][w][l][q]) {
                                for (int x = 0; x <= 9; x++) {
                                    if (!q && !x) {
                                        f[k][0][0][0] += f[k - 1][0][0][0];
                                    } else if (q)

                                        f[k][x][get_status(l, w, x)][1] += f[k - 1][w][l][q];
                                    else
                                        f[k][x][0][1] += f[k - 1][w][l][q];
                                }
                            }
                        }
                    }
                }
            }
            for (int x = 0; x <= 9; x++) {
                res += f[m][x][2][1];
                // printf("%lld ", f[m][x][2][1]);
            }
            // printf("\n");
        }
        if (i > 1) {
            status = get_status(status, c[i - 1], c[i]);
        } else {
            status = 0;
        }
    }

    if (status == 2) res++;

    return res;
}

signed main() {
    int r, l;
    scanf("%lld%lld", &l, &r);
    printf("%lld", cal(r) - cal(l - 1));
}
