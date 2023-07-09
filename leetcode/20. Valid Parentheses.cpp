class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closing = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> brackets;
        for (char val : s) {
            if (closing.find(val) != closing.end()) {
                if (brackets.empty() or closing[val] != brackets.top()) return false;
                else brackets.pop();
            } else brackets.push(val);
        }
        return brackets.empty();
    }
};
