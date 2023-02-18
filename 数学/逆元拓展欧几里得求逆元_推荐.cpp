// O(log(n))
// 拓展欧几里得x为a的逆元b为模,x,y不用初始化什么值都可以
// 一个数与0的最小公倍数是其本身
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
void use() {
    int x, y, a, mod;

    exgcd(a, mod, x, y);

    x = (x % mod + mod) % mod;
}