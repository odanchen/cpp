class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (auto left = prices.begin(), right = left + 1; right != prices.end(); right++) {
            if (*right < *left) left = right;
            else ans = max(ans, *right - *left);
        }
        return ans;
    }
};
