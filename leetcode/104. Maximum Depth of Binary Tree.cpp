    void traverse(TreeNode* root, int curDepth, int &max_depth)
    {
        if(root == nullptr) return;

        max_depth = max(curDepth, max_depth);
        traverse(root->left, curDepth + 1, max_depth);
        traverse(root->right, curDepth + 1, max_depth);
    }
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        traverse(root, 1, max_depth);
        return max_depth;
    }
