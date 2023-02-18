
const int N = 1e6 + 10;

int fa[N];

int found(int x) {
    if (fa[x] == x)
        return x;
    else {
        int oldFa = fa[x];
        fa[x] = found(oldFa);
        return fa[x];
    }
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}