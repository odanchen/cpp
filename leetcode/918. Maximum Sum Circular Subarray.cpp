class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMin(nums[0]), curMax(nums[0]), total(nums[0]), totalMin(nums[0]), totalMax(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            total += nums[i];
            curMax = max(curMax + nums[i], nums[i]);
            curMin = min(curMin + nums[i], nums[i]);
            totalMax = max(totalMax, curMax);
            totalMin = min(totalMin, curMin);
        }
        return totalMax < 0 ? totalMax : max(totalMax, total - totalMin);
    }
};
