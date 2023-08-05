class Solution {
public:
    void backtrack(vector<vector<int>> &ans, int goal, vector<int> &selected, int sum, int k) {
        if (selected.size() == k) {
            if (sum == goal) ans.push_back(selected);
            return;
        }
        if (sum >= goal) return;
        for (int i = selected.empty() ? 1 : selected.back() + 1; i <= 9; i++) {
            selected.push_back(i);
            backtrack(ans, goal, selected, sum + i, k);
            selected.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> selected;
        vector<vector<int>> ans;
        backtrack(ans, n, selected, 0, k);
        return ans;
    }
};
