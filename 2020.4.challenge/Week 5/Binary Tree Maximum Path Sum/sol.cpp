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
    int ret = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        maxPathOneLine(root);
        return ret;
    }
    
    int maxPathOneLine(TreeNode* root){
        if(root == nullptr)
            return 0;
        int cur = root->val;
        int leftSum = maxPathOneLine(root->left), rightSum = maxPathOneLine(root->right);
        int sum = max(cur + leftSum + rightSum, max(cur + leftSum, cur + rightSum));
        if(sum > ret){
            ret = sum;
        }
        return max(0, max(leftSum + cur, rightSum + cur));
    }
};