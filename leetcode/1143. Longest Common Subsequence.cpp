class Solution {
public:
    int recurse(string &text1, string &text2, int m, int n, vector<vector<int>> &memo) {
        if (m == 0 || n == 0) return 0;
        if (memo[m][n] != -1) return memo[m][n];
        if (text1[m - 1] == text2[n - 1]) return memo[m][n] = 1 + recurse(text1, text2, m - 1, n - 1, memo);
        return memo[m][n] = max(recurse(text1, text2, m - 1, n, memo), recurse(text1, text2, m, n - 1, memo));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return recurse(text1, text2, text1.size(), text2.size(), memo);
    }
};
