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
const ll INF = (ll)9e18;
const double PI = acosl(-1);
const double one = 1.0;
const int inf = 0x7fffffff;
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

int dp[2222];
int sdp[2222];
int fa[2222];
int depth[2222];

vector<array<int, 3>> ve1[2222];

void dfs1(int u, int fa) {
    depth[u] = depth[fa] + 1;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (to == fa) continue;
        dfs1(to, u);
    }
}

void dfs(int u, int father) {
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (to == father) continue;
        dfs(to, u);
        sdp[u] += dp[to];
    }
    int num = ve1[u].size() - 1;
    dp[u] = sdp[u];
    rep(i, 0, num) {
        int u1 = ve1[u][i][0];
        int u2 = ve1[u][i][1];
        int w = ve1[u][i][2];
        int tmp = w + sdp[u];
        while (u1 != u) {
            tmp += sdp[u1] - dp[u1];
            u1 = fa[u1];
        }
        while (u2 != u) {
            tmp += sdp[u2] - dp[u2];
            u2 = fa[u2];
        }
        dp[u] = max(dp[u], tmp);
    }
}

// CPH ctrl + Alt + B Run All Test On CPH
signed main() {
    // ios::sync_with_stdio(0);//can't use printf & scanf but can use gets puts getchar
    // cin.tie(0);//untie cin,cout
    // cout.tie(0);//untie cin,cout

    int n = read();
    int m = read();
    fa[1] = 1;
    rep(i, 2, n) {
        int v = read();
        fa[i] = v;
        add(v, i);
    }
    dfs1(1, 1);
    rep(i, 1, m) {
        int u = read();
        int v = read();
        int w = read();
        int ut = u, vt = v;
        while (ut != vt) {
            if (depth[ut] > depth[vt]) {
                ut = fa[ut];
            } else {
                vt = fa[vt];
            }
        }
        // cout << ut << endl;
        ve1[ut].push_back({u, v, w});
    }

    dfs(1, 1);
    cout << dp[1];

    return 0;
}