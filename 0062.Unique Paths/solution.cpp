#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		/*  0 1 2 m 
		* 0 1 1 1
		* 1 1 2 3
		* n
		* 
		*/
		//init dp array
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i) {
			dp[i][0] = 1;
		}
		for (int j = 0; j < m; ++j) {
			dp[0][j] = 1;
		}
		//dp[i][j] = dp[i-1][j]+dp[i][j-1]
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[n - 1][m - 1];
	}
};
int main() {
	int m = 3, n = 2;
	int ret = Solution().uniquePaths(m, n);
	system("pause");
}