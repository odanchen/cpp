class Solution {
public:
    void addPermutation(int level, vector<vector<int>> &ans, vector<int> arr)
    {
        if (level == arr.size() - 1) {
            ans.push_back(arr); return;
        }
        for(int i = level; i < arr.size(); i++)
        {
            swap(arr[level], arr[i]);
            addPermutation(level + 1, ans, arr);
            swap(arr[level], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        addPermutation(0, ans, nums);
        return ans;
    }
};
