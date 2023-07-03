class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        vector<int> hash(26), hash2(26);
        int err1 = -1, err2 = -1;
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
            hash2[goal[i] - 'a']++;
            if (goal[i] != s[i]) {
                if (err1 == -1) err1 = i;
                else if (err2 == -1) err2 = i;
                else return false;
            }
        }
        if (err1 != -1 and err2 == -1) return false;
        if (err1 != -1 and err2 != -1) return s[err1] == goal[err2] and s[err2] == goal[err1];
        return *max_element(hash.begin(), hash.end()) > 1;
    }
};
