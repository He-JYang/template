#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100000;

struct Node {
    int to, next;
} node[N];

int head[N], tot;
int dfn[N], vis[N], low[N], tim;
int scc[N], scc_sum;

void add(int a, int b) {
    node[++tot] = {b, head[a]};
    head[a] = tot;
}

stack<int> st1;
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    st1.push(u);
    vis[u] = 1;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (!dfn[to]) {
            tarjan(to, u);
            low[u] = min(low[to], low[u]);
        } else if (vis[to]) {
            low[u] = min(low[u], dfn[to]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc_sum;
        while (1) {
            int x = st1.top();
            st1.pop();
            scc[x] = scc_sum;
            vis[x] = 0;
            if (x == u) break;
        }
    }
}

signed use(int n, int m) {
    for (int i = 1; i <= m; i++) {
        int a, va, b, vb, op;
        if (op == 1) {  // a=va或b=vb
            add(a + n * (va ^ 1), b + n * vb);
            add(b + n * (vb ^ 1), a + n * va);
        }
        if (op == 2) {  // a=va时b=vb b=vb时a=va
            add(a + n * va, b + n * vb);
            add(a + n * (va ^ 1), b + n * (vb ^ 1));
        }
        if (op == 3) {  // a=va必成立
            add(a + n * (va ^ 1), a + n * (va));
        }
    }
    // node[i]=1表示i为真 node[i+n]=1表示i为假
    for (int i = 1; i <= 2 * n; i++) {
        if (!dfn[i]) tarjan(i, i);
    }
    // 一个变量的真和假存在同一个强连通分量中就不可能实现
    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[i + n]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    // 每个变量取拓扑序大的值（0或1）即可
    for (int i = 1; i <= n; i++) {
        printf("%lld ", scc[i] > scc[i + n]);
    }

    return 0;
}
