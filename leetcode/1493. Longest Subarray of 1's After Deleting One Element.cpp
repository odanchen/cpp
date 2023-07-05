class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len1 = 0, len2 = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (i < nums.size() and nums[i] == 0) i++;
            if (len1 == 0) while (i < nums.size() and nums[i++] == 1) len1++;
            else while (i < nums.size() and nums[i++] == 1) len2++;
            i--;
            ans = max (ans, len1 + len2);
            if (i >= nums.size() - 1 or nums[i + 1] == 0) len1 = len2 = 0;
            else if (len2 != 0) swap(len1 = 0, len2);
        }
        return ans == nums.size() ? ans - 1 : ans;
    }
};
