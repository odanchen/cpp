class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> found(26);
        for (char c: s) if (!(found[c - 'a'] = !found[c - 'a'])) return c;
        return '0';
    }
};
