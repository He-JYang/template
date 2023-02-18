#include <bits/stdc++.h>
using namespace std;

void clock_break(int ans) {  // 在你觉得可能超时的循环中加入它
    if ((double)clock() / CLOCKS_PER_SEC > 0.987) {
        cout << ans;
        exit(0);
    }
}