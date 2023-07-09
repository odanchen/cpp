class Solution {
public: 
    long long seriesSum(int a, int n) {
        return ((2ll * a - n + 1) / 2.0) * n;
    }
    long long calcSum(int num, int n, int index) {
        long long sum = 0;
        sum += (num > n - index) ? seriesSum(num, n - index) : seriesSum(num, num) - num + n - index;
        sum += (num - 1 > index) ? seriesSum(num - 1, index) : seriesSum(num - 1, num - 1) - num + 1 + index;
        return sum;
    }
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        while (left < right) {
            int mid = (left + right) / 2;
            long long sum = calcSum(mid, n, index);
            if (sum > INT_MAX or sum > maxSum) right = mid - 1;
            else left = mid;

            if (left == right - 1) {
                long long sum =  calcSum(right, n, index);
                return sum <= INT_MAX and sum <= maxSum ? right : left;
            }
        }
        return left;
    }
};
