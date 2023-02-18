#include <bits/stdc++.h>
using namespace std;
const int N = 500;
const int inf = 0x7fffffff;
int dis[N][N];

int floyd(int n) {
    for (int k = 1; k <= n; k++) {  // �����Ͽ�k��ʾ��ǰk������Ϊ��ת��i�ܷ񵽴�j����j����̾����Ƕ���
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}