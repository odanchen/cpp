class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        vector<bool> ans(l.size());
        for (int i = 0; i < l.size(); i++) {
            vector<int> temp(r[i] - l[i] + 1);
            for (int j = l[i]; j <= r[i]; j++) temp[j - l[i]] = nums[j];
            sort(temp.begin(), temp.end());
            if (temp.size() > 1) {
                ans[i] = true;
                int diff = temp[1] - temp[0];
                for (int j = 1; j < temp.size(); j++)
                    if (temp[j] - temp[j - 1] != diff) {
                        ans[i] = false;
                        break;
                    }
            }
        }
        return ans;
    }
};
