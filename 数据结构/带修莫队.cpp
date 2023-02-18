#include <bits/stdc++.h>
using namespace std;
#define rep(a, b, c) for (int a = b; a <= c; a++)
int n, m, x, y, z, k, t1, t2, op, ans, flagg, cnt, tot;
int a[100000];
char ch;
int read() {
    return 1;
}
void write(int num) {
    ;
}
const int N = 100000;

// O((1/4)*n^(5/3)常数如下可被化为1/4)

int buc[N];

struct Block {
    int l, r, id, pos1, pos2, tim, ans;
} block[N];

struct Update {
    int id, pos, pre, aft;
} update[N];

// 实测比一般排序快近一倍
bool cmp(Block a, Block b) {
    if (a.pos1 == b.pos1) {
        if (a.pos2 == b.pos2) {
            if ((a.pos2 & 1) ^ (a.pos1 & 1) ^ 1) { return a.tim > b.tim; }  // 因为时间序最开始在最后
            return a.tim < b.tim;
        }
        if (a.pos1 & 1) return a.pos2 < b.pos2;
        return a.pos2 > b.pos2;
    }
    return a.pos1 < b.pos1;
}

bool cmp_bak(Block a, Block b) {
    if (a.pos1 == b.pos1) {
        if (a.pos2 == b.pos2) { return a.tim < b.tim; }
        return a.pos2 < b.pos2;
    }
    return a.pos1 < b.pos1;
}

bool cmp_id(Block a, Block b) {
    return a.id < b.id;
}

void updatef(int p, int op) {
    if (op == 1) {
        if (buc[p] == 0) { ans++; }
        buc[p]++;

    } else {
        if (buc[p] == 1) { ans--; }
        buc[p]--;
    }
}

signed use_example() {
    int cnt1 = 0, cnt2 = 0;
    int blen = pow(n, 2.0 / 3.0);  // 实测2/3远快于1/2(至少4倍)  1/2还T了
    rep(i, 1, m) {
        ch = 0;
        while (!isupper(ch)) {
            scanf("%c", &ch);
        }
        x = read();
        y = read();
        if (ch == 'Q') {
            block[++cnt1] = {x, y, i, (x - 1) / blen + 1, (y - 1) / blen + 1, cnt2};
        } else {
            update[++cnt2] = {i, x, a[x], y};
            a[x] = y;
        }
    }
    sort(block + 1, block + cnt1 + 1, cmp);
    int pl = 1, pr = 0, pt = cnt2;
    rep(i, 1, cnt1) {
        while (block[i].tim > pt) {
            ++pt;
            if (update[pt].pos >= pl && update[pt].pos <= pr) {
                updatef(update[pt].pre, -1);
                updatef(update[pt].aft, 1);
            }
            a[update[pt].pos] = update[pt].aft;
        }
        while (block[i].tim < pt) {
            if (update[pt].pos >= pl && update[pt].pos <= pr) {
                updatef(update[pt].aft, -1);
                updatef(update[pt].pre, 1);
            }
            a[update[pt].pos] = update[pt].pre;
            pt--;
        }
        while (block[i].r > pr) {
            updatef(a[++pr], 1);
        }
        while (block[i].r < pr) {
            updatef(a[pr--], -1);
        }
        while (block[i].l < pl) {
            updatef(a[--pl], 1);
        }
        while (block[i].l > pl) {
            updatef(a[pl++], -1);
        }
        block[i].ans = ans;
    }
    sort(block + 1, block + cnt1 + 1, cmp_id);
    rep(i, 1, cnt1) {
        write(block[i].ans);
        putchar('\n');
    }
    return 0;
}
