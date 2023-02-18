//记忆化搜索/递归 做法
#include <cstdio>
#define MAX_N 20
#define ll long long
using namespace std;

//
int n;
ll f[MAX_N][MAX_N];
ll dfs(int i, int j) {
    if (f[i][j]) return f[i][j];
    if (i == 0) return 1;  //边界
    if (j > 0) f[i][j] += dfs(i, j - 1);
    f[i][j] += dfs(i - 1, j + 1);
    return f[i][j];
}
int catalan_1(int n) {
    return dfs(n, 0);
}

//递归转递推  递推做法
#include <cstdio>
#define MAX_N 20
#define ll long long
using namespace std;

//
int n;
ll f[MAX_N][MAX_N];
int catalan_2(int n) {
    for (int i = 0; i <= n; i++) {
        f[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == j)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = f[i][j - 1] + f[i - 1][j];
        }
    }
    return f[n][n];
}