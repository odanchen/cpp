class Solution {
public:
    string sortSentence(string s) {
        string ans;
        vector<string> strs(9);
        int left = 0, right = 0;
        while (right < s.size()) {
            while (!isdigit(s[right])) right++;
            strs[s[right] - '1'] = s.substr(left, right - left);
            right = left = right + 2;
        }
        for (string &val: strs) if (!val.empty()) ans += (val + ' ');
        return ans.substr(0, ans.size() - 1);
    }
};
