#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// ����dilworth�������½���������С��������������������еĳ��ȡ�
//     ���Ǻ��������ּ򻯳���n�������������������

vector<pii> v1;

int dp[11111];

signed solve() {
    int n;

    for (int i = 1; i <= n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        v1.push_back({x1, x2});
    }
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    int tot = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (v1[i].second > dp[tot]) {
            dp[++tot] = v1[i].second;
        } else {
            int pos = lower_bound(dp + 1, dp + tot + 1, v1[i].second) - dp;
            dp[pos] = v1[i].second;
        }
    }
    cout << tot;

    return 0;
}