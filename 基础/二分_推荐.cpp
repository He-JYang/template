const int n = 1000;

//
bool check(int x) {
    ;
}

// �������Ⱥ���check��������
// ��Ҫ�������������ʾ������
// ��Ҫ�����������佫ע�͵����н���
int binsearch(int l = 0, int r = n, int a[]) {  //������Χl~r
    int ans = -1;                               // �����������ʱ�ķ���ֵ
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;  //
        } else {
            r = mid - 1;  //
        }
    }
    return ans;
}

// �����Ƽ�
// upper_bound(a+1,a+n+1,value) - a �������ҵ�һ������
// lower_bound(a+1,a+n+1,value) - a �������ҵ�һ�����ڵ���

// ��greater������ǿ^_^
// upper_bound(a+1,a+n+1,value,greater<int>()) - a ���ص����������д������ҵ�һ��С��value�������±�
// lower_bound(a+1,a+n+1,value,greater<int>()) - a ���ص����������д������ҵ�һ��С�ڵ���value�������±�