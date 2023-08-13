class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() < nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = nums2.size() * 2;
        while (left <= right) {
            int mid2 = (left + right) / 2, mid1 = nums1.size() + nums2.size() - mid2;

            int left1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
            int left2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            int right1 = (mid1 == nums1.size() * 2) ? INT_MAX : nums1[(mid1) / 2];
            int right2 = (mid2 == nums2.size() * 2) ? INT_MAX : nums2[(mid2) / 2];

            if (left1 > right2) left = mid2 + 1;
            else if (left2 > right1) right = mid2 - 1;
            else return (max(left1, left2) + min(right1, right2)) / 2.0;
        }

        return 0;
    }
};
