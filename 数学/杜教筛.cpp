#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// const int N = 5e6 + 10; // n^2/3
const int N = 1665703;  // n^2/3

int primes[N + 7];
ll mu[N + 7];
bool vis[N + 7];
ll phi[N + 7];
unordered_map<ll, ll> sum_mu;  //���鿪������ô�������ù�ϣ��
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

inline int g_sum(int x)  // g��ǰ׺�ͣ������g = I(x)//��������
{
    return x;
}

inline int get_sum_mu(int x)  // ���仯����
{
    if (x <= N) return mu[x];  //Ԥ����
    // if (sum_mu.find(x) != sum_mu.end()) return sum_mu[x]; //���仯
    if (sum_mu[x]) return sum_mu[x];
    int ans = 1;                            // �Ž�ɸ���Ƴ���1
    for (ll l = 2, r; l <= x; l = r + 1) {  // �����ֿ�
        r = x / (x / l);
        //��_i=2 {g(i)*S(?n/i?)}  g��һ��, Sһ����Ȼ�������ֿ�
        ans -= (g_sum(r) - g_sum(l - 1)) * get_sum_mu(x / l);
    }
    return sum_mu[x] = ans / g_sum(1);  // ������g(1)
}

inline ll get_sum_phi(int x) {
    if (x <= N) return phi[x];
    // if(sum_phi.find(x) != sum_phi.end()) return sum_phi[x];
    if (sum_phi[x]) return sum_phi[x];

    ll ans = x * ((ll)x + 1) / 2;  //�Ž�ɸ�е� n(n + 1) / 2
    for (ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        ans -= 1ll * (g_sum(r) - g_sum(l - 1)) * get_sum_phi(x / l);
    }
    return sum_phi[x] = ans / g_sum(1);
}

//ʹ��ǰinit();����
