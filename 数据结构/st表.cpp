#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

// initʱ�临�Ӷȣ�nlogn����ѯʱ�临�Ӷ�O1

int st[N][__lg(N) + 1];  // NΪҪ��ѯ�����Χ

// __lg(n)����log2(n)������ȡ��,���λ��λ����һ,�����Ϊ��n���λ�Ƶ�&1��Ҫ�ƶ���λ��

// �ڲ�ʹ�õ�0��ʱst������ʵ�0�㣬��Ȼst�����ʹ�õ�0��
// ʹ��st(i, j) ����ʾ����[i, i + 2 ^ j - 1] �е���ֵ
void init_st(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j <= __lg(n); j++) {                                //__lg(len)lenΪҪ��ѯ�ķ�Χ
        for (int i = 1; i + (1 << j - 1) <= n; i++) {                   // ��RE,�࿪30�п�ֱ��дn,��׼д��i + (1 << j) - 1 <= n
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);  // rmq(range max/min query)�����st��
            // st[i][j] = st[st[i][j - 1]][j - 1];                         //·������st��
        }
    }
}

int queryRMQst(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int queryRoadSt(int x, int k) {
    int i = __lg(k);  // Ҳ��, ���� if (k != 0) ����
    if (k != 0)
        for (int i = __lg(k); i >= 0; i--)
            if (x & (1 << i)) x = st[x][i];
    return x;
}