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
    TreeNode* construct(int &idx, vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> &inMap) {
        if (idx <= 0) return idx == 0 ? new TreeNode(postorder[idx]) : NULL;
        int inIdx = inMap[postorder[idx]];
        inMap.erase(inMap.find(postorder[idx]));
        auto cur = new TreeNode(postorder[idx--]);
        
        if (inIdx < inMap[postorder[idx]]) {
            if (inMap.find(inorder[inIdx + 1]) != inMap.end()) 
                cur->right = construct(idx, postorder, inorder, inMap);
        }
        if (idx < 0) return cur;
        if (inIdx > inMap[postorder[idx]]) {
            if (inMap.find(inorder[inIdx - 1]) != inMap.end()) 
                cur->left = construct(idx, postorder, inorder, inMap);
        }

        return cur;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        int idx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        return construct(idx, postorder, inorder, inMap);
    }
};
