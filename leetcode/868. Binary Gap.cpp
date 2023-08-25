class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, cur = 0;
        while (n) {
            cur = 0;
            while (n and !(n & 1)) n >>= 1;
            if (n == 1 and ans == 0) return 0;
            do n >>= 1, cur++;
            while (n and !(n & 1));
            ans = max(ans, cur);
        }
        return ans;
    }
};
