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
    vector<TreeNode*> nodes;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)
            return -1;
        traverse(root, k);
        return nodes[k-1]->val;
    }

    void traverse(TreeNode* root, int k){
        if(root == nullptr || nodes.size() >= k)
            return;
        traverse(root->left, k);
        nodes.push_back(root);
        traverse(root->right, k);
    }
};