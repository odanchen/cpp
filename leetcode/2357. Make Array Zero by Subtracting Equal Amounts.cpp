class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> visited(101);
        visited[0] = 1;
        int cnt = 0;
        for (int val : nums) {
            cnt += !visited[val];
            visited[val] = true;
        }
        return cnt;
    }
};
