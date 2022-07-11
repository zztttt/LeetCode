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
    bool evaluateTree(TreeNode* root) {
        return build(root);
    }
    
    bool build(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int val = root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(val == 0){
                return false;
            }else{
                return true;
            }
        }
        
        if(val == 2){
            return build(root->left) || build(root->right);
        }else{
            return build(root->left) && build(root->right);
        }
    }
};