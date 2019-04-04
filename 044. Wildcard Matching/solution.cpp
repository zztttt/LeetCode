#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#include<map>

using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		//s = adceb, p =*a*b
		//slen = 5, plen = 4
		//init
		/*      * a * b p
			  0 1 2 3 4 j 
		*   0 1 1 0 0 0 
		* a 1 0 1 1 1 0 
		* d 2 0 1 0 1 0
		* c 3 0 1 0 1 0
		* e 4 0 1 0 1 0
		* b 5 0 1 0 1 1
		* s i
		*/
		int slen = s.length(), plen = p.length();
		//dp[i][j] indicates that whether s[0,i-1],p[0,j-1] can pair
		//init
		vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
		//case1: s = "", p =""
		dp[0][0] = true;
		//case2: s = "", p = any
		for (int j = 1; j < plen + 1; ++j) {
			//if p[j-1] != '*', break the loop
			if (p[j - 1] == '*')
				dp[0][j] = true;
			else
				break;
		}
		//dp
		for (int i = 1; i < slen + 1; ++i) {
			for (int j = 1; j < plen + 1; ++j) {
				//case 1: p[j-1] = *
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
				//case2: s[i-1] == p[j-1]
				else if (s[i-1] == p[j-1] || p[j-1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		return dp[slen][plen];
	}
};
int main() {
	string s = "adceb", p = "*a*b";
	int ret = Solution().isMatch(s, p);
	system("pause");
}