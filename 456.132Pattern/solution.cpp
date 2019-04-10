#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int tmp = INT_MIN;
		stack<int> stk;
		for (int i = nums.size() - 1; i >= 0; --i) {
			if (nums[i] < tmp)
				return true;
			else while (!stk.empty() && nums[i] > stk.top()) {
				tmp = stk.top();
				stk.pop();
			}
			stk.push(nums[i]);
		}
		return false;
	}
};
int main() {
	
	vector<int> w = { 2, 3, 1, 1, 4 };
	bool ret = Solution().find132pattern(w);
	system("pause");
}