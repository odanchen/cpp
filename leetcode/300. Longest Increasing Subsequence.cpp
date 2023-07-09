class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (int val : nums) {
            if (ans.empty() or val > ans.back()) ans.push_back(val);
            else *lower_bound(ans.begin(), ans.end(), val) = val;
        }
        return ans.size();
    }
};
