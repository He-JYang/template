const int N = 1000000;

int is_prime[N], prime[N], tot, phi[N];

void euler_phi(int n) {
    for (int i = 2; i <= n; i++) {
        is_prime[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[++tot] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] > n) break;
            is_prime[i * prime[j]] = 0;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];  //若p|m则mp与p质因子种类相同
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];  // 积性函数
            }
        }
    }
}
