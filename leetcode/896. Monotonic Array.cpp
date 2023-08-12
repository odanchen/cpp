class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isGrowing = true, isFalling = true;
        for (int i = 1; i < nums.size(); i++) {
            isGrowing &= nums[i] >= nums[i - 1];
            isFalling &= nums[i] <= nums[i - 1];
        }
        return isGrowing or isFalling;
    }
};
