#include <bits/stdc++.h>
using namespace std;

//ȫ�ֱ���n��m�ֱ�洢��������ʽ����ߴ���
const int N = 1e5 + 10;  // NΪ����ʽ����ߴ���+1
const double PI = acos(-1);
int limit = 1;  //�ձ�n+m���2��������
int L;          //�����Ƶ�λ��
int R[N];       //�����Ʒ�ת������

struct Complex {
    double x, y;
    Complex(double x = 0, double y = 0) : x(x), y(y) {}
};
Complex A[N];

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

void FFT_init(int n, int m) {
    while (limit <= n + m)
        limit <<= 1, L++;
    for (int i = 0; i < limit; ++i)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
}

void FFT(Complex* A, int type)  // FFT���� type=1��ʾ����Ҷ�任��-1��ʾ��任
{
    for (int i = 0; i < limit; ++i)
        if (i < R[i]) swap(A[i], A[R[i]]);

    for (int mid = 1; mid < limit; mid <<= 1) {
        Complex wn(cos(PI / mid), type * sin(PI / mid));

        for (int len = mid << 1, pos = 0; pos < limit; pos += len) {
            Complex w(1, 0);

            for (int k = 0; k < mid; ++k, w = w * wn) {
                Complex x = A[pos + k];
                Complex y = w * A[pos + mid + k];
                A[pos + k] = x + y;
                A[pos + mid + k] = x - y;
            }
        }
    }
    if (type == 1) return;
    for (int i = 0; i <= limit; ++i)
        A[i].x /= limit, A[i].y /= limit;
}

// FFTʹ�ú���������ʽϵ������a��b�ľ���ŵ�c�У���init����
// a[]�ĳ���Ϊn��b[]�ĳ���Ϊm
void use_FFT(int a[], int b[], int c[], int n, int m) {
    Complex A[N];
    for (int i = 0; i < N; i++) {
        A[i].x = a[i];
        A[i].y = b[i];
    }
    FFT(A, 1);
    for (int i = 0; i <= limit; ++i)
        A[i] = A[i] * A[i];  //���a(x)^2
    FFT(A, -1);
    for (int i = 0; i <= n + m; ++i) {
        c[i] = (int)(A[i].y / 2 + 0.5);
    }
}