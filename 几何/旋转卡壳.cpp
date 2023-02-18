#include <bits/stdc++.h>
using namespace std;

const int N = 50007, M = 50007;
Point p[N], con[N];

struct Point {
    int x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  //构造函数
};
typedef Point Vector;

Vector operator-(Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}

bool operator<(const Point& a, Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double Cross(Vector A, Vector B) {
    return A.x * B.y - B.x * A.y;
}

//上为所需几何数据结构

//凸包
int ConvexHull(Point* p /*所有点的集合*/, int n /*全部点的个数*/, Point* ch /*凸包存放*/) {
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; ++i) {  //下凸包
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; --i) {  //上凸包
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    // ch[0]是起点，最后一个点ch[m]也是起点
    return m;
}

//点到原点的距离
int get_dist(const Point& x) {
    return x.x * x.x + x.y * x.y;
}

//旋转卡壳 返回直径
double Rotating_calipers(int con_num /*点的个数*/, Point con[] /*凸包点集*/) {
    int op = 1, ans = 0;
    for (int i = 0; i < con_num; ++i) {
        while (Cross((con[i] - con[op]), (con[i + 1] - con[i])) < Cross((con[i] - con[op + 1]), (con[i + 1] - con[i])))
            //（写成<=会被两个点的数据卡掉，所以必须写成<）
            op = (op + 1) % con_num;
        ans = max(ans, max(get_dist(con[i] - con[op]), get_dist(con[i + 1] - con[op])));
    }
    cout << ans;
    return ans;
}

//返回直径
double use_rotating(int n /*全部点的个数*/, Point p[] /*所有点的集合*/) {
    int con_num = ConvexHull(p, n, con);
    double res = Rotating_calipers(con_num, con);
    return res;
}
