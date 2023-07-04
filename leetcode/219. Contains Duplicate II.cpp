class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(nums[i]) != numMap.end()) {
                if (i - numMap[nums[i]] <= k) return true;
                numMap[nums[i]] = i;
            } else numMap.insert({nums[i], i});
        }
        return false;
    }
};
