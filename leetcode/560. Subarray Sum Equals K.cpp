class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> preFix(nums.size() + 1);
        int ans = 0;
        unordered_map<int, int> intMap = {{0, 1}};
        for (int i = 1; i < preFix.size(); i++) {
            preFix[i] = preFix[i - 1] + nums[i - 1];
            int diff = preFix[i] - k;
            if (intMap.find(diff) != intMap.end()) ans += intMap[diff];
            intMap[preFix[i]]++;
        }
        return ans;
    }
};
