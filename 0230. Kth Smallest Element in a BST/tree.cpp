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
    vector<int> Inorder(TreeNode* t){
        if(t == nullptr) 
            return vector<int>();
        vector<int> ret = vector<int>();
        ret.push_back(t->val);
        
        vector<int> left = vector<int>();
        vector<int> right = vector<int>();
        if(t->left)
            left = Inorder(t->left);
        if(t->right)
            right = Inorder(t->right);
        // left | ret | right
        left.insert(left.end(), ret.begin(), ret.end());
        left.insert(left.end(), right.begin(), right.end());

        return left;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> data = Inorder(root);
        return data[k-1];
    }
};