class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashMap.find(nums[i]) != hashMap.end())
            {
                vector<int> ans = {hashMap[nums[i]], i};
                return ans;
            }
            else
            {
                hashMap.insert({target - nums[i], i});
            }
        }

        return nums;
    }
};
