class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int element : nums) ans = ans ^ element;
        return ans;
    }
};
