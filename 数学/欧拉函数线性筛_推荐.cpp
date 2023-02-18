#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

// ʱ�临�Ӷ�Ϊ����֮�е����ֵmax������r��64*len������phi�����䳤�ȵ�64��
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

int nums[N], phi[N];  // num�����൱��n,phi��phi��id��ֵΪ�˷�MLE����id=l+i�洢

signed use(int l, int r) {
    int sqrr = (int)(sqrt(r));
    ola(sqrr);
    for (int i = l; i <= r; i++) {
        int id = i - l;
        nums[id] = i;
        phi[id] = i;
    }
    // ���ǿ���˲���ҵ�����ĳ������������ȴ����˲���ҵ�һ����������Щ��������������������ȥ����
    // һ��longlong��Χ�ڵ��������64��������˹���  �������ǵ�ʱ�临�Ӷ�С��64*���䳤��
    for (int i = 1; i <= tot; i++) {
        int p = prime[i];
        int mint = (l + p - 1) / p;  // ��С����min times
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