#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
typedef pair<int, int> pii;
const int inf = 0x7fffffff;
struct Node {
    int to, next, w, u;
} node[N];
int head[N], vis[N];
int n, m;

// O(nlogn) ‘§¥¶¿Ì O(1)≤È—Ø

const int LOGN = __lg(N * 4);
int root, a[N], deepth[N];
int f[N * 2], tot, pos[N];
struct LCA_ST {
    int id;
    bool operator<(const LCA_ST& t) const { return deepth[id] < deepth[t.id]; }
} st[N * 2][LOGN];
inline int LCA(int u, int v) {
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);
    int k = __lg(v - u + 1);
    return min(st[u][k], st[v - (1 << k) + 1][k]).id;
}
inline void dfs(int now, int fa) {
    deepth[now] = deepth[fa] + 1;
    f[++tot] = now;
    pos[now] = tot;
    for (int i = head[now]; i; i = node[i].next) {
        int to = node[i].to;
        if (to == fa) continue;
        dfs(to, now);
        f[++tot] = now;
    }
}
void init() {
    dfs(root, root);
    for (int i = 1; i <= tot; i++) {
        st[i][0].id = f[i];
    }
    for (int j = 1; j < LOGN; j++)
        for (int i = 1; i + (1 << j) - 1 <= tot; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}