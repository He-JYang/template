#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e7 + 7;

int qpow(int a, int b, int p = mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

//求组合数
int C(int a, int b, int p) {
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
        res = res * j % p * qpow(i, p - 2, p) % p;
    return res;
}

//计算对质数取模大范围组合数  /***调用这个***/
int lucas(int a, int b, int p = mod) {
    if (a < p && b < p) return C(a, b, p);
    return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
