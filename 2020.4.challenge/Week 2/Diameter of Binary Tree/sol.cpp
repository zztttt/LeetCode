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
    map<TreeNode*, int> m;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        depth(root);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            int sum = 0;
            if(cur->left){
                sum += m[cur->left];
                q.push(cur->left);
            }
            if(cur->right){
                sum += m[cur->right];
                q.push(cur->right);
            }
            if(sum > ret)
                ret = sum;
        }
        return ret;
    }
    int depth(TreeNode* root){
        if(root == nullptr)
            return 0;
        int cur = 1 + max(depth(root->left), depth(root->right));
        m[root] = cur;
        return cur;
    }
};