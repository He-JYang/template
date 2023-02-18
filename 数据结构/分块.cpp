#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 100000;
int a[N];

// O(m¸ùn)
int bl[N], br[N], bt[N];  // bl(block left)  br(block right) bt(belong to block)
int bval1[N];             // bval1(block value 1)
int btag1[N];

void init() {
    int blen = sqrt(n);
    int cnt1 = (n + blen - 1) / blen;
    for (int i = 1; i <= cnt1; i++) {
        bl[i] = (i - 1) * blen + 1;
        br[i] = (i)*blen;
    }
    br[cnt1] = n;
    for (int i = 1; i <= n; i++) {
        int t1 = (i - 1) / blen + 1;
        bt[i] = t1;
        bval1[t1] += a[i];
    }
}

void update(int l, int r, int val) {
    int pl = bt[l], pr = bt[r];
    if (pl == pr) {
        for (int i = l; i <= r; i++) {
            a[i] += val;
        }
    } else {
        for (int i = pl + 1; i <= pr - 1; i++) {
            btag1[i] += val;
        }
        for (int i = l; i <= br[pl]; i++) {
            a[i] += val;
            bval1[pl] += val;
        }
        for (int i = bl[pr]; i <= r; i++) {
            a[i] += val;
            bval1[pr] += val;
        }
    }
}

int query(int l, int r) {
    int pl = bt[l], pr = bt[r];
    int res = 0;
    if (pl == pr) {
        for (int i = l; i <= r; i++) {
            res += a[i] + btag1[pl];
        }
        return res;
    } else {
        for (int i = pl + 1; i <= pr - 1; i++) {
            res += (br[i] - bl[i] + 1) * btag1[i] + bval1[i];
        }
        for (int i = l; i <= br[pl]; i++) {
            res += (a[i] + btag1[pl]);
        }
        for (int i = bl[pr]; i <= r; i++) {
            res += (a[i] + btag1[pr]);
        }
    }
    return res;
}