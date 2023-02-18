const int N = 100000;

//
int fa[N], d[N];  // dΪ�����ڵ�ľ���

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

void merge(int x, int y, int w) {  // y��x��w��Ȩ
    int fax = found(x), fay = found(y);
    if (fax == fay) return;
    fa[fax] = fay;
    d[fax] = -d[x] + d[y] + w;
}

int dist(int x, int y) {  // y��x�����Ȩ
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