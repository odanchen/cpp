class Solution {
public:
    void addPermutation(int &level, vector<vector<int>> &ans, vector<int> arr)
    {
        if (level == arr.size() - 1)
        {
            ans.push_back(arr);
            return;
        }

        for(int i = level; i < arr.size(); i++)
        {
            swap(arr[level], arr[i]);
            level++;
            addPermutation(level, ans, arr);
            level--;
            swap(arr[level], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int level = 0;
        addPermutation(level, ans, nums);
        return ans;
    }
};
