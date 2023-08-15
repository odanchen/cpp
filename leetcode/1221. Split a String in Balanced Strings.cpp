class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, ans = 0;
        for (char c: s) {
            cnt += c == 'L' ? 1 : -1;
            if (cnt == 0) ans++;
        }
        return ans;
    }
};
