class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char digit : n) {
            ans = max(ans, digit - '0');
            if (ans == 9) return 9;
        }
        return ans;
    }
};
