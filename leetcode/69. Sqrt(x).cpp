class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = min(x / 2 + 1, 46340);
        while(left < right) {
            int mid = (left + right) / 2;
            if (mid * mid > x) right = mid -1;
            else if (left == right -1) return (right * right > x) ? left : right;
            else left = mid;
        }
        return left;
    }
};
