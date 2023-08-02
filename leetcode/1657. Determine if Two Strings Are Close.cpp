class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> hash1(26), hash2(26);
        int place1 = 0, place2 = 0;
        for (char c: word1) if (hash1[c - 'a']++ == 0) place1++;
        for (char c: word2) if (hash2[c - 'a']++ == 0) place2++;
        unordered_map<int, int> unused1, unused2;
        for (int i = 0; i < hash1.size(); i++) {
            if (hash1[i] == 0 or hash2[i] == 0) {
                if (hash1[i] == 0 ^ hash2[i] == 0) return false;
            } else if (hash1[i] == hash2[i]) place1--, place2--;
            else if (hash1[i] != 0 and hash2[i] != 0) {
                if (unused2[hash1[i]] != 0) unused2[hash1[i]]--, place1--, place2--;
                else unused1[hash1[i]]++;
                if (unused1[hash2[i]] != 0) unused1[hash2[i]]--, place1--, place2--;
                else unused2[hash2[i]]++;
            }
        }
        return place1 == 0 and place2 == 0;
    }
};
