#include <bits/stdc++.h>

//¿ì¶Á
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
        if (c == '-') {
            f = -1;
            c = getchar();
        }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//¿ìÐ´
inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}