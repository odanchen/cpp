class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        unsigned mask = n;
        while (mask & (mask - 1)) mask &= (mask - 1);
        return ((mask << 1) - 1) ^ n;
    }
};
