class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> letterMap;
        char currentChar = 'a';
        for (char c: key) if (c != ' ' and letterMap.find(c) == letterMap.end()) letterMap[c] = currentChar++;
        for (char &c: message) if (c != ' ') c = letterMap[c];
        return message;
    }
};
