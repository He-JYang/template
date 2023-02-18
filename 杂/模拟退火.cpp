#include <bits/stdc++.h>
using namespace std;

int n, sx, sy;  // sx=sumx

double ansx, ansy;           //全局最优解的坐标
double ans = 1e18, t;        //全局最优解、温度
const double delta = 0.993;  // 0.993; //降温系数

inline double cal(double x, double y) {  //计算
    return 0.0;
}

inline void simulate_anneal() {  // SA主过程
    double x = ansx, y = ansy;
    t = 2000;  //初始温度
    while (t > 1e-14) {
        double X = x + ((rand() << 1) - RAND_MAX) * t;
        double Y = y + ((rand() << 1) - RAND_MAX) * t;  //得出一个新的坐标
        double now = cal(X, Y);
        double Delta = now - ans;
        if (Delta < 0) {  //接受
            x = X, y = Y;
            ansx = x, ansy = y, ans = now;
        } else if (exp(-Delta / t) * RAND_MAX > rand())
            x = X, y = Y;  //以一个概率接受
        t *= delta;
    }
}

inline void use() {                                //多跑几遍SA，减小误差
    ansx = (double)sx / n, ansy = (double)sy / n;  //从平均值开始更容易接近最优解
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
}

void init() {
    srand(18253517);
    srand(rand());
    srand(rand());  //玄学srand
    // cout << RAND_MAX;//32767
}
