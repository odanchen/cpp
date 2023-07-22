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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> toProcess({root});
        while(!toProcess.empty()) {
            int currentTurn = toProcess.size();
            bool found = false;
            for (int i = 0; i < currentTurn; i++) {
                auto cur = toProcess.front();
                toProcess.pop();
                if (cur->left and cur->right and ((cur->left->val == x and cur->right->val == y) or 
                    (cur->left->val == y and cur->right->val == x))) return false;
                if (cur->val == x or cur->val == y) {
                    if (found) return true;
                    else found = true;
                }
                if (cur->left) toProcess.push(cur->left);
                if (cur->right) toProcess.push(cur->right);
            }
            if (found) return false;
        }
        return false;
    }
};
