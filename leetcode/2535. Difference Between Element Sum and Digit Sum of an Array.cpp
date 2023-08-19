class Solution {
public:
    int getDigitSum(int num) {
        if (num == 0) return 0;
        return getDigitSum(num / 10) + num % 10;
    }
    int differenceOfSum(vector<int>& nums) {
        int digitSum = 0, elementSum = 0;
        for (int val: nums) {
            digitSum += getDigitSum(val);
            elementSum += val;
        }
        return elementSum - digitSum;
    }
};
