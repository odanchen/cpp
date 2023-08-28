class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101);
        for (int val: nums) cnt[val]++;
        int ans = 0;
        for (int i = 0; i < cnt.size(); i++) if (cnt[i] == 1) ans += i;
        return ans;
    }
};
