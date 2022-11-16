    void processNode(Node *root)
    {
        if (root->left == NULL) return;

        Node *leftRoot = root->left, *rightRoot = root->right;
        while(leftRoot != NULL)
        {
            leftRoot->next = rightRoot;
            leftRoot = leftRoot->right;
            rightRoot = rightRoot->left;
        }
    }
    void dfs(Node *root)
    {
        if (root == NULL) return;

        processNode(root);
        dfs(root->left);
        dfs(root->right);
    }
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
