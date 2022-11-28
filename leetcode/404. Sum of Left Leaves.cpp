    bool isLeaf(TreeNode *root)
    {
        return root != nullptr && (root->left == nullptr && root->right == nullptr);
    }
    void sumLeftLeaves(TreeNode *root, int &curSum)
    {
        if (root == nullptr) return;

        if (isLeaf(root->left)) curSum += root->left->val;
        sumLeftLeaves(root->left, curSum);
        sumLeftLeaves(root->right, curSum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int curSum = 0;
        sumLeftLeaves(root, curSum);
        return curSum;
    }
