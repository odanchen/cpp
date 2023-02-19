class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (vector<int> &line : grid) {
           int left = 0, right = line.size(), mid;
           while(left < right) {
               mid = (left + right) / 2;
               if (line[mid] >= 0) left = mid + 1;
               else right = mid;
           }
           ans += line.size() - right;
        }
        return ans; 
    }
};
