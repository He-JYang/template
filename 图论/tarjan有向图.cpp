#include <bits/stdc++.h>
using namespace std;

const int M = 1001, N = 1001;
struct Node {
    int to, next;
} node[2 * M + 10];
int head[N], vis[N];

// O(N+M)

int dfn[N], low[N];      // dfn是严格单调递增的只有low可能变化
int Stack[N], tim, idx;  // tim时间戳
int scc[N];              // s表示属于哪一个强连通分量(strongly connected components)

// tarjan 算法在有向图中用于求强连通分量在无向图中用于求割点和割边（桥）
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    Stack[++idx] = u;
    vis[u] = 1;  // 表示在栈里，最终栈一定是空的
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (!dfn[to]) {
            tarjan(to, u);
            low[u] = min(low[u], low[to]);
        } else if (vis[to]) {
            low[u] = min(low[u], dfn[to]);
            // 在求强连通分量时写 dfn和low都是对的但在求割点与桥时只能写dfn也就是现在这种写法
            // 因为在求强连通分量时只要low!=dfn这个点就会被缩点
        }
    }

    if (low[u] == dfn[u]) {
        while (1) {
            int y = Stack[idx--];
            scc[y] = u;  // 缩点
            vis[y] = false;
            if (u == y) break;
        }
    }
}

int use(int n) {
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, i);

    return 0;
}