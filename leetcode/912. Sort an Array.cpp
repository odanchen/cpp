class Solution {
public:
    vector<int> merge(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int aPtr = 0, bPtr = 0;
        while(aPtr < a.size() or bPtr < b.size()) {
            if (aPtr < a.size() and (bPtr >= b.size() or a[aPtr] < b[bPtr])) ans.push_back(a[aPtr++]);
            else ans.push_back(b[bPtr++]);
        }
        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() == 1) return nums;
        vector<int> left(nums.begin(), nums.begin() + nums.size() / 2);
        vector<int> right(nums.begin() + nums.size() / 2, nums.end());
        return merge(left = sortArray(left), right = sortArray(right));
    }
};
