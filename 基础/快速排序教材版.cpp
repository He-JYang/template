//快速排序（从小到大）
void quickSort(int left, int right, int arr[]) {
    if (left >= right) return;
    int i, j, base, temp;
    i = left, j = right;
    base = arr[left];  //取最左边的数为基准数
    while (i < j) {
        while (arr[j] >= base && i < j)  //将>= 改成<= 变成从大到小
            j--;
        while (arr[i] <= base && i < j)  //将<= 改成>= 变成从大到小
            i++;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //基准数归位
    arr[left] = arr[i];
    arr[i] = base;
    quickSort(left, i - 1, arr);   //递归左边
    quickSort(i + 1, right, arr);  //递归右边
}