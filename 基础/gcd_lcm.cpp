//最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//最小公倍数
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
