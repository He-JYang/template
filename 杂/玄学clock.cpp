#include <bits/stdc++.h>
using namespace std;

void clock_break(int ans) {  // ������ÿ��ܳ�ʱ��ѭ���м�����
    if ((double)clock() / CLOCKS_PER_SEC > 0.987) {
        cout << ans;
        exit(0);
    }
}