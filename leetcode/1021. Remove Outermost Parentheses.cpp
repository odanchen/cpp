class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<pair<int, int>> temp;
        string ans;
        int left = 0, right = 0, cnt = 0;
        while (right < s.size()) {
            cnt += s[right++] == '(' ? 1 : -1;
            if (cnt == 0) {
                temp.emplace_back(left, right - 1);
                left = right;
            }
        }
        for (auto &[l, r]: temp) {
            for (int i = l + 1; i < r; i++) ans.push_back(s[i]);
        }
        return ans;
    }
};
