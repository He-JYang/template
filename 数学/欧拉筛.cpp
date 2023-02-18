#include <bits/stdc++.h>
using namespace std;
#define int long long

int const ola_N = 1e7 + 10;
int const ola_maxn = 1e7 + 10;
bool is_prime[ola_N];  // 判断i是否为素数,i=0,i=1的时候都不是质数 ，所以直接标记
int prime[ola_N];      // 存质数
int tot;               // n>100000时tot<n/10

//欧拉筛时间复杂度O(n)每个合数只被其最小质因子筛去
void ola(int n) {
    for (int i = 2; i <= n; i++)
        is_prime[i] = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] == 1) prime[++tot] = i;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] > n) break;
            is_prime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}
