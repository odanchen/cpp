class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, maxNum = nums.front(), cnt = 0;
        for (int &val : nums) {
            if (cnt >= 2 and val == maxNum) cnt++;
            else {
                if (val == maxNum) cnt++;
                else {
                    cnt = 1;
                    maxNum = val;
                }
                swap(val, nums[idx++]);
            }
        }
        return idx;
    }
};
