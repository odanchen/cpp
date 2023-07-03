class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0, xorRes = x ^ y;
        while (xorRes) {
            ans += (xorRes & 1);
            xorRes = xorRes >> 1;
        }
        return ans;
    }
};
