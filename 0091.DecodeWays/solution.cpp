#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>

using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		int len = s.length();
		if (s[0] == '0')
			return 0;
		/*
		* 0 0
		* 1 1
		* 2 2
		* 3 3
		* i
		*/
		//init. dp[i] indicates the number of way to decode s[0, i-1];
		vector<int> dp(len + 1, 0);
		dp[0] = 1; dp[1] = 1;
		for (int i = 2; i < len + 1; ++i) {
			//single code
			if (s[i - 1] >= '1' && s[i - 1] <= '9')
				dp[i] = dp[i] + dp[i - 1];
			//two word code
			if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6'))
				dp[i] = dp[i] + dp[i - 2];
		}
		return dp[len];
	}
};
int main() {
	string s = "226";
	int ret = Solution().numDecodings(s);
	system("pause");
}