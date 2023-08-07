class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        vector<int> ans;
        for (int val: nums) {
            if (ans.empty() or val > ans.back()) ans.push_back(val);
            else *lower_bound(ans.begin(), ans.end(), val) = val;
            if (ans.size() == 3) return true;
        }
        return ans.size() == 3;
    }
};
