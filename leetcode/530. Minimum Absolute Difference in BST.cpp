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
    void bst(TreeNode *root, vector<int> &nodes)
    {
        if (root == NULL) return;

        bst(root->left, nodes);
        nodes.push_back(root->val);
        bst(root->right, nodes);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        bst(root, nodes);

        int diff = abs(nodes[0] - nodes[1]);
        for (int i = 1; i < nodes.size(); i++)
        {
            diff = min(diff, abs(nodes[i - 1] - nodes[i]));
        }

        return diff;
    }
};
