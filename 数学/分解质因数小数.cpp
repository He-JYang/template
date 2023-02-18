#include <bits/stdc++.h>
using namespace std;

int cnt[100000];
vector<int> prime_factors;

void get_prime_factors(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            prime_factors.emplace_back(i);
            while (x % i == 0) {
                x /= i;
                ++cnt[i];
            }
        }
        if (x > 1) {
            prime_factors.emplace_back(x);
            ++cnt[x];
        }
    }
}