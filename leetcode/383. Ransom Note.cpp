class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int notes[26] = {0};
        int available[26] = {0};
        for (char letter : ransomNote) notes[letter - 'a']++;
        for (char letter : magazine) available[letter - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (notes[i] > available[i]) return false;
        }
        return true;
    }
};
