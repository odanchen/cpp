class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0, idx = 0;
        while (cnt < k) if (++idx == s.size() or s[idx] == ' ') cnt++;
        return s.substr(0, idx);
    }
};
