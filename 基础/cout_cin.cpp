#include <bits/stdc++.h>
using namespace std;

signed main() {
    //    ������˽��ơ�ʮ���ơ�ʮ����������
    int a = 10;
    cout << "oct:" << oct << a << endl;          // �԰˽������
    cout << "dec:" << dec << a << endl;          // ��ʮ�������
    cout << "hex:" << hex << a << endl;          // ��ʮ���������
    cout << "bitset:" << bitset<32>(a) << endl;  // ���Ϊʮ��λ��������

    //    �����ָ����������
    double f = 3.1415926;
    cout << f << endl;
    // C++ ��Ĭ�����С�����5λ��
    cout << setprecision(7) << setiosflags(ios::fixed) << f << endl;  // С�����7λ
    cout << setprecision(2) << setiosflags(ios::fixed) << f << endl;  // С�������λ

    //    �����ָ��������롢��䷽ʽ������
    cout << setw(10) << 3.1415 << endl;
    cout << setw(10) << setfill('0') << 3.1415 << endl;
    cout << setw(10) << setfill('0') << setiosflags(ios::left) << 3.1415 << endl;
    cout << setw(10) << setfill('-') << setiosflags(ios::right) << 3.1415 << endl;

    // setw() �еĲ�������ָ��������������ֵû�дﵽָ�����Ŀ�ȣ�Ĭ��������ÿո��롣

    // setfill() �еĲ�������ָ�����ķ�ʽ����ΪĬ�������ǿո����Կ���ָ���Զ������䷽ʽ�������е�ֵ��Ҫʹ�õ����� �� �� ��������

    // setiosflags() �еĲ�������ָ�����뷽ʽ��Ҳ����ָ�����ķ���(���ݵ���߻����ұ�)�� ����Ϊios::leftʱ��ʾ����룬Ҳ���������ݵ��Ҳ������� ����Ϊios::rightʱ��ʾ�Ҷ��룬Ҳ���������ݵ���������� �����ö��뷽ʽʱ��Ĭ���Ҷ��������䡣

    /* ��Ϊcin */

    // cinĬ�Ϻ���ǰ������,�ո�,tab�Ȳ��ɼ��ַ� ��cin>>(char����)��cin>>(string����)ʱ������ ���� �� ����
    // ���Ҫ�����Կ���ʹ��
    // char ch;
    // cin >> noskipws >> ch;

    // cin�����ַ���Ĭ�ϴӵ�0λ��ʼ
    // cin/cout����ֱ�������ַ�����char[]
    char charArray[99];
    cin >> (charArray + 1);
    cout << (charArray + 1);

    return 0;
}