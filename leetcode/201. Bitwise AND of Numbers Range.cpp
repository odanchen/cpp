class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        unsigned mask = UINT_MAX;
        while ((left & mask) != (right & mask)) mask = mask << 1;
        return left & mask;
    }
};
