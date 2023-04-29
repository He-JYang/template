#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

//

const int N = 15;
int n, c[N], d[N];

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    } else {
        int gcd = exgcd(b, a % b, y, x);
        y -= x * (a / b);  // 此处一定要先除后乘不然可能爆精度建议加括号
        return gcd;
    }
}

inline ll inv(ll x, ll p)  // 求逆元
{
    ll X, Y;
    exgcd(x, p, X, Y);
    return (X % p + p) % p;
}
inline ll crt()  // CRT
{
    ll prod = 1, ans = 0;
    for (int i = 1; i <= n; ++i)
        prod *= d[i];
    ll tmp;
    for (int i = 1; i <= n; ++i) {
        tmp = prod / d[i];
        ans += (inv(tmp, d[i]) * c[i] * tmp) % prod;
    }
    return ans % prod;
}
void example() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> d[i] >> c[i];
    int ans = crt();
}
