class Solution {
public:
    bool less(int idx1, int idx2, vector<int> &arr) {
        if (idx2 < 0 or idx2 >= arr.size()) return true;
        return arr[idx2] < arr[idx1];
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int mid = (left + right) / 2;
        while (less(mid, mid - 1, arr) ^ less(mid, mid + 1, arr)) {
            if (less(mid, mid - 1, arr)) left = mid;
            else right = mid;
            mid = (left + right) / 2;
        }
        return mid;
    }
};
