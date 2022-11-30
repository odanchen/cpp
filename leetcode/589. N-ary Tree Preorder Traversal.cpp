    void traverse(Node *root, vector<int> &ans)
    {
        if (root == NULL) return;

        ans.push_back(root->val);
        for (Node* child : root->children) traverse(child, ans);
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }