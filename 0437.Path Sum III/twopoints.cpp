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
    void dfs(TreeNode *root, map<int, int>& m, int sum, int target, int& ret){
        if(root == nullptr)
            return;
        int val = sum + root->val;
        if(m.find(val - target) != m.end())
            ret += m[val - target];
        if(m.find(val) != m.end())
            m[val]++;
        else
            m[val] = 1;
        dfs(root->left, m, val, target, ret);
        dfs(root->right, m, val, target, ret);
        m[val]--;
        if(m[val] == 0)
            m.erase(m.find(val));
    }
    
    int pathSum(TreeNode* root, int target) {
        map<int, int> m;
        m[0] = 1;
        int ret = 0;
        dfs(root, m, 0, target, ret);
        return ret;
    }
};