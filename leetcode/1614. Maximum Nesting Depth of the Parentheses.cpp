class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, ans = 0;
        for (char c: s) {
            if (c == '(') ans = max(ans, ++cnt);
            else if (c == ')') cnt--;
        }
        return ans;
    }
};
