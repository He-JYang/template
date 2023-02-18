#include <bits/stdc++.h>
using namespace std;

const int N = 50007, M = 50007;
Point p[N], con[N];

struct Point {
    int x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  //���캯��
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

//��Ϊ���輸�����ݽṹ

//͹��
int ConvexHull(Point* p /*���е�ļ���*/, int n /*ȫ����ĸ���*/, Point* ch /*͹�����*/) {
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; ++i) {  //��͹��
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; --i) {  //��͹��
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    // ch[0]����㣬���һ����ch[m]Ҳ�����
    return m;
}

//�㵽ԭ��ľ���
int get_dist(const Point& x) {
    return x.x * x.x + x.y * x.y;
}

//��ת���� ����ֱ��
double Rotating_calipers(int con_num /*��ĸ���*/, Point con[] /*͹���㼯*/) {
    int op = 1, ans = 0;
    for (int i = 0; i < con_num; ++i) {
        while (Cross((con[i] - con[op]), (con[i + 1] - con[i])) < Cross((con[i] - con[op + 1]), (con[i + 1] - con[i])))
            //��д��<=�ᱻ����������ݿ��������Ա���д��<��
            op = (op + 1) % con_num;
        ans = max(ans, max(get_dist(con[i] - con[op]), get_dist(con[i + 1] - con[op])));
    }
    cout << ans;
    return ans;
}

//����ֱ��
double use_rotating(int n /*ȫ����ĸ���*/, Point p[] /*���е�ļ���*/) {
    int con_num = ConvexHull(p, n, con);
    double res = Rotating_calipers(con_num, con);
    return res;
}
