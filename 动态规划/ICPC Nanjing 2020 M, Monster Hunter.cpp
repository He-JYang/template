#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2222;

vector<int> e[maxn];

int fa[maxn];

int dp[maxn][maxn][2];
int sz[maxn];
int a[maxn];
const int inf = 1ll << 50;

void dfs(int u) {
    dp[u][1][1] = 0;
    dp[u][0][1] = inf;
    dp[u][1][0] = inf;
    dp[u][0][0] = a[u];
    sz[u]++;
    for (auto v : e[u]) {
        dfs(v);
        static int tmp[maxn][2];
        for (int i = 0; i <= sz[u] + sz[v]; i++) {
            tmp[i][0] = inf;
            tmp[i][1] = inf;
        }
        for (int i = 0; i <= sz[u]; i++) {
            for (int j = 0; j <= sz[v]; j++) {
                tmp[i + j][0] = min(tmp[i + j][0], min(dp[u][i][0] + dp[v][j][0] + a[v], dp[u][i][0] + dp[v][j][1]));
                tmp[i + j][1] = min(tmp[i + j][1], min(dp[u][i][1] + dp[v][j][0], dp[u][i][1] + dp[v][j][1]));
            }
        }
        sz[u] += sz[v];
        for (int i = 0; i <= sz[u]; i++) {
            dp[u][i][0] = tmp[i][0];
            dp[u][i][1] = tmp[i][1];
        }
    }
}

void solve() {
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        sz[i] = 0;
        for (int j = 0; j <= n; j++) {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &fa[i]);
        e[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    dfs(1);
    for (int i = 0; i <= n; i++) {
        printf("%lld", min(dp[1][i][0], dp[1][i][1]));
        printf("%c", " \n"[i == n]);
    }
}

signed main() {
    int T;
    scanf("%lld", &T);
    while (T--) {
        solve();
    }
}