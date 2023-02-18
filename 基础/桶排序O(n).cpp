// #桶排序#

// 所谓的桶排，就是开一个桶cnt,其中cnt[i]?表示数字i的出现次数。排序变得非常简单：
// 时间复杂度O（n）

const int N = 1e7 + 10;
int a[N], cntt[N];
// a为待排序列，cnt为桶

//
void bucketsort(int n, int max_num) {  // max_num可能出现的最大的数
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
