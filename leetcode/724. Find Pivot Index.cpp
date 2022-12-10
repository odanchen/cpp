class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftSum(nums.size() + 2);
        vector<int> rightSum(nums.size() + 2);
        
        for (int i = 1; i < leftSum.size() - 1; i++) leftSum[i] = leftSum[i - 1] + nums[i - 1];
        for (int i = nums.size(); i > 0; i--) rightSum[i] = rightSum[i + 1] + nums[i - 1];

        for (int i = 0; i < nums.size(); i++) if (leftSum[i] == rightSum[i + 2]) return i;

        return -1;
    }
};
