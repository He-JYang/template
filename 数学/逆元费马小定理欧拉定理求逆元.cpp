// O(log(n))
// ���ǿ������Ҷ�������±���չŷ�������һ��������a��mod����
int mod;
// x��a��mod p �����µ���Ԫ
// a*x==1(mod p) --> x=a^(p-2)mod p
int qpow(int a, int b = mod - 2, int mod) {
    int ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}