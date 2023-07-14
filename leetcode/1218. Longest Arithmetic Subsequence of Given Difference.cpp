class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> lengths;
        int ans = 1;
        for (int val : arr) {
            if (lengths.find(val) == lengths.end()) lengths[val + difference] = 1;
            else {
                ans = max(ans, lengths[val] + 1);
                lengths[val + difference] = max(lengths[val] + 1, 
                    lengths.find(val + difference) == lengths.end() ? 0 : lengths[val + difference]);
            }
        }
        return ans;
    }
};
