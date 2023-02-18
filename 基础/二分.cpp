const int n = 1000;

//

bool check(int x) {
    ;
}

// 带不带等号由check函数决定，
// if中填什么由必要条件的区间决定
// 必要条件：（一般是一定满足第一个条件，可能满足第二个条件，一定存在答案的区间）
int binsearch(int l = 1, int r = n, int a[]) {
    int mid = (l + r) / 2;
    // int mid = (l + r + 1) / 2;  //必要条件在左
    while (l < r) {
        if (check(mid)) {
            r = mid;  //必要条件在右
            // l = mid;  //必要条件在左
        } else {
            l = mid + 1;  //必要条件在右
            // r = mid - 1;  //必要条件在左
        }
        mid = (l + r) / 2;
        // mid = (l + r + 1) / 2;//必要条件在左
    }
    return l;
}