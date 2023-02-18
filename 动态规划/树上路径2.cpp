#include <bits/stdc++.h>
#define int long long
// #define int __int128
// #define int unsigned long long
#define double long double  // %Lf
#define rep(a, b, c) for (int a = b; a <= c; a++)
#define per(a, b, c) for (int a = b; a >= c; a--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
// mt19937 mrand(time(0));
// mt19937_64 mrand(time(0));
// const ll INF = (ll)9e18;
const double PI = acosl(-1);
const double one = 1.0;
const int int_inf = 0x7fffffff;
const int inf = int_inf * 2222;
const int maxn = 1e7 + 10;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const ull hashmod = 1e18 + 2049;
int n, m, x, y, z, k, t1, t2, op, ans, mflag, cnt, tot;
int a[maxn];
char ch;

struct Node {
    int to, next, w, u;
} node[2 * maxn];

int head[maxn], vis[maxn];

inline void add(int a, int b, int c = 0) {
    node[++tot] = {b, head[a], c, a};
    head[a] = tot;
}

inline int read() {
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

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
// cur ctrl+enter  Insert line below

vector<array<int, 3>> ve1[2222];

int fa[2222];
int dp[2222][2222];
int pre[2222];
int suf1[2222];
int suf2[2222];
int depth[2222];
void dfs1(int u) {
    depth[u] = depth[fa[u]] + 1;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        dfs1(to);
    }
}

void dfs(int u) {
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        dfs(to);
    }

    rep(i, 1, depth[u]) {
        dp[u][i] = inf;
    }
    int range = ve1[u].size() - 1;
    rep(i, 0, range) {
        int v = ve1[u][i][1];
        int w = ve1[u][i][2];
        dp[u][depth[v]] = min(w, dp[u][depth[v]]);
    }
    suf1[depth[u] + 2] = inf;
    suf2[depth[u] + 2] = inf;

    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        per(i, depth[u] + 1, 1) {
            suf1[i] = min(suf1[i + 1], dp[u][i]);
            suf2[i] = min(suf2[i + 1], dp[to][i]);
        }
        rep(i, 1, depth[u] + 1) {
            dp[u][i] = min(dp[u][i] + suf2[i], dp[to][i] + suf1[i]);
        }
    }

    // rep(i, 1, depth[u]) {
    //     cout << dp[u][i] << ' ';
    // }
    // cout << endl;
}

// CPH ctrl + Alt + B Run All Test On CPH
signed main() {
    // ios::sync_with_stdio(0);//can't use printf & scanf but can use gets puts getchar
    // cin.tie(0);//untie cin,cout
    // cout.tie(0);//untie cin,cout
    n = read();
    m = read();
    fa[1] = 1;
    rep(i, 2, n) {
        fa[i] = read();
        add(fa[i], i);
    }
    dfs1(1);
    rep(i, 1, m) {
        int u = read();
        int v = read();
        int w = read();
        ve1[v].push_back({v, u, w});
    }
    dfs(1);
    if (dp[1][1] >= inf)
        cout << -1;
    else
        cout << dp[1][1];
    return 0;
}