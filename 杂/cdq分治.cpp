const int N = 100000;
int a[N], b[N];

int cdq_merger(int l, int r) {
    if (l == r) {
        // return;
        return a[l] >= 0;  // ��˳���
    }
    int mid = (l + r) >> 1;
    int ans = cdq_merger(l, mid) + cdq_merger(mid + 1, r);
    int pl = l, pr = mid + 1;
    for (int i = l; i <= r; i++) {
        if (pl <= mid && a[pl] <= a[pr] || pr > r) {  // ע������������
            b[i] = a[pl++];
        } else {
            b[i] = a[pr++];
            // ans += (mid - pl + 1);//�������
            ans += pl - mid;  //��˳��ԣ������άƫ��
        }
    }
    for (int i = l; i <= r; i++)
        a[i] = b[i];
    return ans;
}
