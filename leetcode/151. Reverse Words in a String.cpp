class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        for (auto left = s.begin(); left != s.end() + 1; left++) {
            int cnt = 0;
            while (left != s.end() and *left == ' ') {
                left++;
                cnt++;
            }
            auto right = left;
            while (right != s.end() and (isalpha(*right) or isdigit(*right))) right++;
            reverse(left, right);
            while(left != right and cnt > 0) {
                swap(*left, *(left - cnt));
                left++;
            }
            left = right - cnt;
        }
        while(!(isalpha(s.back()) or isdigit(s.back()))) s.pop_back();
        return s;
    }
};
