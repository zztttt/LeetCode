class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstructBinaryTree(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
    TreeNode* reConstructBinaryTree(const vector<int>& pre, const vector<int>& vin, int plow, int phigh, int vlow, int vhigh){
        if(plow > phigh || vlow > vhigh)
            return nullptr;
        int root_val = pre[plow];
        TreeNode* root = new TreeNode(root_val);
        int pos = findPos(vin, root_val);
        int leftCount = pos - vlow, rightCount = vhigh - pos;
        root->left = reConstructBinaryTree(pre, vin, plow + 1, plow + leftCount, vlow, pos - 1);
        root->right = reConstructBinaryTree(pre, vin, plow + leftCount + 1, phigh, pos + 1, vhigh);
        return root;
    }
    int findPos(const vector<int>& v, int target){
        int len = v.size();
        for(int i = 0 ; i < len; ++i){
            if(v[i] == target)
                return i;
        }
        return -1;
    }
};