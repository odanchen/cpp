class Solution {
public:
    int getLowestOperation(string &s, int left, int right) {
        int brace = 0, begin = left;
        while(left <= right) {
            if (s[left] == '(') brace++;
            else if (s[left] == ')') brace--;
            else if (left != begin and (s[left] == '+' or s[left] == '-') and brace == 0) return left;
            left++;
        }
        return s[begin] == '-' ? begin : -1;
    }
    bool isNum(string &s, int left, int right) {
        while (left <= right) if (s[left] == '+' or s[left++] == '-') return false;
        return true;
    }
    int toNum(string &s, int left, int right) {
        int len = 0;
        while (!isdigit(s[left])) left++;
        for (int i = left; i <= right and isdigit(s[i]); i++) len++;
        return stoi(s.substr(left, len));
    }
    int evaluate(string &s, int left, int right) {
        int operation;
        if (isNum(s, left, right)) return toNum(s, left, right);
        while ((operation = getLowestOperation(s, left, right)) == -1) {
            left++;
            right--;
        }
        
        if (operation == left) return 0 - evaluate(s, left + 1, right);
        return evaluate(s, left, operation - 1) + evaluate(s, operation + (s[operation] == '+' ? 1 : 0), right);
    }
    int calculate(string s) {
        string ans;
        for (char c : s) if (c != ' ') ans.push_back(c);
        return evaluate(ans, 0, ans.size() - 1);
    }
};
