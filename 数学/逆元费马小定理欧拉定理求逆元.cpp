// O(log(n))
// 就是快速幂且多数情况下比拓展欧几里得慢一个常数且a和mod互质
int mod;
// x是a在mod p 意义下的逆元
// a*x==1(mod p) --> x=a^(p-2)mod p
int qpow(int a, int b = mod - 2, int mod) {
    int ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}