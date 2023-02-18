int const mu_N = 1e7 + 10;
bool isprime[mu_N] = {1, 1};  // 判断i是否为素数,i=0,i=1的时候都不是质数 ，所以直接标记
int prime[mu_N];              //存质数
int mu[mu_N];
int mu_f[mu_N];

void get_mu(long long n) {
    mu[1] = 1;  // 存放 莫比乌斯函数；
    // isprime[] 存放 是否是质数
    // prime[]  存放  质数
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!isprime[i]) {
            prime[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }  //也可以直接break 因为里面本来存的就是0
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i < n; i++) {
        mu_f[i] = mu_f[i - 1] + mu[i];
    }
}
