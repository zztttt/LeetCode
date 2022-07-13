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
    vector<int> offset;
    vector<int> rightSideView(TreeNode* root) {
        int depth = getMaxDepth(root);
        offset = vector<int>(depth, 0);
        dfs(root, 0);
        return offset;
    }
    
    void dfs(TreeNode* root, int level){
        if(root == nullptr)
            return;
        int val = root->val;
        offset[level] = val;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    
    int getMaxDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        return max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
    }
};