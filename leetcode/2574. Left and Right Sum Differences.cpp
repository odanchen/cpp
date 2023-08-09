class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size()), rightSum(nums.size()), ans(nums.size());
        for (int i = 1; i < leftSum.size(); i++) leftSum[i] = leftSum[i - 1] + nums[i - 1];
        for (int i = rightSum.size() - 2; i >= 0; i--) rightSum[i] = rightSum[i + 1] + nums[i + 1];
        for (int i = 0; i < ans.size(); i++) ans[i] = abs(leftSum[i] -rightSum[i]);
        return ans;
    }
};
