    void addCombination(int n, int k, vector<int> arr, vector<vector<int>> &ans, int depth)
    {
        if (depth == k) 
        {
            ans.push_back(arr);
            return;
        }

        int back;
        if (depth == 0) back = 0;
        else back = arr[depth - 1];
        depth++;

        for(int i = back + 1; i <= n; i++)
        {
            arr[depth - 1] = i;
            addCombination(n, k, arr, ans, depth);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr(k);
        addCombination(n, k, arr, ans, 0);
        return ans;
    }
