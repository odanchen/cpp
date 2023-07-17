class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> tLetters(128), sLetters(128);
        int tMatch = 0, sMatch = 0, left = 0, right = 0, ansLeft = -1, ansRight = -1;
        for (char val : t) if (++tLetters[val] == 1) tMatch++;
        
        while (right < s.size()) {
            if (++sLetters[s[right]] == tLetters[s[right]] and tLetters[s[right]] > 0) sMatch++;
            right++;
            while(tMatch == sMatch) {
                if (right - left < ansRight - ansLeft or ansLeft == -1) {
                    ansLeft = left;
                    ansRight = right;
                }
                if (sLetters[s[left]] == tLetters[s[left]] and tLetters[s[left]] > 0) sMatch--;
                sLetters[s[left++]]--;
            }
        }
        return ansLeft == -1 ? "" : s.substr(ansLeft, ansRight - ansLeft);
    }
};
