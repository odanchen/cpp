class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0, ans = nums.size(); ans > 0; i++, ans--) {
            if (nums[i] >= ans and (i == 0 or nums[i - 1] < ans)) return ans;
        }
        return -1;
    }
};
