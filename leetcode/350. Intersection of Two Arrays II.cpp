class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> map;
        for (int element : nums1) map[element]++;
        for (int element : nums2)
        {
            if (map[element] > 0) ans.push_back(element);
            map[element]--;
        }
        return ans;
    }
};
