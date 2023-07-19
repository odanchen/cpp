class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (left == right - 1) return nums[left] > nums[right] ? left : right;

            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]) return mid;
            if (nums[mid] > nums[mid - 1]) left = mid;
            else right = mid;
        }
        return left;
    }
};
