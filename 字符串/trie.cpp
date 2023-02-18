//   trie tree�Ĵ��淽ʽ������ĸ�����ڱ��ϣ��ߵĽڵ�����������������ĸ
//   trie[rt][x]=tot:rt���ϸ��ڵ��ţ�x����ĸ��tot���¸��ڵ���
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
    }                               // root������ѭ������ǰ׺���һ����ĸ����λ��
    if (op == 1) return isw[root];  // op=1��ѯ�Ƿ�Ϊ���ʻ򵥴ʳ��ֵĴ���
    if (op == 2) return sum[root];  // op=2��ѯǰ׺�ͳ��ֵĴ���
    return 1;                       // op=0�Ƿ�Ϊǰ׺�򵥴�
}
void insert(char s[]) {
    int len = strlen(s);
    int root = 0;
    for (int i = 0; i < len; i++) {
        int id = s[i] - 'a';
        if (!trie[root][id]) trie[root][id] = ++tot;
        root = trie[root][id];
        sum[root]++;  //ǰ׺����
    }
    isw[root]++;  //��־�õ���ĩλ��ĸ��β��㣬�ڲ�ѯ��������ʱ�õ�
}