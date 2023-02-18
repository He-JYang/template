#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000010;
const long long INF = 1e18;

struct Node {
    int to, next, w;
} node[2 * N * N];
int head[N], tot;

void add(int u, int v, int w = 0) {
    node[++tot] = {v, head[u], w};
    head[u] = tot;
}

// O(n^2*m)

// 注边的最大应改为至少 N * M * 2 +N+M

int n, m, dinicS, dinicT, lv[N], cur[N];  // lv是每个点的层数，cur用于当前弧优化标记增广起点
// 弧优化。因为在Dinic算法中，一条边增广一次后就不会再次增广了，
// 所以下次增广时不需要再考虑这条边。我们把head数组复制一份，但不断更新增广的起点。

inline bool bfs()  // BFS分层
{
    memset(lv, -1, sizeof(lv));
    lv[dinicS] = 0;
    memcpy(cur, head, sizeof(head));  // 当前弧优化初始化
    queue<int> q;
    q.push(dinicS);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int eg = head[p]; eg; eg = node[eg].next) {
            int to = node[eg].to, vol = node[eg].w;
            if (vol > 0 && lv[to] == -1) lv[to] = lv[p] + 1, q.push(to);
        }
    }
    return lv[dinicT] != -1;  // 如果汇点未访问过说明已经无法达到汇点，此时返回false
}
int dfs(int p = dinicS, int flow = INF) {
    if (p == dinicT) return flow;
    int rmn = flow;                                       // 剩余的流量
    for (int eg = cur[p]; eg && rmn; eg = node[eg].next)  // 如果已经没有剩余流量则退出
    {
        cur[p] = eg;  // 当前弧优化，更新当前弧
        int to = node[eg].to, vol = node[eg].w;
        if (vol > 0 && lv[to] == lv[p] + 1)  // 往层数高的方向增广
        {
            int c = dfs(to, min(vol, rmn));  // 尽可能多地传递流量
            rmn -= c;                        // 剩余流量减少
            node[eg].w -= c;                 // 更新残余容量
            node[eg ^ 1].w += c;             // 再次提醒，链式前向星的cnt需要初始化为1（或-1）才能这样求反向边
        }
    }
    return flow - rmn;  // 返回传递出去的流量的大小
}
inline int dinic() {
    int ans = 0;
    while (bfs())
        ans += dfs();
    return ans;
}
void use_dinic_example() {
    int n, m;

    //

    tot = 1;
    dinicS = n + m + 1;
    dinicT = n + m + 2;
    for (int i = 1; i <= n; i++) {
        int w;
        add(dinicS, i, w);
        add(i, dinicS, 0);
    }
    for (int i = n + 1; i <= m + n; i++) {
        int w;
        add(i, dinicT, w);
        add(dinicT, i, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int w;
            add(i, j, w);
            add(j, i, 0);
        }
    }
    dinic();
}