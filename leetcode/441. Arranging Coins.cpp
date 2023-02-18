class Solution {
public:
    int arrangeCoins(int n) {
        return (floor(sqrt(1 + n * 8ll)) - 1) / 2;
    }
};
