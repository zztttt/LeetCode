class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL)
			return root;
		vector<Node*> q;
		q.push_back(root);
		while (!q.empty()) {
			int len = q.size();
			vector<Node*> curLevel;
			bool isLeaf = (q[0]->left == NULL);
			for (int i = 0; i < len - 1; ++i) {
				q[i]->next = q[i + 1];
				if (!isLeaf) {
					curLevel.push_back(q[i]->left);
					curLevel.push_back(q[i]->right);
				}
			}
			if (!isLeaf) {
				curLevel.push_back(q[len - 1]->left);
				curLevel.push_back(q[len - 1]->right);
			}
			//update q
			q.clear();
			q = curLevel;
		}
		return root;
	}
};