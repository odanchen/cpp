class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool ans = true;
        for (int val : nums) {
            if (val == 0) return 0;
            if (val < 0) ans = !ans;
        }
        return ans ? 1 : -1;
    }
};
