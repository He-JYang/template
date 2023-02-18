#include <bits/stdc++.h>
#define int long long
// #define int __int128
// #define int unsigned long long
#define double long double  // %Lf
#define rep(a, b, c) for (register int a = b; a <= c; a++)
#define rrep(a, b, c) for (register int a = b; a >= c; a--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
// mt19937 mrand(time(0));
// mt19937_64 mrand(time(0));
const ll INF = (ll)9e18;
const double PI = acosl(-1);
const int inf = 0x7fffffff;
const int maxn = 1e7 + 10;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const ull hashmod = 1e18 + 2049;
int n, m, x, y, z, k, t1, t2, op, ans, flagg, cnt, tot;
int a[maxn];
char ch;

struct Node {
    int to, next, w, u;
} node[maxn];

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
struct Block {
    int l, r, id, pos, ans;
} block[maxn];

bool cmp(Block a, Block b) {
    if (a.pos == b.pos) return a.r < b.r;
    return a.pos < b.pos;
}

bool cmp_id(Block a, Block b) {
    return a.id < b.id;
}

int buc1[maxn];
int buc2[maxn];
int clear[maxn];

void cal(Block& blocki) {
    rep(i, blocki.l, blocki.r) {
        buc1[a[i]] = 0;
    }
    rep(i, blocki.l, blocki.r) {
        if (!buc1[a[i]]) {
            buc1[a[i]] = i;
        } else {
            blocki.ans = max(blocki.ans, i - buc1[a[i]]);
        }
    }
    rep(i, blocki.l, blocki.r) {
        buc1[a[i]] = 0;
    }
}

int discre[maxn];
// CPH ctrl + Alt + B Run All Test On CPH
signed use() {
    // ios::sync_with_stdio(0);
    n = read();
    rep(i, 1, n) {
        discre[i] = a[i] = read();
    }

    sort(discre + 1, discre + n + 1);
    int num1 = unique(discre + 1, discre + n + 1) - discre - 1;
    rep(i, 1, n) {
        a[i] = lower_bound(discre + 1, discre + num1 + 1, a[i]) - discre;
    }

    // rep(i, 1, n) {
    //     cout << a[i] << ' ';
    // }

    int blen = sqrt(n - 1) + 1;

    m = read();
    rep(i, 1, m) {
        x = read();
        y = read();
        block[i] = {x, y, i, (x - 1) / blen + 1};
    }

    sort(block + 1, block + m + 1, cmp);
    int pl = 1, pr = 0;
    int cnt1 = 0;
    for (int i = 1; i <= m;) {
        int br = min(block[i].pos * blen, n);
        pr = br;
        int ans = 0;
        for (int j = block[i].pos; i <= m && j == block[i].pos; i++) {
            pl = br + 1;
            if (block[i].r <= br) {
                cal(block[i]);
                continue;
            }
            while (block[i].r > pr) {
                ++pr;
                buc2[a[pr]] = pr;
                if (buc1[a[pr]] == 0) {
                    buc1[a[pr]] = pr;
                    clear[++cnt1] = a[pr];
                }
                ans = max(ans, pr - buc1[a[pr]]);
            }
            int t1 = ans;
            while (block[i].l < pl) {
                --pl;
                if (!buc2[a[pl]]) {
                    buc2[a[pl]] = pl;
                } else {
                    ans = max(buc2[a[pl]] - pl, ans);
                }
            }
            block[i].ans = ans;
            while (pl <= br) {
                if (buc2[a[pl]] == pl) buc2[a[pl]] = 0;
                ++pl;
            }
            ans = t1;
        }
        rep(i, 1, cnt1) {
            buc1[clear[i]] = buc2[clear[i]] = 0;
        }
        cnt1 = 0;
    }

    sort(block + 1, block + m + 1, cmp_id);

    rep(i, 1, m) {
        write(block[i].ans);
        putchar('\n');
    }

    return 0;
}