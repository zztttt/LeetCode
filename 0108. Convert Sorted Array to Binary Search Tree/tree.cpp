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
    TreeNode* sortedArrayToBST(vector<int>& v) {
        if(v.size() == 0)
            return nullptr;
        
        return build(v, 0, v.size() - 1);
    }
    
    TreeNode* build(vector<int>& v, int low, int high){
        if(low > high)
            return nullptr;
        if(low == high)
            return new TreeNode(v[low]);
        
        int mid = (low + high)/2;
        TreeNode* left = build(v, low, mid - 1);
        TreeNode* right = build(v, mid + 1, high);
        TreeNode* root = new TreeNode(v[mid]);
        root->left = left;
        root->right = right;
        
        return root;
    }
};