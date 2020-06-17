#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<sstream>
#include<assert.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
* Runtime: 36 ms, faster than 98.77% of C++ online submissions for Binary Tree Maximum Path Sum.
* Memory Usage: 25.3 MB, less than 24.78% of C++ online submissions for Binary Tree Maximum Path Sum.
*/
class Solution {
public:
	int ret = INT_MIN;
	int maxSum(TreeNode* root) {
		if (root == NULL) return 0;
		int left = maxSum(root->left);
		int right = maxSum(root->right);
		int cur = root->val;
		int sum = max(cur + left + right, 
						max(cur + left, 
							max(cur + right, cur)));
		ret = ret > sum ? ret : sum;
		return max( cur, max(cur + left, cur + right));
	}
	int maxPathSum(TreeNode* root) {
		int sum = maxSum(root);
		return max(ret, sum);
	}
};

int main() {
	
	int ret = Solution().maxProfit(v);
	return 0;
}