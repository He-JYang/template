#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
typedef pair<int, int> pii;
const int inf = 0x7fffffff;
struct Node {
    int to, next, w;
} node[N];
int head[N], vis[N];

/*** SPFA(shortest path faster algorithm) ***/
// 玄学：O(n ~ n*m)不等
//
int dis[N], in[N];

queue<int> q1;
bool spfa(int start, int n) {
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    dis[start] = 0;
    q1.push(start);

    while (!q1.empty()) {
        int u = q1.front();
        q1.pop();
        vis[u] = 0;  // vis表示是否在队列中
        for (int i = head[u]; i; i = node[i].next) {
            int to = node[i].to;
            int w = node[i].w;
            int t1 = dis[u] + w;
            if (t1 < dis[to]) {
                dis[to] = t1;
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
