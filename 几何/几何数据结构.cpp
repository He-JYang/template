#include <bits/stdc++.h>
using namespace std;

const int N = 5007, M = 50007, INF = 0x3f3f3f3f;
const double DINF = 1e18, eps = 1e-8;
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  //���캯��
};

//!ע�����ֵ������
typedef Point Vector;
//����ƽ��֮�����Ǹ�����������ֻ��Ҫԭ����������յ㼴��
//!���� + ���� = �������� + ���� = ����
Vector operator+(Vector A, Vector B) {
    return Vector(A.x + B.x, A.y + B.y);
}
//!�� - �� = ����(����BC = C - B)
Vector operator-(Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}
//!���� * �� = ����
Vector operator*(Vector A, double p) {
    return Vector(A.x * p, A.y * p);
}
//!���� / ��= ����
Vector operator/(Vector A, double p) {
    return Vector(A.x / p, A.y / p);
}

//!��/�����ıȽϺ���
bool operator<(const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
//!�󼫽�//�ڼ�����ϵ�У�ƽ�����κ�һ�㵽��������ߺͼ���ļнǽ������ǡ�
//��λ����rad
double Polar_angle(Vector A) {
    return atan2(A.y, A.x);
}

//!��̬����sgn�����ж���ȣ����پ����������
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

//���ص��������
bool operator==(const Point& a, const Point& b) {
    return !sgn(a.x - b.x) && !sgn(a.y - b.y);
}

//!���(���㽻����)
double Dot(Vector A, Vector B) {
    return A.x * B.x + A.y * B.y;
}

//!�����Ĳ��(�����㽻����)
//������������������Ķ���(��v�ķ���,w�����,���>0,w���ұ�,���<0,����,���=0)
// cross(x, y) = -cross(y, x)
// cross(x, y) : xAyB - xByA
double Cross(Vector A, Vector B) {
    return A.x * B.y - B.x * A.y;
}
