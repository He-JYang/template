const int n = 1000;

//

bool check(int x) {
    ;
}

// �������Ⱥ���check����������
// if����ʲô�ɱ�Ҫ�������������
// ��Ҫ��������һ����һ�������һ����������������ڶ���������һ�����ڴ𰸵����䣩
int binsearch(int l = 1, int r = n, int a[]) {
    int mid = (l + r) / 2;
    // int mid = (l + r + 1) / 2;  //��Ҫ��������
    while (l < r) {
        if (check(mid)) {
            r = mid;  //��Ҫ��������
            // l = mid;  //��Ҫ��������
        } else {
            l = mid + 1;  //��Ҫ��������
            // r = mid - 1;  //��Ҫ��������
        }
        mid = (l + r) / 2;
        // mid = (l + r + 1) / 2;//��Ҫ��������
    }
    return l;
}