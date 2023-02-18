#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
struct Node {
    int to, next, w, u;
} node[N];
int head[N], tot;
void add(int u, int v, int w = 0) {
    node[++tot] = {v, head[u], w, u};
    head[u] = tot;
}

//

int st[N][__lg(N * 2)], depth[N];

void dfs(int u, int fa) {
    depth[u] = depth[fa] + 1;
    st[u][0] = fa;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (to == fa) continue;
        dfs(to, u);
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v])  // 确保 u 的深度更大
        swap(u, v);
    while (depth[u] > depth[v]) {
        u = st[u][__lg(depth[u] - depth[v])];
    }
    if (u == v) return u;
    for (int i = __lg(depth[u]); i >= 0; i--) {
        if (st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}
int init(int n, int root) {
    dfs(root, root);
    for (int j = 1; j <= __lg(n); j++)
        for (int i = 1; i <= n; i++)
            st[i][j] = st[st[i][j - 1]][j - 1];
}