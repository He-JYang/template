#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int sum0[N], reflect[N];

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int n) {
    while (x <= n) {
        sum0[x] += 1;
        x += lowbit(x);
    }
}

int getsum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += sum0[x];
        x -= lowbit(x);
    }
    return sum;
}

int nixu(int a[], int n) {
    vector<pair<int, int>> v1;
    for (int i = 1; i <= n; ++i) {
        v1.push_back({a[i], i});
    }

    sort(v1.begin(), v1.end());
    for (int i = 1; i <= n; ++i)
        reflect[v1[i - 1].second] = i;  //离散化

    for (int i = 1; i <= n; ++i)
        sum0[i] = 0;  //初始化树状数组
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        update(reflect[i], n);
        ans += i - getsum(reflect[i]);
    }
    return ans;
}