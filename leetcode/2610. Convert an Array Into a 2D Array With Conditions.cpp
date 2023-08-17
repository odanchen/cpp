class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &nums) {
        vector<int> count(nums.size() + 1);
        vector<vector<int>> ans;
        int valCnt = 0;
        for (int val: nums) count[val]++, valCnt++;
        while (valCnt != 0) {
            vector<int> cur;
            for (int i = 0; i < count.size(); i++) {
                if (count[i] > 0) {
                    cur.push_back(i);
                    count[i]--;
                    valCnt--;
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
