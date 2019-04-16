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
* Runtime: 16 ms, faster than 99.08% of C++ online submissions for Maximum Depth of Binary Tree.
* Memory Usage: 19.3 MB, less than 73.56% of C++ online submissions for Maximum Depth of Binary Tree.
* record every level, increase one by one
*/
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		queue<TreeNode*> q;
		q.push(root);
		int ret = 0;
		while (!q.empty()) {
			int curLevelSize = q.size();
			for (int i = 0; i < curLevelSize; ++i) {
				TreeNode* p = q.front();
				q.pop();
				if (p->left)q.push(p->left);
				if (p->right)q.push(p->right);
			}
			++ret;
		}
		return ret;
	}
};

int main() {
	init();
	Solution().maxDepth(root);
	system("pause");
}