#include <bits/stdc++.h>
using namespace std;

const int M = 1001, N = 1001;
struct Node {
    int to, next;
} node[2 * M + 10];
int head[N], vis[N];

// O(N+M)

int dfn[N], low[N];      // dfn���ϸ񵥵�������ֻ��low���ܱ仯
int Stack[N], tim, idx;  // timʱ���
int scc[N];              // s��ʾ������һ��ǿ��ͨ����(strongly connected components)

// tarjan �㷨������ͼ��������ǿ��ͨ����������ͼ����������͸�ߣ��ţ�
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    Stack[++idx] = u;
    vis[u] = 1;  // ��ʾ��ջ�����ջһ���ǿյ�
    for (int i = head[u]; i; i = node[i].next) {
        int to = node[i].to;
        if (!dfn[to]) {
            tarjan(to, u);
            low[u] = min(low[u], low[to]);
        } else if (vis[to]) {
            low[u] = min(low[u], dfn[to]);
            // ����ǿ��ͨ����ʱд dfn��low���ǶԵĵ�����������ʱֻ��дdfnҲ������������д��
            // ��Ϊ����ǿ��ͨ����ʱֻҪlow!=dfn�����ͻᱻ����
        }
    }

    if (low[u] == dfn[u]) {
        while (1) {
            int y = Stack[idx--];
            scc[y] = u;  // ����
            vis[y] = false;
            if (u == y) break;
        }
    }
}

int use(int n) {
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, i);

    return 0;
}