// 邻接表建图版
#include <bits/stdc++.h>
using namespace std;

//
const int N = 1e6 + 10;
struct Node {
    int to, next;
} node[N];

int n;  //节点数
int head[N], tot;
int ind[N];  //入度  in degree 直译入度
int out[N];  //出度
int topolist[N];
queue<int> q;
void toposort() {  // 即bfs
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i);
            topolist[pos++] = i;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = node[i].next) {
            int x = node[i].to;
            ind[x]--;
            if (!ind[x]) {
                q.push(x);
                topolist[pos++] = x;
            }
        }
    }
    return;
}

void add(int a, int b) {
    ind[b]++;
    out[a]++;
    node[++tot] = {b, head[a]};
    head[a] = tot;
}
