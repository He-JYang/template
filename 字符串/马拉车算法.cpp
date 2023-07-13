// 算法讲解
// https://zhuanlan.zhihu.com/p/70532099
// 马拉车算法 Manacher‘s Algorithm 是用来查找一个字符串的最长回文子串的线性方法

using namespace std;

string preProcess(string s) {
    int n = s.length();
    if (n == 0) { return "^$"; }
    string ret = "^";
    for (int i = 0; i < n; i++)
        ret += "#" + s.charAt(i);
    ret += "#$";
    return ret;
}

// 马拉车算法

string longestPalindrome2(string s) {
    string T = preProcess(s);
    int n = T.length();
    int[] P = new int[n];
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i;
        if (R > i) {
            P[i] = min(R - i, P[i_mirror]);  // 防止超出 R
        } else {
            P[i] = 0;  // 等于 R 的情况
        }

        // 碰到之前讲的三种情况时候，需要利用中心扩展法
        while (T.charAt(i + 1 + P[i]) == T.charAt(i - 1 - P[i])) {
            P[i]++;
        }

        // 判断是否需要更新 R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // 找出 P 的最大值
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;  // 最开始讲的求原字符串下标
    return s.substring(start, start + maxLen);
}
