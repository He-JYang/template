#include <bits/stdc++.h>
using namespace std;
const int N = 10010, S = 55, M = 1000010;
char s[M];
int idx, cnt[N * S], tr[N * S][26];
int fail[N * S];

// fail[u]���麬�壺u����һλƥ��ʧ����ת��λ�� fail[u]Ҫ��ת�ĵط����һλ��u��ͬ ��kmpģ��һ�� �����ݽṹ��ͬ

void insert() {  //����ͨ�ֵ���һ������
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
        int t = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++) {
            int u = tr[t][i];
            //���!u˵��û�иö���,��ô���ǿ���ͨ��·��ѹ����˼��,�����丸�׶��ڸö�����ָ��δ�,���
            //�丸��Ҳ��֪����ָ��δ�,��ô�ͻ�ѯ���丸�׵ĸ��ס�
            if (!u) {
                tr[t][i] = tr[fail[t]][i];
            } else {
                fail[u] = tr[fail[t]][i];
                Q.push(u);
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
    build_fail();  //���Ͻ���NEXT����,��BFS
    scanf("%s", s);
    int res = 0;  //ͳ�Ʋ�ͬ�Ӵ��ĸ���
    for (int i = 0, p = 0; s[i]; i++) {
        int t = s[i] - 'a';
        p = tr[p][t];
        int use = p;  //ͳ���Ե�ǰ��Ϊ��׺�������£������������Ӵ�������
        //Ϊ-1�Ļ�˵����ǰ����ǰ���Ѿ�ͳ�ƹ���,���ǲ����ظ�ͳ��,��Ϊ����ֻ��ͳ�Ʋ�ͬ����û����,�����ǳ��ּ��Ρ�
        while (use && cnt[use] != -1) {
            res += cnt[use];
            cnt[use] = -1;  //ͳ�ƹ��˸��³�-1
            use = fail[use];
        }
    }
    printf("%d\n", res);
}
