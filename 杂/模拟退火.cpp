#include <bits/stdc++.h>
using namespace std;

int n, sx, sy;  // sx=sumx

double ansx, ansy;           //ȫ�����Ž������
double ans = 1e18, t;        //ȫ�����Ž⡢�¶�
const double delta = 0.993;  // 0.993; //����ϵ��

inline double cal(double x, double y) {  //����
    return 0.0;
}

inline void simulate_anneal() {  // SA������
    double x = ansx, y = ansy;
    t = 2000;  //��ʼ�¶�
    while (t > 1e-14) {
        double X = x + ((rand() << 1) - RAND_MAX) * t;
        double Y = y + ((rand() << 1) - RAND_MAX) * t;  //�ó�һ���µ�����
        double now = cal(X, Y);
        double Delta = now - ans;
        if (Delta < 0) {  //����
            x = X, y = Y;
            ansx = x, ansy = y, ans = now;
        } else if (exp(-Delta / t) * RAND_MAX > rand())
            x = X, y = Y;  //��һ�����ʽ���
        t *= delta;
    }
}

inline void use() {                                //���ܼ���SA����С���
    ansx = (double)sx / n, ansy = (double)sy / n;  //��ƽ��ֵ��ʼ�����׽ӽ����Ž�
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
}

void init() {
    srand(18253517);
    srand(rand());
    srand(rand());  //��ѧsrand
    // cout << RAND_MAX;//32767
}
