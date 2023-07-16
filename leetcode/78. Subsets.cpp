class Solution {
public:
    void backTrack(vector<int> &nums, vector<int> &cur, vector<vector<int>> &ans, int idx) {
        ans.push_back(cur);
        if (idx == nums.size()) return;
        
        while(idx < nums.size()) {
            cur.push_back(nums[idx++]);
            backTrack(nums, cur, ans, idx);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<vector<int>> ans;
        backTrack(nums, cur, ans, 0);
        return ans;
    }
};
