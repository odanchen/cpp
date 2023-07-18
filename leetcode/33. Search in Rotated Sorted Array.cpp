class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[right] == target) return right;
            if (nums[left] == target) return left;
            if (left == right - 1) return -1;

            if (nums[mid] > nums[right]) {
                if (target > nums[mid] or target < nums[right]) left = mid;
                else right = mid;
            } else {
                if (target > nums[mid] and target < nums[right]) left = mid;
                else right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};
