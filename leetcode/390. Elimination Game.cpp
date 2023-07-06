class Solution {
public:
    int lastRemaining(int n) {
        bool turn = true;
        int ans = 1, diff = 1;
        while (n > 1) {
            if (turn or n & 1) ans += diff;
            diff *= 2;
            n/= 2;
            turn = !turn;
        }
        return ans;
    }
};
