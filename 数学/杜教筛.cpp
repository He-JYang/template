#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// const int N = 5e6 + 10; // n^2/3
const int N = 1665703;  // n^2/3

int primes[N + 7];
ll mu[N + 7];
bool vis[N + 7];
ll phi[N + 7];
unordered_map<ll, ll> sum_mu;  //数组开不了那么大，所以用哈希表
unordered_map<ll, ll> sum_phi;

inline void init(int n = N) {
    vis[0] = vis[1] = 1;
    mu[1] = phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            primes[++primes[0]] = i;
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= primes[0] && i * primes[j] <= n; ++j) {
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                mu[i * primes[j]] = 0;
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            } else {
                mu[i * primes[j]] = -mu[i];
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        mu[i] += mu[i - 1];
        phi[i] += phi[i - 1];
    }
}

inline int g_sum(int x)  // g的前缀和，这里的g = I(x)//常数函数
{
    return x;
}

inline int get_sum_mu(int x)  // 记忆化搜索
{
    if (x <= N) return mu[x];  //预处理
    // if (sum_mu.find(x) != sum_mu.end()) return sum_mu[x]; //记忆化
    if (sum_mu[x]) return sum_mu[x];
    int ans = 1;                            // 杜教筛中推出的1
    for (ll l = 2, r; l <= x; l = r + 1) {  // 整除分块
        r = x / (x / l);
        //Σ_i=2 {g(i)*S(?n/i?)}  g不一样, S一样，然后整除分块
        ans -= (g_sum(r) - g_sum(l - 1)) * get_sum_mu(x / l);
    }
    return sum_mu[x] = ans / g_sum(1);  // 最后除以g(1)
}

inline ll get_sum_phi(int x) {
    if (x <= N) return phi[x];
    // if(sum_phi.find(x) != sum_phi.end()) return sum_phi[x];
    if (sum_phi[x]) return sum_phi[x];

    ll ans = x * ((ll)x + 1) / 2;  //杜教筛中的 n(n + 1) / 2
    for (ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        ans -= 1ll * (g_sum(r) - g_sum(l - 1)) * get_sum_phi(x / l);
    }
    return sum_phi[x] = ans / g_sum(1);
}

//使用前init();即可
