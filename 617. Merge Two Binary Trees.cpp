    void merge(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr && root2 == nullptr) return;
        if (root1->left == nullptr && root2->left != nullptr) root1->left = new TreeNode(); 
        if (root1->right == nullptr && root2->right != nullptr) root1->right = new TreeNode(); 
        if (root2->left == nullptr && root1->left != nullptr) root2->left = new TreeNode(); 
        if (root2->right == nullptr && root1->right != nullptr) root2->right = new TreeNode(); 

        root1->val += root2->val;
        merge(root1->left, root2->left);
        merge(root1->right, root2->right);
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return nullptr;
        if (root1 == nullptr) root1 = new TreeNode();
        if (root2 == nullptr) root2 = new TreeNode();
        merge(root1, root2);
        return root1;
    }
