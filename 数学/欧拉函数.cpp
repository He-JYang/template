// 1?N 中与 N 互质的数的个数，被称为欧拉函数
//时间复杂度为根号n
inline int euler_one(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);  // n至多有一个比根号n大的质因子
    return ans;
}
