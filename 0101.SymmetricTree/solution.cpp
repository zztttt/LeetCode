#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>
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
		5
	   / \
	  1   4
		 / \
		3   6
	*/
	/*root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(6);*/
	/*
		10
	   /  \
	  5    15
		  /  \
		 6    20
	*/
	/*root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(20);*/

	root = new TreeNode(1);
	root->left = new TreeNode(1);
}
/*
* Runtime: 8 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
* Memory Usage: 14.7 MB, less than 99.82% of C++ online submissions for Symmetric Tree
*/
class Solution {
public:
	bool compare(TreeNode* left, TreeNode* right) {
		bool ret = true;
		if (left)
			ret = ret && (right);
		else
			ret = ret && (!right);
		//assert false
		if (!ret)return ret;
		if (left) {
			ret = ret && (left->val == right->val);
			ret = ret && compare(left->left, right->right) && compare(left->right, right->left);
		}
		return ret;
	}
	bool isSymmetric(TreeNode* root) {
		bool ret = true;
		if (root == NULL) return true;
		ret = compare(root->left, root->right);
		return ret;
	}
};

int main() {
	init();
	bool ret = Solution().isSymmetric(root);
	system("pause");
}