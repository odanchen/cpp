class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 or n == 2) return 1;

        int oneBack = 1, twoBack = 1, threeBack = 0; 
        int cur = 2;
        for (int i = 4; i <= n; i++) {
            threeBack = twoBack;
            twoBack = oneBack;
            oneBack = cur;
            cur = oneBack + twoBack + threeBack;
        }
        return cur;
    }
};
