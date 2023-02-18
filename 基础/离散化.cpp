#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int a[N];
int n;

// O(nlogn) a[i]ֱ�ӱ���ֵΪ��ɢ�����ֵ��ԭֵΪdiscre[a[i]]

int discre[N];

signed discretization() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        discre[i] = a[i];
    }
    sort(discre + 1, discre + n + 1);
    int numnum = unique(discre + 1, discre + n + 1) - discre - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(discre + 1, discre + numnum + 1, a[i]) - discre;
    }
}