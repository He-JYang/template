// 算法讲解
// https://zhuanlan.zhihu.com/p/70532099
// 马拉车算法 Manacher‘s Algorithm 是用来查找一个字符串的最长回文子串的线性方法

#include <bits/stdc++.h>
using namespace std;

// 马拉车算法
const int maxn = 1e6 + 10;
string temp;
int p[maxn];

string longestPalindrome2(string& s) {
    temp = "^";
    for (auto ch : s) {
        temp += "#" + ch;
    }
    if (s.length()) temp += "#";
    temp += "$";

    int n = temp.length();
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i;
        p[i] = min(R - i, p[i_mirror]);  // 防止超出 R

        // 碰到之前讲的三种情况时候，需要利用中心扩展法
        while (temp[i + 1 + p[i]] == temp[i - 1 - p[i]]) {
            p[i]++;
        }

        // 判断是否需要更新 R
        if (i + p[i] > R) {
            C = i;
            R = i + p[i];
        }
    }

    // 找出 p 的最大值
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;  // 最开始讲的求原字符串下标
    return s.substr(start, start + maxLen);
}
