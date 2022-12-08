class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m + n);
        int idx1 = 0, idx2 = 0, idx = 0;

        while(idx < m + n)
        {
            if (idx1 >= m)
            {
                ans[idx] = nums2[idx2];
                idx++;
                idx2++;
            }
            else if (idx2 >= n)
            {
                ans[idx] = nums1[idx1];
                idx++;
                idx1++;
            }
            else if (nums1[idx1] < nums2[idx2]) 
            {
                ans[idx] = nums1[idx1];
                idx++;
                idx1++;
            }
            else
            {
                ans[idx] = nums2[idx2];
                idx++;
                idx2++;
            }
        }
        nums1 = ans;
    }
};
