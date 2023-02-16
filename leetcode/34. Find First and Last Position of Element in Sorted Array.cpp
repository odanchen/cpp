class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        int left = 0, right = nums.size() - 1, mid, ansLeft;
        while(left < right) {
            mid = (left + right) / 2;

            if (left == right - 1) {
                left = (nums[left] == target) ? left : right;
                break;
            }
            else if (nums[mid] < target) left = mid;
            else right = mid;
        }
        if (nums[left] != target) return vector<int>{-1, -1};
        ansLeft = left;
        left = 0;
        right = nums.size() - 1;
        while(left < right) {
            mid = (left + right) / 2;
            if (left == right - 1) {
                right = (nums[right] == target) ? right : left;
                break;
            }
            else if (nums[mid] > target) right = mid;
            else left = mid;
        }
        return vector<int>{ansLeft, right};
    }
};
