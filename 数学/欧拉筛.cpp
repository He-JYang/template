#include <bits/stdc++.h>
using namespace std;
#define int long long

int const ola_N = 1e7 + 10;
int const ola_maxn = 1e7 + 10;
bool is_prime[ola_N];  // �ж�i�Ƿ�Ϊ����,i=0,i=1��ʱ�򶼲������� ������ֱ�ӱ��
int prime[ola_N];      // ������
int tot;               // n>100000ʱtot<n/10

//ŷ��ɸʱ�临�Ӷ�O(n)ÿ������ֻ������С������ɸȥ
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
