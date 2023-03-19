// O(n)
const int niyuan_N = 3e6 + 20;
int inv[niyuan_N] = {0, 1};

int niyuan(int n, int mod) {
    for (int i = 2; i <= n; i++)
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    return 0;
}