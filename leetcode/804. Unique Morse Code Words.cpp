class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        vector<string> code = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...",
                    "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> uSet;
        for (string& word: words) {
            string coded;
            for (char c: word) coded.append(code[c - 'a']);
            uSet.insert(coded);
        }
        return uSet.size();
    }
};
