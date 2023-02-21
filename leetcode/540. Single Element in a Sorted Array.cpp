class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right) {
            mid = (left + right) / 2;
            if (mid == 0 or mid == nums.size() - 1) return nums[mid];

            if (nums[mid - 1] != nums[mid] and nums[mid + 1] != nums[mid]) return nums[mid];
            mid = (nums[mid - 1] == nums[mid]) ? mid - 1 : mid;
            if (mid & 1) right = mid - 1;
            else left = mid + 2;
        }
        return nums[left];
    }
};
