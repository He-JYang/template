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

//
// O(mlogm)
int dis[N];
int fa[N];

int found(int x) {
    if (x == fa[x]) return x;
    return fa[x] = found(fa[x]);
}
bool cmp(Node a, Node b) {
    return a.w < b.w;
}

void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

void kruskal() {  // 注意kruskal其实可以只用m而经常被用成2*m用成2m了记得乘2
    sort(node, node + m, cmp);
    //将边的权值排序
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int fau = found(node[i].u), fav = found(node[i].to);
        if (fau == fav) { continue; }
        //若出现两个点已经联通了，则说明这一条边不需要了
        fa[fav] = fau;
        //将eu、ev合并
        if (++cnt == n - 1) { break; }
        //循环结束条件，及边数为点数减一时
    }
}