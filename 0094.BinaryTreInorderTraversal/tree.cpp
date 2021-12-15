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
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode *head = root;
        while(head != nullptr || !stk.empty()){
            while(head != nullptr){
                stk.push(head);
                head = head->left;
            }
            if(!stk.empty()){
                TreeNode* top = stk.top();
                stk.pop();
                ret.push_back(top->val);
                head = top->right;
            }
        }
        return ret;
    }
};