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
    TreeNode* construct(int &idx, vector<int>& preorder, vector<int> &inorder, unordered_map<int, int> &inMap) {
        if (idx == preorder.size() or inMap.find(preorder[idx]) == inMap.end()) return NULL;
        int inIdx = inMap[preorder[idx]];
        TreeNode* root = new TreeNode(preorder[idx]);
        inMap.erase(inMap.find(preorder[idx++]));
            
        if (idx < preorder.size() and inMap[preorder[idx]] < inIdx) {
            root->left = construct(idx, preorder, inorder, inMap);
        }
        if (inIdx == preorder.size() - 1 or inMap.find(inorder[inIdx + 1]) == inMap.end()) return root;
        root->right = construct(idx, preorder, inorder, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int idx = 0;
        for (int i = 0; i < inorder.size(); i++i) inMap[inorder[i]] = i;
        return construct(idx, preorder, inorder, inMap);
    }
};
