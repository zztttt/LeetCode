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
    bool isValidSequence(TreeNode* root, vector<int>& v) {
        return isValid(root, v, 0);
    }
    bool isValid(TreeNode* root, vector<int>& v, int pos){
        if(root == nullptr || pos >= v.size())
            return false;
        if(root->val != v[pos])
            return false;
        if(root->val == v[pos] && pos == v.size() - 1 && !(root->left) && !(root->right))
            return true;
        return isValid(root->left, v, pos + 1) || isValid(root->right, v, pos + 1);
    }
};