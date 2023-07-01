class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(n > 0 or m > 0) {
            if (n == 0 or (m > 0 and (nums1[m - 1] > nums2[n - 1]))) nums1[n + m] = nums1[--m];
            else nums1[n + m] = nums2[--n];
        }
    }
};
