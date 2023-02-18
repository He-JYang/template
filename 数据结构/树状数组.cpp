// # ��״���� #

#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & (-x))  // ����������С�߶γ���
const int N = 1e5 + 10;
int n;
int tree[N];

inline void update(int pos, int x) {  //����pos����x   pos!=0 �����δ���
    for (int i = pos; i <= n; i += lowbit(i)) {
        tree[i] += x;
    }
}

inline int query(int pos) {  //��ǰpos��� pos=0ʱ����0
    int ans = 0;
    for (int i = pos; i; i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}

int queryi(int sum, int n = N) {  // �൱�ڲ�ѯsum[pos]<=sum�����λ�ã�nΪ���������ĸ���;
    // �滻ע���޸�Ϊsum[pos]<=sum�ĵ�һ�����λ�ã�������a[i]==0��λ��

    int pos = 0;
    int now = 0;
    for (int i = 31ll; i >= 0; --i) {
        pos += 1ll << i;
        // if (pos > n || tree[pos] + now >= sum)//��һ�����λ��
        if (pos > n || tree[pos] + now > sum)  //�������λ��
            pos -= 1ll << i;
        else
            now += tree[pos];
    }
    // return pos + 1;//��һ�����λ��
    return pos;  //�������λ��
}

// ����������ֵ ����Сֵ
void updatemax(int x, int val) {
    while (x <= n) {
        tree[x] = max(tree[x], val);
        x += lowbit(x);
    }
}

// ��ѯǰ׺���ֵ ����Сֵ
int querymax(int x) {
    int t = 0;
    while (x) {
        t = max(t, tree[x]);
        x -= lowbit(x);
    }
    return t;
}