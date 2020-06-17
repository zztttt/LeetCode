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
* Runtime: 8 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
* Memory Usage: 13.7 MB, less than 93.74% of C++ online submissions for Binary Tree Level Order Traversal.
* example:
*  	 3
	/  \
	9    20
		/  \
	   15   7    init: 3, NULL; loop1: 9, 20, NULL; loop2: 15, 7, NULL; loop3: NULL; loop4: break, tmp is empty
*/
class Solution {
public:
	vector<int> tmp;
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL)return vector<vector<int>>(1, tmp);
		vector<vector<int>> ret;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		while (!q.empty()) {
			TreeNode* p = q.front();
			q.pop();
			if (p != NULL) {
				tmp.push_back(p->val);
				if (p->left)
					q.push(p->left);
				if (p->right)
					q.push(p->right);
			}
			else {
				//tmp.empty means this level arrives at MAX DEPTH
				if (tmp.empty())
					break;
				//insert the next level's flag
				q.push(NULL);
				ret.push_back(tmp);
				tmp.clear();
			}
		}
		return ret;
	}
};

int main() {
	init();
	Solution().levelOrder(root);
	system("pause");
}