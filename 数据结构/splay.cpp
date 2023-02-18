#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 2147483647;

int ch[N][2], val[N], cnt[N], sz[N], fa[N], root, tot;

void pushup(int rt) {
    sz[rt] = sz[ch[rt][0]] + sz[ch[rt][1]] + cnt[rt];
}
int dir(int u) {
    return ch[fa[u]][1] == u;
}
void connect(int u, int f, int d) {
    ch[f][d] = u;
    fa[u] = f;
}
void destory(int u, int f) {
    ch[f][dir(u)] = 0;
    fa[u] = 0;
}
void rotate(int u) {
    int f = fa[u], ff = fa[f], du = dir(u);
    if (!f) return;  //已经是根节点
    int df = dir(f);
    connect(u, ff, df), connect(ch[u][du ^ 1], f, du), connect(f, u, du ^ 1);
    pushup(f), pushup(u);
}
void splay(int u, int rt) {
    for (int f = fa[u]; f != rt; f = fa[u]) {
        if (fa[f] != rt) (dir(u) ^ dir(f)) ? rotate(u) : rotate(f);
        rotate(u);
    }
    if (!rt) root = u;
}

void insert(int x) {
    int u = root, f = 0;
    while (u && val[u] != x) {
        f = u;
        u = ch[u][x > val[u]];
    }
    if (u)
        splay(u, 0), cnt[u]++;
    else {
        u = ++tot;
        val[u] = x;
        cnt[u] = sz[u] = 1;
        connect(u, f, x > val[f]);
        splay(u, 0);
    }
}
int fd(int x) {
    int u = root;
    while (u && val[u] != x) {
        u = ch[u][x > val[u]];
    }
    if (u) splay(u, 0);
    return u;
}
void del(int x) {
    int u = fd(x);
    if (!u) return;
    if (cnt[u] > 1)
        cnt[u]--;
    else {
        int v = ch[u][0];
        if (!v) {
            root = ch[u][1];
            destory(root, u);
        } else {
            while (ch[v][1])
                v = ch[v][1];
            splay(v, u);
            u = ch[u][1];
            destory(v, root);
            destory(u, root);
            connect(u, v, 1);
            pushup(v);
            root = v;
        }
    }
}

int rankx(int x) {
    return sz[ch[fd(x)][0]] + 1;
}
int findk(int k) {
    int u = root;
    while (u) {
        if (sz[ch[u][0]] + cnt[u] >= k) {
            if (sz[ch[u][0]] < k) {
                splay(u, 0);
                return val[u];
            } else
                u = ch[u][0];
        } else
            k -= sz[ch[u][0]] + cnt[u], u = ch[u][1];
    }
    return -1;
}

int pre(int x) {
    int u = root, ans = -inf, id = 0;
    while (u) {
        if (val[u] < x && val[u] > ans) ans = val[u], id = u;
        u = ch[u][x > val[u]];
    }
    splay(id, 0);
    return ans;
}
int nxt(int x) {
    int u = root, ans = inf, id = 0;
    while (u) {
        if (val[u] > x && val[u] < ans) ans = val[u], id = u;
        u = ch[u][x >= val[u]];
    }
    splay(id, 0);
    return ans;
}
// void display(int u) {  //用于调试，功能是打印整棵树的所有节点信息
//     if (!u) return;
//     printf("%d,%d,%d,%d,%d,%d\n", u, val[u], cnt[u], sz[u], ch[u][0], ch[u][1]);
//     display(ch[u][0]);
//     display(ch[u][1]);
// }
void use_example() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1) {
            insert(x);
        } else if (op == 2) {
            del(x);
        } else if (op == 3) {
            printf("%d\n", rankx(x));
        } else if (op == 4) {
            printf("%d\n", findk(x));
        } else if (op == 5) {
            printf("%d\n", pre(x));
        } else if (op == 6) {
            printf("%d\n", nxt(x));
        }
    }
}
