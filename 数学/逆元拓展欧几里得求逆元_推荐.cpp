// O(log(n))
// ��չŷ�����xΪa����ԪbΪģ,x,y���ó�ʼ��ʲôֵ������
// һ������0����С���������䱾��
int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    } else {
        int gcd = exgcd(b, a % b, y, x);
        y -= x * (a / b);  // �˴�һ��Ҫ�ȳ���˲�Ȼ���ܱ����Ƚ��������
        return gcd;
    }
}
void use() {
    int x, y, a, mod;

    exgcd(a, mod, x, y);

    x = (x % mod + mod) % mod;
}