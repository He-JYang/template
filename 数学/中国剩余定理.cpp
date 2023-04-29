#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

//

const int N = 15;
int n, a[N], mods[N];

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
        prod *= mods[i];
    ll tmp;
    for (int i = 1; i <= n; ++i) {
        tmp = prod / mods[i];
        ans += (inv(tmp, mods[i]) * a[i] * tmp) % prod;
    }
    return ans % prod;
}
/*
    a[i]为每个方程式的余数
    mods[i]为每个方程的模数
    使用条件为所有mods[i]互质
 */
signed example() {
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> mods[i];
    int ans = crt();
    cout << ans;
}
