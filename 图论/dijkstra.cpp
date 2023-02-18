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

void dijkstra(int start, int n) {
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    dis[start] = 0;
    for (int k = 1; k <= n; k++) {
        int u = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (u == 0 || dis[u] > dis[i]) u = i;
        }
        vis[u] = 1;
        for (int i = head[u]; i; i = node[i].next) {
            int to = node[i].to;
            int w = node[i].w;
            int t1 = dis[u] + w;
            if (dis[to] > t1) { dis[to] = t1; }
        }
    }
}
