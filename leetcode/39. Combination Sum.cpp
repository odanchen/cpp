class Solution {
public:
    typedef vector<int>::iterator iter;
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> cur, int sum, iter it, int target) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }

        while(it != nums.end() and sum + *it <= target) {
            cur.push_back(*it);
            solve(ans, nums, cur, sum + *it, it, target);
            cur.pop_back();
            it++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(ans, candidates, vector<int>(), 0, candidates.begin(), target);
        return ans;
    }
};
