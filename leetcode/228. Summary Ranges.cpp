class Solution {
public:
    string getRange(int a, int b) {
        if (a == b) return to_string(a);
        return to_string(a).append("->").append(to_string(b));
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int left = 0, right;
        while(left < nums.size()) {
            right = left;
            while(right < nums.size() - 1 and nums[right] == nums[right + 1] - 1) right++;
            ans.push_back(getRange(nums[left], nums[right]));
            left = right + 1;
        }
        return ans;
    }
};
