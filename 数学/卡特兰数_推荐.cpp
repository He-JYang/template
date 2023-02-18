#include <bits/stdc++.h>
using namespace std;
long long ans1, ans2;

// 最多30位卡特兰数含30
int C(int a, int b) {  //简易版C
    int mul = 1;
    int dev = 1;
    for (int i = a - b + 1, j = 1; i <= a; i++, j++) {
        mul *= i;
        dev *= j;
        int dev1 = __gcd(mul, dev);
        mul /= dev1;
        dev /= dev1;
    }
    return mul;
}

int catalan(int n) {
    return C(2 * n, n) - C(2 * n, n - 1);
}