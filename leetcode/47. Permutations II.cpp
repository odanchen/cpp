class Solution {
public:
    void addPermutation(int &level, set<vector<int>> &ans, vector<int> arr)
    {
        if (level == arr.size() - 1)
        {
            ans.insert(arr);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> unique;
        int level = 0;
        addPermutation(level, unique, nums);
        for (vector<int> element : unique) ans.push_back(element);
        return ans;
    }   
};
