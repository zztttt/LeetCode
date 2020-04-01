#include <bits/stdc++.h>

using namespace std;

int IsSymbol(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int Priority(char c) {
	switch (c)
	{
		case '*':
		case '/':return 1;
		case '+':
		case '-':return 0;
		default: return -1;
	}
}

string Brackets(string s) {
	return "("+s+")";
}

int ComparePri(char x, char y) {
	return Priority(x) > Priority(y) ? 1 : 0;
}


struct TreeNode {
	char val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* Post2Tree(string str) {
    
	stack<TreeNode*> s;
	
	int len = str.length();
	for (int i=0; i<len; i++) {
		char c = str[i];
		
		if ( !IsSymbol(c)) {
			TreeNode *tmp = new TreeNode(c);
            s.push(tmp);
		}
        else {
            TreeNode *b = s.top();
            s.pop();

            TreeNode *a = s.top();
            s.pop();

            TreeNode *cal = new TreeNode(c);
            cal->left = a;
            cal->right = b;
            s.push(cal);
        }
	}

    TreeNode *root = s.top();
    s.pop();
    
    return root;
}

string Tree2Infix(TreeNode *root) {
    string res = "";
    string l, r;

    if (root) {
        l = Tree2Infix(root->left);
        r = Tree2Infix(root->right);

        if (root->left) {
            if (IsSymbol(root->left->val) && ComparePri(root->val, root->left->val)) {
                l = Brackets(l);
            }
        }

        if (root->right) {
            if (IsSymbol(root->right->val) && !ComparePri(root->right->val, root->val)) {
                r = Brackets(r);
            }
        }

        res = l + root->val + r;
    }

    return res;
}
	
	
	
int main() {
	string s = "2963/+5-*4+";
    
    TreeNode *root = Post2Tree(s);
    //inOrder(root);
	cout << endl;

    cout << Tree2Infix(root);
	return 0;
}
