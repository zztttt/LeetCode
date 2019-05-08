#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
/*
* Runtime: 4 ms, faster than 100.00% of C++ online submissions for Rotate Image.
* Memory Usage: 9.1 MB, less than 94.85% of C++ online submissions for Rotate Image.
*/
class Solution
{
public:
	void rotate(vector<vector<int>> &m){
		vector<vector<int>> tmp = m;
		int row = m.size();
		if (row == 0)return;
		int col = m[0].size();
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				m[i][j] = tmp[col - j - 1][i];
			}
		}
	}
};

int main() {
	
}

