#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
typedef pair<int, int> pii;
const int inf = 0x7fffffff;
struct Node {
    int to, next, w, u;
} node[N];
int head[N], vis[N];
int n, m;

//
// O(mlogm)
int dis[N];
int fa[N];

int found(int x) {
    if (x == fa[x]) return x;
    return fa[x] = found(fa[x]);
}
bool cmp(Node a, Node b) {
    return a.w < b.w;
}

void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

void kruskal() {  // ע��kruskal��ʵ����ֻ��m���������ó�2*m�ó�2m�˼ǵó�2
    sort(node, node + m, cmp);
    //���ߵ�Ȩֵ����
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int fau = found(node[i].u), fav = found(node[i].to);
        if (fau == fav) { continue; }
        //�������������Ѿ���ͨ�ˣ���˵����һ���߲���Ҫ��
        fa[fav] = fau;
        //��eu��ev�ϲ�
        if (++cnt == n - 1) { break; }
        //ѭ������������������Ϊ������һʱ
    }
}