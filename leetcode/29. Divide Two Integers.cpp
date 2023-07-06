class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1 and dividend == INT_MIN) return INT_MAX; 
        long long dvd = abs(dividend), dvs = abs(divisor), ans = 1;
        if (dvs > dvd) return 0;
        while(dvs << 1 < dvd) {
            dvs = dvs << 1;
            ans = ans << 1;
        }
        return dividend > 0 ^ divisor > 0 ? 
            -ans - abs(divide((int) (dvd - dvs), divisor)) : 
            ans + abs(divide((int) (dvd - dvs), divisor));
    }
}; 
