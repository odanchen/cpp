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
class Solution {
public:
    void addBranch(TreeNode* root, string cur, vector<string> &ans) {
        if (root == NULL) return;
        if (!cur.empty()) cur.append("->");
        cur.append(to_string(root->val));
        if (root->left == NULL and root->right == NULL) ans.push_back(cur);
        else {
            addBranch(root->left, cur, ans);
            addBranch(root->right, cur, ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        addBranch(root, "", ans);
        return ans;
    }
};
