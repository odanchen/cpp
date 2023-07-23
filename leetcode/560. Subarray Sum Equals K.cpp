class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, cur = 0;
        unordered_map<int, int> intMap = {{0, 1}};
        for (int val : nums) {
            cur += val;
            int diff = cur - k;
            if (intMap.find(diff) != intMap.end()) ans += intMap[diff];
            intMap[cur]++;
        }
        return ans;
    }
};
