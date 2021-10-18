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
    class Node{
    public:
        TreeNode *self;
        TreeNode *parent;
        Node(TreeNode *_self, TreeNode *_parent): self(_self), parent(_parent){}
    };
    bool isCousins(TreeNode* root, int x, int y) {
        queue<Node> q;
        q.push(Node(root, nullptr));

        while(!q.empty()){
            queue<Node> nextLevel;
            map<int, TreeNode*> valueWithParent;
            while(!q.empty()){
                Node cur = q.front();
                q.pop();
                valueWithParent[cur.self->val] = cur.parent;
                if(cur.self->left)
                    nextLevel.push(Node(cur.self->left, cur.self));
                if(cur.self->right)
                    nextLevel.push(Node(cur.self->right, cur.self));
            }
            map<int, TreeNode*>::iterator it1 = valueWithParent.find(x), it2 = valueWithParent.find(y);
            if(it1 != valueWithParent.end() && it2 != valueWithParent.end() && it1->second != it2->second)
                return true;
            q = nextLevel;
        }
        return false;
    }
};