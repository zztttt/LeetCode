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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if(pre.size() == 0)
            return nullptr;

        TreeNode* root = build(pre, 0, pre.size() - 1);
        return root;
    }
    
    TreeNode* build(const vector<int>& pre, int low, int high){
        if(low > high)
            return nullptr;
        if(low == high)
            return new TreeNode(pre[low]);
        int rootVal = pre[low], start = low + 1, len = pre.size(), count = 0;
        while(start < len){
            if(pre[start] < rootVal){
                start++;
                count++;
            }
            else
                break;
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(pre, low + 1, low + count);
        root->right = build(pre, low + count + 1, high);
        return root;
    }
};