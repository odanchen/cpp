class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = nums.size() - 1;
        while(idx >= 0 and nums[idx] == val) idx--;
        for (int i = 0; i < idx; i++) {
            if (nums[i] == val) swap(nums[i], nums[idx]);
            while(idx >= 0 and nums[idx] == val) idx--;
        }
        return idx + 1;
    }
};
