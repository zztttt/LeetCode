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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        int cur = root->val, pv = p->val, qv = q->val;

        if(pv < cur && qv < cur)
            return lowestCommonAncestor(root->left, p, q);
        else if(pv > cur && qv > cur)
            return lowestCommonAncestor(root->right, p, q);
        else 
            return root;
    }
};