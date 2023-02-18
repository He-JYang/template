//   trie tree的储存方式：将字母储存在边上，边的节点连接与它相连的字母
//   trie[rt][x]=tot:rt是上个节点编号，x是字母，tot是下个节点编号
#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
int tot = 1;

//

int trie[N][26];
int isw[N];
int sum[N];
int search(char s[], int op = 1) {
    int root = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int id = s[i] - 'a';
        if (!trie[root][id]) return 0;
        root = trie[root][id];
    }                               // root经过此循环后变成前缀最后一个字母所在位置
    if (op == 1) return isw[root];  // op=1查询是否为单词或单词出现的次数
    if (op == 2) return sum[root];  // op=2查询前缀和出现的次数
    return 1;                       // op=0是否为前缀或单词
}
void insert(char s[]) {
    int len = strlen(s);
    int root = 0;
    for (int i = 0; i < len; i++) {
        int id = s[i] - 'a';
        if (!trie[root][id]) trie[root][id] = ++tot;
        root = trie[root][id];
        sum[root]++;  //前缀保存
    }
    isw[root]++;  //标志该单词末位字母的尾结点，在查询整个单词时用到
}