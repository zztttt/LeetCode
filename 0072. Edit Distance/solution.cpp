#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

/*
* Runtime: 12 ms, faster than 99.29% of C++ online submissions for Edit Distance.
* Memory Usage: 11.3 MB, less than 15.66% of C++ online submissions for Edit Distance.
*/
class Solution {
public:
	/* s1 = horse, s2 = ros
	*  0 1 2 3 j/n
	*  1 1 2 3
	*  2 2 1 2
	*  3 2 2 2
	*  4 3 3 2
	*  5 4 4 3
	*  i/m
	*/
	int minDistance(string s1, string s2) {
		int m = s1.length(), n = s2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			dp[i][0] = i;
		}
		for (int i = 1; i <= n; ++i) {	
			dp[0][i] = i;
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				//s1[i] == s2[j]
				//dp[i][j] = dp[i-1][j-1]
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					//s1[i] != s2[j]
					//case 1: modify s1[i], dp[i][j] = dp[i-1][j-1] + 1
					//case 2: delete s1[i], dp[i][j] = dp[i-1][j] + 1
					//case 3: add s2[j] s1, dp[i][j] = dp[i][j-1]+1 (means delete s2[j])
					dp[i][j] = min(dp[i][j - 1], 
								  min(dp[i - 1][j], dp[i-1][j-1])) + 1;
				}
			}
		}
		return dp[m][n];
	}
};

int main() {
	string s1 = "horse", s2 = "ros";
	int ret = Solution().minDistance(s1, s2);
	system("pause");
}

