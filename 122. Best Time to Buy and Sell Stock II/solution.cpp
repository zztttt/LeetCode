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
* Runtime: 8 ms, faster than 99.21% of C++ online submissions for Best Time to Buy and Sell Stock II.
* Memory Usage: 9.8 MB, less than 5.39% of C++ online submissions for Best Time to Buy and Sell Stock II.
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ret = 0, len = prices.size();
		if (len == 0) return ret;
		for (int i = 1; i < len; ++i) {
			if (prices[i] > prices[i - 1])
				ret = ret + prices[i] - prices[i - 1];
		}
		return ret;
	}
};

int main() {
	vector<int> v = { 7, 1, 5, 3, 6, 4 };
	int ret = Solution().maxProfit(v);
	return 0;
}