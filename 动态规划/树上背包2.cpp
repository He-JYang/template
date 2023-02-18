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

int dp[55555][111];
int sz[maxn];

void dfs(int u, int fa) {
    rep(i, 1, min(n, 100ll)) {
        dp[u][i] = -inf;
    }
    dp[u][0] = 0;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (to == fa) continue;
        dfs(to, u);
        per(i, min(sz[u], 100ll), 0) {
            for (int j = 0; j <= sz[to] && i + j <= min(n, 100ll); j++) {
                dp[u][i + j] = max(dp[u][i + j], dp[to][j] + dp[u][i]);
            }
        }
        sz[u] += sz[to];
    }
    sz[u]++;
    per(i, min(sz[u], 100ll), 1) {
        dp[u][i] = dp[u][i - 1] + a[u];
    }
}

// CPH ctrl + Alt + B Run All Test On CPH
signed main() {
    // ios::sync_with_stdio(0);//can't use printf & scanf but can use gets puts getchar
    // cin.tie(0);//untie cin,cout
    // cout.tie(0);//untie cin,cout
    n = read();
    int q = read();
    rep(i, 2, n) {
        int v = read();
        add(i, v);
        add(v, i);
    }
    rep(i, 1, n) {
        a[i] = read();
    }
    dfs(1, 1);

    rep(i, 1, q) {
        int u = read();
        int m = read();
        printf("%lld\n", dp[u][m]);
    }

    return 0;
}