class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits = {num % 10, (num % 100) / 10, (num % 1000) / 100,  num / 1000};
        sort(digits.begin(), digits.end());
        return (digits[0] + digits[1]) * 10 + digits[2] + digits[3];
    }
};
