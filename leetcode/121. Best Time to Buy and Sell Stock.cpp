class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> runningMax(prices.size());
        runningMax[runningMax.size() - 1] = prices[prices.size() - 1];
        for (int i = runningMax.size() - 2; i >= 0; i--)
        {
            runningMax[i] = max(prices[i], runningMax[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            ans = max(ans, runningMax[i + 1] - prices[i]);
        }
        return ans;
    }
};
