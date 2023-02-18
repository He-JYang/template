#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int example_a[N];

//
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

void mul(int a[], int x)  //高精求积
{
    int g = 0;
    for (int i = mlen; i >= 0; i--) {
        a[i] = a[i] * x + g;
        g = a[i] / 10;
        a[i] = a[i] % 10;
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

void equ(int a[], int x) {
    memset(a, 0, (mlen + 1) * sizeof(int));
    for (int i = mlen; i >= 0; i--) {
        a[i] = (x % 10);
        x /= 10;
    }
}

void equ(int a[], string s1) {
    memset(a, 0, (mlen + 1) * sizeof(int));
    int slen = s1.length();
    for (int i = mlen; i > mlen - slen; i--) {
        a[i] = s1[slen - (mlen - i) - 1] - '0';
    }
}

void mul(int a[], int m[], int res[]) {  // m*a=res;
    int temp[mlen + 1];
    memset(res, 0, (mlen + 1) * sizeof(int));
    for (int i = mlen; i >= 0; i--) {
        memset(temp, 0, (mlen + 1) * sizeof(int));
        int move = mlen - i;
        for (int j = move; j <= mlen + move; j++) {
            temp[j - move] = a[j];
        }
        mul(temp, m[i]);
        add(temp, res);
    }
}
