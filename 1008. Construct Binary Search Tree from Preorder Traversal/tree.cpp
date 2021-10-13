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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
    TreeNode* build(const vector<int>& preorder, int low, int high){
        //cout << "low:" << low << ", high:" << high << endl;
        if(low > high)
            return nullptr;
        if(low == high)
            return new TreeNode(preorder[low]);
        int rootVal = preorder[low];
        int pos = findPos(preorder, low, high, rootVal);
        //cout << "find:" << pos << endl;
        TreeNode *root = new TreeNode(rootVal);
        root->left = build(preorder, low + 1, pos - 1);
        root->right = build(preorder, pos, high);
        return root;
    }
    int findPos(const vector<int>& preorder, int low, int high, int target){
        int i = low;
        for(; i <= high; ++i){
            if(preorder[i] > target)
                break;
        }
        return i;
    }
};