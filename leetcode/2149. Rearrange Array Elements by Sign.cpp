class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> ans(nums.size());
        auto itNeg = find_if(nums.begin(), nums.end(), [](int n) { return n < 0; });
        auto itPos = find_if(nums.begin(), nums.end(), [](int n) { return n > 0; });
        auto it = ans.begin();
        while (it != ans.end()) {
            *(it++) = *(itPos++);
            *(it++) = *(itNeg++);
            while (itPos != nums.end() and *itPos < 0) itPos++;
            while (itNeg != nums.end() and *itNeg > 0) itNeg++;
        }
        return ans;
    }
};
