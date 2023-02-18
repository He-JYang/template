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

// O(mlogm)
int dis[N];

priority_queue<pii, vector<pii>, greater<pii>> pq1;
void dijkstra(int start, int n) {
    pq1.push({0, start});
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    dis[start] = 0;
    while (!pq1.empty()) {
        int u = pq1.top().second;
        pq1.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = node[i].next) {
            int to = node[i].to;
            int w = node[i].w;
            int t1 = dis[u] + w;
            if (t1 < dis[to]) {
                pq1.push({t1, to});
                dis[to] = t1;
            }
        }
    }
}
