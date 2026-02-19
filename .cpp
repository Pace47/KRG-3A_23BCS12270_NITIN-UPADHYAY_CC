class Solution {
public:
    long long g(long long x, long long y) {
        while (y) {
            long long t = x % y;
            x = y;
            y = t;
        }
        return x;
    }

    int nthMagicalNumber(int n, int a, int b) {
        const long long MOD = 1e9 + 7;

        long long d = g(a, b);
        long long l = 1LL * a / d * b;

        long long lo = 1, hi = 1LL * n * min(a, b);

        while (lo < hi) {
            long long m = (lo + hi) / 2;
            long long c = m / a + m / b - m / l;

            if (c < n) lo = m + 1;
            else hi = m;
        }

        return lo % MOD;
    }
};
