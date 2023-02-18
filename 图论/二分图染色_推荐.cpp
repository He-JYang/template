const int N = 100000;
// 二分图本质是无向图

struct Node {
    int to, next;
} node[N];

// O(n+m)
int head[N];
int color[N];

// 染色1表示白色-1表示黑色0表示没染
bool dfs(int v, int c) {
    color[v] = c;
    for (int i = head[v]; i; i = node[i].next) {
        int to = node[i].to;
        if (color[to] == c) return false;
        if (color[to] == 0 && !dfs(to, -c)) return false;
    }
    return true;
}

bool use(int n) {
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1)) return false;
        }
    }
    return true;
}