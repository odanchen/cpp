class Solution {
public:
    void updateBestScore(vector<int>::iterator it, vector<int> &nums, int target, int &best) {
        auto left = it + 1;
        auto right = nums.end() - 1;
        while(left != right) {
            if (abs(*left + *right + *it - target) < abs(target - best)) best = *it + *left + *right;
            if (*left + *right + *it == target) {best = target; return;}

            if (*it + *left + *right < target) while(left != right and *it + *left + *right < target) left++;  
            else if (*it + *left + *right > target) while(left != right and *it + *left + *right > target) right--;  
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = nums[0] + nums[1] + nums[2];
        for (auto it = nums.begin(); it != nums.end() - 2; it++) {
            updateBestScore(it, nums, target, best);
            if (best == target) return best;
        }
        return best;
    }
};
