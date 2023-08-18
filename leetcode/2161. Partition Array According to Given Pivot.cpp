class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessers, greaters, equals;
        int idx = 0, left = 0, right = 0, mid = 0;
        for (int val: nums) {
            if (val < pivot) lessers.push_back(val);
            else if (val > pivot) greaters.push_back(val);
            else equals.push_back(val);
        }
        while (idx < nums.size()) {
            if (left < lessers.size()) nums[idx++] = lessers[left++];
            else if (mid < equals.size()) nums[idx++] = equals[mid++];
            else nums[idx++] = greaters[right++];
        }
        return nums;
    }
};
