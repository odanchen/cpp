class Solution {
public:
int countConsistentStrings(string allowed, vector<string> &words) {
    vector<bool> letters(26);
    for (char c: allowed) letters[c - 'a'] = true;
    return count_if(words.begin(), words.end(),
                    [&](string &s) { 
                        return all_of(s.begin(), s.end(), [&](char c) { return letters[c - 'a']; }); 
                        });
    }
};
