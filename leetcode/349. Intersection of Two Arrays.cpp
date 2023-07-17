class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> numSet(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int num : nums2) {
            if (numSet.find(num) != numSet.end()) {
                ans.push_back(num);
                numSet.erase(num);
            }
        }
        return ans;
    }
};
