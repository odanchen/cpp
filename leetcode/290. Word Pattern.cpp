class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> relation;
        set<string> occupiedWords;
        vector<string> wordList;
        for (int left = 0; left < s.size(); left++) {
            int right = left + 1;
            while (right < s.size() && s[right] != ' ') right++;

            wordList.push_back(s.substr(left, right - left));
            left = right;
        }

        if (pattern.size() != wordList.size()) return false;
        for (int i = 0; i < pattern.size(); i++) {
            if (relation.find(pattern[i]) == relation.end()) 
            {
                if (occupiedWords.find(wordList[i]) != occupiedWords.end()) return false;
                relation.insert(pair<char, string>(pattern[i], wordList[i]));
                occupiedWords.insert(wordList[i]);
            }
            else if (relation.at(pattern[i]) != wordList[i]) return false;
        }
        return true;
    }
};
