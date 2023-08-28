class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int centre = nums[nums.size() / 2], ans = 0;
        for (int val: nums) ans += abs(val - centre);
        return ans;
    }
};
