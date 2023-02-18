#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000010;
const long long INF = 1e18;

struct Node {
    int to, next, w;
} node[2 * N * N];
int head[N], tot;

void add(int u, int v, int w = 0) {
    node[++tot] = {v, head[u], w};
    head[u] = tot;
}

// O(n^2*m)

// ע�ߵ����Ӧ��Ϊ���� N * M * 2 +N+M

int n, m, dinicS, dinicT, lv[N], cur[N];  // lv��ÿ����Ĳ�����cur���ڵ�ǰ���Ż�����������
// ���Ż�����Ϊ��Dinic�㷨�У�һ��������һ�κ�Ͳ����ٴ������ˣ�
// �����´�����ʱ����Ҫ�ٿ��������ߡ����ǰ�head���鸴��һ�ݣ������ϸ����������㡣

inline bool bfs()  // BFS�ֲ�
{
    memset(lv, -1, sizeof(lv));
    lv[dinicS] = 0;
    memcpy(cur, head, sizeof(head));  // ��ǰ���Ż���ʼ��
    queue<int> q;
    q.push(dinicS);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int eg = head[p]; eg; eg = node[eg].next) {
            int to = node[eg].to, vol = node[eg].w;
            if (vol > 0 && lv[to] == -1) lv[to] = lv[p] + 1, q.push(to);
        }
    }
    return lv[dinicT] != -1;  // ������δ���ʹ�˵���Ѿ��޷��ﵽ��㣬��ʱ����false
}
int dfs(int p = dinicS, int flow = INF) {
    if (p == dinicT) return flow;
    int rmn = flow;                                       // ʣ�������
    for (int eg = cur[p]; eg && rmn; eg = node[eg].next)  // ����Ѿ�û��ʣ���������˳�
    {
        cur[p] = eg;  // ��ǰ���Ż������µ�ǰ��
        int to = node[eg].to, vol = node[eg].w;
        if (vol > 0 && lv[to] == lv[p] + 1)  // �������ߵķ�������
        {
            int c = dfs(to, min(vol, rmn));  // �����ܶ�ش�������
            rmn -= c;                        // ʣ����������
            node[eg].w -= c;                 // ���²�������
            node[eg ^ 1].w += c;             // �ٴ����ѣ���ʽǰ���ǵ�cnt��Ҫ��ʼ��Ϊ1����-1���������������
        }
    }
    return flow - rmn;  // ���ش��ݳ�ȥ�������Ĵ�С
}
inline int dinic() {
    int ans = 0;
    while (bfs())
        ans += dfs();
    return ans;
}
void use_dinic_example() {
    int n, m;

    //

    tot = 1;
    dinicS = n + m + 1;
    dinicT = n + m + 2;
    for (int i = 1; i <= n; i++) {
        int w;
        add(dinicS, i, w);
        add(i, dinicS, 0);
    }
    for (int i = n + 1; i <= m + n; i++) {
        int w;
        add(i, dinicT, w);
        add(dinicT, i, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int w;
            add(i, j, w);
            add(j, i, 0);
        }
    }
    dinic();
}