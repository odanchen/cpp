class Solution {
public:
    static bool isPalindrome(string &s) {
        for (int i = 0; i < s.size() / 2; i++) if (s[i] != s[s.size() - i - 1]) return false;
        return true;
    }

    string firstPalindrome(vector<string> &words) {
        auto temp = find_if(words.begin(), words.end(), isPalindrome);
        return temp == words.end() ? "" : *temp;
    }
};
