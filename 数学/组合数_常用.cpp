const int N = 11111;
int mod = 998244353;

int jc[N];
int inv[N];

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

void init() {
    int n;
    for (int i = 1; i <= n; i++) {
        jc[i] = jc[i - 1] * i % mod;
    }
    int x, y;
    exgcd(jc[n], mod, x, y);
    x = (x % mod + mod) % mod;
    inv[n] = x;

    for (int i = n; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

int C(int n, int r) {
    return jc[n] * inv[n - r] % mod * inv[r] % mod;
}