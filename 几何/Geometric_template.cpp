#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
//高精度
typedef long long ll;

const int inf = 0x7fffffff;
const int INF = (ll)9e18;
const double DINF = 12345678910, eps = 1e-10;
const double PI = acosl(-1);
// const long double PI = acosl(-1);
const int maxn = 50007, maxm = 50007;
const int mod = 1e9 + 7;
const int mod2 = 998244353;

struct Point {
    int x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  //构造函数
};
typedef Point Vector;
Vector operator+(Vector A, Vector B) {
    return Vector(A.x + B.x, A.y + B.y);
}
Vector operator-(Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}
Vector operator*(Vector A, double p) {
    return Vector(A.x * p, A.y * p);
}
Vector operator/(Vector A, double p) {
    return Vector(A.x / p, A.y / p);
}
bool operator<(const Point& a, Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}
bool operator==(const Point& a, const Point& b) {
    return !dcmp(a.x - b.x) && !dcmp(a.y - b.y);
}
double Polar_angle(Vector A) {
    return atan2(A.y, A.x);
}
inline double D_to_R(double D)  //角度转弧度
{
    return PI / 180 * D;
}
//右手定则，从第一个转到第二个向上为正向下为负
double Cross(Vector A, Vector B) {
    return A.x * B.y - B.x * A.y;
}
Vector Rotate(Vector A, double rad) {
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}
Point Get_line_intersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}
double convex_polygon_area(Point* p, int n) {
    double area = 0;
    for (int i = 1; i <= n - 2; ++i)
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    return area / 2;
}

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

Point p[maxn], ch[maxn];
int n, m, x, y, z, k, t1, t2, op, ans, flagg, cnt, tot;

// !!!注意当数值达到一定程度时必须改用longlong而不是double，double含有效位
// 用快捷键，或全局替换将double 换成int (即long long )
signed main() {
    // ios::sync_with_stdio(0);

    return 0;
}
