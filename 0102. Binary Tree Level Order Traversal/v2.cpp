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
    vector<int> tmp;
	vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
		if (root == NULL)return ret;
        
        vector<TreeNode*> cur;
        vector<TreeNode*> next;
        vector<int> curData;
        
        cur.push_back(root);
        
        while(!cur.empty()){
            int size = cur.size();
            for(int i = 0; i < size; i++){
                curData.push_back(cur[i]->val);
                if(cur[i]->left)
                    next.push_back(cur[i]->left);
                if(cur[i]->right)
                    next.push_back(cur[i]->right);
            }
            // transfer next to cur, then clear next
            cur.clear();
            cur = vector(next.begin(), next.end());
            ret.push_back(curData);
            
            next.clear();
            curData.clear();
        }
        return ret;
    }
};