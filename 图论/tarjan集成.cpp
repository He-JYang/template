#include <bits/stdc++.h>
using namespace std;

const int M = 1001, N = 1001;
struct Node {
    int to, next;
} node[2 * M + 10];
int head[N], vis[N];

// O(N+M)
//

int dfn[N], low[N];      // dfn是严格单调递增的只有low可能变化
int Stack[N], tim, idx;  // tim时间戳
int scc[N], p[N];        // s表示属于哪一个强连通分量(strongly connected components)，p表示点权
int cp[N];               // 割点cut_point的缩写
int scc_cnt;             // 强连通分量序即逆拓扑序
set<pair<int, int>> brige;

// tarjan 算法在有向图中用于求强连通分量在无向图中用于求割点和割边（桥）
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    Stack[++idx] = u;
    vis[u] = 1;     // 表示在栈里，最终栈一定是空的
    int child = 0;  //代表子树的数量在求割点与桥时在根节点判断是否为割点或桥时才用
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (!dfn[to]) {
            child++;  // 求割点或桥时这个计数只在判断根节点时才使用
            tarjan(to, u);
            low[u] = min(low[u], low[to]);
            if (low[to] >= dfn[u] && u != fa) {  // 求割点用>=求桥用>
                cp[u] = true;
                // brige.insert({u, to});
            }
        }
        // 求强连通分量
        else if (vis[to]) {
            low[u] = min(low[u], dfn[to]);
            // 在求强连通分量时写 dfn和low都是对的但在求割点与桥时只能写dfn也就是现在这种写法
            // 因为在求强连通分量时只要low!=dfn这个点就会被缩点
        }
        // 求割点或桥
        // else if (dfn[to] < dfn[u] && to != fa) {
        //     low[u] = min(low[u], dfn[to]);
        // }
    }

    if (low[u] == dfn[u]) {
        // scc_cnt++;
        while (1) {
            int y = Stack[idx--];
            scc[y] = u;  // 缩点
            // scc[y] = scc_cnt; // 顺便求逆拓扑序
            vis[y] = false;
            if (u == y) break;
            p[u] += p[y];  // 将点上的信息全部加到代表元（点）上（点权等）
        }
    }
    if (fa == u && child > 1) { cp[u] = true; }  // 判断根节点是否为割点
}

int use(int n) {
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, i);

    return 0;
}