const int N = 100000;

//
int fa[N], d[N];  // d为到父节点的距离

int found(int x) {
    if (fa[x] == x)
        return x;
    else {
        int oldFa = fa[x];
        fa[x] = found(oldFa);
        d[x] = d[x] + d[oldFa];
        return fa[x];
    }
}

void merge(int x, int y, int w) {  // y比x多w的权
    int fax = found(x), fay = found(y);
    if (fax == fay) return;
    fa[fax] = fay;
    d[fax] = -d[x] + d[y] + w;
}

int dist(int x, int y) {  // y比x多多少权
    int fax = found(x), fay = found(y);
    if (fax != fay)
        return -1;
    else
        return d[x] - d[y];
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}