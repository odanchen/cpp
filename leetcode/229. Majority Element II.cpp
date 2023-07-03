class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1, n2, cnt1 = -1, cnt2 = -1;
        for (int val : nums) {
            if (cnt1 <= 0 and (cnt2 <= 0 or val != n2)) {
                cnt1 = 1;
                n1 = val;
            }
            else if (val == n1) cnt1++;
            else if (cnt2 <= 0) {
                cnt2 = 1;
                n2 = val;
            }
            else if (val == n2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0;
        cnt2 = cnt2 <= 0 ? -1 : 0;
        for (int val : nums) {
            if (val == n1) cnt1++;
            if (val == n2 and cnt2 != -1) cnt2++;
        }
        if (cnt1 > nums.size() / 3) ans.push_back(n1);
        if (cnt2 > (int)nums.size() / 3) ans.push_back(n2);
        return ans;
    }
};
