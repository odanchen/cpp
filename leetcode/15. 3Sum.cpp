class Solution {
public:
    void getTriplets(int i, vector<int> &nums, vector<vector<int>> &ans) {
        int goal = (-1) * nums[i];
        int left = i + 1, right = nums.size() - 1;
        while(left < right) {
            if (left == right) {
                if (left + right == goal) ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                return;
            }
            if (nums[left] + nums[right] < goal) {
                while(left < right and nums[left] + nums[right] < goal) left++;
            }
            else if (nums[left] + nums[right] > goal) {
                while(left < right and nums[left] + nums[right] > goal) right--;
            }
            else {
                ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                do {left++;} while (nums[left - 1] == nums[left] && left < right);
                do {right--;} while (nums[right + 1] == nums[right] && left < right);
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 or nums[i] != nums[i - 1]) {
                getTriplets(i, nums, ans);
            }
        }
        return ans;
    }
};
