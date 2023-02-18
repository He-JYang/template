#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 2147483647;

int ch[N][2], cnt[N], sz[N], val[N], tar[N], fa[N], tot, root;

mt19937 rnd(time(0));

void display(int u) {
    if (!u) return;
    printf("%d,%d,%d,%d,%d,%d,%d,%d\n", u, val[u], cnt[u], sz[u], fa[u], tar[u], ch[u][0], ch[u][1]);
    display(ch[u][0]);
    display(ch[u][1]);
}
void pushup(int rt) {
    sz[rt] = sz[ch[rt][0]] + sz[ch[rt][1]] + cnt[rt];
}
int newnode(int f, int x) {
    val[++tot] = x;
    sz[tot] = cnt[tot] = 1;
    tar[tot] = rnd();
    fa[tot] = f;
    return tot;
}
int dir(int u) {
    return ch[fa[u]][1] == u;
}
void connect(int u, int f, int d) {
    fa[u] = f;
    ch[f][d] = u;
}
void rotate(int u) {
    int f = fa[u], ff = fa[f], du = dir(u);
    if (!f) return;
    int df = dir(f);
    connect(u, ff, df), connect(ch[u][du ^ 1], f, du), connect(f, u, du ^ 1);
    pushup(f), pushup(u);
    if (!ff) root = u;
}
void insert(int& u, int f, int x) {  // 注意第一个参数是引用
    if (!u) {
        u = newnode(f, x);
        return;
    }
    sz[u]++;
    if (val[u] == x) {
        cnt[u]++;
    } else
        insert(ch[u][x > val[u]], u, x);
    if (ch[u][0] && tar[u] > tar[ch[u][0]]) {
        rotate(ch[u][0]);
    } else if (ch[u][1] && tar[u] > tar[ch[u][1]]) {
        rotate(ch[u][1]);
    }
}
void del(int& u, int x) {
    if (!u)
        return;
    else if (val[u] == x) {
        if (cnt[u] > 1) {
            cnt[u]--;
        } else if (ch[u][0] && ch[u][1]) {
            int v;
            if (val[ch[u][0]] < val[ch[u][1]]) {
                v = ch[u][0];
                rotate(v);
                del(ch[v][1], x);
            } else {
                v = ch[u][1];
                rotate(v);
                del(ch[v][0], x);
            }
        } else {
            int v = fa[u];
            fa[u] = 0;
            u = ch[u][0] + ch[u][1];
            fa[u] = v;
            return;
        }
    } else
        del(ch[u][x > val[u]], x);
    pushup(u);
}

int rankx(int x) {
    int u = root, ans = 0;
    while (u) {
        if (val[u] < x)
            ans += sz[ch[u][0]] + cnt[u], u = ch[u][1];
        else
            u = ch[u][0];
    }
    return ans + 1;
}
int findk(int k) {
    int u = root;
    while (u) {
        if (sz[ch[u][0]] + cnt[u] >= k) {
            if (sz[ch[u][0]] < k)
                return val[u];
            else
                u = ch[u][0];
        } else
            k -= sz[ch[u][0]] + cnt[u], u = ch[u][1];
    }
    return -1;
}
int pre(int x) {
    int u = root, ans = -inf;
    while (u) {
        if (val[u] < x && val[u] > ans) ans = val[u];
        u = ch[u][x > val[u]];
    }
    return ans;
}
int nxt(int x) {
    int u = root, ans = inf;
    while (u) {
        if (val[u] > x && val[u] < ans) ans = val[u];
        u = ch[u][x >= val[u]];
    }
    return ans;
}
void example_use() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1) {
            insert(root, 0, x);
        } else if (op == 2) {
            del(root, x);
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
