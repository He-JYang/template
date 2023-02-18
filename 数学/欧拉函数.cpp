// 1?N ���� N ���ʵ����ĸ���������Ϊŷ������
//ʱ�临�Ӷ�Ϊ����n
inline int euler_one(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);  // n������һ���ȸ���n���������
    return ans;
}
