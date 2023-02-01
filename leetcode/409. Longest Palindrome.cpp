class Solution {
public:
    int longestPalindrome(string s) {
        set<char> letters;
        int ans = 0;
        for (char letter : s) {
            if (letters.find(letter) == letters.end()) letters.insert(letter);
            else {
                letters.erase(letters.find(letter));
                ans += 2;
            }
        }
        return (letters.empty()) ? ans : ans + 1;
    }
};
