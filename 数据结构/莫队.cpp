#include <bits/stdc++.h>
using namespace std;
#define rep(a, b, c) for (register int a = b; a <= c; a++)
#define rrep(a, b, c) for (register int a = b; a >= c; a--)
int n, m, x, y, z, k, t1, t2, op, ans, flagg, cnt, tot;
const int N = 1000000;
int a[N];
char ch;

inline int read();
inline void write(int x);

// O(1/4*(n^(3/2)))

int sum;
int buc[N];

struct Block {
    int l, r, id, ansup, ansdown, pos;
} block[N];

bool cmp(Block a, Block b) {
    if (a.pos == b.pos) {
        if (a.pos & 1) return a.r < b.r;
        return a.r > b.r;
    }
    return a.pos < b.pos;
}

bool cmp_id(Block a, Block b) {
    return a.id < b.id;
}

void update(int p, int op) {
    p = a[p];
    sum -= buc[p] * buc[p];
    buc[p] += op;
    sum += buc[p] * buc[p];
}

// CPH ctrl + Alt + B Run All Test On CPH
signed use() {
    // ios::sync_with_stdio(0);
    n = read();
    m = read();
    rep(i, 1, n) {
        a[i] = read();
    }
    int blen = sqrt(n - 1) + 1;
    rep(i, 1, m) {
        block[i].l = read();
        block[i].r = read();
        block[i].id = i;
        block[i].pos = (block[i].l - 1) / blen + 1;
    }

    sort(block + 1, block + m + 1, cmp);
    int pl = 1, pr = 0;
    rep(i, 1, m) {
        while (block[i].r > pr) {
            update(++pr, 1);
        }
        while (block[i].r < pr) {
            update(pr--, -1);
        }
        while (block[i].l < pl) {
            update(--pl, 1);
        }
        while (block[i].l > pl) {
            update(pl++, -1);
        }
        if (block[i].l == block[i].r) {
            block[i].ansdown = 1;
            continue;
        }
        block[i].ansdown = (block[i].r - block[i].l + 1) * (block[i].r - block[i].l);
        block[i].ansup = sum - (block[i].r - block[i].l + 1);
        int gcd = __gcd(block[i].ansup, block[i].ansdown);
        block[i].ansup /= gcd;
        block[i].ansdown /= gcd;
    }
    sort(block + 1, block + m + 1, cmp_id);

    rep(i, 1, m) {
        write(block[i].ansup);
        putchar('/');
        write(block[i].ansdown);
        putchar('\n');
    }

    return 0;
}