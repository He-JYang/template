//�������򣨴�С����
void quickSort(int left, int right, int arr[]) {
    if (left >= right) return;
    int i, j, base, temp;
    i = left, j = right;
    base = arr[left];  //ȡ����ߵ���Ϊ��׼��
    while (i < j) {
        while (arr[j] >= base && i < j)  //��>= �ĳ�<= ��ɴӴ�С
            j--;
        while (arr[i] <= base && i < j)  //��<= �ĳ�>= ��ɴӴ�С
            i++;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //��׼����λ
    arr[left] = arr[i];
    arr[i] = base;
    quickSort(left, i - 1, arr);   //�ݹ����
    quickSort(i + 1, right, arr);  //�ݹ��ұ�
}