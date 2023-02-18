#include <bits/stdc++.h>
#define int long long
// #define int __int128
// #define int unsigned long long
#define double long double  // %Lf
#define rep(a, b, c) for (int a = b; a <= c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)
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

int tmp[2222];

int sz[2222];
int dp[2222][2222];

void dfs(int u, int fa) {
    // cout << u << endl;

    for (int i = 1; i <= n; i++) {
        dp[u][i] = -inf;
    }
    dp[u][0] = 0;

    for (int cnt = head[u]; cnt; cnt = node[cnt].next) {
        int to = node[cnt].to;
        if (to == fa) continue;

        dfs(to, u);
        // for (int i = 1; i <= sz[u] + sz[to]; i++) {
        //     tmp[i] = -inf;
        // }
        // tmp[0] = 0;

        // rep(i, 0, sz[u]) {
        rrep(i, sz[u], 0) {
            for (int j = 0; j <= sz[to]; j++) {
                // tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[to][j]);
                dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[to][j]);
            }
        }
        sz[u] += sz[to];
        // rep(i, 0, sz[u]) {
        //     dp[u][i] = tmp[i];
        // }
    }
    sz[u]++;
    rrep(i, sz[u], 1) {
        dp[u][i] = dp[u][i - 1] + a[u];
    }
    dp[u][0] = 0;
}

// CPH ctrl + Alt + B Run All Test On CPH
signed use_example() {
    n = read();
    m = read();
    rep(i, 2, n) {
        int v = read();
        add(v, i);
        add(i, v);
    }
    rep(i, 1, n) {
        a[i] = read();
    }
    dfs(1, 1);
    rep(i, 1, m) {
        int u = read();
        int num = read();
        printf("%lld\n", dp[u][num]);
    }
    return 0;
}