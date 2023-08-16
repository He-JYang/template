#include <bits/stdc++.h>
using namespace std;
const int N = 10010, S = 55, M = 1000010;
char s[M];
int idx, cnt[N * S], tr[N * S][26];
int fail[N * S];

// fail[u]数组含义：u的下一位匹配失败跳转的位置 fail[u]要跳转的地方最后一位与u相同 与kmp模板一样 与数据结构书上不同

void insert() {  // 像普通字典树一样插入
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int t = s[i] - 'a';
        if (!tr[p][t]) tr[p][t] = ++idx;
        p = tr[p][t];
    }
    cnt[p]++;
}
void build_fail() {
    queue<int> Q;
    for (int i = 0; i < 26; i++) {
        if (tr[0][i]) Q.push(tr[0][i]);
    }
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++) {
            int v = tr[u][i];
            // 如果!v说明没有该儿子,那么我们可以通过路径压缩的思想,看看其父亲对于该儿子是指向何处,如果
            // 其父亲也不知道该指向何处,那么就会询问其父亲的父亲。
            if (!v) {
                tr[u][i] = tr[fail[u]][i];
            } else {
                fail[v] = tr[fail[u]][i];
                Q.push(v);
            }
        }
    }
}
void example_use() {
    idx = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert();
    }
    build_fail();  // 树上建立NEXT数组,用BFS
    scanf("%s", s);
    int res = 0;  // 统计不同子串的个数
    for (int i = 0, p = 0; s[i]; i++) {
        int t = s[i] - 'a';
        p = tr[p][t];
        int use = p;  // 统计以当前串为后缀的条件下，符合条件的子串个数。
        // 为-1的话说明当前串串前面已经统计过了,我们不必重复统计,因为我们只是统计不同串出没出现,而不是出现几次。
        while (use && cnt[use] != -1) {
            res += cnt[use];
            cnt[use] = -1;  // 统计过了更新成-1
            use = fail[use];
        }
    }
    printf("%d\n", res);
}
