#include <bits/stdc++.h>
using namespace std;

const int mlen = 100;
void show(int a[]) {
    int onshow = 0;
    for (int i = 0; i <= mlen; i++) {
        if (a[i] != 0) onshow = 1;
        if (onshow) cout << a[i];
    }
    if (onshow == 0) cout << 0;
    cout << endl;
}
void equ(int a[], int x) {
    memset(a, 0, (mlen + 1) * sizeof(int));
    for (int i = mlen; i >= 0; i--) {
        a[i] = (x % 10);
        x /= 10;
    }
}
void add(int a[], int s[])  //高精求和s+=a
{
    int g = 0;
    for (int i = mlen; i >= 0; i--) {
        s[i] = s[i] + a[i] + g;
        g = s[i] / 10;
        s[i] = s[i] % 10;
    }
}
void mul(int a[], int x)  //高精求积
{
    int g = 0;
    for (int i = mlen; i >= 0; i--) {
        a[i] = a[i] * x + g;
        g = a[i] / 10;
        a[i] = a[i] % 10;
    }
}