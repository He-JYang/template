#include <bits/stdc++.h>
using namespace std;
// vector能在1s内模拟10^5的随机插入
vector<int> v1;
void use(int a[], int b[], int n) {
    for (int i = 1; i <= n; i++) {
        v1.insert(v1.begin() + a[i], b[i]);
    }
}