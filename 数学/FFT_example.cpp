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
int L;          //二进制的位数
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
    //模长相乘，幅度相加
    return Complex(J.x * Q.x - J.y * Q.y, J.x * Q.y + J.y * Q.x);
}
Complex operator-(Complex J, Complex Q) {
    return Complex(J.x - Q.x, J.y - Q.y);
}
Complex operator+(Complex J, Complex Q) {
    return Complex(J.x + Q.x, J.y + Q.y);
}

//自己集成的_计算第一个比m+n大的2的整数幂limit,二进制翻转数数组R
void FFT_init(int n, int m) {
    while (limit <= n + m)
        limit <<= 1, L++;
    for (int i = 0; i < limit; ++i)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
}

void FFT(Complex* A, int type) {  // FFT板子
    for (int i = 0; i < limit; ++i)
        if (i < R[i]) swap(A[i], A[R[i]]);
    // i小于R[i]时才交换，防止同一个元素交换两次，回到它原来的位置。

    //从底层往上合并
    for (int mid = 1; mid < limit; mid <<= 1) {
        //待合并区间长度的一半，最开始是两个长度为1的序列合并,mid = 1;
        Complex wn(cos(PI / mid), type * sin(PI / mid));  //单位根w_n^1;

        for (int len = mid << 1, pos = 0; pos < limit; pos += len) {
            // len是区间的长度，pos是当前的位置,也就是合并到了哪一位
            Complex w(1, 0);  //幂,一直乘，得到平方，三次方...

            for (int k = 0; k < mid; ++k, w = w * wn) {
                //只扫左半部分，蝴蝶变换得到右半部分的答案,w 为 w_n^k
                Complex x = A[pos + k];            //左半部分
                Complex y = w * A[pos + mid + k];  //右半部分
                A[pos + k] = x + y;                //左边加
                A[pos + mid + k] = x - y;          //右边减
            }
        }
    }
    if (type == 1) return;
    for (int i = 0; i <= limit; ++i)
        a[i].x /= limit;
    //最后要除以limit也就是补成了2的整数幂的那个N，将点值转换为系数
    //（前面推过了点值与系数之间相除是N）
}

//正常FFT
/*
int main() {
    n = read(), m = read();
    //读入多项式的每一项，保存在复数的实部
    for (int i = 0; i <= n; ++i)
        a[i].x = read();
    for (int i = 0; i <= m; ++i)
        b[i].x = read();
    while (limit <= n + m)
        limit <<= 1, L++;
    //也可以写成：limit = 1 << int(log2(n + m) + 1);
    // 补成2的整次幂，也就是N
    for (int i = 0; i < limit; ++i)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    FFT(a, 1);  // FFT 把a的系数表示转化为点值表示
    FFT(b, 1);  // FFT 把b的系数表示转化为点值表示
    //计算两个系数表示法的多项式相乘后的点值表示
    for (int i = 0; i <= limit; ++i)
        a[i] = a[i] * b[i];
    //对应项相乘，O(n)得到点值表示的多项式的解C，利用逆变换完成插值得到答案C的点值表示
    FFT(a, -1);

    for (int i = 0; i <= n + m; ++i)
        //这里的 x 和 y 是 double 的 hhh
        printf("%d ", (int)(a[i].x + 0.5));  //注意要+0.5，否则精度会有问题
}
*/

//三步变两步FFT

int main() {
    n = read(), m = read();
    for (int i = 0; i <= n; ++i)
        a[i].x = read();
    for (int i = 0; i <= m; ++i)
        a[i].y = read();  //把b(x)放到a(x)的虚部上
    while (limit <= n + m)
        limit <<= 1, L++;
    for (int i = 0; i < limit; ++i)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    FFT(a, 1);
    for (int i = 0; i <= limit; ++i)
        a[i] = a[i] * a[i];  //求出a(x)^2
    FFT(a, -1);

    for (int i = 0; i <= n + m; ++i)
        printf("%d ", (int)(a[i].y / 2 + 0.5));
    //虚部取出来除2，注意要+0.5，否则精度会有问题,这里的x和y都是double
}
