#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int ch[N][2], tot, sz[N], val[N], tar[N], root;
mt19937 rnd(time(0));
void display(int u) {
    if (!u) return;
    printf("%d,%d,%d,%d,%d,%d\n", u, val[u], tar[u], sz[u], ch[u][0], ch[u][1]);
    display(ch[u][0]);
    display(ch[u][1]);
}
void pushup(int rt) {
    sz[rt] = sz[ch[rt][0]] + sz[ch[rt][1]] + 1;
}
int merge(int u, int v) {  //保证u树的最大权值小于等于v树的最小权值
    if (!u || !v) return u + v;
    if (tar[u] < tar[v]) {
        ch[u][1] = merge(ch[u][1], v);
        pushup(u);
        return u;
    }
    ch[v][0] = merge(u, ch[v][0]);
    pushup(v);
    return v;
}
void splitv(int rt, int v, int& x, int& y) {
    if (!rt) {
        x = y = 0;
        return;
    }
    if (val[rt] <= v) {
        x = rt;
        splitv(ch[rt][1], v, ch[x][1], y);
    } else {
        y = rt;
        splitv(ch[rt][0], v, x, ch[y][0]);
    }
    pushup(rt);
}
void splitk(int rt, int k, int& x, int& y) {
    if (!rt) {
        x = y = 0;
        return;
    }
    if (sz[ch[rt][0]] + 1 <= k) {
        x = rt;
        splitk(ch[rt][1], k - sz[ch[rt][0]] - 1, ch[x][1], y);
    } else {
        y = rt;
        splitk(ch[rt][0], k, x, ch[y][0]);
    }
    pushup(rt);
}
int newnode(int x) {
    val[++tot] = x;
    sz[tot] = 1;
    tar[tot] = rnd();
    return tot;
}
void insert(int v) {
    if (!root) {
        root = newnode(v);
        return;
    }
    int x, y;
    splitv(root, v, x, y);
    root = merge(merge(x, newnode(v)), y);
}
void del(int v) {
    int x, y, z;
    splitv(root, v, x, z);
    splitv(x, v - 1, x, y);
    root = merge(merge(x, merge(ch[y][0], ch[y][1])), z);
}
int maxt(int rt) {
    while (ch[rt][1])
        rt = ch[rt][1];
    return val[rt];
}
int mint(int rt) {
    while (ch[rt][0])
        rt = ch[rt][0];
    return val[rt];
}
int rankx(int v) {
    int x, y, ans;
    splitv(root, v - 1, x, y);
    ans = sz[x] + 1;
    root = merge(x, y);
    return ans;
}
int findk(int k) {
    int x, y, ans;
    splitk(root, k, x, y);
    ans = maxt(x);
    root = merge(x, y);
    return ans;
}
int pre(int v) {
    int x, y, ans;
    splitv(root, v - 1, x, y);
    ans = maxt(x);
    root = merge(x, y);
    return ans;
}
int nxt(int v) {
    int x, y, ans;
    splitv(root, v, x, y);
    ans = mint(y);
    root = merge(x, y);
    return ans;
}
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
