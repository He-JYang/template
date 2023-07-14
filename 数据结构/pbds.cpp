#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
/*
    定义一颗红黑树
    int 关键字类型
    null_type无映射(低版本g++为null_mapped_type)
    less<int>从小到大排序
    rb_tree_tag 红黑树（splay_tree_tag）
    tree_order_statistics_node_update结点更新
    插入t.insert();
    删除t.erase();
    求k在树中是第几大:t.order_of_key();
    求树中的第k大:t.find_by_order();
    前驱:t.lower_bound();
    后继t.upper_bound();
    a.join(b)b并入a 前提是两棵树的key的取值范围不相交
    a.split(v,b)key小于等于v的元素属于a，其余的属于b
    T.lower_bound(x)   >=x的min的迭代器
    T.upper_bound(x)   >x的min的迭代器
    T.find_by_order(k) 有k个数比它小的数
*/
/* 第一个参数代表key的类型 第二个参数表示value的类型。这里不需要映射值，也就填null_type。在老版本G++这个需要替换为null_mapped_type（如BZOJ）。 第三个参数表示key的排序方式，从小到大。 第四个参数表示使用哪种数据结构，rb_tree_tag表示红黑树。 第五个参数表示如何更新保存节点信息，填写tree_order_statistics_node_update会额外获得order_of_key() 和find_by_order() 两个功能。 */

int example() {
    // 例子:
    // P3369 【模板】普通平衡树

    // 您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：

    // 1  插入xx数
    // 2  删除xx数(若有多个相同的数，因只删除一个)
    // 3  查询xx数的排名(排名定义为比当前数小的数的个数 + 1 + 1。若有多个相同的数，因输出最小的排名)
    // 4  查询排名为xx的数
    // 5  求xx的前驱(前驱定义为小于xx，且最大的数)
    // 6  求xx的后继(后继定义为大于xx，且最小的数)

    typedef long long ll;
    typedef __gnu_pbds::tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> RBT;
    RBT rbt;
    ll T, op, x;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &op, &x);
        if (op == 1)
            rbt.insert((x << 20) + T + 1);
        else if (op == 2)
            rbt.erase(rbt.lower_bound(x << 20));
        else if (op == 3)
            printf("%lld\n", rbt.order_of_key(x << 20) + 1);
        else if (op == 4)
            printf("%lld\n", *rbt.find_by_order(x - 1) >> 20);
        else if (op == 5)
            printf("%lld\n", *(--rbt.lower_bound(x << 20)) >> 20);
        else if (op == 6)
            printf("%lld\n", *rbt.upper_bound((x + 1) << 20) >> 20);
    }

    // 另一种用vector的写法写法:
    vector<int> a;
    switch (op) {
        case (1):
            a.insert(upper_bound(a.begin(), a.end(), x), x);
            break;
        case (2):
            a.erase(lower_bound(a.begin(), a.end(), x));
            break;
        case (3):
            cout << lower_bound(a.begin(), a.end(), x) - a.begin() + 1 << endl;
            break;
        case (4):
            cout << a[x - 1] << endl;
            break;
        case (5):
            cout << *--lower_bound(a.begin(), a.end(), x) << endl;
            break;
        case (6):
            cout << *upper_bound(a.begin(), a.end(), x) << endl;
            break;
    }

    return 0;
}
