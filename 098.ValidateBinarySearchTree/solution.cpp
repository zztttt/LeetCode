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
/*Runtime: 20 ms, faster than 99.08% of C++ online submissions for Validate Binary Search Tree.
* Memory Usage : 20.6 MB, less than 57.88% of C++ online submissions for Validate Binary Search Tree.
*/
class Solution {
public:
	int maxValue(TreeNode* root) {
		if (root == NULL)
			return INT_MAX;
		while (root->right)
			root = root->right;
		return root->val;
	}
	int minValue(TreeNode* root) {
		if (root == NULL)
			return INT_MIN;
		while (root->left) {
			root = root->left;
		}
		return root->val;
	}
	bool isValidBST(TreeNode* root) {
		bool ret = true;
		if (root == NULL)
			return true;
		//left tree's max value must be less than root->val && left->val < root->val
		if (root->left) {
			ret = ret && (root->val > maxValue(root->left));
			ret = ret && isValidBST(root->left);
		}
		//right tree's min value must be more than root->val && right->val > root->val
		if (root->right) {
			ret = ret && (root->val < minValue(root->right));
			ret = ret && isValidBST(root->right);
		}
		return ret;
	}
};

int main() {
	init();
	bool ret = Solution().isValidBST(root);
	system("pause");
}