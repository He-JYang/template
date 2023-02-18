#include <bits/stdc++.h>
using namespace std;
#define rep(a, b, c) for (int a = b; a <= c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)
const int N = 3333;
const int ainf = 0x3f3f3f3f;  // addable inf 可加无穷大
int n, m, tot;
int a[N];
struct Node {
    int to, next, w, u;
} node[2 * N];
int head[N], vis[N];
inline void add(int a, int b, int c = 0) {
    node[++tot] = {b, head[a], c, a};
    head[a] = tot;
}

inline int read();

// O(n*m)

int dp[3333][3333];
int ind[3333];
int rind[3333];
int sz[3333];

int cnt1 = 0;

void dfs(int u) {
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        dfs(to);
        sz[u] += sz[to];
    }
    sz[u]++;
    ind[u] = ++cnt1;
}

signed use_example() {
    n = read();
    m = read();
    int ans = 0;
    rep(u, 1, n - m) {
        int k = read();
        rep(i, 1, k) {
            int v = read();
            int w = read();
            add(u, v, -w);
            a[v] = -w;
        }
    }
    rep(i, n - m + 1, n) {
        a[i] += read();
    }

    dfs(1);

    rep(i, 1, n) {
        rind[ind[i]] = i;
    }

    rep(i, 0, n) {
        rep(j, 1, n) {
            dp[i][j] = -ainf;
        }
    }

    rep(i, 1, n) {
        int num = rind[i];
        rrep(j, m, 1) {
            if (num >= n - m + 1) {
                dp[i][j] = max(dp[i - 1][j - 1] + a[num], dp[i - 1][j]);
            } else {
                dp[i][j] = max(dp[i - 1][j] + a[num], dp[i - sz[num]][j]);
            }
        }
    }

    rep(i, 1, m) {
        if (dp[ind[1]][i] >= 0) { ans = i; }
    }
    cout << ans;
    return 0;
}

// 来源：洛谷P1273 有线电视网