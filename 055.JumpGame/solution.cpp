#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

/*
*Runtime: 12 ms, faster than 98.64% of C++ online submissions for Jump Game.
*Memory Usage: 9.9 MB, less than 98.41% of C++ online submissions for Jump Game.
*/
//record the current maxReach, break if maxReach <= pos, return maxReach >= maxPos
class Solution {
public:
	bool canJump(vector<int>& n) {
		int maxReach = 0, len = n.size();
		for (int i = 0; i < len; ++i) {
			maxReach = max(i + n[i], maxReach);
			//can not reach this pos
			if (maxReach <= i) {
				break;
			}
		}
		return maxReach >= len - 1;
	}
};

int main() {
	
	vector<int> w = { 3,2,1,0,4 };
	bool ret = Solution().canJump(w);
	system("pause");
}