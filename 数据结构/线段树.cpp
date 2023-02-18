#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int n;

//
const int N = 1e7 + 10;  // N½¨ÒéÎª4*n

struct Segm {
    int value1, tag1;
} segm[N];

void push_up(int p) {
    segm[p].value1 = segm[p * 2].value1 + segm[p * 2 + 1].value1;
}

void push_downf(int p, int l, int r, int tag1) {
    segm[p].tag1 += tag1;
    segm[p].value1 += tag1 * (r - l + 1);
}

void push_down(int p, int l, int r) {
    int mid = (l + r) / 2;
    push_downf(p * 2, l, mid, segm[p].tag1);
    push_downf(p * 2 + 1, mid + 1, r, segm[p].tag1);
    segm[p].tag1 = 0;
}

void build(int p, int l, int r) {
    if (l == r) {
        segm[p].value1 = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    push_up(p);
}

void update(int ql, int qr, int p, int l, int r, int value1) {
    if (ql <= l && qr >= r) {
        segm[p].tag1 += value1;
        segm[p].value1 += (r - l + 1) * value1;
        return;
    }
    int mid = (l + r) / 2;
    push_down(p, l, r);
    if (ql <= mid) update(ql, qr, p * 2, l, mid, value1);
    if (qr > mid) update(ql, qr, p * 2 + 1, mid + 1, r, value1);
    push_up(p);
}

int query(int ql, int qr, int p, int l, int r) {
    int res = 0;
    if (ql <= l && qr >= r) { return segm[p].value1; }
    int mid = (l + r) / 2;
    push_down(p, l, r);
    if (ql <= mid) { res += query(ql, qr, p * 2, l, mid); }
    if (qr > mid) { res += query(ql, qr, p * 2 + 1, mid + 1, r); }
    return res;
}
