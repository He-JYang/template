#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
const int maxn = 2.5e4 + 10, maxm = 2 * (1e5 + 10);
typedef long long ll;
typedef pair<int, int> pii;
int T, R, P, S;
int dis[maxn], head[maxn], tot;
bool vis[maxn];
struct Edge {
    int next, to, w;
} edge[maxm];
void spfa() {
    deque<int> dq;
    dq.push_back(S);
    vis[S] = 1;
    memset(dis, 0x7f, sizeof(dis));
    dis[S] = 0;
    while (!dq.empty()) {
        int now = dq.front();
        dq.pop_front();
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            if (dis[to] > dis[now] + edge[i].w) {
                dis[to] = dis[now] + edge[i].w;
                if (!vis[to]) {
                    if (!dq.empty() && dis[to] <= dis[dq.front()])
                        dq.push_front(to);
                    else
                        dq.push_back(to);
                    vis[to] = 1;
                }
            }
        }
        vis[now] = 0;
    }
}
void add(int x, int y, int z) {
    edge[++tot] = Edge{head[x], y, z};
    head[x] = tot;
}
int main() {
    int i, j, k;
    int x, y, z;
    scanf("%d%d%d%d", &T, &R, &P, &S);
    for (i = 1; i <= R; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    for (i = 1; i <= P; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    spfa();
    for (i = 1; i <= T; i++) {
        if (dis[i] != 0x7f7f7f7f) {
            printf("%d\n", dis[i]);
        } else {
            printf("NO PATH\n");
        }
    }
}
