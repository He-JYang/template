#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
typedef unsigned long long ull;
const int hashmod = 1e18 + 2049;

//

int Hash(char s[]) {  //��scanf�ӿ����
    int base = 131;
    int val = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        val = (base * val + (ull)s[i]) % hashmod;
    }
    return val;
    //ö�ٸ��ַ�����ÿһλ����base��ˣ�ת��Ϊbase���ƣ���(ull)��Ϊ�˷�ֹ��ջ���һ��������(ull)���޷��ŵģ�����ʵ����һ��ull�ǿ��Բ���mod�ģ��Ӹ�mod������
    //Ȼ������mod�����ѧ��Ī���Ȳ���mod����300��ms
}