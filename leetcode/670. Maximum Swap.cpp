class Solution {
public:
    int maximumSwap(int num) {
        int copy = num, ans = 0;
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        for (int i = 0; i < digits.size(); i++) {
            int maxVal = i;
            for (int j = i + 1; j < digits.size(); j++) if (digits[maxVal] <= digits[j]) maxVal = j;
            if (maxVal > i and digits[i] != digits[maxVal]) {
                swap(digits[i], digits[maxVal]);
                for (int val: digits) (ans *= 10) += val;
                return ans;
            }
        }
        return copy;
    }
};
