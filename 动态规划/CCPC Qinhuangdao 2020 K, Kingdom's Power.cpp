#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;

vector<int> e[maxn];

int fa[maxn];

int dp[maxn][2];
int dep[maxn];

void dfs(int u) {
    dp[u][1] = dep[u];
    for (auto v : e[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
        dp[u][1] = min({
            dp[u][1] + dp[v][1],
            dp[u][1] + dp[v][0] + 2,
            dp[u][0] + dp[v][1],
        });
        dp[u][0] += dp[v][0] + 2;
    }
}

void solve() {
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        e[i].clear();
    }
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &fa[i]);
        e[fa[i]].push_back(i);
    }

    dfs(1);
}

signed main() {
    int T;
    scanf("%lld", &T);
    int cnt = 0;
    while (T--) {
        solve();
        cnt++;
        printf("Case #%lld: %lld\n", cnt, min(dp[1][1], dp[1][0]));
    }
}
