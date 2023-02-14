class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = min(num / 2 + 1, 46340);
        while(left < right) {
            int mid = (left + right) / 2;
            if (mid * mid > num) right = mid -1;
            else if (left == right -1) return (right * right > num) ? left * left == num : right * right == num;
            else left = mid;
        }
        return left * left == num;
    }
};
