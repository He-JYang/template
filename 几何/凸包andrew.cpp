//����͹�������������p������Ϊp���������ch����������͹�����������
//���벻�����ظ��ĵ㣬����ִ������������˳�򽫱��ƻ�����ΪҪ���򣬿��Լ�һ�������ԭ����id��
//�����ϣ����͹������������㣬������<=�ĳ�<����
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  //���캯��
};
typedef Point Vector;

Vector operator-(Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}

double Cross(Vector A, Vector B) {
    return A.x * B.y - B.x * A.y;
}

// Andrew�㷨
int ConvexHull(Point p[], int n, Point ch[]) {
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; ++i) {  //��͹��
        //������<=0˵���±�б��С˵���Ѿ�����͹�����ˣ��Ͻ�����
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
    return m;
}
