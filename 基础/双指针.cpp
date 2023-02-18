#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
bool check();

// 滑动窗口型双指针
// 写法一：
void solve1() {
    for (int r = 0, l = 1;;) {  //右边界
        if (++r > n) break;
        // push

        while (!check()) {
            // pop
            l++;
        }
        ans = max(ans, l - r + 1);
    }
}

// 写法二：
void solve2() {
    int l = 1, r = 0;
    while (1) {
        if (check()) {
            ans = max(ans, l - r + 1);
            if (++r > n) break;

            // push
        } else {
            // pop
            l++;
        }
    }
}
