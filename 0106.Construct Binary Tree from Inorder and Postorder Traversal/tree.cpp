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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder, int ilow, int ihigh, int plow, int phigh){
        //cout << ilow << "," << ihigh << "," << plow << "," << phigh << endl;
        if(ilow > ihigh || plow > phigh)
            return nullptr;
        if(ilow == ihigh)
            return new TreeNode(inorder[ilow]);
        if(plow == phigh)
            return new TreeNode(postorder[plow]);
        int rootVal = postorder[phigh];
        TreeNode *root = new TreeNode(rootVal);
        int pos = findPos(inorder, ilow, ihigh, rootVal);
        root->left = build(inorder, postorder, ilow, pos - 1, plow, plow + (pos - ilow) - 1);
        root->right = build(inorder, postorder, pos + 1, ihigh, plow + (pos - ilow), phigh - 1);
        return root;
    }
    int findPos(const vector<int>& v, int low, int high, int target){
        for(int i = low; i <= high; i++){
            if(v[i] == target)
                return i;
        }
        return -1;
    }
};