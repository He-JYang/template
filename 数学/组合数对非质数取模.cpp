#include <bits/stdc++.h>
using namespace std;

void exgcd(long long a, long long b, long long& x, long long& y) {
    if (!b) return (void)(x = 1, y = 0);
    exgcd(b, a % b, x, y);
    long long tmp = x;
    x = y;
    y = tmp - a / b * y;
}

inline long long INV(long long a, long long p) {
    long long x, y;
    exgcd(a, p, x, y);
    return (x + p) % p;
}

inline long long fast_pow(long long a, long long b, long long p) {
    long long t = 1;
    a %= p;
    while (b) {
        if (b & 1LL) t = (t * a) % p;
        b >>= 1LL;
        a = (a * a) % p;
    }
    return t;
}

inline long long F(long long n, long long P, long long PK) {
    if (n == 0) return 1;
    long long rou = 1;  //循环节
    long long rem = 1;  //余项
    for (long long i = 1; i <= PK; i++) {
        if (i % P) rou = rou * i % PK;
    }
    rou = fast_pow(rou, n / PK, PK);
    for (long long i = PK * (n / PK); i <= n; i++) {
        if (i % P) rem = rem * (i % PK) % PK;
    }
    return F(n / P, P, PK) * rou % PK * rem % PK;
}
inline long long G(long long n, long long P) {
    if (n < P) return 0;
    return G(n / P, P) + (n / P);
}
inline long long C_PK(long long n, long long m, long long P, long long PK) {
    long long fz = F(n, P, PK), fm1 = INV(F(m, P, PK), PK), fm2 = INV(F(n - m, P, PK), PK);
    long long mi = fast_pow(P, G(n, P) - G(m, P) - G(n - m, P), PK);
    return fz * fm1 % PK * fm2 % PK * mi % PK;
}
long long A[1001], B[1001];
// x=B(mod A)

//扩展卢卡斯定理  /***调用这个***/
inline long long C(long long n, long long m, long long P) {
    long long ljc = P, tot = 0;
    for (long long tmp = 2; tmp * tmp <= P; tmp++) {
        if (!(ljc % tmp)) {
            long long PK = 1;  // 分解为质数p的k次幂
            while (!(ljc % tmp)) {
                PK *= tmp;
                ljc /= tmp;
            }
            A[++tot] = PK;
            B[tot] = C_PK(n, m, tmp, PK);
        }
    }
    if (ljc != 1) {
        A[++tot] = ljc;
        B[tot] = C_PK(n, m, ljc, ljc);
    }
    long long ans = 0;
    for (long long i = 1; i <= tot; i++) {
        long long M = P / A[i], T = INV(M, A[i]);
        ans = (ans + B[i] * M % P * T % P) % P;
    }
    return ans;
}
