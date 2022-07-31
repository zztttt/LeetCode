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
    void flatten(TreeNode* root) {
        adjust(root);
    }
    
    TreeNode* adjust(TreeNode* root){
        if(root == nullptr)
            return nullptr;
        TreeNode *left = adjust(root->left), *right = adjust(root->right);
        if(root->left != nullptr){
            TreeNode* oldRight = root->right;
            root->right = root->left;
            root->left = nullptr;
            left->right = oldRight;
        }
        if(right != nullptr){
            return right;
        }
        if(left != nullptr){
            return left;
        }
        return root;
    }
};