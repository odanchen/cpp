class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = count_if(word.begin(), word.end(), [](char c){return isupper(c);});
        return cnt == 0 or cnt == word.size() or (cnt == 1 and isupper(word.front()));
    }
};
