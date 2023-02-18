// # 树状数组 #

#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & (-x))  // 返回所属最小线段长度
const int N = 1e5 + 10;
int n;
int tree[N];

inline void update(int pos, int x) {  //单点pos增加x   pos!=0 否则会段错误
    for (int i = pos; i <= n; i += lowbit(i)) {
        tree[i] += x;
    }
}

inline int query(int pos) {  //求前pos项和 pos=0时返回0
    int ans = 0;
    for (int i = pos; i; i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}

int queryi(int sum, int n = N) {  // 相当于查询sum[pos]<=sum的最大位置，n为数组中数的个数;
    // 替换注释修改为sum[pos]<=sum的第一次最大位置，即不计a[i]==0的位置

    int pos = 0;
    int now = 0;
    for (int i = 31ll; i >= 0; --i) {
        pos += 1ll << i;
        // if (pos > n || tree[pos] + now >= sum)//第一次最大位置
        if (pos > n || tree[pos] + now > sum)  //最终最大位置
            pos -= 1ll << i;
        else
            now += tree[pos];
    }
    // return pos + 1;//第一次最大位置
    return pos;  //最终最大位置
}

// 单点更新最大值 或最小值
void updatemax(int x, int val) {
    while (x <= n) {
        tree[x] = max(tree[x], val);
        x += lowbit(x);
    }
}

// 查询前缀最大值 或最小值
int querymax(int x) {
    int t = 0;
    while (x) {
        t = max(t, tree[x]);
        x -= lowbit(x);
    }
    return t;
}