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
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
    
    int dfs(TreeNode* root, int fromParent){
        if(root == nullptr)
            return 0;
        int val = root->val;
        int right = dfs(root->right, fromParent);
        int left = dfs(root->left, right + val + fromParent);
        root->val = val + right + fromParent;
        return left + val + right;
    }
};