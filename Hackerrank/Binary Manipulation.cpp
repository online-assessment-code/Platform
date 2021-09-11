long minOperations(long n, long res = 0) {
    if (n == 0) return res;
    long b = 1;
    while ((b << 1) <= n)
        b = b << 1;
    return minOperations((b >> 1) ^ b ^ n, res + b);
}
