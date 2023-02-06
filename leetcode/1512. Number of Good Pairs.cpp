class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> visited;
        int ans = 0;
        for (int val : nums) {
            if (visited.find(val) == visited.end()) visited.insert(pair<int, int>(val, 1));
            else {
                ans += visited.at(val);
                visited.at(val)++;
            }
        }
        return ans;
    }
};
