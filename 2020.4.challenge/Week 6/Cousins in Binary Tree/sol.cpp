class Solution {
    int xDepth = -1;
    int yDepth = -1;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root, x, y, 0);
        return xDepth != -1 && xDepth == yDepth;
    }
    
    void solve(TreeNode *root, int x, int y, int depth){
        if(!root) return;
        if(
            root->left &&
            root->right && 
            (root->left->val == x || root->left->val == y) &&
            (root->right->val == x || root->right->val == y)
        ) return;
        
        if(root->val == x){
            xDepth = depth;
            return;
        }
        if(root->val == y){
            yDepth = depth;
            return;
        }
        
        solve(root->left, x, y, depth+1);
        solve(root->right, x, y, depth+1);
    }
};