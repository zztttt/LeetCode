/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ret = INT_MIN;
    int maxPathSum(TreeNode* root) {
        // loop
        maxSum(root);
        return ret;
    }

    int maxSum(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = maxSum(root->left), right = maxSum(root->right);
        int cur = root->val;
        int localSum = cur;
        if(left > 0) localSum += left;
        if(right > 0) localSum += right;

        ret = max(ret, localSum);
        return max( cur, max(cur + left, cur + right));
    }
};