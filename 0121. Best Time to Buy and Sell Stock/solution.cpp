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
* Runtime: 8 ms, faster than 99.22% of C++ online submissions for Best Time to Buy and Sell Stock.
* Memory Usage: 9.8 MB, less than 5.08% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ret = 0, len = prices.size();
		if (len == 0) return ret;
		vector<int> dp(prices.begin(), prices.end());
		dp[0] = INT_MAX;
		int nmin = INT_MAX;
		for (int i = 0; i < len - 1; ++i) {
			nmin = min(nmin, prices[i]);
			dp[i + 1] = nmin;
		}
		for (int i = 0; i < len; ++i) {
			if (prices[i] > dp[i]) {
				ret = max(ret, prices[i] - dp[i]);
			}
		}
		return ret;
	}
};

int main() {
	vector<int> v = { 7, 1, 5, 3, 6, 4 };
	int ret = Solution().maxProfit(v);
	return 0;
}