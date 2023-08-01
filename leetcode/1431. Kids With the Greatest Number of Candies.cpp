class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxVal = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size());
        for (int i = 0; i < ans.size(); i++) ans[i] = candies[i] + extraCandies >= maxVal;
        return ans;
    }
};
