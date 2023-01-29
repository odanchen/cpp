class Solution {
public:
    typedef string::iterator sIter;
    map<char, string> letterMap;
    void generateCombinations(sIter it, vector<string> &ans, string &digits, string cur) {
        if (it == digits.end()) {
            ans.push_back(cur);
            return;
        }

        for (char letter : letterMap.at(*it)) {
            generateCombinations(it + 1, ans, digits, cur + letter);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        
        auto insert = [&](char digit, string letters){letterMap.insert(pair<char, string>(digit, letters));};
        insert('2', "abc"); insert('3', "def");
        insert('4', "ghi"); insert('5', "jkl");
        insert('6', "mno"); insert('7', "pqrs");
        insert('8', "tuv"); insert('9', "wxyz");

        vector<string> ans;
        generateCombinations(digits.begin(), ans, digits, "");
        return ans;
    }
};
