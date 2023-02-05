class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, rec(26), found(26);
        if (s.size() < p.size()) return vector<int>();
        for (char letter : p) rec[letter - 'a']++;
        for (int i = 0; i < p.size(); i++) found[s[i] - 'a']++;
        if (rec == found) ans.push_back(0);
        for (int i = 1; i < s.size() - p.size() + 1; i++) {
            found[s[i - 1] - 'a']--;
            found[s[i + p.size() - 1] - 'a']++;
            if (rec == found) ans.push_back(i);
        }
        return ans;
    }
};
