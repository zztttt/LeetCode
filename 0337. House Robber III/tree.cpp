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
    int robNode(TreeNode* root, int& robMax, int& notRobMax){
        if(root == nullptr)
            return 0;
        int leftRobMax = 0, leftNotRobMax = 0, rightRobMax = 0, rightNotRobMax = 0;
        int leftMax = robNode(root->left, leftRobMax, leftNotRobMax);
        int rightMax = robNode(root->right, rightRobMax, rightNotRobMax);
        robMax = root->val + leftNotRobMax + rightNotRobMax;
        notRobMax = leftMax + rightMax;
        return max(robMax, notRobMax);
    }
    
    int rob(TreeNode* root) {
        int robMax = 0, notRobMax = 0;
        return robNode(root, robMax, notRobMax);
    }
};