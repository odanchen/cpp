class Solution {
public:
    bool isWord(string &word, unordered_set<char> &letters) {
        for (char c: word) if (letters.find(tolower(c)) == letters.end()) return false;
        return true;
    }

    vector<string> findWords(vector<string> &words) {
        unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<string> ans;
        for (string &word: words) {
            unordered_set<char> *letters;
            if (row1.find(tolower(word.front())) != row1.end()) letters = &row1;
            else letters = &(row2.find(tolower(word.front())) != row2.end() ? row2 : row3);
            if (isWord(word, *letters)) ans.push_back(word);
        }
        return ans;
    }
};
