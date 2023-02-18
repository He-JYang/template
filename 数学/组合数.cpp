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

//����int��Χ�����
int C(int a, int b, int p = mod) {
    if (a < b) return 0;

    int down = 1, up = 1;
    for (int i = a, j = 1; j <= b; i--, ++j) {
        up = up * i % p;
        down = down * j % p;
    }
    return up * qpow(down, p - 2, p) % p;
}

//���������ȡģ��Χ�����  /***�������***/
int lucas(int a, int b, int p = mod) {
    if (a < p && b < p) return C(a, b, p);
    return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
