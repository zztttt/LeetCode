#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static TreeNode* root;
void init() {
	/*
		3
	   /  \
	  9    20
		  /  \
		 15   7
	*/
	root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	/*root = new TreeNode(1);
	root->left = new TreeNode(1);*/
}
/*
* Runtime: 12 ms, faster than 39.07% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
* Memory Usage: 13.3 MB, less than 92.28% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
* 
* isReverse is changed at the end of every loop, check whether to reverse before store vector 
*/
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == NULL)return{};
		int isReverse = false;
		vector<vector<int>> ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			//store all elements of queue in tmp vector 
			vector<int> vloop;
			for (int i = q.size(); i > 0; --i) {
				TreeNode* p = q.front();
				vloop.push_back(p->val);
				q.pop();
				if (p->left)q.push(p->left);
				if (p->right)q.push(p->right);
			}
			if (isReverse)
				reverse(vloop.begin(), vloop.end());
			ret.push_back(vloop);
			isReverse = !isReverse;
		}
		return ret;
	}
};

int main() {
	init();
	Solution().zigzagLevelOrder(root);
	system("pause");
}