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

// dp[i][j]表示从i~N选的重量不超过j的点集的最大权值和，并且要求这个点集中不存在一个点选了，但他的祖先没有被选的情况

int w[maxn];

int l[maxn];   // u的所含有的结点的最小dfs序（即先序）即他本身
int id[maxn];  // dfs序为i的结点即通过u的dfs序反求u
int r[maxn];   // u的所含有的结点的最大dfs序（即先序）这样r[u]+1就是跳过u这一整个子树的下一个子树

void dfs(int u, int fa) {
    l[u] = ++cnt;
    id[cnt] = u;
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (to == fa) continue;
        dfs(to, u);
    }
    r[u] = cnt;
}

int dp[1111][11111];  // dp[i][j]表示从i~N选的重量不超过j的点集的最大权值和

// CPH ctrl + Alt + B Run All Test On CPH
signed main() {
    // ios::sync_with_stdio(0);//can't use printf & scanf but can use gets puts getchar
    // cin.tie(0);//untie cin,cout
    // cout.tie(0);//untie cin,cout
    n = read();
    m = read();
    rep(i, 2, n) {
        int v = read();
        add(i, v);
        add(v, i);
    }
    rep(i, 1, n) {
        a[i] = read();
    }
    rep(i, 1, n) {
        w[i] = read();
    }

    dfs(1, 1);
    rep(i, 1, m) {
        dp[n + 1][i] = -inf;
    }
    per(i, n, 1) {
        int u = id[i];
        per(j, m, 0) {
            dp[i][j] = dp[r[u] + 1][j];
            if (j >= w[u]) { dp[i][j] = max(dp[i][j], dp[i + 1][j - w[u]] + a[u]); }
        }
    }
    rep(i, 0, m) {
        printf("%lld\n", max(0ll, dp[1][i]));
    }

    return 0;
}