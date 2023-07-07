class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        for (int row = 0; row < rowIndex; row++) {
            ans.push_back(1);
            for (int i = ans.size() - 2; i > 0; i--) ans[i] += ans[i - 1];
        }
        return ans;
    }
};
