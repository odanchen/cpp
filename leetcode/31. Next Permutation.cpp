class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int curMax = nums.back();
        bool isFound = false;
        for (int it = nums.size() - 2; it >= 0 and !isFound; it--) {
            if (nums[it] >= curMax) curMax = nums[it];
            else {
                int rightSwap = it + 1;
                for (int right = it + 1; right < nums.size(); right++) {
                    if (nums[right] < nums[rightSwap] and nums[right] > nums[it]) rightSwap = right;
                }
                swap(nums[it], nums[rightSwap]);
                sort(nums.begin() + it + 1, nums.end());
                isFound = true;
            }
        }
        if (!isFound) sort(nums.begin(), nums.end());
    }
};
