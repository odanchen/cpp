class Solution {
public:
    bool checkPartition(vector<int> &nums, int idx, vector<int> &memo) {
        if (idx >= nums.size() or memo[idx] != -1) return idx >= nums.size() or memo[idx];
        bool ans = false;

        if (idx < nums.size() - 2) {
            if (nums[idx] == nums[idx + 1] and nums[idx + 1] == nums[idx + 2]) {
                ans |= checkPartition(nums, idx + 3, memo);
            }
            if (!ans and (nums[idx] == nums[idx + 1] - 1 and nums[idx + 1] == nums[idx + 2] - 1)) {
                ans |= checkPartition(nums, idx + 3, memo);
            }
        }
        if (!ans and idx < nums.size() - 1 and nums[idx] == nums[idx + 1]) {
            ans |= checkPartition(nums, idx + 2, memo);
        }
        return memo[idx] = ans;
    }

    bool validPartition(vector<int> &nums) {
        vector<int> memo(nums.size(), -1);
        return checkPartition(nums, 0, memo);
    }
};
