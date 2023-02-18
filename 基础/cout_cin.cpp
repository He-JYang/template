#include <bits/stdc++.h>
using namespace std;

signed main() {
    //    ①输出八进制、十进制、十六进制数据
    int a = 10;
    cout << "oct:" << oct << a << endl;          // 以八进制输出
    cout << "dec:" << dec << a << endl;          // 以十进制输出
    cout << "hex:" << hex << a << endl;          // 以十六进制输出
    cout << "bitset:" << bitset<32>(a) << endl;  // 输出为十六位二进制数

    //    ②输出指定精度数据
    double f = 3.1415926;
    cout << f << endl;
    // C++ 中默认输出小数点后5位数
    cout << setprecision(7) << setiosflags(ios::fixed) << f << endl;  // 小数点后7位
    cout << setprecision(2) << setiosflags(ios::fixed) << f << endl;  // 小数点后两位

    //    ③输出指定域宽、对齐、填充方式的数据
    cout << setw(10) << 3.1415 << endl;
    cout << setw(10) << setfill('0') << 3.1415 << endl;
    cout << setw(10) << setfill('0') << setiosflags(ios::left) << 3.1415 << endl;
    cout << setw(10) << setfill('-') << setiosflags(ios::right) << 3.1415 << endl;

    // setw() 中的参数用于指定域宽，对于输出的值没有达到指定域宽的宽度，默认在左侧用空格补齐。

    // setfill() 中的参数用于指定填充的方式，因为默认填充的是空格，所以可以指定自定义的填充方式，参数中的值需要使用单引号 ’ ’ 括起来。

    // setiosflags() 中的参数用于指定对齐方式，也就是指明填充的方向(数据的左边或者右边)。 参数为ios::left时表示左对齐，也就是在数据的右侧进行填充 参数为ios::right时表示右对齐，也就是在数据的左侧进行填充 不设置对齐方式时则默认右对齐进行填充。

    /* 下为cin */

    // cin默认忽略前导换行,空格,tab等不可见字符 在cin>>(char类型)或cin>>(string类型)时会引起 跳过 和 结束
    // 如果要不忽略可以使用
    // char ch;
    // cin >> noskipws >> ch;

    // cin输入字符串默认从第0位开始
    // cin/cout可以直接输入字符数组char[]
    char charArray[99];
    cin >> (charArray + 1);
    cout << (charArray + 1);

    return 0;
}