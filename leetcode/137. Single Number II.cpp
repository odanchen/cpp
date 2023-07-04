class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int val : nums) {
            once = once ^ val & (~twice);
            twice = twice ^ val & (~once);
        }
        return once;
    }
};
