class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        bool isNegative = num < 0;
        num = abs(num);
        string ans;
        vector<char> digitMap = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        while (num > 0) {
            ans.push_back(digitMap[num % 16]);
            num /= 16;
        }
        if (isNegative) while (ans.size() < 8) ans.push_back('0');
        reverse(ans.begin(), ans.end());
        if (isNegative) {
            for (char &c: ans) c = digitMap[15 - (isdigit(c) ? c - '0' : c - 'a' + 10)];
            size_t idx = ans.size() - 1;
            while (ans[idx] == 'f') ans[idx--] = '0';
            ans[idx] = digitMap[(isdigit(ans[idx]) ? ans[idx] - '0' : ans[idx] - 'a' + 10) + 1];
        }
        return ans;
    }
};  
