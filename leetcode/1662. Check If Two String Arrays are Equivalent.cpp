class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int s1 = 0, s2 = 0, v1 = 0, v2 = 0;
        while ((v1 < word1.size() and s1 < word1[v1].size()) or (v2 < word2.size() and s2 < word2[v2].size())) {
            if (v1 >= word1.size() or v2 >= word2.size()) return false;
            if (word1[v1][s1] != word2[v2][s2]) return false;

            if (++s1 >= word1[v1].size()) s1 = 0, v1++;
            if (++s2 >= word2[v2].size()) s2 = 0, v2++;
        }
        return true;
    }
};
