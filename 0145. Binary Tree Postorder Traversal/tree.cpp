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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> ret;
        stack<TreeNode*> nodes;
        stack<TreeNode*> stk;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* top = nodes.top();
            nodes.pop();
            stk.push(top);
            if(top->left){
                nodes.push(top->left);
            }
            if(top->right){
                nodes.push(top->right);
            }
        }
        
        while(!stk.empty()){
            ret.push_back(stk.top()->val);
            stk.pop();
        }
        return ret;
    }
};