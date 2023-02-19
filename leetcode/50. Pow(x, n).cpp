class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 or x == 1) return 1;
        if (!(n & 1)) {
            x *= x;
            n /= 2;
        }
        return (n < 0) ? 1 / myPow(x, -n) : x * myPow(x, n - 1);
    }
};
