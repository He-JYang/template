#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];

void qsort(int l, int r)  //Ӧ�ö���˼��
{
    int mid = a[(l + r) / 2];  //�м���
    int i = l, j = r;
    do {
        while (a[i] < mid)
            i++;  //������벿�ֱ��м��������
        while (a[j] > mid)
            j--;     //�����Ұ벿�ֱ��м���С����
        if (i <= j)  //�����һ�鲻����������������С�Ҵ󣩵���
        {
            swap(a[i], a[j]);  //����
            i++;               // �ɼ�дΪswap(a[i++],a[j--]);
            j--;
        }
    } while (i <= j);        //����ע��Ҫ��=
    if (l < j) qsort(l, j);  //�ݹ�������벿��
    if (i < r) qsort(i, r);  //�ݹ������Ұ벿��
}