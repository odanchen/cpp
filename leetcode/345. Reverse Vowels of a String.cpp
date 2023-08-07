class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels({'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'});
        size_t left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right and vowels.find(s[left]) == vowels.end()) left++;
            while (left < right and vowels.find(s[right]) == vowels.end()) right--;
            if (left < right) swap(s[left++], s[right--]);
        }
        return s;
    }
};
