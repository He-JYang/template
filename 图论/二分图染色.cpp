#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

// O(n+m)

vector<int> mp[maxn];

int color[maxn];
int n, m;
bool bfs_tu(int u) {
    queue<int> que;
    que.push(u);
    color[u] = 1;
    while (que.size()) {
        int x = que.front();
        que.pop();
        for (int i = 1; i <= n; i++) {
            if (mp[x][i]) {
                if (color[i] == -1)  //如果未能染色
                {
                    color[i] = color[x] ^ 1;  //与上一个相连结点颜色要不同
                    que.push(i);
                } else if (color[i] == color[x])  //如果有冲突
                {
                    return false;
                }
            }
        }
    }
    return true;
}
bool match() {
    memset(color, -1, sizeof(color));
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1)  //如果没有染色，就说明这不在上一个连通块里
        {
            if (!bfs_tu(i)) return false;
        }
    }
    return true;
}