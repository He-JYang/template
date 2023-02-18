#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
typedef unsigned long long ull;
const int hashmod = 1e18 + 2049;

//

int Hash(char s[]) {  //用scanf加快读入
    int base = 131;
    int val = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        val = (base * val + (ull)s[i]) % hashmod;
    }
    return val;
    //枚举该字符串的每一位，与base相乘，转化为base进制，加(ull)是为了防止爆栈搞出一个负数，(ull)是无符号的，但其实加了一个ull是可以不用mod的，加个mod更保险
    //然而加了mod会很玄学，莫名比不加mod慢了300多ms
}