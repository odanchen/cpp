class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        for(int num : nums) {
            if (ans.empty() || num > ans.back()) ans.push_back(num);
            else {
                vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), num);
                *it = num;
            }
        }

        return ans.size();
    }
};
