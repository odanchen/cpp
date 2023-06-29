class Solution {
public:
    bool checkSubstr(string &s, int len) {
        for (int i = 0; i < s.size(); i += len) {
            for (int j = 0; j < len; j++) {
                if (s[i + j] != s[j]) return false;
            }
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size() / 2; i++) {
            if (s.size() % i == 0 && checkSubstr(s, i)) return true;
        }
        return false;
    }
};
