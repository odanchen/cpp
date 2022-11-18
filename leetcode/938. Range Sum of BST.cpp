    void dfs(TreeNode* root, int low, int high, int &sum)
    {
        if (root == NULL) return;

        if (root->val >= low && root->val <= high) sum += root->val;
        dfs(root->left, low, high, sum);
        dfs(root->right, low, high, sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        dfs(root, low, high, sum);
        return sum;
    }
