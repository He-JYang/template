#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
typedef pair<int, int> pii;
const int inf = 0x7fffffff;
struct Node {
    int to, next, w;
} node[N];
int head[N], vis[N];

// O(mlogm)
int dis[N];

priority_queue<pii, vector<pii>, greater<pii> > q;

void prim(int n) {
    dis[1] = 0;
    int cnt = 0;
    q.push(make_pair(0, 1));
    while (!q.empty() && cnt < n) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        cnt++;
        vis[u] = 1;
        for (int i = head[u]; i; i = node[i].next) {
            if (node[i].w < dis[node[i].to]) {
                dis[node[i].to] = node[i].w;
                q.push(make_pair(dis[node[i].to], node[i].to));
            }
        }
    }
}