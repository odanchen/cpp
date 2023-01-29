class Solution {
public:
    void solve(int n, string cur, int opened, vector<string> &ans) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }

        if (opened > 0) {
            solve(n, cur + ')', opened - 1, ans);
        }
        if (cur.size() + opened < n * 2) {
            solve(n, cur + '(', opened + 1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, "(", 1, ans);
        return ans;
    }
};
