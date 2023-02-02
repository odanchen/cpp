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
    void process(TreeNode *node, vector<int> &level, queue<TreeNode*> &nQueue, int &nextTurn) {
        level.push_back(node->val);
        if (node->left != NULL) {
            nQueue.push(node->left); nextTurn++;
        }
        if (node->right != NULL) {
            nQueue.push(node->right); nextTurn++;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<int> level;
        queue<TreeNode*> nQueue;
        int toProcess = 1, nextTurn = 0;
        nQueue.push(root);
        while(!nQueue.empty()) {
            for (int i = 0; i < toProcess; i++) {
                TreeNode* node = nQueue.front();
                nQueue.pop();
                process(node, level, nQueue, nextTurn);
            }
            ans.push_back(level);
            level = vector<int>();
            toProcess = nextTurn;
            nextTurn = 0;
        }
        return ans;
    }
};
