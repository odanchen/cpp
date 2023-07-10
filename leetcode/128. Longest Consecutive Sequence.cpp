class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> intMap;
        int ans = 0;
        for (int val : nums) {
            if (intMap.find(val) == intMap.end()) {
                int left = intMap.find(val - 1) == intMap.end() ? 0 : intMap[val - 1];
                int right = intMap.find(val + 1) == intMap.end() ? 0 : intMap[val + 1];
                int sum = left + right + 1;
                ans = max(ans, sum);
                intMap[val - left] = sum;
                intMap[val + right] = sum; 
                intMap[val] = sum;
            }
        }
        return ans;
    }
};
