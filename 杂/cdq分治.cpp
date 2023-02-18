const int N = 100000;
int a[N], b[N];

int cdq_merger(int l, int r) {
    if (l == r) {
        // return;
        return a[l] >= 0;  // 求顺序对
    }
    int mid = (l + r) >> 1;
    int ans = cdq_merger(l, mid) + cdq_merger(mid + 1, r);
    int pl = l, pr = mid + 1;
    for (int i = l; i <= r; i++) {
        if (pl <= mid && a[pl] <= a[pr] || pr > r) {  // 注意是三个条件
            b[i] = a[pl++];
        } else {
            b[i] = a[pr++];
            // ans += (mid - pl + 1);//求逆序对
            ans += pl - mid;  //求顺序对，即求二维偏序
        }
    }
    for (int i = l; i <= r; i++)
        a[i] = b[i];
    return ans;
}
