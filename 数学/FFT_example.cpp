#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5000007;

const double PI = acos(-1);

int n, m;
int res, ans[N];
int limit = 1;  //
int L;          //�����Ƶ�λ��
int R[N];

inline int read() {
    register int x = 0, f = 1;
    register char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

struct Complex {
    double x, y;
    Complex(double x = 0, double y = 0) : x(x), y(y) {}
} a[N], b[N];

Complex operator*(Complex J, Complex Q) {
    //ģ����ˣ��������
    return Complex(J.x * Q.x - J.y * Q.y, J.x * Q.y + J.y * Q.x);
}
Complex operator-(Complex J, Complex Q) {
    return Complex(J.x - Q.x, J.y - Q.y);
}
Complex operator+(Complex J, Complex Q) {
    return Complex(J.x + Q.x, J.y + Q.y);
}

//�Լ����ɵ�_�����һ����m+n���2��������limit,�����Ʒ�ת������R
void FFT_init(int n, int m) {
    while (limit <= n + m)
        limit <<= 1, L++;
    for (int i = 0; i < limit; ++i)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
}

void FFT(Complex* A, int type) {  // FFT����
    for (int i = 0; i < limit; ++i)
        if (i < R[i]) swap(A[i], A[R[i]]);
    // iС��R[i]ʱ�Ž�������ֹͬһ��Ԫ�ؽ������Σ��ص���ԭ����λ�á�

    //�ӵײ����Ϻϲ�
    for (int mid = 1; mid < limit; mid <<= 1) {
        //���ϲ����䳤�ȵ�һ�룬�ʼ����������Ϊ1�����кϲ�,mid = 1;
        Complex wn(cos(PI / mid), type * sin(PI / mid));  //��λ��w_n^1;

        for (int len = mid << 1, pos = 0; pos < limit; pos += len) {
            // len������ĳ��ȣ�pos�ǵ�ǰ��λ��,Ҳ���Ǻϲ�������һλ
            Complex w(1, 0);  //��,һֱ�ˣ��õ�ƽ�������η�...

            for (int k = 0; k < mid; ++k, w = w * wn) {
                //ֻɨ��벿�֣������任�õ��Ұ벿�ֵĴ�,w Ϊ w_n^k
                Complex x = A[pos + k];            //��벿��
                Complex y = w * A[pos + mid + k];  //�Ұ벿��
                A[pos + k] = x + y;                //��߼�
                A[pos + mid + k] = x - y;          //�ұ߼�
            }
        }
    }
    if (type == 1) return;
    for (int i = 0; i <= limit; ++i)
        a[i].x /= limit;
    //���Ҫ����limitҲ���ǲ�����2�������ݵ��Ǹ�N������ֵת��Ϊϵ��
    //��ǰ���ƹ��˵�ֵ��ϵ��֮�������N��
}

//����FFT
/*
int main() {
    n = read(), m = read();
    //�������ʽ��ÿһ������ڸ�����ʵ��
    for (int i = 0; i <= n; ++i)
        a[i].x = read();
    for (int i = 0; i <= m; ++i)
        b[i].x = read();
    while (limit <= n + m)
        limit <<= 1, L++;
    //Ҳ����д�ɣ�limit = 1 << int(log2(n + m) + 1);
    // ����2�������ݣ�Ҳ����N
    for (int i = 0; i < limit; ++i)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    FFT(a, 1);  // FFT ��a��ϵ����ʾת��Ϊ��ֵ��ʾ
    FFT(b, 1);  // FFT ��b��ϵ����ʾת��Ϊ��ֵ��ʾ
    //��������ϵ����ʾ���Ķ���ʽ��˺�ĵ�ֵ��ʾ
    for (int i = 0; i <= limit; ++i)
        a[i] = a[i] * b[i];
    //��Ӧ����ˣ�O(n)�õ���ֵ��ʾ�Ķ���ʽ�Ľ�C��������任��ɲ�ֵ�õ���C�ĵ�ֵ��ʾ
    FFT(a, -1);

    for (int i = 0; i <= n + m; ++i)
        //����� x �� y �� double �� hhh
        printf("%d ", (int)(a[i].x + 0.5));  //ע��Ҫ+0.5�����򾫶Ȼ�������
}
*/

//����������FFT

int main() {
    n = read(), m = read();
    for (int i = 0; i <= n; ++i)
        a[i].x = read();
    for (int i = 0; i <= m; ++i)
        a[i].y = read();  //��b(x)�ŵ�a(x)���鲿��
    while (limit <= n + m)
        limit <<= 1, L++;
    for (int i = 0; i < limit; ++i)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    FFT(a, 1);
    for (int i = 0; i <= limit; ++i)
        a[i] = a[i] * a[i];  //���a(x)^2
    FFT(a, -1);

    for (int i = 0; i <= n + m; ++i)
        printf("%d ", (int)(a[i].y / 2 + 0.5));
    //�鲿ȡ������2��ע��Ҫ+0.5�����򾫶Ȼ�������,�����x��y����double
}
