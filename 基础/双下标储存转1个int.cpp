int encode(int id1, int id2) {
    return id1 * 1000000 + id2;
}
int decode1(int code) {
    return code / 1000000;
}
int decode2(int code) {
    return code % 1000000;
}
