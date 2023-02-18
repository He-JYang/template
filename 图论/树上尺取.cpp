#include <bits/stdc++.h>
#define rep(a, b, c) for (int a = b; a <= c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)
using namespace std;
const int N = 1e4;
int n, m, x, y, z, k, t1, t2, op, ans, flagg, cnt, tot;
int a[N];
const int inf = 0x7fffffff;
char ch;

struct Node {
    int to, next, w, u;
} node[2 * N];

int head[N], vis[N];

inline void add(int a, int b, int c = 0) {
    node[++tot] = {b, head[a], c, a};
    head[a] = tot;
}

inline int read();

// O(n^2)

int dis[N];  // 到直径一端的距离
int len, far, farl, farr;
int fa[N];   // 用fa数组遍历直径
int des[N];  // 存是否为直径点

void dfs(int u, int father) {
    if (dis[u] > len) {
        len = dis[u];
        far = u;
    }
    fa[u] = father;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        int w = node[i].w;
        if (to == father) continue;
        dis[to] = dis[u] + w;
        dfs(to, u);
    }
}

void dfs2(int u, int vfa, int dis) {
    a[u] = dis;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (to == vfa || des[to]) continue;
        dfs2(to, u, dis + node[i].w);
        a[u] = max(a[to], a[u]);
    }
}

signed use_example() {
    n = read();
    m = read();
    rep(i, 1, n - 1) {
        int u = read();
        int v = read();
        int w = read();
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, 1);
    farr = far;
    len = 0;
    rep(i, 1, n) {
        dis[i] = 0;
    }
    dfs(far, far);
    farl = far;
    fa[farr] = 0;
    for (int i = farl; i; i = fa[i]) {
        des[i] = 1;
    }
    for (int i = farl; i; i = fa[i]) {
        dfs2(i, i, 0);
    }
    ans = inf;
    for (int i = farl; i; i = fa[i]) {
        int maxa = a[i];
        for (int j = i; j; j = fa[j]) {
            int tmpans = dis[farl] - dis[i];
            if (dis[i] - dis[j] > m) break;
            tmpans = max(tmpans, dis[j]);
            maxa = max(maxa, a[j]);
            tmpans = max(tmpans, maxa);
            ans = min(ans, tmpans);
        }
    }

    cout << ans;

    return 0;
}

// 源自洛谷P1099树网的核