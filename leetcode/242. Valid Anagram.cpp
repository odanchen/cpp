class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26);
        for (char letter : s) hash[letter - 'a']++;
        for (char letter : t) hash[letter - 'a']--;

        for (int element : hash) if (element != 0) return false;
        return true;
    }
};
