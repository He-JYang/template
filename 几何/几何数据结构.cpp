#include <bits/stdc++.h>
using namespace std;

const int N = 5007, M = 50007, INF = 0x3f3f3f3f;
const double DINF = 1e18, eps = 1e-8;
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  //构造函数
};

//!注意区分点和向量
typedef Point Vector;
//向量平移之后还是那个向量，所以只需要原点和向量的终点即可
//!向量 + 向量 = 向量，点 + 向量 = 向量
Vector operator+(Vector A, Vector B) {
    return Vector(A.x + B.x, A.y + B.y);
}
//!点 - 点 = 向量(向量BC = C - B)
Vector operator-(Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}
//!向量 * 数 = 向量
Vector operator*(Vector A, double p) {
    return Vector(A.x * p, A.y * p);
}
//!向量 / 数= 向量
Vector operator/(Vector A, double p) {
    return Vector(A.x / p, A.y / p);
}

//!点/向量的比较函数
bool operator<(const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
//!求极角//在极坐标系中，平面上任何一点到极点的连线和极轴的夹角叫做极角。
//单位弧度rad
double Polar_angle(Vector A) {
    return atan2(A.y, A.x);
}

//!三态函数sgn用于判断相等，减少精度误差问题
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

//重载等于运算符
bool operator==(const Point& a, const Point& b) {
    return !sgn(a.x - b.x) && !sgn(a.y - b.y);
}

//!点积(满足交换律)
double Dot(Vector A, Vector B) {
    return A.x * B.x + A.y * B.y;
}

//!向量的叉积(不满足交换律)
//等于两向量有向面积的二倍(从v的方向看,w在左边,叉积>0,w在右边,叉积<0,共线,叉积=0)
// cross(x, y) = -cross(y, x)
// cross(x, y) : xAyB - xByA
double Cross(Vector A, Vector B) {
    return A.x * B.y - B.x * A.y;
}
