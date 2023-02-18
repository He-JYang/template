#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

// 时间复杂度为两者之中的最大值max（根号r，64*len）所求phi的区间长度的64倍
signed prime[N], is_prime[N], tot;

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

int nums[N], phi[N];  // num存数相当于n,phi存phi（id）值为了防MLE采用id=l+i存储

signed use(int l, int r) {
    int sqrr = (int)(sqrt(r));
    ola(sqrr);
    for (int i = l; i <= r; i++) {
        int id = i - l;
        nums[id] = i;
        phi[id] = i;
    }
    // 我们可以瞬间找到含有某个质数的数，却不能瞬间找到一个数含有哪些质数，于是我们用质数去找数
    // 一个longlong范围内的数最多由64个质数相乘构成  于是我们的时间复杂度小于64*区间长度
    for (int i = 1; i <= tot; i++) {
        int p = prime[i];
        int mint = (l + p - 1) / p;  // 最小倍数min times
        int maxt = r / p;
        for (int j = mint;; maxt) {
            int num = p * j - l;
            if (nums[num] % p == 0) {
                phi[num] = phi[num] / p * (p - 1);
                while (nums[num] % p == 0) {
                    nums[num] /= p;
                }
            }
        }
    }

    for (int i = l; i <= r; i++) {
        int id = i - l;
        if (nums[id] > 1) { phi[id] = phi[id] / nums[id] * (nums[id] - 1); }
    }
}