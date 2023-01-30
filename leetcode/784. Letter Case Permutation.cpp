class Solution {
public:
    void addPermutation(int idx, vector<string> &ans, string s) {
        if (idx == s.size()) {
            ans.push_back(s); return;
        }
        if(isalpha(s[idx])) {
            s[idx] = toupper(s[idx]); addPermutation(idx + 1, ans, s);
            s[idx] = tolower(s[idx]); addPermutation(idx + 1, ans, s);
        }
        else addPermutation(idx + 1, ans, s);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        addPermutation(0, ans, s);
        return ans;
    }
};
