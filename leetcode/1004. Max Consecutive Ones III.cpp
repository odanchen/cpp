class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int left = 0, right = 0, zeros = 0;
        while (right < nums.size()) {
            if (zeros < k or (zeros == k and nums[right] == 1)) {
                if (nums[right++] == 0) zeros++;
            } else {
                if (nums[left++] == 0) zeros--;
                if (nums[right++] == 0) zeros++;
            }
        }
        return right - left;
    }
};
