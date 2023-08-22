class Solution {
public:
    string finalString(string s) {
        string ans;
        ans.reserve(s.size());
        for (char c: s) {
            if (c == 'i') reverse(ans.begin(), ans.end());
            else ans.push_back(c);
        }
        return ans;
    }
};
