class Solution {
public:
    static const int mod = 1000000007;
    int numTilings(int n) {
        vector<int> dp(max(3, n));
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;
        for (int i = 3; i < n; i++) dp[i] = ((2 * dp[i - 1]) % mod + (dp[i - 3]) % mod) % mod;
        return dp[n - 1];
    }
};
