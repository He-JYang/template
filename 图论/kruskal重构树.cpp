#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define cf    \
    int _;    \
    cin >> _; \
    while (_--)
typedef pair<int, int> par;
int lowbit(int n) {
    return (n & (-n));
}
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2001000;
const int M = 2000010;
int n, m, k, ans, a, b, T, cnt, tot, top, num, sum, root, mas, Q, x, y, t;
char ch;
int f[N][30];
int dpth[N], dist[N][30];
int smm[N];
struct node {
    int f, t, w;
} arr[M];
bool cmp(node a, node b) {
    return a.w > b.w;
}
vector<int> v[N];
int bcj[N];
int find(int a) {
    if (a == bcj[a]) return a;
    return bcj[a] = find(bcj[a]);
}
void dfs(int u, int father) {
    dpth[u] = dpth[father] + 1;
    f[u][0] = father;
    for (int i = 1; (1 << i) <= dpth[u]; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (auto ed : v[u]) {
        if (ed != father) { dfs(ed, u); }
    }
}
int lca(int x, int y) {
    if (dpth[x] > dpth[y]) swap(x, y);
    per(i, t, 0) {
        if (dpth[x] <= dpth[y] - (1 << i)) y = f[y][i];
    }
    if (x == y) return x;
    per(i, t, 0) {
        if (f[y][i] != f[x][i]) y = f[y][i], x = f[x][i];
    }
    return f[x][0];
}
signed main() {
    n = read();
    m = read();
    rep(i, 1, m) {
        x = read();
        y = read();
        t = read();
        arr[i] = {x, y, t};
    }
    int lim = (n << 1) - 1;
    rep(i, 1, n) bcj[i] = i;
    sort(arr + 1, arr + 1 + m, cmp);
    tot = n;
    rep(i, 1, m) {
        int x = arr[i].f, y = arr[i].t;
        a = find(x);
        b = find(y);
        if (a == b) continue;
        ++tot;
        bcj[a] = tot;
        bcj[b] = tot;
        bcj[tot] = tot;
        smm[tot] = arr[i].w;
        v[tot].push_back(a);
        v[tot].push_back(b);
        if (tot == lim) break;
    }
    t = log(tot) / log(2) + 1;
    for (int i = tot; i > n; --i)  //预处理lca,注意原图可能不联通，所以我们可能构出了一个森林
        if (!dpth[i]) dpth[i] = 1, f[i][0] = i, dfs(i, 0);
    cf {
        a = read();
        b = read();
        // lca 的板子
        if (find(a) != find(b)) {
            cout << -1 << "\n";
            continue;
        }
        int now = lca(a, b);
        printf("%d\n", smm[now]);
    }
    return 0;
}