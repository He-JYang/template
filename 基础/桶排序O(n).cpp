// #Ͱ����#

// ��ν��Ͱ�ţ����ǿ�һ��Ͱcnt,����cnt[i]?��ʾ����i�ĳ��ִ����������÷ǳ��򵥣�
// ʱ�临�Ӷ�O��n��

const int N = 1e7 + 10;
int a[N], cntt[N];
// aΪ�������У�cntΪͰ

//
void bucketsort(int n, int max_num) {  // max_num���ܳ��ֵ�������
    for (int i = 1; i <= n; i++) {
        cntt[a[i]]++;
    }
    int pos = 1;
    for (int i = 0; i < max_num; i++) {
        for (int j = 0; j < cntt[i]; j++) {
            a[pos++] = i;
        }
    }
}
