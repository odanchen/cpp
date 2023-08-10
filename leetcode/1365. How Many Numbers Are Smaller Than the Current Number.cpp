class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<pair<int, int>> numsCopy(nums.size());
        for (int i = 0; i < nums.size(); i++) numsCopy[i] = {nums[i], i};
        sort(numsCopy.begin(), numsCopy.end());
        int idx = 0, cnt = 0;
        while (idx < nums.size()) {
            nums[numsCopy[idx].second] = cnt;
            if (idx != nums.size() - 1 and numsCopy[idx].first != numsCopy[idx + 1].first) cnt = idx + 1;
            idx++;
        }
        return nums;
    }
};
