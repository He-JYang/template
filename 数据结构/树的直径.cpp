#include <bits/stdc++.h>
using namespace std;
const int N = 11111;
struct Node {
    int to, next, w;
} node[N];

int ans, n, m;
int head[N];

// O(n) 求树直径
// O(nlogn)求覆盖s1所有点的最小树的直径
set<int> s1;

int far;
void dfs(int u, int fa, int len) {
    if (s1.find(u) != s1.end()) {
        if (len > ans) {
            ans = len;
            far = u;
        }
    }
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (to == fa) continue;
        dfs(to, u, len + 1);
    }
}

void solve() {
    for (int i = 1; i <= m; i++) {
        int x;
        s1.insert(x);
    }
    dfs(*s1.begin(), 0, 0);
    dfs(far, 0, 0);
}