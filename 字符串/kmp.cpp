#include <bits/stdc++.h>
using namespace std;

int kmp[1000];

// kmp[j]表示j+1位匹配失败后要跳转的位置

// a[]从0开始有效
void kmp_match(char a[], char b[]) {  // a为主串b为模式串 （简单点说a长，b短）
    int la = strlen(a);
    int lb = strlen(b);
    
    kmp[0] = -1;
    int j = -1;
    for (int i = 1; i < lb; i++) {
        while (j != -1 && b[i] != b[j + 1])
            j = kmp[j];
        //此处判断j是否为0的原因在于，如果回跳到第一个字符就不用再回跳了
        //通过自己匹配自己来得出每一个点的kmp值
        if (b[j + 1] == b[i]) j++;
        kmp[i] = j;
        // i+1失配后应该如何跳
    }

    j = -1;  // j可以看做表示当前已经匹配完的模式串的最后一位的位置
    //如果楼上看不懂，你也可以理解为j表示模式串匹配到第几位了
    for (int i = 0; i < la; i++) {
        while (j != -1 && b[j + 1] != a[i])
            j = kmp[j];
        //如果失配 ，那么就不断向回跳，直到可以继续匹配
        if (b[j + 1] == a[i]) j++;
        //如果匹配成功，那么对应的模式串位置++
        if (j == lb - 1) {
            j = kmp[j];
            //继续匹配
        }
    }
}