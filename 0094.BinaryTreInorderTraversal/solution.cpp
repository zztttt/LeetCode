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

/*
* Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
* Memory Usage: 11 MB, less than 5.11% of C++ online submissions for Binary Tree Inorder Traversal.
* recursivly loop this
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL)
			return vector<int>();
		vector<int> ret(1, root->val);
		vector<int> left = inorderTraversal(root->left);
		vector<int> right = inorderTraversal(root->right);
		//merge left into ret
		ret.insert(ret.begin(), left.begin(), left.end());
		//merge right into ret
		ret.insert(ret.begin() + ret.size(), right.begin(), right.end());
		return ret;
	}
};

int main() {
	
	//vector<int> w = { 3,2,1,0,4 };
	TreeNode* root = new TreeNode();
	vector<int> ret = Solution().inorderTraversal(w);
	system("pause");
}