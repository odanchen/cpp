class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left, right;
        left = 0;
        right = numbers.size() - 1;

        while(numbers[left] + numbers[right] != target)
        {
            if(numbers[left] + numbers[right] > target) right--;
            else left++;
        }

        return (vector<int>) {left + 1, right + 1};
    }
};
