// O(n)求区间最大最小值后O(1)转移
// 单调队列,又名双端队列
// 直接在后面加括号的话相当于初始向里面添加了n个元素0  queue<int>q1(n);
// vector<int>v1(n);也是push_back的话会直接push到n+1的位置即v1[n]的位置;
// 无法初始化容量，用q1.resize()和q1(n)一样的效果T_T
// 如果要卡常建议开两倍大小手写deque
