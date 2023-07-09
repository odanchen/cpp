class Solution {
public:
    int rob(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] += max(i - 2 < 0 ? 0 : nums[i - 2], i - 3 < 0 ? 0 : nums[i - 3]);
        }
        return nums.size() > 1 ? max(nums.back(), nums[nums.size() - 2]) : nums.back();
    }
};
