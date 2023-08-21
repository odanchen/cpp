class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (char c = s[0]; c <= s[3]; c++) {
            for (char d = s[1]; d <= s[4]; d++) ans.push_back(string() + c + d);
        }
        return ans;
    }
};
