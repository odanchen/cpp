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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) return root;
        if (root->left == nullptr and root->right == nullptr and root->val == key) return nullptr;
        auto node = root, prev = root, temp = root;
        while (node->val != key) {
            prev = node;
            if (key > node->val) node = node->right;
            else node = node->left;
            if (node == nullptr) return root;
        }
        temp = node->left;
        if (node == root) {
            root = node = root->right;
            if (node == nullptr) return temp;
        } else {
            if (node == prev->left) {
                prev->left = node->right;
                node = prev;
            } else {
                prev->right = node->right;
                node = node->right;
                if (prev->right == nullptr) {
                    prev->right = temp;
                    return root;
                }
            }
        }
        while (node->left != nullptr) node = node->left;
        node->left = temp;
        return root;
    }
};
