#include <bits/stdc++.h>
using namespace std;
#define int long long

int C(int a, int b) {  //���װ�C���61��longlong��Χ��������
    int mul = 1;
    int dev = 1;
    if (b >= a + 1 / 2) b = a - b;
    for (int i = a - b + 1, j = 1; i <= a; i++, j++) {
        mul *= i;
        dev *= j;
        int dev1 = __gcd(mul, dev);
        mul /= dev1;
        dev /= dev1;
    }
    return mul;
}
