class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, left = 1, right = nums[0];
        while (left < nums.size()) {
            int nextRight = right;

            while (left <= right and left < nums.size()) {
                nextRight = max(nums[left] + left, nextRight);
                left++;
            }
            right = min(nextRight, (int) nums.size());
            ans++;
        }

        return ans;
    }
};
