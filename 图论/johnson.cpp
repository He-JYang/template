#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 3e3 + 10;
const int inf = 0x7fffffff;
int tot;
struct Node {
    int to, next, w;
} node[N];
int head[N], vis[N];
inline void add(int a, int b, int c = 0) {
    node[++tot] = {b, head[a], c};
    head[a] = tot;
}

// O(nmlogm)
//

int h[N], in[N];
int dis[N];
int disMatrix[N][N];  // 距离矩阵 存从i出发到j的最短路距离

queue<int> q1;
bool spfa(int start, int n) {
    for (int i = 1; i <= n; i++) {
        h[i] = inf;
    }
    h[start] = 0;
    q1.push(start);

    while (!q1.empty()) {
        int u = q1.front();
        q1.pop();
        vis[u] = 0;  // vis表示是否在队列中
        for (int i = head[u]; i; i = node[i].next) {
            int to = node[i].to;
            int w = node[i].w;
            int t1 = h[u] + w;
            if (t1 < h[to]) {
                h[to] = t1;
                if (!vis[to]) {
                    q1.push(to);
                    vis[to] = 1;
                    in[to]++;
                    if (in[to] > n) return false;  // 若一个点入队超过n次则存在负权环
                }
            }
        }
    }
    return true;
}

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

// johnson全源最短路 若存在负环返回false
bool johnson(int n) {
    for (int i = 1; i <= n; i++) {
        add(0, i, 0);
    }
    if (!spfa(0, n)) return false;
    for (int u = 1; u <= n; u++) {
        for (int i = head[u]; i; i = node[i].next) {
            int to = node[i].to;
            node[i].w = node[i].w + h[u] - h[to];
        }
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i, n);
        for (int j = 1; j <= n; j++) {
            vis[j] = 0;  // spfa跑完vis是全空 dijkstra跑完能到的vis全满
            if (dis[j] != inf) {
                disMatrix[i][j] = dis[j] - h[i] + h[j];
            } else {
                disMatrix[i][j] = inf;
            }
        }
    }
    return true;
}
