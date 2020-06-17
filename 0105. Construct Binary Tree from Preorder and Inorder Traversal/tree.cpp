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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int len = pre.size();
        return build(pre, in, 0, len - 1, 0, len - 1);
    }
    
    TreeNode* build(vector<int>& pre, vector<int>& in, int plow, int phigh, int ilow, int ihigh){
        //cout << "plow:" << plow << "phigh:" << phigh << endl;
        //cout << "ilow:" << ilow << "ihigh:" << ihigh << endl;
        if(plow > phigh || ilow > ihigh)
            return nullptr;
        if(plow == phigh && ilow == ihigh)
            return new TreeNode(pre[plow]);
        
        int rootVal = pre[plow];
        TreeNode* root = new TreeNode(rootVal);
        
        int pos = getPos(in, ilow, ihigh, rootVal);
        int leftSize = pos - ilow, rightSize = ihigh - pos;
        
        root->left = build(pre, in, plow + 1, plow + leftSize, ilow, pos - 1);
        root->right = build(pre, in, plow + leftSize + 1, phigh, pos + 1, ihigh);
        
        return root;
    }
    
    int getPos(vector<int>& v, int low, int high, int target){
        for(int i = low; i <= high; ++i){
            if(v[i] == target)
                return i;
        }
        assert(0);
    }
};