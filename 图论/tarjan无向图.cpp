#include <bits/stdc++.h>
using namespace std;

const int M = 1001, N = 1001;
struct Node {
    int to, next;
} node[2 * M + 10];
int head[N], vis[N];

// O(N+M)
//

int dfn[N], low[N];      // dfn���ϸ񵥵�������ֻ��low���ܱ仯
int Stack[N], tim, idx;  // timʱ���
int scc[N], p[N];        // s��ʾ������һ��ǿ��ͨ����(strongly connected components)��p��ʾ��Ȩ
int cp[N];               // ���cut_point����д
int scc_cnt;             // ǿ��ͨ��������������
set<pair<int, int>> brige;

// tarjan �㷨������ͼ��������ǿ��ͨ����������ͼ����������͸�ߣ��ţ�
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    Stack[++idx] = u;
    vis[u] = 1;     // ��ʾ��ջ�����ջһ���ǿյ�
    int child = 0;  //������������������������ʱ�ڸ��ڵ��ж��Ƿ�Ϊ������ʱ����
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (!dfn[to]) {
            child++;  // �������ʱ�������ֻ���жϸ��ڵ�ʱ��ʹ��
            tarjan(to, u);
            low[u] = min(low[u], low[to]);
            if (low[to] >= dfn[u] && u != fa) {  // ������>=������>
                cp[u] = true;
                // brige.insert({u, to});
            }
        }
        // ��ǿ��ͨ����
        else if (vis[to]) {
            low[u] = min(low[u], dfn[to]);
            // ����ǿ��ͨ����ʱд dfn��low���ǶԵĵ�����������ʱֻ��дdfnҲ������������д��
            // ��Ϊ����ǿ��ͨ����ʱֻҪlow!=dfn�����ͻᱻ����
        }
        // �������
        // else if (dfn[to] < dfn[u] && to != fa) {
        //     low[u] = min(low[u], dfn[to]);
        // }
    }

    if (low[u] == dfn[u]) {
        // scc_cnt++;
        while (1) {
            int y = Stack[idx--];
            scc[y] = u;  // ����
            // scc[y] = scc_cnt; // ˳������������
            vis[y] = false;
            if (u == y) break;
            p[u] += p[y];  // �����ϵ���Ϣȫ���ӵ�����Ԫ���㣩�ϣ���Ȩ�ȣ�
        }
    }
    if (fa == u && child > 1) { cp[u] = true; }  // �жϸ��ڵ��Ƿ�Ϊ���
}

int use(int n) {
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, i);

    return 0;
}