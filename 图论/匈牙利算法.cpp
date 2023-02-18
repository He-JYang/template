const int N = 100000;

struct Node {
    int to, next;
} node[N];

int head[N], color[N];
int vistime[N];
int mch[N];  // 与之配对的点

bool match(int u, int tag) {
    if (vistime[u] == tag) return false;
    vistime[u] = tag;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (mch[to] == 0 || match(mch[to], tag)) {
            mch[to] = u;
            return true;
        }
    }
    return false;
}

int use(int n) {
    int max_matches;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1 && match(i, i)) { ++max_matches; }
    }
    return max_matches;
}
