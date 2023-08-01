class Solution {
public:
    void addCombination(int n, int k, vector<int> &arr, vector<vector<int>> &ans) {
        if (arr.size() == k) {
            ans.push_back(arr);
            return;
        }

        int back = arr.empty() ? 0 : arr.back();
        for (int i = back + 1; i <= n; i++) {
            arr.push_back(i);
            addCombination(n, k, arr, ans);
            arr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        addCombination(n, k, arr, ans);
        return ans;
    }
};
