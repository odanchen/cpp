class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 2, ans = nums.front();
        while (left < nums.size()) {
            ans += nums[left];
            left += 2;
        }
        return ans;
    }
};
