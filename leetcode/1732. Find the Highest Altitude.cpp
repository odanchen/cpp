class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, ans = 0;
        for (int val : gain) ans = max(ans, cur += val);
        return ans;
    }
};
