#include <bits/stdc++.h>

FILE *fin = stdin, *fout = stdout;
inline int read(int& x) {  //快读和快写，否则10^7忍受不了
    char c = 0;
    int f = x = 0;
    while (c < 48 || c > 57) {
        if (c == -1) return 0;
        if (c == '-') f = 1;
        c = fgetc(fin);
    }
    while (c > 47 && c < 58)
        x = (x << 3) + (x << 1) + (c & 15), c = fgetc(fin);
    if (f) x = -x;
    return 1;
}
inline void write(int x) {
    if (x < 0) return fputc('-', fout), write(-x);
    if (x > 9) write(x / 10);
    fputc((x % 10) | 48, fout);
}