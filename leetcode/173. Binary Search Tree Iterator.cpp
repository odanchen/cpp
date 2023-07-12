/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        if (toProcess.empty()) cur = addAll(cur);
        int ans = cur->val;
        toProcess.pop();
        if (cur->right) cur = addAll(cur->right);
        else if (!toProcess.empty()) cur = toProcess.top();
        else cur = NULL;
        return ans;
    }
    
    bool hasNext() {
        return cur != NULL;
    }
private:
    TreeNode* addAll(TreeNode* cur) {
        while (cur->left) {
            toProcess.push(cur);
            cur = cur->left;
        }
        toProcess.push(cur);
        return cur;
    }
    stack<TreeNode*> toProcess;
    TreeNode* cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
