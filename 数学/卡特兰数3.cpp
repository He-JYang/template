#include <cstdio>
#include <cstring>  //Ϊ��NOIP��������ͷ�ļ�
#include <iostream>
using namespace std;

//
int f[20][20];  //���ݾ͸���18������20��󷽵�
int n;
int catalan(int n) {
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= n; i++)
        f[i][0] = 1;  //�߽�һ��Ҫ��
    for (int j = 1; j <= n; j++)
        for (int i = 0; i <= n; i++)
        //����Ҫ��f[0][n]������iҪ���㿪ʼ��
        {
            if (i >= 1) f[i][j] = f[i - 1][j] + f[i + 1][j - 1];
            if (i == 0)  //ջ��û�ж���
                f[i][j] = f[i + 1][j - 1];
        }
    return f[0][n];
}