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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> nodeQueue({root});
        int toProcess = 1, nextTurn = 0;
        while(!nodeQueue.empty()) {
            double sum = 0;
            for (int i = 0; i < toProcess; i++) {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();

                sum += cur->val;
                if (cur->left != NULL) {
                    nodeQueue.push(cur->left);
                    nextTurn++;
                }
                if (cur->right != NULL) {
                    nodeQueue.push(cur->right);
                    nextTurn++;
                }
            }
            ans.push_back(sum / toProcess);
            toProcess = nextTurn;
            nextTurn = 0;
        }
        return ans;
    }
};
