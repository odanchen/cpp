class Solution {
public:
    bool hasAlternatingBits(int n) {
        return ((n ^ (n >> 1)) & ((unsigned)(n ^ (n >> 1)) + 1)) == 0;
    }
};
