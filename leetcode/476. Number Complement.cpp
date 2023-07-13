class Solution {
public:
    int findComplement(int num) {
        unsigned mask = num;
        while (mask & (mask - 1)) mask &= (mask - 1);
        return ((mask << 1) - 1) ^ num;
    }
};
