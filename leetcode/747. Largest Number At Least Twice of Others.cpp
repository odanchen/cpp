class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int first = -1, second = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (first == -1) first = i;
            else if (nums[i] > nums[first]) {
                swap(first, second);
                first = i;
            } else if (second == -1 or nums[i] > nums[second]) second = i;
        }
        return nums[first] / 2 >= nums[second] ? first : -1;
    }
};
