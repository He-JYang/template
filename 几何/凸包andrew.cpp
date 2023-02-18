//计算凸包，输入点数组p，个数为p输出点数组ch，函数返回凸包顶点个数。
//输入不能有重复的点，函数执行完后的输入点的顺序将被破坏（因为要排序，可以加一个数组存原来的id）
//如果不希望在凸包边上有输入点，把两个<=改成<即可
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  //构造函数
};
typedef Point Vector;

Vector operator-(Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}

double Cross(Vector A, Vector B) {
    return A.x * B.y - B.x * A.y;
}

// Andrew算法
int ConvexHull(Point p[], int n, Point ch[]) {
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; ++i) {  //下凸包
        //如果叉积<=0说明新边斜率小说明已经不是凸包边了，赶紧踢走
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
    return m;
}
