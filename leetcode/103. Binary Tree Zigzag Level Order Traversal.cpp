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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        vector<vector<int>> ans;
        bool left = false;
        int nextTurn = 0, toProcess = 1;
        stack<TreeNode*> leftStack;
        stack<TreeNode*> rightStack;
        
        rightStack.push(root);
        while(!leftStack.empty() or !rightStack.empty()) {
            ans.push_back(vector<int>());
            for (int i = 0; i < toProcess; i++) {
                TreeNode* cur;
                if (!left) {
                    cur = rightStack.top();
                    rightStack.pop();
                    if (cur->left != NULL) {leftStack.push(cur->left); nextTurn++;}
                    if (cur->right != NULL) {leftStack.push(cur->right); nextTurn++;}
                } else {
                    cur = leftStack.top();
                    leftStack.pop();
                    if (cur->right != NULL) {rightStack.push(cur->right); nextTurn++;}
                    if (cur->left != NULL) {rightStack.push(cur->left); nextTurn++;}
                }
                ans.back().push_back(cur->val);
            }
            toProcess = nextTurn;
            left = !left;
            nextTurn = 0;
        }
        return ans;
    }
};
