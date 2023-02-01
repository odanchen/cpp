class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        int mid;
        while(left < right) {
            mid = (left + right) / 2;
            if (matrix[mid][0] > target) right = mid - 1;
            else if (left == right - 1) {
                if (matrix[right][0] > target) right = left;
                else left = right;
            }
            else left = mid;
        }
        auto ans = lower_bound(matrix[left].begin(), matrix[left].end(), target); 
        if (ans < matrix[left].begin() or ans >= matrix[left].end()) return false;
        return *ans == target;
    }
};
