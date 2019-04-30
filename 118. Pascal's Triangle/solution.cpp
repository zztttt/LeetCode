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

/*
* Runtime: 4 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
* Memory Usage: 8.9 MB, less than 13.62% of C++ online submissions for Pascal's Triangle.
*/
class Solution {
public:
	vector<vector<int>> generate(int n) {
		vector<vector<int>> ret;
		ret.push_back(vector<int>(1, 1));
		for (int i = 1; i < n; ++i) {
			vector<int> curLevel;
			//push first 1
			curLevel.push_back(1);
			vector<int> preLevel = ret[i - 1];
			int len = preLevel.size();
			for (int j = 0; j < len - 1; ++j) {
				curLevel.push_back(preLevel[j] + preLevel[j + 1]);
			}
			//push last 1
			curLevel.push_back(1);
			ret.push_back(curLevel);
		}
		return ret;
	}
};

int main() {
	int n = 3;
	vector<vector<int>> v = Solution().generate(n);
	return 0;
}