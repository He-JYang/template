#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];

void qsort(int l, int r)  //应用二分思想
{
    int mid = a[(l + r) / 2];  //中间数
    int i = l, j = r;
    do {
        while (a[i] < mid)
            i++;  //查找左半部分比中间数大的数
        while (a[j] > mid)
            j--;     //查找右半部分比中间数小的数
        if (i <= j)  //如果有一组不满足排序条件（左小右大）的数
        {
            swap(a[i], a[j]);  //交换
            i++;               // 可简写为swap(a[i++],a[j--]);
            j--;
        }
    } while (i <= j);        //这里注意要有=
    if (l < j) qsort(l, j);  //递归搜索左半部分
    if (i < r) qsort(i, r);  //递归搜索右半部分
}