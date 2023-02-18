#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
typedef pair<int, int> pii;
const int inf = 0x7fffffff;
struct Node {
    int to, next, w;
} node[N];
int head[N], vis[N];

// O(n^2)
int dis[N];

int prim(int n) {
    for (int i = 2; i <= n; ++i) {
        dis[i] = inf;
    }
    int cnt = 0, u = 1;
    while (++cnt <= n)  //最小生成树边数等于点数-1但为了让连通图所有点vis都等于1
    {
        int minw = inf;
        vis[u] = 1;
        for (int i = head[u]; i; i = node[i].next) {
            int to = node[i].to;
            if (dis[to] > node[i].w && !vis[to]) { dis[to] = node[i].w; }
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && minw > dis[i]) {
                minw = dis[i];
                u = i;
            }
        }
    }
    return 0;
}