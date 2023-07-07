class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++){
            if (hashMap.find(nums[i]) != hashMap.end()) return {hashMap[nums[i]], i};
            else hashMap.insert({target - nums[i], i});
        }

        return nums;
    }
};
