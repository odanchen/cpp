class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0, div = 5;
        while (div <= n) {
            ans += n / div;
            div *= 5;
        } 
        return ans;
    }
};
