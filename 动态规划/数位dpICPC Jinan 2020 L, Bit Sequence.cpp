#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[77][2][2];
int num[77];
int m;
int a[111];
int count1[233];

int n, l;

int dfs(int ind, int ser, int cnt) {
    if (ind > m - 7) {
        int ans = 0;
        for (int i = 0; i < 128; i++) {
            int flag = 1;
            for (int j = 0; j < n; j++) {
                if (a[j] != ((cnt ^ ((i + j >= 128) ? ser : 0)) ^ (count1[i + j]))) {
                    flag = 0;
                    break;
                }
            }
            ans += flag;
        }
        return ans;
    }
    if (f[ind][ser][cnt] != -1) return f[ind][ser][cnt];
    int ans = 0;
    for (int j = 0; j <= 1; j++) {
        ans = ans + dfs(ind + 1, (j == 0 ? 0 : (ser ^ 1ll)), cnt ^ j);
    }
    return f[ind][ser][cnt] = ans;
}

void solve() {
    scanf("%lld%lld", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int rem = l % (1ll << 7);
    // printf("%lld ", rem);
    m = 0;
    while (l) {
        num[++m] = l % 2;
        l /= 2;
    }

    reverse(num + 1, num + 1 + m);
    memset(f, -1, sizeof(f));

    int ans = 0;

    int cnt = 0;
    int ser = 0;
    for (int i = 1; i <= m - 7; i++) {
        for (int j = 0; j < num[i]; j++) {
            ans = ans + dfs(i + 1, (j == 0 ? 0 : (ser ^ 1ll)), cnt ^ j);
        }
        cnt = cnt ^ num[i];
        ser = (num[i] ? (ser ^ 1ll) : 0);
    }

    for (int i = 0; i <= rem; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (a[j] != ((cnt ^ ((i + j >= 128) ? ser : 0)) ^ (count1[i + j]))) {
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    printf("%lld\n", ans);
}

signed main() {
    int T;
    scanf("%lld", &T);

    for (int i = 1; i < 233; i++) {
        int cnt = 0;
        for (int j = 0; j < 8; j++) {
            if ((i >> j) & 1) cnt++;
        }
        count1[i] = cnt & 1;
    }

    while (T--) {
        solve();
    }
}
