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
const int maxn = 111111;
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

vector<int> ve1[maxn];

int dp[111111];
int dp2[111111];
int dp3[111111];
int pre[111111];
int suf[111111];

void dfs(int u) {
    int num = ve1[u].size() - 1;
    dp[u] = 1;
    // cout << u << ' ';
    rep(i, 0, num) {
        int v = ve1[u][i];
        dfs(v);
        dp[u] *= (dp[v] + 1);
        dp[u] %= m;
    }
}

void dfs2(int u) {
    int num = ve1[u].size() - 1;
    suf[num + 1] = 1;
    pre[0] = 1;
    // cout << u << ' ';
    per(i, num, 0) {
        int v = ve1[u][i];
        suf[i] = suf[i + 1] * (dp[v] + 1) % m;
    }

    rep(i, 0, num) {
        int v = ve1[u][i];
        pre[i + 1] = pre[i] * (dp[v] + 1) % m;
    }
    rep(i, 0, num) {
        int v = ve1[u][i];
        dp2[v] = suf[i + 1] * pre[i] % m;
        if (u != 1) { dp2[v] = dp2[v] * (dp2[u] + 1) % m; }
    }
    rep(i, 0, num) {
        int v = ve1[u][i];
        dp3[v] = (dp2[v] + 1) * dp[v] % m;
        dfs2(v);
    }
}

// CPH ctrl + Alt + B Run All Test On CPH
signed main() {
    // ios::sync_with_stdio(0);//can't use printf & scanf but can use gets puts getchar
    // cin.tie(0);//untie cin,cout
    // cout.tie(0);//untie cin,cout
    n = read();
    m = read();
    rep(i, 2, n) {
        int v = read();
        ve1[v].push_back(i);
    }
    dfs(1);
    dfs2(1);
    dp3[1] = dp[1];
    rep(i, 1, n) {
        printf("%lld\n", dp3[i]);
    }

    return 0;
}