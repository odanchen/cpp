class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, left = 0, right = 0;
        while(right < nums.size() and sum < target) sum += nums[right++];
        if (sum < target) return 0;
        while (sum - nums[left] >= target) sum -= nums[left++];
        while (right < nums.size()) {
            sum += nums[right++];
            sum -= nums[left++];
            while (sum - nums[left] >= target) sum -= nums[left++];
        }
        return right - left;
    }
};
