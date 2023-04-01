const int n = 1000;

//
bool check(int x) {
    ;
}

// 对n个数进行二分可能的返回值有n+1个其中第n+1个为ans的初值
// mid 会取遍l，r的所有值含端点,ans=初值是默认值一般设为 l-1或r+1
// 带不带等号由check函数决定
// 必要条件在右区间的示例如下
// 必要条件在左区间将注释的两行交换
int binsearch(int l = 1, int r = n, int a[]) {  // 搜索范围l~r
    int ans = -1;                               // 搜索不到结果时的返回值
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

// 亲情推荐
// upper_bound(a+1,a+n+1,value) - a 从左往右第一个大于
// lower_bound(a+1,a+n+1,value) - a 从左往右第一个大于等于

// 用greater让他更强^_^
// upper_bound(a+1,a+n+1,value,greater<int>()) - a 返回单调非增序列从左往右第一个小于value的数的下标
// lower_bound(a+1,a+n+1,value,greater<int>()) - a 返回单调非增序列从左往右第一个小于等于value的数的下标