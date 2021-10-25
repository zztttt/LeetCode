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
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        TreeNode *left = root, *right = root;
        int leftHeight = 0, rightHeight = 0;
        while(left){
            left = left->left;
            leftHeight++;
        }
        while(right){
            right = right->right;
            rightHeight++;
        }
        if(leftHeight == rightHeight)
            return pow(2, leftHeight) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};