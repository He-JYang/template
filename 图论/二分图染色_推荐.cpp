const int N = 100000;
// ����ͼ����������ͼ

struct Node {
    int to, next;
} node[N];

// O(n+m)
int head[N];
int color[N];

// Ⱦɫ1��ʾ��ɫ-1��ʾ��ɫ0��ʾûȾ
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