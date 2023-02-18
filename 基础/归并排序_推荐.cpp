const int N = 100000;
int a[N], b[N];
int ans = 0;

void merger(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merger(l, mid);
    merger(mid + 1, r);
    int pl = l, pr = mid + 1;
    for (int i = l; i <= r; i++) {
        if (pl <= mid && a[pl] <= a[pr] || pr > r) {  // 注意是三个条件
            b[i] = a[pl++];
        } else {
            b[i] = a[pr++];
            // ans += (mid - pl + 1);求逆序对
        }
    }
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}
