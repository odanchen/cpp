class Solution {
public:
    typedef vector<string> vString;
    typedef string::iterator sIter;
    void fillMap(map<char, vector<char>> &letterMap) {
        letterMap.insert(pair<char, vector<char>>('2', vector<char>{'a', 'b', 'c'}));
        letterMap.insert(pair<char, vector<char>>('3', vector<char>{'d', 'e', 'f'}));
        letterMap.insert(pair<char, vector<char>>('4', vector<char>{'g', 'h', 'i'}));
        letterMap.insert(pair<char, vector<char>>('5', vector<char>{'j', 'k', 'l'}));
        letterMap.insert(pair<char, vector<char>>('6', vector<char>{'m', 'n', 'o'}));
        letterMap.insert(pair<char, vector<char>>('7', vector<char>{'p', 'q', 'r', 's'}));
        letterMap.insert(pair<char, vector<char>>('8', vector<char>{'t', 'u', 'v'}));
        letterMap.insert(pair<char, vector<char>>('9', vector<char>{'w', 'x', 'y', 'z'}));
    }
    void generateCombinations(sIter it, vString &ans, string &digits, string cur, map<char, vector<char>> &letterMap) {
        if (it == digits.end()) {
            ans.push_back(cur);
            return;
        }

        for (char letter : letterMap.at(*it)) {
            generateCombinations(it + 1, ans, digits, cur + letter, letterMap);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();

        map<char, vector<char>> letterMap;
        fillMap(letterMap);
        vector<string> ans;
        generateCombinations(digits.begin(), ans, digits, "", letterMap);
        return ans;
    }
};
