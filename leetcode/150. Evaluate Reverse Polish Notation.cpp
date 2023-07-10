class Solution {
public:
    bool isOperation(string &s) {
        return s.size() == 1 and (s[0] == '*' or s[0] == '/' or s[0] == '+' or s[0] == '-');
    }
    void performOperation(stack<int> &nums, char token) {
        int n2 = nums.top(); nums.pop();
        int n1 = nums.top(); nums.pop();
        switch(token) {
            case '-': nums.push(n1 - n2); break;
            case '+': nums.push(n1 + n2); break;
            case '/': nums.push(n1 / n2); break;
            default : nums.push(n1 * n2); break;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string &token : tokens) {
            if (!isOperation(token)) nums.push(stoi(token));
            else performOperation(nums, token.front());
        }
        return nums.top();
    }
};
