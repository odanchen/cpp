class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ans(s.size(), '0');
        int idx = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.size(); j += (i == 0) ? (numRows - 1) * 2 : i * 2) {
                ans[idx++] = s[j];
                j += numRows - 1 - i == 0 ? (numRows - 1) * 2 : (numRows - 1 - i) * 2;
                if (j < s.size()) ans[idx++] = s[j];
            }
        }
        return ans;
    }
};
